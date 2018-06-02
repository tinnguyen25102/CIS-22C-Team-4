/*
 * Class.h
 *
 *  Created on: May 31, 2018
 *      Author: tinnguyen
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include "List.h"
#include "Order.h"
#include <iostream>
using namespace std;

class Customer {
private:
	string first_name;
	string last_name;
	string address;
	string city;
	string state;
	int zip;
	List<Order> orders;

public:

	Customer() {
		first_name = "";
		last_name = "";
		address = "";
		city = "";
		state = "";
		zip = 0;
		//orders=;
	}
	Customer(string fname, string lname, string address, string city, string state, int zip, orders order){
		this->first_name=fname;
		this->last_name=lname;
		this->address=address;
		this->city=city;
		this->state=state;
		this->zip=zip;
		this->orders=order;
	}

	//setters functions:
	void set_First_Name(string firstname){
		this->first_name = firstname;
	}
	void set_Last_Name(string lastname){
			this->last_name = lastname;
		}
	void set_Address(string address){
		this->address=address;
	}
	void set_State(string state){
		this->state=state;
	}
	void set_City(string city){
		this->city=city;
	}
	void set_Zip(int zip){
		this->zip=zip;
	}

	//getters function:

	string get_First_Name(){
		return first_name;
	}
	string get_Last_Name(){
		return last_name;
	}
	string get_Address(){
		return address;
	}
	string get_State(){
		return state;
	}
	string get_City(){
		return city;
	}
	int get_Zip(){
		return zip;
	}

	bool operator==(const Customer& customer) {
		return (first_name == customer.first_name && last_name == customer.last_name);
	}

	bool operator<(const Customer& customer) {
		if (first_name < customer.first_name)
			return true;
		else if (first_name == customer.first_name) {
			if (last_name < customer.last_name)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator>(const Customer& customer) {
			if (first_name > customer.first_name)
				return true;
			else if (first_name == customer.first_name) {
				if (last_name > customer.last_name)
					return true;
				else
					return false;
			}
			else
				return false;
		}

	void print(ostream& out) const {
		out << first_name << '\n'
			<< last_name << '\n'
			<< address << '\n'
			<< city << '\n'
			<< state << '\n'
			<< zip << '\n';
	}

ostream& operator<<(ostream& out, const Order& order){

	return out;
}

void add_Order(Order 0) {
	//insert
}

void remove_Order(Order o){
	//traverse n remove
}

};

#endif /* CUSTOMER_H_ */
