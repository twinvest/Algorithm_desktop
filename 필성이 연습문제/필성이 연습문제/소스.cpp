#include<iostream>
#include<stdio.h>
using namespace std;

void Set(int**pp, int a);

void main()
{
	int a;
	int * p = &a;
	int** pp = &p;

	Set(pp, 3);
	cout << a << endl;
}

void Set(int**pp, int a)
{
	cout << *pp;
}