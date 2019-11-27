#include<cstdio>
#define MAX 1000
int arr[MAX];
int main() 
{
	int N; 
	scanf("%d", &N);
	N = N + 1;

	arr[0] = 0;
	arr[1] = 9;
	arr[2] = 10;

	for (int i = 2; i < N; i++) {
		int willplus = arr[i] / 10;
		arr[i + 1] = arr[i] + willplus;
		if (arr[i + 1] / 10 != willplus) {
			arr[i + 1] = arr[i] + (arr[i + 1] / 10);
		}
	}
	
	printf("%d", arr[N - 1]);

	/*for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}*/
}