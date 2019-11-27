#pragma once
#define MAX_INST 256
#define MAX_LINES 5000
#define MAX_OPERAND 4


char *input_data[MAX_LINES];
static int line_num;	//input명령어 라인의 수
static int sym_cnt;	//symtab의 symbol의 수
static int r_lit_cnt;	//리터럴 값의 전체 수
static int r_cnt;	//서브루틴의 수
static int refer_cnt;	//참조값의 수
static int loc_cnt;	//loc값의 수
int LOCCTR[MAX_LINES];	//loc값 배열	
char cal[3][1];	//연산
int end[10];	//프로그램의 길이




				/*
				* 어셈블리 할 소스코드를 토큰단위로 관리하기 위한 구조체 변수이다.
				*/
struct token_unit
{
	char *label;
	char *operate;
	char *operand[MAX_OPERAND];
	char *comment;
	char op[10];

};

/*
* instruction 목록 파일로 부터 정보를 받아와서 생성하는 구조체 변수이다.
*/
struct inst_unit
{
	char name[7];
	char op[3];
	int format;
	int op_cnt;
};

/*
* 심볼을 관리하는 구조체이다.
* 심볼 테이블은 심볼 이름, 심볼의 위치, 섹션으로 구성된다.
*/
struct symbol_unit {
	char symbol[10];
	int addr;
	int r_cnt;
};
/*
* literal전체 구조체
*/
typedef struct literal_unit {
	char symbol[10];
	int addr;
	int sub_r_cnt;

}literals;

typedef struct symbol_unit symbol;
literals lit_table[MAX_LINES];	//literal 구조체
symbol sym_table[MAX_LINES];

/*
* object code 구조체
*/
typedef struct address_unit {
	char byte[3];
	int op;
	int loc;
	int xbpe;
	int r_cnt;
	int is_r;
	int format;
}address;

address addr[MAX_LINES];

/*
* 참조값(reference) 구조체
*/
typedef struct subroutine {
	char refer[3][30];
	int cnt;
	int sub_cnt;
}sub;


sub refer_table[MAX_LINES];

/*
* 레지스터 값 구조체
*/
typedef struct register_unit
{
	char ch[2];
	int num;
}registe;

registe reg[9] =
{
	{ "A",0 },{ "X",1 },{ "L",2 },{ "B",3 },{ "S",4 },{ "T",5 },{ "F",6 },{ "PC",8 },{ "SW",9 }
};



typedef struct token_unit token;
typedef struct inst_unit inst;
inst instruction[MAX_INST];
token *table[MAX_LINES];

static char *input_file;
static char *output_file;
int init_my_assembler(void);
int init_inst_file(char *inst_file);
int init_input_file(char *input_file);
int search_opcode(char *str);
void make_opcode_output(char *);
int search_register(char *);
void input_sym();
void data_output();
int search_cal(char *);
void input_address();
void make_objectcode_output(char *file_name);