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
#include "List.h"
#include "Order.h"
using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable(){}
    //constructor

    ~HashTable(){}
    //destructor


    /**Access Functions*/

    int hash(string key) const;
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int countBucket(int index) const;
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    int search(Customer c) const;
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(Customer c);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Customer c);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: b is in the table

    /**Additional Functions*/

    void DisplayCustomer(ostream& out) const;

private:
    static const int SIZE = 100;
    List<Customer> Table[SIZE];
};

int HashTable:: hash(string key) const {
		int index, sum = 0;
		for (int i = 0; i < key.length(); i++){
			sum += (int) key[i]; //summing the ASCII values for each character in the stringindex = sum % SIZE; //dividing the summed ASCII values by TABLE_SIZE//and storing remainder as my indexreturn index;}
	}
	index= sum % SIZE;
	return index;
}

void HashTable::insert(Customer c) {
	int index = hash(c.get_First_Name() + c.get_Last_Name());
	Table[index].insertStop(c);
}

int HashTable::search(Customer c) const {
	int index = hash(c.get_First_Name() + c.get_Last_Name());
	if (Table[index].linearSearch(c) != -1) { // if the book is in the table.
		return index;
	} else{
		return -1; //if book is not in the table}
	}
}

void HashTable::remove(Customer c){
	int index=hash(c.get_First_Name() + c.get_Last_Name());
	Table[index].startIterator();
	while(Table[index].getIterator().get_First_Name() != c.get_First_Name() && Table[index].getIterator().get_Last_Name() != c.get_Last_Name()){
		Table[index].moveIterNext();
	}
	Table[index].removeIterator();
}

int HashTable::countBucket(int index) const {
	assert(index>=0 && index <SIZE);
	return Table[index].getLength();
}

#endif /* HASHTABLE_H_ */
