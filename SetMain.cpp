#include "Set.h"

using namespace std;

int main()
{	

	Set list;
	Set first;
	Set second;
	Set copylist;
	
	list.Insert(23);
	list.Insert(14);
	list.Insert(34);
	list.Insert(25);

	cout<< "Testing operator = :" << endl;
	first = list;
	cout<< first;
	cout<< endl;

	copylist.Insert(5);
	copylist.Insert(14);
	copylist.Insert(34);
	copylist.Insert(23);
	copylist.Insert(17);

	cout<< "Testing copy constructor :" << endl;
	second = copylist;
	cout<< second;
	cout<< endl;

	cout<< "Testing operator [] :" << endl;
	cout<< list[3]<< endl;
	cout<< "Testing operator < :" << endl;
	cout<< (copylist<list);
	cout<< endl;
	cout<< (list<copylist);
	cout<< endl;
	cout<< "Testing operator ^ :" << endl;
	cout<< (copylist^list);
	cout<< endl;
	cout<< "Testing operator + :" << endl;
	cout<< list+copylist;
	cout<<endl;
	cout<< "Testing operator - :" << endl;
	cout<< copylist-list;
	cout<< endl;
	cout<< list-copylist;
	cout<< endl;
	cout<< "Testing operator >> :" <<endl;
	bool insert = false;
	while(insert == false)
	{
		try
		{		
			cout<< "Add an integer to the Set list" << endl;
			cin>>list;
			insert = true;	
		}
		catch (Set::DuplicateException n)
		{	
			cout << "-Error Report- " << endl ;
			cout << "exception nature: " << n.message << endl ;
			cout << endl;
		}
	}
	char option ;
	int n;
	
	while (1)
	{	cout << "Options:  (I)nsert, (P)rint, (D)elete, (F)ind, (S)ize, (E)xit  " ;
		cin >> option ;
		cin.ignore() ;
		
		switch (option)
		{	
		case 'I':
		case 'i':
				try
				{		
					cout << "Enter integer: " ;
					cin >> n ;
					list.Insert(n) ;
					
				}
				catch (Set::DuplicateException n)
				{	
					cout << "-Error Report- " << endl ;
					cout << "exception nature: " << n.message << endl ;
					cout << endl;
				}
				break ;
		case 'P':  
		case 'p':	
			list.Print() ;
			break ;

		case 'D': 
		case 'd':	
			cout << "Enter integer to remove: " ;
			cin >> n ;
			list.Delete(n);
			break ;
		case 'F': 
		case 'f':	
			cout << "Enter integer to find: " ;
			cin >> n ;
			list.Find(n);
			break ;
		case 'S': 
		case 's':	
			cout << "The numbe of integers in the list is: "<< list.Size() << endl;
			break ;
		case 'E':  
		case 'e':
			system("pause") ;
			return 0 ;
		}
	}
	
}