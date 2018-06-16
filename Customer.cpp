/*
 * Customer.cpp
 * Tin Nguyen
 */

#include "Customer.h"
#include <iostream>
#include "Order.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Customer::Customer() {
	username = "";
	password = "";
	firstname = "";
	lastname = "";
	isEmployee = false;
	address = "";
	city = "";
	zip = 0;
	email = "";
}

Customer::Customer(string username, string password, string firstName, string lastName, bool isEmployee, string address, string city, unsigned zip, string email) {
	this->username = username;
	this->password = password;
	this->firstname = firstName;
	this->lastname = lastName;
	this->isEmployee = isEmployee;
	this->address = address;
	this->city = city;
	this->zip = zip;
	this->email = email;
}

string Customer::getAddress() const {
	return address;
}

string Customer::getCity() const {
	return city;
}

unsigned Customer::getZip() const {
	return zip;
}

string Customer::getEmail() const {
	return email;
}

void Customer::setAddress(string address) {
	this->address = address;
}

void Customer::setCity(string city) {
	this->city = city;
}

void Customer::setZip(unsigned zip) {
	this->zip = zip;
}

void Customer::setEmail(string email) {
	this->email = email;
}


void Customer::getOrder(ostream &out) const {
	out << order;
}

/*void Customer::getOrderList(ostream &out) const {
orders.displayList(out);	//TODO: Change this
}*/


void Customer::insertOrder(Order order) {
	orders.insertStop(order);
}

void Customer::removeOrder(Order order) {	// loop through the orders List to find order then remove it.
	orders.startIterator();
	while(orders.getIterator().operator <=(order)){
		orders.moveIterNext();
	}
	orders.removeIterator();
}

bool Customer::operator==(const Customer& customer) {
	return (firstname == customer.firstname && lastname == customer.lastname && username == customer.username && password == customer.password);
}

bool Customer::operator<(const Customer& customer) {
	if (firstname < customer.firstname)
		return true;
	else if (firstname == customer.firstname) {
		if (lastname < customer.lastname)
			return true;
		else if (lastname == customer.lastname) {
			if (username < customer.username)
				return true;
			else if (username == customer.username) {
				if (password < customer.password)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool Customer::operator>(const Customer& customer) {
	if (firstname > customer.firstname)
		return true;
	else if (firstname == customer.firstname) {
		if (lastname > customer.lastname)
			return true;
		else if (lastname == customer.lastname) {
			if (username > customer.username)
				return true;
			else if (username == customer.username) {
				if (password > customer.password)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void Customer::read(ifstream& in) {
	string temp;
	bool temp1;
	unsigned temp2;

	in >> temp;
	username = temp;
	in >> temp;
	password = temp;
	in >> temp;
	firstname = temp;
	in >> temp;
	lastname = temp;
	in >> temp1;
	isEmployee = temp1;
	getline(in, temp);
	address = temp;
	in >> temp;
	city = temp;
	in >> temp2;
	zip = temp2;
	in >> temp;
	email = temp;

	while (in.peek() == '\n')
		in.get();
}

void Customer::write(ostream& out) {
	out << username << '\n';
	out << password << '\n';
	out << firstname << '\n';
	out << lastname << '\n';
	out << isEmployee << '\n';
	out << address << '\n';
	out << city << '\n';
	out << zip << '\n';
	out << email << '\n' << '\n';
}



void Customer:: printCustomerHeader(ostream& out){
	out << left << setw(15) << "Firstname" << setw(15) << "Lastname" << setw(15) << "address" << setw(15) << "city" << setw(15) << "zip" << "email" << '\n';
}

std::ostream& operator<<(ostream& out, const Customer customer) {

	out << left << setw(15) << customer.firstname << setw(15) << customer.lastname << setw(15) << customer.address << setw(15) << customer.city << setw(15) << customer.zip << customer.email << '\n';
	return out;
}

string Customer:: toString(const Customer& customer, ostream& out){
string str;
stringstream ss;
ss << customer.getZip(); //convert int to a string
str = customer.firstname + "," + customer.lastname +"," + customer.address+"," +customer.city +"," + ss.str();
return str;
}



