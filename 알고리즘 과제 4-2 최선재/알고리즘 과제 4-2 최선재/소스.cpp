#include<cstdio>
#include<iostream>
using namespace std;
int arr[100000000] = { 0, };
int main(void) {
	int wtn;
	scanf("%d", &wtn);
	int i = 10;
	arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = arr[6] = arr[7] = arr[8] = arr[9] = 1;

	while (arr[i - 1] != wtn + 1) {
		int no = i;
		while (no > 9)
			no /= 10;
		arr[i] = arr[i - no] + 1;
		i += 1;
	}
	printf("%d", i - 2);
}