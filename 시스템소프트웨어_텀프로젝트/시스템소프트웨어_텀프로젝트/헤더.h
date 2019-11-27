#pragma once
#define MAX_INST 256
#define MAX_LINES 5000
#define MAX_OPERAND 4


char *input_data[MAX_LINES];
static int line_num;	//input��ɾ� ������ ��
static int sym_cnt;	//symtab�� symbol�� ��
static int r_lit_cnt;	//���ͷ� ���� ��ü ��
static int r_cnt;	//�����ƾ�� ��
static int refer_cnt;	//�������� ��
static int loc_cnt;	//loc���� ��
int LOCCTR[MAX_LINES];	//loc�� �迭	
char cal[3][1];	//����
int end[10];	//���α׷��� ����




				/*
				* ����� �� �ҽ��ڵ带 ��ū������ �����ϱ� ���� ����ü �����̴�.
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
* instruction ��� ���Ϸ� ���� ������ �޾ƿͼ� �����ϴ� ����ü �����̴�.
*/
struct inst_unit
{
	char name[7];
	char op[3];
	int format;
	int op_cnt;
};

/*
* �ɺ��� �����ϴ� ����ü�̴�.
* �ɺ� ���̺��� �ɺ� �̸�, �ɺ��� ��ġ, �������� �����ȴ�.
*/
struct symbol_unit {
	char symbol[10];
	int addr;
	int r_cnt;
};
/*
* literal��ü ����ü
*/
typedef struct literal_unit {
	char symbol[10];
	int addr;
	int sub_r_cnt;

}literals;

typedef struct symbol_unit symbol;
literals lit_table[MAX_LINES];	//literal ����ü
symbol sym_table[MAX_LINES];

/*
* object code ����ü
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
* ������(reference) ����ü
*/
typedef struct subroutine {
	char refer[3][30];
	int cnt;
	int sub_cnt;
}sub;


sub refer_table[MAX_LINES];

/*
* �������� �� ����ü
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