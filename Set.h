// A linked-list of names
#ifndef _LLIST_H
#define _LLIST_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std ;

// Create a data type for the linked list node
class SetNode
{  
public:	
	int numbers;
	SetNode() ;
	SetNode(int) ;
	SetNode *next;
}; 

class Set
{  
private:
	SetNode *head;
public:
	Set();
	~Set();
	Set( const Set & obj);
	bool operator<( const Set & a);
	Set operator^( const Set & a);
	Set operator+( const Set & a);
	Set operator-( const Set & a);
	Set & operator = (const Set & a);
	int operator [](int);
	friend ostream & operator<<(ostream&, const Set &);
	friend istream & operator>>( istream&, Set &);
	void Insert (int);
	void Delete (int);	
	bool Find(int) const;
	void Print();
	int Size() const;
	class DuplicateException
	{
	public:
		public:
		string message ; 
		DuplicateException(string errorm)
		{
			message = errorm;
		}

	} ;
};

#endif