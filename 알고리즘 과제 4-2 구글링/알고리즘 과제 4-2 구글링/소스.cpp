#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

//몇자리 숫자인지를 알려줌
int countdig(int m)
{
	if (m == 0)
		return 0;
	else
		return 1 + countdig(m / 10);
}
int countSteps(int x)
{
	// count the total number of stesp 
	int c = 0;
	int last = x;

	// iterate till we reach 0 
	while (last) {
		//몇자리 숫자인지 반환해줌.
		int digits = countdig(last);
		
		//1감소. 이유는 10을 제곱하려고!
		digits -= 1;

		//나눌숫자를 제곱으로 구함.
		int divisor = pow(10, digits);

		//이렇게 하면 99/10, 101/100등을 구할 수 있음. 즉, 첫자리를 구할 수 있다. 99의 경우 9, 101의 경우 1
		int first = last / divisor;

		//앞자리가 바뀌는 제일 작은 숫자를 알아 낼 수 있음. 즉, 90 80 70 100 등 
		int lastnumber = first * divisor;

		// find the number of numbers 
		// with same first digit that are jumped 
		//101-100/1, 99-90/9
		int skipped = (last - lastnumber) / first;
		skipped += 1;

		// count the steps 
		c += skipped;

		// the next number with a different 
		// first digit 
		last = last - (first * skipped);
	}
	return c;
}
int main()
{
	int n = 100;
	cout << countSteps(n);
	return 0;
}