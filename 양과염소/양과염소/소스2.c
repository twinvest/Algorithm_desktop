int main()
{
	int number;
	scanf("%d", &number);
	int n=1;
	int s;

	while (number>s)
	{
		s = (0.5 * n * n) + (0.5 * n);
		++n;
	}
	printf("n의 값 : %d\n", n);
	printf("s의 값 : %d\n", s);
	printf("number의 값 : %d\n", number);


}