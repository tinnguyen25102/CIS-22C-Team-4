/*
 * Employee.cpp
 * Vu Pham
 */

#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Employee::Employee() {
	username = "";
	password = "";
	firstname = "";
	lastname = "";
	isEmployee = true;
}

Employee::Employee(string username, string password, string firstName, string lastName, bool isEmployee) {
	this->username = username;
	this->password = password;
	this->firstname = firstname;
	this->lastname = lastname;
	this->isEmployee = isEmployee;
}

bool Employee::operator==(const Employee& employee) {
	return (firstname == employee.firstname && lastname == employee.lastname && username == employee.username && password == employee.password);
}

bool Employee::operator<(const Employee& employee) {
	if (firstname < employee.firstname)
		return true;
	else if (firstname == employee.firstname) {
		if (lastname < employee.lastname)
			return true;
		else if (lastname == employee.lastname) {
			if (username < employee.username)
				return true;
			else if (username == employee.username) {
				if (password < employee.password)
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

bool Employee::operator>(const Employee& employee) {
	if (firstname > employee.firstname)
		return true;
	else if (firstname == employee.firstname) {
		if (lastname > employee.lastname)
			return true;
		else if (lastname == employee.lastname) {
			if (username > employee.username)
				return true;
			else if (username == employee.username) {
				if (password > employee.password)
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

void Employee::read(ifstream& in) {
	string temp;
	bool temp1;

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

	while (in.peek() == '\n')
		in.get();
}

void Employee::write(ostream& out) {
	out << username << '\n';
	out << password << '\n';
	out << firstname << '\n';
	out << lastname << '\n';
	out << isEmployee << '\n' << '\n';
}

ostream& operator<<(ostream& out, const Employee& employee) {
	out << left << setw(15) << employee.firstname << employee.lastname << "\n";
	return out;
}


