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
		printf("일치\n");
	else
		printf("불일치\n");

	result2 = quadrant(p1);
	printf("점은 %d사분면에 있습니다.\n", result2);

	/*struct employee {
		char name[30];
		int salary;
	};
	struct employee emp[10];
	
	char name2[30] = "철수";
	strcpy(emp[0].name, name2);
	emp[0].salary = 300;

	printf("%s의 월급은 %d입니다.", emp[0].name, emp[0].salary);*/





	/*enum days {MON, TUE, WED, THU, FRI, SAT, SUN}; //열거형
	char* days_name[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" }; //포인터들의 배열을 만들고 문자열 상수로 초기화한다.
	enum days d;
	for (d = MON; d <= SUN; d++)
		printf("%d번째 요일의 이름은 %s입니다.\n", d, days_name[d]);
	return 0;*/



	/*union example { //공용체 예제
		int i;
		int c;
	};

	union example data;

	printf("example의 크기 : %d\n", sizeof(data));
	data.c = 'A';
	printf("data.c : %c data.i : %d\n", data.c, data.i);*/



	/*struct student {       //포인터 사용하는 예제
		int student_number;
		char name[10];
		double grade;
	};

	struct student s = {201219289, "kim", 4.3};
	struct student * p;
	p = &s;

	printf("학번 : %d\n", p->student_number);
	printf("이름 : %s\n", p->name);
	printf("성적 : %lf\n\n", p->grade);

	printf("학번 : %d\n", (*p).student_number);  //*p.student_number  는 아예 빨간줄 뜬다.
	printf("이름 : %s\n", (*p).name);
	printf("성적 : %lf\n\n", (*p).grade);

	printf("학번 : %d\n", s.student_number);
	printf("이름 : %s\n", s.name);
	printf("성적 : %lf\n\n", s.grade);*/

	
		
	
	/*struct student {        //구조체배열을 사용한 예제
		int student_number;
		char name[10];
		double grade;
	};

	struct student list[3];
	char name2[15];
	
	
	for (int i = 0; i < 3; i++)
	{
		printf("학번을 입력하세요 : ");
		scanf("%d", &list[i].student_number);
		printf("성적을 입력하세요 : ");
		scanf("%lf", &list[i].grade);
		
		printf("이름을 입력하세요 : ");
		scanf("%s", list[i].name);
		//scanf("%s", name2);
		//strcpy(list[i].name, name2);
		
		printf("%d\n", list[i].student_number);
		printf("%s\n", list[i].name);
		printf("%lf\n", list[i].grade);
		printf("i의 값: %d\n\n", i);
	}*/

	
	
	/*struct student a; //구조체 예제.
	char name2[15] = "김태우";    
	
	a.student_number = 201219289;
	strcpy(a.name, name2);         //이거 주의!!!
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