#include "Set.h"

SetNode::SetNode()
{
	numbers = 0 ;
	next = NULL ;
}

SetNode::SetNode(int n)
{   
	numbers = n ;
	next = NULL ;
}

Set::Set()
{
	head = new SetNode (0) ;
	head->next = new SetNode (100) ;
}
Set::~Set()
{
	SetNode *here = head, *after ;
	while (here != NULL)
	{	
		after = here -> next ;
		delete here;
		here = after ;
	}
}
Set::Set(const Set & obj)
{
	SetNode * copy= obj.head;
	head = new SetNode (0) ;
	head->next = new SetNode (100) ;
	while (copy != NULL)			
	{  
		if(copy->numbers != 0 && copy->numbers != 100)
		{
			Insert(copy->numbers);	
		}
		copy = copy->next;
	}

}
Set & Set::operator=(const Set &a)
{
	SetNode * copy= a.head;
	head = new SetNode (0) ;
	head->next = new SetNode (100) ;
	while (copy != NULL)			
	{  
		if(copy->numbers != 0 && copy->numbers != 100)
		{
			Insert(copy->numbers);	
		}
		copy = copy->next;
	}
	return *this;
}

bool Set::operator<( const Set & a)
{
	
	a.Size();
	this->Size(); 
	if ( this->Size() > a.Size()) return false;
	SetNode *here = head->next ;
	while ( here->next != NULL)
	{
		if (a.Find(here->numbers)== false) return false;
		here= here->next;
	}
	return true;

}
Set Set::operator^( const Set & a)
{
	Set result;
	SetNode *here = head->next ;
	while ( here->next != NULL)
	{
		if (a.Find(here->numbers)== true)
		{
			result.Insert(here->numbers);
		}
		here= here->next;
	}
	return result;
}
Set Set::operator+( const Set & a)
{
	Set result;
	SetNode *here = head->next ;
	while ( here->next != NULL)
	{
		result.Insert(here->numbers);
		here= here->next;
	}
	here = a.head->next;
	while ( here->next != NULL)
	{
		if (result.Find(here->numbers)!= a.Find(here->numbers) )
		{
			result.Insert(here->numbers);
		}
		here= here->next;
	}
	return result;
}
Set Set::operator-( const Set & a)
{
	Set result;
	SetNode *here = head->next ;
	while ( here->next != NULL)
	{
		if (a.Find(here->numbers)== false) 
		{
			result.Insert(here->numbers);
		}
		here= here->next;
	}
	return result;
}

int Set::operator[](int n)
{
	int count = 0;
	SetNode *here = head;
	SetNode *prev = head;
	for ( int i = 0; i < n && here->next != NULL; i++)
	{
		here= here->next;
	}
	return here->numbers;
}
ostream & operator<<( ostream & obj, const Set & a)
{
	SetNode *here = a.head->next;
	stringstream ss;
	while (here->next != NULL)
		{
			ss<< here->numbers <<", ";
			here = here->next;
		}
	obj<<ss.str();
	return obj;
}

istream & operator>>( istream & obj, Set & a)
{
	int temp;
	obj>> temp;
	a.Insert(temp);
	return obj;
}

bool Set::Find(int n) const
{
	SetNode *here = head;
	SetNode *prev = head;
	
	while (n != here->numbers && here->next != NULL) 
	{	
		prev = here ;
		here = here->next;
	}
	if (here->next != NULL)
	{	
		cout<< "The item is found" << endl;
		return true;
	}
	cout<< "not found" << endl;
	return false;
}

int Set::Size() const
{
	int count = 0;
	SetNode *here = head->next ;
	SetNode *prev = head ;
	while (here->numbers != 0 && here->numbers != 100) 
	{	
		prev = here ;
		here = here->next;
		count++;
	}
	return count;
}

void Set::Insert (int n)
{	
	SetNode *newnode = new SetNode(n) ;

	SetNode *here = head->next ; 
	SetNode *prev = head ;
	

	while (n >= here->numbers )  
	{	
		if( n == here->numbers || n == prev->numbers)
		{
			throw DuplicateException("You Are trying to put an integer that is already in the Set");
		}
		prev = here;
		here = here->next ;
	}

	prev->next = newnode ;
	newnode->next = here ;

}
void Set::Delete (int n)
{	
	SetNode *here = head->next ;
	SetNode *prev = head ;
	
	while (n != here->numbers && here->next != NULL) 
	{	
		prev = here ;
		here = here->next ;
	}
	if (here->next != NULL)
	{	
		prev->next = here->next ;
		delete here ;
	}
}
void Set::Print()
{    
	SetNode *here = head->next ;			
	
	while (here->next != NULL)			
	{     
		cout << here->numbers << endl ;
		here = here->next ;
	}
}