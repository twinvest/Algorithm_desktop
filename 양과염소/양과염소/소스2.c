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
	printf("n�� �� : %d\n", n);
	printf("s�� �� : %d\n", s);
	printf("number�� �� : %d\n", number);


}