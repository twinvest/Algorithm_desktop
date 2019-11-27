#include<algorithm>
#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;
int temp;
int travel_distace;
int money = 20000;

vector<int> v;
int main()
{
	
	
	string line;
	getline(cin, line);
	stringstream ss(line);
	
	for (int distance; !(ss >> distance).fail();)
	{
		if (distance > 40)
		{
			distance = distance - 40;
			money -= 720;
			int a = (distance / 8) * 80;
			int b = (distance % 8) * 10;
			money -= (a+b);
		}
		else
			money -= 720;
	}
	printf("%d", money);
	return 0;
}
