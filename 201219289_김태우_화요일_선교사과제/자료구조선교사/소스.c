#include <stdio.h>
#include <conio.h>
#include <windows.h>



typedef struct {
	int mis;
	int can;
} MACState;


MACState bank[2];         // left bank, right bank



#define MAX_STEP              2
#define MAX_RULE              2
#define MAX_SIDE              2
#define GOAL_CHECK            0
#define STEP_GOTO_1           1
#define STEP_GOTO_2           2
#define STEP_CONTINUE         3



							// 0: CAN, CAN

							// 1: CAN only

							// 2: MIS, CAN

							// 3: MIS, MIS

							// 4: MIS only



char *rule_name[] = { 
"2 Cannibals",

"1 Cannibal",

"1 Missionary And 1 Cannibal",

"2 Missionaries",

"1 Missionary" };



#define CANCAN    0
#define    CAN    1
#define MISCAN    2
#define MISMIS    3
#define MIS       4



int rule_table[MAX_STEP][MAX_RULE][MAX_SIDE] = { { {CANCAN, CAN}, { NULL, NULL }}, { { MISMIS, MISCAN },{ NULL, CAN } } };





int movepeople(int dir, int todo)

{

	static int s, t;



	s = 0;

	t = 1;



	if (dir == 1)

	{

		s = 1;

		t = 0;

	}



	switch (todo)

	{

	case 0:

		if (bank[s].can < 2)

			return 0;

		bank[s].can -= 2;    // move can, can

		bank[t].can += 2;

		break;

	case 1:

		if (bank[s].can == 0)

			return 0;

		bank[s].can--;       // move can only

		bank[t].can++;

		break;

	case 2:

		if (bank[s].mis == 0 || bank[s].can == 0)

			return 0;

		bank[s].mis--;                     // move mis, can

		bank[t].mis++;

		bank[s].can--;

		bank[t].can++;

		break;

	case 3:

		if (bank[s].mis < 2)

			return 0;

		bank[s].mis -= 2;    // move mis, mis

		bank[t].mis += 2;

		break;

	case 4:

		if (bank[s].mis == 0)

			return 0;

		bank[s].mis--;                     // move mis only

		bank[t].mis++;

		break;

	}



	return 1;

}



void init()

{

	bank[0].mis = 3;

	bank[0].can = 3;

	bank[1].mis = 0;

	bank[1].can = 0;

}



int safety_check(int cur_step)

{

	if (cur_step == 0)

	{

		if (bank[1].mis == 3 && bank[1].can == 3)

			return GOAL_CHECK;



		if (bank[1].can == 3)

			return STEP_GOTO_2;

	}



	if (cur_step == 1)

	{

		if (bank[1].mis == 3)

			return STEP_GOTO_1;

	}



	return STEP_CONTINUE;

}



void displaystate(int rule, int dir)

{

	static int step = 0;

	int i;
		
	step++;

	printf("---STEP %d---------------------\n", step);



	if (rule == -1)

	{

		printf("<find_solution> Simulator\n");

		printf("Press any key to start!\n");

		getch();

	}

	else

		printf("Move: %s %s\n", rule_name[rule],

		(dir == 0) ? "To The Right" : "To The Left");



	for (i = 0; i < 3; i++)

	{

		if (i < bank[0].mis)

			printf(" Mis");



		printf("\t\t\t");



		if (i < bank[1].mis)

			printf(" Mis");



		printf("\n");

	}



	for (i = 0; i < 3; i++)

	{

		if (i < bank[0].can)

			printf(" Can");



		printf("\t\t\t");



		if (i < bank[1].can)

			printf(" Can");



		printf("\n");

	}



	Sleep(2000);

}



void find_solution()

{
	int step = 0;
	int dir = 0;                          // left to right
	int cs;
	int stop = 0;
	int rule;

	
	while (!stop)

	{

		rule = 0;

		if (!movepeople(dir, rule_table[step][rule][dir]))

		{

			rule = 1;

			movepeople(dir, rule_table[step][rule][dir]);

		}



		cs = safety_check(step);



		switch (cs)

		{

		case GOAL_CHECK:

			stop = 1;

			break;

		case STEP_GOTO_1:

			step = 0;

			break;

		case STEP_GOTO_2:

			step = 1;

			break;

		case STEP_CONTINUE:

			break;

		}



		displaystate(rule, dir);



		// turn the direction

		dir = (dir == 0) ? 1 : 0;

	}

}

void main()

{

	init();

	displaystate(-1, -1);

	find_solution();

	printf("Done!\n");

}
