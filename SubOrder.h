#ifndef SRC_SUBORDER_H_
#define SRC_SUBORDER_H_

#include "Product.h"

struct subOrder {
	Product * laptop;
	int quantity;
	float price;
	subOrder() {
		laptop = NULL;
		price = 0;
		quantity = 1;
	}
	subOrder(Product * toBuy) {
		laptop = toBuy;
		price = toBuy->getPrice();
		quantity = 1;
	}
	void setQuantity(int q) {
		quantity = q;
		price = laptop -> getPrice() * q;
	}
	int getQuantity() {
		return quantity;
	}
	friend ostream & operator<<(ostream & out, const subOrder& SO) {
		out << " " << SO.laptop -> getMake() << SO.laptop -> getModel() << endl << "Quantity: " << SO.quantity;
		return out;
	}
	bool operator==(const subOrder &rhs) {
		return (*laptop == *rhs.laptop and quantity == rhs.quantity);
	}
};

#endif /* SRC_SUBORDER_H_ */
