#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <windows.h>
#include <conio.h>

using namespace std;

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
///////////////////////////////////////////// Date class ///////////////////////////////////////////// 
class Date :public tm { //time.h, ctime�� �ִ� tm ����ü�� ������ 
	friend class CalInterface;

protected:
	unsigned int tdays; //1�� 1�� 1���� 1�Ϸ� �Ͽ� ����� ��¥�� ��ü �� ���� ���� 
	int mfday; // ����� ���� 1���� ��ġ ����(2015�� 3���� ���� ��� 1���� �Ͽ����̹Ƿ� mfday�� 0) �޷��� ���鶧 �ʿ��� 
	int year; // tm_year�� 1900����� �����ϹǷ� 1�Ϻ��� �����ϴ� ������ ���� ���� 

	static const int ldays[12]; //�� ���� ������ ��¥�� �����ϰ� �ִ� ����迭 

	bool leapCheck(int ayear); //�������� �ƴ����� �Ǵ��ϴ� �Լ� 

	void arrByMDY(void); // ������� �������� ������ ������ ��� 
	void arrByTdays(void); // tdays�� �������� ������ ������ ��� 
	void arrRest(void); // �����, tdays�� �������� ������ ������ ���
	void getDayName(void);	// tm_wday�� �������� �����̸��� ���� 
	char day_name[4]; // ���� �̸��� ����Ǵ� ���ڿ� 

public:
	int color; //���ڻ��� �����ϴ� �Լ� 

	Date(void); //������ 
	void setDate(int amon, int amday, int ayear); //������� �޾� �����͸� ���� 
	void setDate(int atdays); //tdays�� �޾� �����͸� ���� 
	void showDate(void); // �����͸� ��� 
	const Date operator +(const int a) const; //+�������Լ� 
	const Date operator -(const int a) const; //-������ �Լ� 
	const int operator -(const Date &A) const; //-������ �Լ� 
};
const int Date::ldays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //�� ���� ������ ��¥�� 

bool Date::leapCheck(int ayear) {
	if (ayear % 4 == 0 && ayear % 100 != 0 || ayear % 400 == 0) return 1;
	return 0;
}
void Date::arrRest(void) {
	tm_yday = -1;
	tm_yday += tm_mday;
	for (int i = 0; i<tm_mon; i++) {
		if (leapCheck(year) && i == 1) tm_yday += ldays[1] + 1;
		else tm_yday += ldays[i];
	}
	tm_year = year - 1900;
	tm_wday = tdays % 7;
	getDayName();
	mfday = (tdays - tm_mday + 1) % 7;
}
void Date::arrByMDY(void) {
	int i;
	tdays = 0;

	tdays += tm_mday;
	for (i = 0; i<tm_mon; i++) {
		if (leapCheck(year) && i == 1) tdays += ldays[1] + 1;
		else tdays += ldays[i];
	}
	for (i = 1; i<year; i++) {
		if (leapCheck(i)) tdays += 366;
		else tdays += 365;
	}
	arrRest();
}
void Date::arrByTdays(void) {
	int i, temp;

	tm_mon = 0;
	tm_mday = 0;
	year = 0;

	temp = tdays;
	for (i = 0;; i++) {
		if (i == 0) year++;
		else if (leapCheck(i)) {
			if (temp <= 366) break;
			temp -= 366;
			year++;
		}
		else {
			if (temp <= 365) break;
			temp -= 365;
			year++;
		}
	}
	for (i = 0; i<12; i++) {
		if (leapCheck(year) && i == 1) {
			if (temp - (ldays[1] + 1) <= 0) break;
			else temp -= (ldays[1] + 1);
		}
		else {
			if (temp - ldays[i] <= 0) break;
			else temp -= ldays[i];
		}
		tm_mon++;
	}
	tm_mday = temp;
	arrRest();
}
void Date::getDayName(void) {
	switch (tm_wday) {
	case 0: memcpy(day_name, "SUN", 4); break;
	case 1: memcpy(day_name, "MON", 4); break;
	case 2: memcpy(day_name, "TUE", 4); break;
	case 3: memcpy(day_name, "WED", 4); break;
	case 4: memcpy(day_name, "THU", 4); break;
	case 5: memcpy(day_name, "FRI", 4); break;
	case 6: memcpy(day_name, "SAT", 4); break;
	}
}
Date::Date(void) {
	time_t raw;
	time(&raw);
	struct tm* curtime;
	curtime = localtime(&raw);
	tm_mon = curtime->tm_mon;
	tm_mday = curtime->tm_mday;
	year = curtime->tm_year + 1900;
	arrByMDY();
	color = 0x0007;
}
void Date::setDate(int amon, int amday, int ayear) {
	tm_mon = amon - 1;
	tm_mday = amday;
	year = ayear;
	arrByMDY();
}
void Date::setDate(int atdays) {
	tdays = atdays;
	arrByTdays();
}
void Date::showDate(void) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << setw(2) << setfill('0') << tm_mon + 1 << '/' << setw(2) << tm_mday << '/' << setw(4) << year << '(' << day_name << ')';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0007);
}
const Date Date::operator +(const int a) const {
	Date B;
	B.tdays = tdays + a;
	B.arrByTdays();
	return B;
}
const Date Date::operator -(const int a) const {
	Date B;
	B.tdays = tdays - a;
	B.arrByTdays();
	return B;
}
const int Date::operator -(const Date &A) const {
	int B;
	B = tdays - A.tdays;
	return B;
}
///////////////////////////////////////////// Calendar class ///////////////////////////////////////////// 

class Calendar :public Date {
	friend class CalInterface;

protected:
	int cal_x; //�޷� ��� x��ǥ ���� ���� 
	int cal_y; //�޷� ��� y��ǥ ���� ���� 

	Date saved; //ǥ�õǴ� �޷°� ������ ��¥���� ������ �� �ִ� class CalInterface���� �ʿ��� 

	void makeCalData(void); //�޷°��� ���ϴ� �Լ� 
	int caldata[6][7]; //�޷°��� ����Ǵ� 2���� �迭 

public:
	Calendar(void) { //������. ������ �ʱ�ȭ 
		memset(this, 0, sizeof(Calendar));
	}
	void setCalendar(const Date &A) { //Date Ÿ���� �޾� �޷��� ���� 
		memcpy(this, &A, sizeof(Date));
		makeCalData();
	}
	void showCalendar(int ax, int ay); //x,y��ǥ�� ������Ʈ�ϰ� �޷� ��� 
	void showCalendar(void); // ����� ��ǥ�� �޷� ���(�ʱⰪ�� 0,0) 
};
void Calendar::makeCalData(void) {
	int leap_adj_this_mon = 0; //�̹����� ���޺������� �����ϴ� ���� 
	int leap_adj_last_mon = 0; //�������� ���޺������� �����ϴ� ���� 
	if (leapCheck(year) && tm_mon == 1) leap_adj_this_mon = 1; //�̴��� 2���̸� ���� ���� 
	if (leapCheck(year) && tm_mon == 2) leap_adj_last_mon = 1; //�������� 2���̸� ���� ���� 

	int this_mday = 1; //�̹����� ���۳�¥ 
	int next_mday = 1; //�������� ���۳�¥ 

	int last_mday; //�������� ���۳�¥�� �����ϴ� ����                      /* �������� ���۳�¥�� ����                                           */
	if (mfday == 0) last_mday = ldays[(tm_mon + 11) % 12] - 7 + 1 + leap_adj_last_mon; /* �̺κ��� ���� ������ �Ͽ����϶�, �������� �������ָ� �����ֱ� ���� */
	else         last_mday = ldays[(tm_mon + 11) % 12] - mfday + 1 + leap_adj_last_mon; /* ���� ������ �Ͽ����� �ƴҶ� ��ĭ��ŭ                               */

	for (int i = 0; i<6; i++) {
		for (int j = 0; j<7; j++) {
			if (last_mday <= ldays[(tm_mon + 11) % 12] + leap_adj_last_mon) caldata[i][j] = 100 + last_mday++; //�������� ��¥���� 100�� ���ؼ� ���� 
			else if (this_mday <= ldays[tm_mon % 12] + leap_adj_this_mon) caldata[i][j] = this_mday++;
			else caldata[i][j] = 200 + next_mday++; //���� ���� ��¥���� 200�� ���ؼ� ���� 
		}
	}
}
void Calendar::showCalendar(void) {
	gotoxy(cal_x, cal_y);
	cout << "      << < " << setw(2) << setfill('0') << tm_mon + 1 << '/' << setw(4) << year << " > >> ";
	gotoxy(cal_x, cal_y + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00c0);
	cout << " SUN";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0070);
	cout << " MON TUE WED THU FRI";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00F0);
	cout << " SAT" << endl;
	gotoxy(cal_x, cal_y + 2);
	for (int i = 0; i<6; i++) {
		gotoxy(cal_x, cal_y + 2 + i);
		for (int j = 0; j<7; j++) {
			switch (j) {
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				break;
			case 6:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
				break;
			}
			if (caldata[i][j]>200) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0008);
				cout << setw(4) << setfill(' ') << caldata[i][j] - 200;
			}
			else if (caldata[i][j]>100) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0008);
				cout << setw(4) << setfill(' ') << caldata[i][j] - 100;
			}
			else if (caldata[i][j] != 0) cout << setw(4) << setfill(' ') << caldata[i][j];
			else cout << "    ";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}
void Calendar::showCalendar(int ax, int ay) {
	cal_x = ax;
	cal_y = ay;
	showCalendar();
}
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define TAP 9
#define MAX_YEAR 2100
#define MIN_YEAR 1900

class CalInterface {
private:
	const int cal1_x = 2;			//ù��° �޷��� ��ǥ�� 
	const int cal1_y = 4;
	const int cal2_x = 2;			//�ι�° �޷��� ��ǥ�� 
	const int cal2_y = 13;
	const int texts_x = 35;		//�����ʿ� �ߴ� �޼����� ��ǥ�� 
	const int texts_y = 5;
	const int cac_x = texts_x;	//��¥ ���� ��ǥ�� 
	const int cac_y = 14;
	const int clock_x = 70;		//�ð� ��ǥ�� 
	const int clock_y = 21;

	int key; //�ַܼ� �Է¹��� ���� �����ϴ� ���� 

	int cur_area; //Ŀ���� ��� ������ �ִ���(ù��°�޷� ���κ�:0, ù��°�޷� ����:1, �ι�° �޷� ���κ�:2, �ι�°�޷� ����:3 )
	int cur_x; //�޷� ���������� Ŀ���� ��ǥ�� 
	int cur_y;
	int cur_top; //�޷� ���κп��� Ŀ���� ��ġ�� 
	int cur_cnt_max; // >��� Ŀ���� �������� ��Ÿ���µ� ���Ǵ� ����
	int cur_cnt; // >��� Ŀ���� �������� ��Ÿ���µ� ���Ǵ� ���� (0~cur_cnt_max�� ������ 1�� �̵��ϸ�, -1�� ��쿡�� ������縸 ǥ��) 

	Date today; //���� ��¥�� ���� 
	Calendar cal1; //ù��° �޷� 
	Calendar cal2; //�ι�° �޷� 

	void showCalendar(Calendar &A) { //�޷��� ǥ���ϸ鼭 ��ũ�� ��¥�� ǥ�� 
		A.showCalendar();
		showMarkedDate(A);
	}
	void markDate(Calendar &A, Date &B, int color); //�޷� A�� B�� ��¥�� color�� ����� ǥ�� 
	void showMarkedDate(Calendar &A) { //������ ���� ��¥���� ���⼭ �߰�, ���� �� �� ���� 
		markDate(A, today, today.color);
		if (A.saved.tdays != 0 && A.saved.tdays != today.tdays)markDate(A, A.saved, A.color);
	}

	void showCur(void); //Ŀ���� cur_area 0~3�� ������(��¥���⿡ ���� ������) Ŀ���� �ִϸ��̼��� ǥ�� 
	void curInCalBody(Calendar &A); //Ŀ���� �޷º����� ������(cur_area�� 1Ȥ�� 3�϶�) 
	void curInCalTop(Calendar &A); //Ŀ���� �޷����κп� ������(cur_area�� 0Ȥ�� 2�϶�)

	int getCurDate(Calendar &A); //Ŀ���� ��ġ�κ��� ��¥�� �̾Ƴ� 
	void getCur_xy(Calendar &A) { //�޷¿��� ��¥�� �����Ͽ� Ŀ���� ��ġ�� ���� 
		cur_x = A.tm_wday;
		cur_y = (A.mfday + A.tm_mday - 1) / 7 + 1;
		if (A.mfday == 0) cur_y++;
	}

	void moveInCalBody(Calendar &A); //�޷� �������� Ŀ�� ������ ���� 
	void moveInCalTop(Calendar &A); //�޷� ���κп��� Ŀ�� ������ ���� 

	void addMon(Calendar &A); //�Ѵ��� ���� 
	void subMon(Calendar &A); //�Ѵ��� �� 
	void addYear(Calendar &A); //�ϳ��� ���� 
	void subYear(Calendar &A); //�ϳ��� �� 

	void getMMYYYY(Calendar &A); //�޷� ���κп��� ��/�� �κп� ��¥�Է¹޴� �Լ�

	void turnOff(void); //���α׷� ���� Ȯ�� 

	void showCurTime(void); //����ð��� ǥ�� 
	void hideCurTime(void); //����ð��� ���� 

	void calculator(void); //��¥���� �Լ� 
	int cur_cac; // ��¥���⿡�� Ŀ����ġ�� �����ϴ� ���� 
	void showCacCur(void); //��¥���� ù��° step���� Ŀ���ִϸ��̼� ǥ�� 
	void delCacCur(void); //��¥�Ի�� ù��° step���� Ŀ�� ����  

public:
	CalInterface(); //���α׷��� �����ϰ� ������ �ʱ�ȭ 
	void display(void); //ȭ���� ��� 
	void getKey(void); //Ű�Է� �޴� �Լ� 
};
CalInterface::CalInterface() {
	cal1.setCalendar(today); //���ó�¥�� ù��° �޷� ���� 
	cal1.cal_x = cal1_x; //ù��° �޷� ��ǥ �Է� 
	cal1.cal_y = cal1_y;
	cal2.setCalendar(today); //���ó�¥�� �ι�° �޷� ����
	cal2.cal_x = cal2_x; //�ι�° �޷� ��ǥ �Է�
	cal2.cal_y = cal2_y;

	today.color = 0x000A; //�޷� ��¥ ���� ���� 
	cal1.color = 0x000B;
	cal2.color = 0x000D;

	getCur_xy(cal1); //ù��°�޷¿��� Ŀ����ġ ���� 
	cur_area = 1; //ù��° �޷� ������ Ŀ���� ��ġ 
	cur_cnt_max = 20; // >��� Ŀ���� ������ �ӵ� 
	cur_cnt = 1;	// >��� Ŀ���� �ʱⰪ  
}
void CalInterface::display(void) {
	int text1;
	int text2;
	int text3;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	gotoxy(2, 1); cout << " �� ��¥������α׷� ��        ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
	cout << "TAP : ��¥����   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	cout << "����Ű: �̵�   ENTER: ����";
	gotoxy(1, 2); cout << "______________________________________________________________________________";
	gotoxy(1, 22); cout << "______________________________________________________________________________";
	gotoxy(2, 23); cout << " ESC: ����/���(�Է½�)        BLOG.NAVER.COM/AZURE0777";

	showCalendar(cal1);
	showCalendar(cal2);

	gotoxy(texts_x, text1 = texts_y); cout << "������ "; today.showDate(); cout << "�Դϴ�.";

	gotoxy(texts_x, text2 = text1 + 2);
	if (cal1.saved.tdays != 0 && cal1.saved.tdays != today.tdays) {
		cal1.saved.showDate(); cout << "�� ���÷κ���      ";
		gotoxy(texts_x, text2 + 1);
		if (cal1.saved.tdays>today.tdays) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			cout << "     " << cal1.saved - today << "�� ��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			cout << "�Դϴ�.          ";
		}
		if (cal1.saved.tdays<today.tdays) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			cout << "     " << today - cal1.saved << "�� ��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			cout << "�Դϴ�.          ";
		}
	}
	else {
		cout << "                                              ";
		gotoxy(texts_x, text2 + 1);
		cout << "                                              ";
	}

	gotoxy(texts_x, text3 = text2 + 3);
	if (cal2.saved.tdays != 0 && cal1.saved.tdays != 0 && cal2.saved.tdays != today.tdays&&cal1.saved.tdays != today.tdays&&cal1.saved.tdays != cal2.saved.tdays) {
		cal2.saved.showDate(); cout << "�� "; cal1.saved.showDate(); cout << "�κ��� ";;
		gotoxy(texts_x, text3 + 1);
		if (cal2.saved.tdays>cal1.saved.tdays) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			cout << "     " << cal2.saved - cal1.saved << "�� ��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			cout << "�Դϴ�.          ";
		}
		if (cal2.saved.tdays<cal1.saved.tdays) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			cout << "     " << cal1.saved - cal2.saved << "�� ��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			cout << "�Դϴ�.          ";
		}
	}
	else {
		cout << "                                              ";
		gotoxy(texts_x, text3 + 1);
		cout << "                                              ";
	}
}
void CalInterface::markDate(Calendar &A, Date &B, int color) {
	if (A.tm_mon == B.tm_mon&&A.year == B.year) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		int x = B.tm_wday;
		int y = (B.mfday + B.tm_mday - 1) / 7 + 1;
		if (B.mfday == 0) y++;
		gotoxy(A.cal_x + x * 4, A.cal_y + y + 1);
		cout << setw(4) << setfill(' ') << B.tm_mday;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
}
void CalInterface::addMon(Calendar &A) {
	if (A.tm_mon<11) {
		A.tm_mon++;
	}
	else if (A.year<MAX_YEAR) {
		A.tm_mon = 0;
		A.year++;
	}
	else return;
	A.arrByMDY();
	A.makeCalData();
	display();
}
void CalInterface::subMon(Calendar &A) {
	if (A.tm_mon>0) {
		A.tm_mon--;
	}
	else if (A.year>MIN_YEAR) {
		A.tm_mon = 11;
		A.year--;
	}
	else return;
	A.arrByMDY();
	A.makeCalData();
	display();
}
void CalInterface::addYear(Calendar &A) {
	if (A.year<MAX_YEAR) A.year++;
	else return;

	A.arrByMDY();
	A.makeCalData();
	display();
}
void CalInterface::subYear(Calendar &A) {
	if (A.year>MIN_YEAR) A.year--;
	else return;

	A.arrByMDY();
	A.makeCalData();
	display();
}
void CalInterface::curInCalBody(Calendar &A) {
	if (cur_cnt == cur_cnt_max / 2) {
		gotoxy(A.cal_x + 4 * cur_x + 1, A.cal_y + 1 + cur_y);
		putchar('-');
	}
	else if (cur_cnt == 1) {
		gotoxy(A.cal_x + 4 * cur_x + 1, A.cal_y + 1 + cur_y);
		putchar('>');
	}
	else if (cur_cnt == 0) cur_cnt = cur_cnt_max;
	else if (cur_cnt == -1) {
		gotoxy(A.cal_x + 4 * cur_x + 1, A.cal_y + 1 + cur_y);
		putchar('>');
	}
	cur_cnt--;
}
void CalInterface::curInCalTop(Calendar &A) {
	bool act_val = false;
	if (cur_cnt == cur_cnt_max / 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		act_val = true;
	}
	else if (cur_cnt == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		act_val = true;
	}
	else if (cur_cnt == 0) cur_cnt = cur_cnt_max;
	else if (cur_cnt == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		act_val = true;
	}
	cur_cnt--;

	if (act_val == true) {
		switch (cur_top) {
		case 0:
			gotoxy(A.cal_x + 6, A.cal_y);
			cout << "<<";
			break;
		case 1:
			gotoxy(A.cal_x + 9, A.cal_y);
			cout << '<';
			break;
		case 2:
			gotoxy(A.cal_x + 11, A.cal_y);
			cout << setw(2) << setfill('0') << A.tm_mon + 1 << '/' << setw(4) << A.year;
			break;
		case 3:
			gotoxy(A.cal_x + 19, A.cal_y);
			cout << '>';
			break;
		case 4:
			gotoxy(A.cal_x + 21, A.cal_y);
			cout << ">>";
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
}
void CalInterface::moveInCalBody(Calendar &A) {
	switch (key) {
	case UP:
		if (cur_y>1) {
			cur_y--;
		}
		else if (cur_y == 1) {
			if (cur_area>0)cur_area--;
			cur_top = 2;
		}
		break;
	case DOWN:
		if (cur_y<6) {
			cur_y++;
		}
		else if (cur_y == 6) {
			if (cur_area<3 && cal1.saved.tdays != 0 && cal1.saved.tdays != today.tdays)cur_area++;
			cur_top = 2;
		}
		break;
	case RIGHT:
		if (cur_x<6) {
			cur_x++;
		}
		else if (cur_x == 6 && cur_y<6) {
			cur_x = 0;
			cur_y++;
		}
		else if (cur_x == 6 && cur_y == 6) {
			addMon(A);
		}
		break;
	case LEFT:
		if (cur_x>0) {
			cur_x--;
		}
		else if (cur_x == 0 && cur_y>1) {
			cur_x = 6;
			cur_y--;
		}
		else if (cur_x == 0 && cur_y == 1) {
			subMon(A);
		}
		break;
	case ENTER:
		if (A.year == MIN_YEAR && A.tm_mon == 0 && getCurDate(A)<1) return;
		if (A.year == MAX_YEAR && A.tm_mon == 11 && getCurDate(A)>31) return;
		A.tm_mday = getCurDate(A);
		A.arrByMDY();
		A.arrByTdays();
		A.makeCalData();
		getCur_xy(A);
		A.saved = A;
		display();
		return;
	}
	showCalendar(A);
}
void CalInterface::moveInCalTop(Calendar &A) {
	switch (key) {
	case UP:
		if (cur_area>0) {
			cur_area--;
			cur_y = 6;
		}
		break;
	case DOWN:
		if (cur_area<3) {
			cur_area++;
			cur_y = 1;
		}
		break;
	case RIGHT:
		if (cur_top == 4) addYear(A);
		if (cur_top<4)cur_top++;
		break;
	case LEFT:
		if (cur_top == 0) subYear(A);
		if (cur_top>0)cur_top--;
		break;
	case ENTER:
		switch (cur_top) {
		case 0:
			subYear(A);
			break;
		case 1:
			subMon(A);
			break;
		case 2:
			getMMYYYY(A);
			break;
		case 3:
			addMon(A);
			break;
		case 4:
			addYear(A);
			break;
		}
		break;
	case 0x30:
	case 0x31:
	case 0x32:
	case 0x33:
	case 0x34:
	case 0x35:
	case 0x36:
	case 0x37:
	case 0x38:
	case 0x39:
		getMMYYYY(A);
		break;
	}
	showCalendar(A);
}
void CalInterface::showCur(void) {
	switch (cur_area) {
	case 0:
		curInCalTop(cal1);
		break;
	case 1:
		curInCalBody(cal1);
		break;
	case 2:
		curInCalTop(cal2);
		break;
	case 3:
		curInCalBody(cal2);
		break;
	}
}
void CalInterface::getKey(void) {
	int dump;
	key = 0;

	Sleep(50);
	showCurTime();
	showCur();
	while (kbhit()) key = getch();
	if (key == 0) return;
	if (key == ESC) turnOff();
	if (key == TAP) {
		cur_cnt = -1;
		showCur();
		hideCurTime();
		calculator();
		cur_cnt = 1;
		showCur();
		return;
	}
	switch (cur_area) {
	case 0:
		moveInCalTop(cal1);
		break;
	case 1:
		moveInCalBody(cal1);
		break;
	case 2:
		moveInCalTop(cal2);
		break;
	case 3:
		moveInCalBody(cal2);
		break;
	}
	cur_cnt = 1;
	showCur();
}
int CalInterface::getCurDate(Calendar &A) {
	int val = (cur_y - 1) * 7 + (cur_x + 1) - A.mfday;
	if (A.mfday == 0) val -= 7;
	return val;
}
void CalInterface::getMMYYYY(Calendar &A) {
	int min_year = MIN_YEAR;
	int max_year = MAX_YEAR;
	char MMYYYY[8] = "MM/YYYY";
	int location = 0;
	bool checkMMYYYY = false;

	hideCurTime();
	setcursortype(SOLIDCURSOR);
	gotoxy(A.cal_x + 11, A.cal_y); cout << MMYYYY;
	gotoxy(A.cal_x + 11, A.cal_y);
	while (1) {
		if (kbhit()) key = getch();
		if (key == ESC) {
			gotoxy(26, A.cal_y); printf("                                         ");
			setcursortype(NOCURSOR);
			return;
		}
		if (key == 224) {
			do { key = getch(); } while (key == 224);
			switch (key) {
			case RIGHT:
				if (location<6) {
					location++;
					if (location == 2)location++;
				}
				break;
			case LEFT:
				if (location>0) {
					location--;
					if (location == 2)location--;
				}
				break;
			}
		}
		switch (key) {
		case BACKSPACE:
			if (location>0) {
				location--;
				if (location == 2)location--;
			}
			break;
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
			cout << char(key);
			MMYYYY[location] = key;
			if (location<6) {
				location++;
				if (location == 2)location++;
			}
			gotoxy(A.cal_x + 11, A.cal_y); cout << MMYYYY;
			checkMMYYYY = true;
			for (int i = 0; i<7; i++)if (MMYYYY[i] == 'M' || MMYYYY[i] == 'Y') checkMMYYYY = false;
			if (checkMMYYYY == true) {
				int intMM;
				int intYYYY;
				intMM = atoi(MMYYYY + 0);
				intYYYY = atoi(MMYYYY + 3);
				if (intMM<1 || intMM>12 || intYYYY<MIN_YEAR || intYYYY>MAX_YEAR) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
					gotoxy(26, A.cal_y); cout << "<- 01/" << setw(4) << setfill('0') << min_year << " ~ 12/" << setw(4) << setfill('0') << max_year << "�� ���� �Է����ּ���.";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
					strncpy(MMYYYY, "MM/YYYY", strlen(MMYYYY));
					gotoxy(A.cal_x + 11, A.cal_y); cout << MMYYYY;
					location = 0;
				}
				else {
					gotoxy(26, A.cal_y); printf("                                         ");
					A.tm_mon = intMM - 1;
					A.year = intYYYY;
					A.arrByMDY();
					A.makeCalData();
					display();
					setcursortype(NOCURSOR);
					return;
				}
			}
		}
		if (key != 0) {
			gotoxy(A.cal_x + 11 + location, A.cal_y);
		}
		key = 0;
	}
}

void CalInterface::turnOff(void) {
	int x = 20;
	int y = 8;

	hideCurTime();
	key = 0;
	gotoxy(x, y + 0); cout << "������������������������������";
	gotoxy(x, y + 1); cout << "��   �����մϱ�? (Y/N)      ��";
	gotoxy(x, y + 2); cout << "������������������������������";
	gotoxy(x + 23, y + 1);
	setcursortype(NORMALCURSOR);
	while (1) {
		if (kbhit()) key = getch();
		switch (key) {
		case 89:
		case 121:
		case ESC:
			system("cls");
			display();
			gotoxy(0, 24);
			exit(0);
			break;
		case 110:
		case 78:
			setcursortype(NOCURSOR);
			system("cls");
			display();
			return;
			break;
		}
	}
}

void CalInterface::showCacCur(void) {
	if (cur_cnt == cur_cnt_max / 2) {
		gotoxy(cac_x - 2, cac_y + cur_cac);
		putchar('-');
		gotoxy(cac_x + 24, cac_y + cur_cac);
		putchar('-');
	}
	else if (cur_cnt == 1) {
		gotoxy(cac_x - 2, cac_y + cur_cac);
		putchar('>');
		gotoxy(cac_x + 24, cac_y + cur_cac);
		putchar('<');
	}
	else if (cur_cnt == 0) cur_cnt = cur_cnt_max;
	cur_cnt--;
}void CalInterface::delCacCur(void) {
	gotoxy(cac_x - 2, cac_y + cur_cac);
	putchar(' ');
	gotoxy(cac_x + 24, cac_y + cur_cac);
	putchar(' ');
}
void CalInterface::calculator(void) {
	Date temp;
	cur_cac = 0;
	cur_cnt = 1;
	int max_cur_cac = 0;
	int step = 0;
	char num[6] = { 0, };
	int intNum = 0;
	gotoxy(cac_x, cac_y);
	cout << "                                  ";
	gotoxy(cac_x, cac_y + 1);
	cout << "                                  ";
	gotoxy(cac_x, cac_y);
	today.showDate(); cout << "�κ���..";
	if (cal1.saved.tdays != 0 && cal1.saved.tdays != today.tdays) {
		gotoxy(cac_x, cac_y + 1);
		cal1.showDate(); cout << "�κ���..";
		max_cur_cac++;
	}
	if (cal2.saved.tdays != 0 && cal2.saved.tdays != today.tdays&&cal2.saved.tdays != cal1.saved.tdays) {
		gotoxy(cac_x, cac_y + 2);
		cal2.showDate(); cout << "�κ���..";
		max_cur_cac++;
	}
	while (1) {
		key = 0;
		if (kbhit()) key = getch();

		if (step == 0 && max_cur_cac == 0) {
			temp = today;
			step++;
		}

		if (step == 0 && max_cur_cac != 0) {
			Sleep(50);
			showCacCur();
			switch (key) {
			case UP:
				delCacCur();
				if (cur_cac>0) cur_cac--;
				else cur_cac = max_cur_cac;
				cur_cnt = 1;
				break;
			case DOWN:
				delCacCur();
				if (cur_cac<max_cur_cac) cur_cac++;
				else cur_cac = 0;
				cur_cnt = 1;
				break;
			case ENTER:
				delCacCur();
				switch (cur_cac) {
				case 0:
					temp = today;
					break;
				case 1:
					temp = cal1.saved;
					break;
				case 2:
					temp = cal2.saved;
					break;
				}
				step++;
				break;
			case ESC:
				delCacCur();
				for (int i = 0; i <= max_cur_cac; i++) {
					gotoxy(cac_x, cac_y + i);
					cout << "                       ";
				}
				return;
			}
		}
		if (step == 1) {
			key = 0;
			gotoxy(cac_x, cac_y);
			temp.showDate(); cout << "�κ���       ��..";
			for (int i = 1; i <= max_cur_cac; i++) {
				gotoxy(cac_x, cac_y + i);
				cout << "                       ";
			}
			gotoxy(cac_x + 22, cac_y);
			setcursortype(NORMALCURSOR);
			cur_cac = 0;
			step++;
		}
		if (step == 2) {
			switch (key) {
			case ESC:
				gotoxy(cac_x, cac_y); cout << "                                ";
				gotoxy(cac_x, cac_y + 1); cout << "                                ";
				setcursortype(NOCURSOR);
				return;
			case 0x30:
			case 0x31:
			case 0x32:
			case 0x33:
			case 0x34:
			case 0x35:
			case 0x36:
			case 0x37:
			case 0x38:
			case 0x39:
				if (cur_cac<5) {
					num[cur_cac] = key;
					cur_cac++;
				}
				break;
			case BACKSPACE:
				if (cur_cac>0) {
					cur_cac--;
					num[cur_cac] = 0;
				}
				break;
			case ENTER:
				intNum = atoi(num);
				if (intNum == 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
					gotoxy(cac_x, cac_y + 1); printf("1 ~ 99999 �� ���� �Է����ּ���.");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
				}
				else {
					gotoxy(cac_x, cac_y + 1); cout << "                                ";
					step++;
				}
			}
			if (key != 0) {
				gotoxy(cac_x + 22, cac_y);
				cout << num << ' ';
				gotoxy(cac_x + 22 + cur_cac, cac_y);
			}
		}
		if (step == 3) {
			key = 0;
			gotoxy(cac_x + 22, cac_y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
			cout << intNum << "��";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			cout << " ��/�Ĵ�..";
			cur_cac = 0;
			step++;
			gotoxy(cac_x + strlen(num) + 25, cac_y);
			setcursortype(SOLIDCURSOR);
		}
		if (step == 4) {
			switch (key) {
			case ESC:
				gotoxy(cac_x, cac_y); cout << "                                       ";
				gotoxy(cac_x, cac_y + 1); cout << "                                       ";
				return;
			case RIGHT:
				if (cur_cac == 0) {
					gotoxy(cac_x + strlen(num) + 28, cac_y);
					cur_cac = 1;
				}
				break;
			case LEFT:
				if (cur_cac == 1) {
					gotoxy(cac_x + strlen(num) + 25, cac_y);
					cur_cac = 0;
				}
				break;
			case ENTER:
				gotoxy(cac_x + strlen(num) + 25, cac_y);
				if (cur_cac == 0) {
					temp = temp - intNum;
					cout << "����     ";
				}
				if (cur_cac == 1) {
					temp = temp + intNum;
					cout << "�Ĵ�     ";
				}
				temp.color = 0x000F;
				gotoxy(cac_x + 5, cac_y + 1);
				temp.showDate(); cout << "�Դϴ�.";
				setcursortype(NOCURSOR);
				return;
			}
		}
	}
}

void CalInterface::showCurTime(void) {
	time_t raw;
	time(&raw);
	struct tm* curtime;
	gotoxy(clock_x, clock_y);
	curtime = localtime(&raw);
	cout << setw(2) << setfill('0') << curtime->tm_hour << ':' << setw(2) << setfill('0') << curtime->tm_min << ':' << setw(2) << setfill('0') << curtime->tm_sec;
}
void CalInterface::hideCurTime(void) {
	gotoxy(clock_x, clock_y);
	cout << "         ";
}

int main(void) {

	setcursortype(NOCURSOR);

	CalInterface CalIF;

	CalIF.display();

	for (int f_cnt = 0;; f_cnt++) {
		CalIF.getKey();
	}

}
