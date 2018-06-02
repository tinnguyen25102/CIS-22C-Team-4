/*
 * ProductS.h
 *
 *  Created on: May 30, 2018
 *      Author: vupham
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_

#include "Product.h"
#include <iostream>
#include <string>
using namespace std;

class ProductS : public Product {
public:
	ProductS();
	ProductS(string make, string model, double screenSize, unsigned cpuGen, unsigned year, double price);

	void operator=(const Product& product);
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
