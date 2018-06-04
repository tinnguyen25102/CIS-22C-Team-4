/*
 * User.h
 *
 *  Created on: May 31, 2018
 *      Author: tinnguyen
 */

#ifndef USER_H_
#define USER_H_
#include "Customer.h"
#include <iostream>
using namespace std;

class user : public Customer {
public:
	user();
	user(string username, string password, bool isEmployee);

	//
};



#endif /* USER_H_ */
