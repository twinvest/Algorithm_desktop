#include <iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(void) {
	int arrindex = 0, arr2index = 0, arr4index = 0;
	
	char arr[100];
	char arr2[100];
	int arr3[100];
	char arr4[100];
	scanf("%s", arr);
	
	char * p = arr;
	char * p2 = arr2;
	int * p3 = arr3;

	for (; *p != NULL; p++)   //숫자 뽑아내기
	{
		if (*p >= 65 && *p <= 90)  //대문자
			arr2[arrindex++] = *p;
		if (*p >= 97 && *p <= 122) //소문자
			arr2[arrindex++] = *p;
		if (*p >= 49 && *p <= 57) //숫자
			p3[arr2index++] = (*p-48);
	}
	
	int flag = 0;
	int flag2 = 0;
	p2 = arr2;
	p3 = arr3;
	char *p4 = arr4;
	
	for(p=arr; *p != NULL; p++)
	{
		arr4index++;
		if (*p2 >= 97 && *p2 <= 122 || *p2 >= 65 && *p2 <= 90)
		{
			if (*p2 >= 97 && *p2 <= 122) flag2++;
			else
			{
				*p4 = *p2;
				p4++;
				p2++;
				flag2++;
			}
			
		}
		if (*p3 >= 1 && *p3 <= 9)
		{
			flag++;
			if (*p3 == 1) p3++;
			else
			{
				if (*p2 >= 97 && *p2 <= 122)	continue;
				else
				{
					*p4 = (*p3 + 48);
					p3++;
					p4++;
				}
				
			}
		}
	}
	if (flag2 != flag) printf("error");
	else
	{
		for (int i = 0; i < arr4index - 1; i++)
			printf("%c", arr4[i]);
	}
	return 0;
}