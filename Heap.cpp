/*
 * Heap.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: Andrew Maxwell
 */

#include <vector>
#include <iostream>
#include <math.h>
#include <assert.h>
#include "Heap.h"

using namespace std;

bool DEBUG = false;

    /**Helper Functions*/

    void Heap::heapify(int i) {
        int l = i * 2;
        int r = i * 2 + 1;
        int greatest = i;
    	if (l <= heap_size and *(heap -> at(l)) > *(heap -> at(greatest))) {
    		greatest = l;
    	}
    	if (r <= heap_size and *(heap -> at(r)) > *(heap -> at(greatest))) {
    		greatest = r;
    	}
        if (greatest != i) {
        	Order * swap = heap -> at(greatest);
        	heap -> at(greatest) = heap -> at(i);
        	heap -> at(i) = swap;
        	heapify(greatest);
        }
    }
    //helper function to build_heap, remove, and sort
    //bubbles an element down to its proper location within the heap

    void Heap::heap_increase_key(int i, Order * key) {
    	if (*(heap -> at(floor(i/2))) < *key) {
    		heap -> at(i) = heap -> at(floor(i/2));
    		heap -> at(floor(i/2)) = key;
    		heap_increase_key(floor(i/2), key);
    	}
    }
    //helper function to insert
    //bubbles an element up to its proper location

    /**Constructors*/

    Heap::Heap() {
    	heap_size = 0;
    	heap = new vector<Order *>;
    	Order placeHolder;
    	heap -> push_back(&placeHolder);
    }
    //Constructor for a new heap

    /**Manipulation Procedures*/

    void Heap::build_heap() {
        for (int i = heap_size/2; i > 0; i--) {
            heapify(i);
        }
    }
    //Builds the heap
    //Called as a helper function of the constructor
    //Calls heapify as a helper function

    void Heap::place(Order * o, int days) {
    	if (o == NULL) {
    		return;
    	}
    	assert (!o -> isShipped());
    	o -> placeOrder(days);
    	heap -> push_back(o);
    	heap_size++;
    	heap_increase_key(heap_size, o);
    }
    //Places an order while simultaneously putting it on the heap

    void Heap::ship(int index) {
    	assert(1 <= index);
    	assert(index <= heap_size);
    	heap -> at(index) -> ship();
    	heap -> at(index) = heap -> at(heap_size);
    	heap -> pop_back();
    	heap_size--;
    	heapify(index);
    }
    //Ships an order and removes it from the heap.

    void Heap::ship(Order * o) {
    	for (unsigned i = 0; i < heap -> size(); i++) {
    		if (heap -> at(i) == o) {
    			ship(i);
    		}
    	}
    }
    //Calls previous ship function. Just allows you to ship by passing an order to the heap rather than an index.

    /**Access Functions*/

    Order * Heap::get_max() const {
        assert(heap_size > 0);
        return heap -> at(1);
    }
    //returns the maximum value in the heap
    //pre: heap_size > 0

    Order * Heap::get_parent(int i) const {
        assert(0 < i);
        assert(i <= heap_size);
        return heap -> at(floor(i/2));
    }
    //returns the location (index) of the element stored at index i
    //pre: 0 < i <= heap_size

     Order * Heap::get_left(int i)  const {
        assert(0 < i);
        assert(i <= heap_size);
        return heap -> at(i * 2);
    }
    //returns the location (index) of the left child of the element stored at i
    //pre: 0 < i <= heap_size

    Order * Heap::get_right(int i)  const {
        assert(0 < i);
        assert(i <= heap_size);
        return heap -> at((i * 2) + 1);

    }
    //returns the location (index) of the right child of the element stored at i
    //pre: 0 < i <= heap_size

    int Heap::get_size() const {
        return heap_size;
    }

    Order * Heap::get_element(int i) const {
        assert(0 < i);
        assert(i <= heap_size);
        return heap -> at(i);
    }
    //returns the element at the specified index i
    //pre: 0 < i <= heap_size

    /**Additional Operations*/

    void Heap::displayHeap(ostream& out) const {
    	int level = 0;
        for (int i = 1; i <= heap_size; i++) {
            if (floor(log2(i)) > level) {
                out << endl;
                level++;
            }
            heap -> at(i) -> print(out);
        }
    }

    void Heap::print(ostream & out, int index) {
    	heap -> at(index) -> printDetailed(out);
    }

    void Heap::printSorted(ostream& out) {
    	int realLength = heap_size;
    	while (heap_size > 1) {
    		if (DEBUG) {
    			out << "\ninitially\n";
    			displayHeap(out);
    		}
    		Order * swap = heap -> at(1);
    		heap -> at(1) = heap -> at(heap_size);
    		heap -> at(heap_size) = swap;
    		if (DEBUG) {
        		out << "\nafter swapping\n";
        		displayHeap(out);
    		}
    		heap_size--;
    		heapify(1);
    		if (DEBUG) {
    			out << "\nafter decreasing length and heapify\n";
    			displayHeap(out);
    		}
    	}
    	heap_size = realLength;
        for (int i = heap_size; i >= 1; i--) {
            (*heap)[i] -> print(out);
        }
    	build_heap();
    }
    //prints each element in the array (heap) on a different line
