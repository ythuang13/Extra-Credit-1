/*
*   Huang, Yitian
*
*   November 17, 2020
*
*   CS A250
*   Extra Credit 1
*/

//#include "Node.cpp"
//#include "Node.h"
#include "SLL.cpp"
#include "SLL.h"

#include <iostream>

using namespace std;

int main()
{

	SLL<int> s1;
	SLL<int> s2;
	s1.push(1);
	cout << "s1.push(1)\n"<< "s1: " << s1 << "\n\n";
	s2 = s1;
	s1.push(2);
	s2.push(3);
	cout << "s2 = s1, s1.push(2), s2.push(3)\n";
	cout << "s1: " << s1 << "\n";
	cout << "s2: " << s2 << "\n\n";

	int temp = s1.pop();
	s2.clear();
	cout << "After s1.pop() and s2.clear()\n";
	cout << "pop: " << temp << "\n";
	cout << "s1: " << s1 << "\n";
	cout << "s2: " << s2 << "\n\n";

	SLL<int> s3(s1);
	s1.push(42);
	cout << "copy constructor s3: " << s3 << "\n";

	system("Pause");
	return 0;
}
