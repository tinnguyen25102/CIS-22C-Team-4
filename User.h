/*
 * User.h
 * Vu Pham
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
	string username;
	string password;
	string firstname;
	string lastname;
	bool isEmployee;

public:
	User();

	string getUsername() const;
	string getPassword() const;
	string getFirstname() const;
	string getLastname() const;
	bool getIsEmployee() const;

	void setUsername(string username);
	void setPassword(string password);
	void setFirstname(string firstname);
	void setLastname(string lastname);
	void setIsEmployee(bool isEmployee);

};


#endif /* USER_H_ */
