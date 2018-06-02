/**
 * Vu Pham
 * Tin Nguyen
 * CIS 22C, Lab 4
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <cstddef> //for NULL
#include <assert.h> //for assert function
#include <iomanip> //for setw
#include <fstream> //for fileIO
using namespace std;

template<class listdata> //list stores generic listdata, not any specific C++ type
class List {

private:
	struct Node {
		listdata data;
		Node* next;
		Node* previous;

		Node(listdata newData) {
			data = newData;
			next = NULL;
			previous = NULL;
		}
	};

	Node* start;
	Node* stop;
	Node* iterator;
	int length;

	bool isSorted(Node* node) const;
	//Helper function for the isSorted() public function.
	//Recursively determines whether a list is sorted in ascending order.

	void displayReverse(Node* node, ostream &out) const;
	//Helper function for the public displayReverse wrapper function
	//Recursively prints the data in a list in reverse order

	int binarySearch(int low, int high, listdata data) const;
	//Recursively search the list by dividing the search space in half
	//Returns the index of the element, if it is found in the list
	//Returns -1 if the element is not in the list
	//Post: iterator location is not changed

public:

	/**Constructors and Destructors*/

	List();
	//Default constructor; initializes and empty list
	//Postcondition: start and stop nodes are set to NULL, length set to 0

	List(const List &list);
	//Copy constructor (deep copy); allocates new memory and copy contents to new list
	//Postcondition: New list will contain a copy of the data in the original list

	~List();
	//Destructor. Frees memory allocated to the list
	//Postcondition: all nodes are deleted, resources are freed

	/**Accessors*/

	listdata getStart() const;
	//Returns the data at the start of the list
	//Precondition: length != 0

	listdata getStop() const;
	//Returns the data at the end of the list
	//Precondition: length != 0

	bool isEmpty() const;
	//Determines whether a list is empty.
	//Postcondition: returns true if length==0 and false if otherwise

	int getLength() const;
	//Returns the size of the list

	listdata getIterator() const;
	//Returns the data of the node the iterator pointing at
	//Precondition: iterator != NULL

	bool offEnd() const;
	//Returns whether the iterator is off the list

	bool operator==(const List &list) const;
	//Compares two lists to see if they contain the same data in the same order
	//Postcondition: returns true if equal and false if otherwise

	bool isSorted() const;
	//Wrapper function that calls the isSorted helper function to determine whether a list is sorted in ascending order.
	//We will assume that a list is trivially sorted if it is empty.
	//Therefore, no precondition is needed.

	int getIndex() const;
	//Indicates the index of the Node where the iterator is currently pointing at.
	//Nodes are numbered starting at 1 through "length".
	//Pre: iterator != NULL

	int linearSearch(listdata data) const;
	//Iteratively searches the list, element by element, from the start of the list to the end.
	//Returns the index of the element, if it is found in the list.
	//Does not call the indexing functions in the implementation
	//Returns -1 if the element if not in the List
	//Pre: length != 0
	//Post: iterator location does not change

	int binarySearch(listdata data) const;
	//Returns the index where data is located in the list.
	//Calls the private helper function binarySearch to perform the search
	//Pre: length != 0 && isSorted()
	//Post: iterator location is not changed

	/**Manipulation Procedures*/

	void removeStart();
	//Removes the value stored in first node in the list
	//Precondition: getLength() > 0
	//Postcondition: if length = 1 --> length = 0 and start and stop = NULL
	//               if length > 1 --> second node becomes start node, length--

	void removeStop();
	//Removes the value stored in the last node in the list
	//Precondition: getLength() > 0
	//Postcondition: if length = 1 --> length = 0 and start and stop = NULL
	//               if length > 1 --> second to last node becomes stop node, length--

	void insertStart(listdata data);
	//Inserts a new data at the beginning of the list
	//If the list is empty, the new data becomes both start and stop
	//Postcondition: if length = 0 --> start and stop = newNode, length++
	//               if length > 0 --> start node becomes second node, newNode becomes start node, length++

	void insertStop(listdata data);
	//Inserts a new data at the end of the list
	//If the list is empty, the new data becomes both start and stop
	//Postcondition: if length = 0 --> start and stop = newNode, length++
	//               if length > 0 --> stop node becomes second to last, newNode becomes stop node, length++

	void startIterator();
	//Moves iterator to start of the list
	//Postcondition: iterator will point at start

	void removeIterator();
	//Removes the node currently pointed to by the iterator
	//Precondition: iterator != NULL
	//Postcondition: current node is removed, iterator->previous and iterator->next are now connected, length--

	void insertIterator(listdata data);
	//Inserts an element after the node currently pointed to by the iterator
	//Precondition: iterator != NULL
	//Postcondition: new node N is added after the iterator, iterator is connected with N, N is connected with iterator->next, length++

	void moveIterNext();
	//Moves the iterator up by one node towards stop
	//Precondition: iterator != NULL
	//Postcondition: iterator = iterator->next

	void moveIterPrevious();
	//Moves the iterator back by one node towards start
	//Precondition: iterator != NULL
	//Postcondition: iterator = iterator->previous

	void moveToIndex(int index);
	//Moves the iterator to the node whose index number is specified in the parameter.
	//Nodes are numbered starting at 1 to "length".
	//Pre: length != 0 && index <= length

	/**Additional List Operations*/

	void displayList(ostream &out) const;
	//Prints to the console or file the value of each data in the list sequentially and separated by a blank space
	//Prints nothing if the list is empty
	//Prints a empty newline character if it's empty..

	void displayNumberedList(ostream &out) const;
	//Prints the contents of the linked list to the console or file in the format: <element> followed by a newline
	//Prints nothing if the list is empty
	//Prints a empty newline character if it's empty..

	void displayReverse(ostream &out) const;
	//Wrapper function that calls the private displayReverse helper function to print a list in reverse
	//Prints nothing if the list is empty

};

template<class listdata>
List<listdata>::List() {
	start = NULL;
	stop = NULL;
	iterator = NULL;
	length = 0;
}

template<class listdata>
List<listdata>::List(const List &list) {
	if (list.start == NULL)
		start = stop = iterator = NULL;
	else {
		start = new Node(list.start->data);
		Node* temp = list.start;
		iterator = start;
		while (temp->next != NULL) {
			temp = temp->next;
			iterator->next = new Node(temp->data);
			iterator->next->previous = iterator;
			iterator = iterator->next;
		}
		stop = iterator;
		iterator = NULL;
	}
	length = list.length;
}

template<class listdata>
List<listdata>::~List() {
	Node* b = start;
	Node* a = NULL;
	while (b != NULL) {
		a = b->next;
		delete b;
		b = a;
	}
	iterator = NULL;
}

template<class listdata>
listdata List<listdata>::getStart() const {
	assert(length != 0);
	return start->data;
}

template<class listdata>
listdata List<listdata>::getStop() const {
	assert(length != 0);
	return stop->data;
}

template<class listdata>
bool List<listdata>::isEmpty() const {
	return length == 0;
}

template<class listdata>
int List<listdata>::getLength() const {
	return length;
}

template<class listdata>
listdata List<listdata>::getIterator() const {
	assert(iterator != NULL);
	return iterator->data;
}

template<class listdata>
bool List<listdata>::offEnd() const {
	return iterator == NULL;
}

template<class listdata>
bool List<listdata>::operator==(const List &list) const {
	if (length != list.length)
		return false;
	Node* temp1 = start;
	Node* temp2 = list.start;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

template<class listdata>
void List<listdata>::removeStart() {
	assert(length != 0);
	if (length == 1) {
		delete start;
		start = stop = NULL;
	} else {
		Node* temp = start;
		start = start->next;
		delete temp;
		start->previous = NULL;
	}
	length--;
}

template<class listdata>
void List<listdata>::removeStop() {
	assert(length != 0);
	if (length == 1) {
		delete stop;
		start = stop = NULL;
	} else {
		Node* temp = stop->previous;
		delete stop;
		stop = temp;
		stop->next = NULL;
	}
	length--;
}

template<class listdata>
void List<listdata>::insertStart(listdata data) {
	Node* N = new Node(data);
	if (length == 0) {
		start = N;
		stop = N;
	} else {
		N->next = start;
		start->previous = N;
		start = N;
	}
	length++;
}

template<class listdata>
void List<listdata>::insertStop(listdata data) {
	Node* N = new Node(data);
	if (length == 0) {
		stop = start = N;
	} else {
		stop->next = N;
		N->previous = stop;
		stop = N;
	}
	length++;
}

template<class listdata>
void List<listdata>::startIterator() {
	iterator = start;
}

template<class listdata>
void List<listdata>::removeIterator() {
	assert(iterator != NULL);
	if (iterator == start)
		removeStart();
	else if (iterator == stop)
		removeStop();
	else {
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		delete iterator;
		length--;
	}
	iterator = NULL;
}

template<class listdata>
void List<listdata>::insertIterator(listdata data) {
	assert(iterator != NULL);
	if (iterator == stop)
		insertStop(data);
	else {
		Node* N = new Node(data);
		N->previous = iterator;
		N->next = iterator->next;
		iterator->next->previous = N;
		iterator->next = N;
		length++;
	}
}

template<class listdata>
void List<listdata>::moveIterNext() {
	assert(iterator != NULL);
	iterator = iterator->next;
}

template<class listdata>
void List<listdata>::moveIterPrevious() {
	assert(iterator != NULL);
	iterator = iterator->previous;
}

template<class listdata>
void List<listdata>::displayList(ostream &out) const {
	Node* temp = start;
	while (temp != NULL) {
		out << temp->data << " ";
		temp = temp->next;
	}
	out << endl;
}

template<class listdata>
void List<listdata>::displayNumberedList(ostream &out) const {
	Node* temp = start;
	int elem = 1;
	out << left << setw(15) << "Element" << "Value" << endl;
	while (temp != NULL) {
		out << left << setw(15) << elem << temp->data << endl;
		temp = temp->next;
		elem++;
	}
}

//*****NEW FUNCTIONS IN LAB4*****

template<class listdata>
bool List<listdata>::isSorted() const { //Wrapper function for isSorted
	return isSorted(start);
}

template<class listdata>
bool List<listdata>::isSorted(Node* node) const { //Helper function for isSorted
	if (node == stop) {
		return true;
	} else if (node->data < node->next->data) {
		isSorted(node->next);
	} else {
		return false;
	}
}

template<class listdata>
int List<listdata>::getIndex() const {
	assert(iterator != NULL);
	Node* temp = start;
	int index = 1;
	while (true) {
		if (temp == iterator) {
			return index;
		}
		temp = temp->next;
		index++;
	}
}

template<class listdata>
void List<listdata>::moveToIndex(int index) {
	assert((length != 0) && (index <= length));
	iterator = start;
	for (int i = 1; i < index; i++) {
		iterator = iterator->next;
	}
}

template<class listdata>
int List<listdata>::linearSearch(listdata data) const {
	assert(length != 0);
	Node* temp = start;
	for (int i = 1; i <= length; i++) {
		if (temp->data == data)
			return i;
		temp = temp->next;
	}
	return -1;
}

template<class listdata>
int List<listdata>::binarySearch(listdata data) const { //Wrapper function for binarySearch
	assert((length != 0) && isSorted());
	return binarySearch(1, length, data);
}

template<class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const { //Helper function for binarySearch
	if (high < low)
		return -1;
	int mid = low + (high - low) / 2;
	Node* temp = start;
	for (int i = 1; i < mid; i++) {
		temp = temp->next;
	}
	if (temp->data == data) {
		return mid;
	} else if (data < temp->data) {
		return binarySearch(low, mid - 1, data);
	} else {
		return binarySearch(mid + 1, high, data);
	}
}

template<class listdata>
void List<listdata>::displayReverse(ostream &out) const { //Wrapper function for displayReverse
	List<listdata>::displayReverse(stop, out);
}

template<class listdata>
void List<listdata>::displayReverse(Node* node, ostream &out) const { //Helper function for displayReverse
	if (node == NULL) {
		return;
	}
	out << node->data << " ";
	displayReverse(node->previous, out);
}

#endif /* LIST_H_ */
