#include<iostream>
using namespace std;

#define multifly(x, y) x*y

void main()
{
	cout << multifly(1 + 1, 1 + 2) << endl;

	cout << multifly(1 + 1, 1 + 2) / multifly(1 + 1, 1 + 2) << endl;
}