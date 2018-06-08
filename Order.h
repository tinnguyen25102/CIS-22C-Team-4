/*
 * Order.h
 *
 *  Created on: Jun 2, 2018
 *      Author: Andrew Maxwell
 */

#ifndef ORDER_H_
#define ORDER_H_

#include "List.h"
#include "SubOrder.h"
#include "BST.h"
#include <ctime>
using namespace std;

class Order {
	
private:
	List<subOrder> laptops;
	int shippingSpeed;
	time_t timePlaced, arriveBy;
	bool placed, shipped;
	float price;	//TODO: Figure out how to handle shipping/delivery. E.g. have an employee enter when it's delivered, or have it record a ship time and chnage it to delivered after the shipping time has elapsed?
	
public:
	
	/** constructors */

	Order();

	/** management functions - getters and setters*/

	string getArriveBy() const;
	//returns the date that the order should arrive, determined based on day order is placed and shipping speed

	string getDayPlaced() const;
	//returns the date the order was placed

	int getShippingSpeed() const;
	//returns the shipping speed

	float getPrice();
	//returns the total price of all of the items.

	bool isPlaced() const;
	//returns whether the order has been placed or not

	void setIsPlaced(bool isPlaced) ;

	bool isShipped() const;
	//returns whether the order has been shipped. If the order has been shipped, no further modification is allowed.

	void ship();
	//sets the order to shipped.

	void addLaptop(Product * newLaptop);
	//Adds a new laptop. If laptop matches existing laptop, increment by 1. Changes price of order.
	//Pre: !isShipped
	
	void removeLaptop(int index);
	//removes a laptop from the list, by index. Changes price of order.
	//Pre: !isShipped
	//Pre: Index < length of list
	//(check for these before calling the function, so that you can display a user-friendly error message)

	void setQuantity(int index, int quant);
	//changes the quantity variable for laptop at index

	void placeOrder(int daysToShip);
	//places the order; sets it as ready to ship

	bool operator>(const Order&);
	//Compares orders based on when they need to ship. Used for priority queue.

	bool operator<(const Order&);

	bool operator>=(const Order&);

	bool operator<=(const Order&);

	void print(ostream & out);

	void printDetailed(ostream & out);

	void save(ostream & out);

	Order * load(istream & in, BST<Product> & products);
};


#endif /* ORDER_H_ */
