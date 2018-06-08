/*
 * Heaptest.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: Andrew
 */

#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
	Heap laptops;
	Order order1;
	Product x, y, z;

	//creating dummy laptops to test with
	x.setMake("Xbook");
	y.setMake("Ytop");
	z.setMake("Flipz");
	x.setPrice(100);
	y.setPrice(200);
	z.setPrice(300);

	//testing add laptop
	order1.addLaptop(&z);
	order1.addLaptop(&x);
	order1.printDetailed(cout);

	//testing remove laptop
	order1.removeLaptop(1);
	order1.printDetailed(cout);

	//testing setting the quantity
	order1.setQuantity(0, 4);
	order1.printDetailed(cout);
	order1.setQuantity(0, 0);	//will remove the item from the cart
	order1.printDetailed(cout);

	order1.addLaptop(&x);
	order1.addLaptop(&y);
	order1.addLaptop(&z);

	laptops.place(&order1, 6);

	Order order2;
	order2.addLaptop(&x);
	order2.setQuantity(0, 7);
	Order order3;
	order3.addLaptop(&x);
	order3.setQuantity(0,8);
	Order order4;
	order4.addLaptop(&x);
	order4.setQuantity(0,9);
	order2.placeOrder(7);
	order3.placeOrder(8);
	order4.placeOrder(9);
	laptops.place(&order4, 9);
	laptops.place(&order2, 7);
	laptops.place(&order3, 8);

	order1.printDetailed(cout);
	//cout << "\nLaptop heap: ";
	//laptops.displayHeap(cout);
	//cout << "\nend of laptop heap";
	cout << "Testing printSorted\n";
	laptops.printSorted(cout);
	cout << "\nTesting displayHeap\n";
	laptops.displayHeap(cout);
	laptops.ship(&order1);
	cout << "Test";
	return 0;
}


