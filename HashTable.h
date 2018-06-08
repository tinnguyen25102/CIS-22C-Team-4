/*
 * HashTable.h
 *
 *  Created on: May 31, 2018
 *      Author: tinnguyen
 */


#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include "Customer.h"
#include "Employee.h"
#include "List.h"
#include <iostream>

using namespace std;

template <class htdata>
class HashTable {
public:
    /**Constructors*/

    HashTable(){}
    //constructor

    ~HashTable(){}
    //destructor


    /**Access Functions*/

    int hash(string key) const;


    void remove(Customer c);

    int search(htdata f) const;


    void insert(htdata c);


    void Display(htdata c,ostream& out) ;

private:
    static const int SIZE = 100;
    List<htdata> Table[SIZE];
};

template<class htdata>
int HashTable<htdata>:: hash(string key) const {
	string temp;
		int index, sum = 0;
		for (int i = 0; i < key.length(); i++){
			sum += (int) key[i]; //summing the ASCII values for each character in the stringindex = sum % SIZE; //dividing the summed ASCII values by TABLE_SIZE//and storing remainder as my indexreturn index;}
	}
	index= sum % SIZE;
	return index;
}

template<class htdata>
void HashTable<htdata>::insert(htdata c) {
	int index = hash (c.getFirstname()+ c.getLastname());
	Table[index].insertStop(c);
}


template<class htdata>
void HashTable<htdata>::Display(htdata c, ostream& out) {
	int index = hash ( c.getFirstname()+ c.getLastname());
Table[index].displayNumberedList(cout);		//display whole list of customer.
}

template<class htdata>
int HashTable<htdata>::search (htdata f) const{
	int index = hash (f.getFirstname()+ f.getLastname());
	return Table[index].linearSearch(f);    //return index of customer, working on return multiple customer
}


//new function getBucket

#endif /* HASHTABLE_H_ */
