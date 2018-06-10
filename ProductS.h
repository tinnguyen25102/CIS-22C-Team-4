#ifndef PRODUCTS_H_
#define PRODUCTS_H_

#include <iostream>
#include <string>

#include "Product.h"

using namespace std;

class ProductS : public Product {
public:
	ProductS();
	ProductS(string make, string model, double screenSize, unsigned cpuGen, unsigned year, double price);

	void operator=(const ProductS& product);
	//copies contents from Product to ProductS

	//Overriding functions
	bool operator==(const ProductS& product);
	//determines if this->product and product are the same
	bool operator<(const ProductS& product);
	//determines if this->product comes before product alphabetically BASED ON SECONDARY KEY (model) FIRST, THEN PRIMARY KEY (make)
	bool operator>(const ProductS& product);
	//determines if this->product comes after product alphabetically BASED ON SECONDARY KEY (model) FIRST, THEN PRIMARY KEY (make)
};



#endif /* PRODUCTS_H_ */
