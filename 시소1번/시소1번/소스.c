#include<stdio.h>
#define TIME 31536000;

int immigrant_calculator(int time, int current_population)
{
	int immigrant = 0;
	while (time>=27)
	{
		time -= 27;
		++immigrant;
	}
	return immigrant;
}

int death_calculator(int time, int current_population)
{
	int death = 0;
	while (time>=12)
	{
		time -= 12;
		++death;
	}
	return death;

}
int birth_calculator(int time, int current_population)
{
	int birth = 0;
	while (time>=8)
	{
		time -= 8;
		++birth;
	}
	return birth;

}

int main()
{
	int time = TIME; //1년을 초로 환산.
	int current_population = 51470000; //현재인구
	int result_population = 0;
	
	int death = death_calculator(time, current_population);
	int birth = birth_calculator(time, current_population);
	int immigrant = immigrant_calculator(time, current_population);
		
	result_population = birth + immigrant-death;
	
	printf("현재인구 : %d\n", current_population);
	printf("변화된 인구 수: %d\n", result_population);
	printf("최종 1년 후 인구 수: %d\n", result_population + current_population);
	

}