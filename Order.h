/*
 * Order.h
 *
 *  Created on: Jun 2, 2018
 *      Author: Andrew
 */

#ifndef ORDER_H_
#define ORDER_H_

#include "List.h"
#include "Product.h"
using namespace std;

class Order {
	
private:
	struct subOrder {
		Product * laptop;
		int quantity = 1;
		float price;
		subOrder(Product * toBuy) {
			laptop = toBuy;
			price = toBuy -> getPrice();
		}
		void setQuantity(int q) {
			quantity = q;
			price = laptop -> getPrice() * q;
		}
		void print(ostream & out) {
			out << endl << laptop -> getMake() << endl << "Quantity: " << quantity;
		}
	};
	List<subOrder> laptops;
	int shippingSpeed, dayPlaced;
	bool placed, shipped;
	float price;
	
public:
	
	/** constructors */

	Order();

	/** management functions - getters and setters*/

	int getArriveBy() const;
	//returns the date that the order should arrive, determined based on day order is placed and shipping speed

	int getDayPlaced() const;
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

	void stopOrder();
	//"un-places" the order

	bool operator>(const Order&);
	//Compares orders based on when they need to ship. Used for priority queue.

	bool operator<(const Order&);

	bool operator>=(const Order&);

	bool operator<=(const Order&);

	void print(ostream & out);

	void printDetailed(ostream & out);
};




#endif /* ORDER_H_ */
