#include<stdio.h>

int birth_cal(void);
int death_cal(void);
int immigrant_cal(void);

int main(void)
{
	int cur_population = 11788;
	int birth_result = birth_cal();
	int death_result = death_cal();
	int immigrant_result = immigrant_cal();

	int result = cur_population + birth_result - death_result + immigrant_result;
	
	printf("�����ϰ��� �α� ���� ��ȭ : %d", result);
}

int birth_cal(void)
{
	int birth = 0;
	int time = 10080;
	while (time > 0)
	{
		time = time - 8;
		birth = birth + 1;
	}
	printf("ź���� : %d\n", birth);
	return birth;
}

int death_cal(void)
{
	int death = 0;
	int time = 10080;
	while (time > 0)
	{
		time = time - 12;
		death = death + 1;
	}
	printf("������ : %d\n", death);
	return death;
}

int immigrant_cal(void)
{
	int immigrant = 0;
	int time = 10080;
	while (time > 0)
	{
		time = time - 27;
		immigrant = immigrant + 1;
	}
	printf("�̹��ڼ� : %d\n", immigrant);
	return immigrant;
}