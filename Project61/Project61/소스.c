#include<stdio.h>
#include<stdlib.h>
int team;

void search(int *p, int*ptr, int current_position, int next_position, int k)
{
	if ((p[k] == p[next_position]) && (ptr[next_position] != -1))  //current_position == next_position && 
	{
		ptr[next_position] = -1;
		team++;
	}
	else
	{
		current_position = next_position;
		next_position = p[current_position];
		if (current_position == next_position && (ptr[next_position] == -1))
			return;
		search(p, ptr, current_position, next_position, k);
	}
}
int main(void)
{
	int test_case;
	scanf("%d", &test_case);

	while (test_case--)
	{
		team = 0;
		int student_num;
		scanf("%d", &student_num);
		if (student_num > 100000 && student_num < 2)
			exit(0);
		int * p = (int*)malloc(sizeof(int)*student_num);
		int * ptr = (int*)malloc(sizeof(int)*student_num);
		for (int i = 1; i <= student_num; i++)
			scanf("%d", &p[i]);
		for (int i = 1; i <= student_num; i++)
		{

			int current_position = i; //현재 위치, 항상 끝은 여기로 돌아와야함, 학생번호
			int k = current_position;
			int next_position = p[i];  //이동할 곳, 다음 탐색할 곳
			search(p, ptr, current_position, next_position, k);
		}
		printf("%d\n", student_num - team);
	}
	return 0;
}