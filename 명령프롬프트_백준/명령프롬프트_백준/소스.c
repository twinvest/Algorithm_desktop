/*#include<stdio.h>

int num;
char moonja;
char arr[51];

int main() {
	scanf("%d %s", &num, arr);
	for (int i = 1; i < num; i++) 
		for (int j = 0; arr[j]; j++) 
			scanf(" %c", &moonja), arr[j] = arr[j] - moonja ? '?' : moonja;
	
	printf("%s\n", arr);
	return 0;
}*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char str[51];
}NAME;


int main() {
	int N, len;
	NAME file[51];

	scanf("%d", &N);// 파일 이름의 개수

	for (int i = 0; i < N; i++) { //파일 이름 받기
		scanf("%s", file[i].str);
	}
	len = strlen(file[0].str);
	for (int j = 0; j < len; j++) {

		for (int k = 1; k < N; k++) {
			if (file[0].str[j] != file[k].str[j]) {
				file[0].str[j] = '?';
				break;
			}

		}
	}
	printf("%s\n", file[0].str);

}