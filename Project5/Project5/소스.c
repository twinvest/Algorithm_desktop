#include<stdio.h>


int SquareByValue(int value)
{
	value = value * value;
	return value;
}

int SquareByReference(int*value)
{
	*value = (*value) * (*value);
	return *value;
}




int main(void)
{
	int i = 12;
	int num;

	
	printf("%d \n", SquareByValue(i));
	printf("%d \n", SquareByReference(&i));
	printf("%d \n", i);
	
	scanf("%d", &num);


}