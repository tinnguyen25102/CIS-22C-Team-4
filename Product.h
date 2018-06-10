/*
 * Product.h
 * Vu Pham
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string make;
	string model;
	double screenSize;
	unsigned cpuGen;
	unsigned year;
	double price;

public:
	Product();
	Product(string make, string model, double screenSize, unsigned cpuGen, unsigned year, double price);

	string getMake() const;
	string getModel() const;
	double getScreenSize() const;
	unsigned getCpuGen() const;
	unsigned getYear() const;
	double getPrice() const;

	void setMake(string make);
	void setModel(string model);
	void setScreenSize(double screenSize);
	void setCpuGen(unsigned cpuGen);
	void setYear(unsigned year);
	void setPrice(double price);

	bool operator==(const Product& product);
	//determines if this->product and product are the same
	bool operator<(const Product& product);
	//determines if this->product comes before product alphabetically BASED ON PRIMARY KEY (make) FIRST, THEN SECONDARY KEY (model)
	bool operator>(const Product& product);
	//determines if this->product comes after product alphabetically BASED ON PRIMARY KEY (make) FIRST, THEN SECONDARY KEY (model)

	friend ostream& operator<<(ostream& out, const Product& product);
	//prints all fields using a column format
	void print(ostream& out) const;
	//Print in the format of:
	//<make>
	//<model>
	//<screenSize>
	//<cpuGen>
	//<year>
	//<price>
};


#endif /* PRODUCT_H_ */
