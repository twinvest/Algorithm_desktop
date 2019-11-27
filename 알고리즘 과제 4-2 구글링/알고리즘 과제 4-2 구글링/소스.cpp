#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

//���ڸ� ���������� �˷���
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
		//���ڸ� �������� ��ȯ����.
		int digits = countdig(last);
		
		//1����. ������ 10�� �����Ϸ���!
		digits -= 1;

		//�������ڸ� �������� ����.
		int divisor = pow(10, digits);

		//�̷��� �ϸ� 99/10, 101/100���� ���� �� ����. ��, ù�ڸ��� ���� �� �ִ�. 99�� ��� 9, 101�� ��� 1
		int first = last / divisor;

		//���ڸ��� �ٲ�� ���� ���� ���ڸ� �˾� �� �� ����. ��, 90 80 70 100 �� 
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