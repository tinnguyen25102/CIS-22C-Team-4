/*
 * Order.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: Andrew
 */

#include "List.h"
#include "Product.h"
#include "Order.h"
#include <assert.h>
#include <iomanip>
using namespace std;


	/** constructors */

	Order::Order() {
		shippingSpeed = dayPlaced = price = 0;
		placed = shipped = false;
	}

	/** management functions - getters and setters*/

	int Order::getArriveBy() const {
		return dayPlaced + shippingSpeed;
	}
	//returns the date that the order should arrive, determined based on day order is placed and shipping speed

	int Order::getDayPlaced() const {
		return dayPlaced;
	}
	//returns the date the order was placed

	int Order::getShippingSpeed() const {
		return shippingSpeed;
	}
	//returns the shipping speed

	bool Order::isPlaced() const {
		return placed;
	}
	//returns whether the order has been placed or not

	void Order::setIsPlaced(bool isPlaced) {
		placed = isPlaced;
	}

	bool Order::isShipped() const {
		return shipped;
	}
	//returns whether the order has been shipped. If the order has been shipped, no further modification is allowed.

	void Order::ship() {
		shipped = true;
	}
	//sets the order to shipped.

	void Order::addLaptop(Product * newLaptop) {
		assert(!placed);
		subOrder newLT(newLaptop);
		laptops.insertStop(newLT);
		price += newLT.price;
	}
	//Adds a new laptop. If laptop matches existing laptop, increment by 1.
	//Pre: !placed

	void Order::removeLaptop(int index) {
		assert(!placed);
		assert(index < laptops.getLength());
		laptops.moveToIndex(index);
		price -= laptops.getIterator().price;
		laptops.removeIterator();
	}
	//removes a laptop from the list, by index
	//Pre: !Placed
	//Pre: Index < length of list
	//(check for these before calling the function, so that you can display a user-friendly error message)

	void Order::setQuantity(int index, int quant) {
		assert(!placed);
		assert(index < laptops.getLength());
		laptops.moveToIndex(index);
		price -= laptops.getIterator().price;
		laptops.getIterator().setQuantity(quant);
		price += laptops.getIterator().price;
	}
	//Pre: !Placed
	//Pre: Index < length of list
	//changes the quantity variable for laptop at index + updates teh price

	void Order::placeOrder(int daysToShip)	//TODO: finish writing this
	//places the order; sets it as ready to ship

	void Order::stopOrder() {
		assert(!shipped);
		placed = false;
		shippingSpeed = dayPlaced = 0;
		//TODO: When order is not placed, remove from maxheap
	}
	//"un-places" the order
	//Pre: !shipped

	bool Order::operator>(const Order& order) {
		if (this -> getArriveBy() < order.getArriveBy()) {
			return true;
		} else {
			return false;
		}
	}
	//returns true if the first order is higher priority. That is, compares priority; item on left is greater priority.

	bool Order::operator<(const Order& order) {
		if (this -> getArriveBy() > order.getArriveBy()) {
			return true;
		} else {
			return false;
		}
	}


	bool Order::operator>=(const Order& order) {
		if (this -> getArriveBy() <= order.getArriveBy()) {
			return true;
		} else {
			return false;
		}
	}

	bool Order::operator<=(const Order& order) {
		if (this -> getArriveBy() >= order.getArriveBy()) {
			return true;
		} else {
			return false;
		}
	}

	void Order::print(ostream & out) {
		out << fixed << setw(10) endl << "Total value: $" << price << "Ship by: " << //TODO: finish writing print methods - write a detailed print that displays all the laptops ordered (this is just a quick 1-line overview)
	}
