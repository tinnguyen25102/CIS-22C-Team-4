/*
 * User.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: vupham
 */

#include "User.h"
#include <iostream>
#include <iomanip>
using namespace std;

User::User() {
	username = "";
	password = "";
	firstname = "";
	lastname = "";
	isEmployee = true;
}

string User::getUsername() const {
	return username;
}

string User::getPassword() const {
	return password;
}

string User::getFirstname() const {
	return firstname;
}

string User::getLastname() const {
	return lastname;
}

bool User::getIsEmployee() const {
	return isEmployee;
}

void User::setUsername(string username) {
	this->username = username;
}

void User::setPassword(string password) {
	this->password = password;
}

void User::setFirstname(string firstname) {
	this->firstname = firstname;
}

void User::setLastname(string lastname) {
	this->lastname = lastname;
}

void User::setIsEmployee(bool isEmployee) {
	this->isEmployee = isEmployee;
}


