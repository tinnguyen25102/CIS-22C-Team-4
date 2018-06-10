#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <string>

#include "List.h"
#include "Order.h"
#include "User.h"
using namespace std;

class Order;

class Customer : public User {
private:
	string address;
	string city;
	unsigned zip;
	string email;
	List<Order> orders;
	Order order;

public:
	Customer();
	Customer(string username, string password, string firstName, string lastName, bool isEmployee, string address, string city, unsigned zip, string email);
	//No orders in constructor

	string getAddress() const;
	string getCity() const;
	unsigned getZip() const;
	string getEmail() const;

	void setAddress(string address);
	void setCity(string city);
	void setZip(unsigned zip);
	void setEmail(string email);

	void displayCustomer(Customer c, ostream& out);
	void getOrderList(ostream &out) const;		//print list of orders
	void insertOrder(Order order);				//insert new order to list
	void removeOrder(Order order);				//remove an order from list

	bool operator==(const Customer& customer);
	bool operator<(const Customer& customer);
	bool operator>(const Customer& customer);

	void printCustomerHeader(ostream& out);
	string toString(const Customer& customer, ostream& out);

	void read(ifstream& in);	//read data from file
	void write(ostream& out);	//write data to file

	friend ostream& operator<<(ostream& out, const Customer customer);		//display in console

};



#endif /* CUSTOMER_H_ */
