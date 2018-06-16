/*
 * Employee.h
 * Vu Pham
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

#include "User.h"

using namespace std;

class Employee : public User {
public:
	Employee();
	Employee(string username, string password, string firstName, string lastName, bool isEmployee);

	//check firstname -> lastname -> username -> password
	bool operator==(const Employee& employee);
	bool operator<(const Employee& employee);
	bool operator>(const Employee& employee);

	void read(ifstream& in);		//read data from file
	void write(ostream& out);	//write data to file

	friend ostream& operator<<(ostream& out, const Employee& employee);		//display in console
};



#endif /* EMPLOYEE_H_ */
