#include<stdio.h>
struct point {
	int x, y;
};
int equal(struct point p1, struct point p2);
int quadrant(struct point p);
int main()
{
	
	
	int result;
	int result2;
	struct point p1 = {1, -3 };
	struct point p2 = { 2, 2 };
	result = equal(p1, p2);
	
	if (result)
		printf("��ġ\n");
	else
		printf("����ġ\n");

	result2 = quadrant(p1);
	printf("���� %d��и鿡 �ֽ��ϴ�.\n", result2);

	/*struct employee {
		char name[30];
		int salary;
	};
	struct employee emp[10];
	
	char name2[30] = "ö��";
	strcpy(emp[0].name, name2);
	emp[0].salary = 300;

	printf("%s�� ������ %d�Դϴ�.", emp[0].name, emp[0].salary);*/





	/*enum days {MON, TUE, WED, THU, FRI, SAT, SUN}; //������
	char* days_name[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" }; //�����͵��� �迭�� ����� ���ڿ� ����� �ʱ�ȭ�Ѵ�.
	enum days d;
	for (d = MON; d <= SUN; d++)
		printf("%d��° ������ �̸��� %s�Դϴ�.\n", d, days_name[d]);
	return 0;*/



	/*union example { //����ü ����
		int i;
		int c;
	};

	union example data;

	printf("example�� ũ�� : %d\n", sizeof(data));
	data.c = 'A';
	printf("data.c : %c data.i : %d\n", data.c, data.i);*/



	/*struct student {       //������ ����ϴ� ����
		int student_number;
		char name[10];
		double grade;
	};

	struct student s = {201219289, "kim", 4.3};
	struct student * p;
	p = &s;

	printf("�й� : %d\n", p->student_number);
	printf("�̸� : %s\n", p->name);
	printf("���� : %lf\n\n", p->grade);

	printf("�й� : %d\n", (*p).student_number);  //*p.student_number  �� �ƿ� ������ ���.
	printf("�̸� : %s\n", (*p).name);
	printf("���� : %lf\n\n", (*p).grade);

	printf("�й� : %d\n", s.student_number);
	printf("�̸� : %s\n", s.name);
	printf("���� : %lf\n\n", s.grade);*/

	
		
	
	/*struct student {        //����ü�迭�� ����� ����
		int student_number;
		char name[10];
		double grade;
	};

	struct student list[3];
	char name2[15];
	
	
	for (int i = 0; i < 3; i++)
	{
		printf("�й��� �Է��ϼ��� : ");
		scanf("%d", &list[i].student_number);
		printf("������ �Է��ϼ��� : ");
		scanf("%lf", &list[i].grade);
		
		printf("�̸��� �Է��ϼ��� : ");
		scanf("%s", list[i].name);
		//scanf("%s", name2);
		//strcpy(list[i].name, name2);
		
		printf("%d\n", list[i].student_number);
		printf("%s\n", list[i].name);
		printf("%lf\n", list[i].grade);
		printf("i�� ��: %d\n\n", i);
	}*/

	
	
	/*struct student a; //����ü ����.
	char name2[15] = "���¿�";    
	
	a.student_number = 201219289;
	strcpy(a.name, name2);         //�̰� ����!!!
	a.grade = 4.3;

	printf("%d\n", a.student_number);
	printf("%s\n", a.name);
	printf("%lf\n", a.grade);
	printf("%d", sizeof(a));*/

}

int equal(struct point p1, struct point p2)
{
	int result;
	if (p1.x == p2.x)
	{
		if (p1.y == p2.y)
			result = 1;
		
		else
			result = 0;
		
	}
	else
		result = 0;
	return result;
}

int quadrant(struct point p)
{
	int result;
	if (p.x > 0 && p.y > 0)
		result = 1;
	else if (p.x < 0 && p.y>0)
		result = 2;
	else if (p.x < 0 && p.y < 0)
		result = 3;
	else if (p.x > 0 && p.y < 0)
		result = 4;

	return result;
}