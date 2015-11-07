#include <iostream>#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;

	if (mySize == 0)
		return;

	Node * origPtr, *lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

// Traverse the LinkedList and process data in each node
void LinkedList::traverse()
{
	Node * ptr = first;
	ElementType sum = 0;

	while (ptr != NULL)
	{
		// Process part of data
		// For example find sum of all data.
		sum += ptr->data;
		ptr = ptr->next;
	}
	return;
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

bool LinkedList::empty(){
	return (mySize == 0);
}

///////////////////////////////////////////Project 2 Functions
//	1.	//
int LinkedList::count(int num) const{
	if (mySize == 0){
		cout << "Your list is empty" << endl;
		return NULL;
	}
	else{
		Node * ptr = first;
		int counter = 0;
		for (int i = 0; i < mySize; i++){
			if (num == ptr->data)
				counter++;
			ptr = ptr->next;
		}
		return counter;
	}
}

ElementType LinkedList::GetNth(int position) const{
	Node * ptr = first;
	if (mySize == 0){
		cout << "Your list is empty." << endl;
		return NULL;
	}
	else if (mySize <= position || position < 0){
		return NULL;
	}
	else{
		for (int i = 0; i < position; i++){
			ptr = ptr->next;
		}
		return ptr->data;
	}
}

ElementType LinkedList::Pop(){
	Node * ptr = first;
	if (mySize == 0){
		cout << "LIST IS EMPTY" << endl;
		return NULL;
	}
	else if (mySize == 1){
		first = NULL;
		mySize = 0;
		return ptr->data;
	}



	first = ptr->next;

	//Making old top point to nothing
	ptr->next = NULL;

	mySize--;

	return ptr->data;
}

void LinkedList::Append(LinkedList a){
	Node * ptr = first;
	if (mySize == 0 || a.empty()){
		cout << "Error: Your list is empty. Nothing was appended." << endl;
		return;
	}
	else{
		for (int i = 0; i < mySize; i++){
			ptr = ptr->next;
		}

		int i = mySize;
		int x = 0;
		while (a.GetNth(x) != NULL){
			mySize++;
			insert(a.GetNth(x), i);
			x++; i++;
		}
	}
	return;
}

void LinkedList::Duplicates(){
	if (mySize == 0){
		cout << "Error: Your list is empty." << endl;
		return;
	}
	else if (mySize == 1){
		return;
	}
	
	Node * ptr = first;
	Node * dupl = ptr->next;
	Node * movetmp = first;

	for (int i = 0; i < (mySize - 1); i++){
		for (int y = 1; y < mySize; y++){
			if (dupl->next == NULL)
				break;
			if (ptr->data == dupl->data){
				movetmp = first;
				for (int z = 0; z < (y-1); z++){
					movetmp = movetmp->next;
				}
				movetmp->next = dupl->next;
				dupl = movetmp;
				mySize--;
			}
			dupl = dupl->next;
		}
		ptr = ptr->next;
		dupl = ptr->next;
	}
}
