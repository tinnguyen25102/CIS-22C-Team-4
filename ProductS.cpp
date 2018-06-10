#include "ProductS.h"
#include <iostream>
using namespace std;

ProductS::ProductS() {
	make = "";
	model = "";
	screenSize = 0.0;
	cpuGen = 0;
	year = 0;
}

ProductS::ProductS(string make, string model, double screenSize, unsigned cpuGen, unsigned year, double price) {
	this->make = make;
	this->model = model;
	this->screenSize = screenSize;
	this->cpuGen = cpuGen;
	this->year = year;
	this->price = price;
}

void ProductS::operator=(const ProductS& product) {
	make = product.getMake();
	model = product.getModel();
	screenSize = product.getScreenSize();
	cpuGen = product.getCpuGen();
	year = product.getYear();
	price = product.getPrice();
}

bool ProductS::operator==(const ProductS& product) {
	return (model == product.model && make == product.make);
}

bool ProductS::operator<(const ProductS& product) {
	if (model < product.model)
		return true;
	else if (model == product.model) {
		if (make < product.make)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool ProductS::operator>(const ProductS& product) {
	if (model > product.model)
		return true;
	else if (model == product.model) {
		if (make > product.make)
			return true;
		else
			return false;
	}
	else
		return false;
}

