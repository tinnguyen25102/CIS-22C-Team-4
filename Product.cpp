/*
 * Product.cpp
 * Vu Pham
 */

#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;


Product::Product() {
	make = "";
	model = "";
	screenSize = 0.0;
	cpuGen = 0;
	year = 0;
	price = 0;
}

Product::Product(string make, string model, double screenSize, unsigned cpuGen, unsigned year, double price) {
	this->make = make;
	this->model = model;
	this->screenSize = screenSize;
	this->cpuGen = cpuGen;
	this->year = year;
	this->price = price;
}

string Product::getMake() const {
	return make;
}

string Product::getModel() const {
	return model;
}

double Product::getScreenSize() const {
	return screenSize;
}

unsigned Product::getCpuGen() const {
	return cpuGen;
}

unsigned Product::getYear() const {
	return year;
}

double Product::getPrice() const {
	return price;
}

void Product::setMake(string make) {
	this->make = make;
}

void Product::setModel(string model) {
	this->model = model;
}

void Product::setScreenSize(double screenSize) {
	this->screenSize = screenSize;
}

void Product::setCpuGen(unsigned cpuGen) {
	this->cpuGen = cpuGen;
}

void Product::setYear(unsigned year) {
	this->year = year;
}

void Product::setPrice(double price) {
	this->price = price;
}

bool Product::operator==(const Product& product) {
	return (make == product.make && model == product.model);
}

bool Product::operator<(const Product& product) {
	if (make < product.make)
		return true;
	else if (make == product.make) {
		if (model < product.model)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Product::operator>(const Product& product) {
	if (make > product.make)
		return true;
	else if (make == product.make) {
		if (model > product.model)
			return true;
		else
			return false;
	}
	else
		return false;
}

ostream& operator<<(ostream& out, const Product& product) {
	out << left << setw(16) << product.make << setw(32) << product.model << setw(16)
			<< product.screenSize << setw(16) << product.cpuGen << setw(16) << product.year << product.price << "\n";
	return out;
}

void Product::print(ostream& out) const {
	out << make << '\n'
		<< model << '\n'
		<< screenSize << '\n'
		<< cpuGen << '\n'
		<< year << '\n'
		<< price << '\n';
}
