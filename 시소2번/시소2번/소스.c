#include<stdio.h>
void translate(int translate_time)
{
	int copy = translate_time;
	int day = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;
	
	day = copy / 86400; //day
	hour = (copy % 86400)/3600; //�� �������� ������ hour�� ������.
	minute = ((copy % 86400) % 3600) / 60;
	second = ((copy % 86400) % 3600) % 60;
	
	printf("�Է¹��� %d�ʴ� %d�� %d�ð� %d�� %d�ʷ� ȯ��˴ϴ�.\n", translate_time, day, hour, minute, second);
}

int main() 
{
	int translate_time;
	int after_translate_time;
	
	while (1)
	{
		printf("��ȯ�� �ð��� �Է����ּ��� : ");
		scanf("%d", &translate_time);
		if (translate_time >= 0 && translate_time <= 1000000)
			break;
		printf("�ٽ� �Է����ּ���!\n");
	}
	printf("��ȯ�� ��(�Է¹��� ��) : %d\n", translate_time);
	translate(translate_time);

}