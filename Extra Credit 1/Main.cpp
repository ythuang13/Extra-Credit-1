/*
	Huang, Yitian
	Moore, Jaden

	December 1, 2020

	CS A250
	Extra Credit 1
*/

#include "SLL.cpp"

#include <iostream>

using namespace std;

int main()
{
	SLL<int> list1;
	SLL<int> list2;

	list1.push( 1 );
	list1.push( 2 );
	list1.push( 3 );
	//list1.push( 4 );
	//list1.push( 5 );
	//list1.push( 6 );

	if ( list1.find( 2 ) )
	{
		cout << "found";
	}
	else
	{
		cout << "not found";
	}


	cout << "List 1: " << list1 << "\n";
	list2 = list1;

	cout << "After assignment operator\n";
	cout << "List 1: " << list1 << "\n";
	cout << "List 2: " << list2 << "\n\n";

	SLL<int> s3( list1 );
	cout << "Copy constructor List 3: " << s3 << "\n";


	int temp = list1.pop();
	cout << endl << temp << endl;
	cout << list1 << endl;

	list2.clear();
	cout << "After s1.pop() and s2.clear()\n";
	cout << "pop: " << temp << "\n";
	cout << "s1: " << list1 << "\n";
	cout << "s2: " << list2 << "\n\n";

	cout << "\noperator= testing: \n";
	list1.clear();
	list2.clear();
	s3.clear();


	list1.push( 3 );
	list2.push( 1 );
	list1 = list2;
	cout << "s1: " << list1 << "\n";
	cout << "s2: " << list2 << "\n";

	system( "Pause" );
	return 0;
}
