/*
 * List.h
 * Andrew Maxwell
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <cstddef> //for NULL
#include <assert.h>
using namespace std;

template <class listdata> //list stores generic listdata

class List {

private:
    struct Node {
        listdata data;
        Node* next;
        Node* previous;

        Node(listdata newData){
            data = newData;
            next = NULL;
            previous = NULL;
        }
    };

    Node* start;
    Node* stop;
    Node* iterator;
    int length;

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes an empty list
    //Postcondition: start and stop initialized to null.
    //Length initialized to 0.

    List(const List<listdata> &oldList);
    //Copy constructor; creates a duplicate list
    //Postcondition: New list has same data as old list, stored
    //in different memory.

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: Deletes every node in the list
    //before the list object is destroyed.

    /**Accessors*/

    listdata getStart() const;
    //Returns the data at the start of the list
    //Precondition: Length of list >= 1.

    listdata getStop() const;
    //Returns the data at the end of the list
    //Precondition: Length of list >= 1.

    bool isEmpty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    listdata getIterator() const;
    //returns the data stored in the element pointed at by the iterator
    //Precondition: Iterator must be pointing at a list element

    bool offEnd() const;
    //Is false if iterator is pointing at a valid list element

    bool operator==(const List &rhs) const;
    //Compares two lists.

    bool isSorted() const;

    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function

private:

    bool isSorted(Node* node) const;
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.

public:

    int getIndex() const;
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered starting at 1 through the size of the list
    //Pre: !offEnd()

    int linearSearch(listdata data) const;
    //Iteratively searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Does not call the indexing functions in the implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    //Post: The iterator location has not been changed

    int binarySearch(listdata data) const;
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)
    //Post: The iterator location has not been changed

private:

    int binarySearch(int low, int high, listdata data) const;
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List
    //Post: The iterator location has not been changed

public:

    /**Manipulation Procedures*/

    void removeStart();
    //Removes the value stored in first node in the list
    //Precondition: Length of list >= 1.
    //Postcondition: First node of list is deleted. Start pointer
    //now points to second node in the list.

    void removeStop();
    //Removes the value stored in the last node in the list
    //Precondition: Length of list >= 1.
    //Postcondition: Last node of list is deleted. Stop pointer now
    //points to the new last node. Last node points to null.

    void insertStart (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition: Node created at the beginning of the list,
    //data stored in node.

    void insertStop(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both start and stop
    //Postcondition: Node created at end of list, data stored in node.

    void startIterator();
    //Sets the iterator to the start pointer

    void removeIterator();
    //Deletes the node pointed at by the iterator.
    //Precondition: Iterator must be pointing at a valid list node.

    void insertIterator(listdata data);
    //Inserts a list node after the one pointed at by the iterator.
    //Postcondition: New list node.
    //Precondition: Iterator must point at a valid node.

    void moveIterNext();
    //move iterator up list one

    void moveIterPrevious();
    //move iterator down list one

    void moveToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Nodes are numbered starting at 1 through the size of the List
    //Pre: size != 0
    //Pre: index <= size

    /**Additional List Operations*/

    void displayList(ostream &out) const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints a empty newline character if it's empty..

    void displayNumberedList(ostream &out) const;
    //Prints to the console the value of each data in the list, with a number.
    //Prints an empty newline character if the list is empty.

    void displayReverse(ostream& out) const;
    //Wrapper function that calls the private displayReverse helper function to print a list in reverse
    //prints nothing if the List is empty

private:

    void displayReverse(Node* node, ostream& out) const;
    //Helper function for the public displayReverse wrapper function.
    //Recursively prints the data in a List in reverse.
};

#endif /* LIST_H_ */

/**Function Declarations*/
/**Constructors and Destructors*/

template <class listdata>   //Default constructor
List<listdata>::List() {
    start = stop = iterator = NULL;
    length = 0;
}

template <class listdata>
List<listdata>::List(const List<listdata> &oldList) {   //Copy constructor
	length = 0;
	if (oldList.length == 0)
	{
		start = stop = iterator = NULL;
	}
	else
	{
		Node * temp = oldList.start;
		while (temp != NULL)
		{
			insertStop(temp -> data);
			temp = temp -> next;
		}
	}
}

template <class listdata>   //Destructor
List<listdata>::~List()
{
    Node* b = start;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b -> next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}

/**Accessors*/

template <class listdata>   //returns data in first element
listdata List<listdata>::getStart() const
{
    assert(start);
    return start -> data;
}

template <class listdata>   //returns data in last element
listdata List<listdata>::getStop() const
{
    assert(stop);
	return stop -> data;
}

template <class listdata>   //returns whether the list is empty
bool List<listdata>::isEmpty() const
{
    return (length == 0);
}

template <class listdata>   //returns number of elements
int List<listdata>::getLength() const
{
	return length;
}

template <class listdata>   //returns data contained in element at iterator
listdata List<listdata>::getIterator() const
{
    assert(iterator);
    return iterator -> data;
}

template <class listdata>   //Returns false if iterator points to an element.
bool List<listdata>::offEnd() const
{
    return (iterator == NULL);
}

template <class listdata>   //== operator overload
bool List<listdata>::operator==(const List &rhs) const
{
    Node * thisIterator = start;
    Node * thatIterator = rhs.start;
    bool same = true;
    while (thisIterator and thatIterator)
    {
        if (thisIterator -> data != thatIterator -> data)
        {
            same = false;
            break;
        }
        else
        {
            thisIterator = thisIterator -> next;
            thatIterator = thatIterator -> next;
        }
    }
    if (thisIterator != thatIterator)
    {
        same = false;
    }
    return same;
}

template <class listdata>
bool List<listdata>::isSorted() const
{
    if (length < 2) {
        return true;
    }
    else {
        return isSorted(start);
    }
}

template <class listdata>
bool List<listdata>::isSorted(Node* node) const
{
    bool inOrder = true;
    if (node -> next != NULL) {
        if (node -> next -> data > node -> data and isSorted(node -> next)) {
            inOrder = true;
        }
        else {
            inOrder = false;
        }
    }
    return inOrder;
}

template <class listdata>
int List<listdata>::getIndex() const {
    assert(iterator != NULL);
    Node * temp = start;
    int count = 1;
    while (temp != iterator) {
        temp = temp -> next;
        count++;
    }
    return count;
}

template <class listdata>
int List<listdata>::linearSearch(listdata data) const {
    Node * tempIter = start;
    int index = 1;
    bool found = false;
    while (tempIter != NULL) {
        if (data == tempIter -> data) {
            found = true;
            break;
        }
        else {
            index++;
            tempIter = tempIter -> next;
        }
    }
    if(found) {
        return index;
    }
    else {
        return -1;
    }
}

template <class listdata>
int List<listdata>::binarySearch(listdata data) const {
    assert(length > 0);
    assert(isSorted());
    return binarySearch(0, length, data) + 1;
}

template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) const {
    Node * tempIter = start;
    for (int i = 0; i < (low + high) / 2; i++) {
        tempIter = tempIter -> next;
    }
    if (tempIter -> data == data) {
        return ((low + high) / 2);
    }
    else if (low + 1 == high) {
        return -2;
    }
    else if (tempIter -> data < data) {
        return binarySearch((low + high) / 2, high, data);
    }
    else {
        return binarySearch(low, (low + high) / 2, data);
    }
}



/**Manipulation Procedures*/

template <class listdata>   //Removes first node in the list.
void List<listdata>::removeStart()
{
    assert(start);
    if (length == 1)
	{
		delete start;
		start = stop = NULL;
		length--;
	}
	else
	{
		start = start -> next;
		delete start -> previous;
		start -> previous = NULL;
		length--;
	}
}

template <class listdata>   //removes last element in the list
void List<listdata>::removeStop()
{
    assert(stop);
    if (length == 1)
	{
		delete stop;
		start = stop = NULL;
		length = 0;
	}
	else
	{
		stop = stop -> previous;
		delete stop -> next;
		stop -> next = NULL;
		length--;
	}
}

template <class listdata>   //Inserts node at start of list
void List<listdata>::insertStart(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
        start = N;
        stop = N;
    }
    else
    {
        N -> next = start;
        start -> previous = N;
        start = N;
    }
    length++;
}

template <class listdata>   //Inserts node at end of list
void List<listdata>::insertStop(listdata data)
{
	Node* N = new Node(data);
	if (length == 0)
	{
		start = N;
		stop = N;
	}
	else
	{
		stop -> next = N;
		N -> previous = stop;
		stop = N;
	}
	length++;
}

template <class listdata>   //moves iterator to start of list
void List<listdata>::startIterator()
{
    iterator = start;
}

template <class listdata>   //removes element pointed at by iterator.
void List<listdata>::removeIterator()
{
    assert(iterator);
    if (iterator -> next)
    {
    iterator -> next -> previous = iterator -> previous;
    }
    else
    {
        stop = iterator -> previous;
    }
    if (iterator -> previous)
    {
    iterator -> previous -> next = iterator -> next;
    }
    else
    {
        start = iterator -> next;
    }
    delete iterator;
    iterator = NULL;
    length--;
}

template <class listdata>   //inserts an element after the element the iterator
void List<listdata>::insertIterator(listdata data)
{
    assert(iterator);
    Node * newNode = new Node(data);
    if (iterator -> next)
    {
        iterator -> next -> previous = newNode;
        newNode -> next = iterator -> next;
    }
    else
    {
        stop = newNode;
    }
    newNode -> previous = iterator;
    iterator -> next = newNode;
    length++;
}

template <class listdata>   //moves iterator towards the end
void List<listdata>::moveIterNext()
{
    assert(iterator);
    iterator = iterator -> next;
}

template <class listdata>   //moves iterator towards the start
void List<listdata>::moveIterPrevious()
{
    assert(iterator);
    iterator = iterator -> previous;
}

template <class listdata>
void List<listdata>::moveToIndex(int index) {
    index--;
    assert (length > 0);
    assert (index <= length);
    startIterator();
    for (int i = 0; i < index; i++) {
        moveIterNext();
    }
}

/** Display functions */

template <class listdata>   //Displays the list
void List<listdata>::displayList(ostream &out) const
{
    Node* temp = start; //create a temporary iterator
    while (temp != NULL) {
    	out << temp->data << " ";	//outputs data
    	temp = temp->next;		//moves iterator to next node
    }
    out << endl; //ends line after outputting list
}

template <class listdata>   //displays list vertically w/ numbers.
void List<listdata>::displayNumberedList(ostream &out) const
{
    Node* temp = start;
    int i = 1;
    while (temp != NULL)
    {
        out << "#" << i << ": " << temp -> data << endl;
        temp = temp -> next;
        i++;
    }
}

template <class listdata> //displays list in reverse - public wrapper function
void List<listdata>::displayReverse(ostream &out) const
{
    cout << endl;
    if (stop) {
        displayReverse(stop, out);
    }
}

template <class listdata> //displays list in reverse - recursive helper function
void List<listdata>::displayReverse(Node * node, ostream &out) const
{
    out << node -> data << " ";
    if (node -> previous != NULL) {
        displayReverse(node -> previous, out);
    }
}




