#include<stdio.h>
void translate(int translate_time)
{
	int copy = translate_time;
	int day = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;
	
	day = copy / 86400; //day
	hour = (copy % 86400)/3600; //이 나머지를 가지고 hour를 따진다.
	minute = ((copy % 86400) % 3600) / 60;
	second = ((copy % 86400) % 3600) % 60;
	
	printf("입력받은 %d초는 %d일 %d시간 %d분 %d초로 환산됩니다.\n", translate_time, day, hour, minute, second);
}

int main() 
{
	int translate_time;
	int after_translate_time;
	
	while (1)
	{
		printf("변환할 시간을 입력해주세요 : ");
		scanf("%d", &translate_time);
		if (translate_time >= 0 && translate_time <= 1000000)
			break;
		printf("다시 입력해주세요!\n");
	}
	printf("변환할 초(입력받은 초) : %d\n", translate_time);
	translate(translate_time);

}