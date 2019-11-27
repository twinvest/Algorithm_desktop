#include <stdio.h>
#include <string.h>

int main() {
	char str[16];
	int length, i, cnt = 0;

	gets(str);
	length = strlen(str);//배열에 들어간길이.

	for (i = 0; i < length; i++) {
		if (('A' <= str[i]) && (str[i] <= 'C'))//아스키코드 ABC 65<=str[i]<=67와 같음
			cnt += 3;

		else if (('D' <= str[i]) && (str[i] <= 'F'))//DEF
			cnt += 4;

		else if (('G' <= str[i]) && (str[i] <= 'I'))//GHI
			cnt += 5;

		else if (('J' <= str[i]) && (str[i] <= 'L'))//JKL
			cnt += 6;

		else if (('M' <= str[i]) && (str[i] <= 'O'))//MNO
			cnt += 7;

		else if (('P' <= str[i]) && (str[i] <= 'S'))//PQRS
			cnt += 8;

		else if (('T' <= str[i]) && (str[i] <= 'V'))//TUV
			cnt += 9;

		else if (('W' <= str[i]) && (str[i] <= 'Z'))//WXYZ
			cnt += 10;
	}
	printf("%d\n", cnt);
}