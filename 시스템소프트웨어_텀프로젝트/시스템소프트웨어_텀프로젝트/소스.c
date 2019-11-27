#include"헤더.h";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int init_my_assembler(void);
int init_inst_file(char *inst_file);
void print_table(void);

//FILE * rp;
int main(void)
{

	if (init_my_assembler()< 0)
	{
		printf("init_my_assembler: error\n");
		return -1;
	}
	
	/*for (int i = 0; i < MAX_INST; i++)
	{
		
			printf("%s",instruction[i].name);
	}*/


	
	//make_opcode_output("output(hw4).txt"); 주석처리

	//assem_pass1(); 주석처리 
	//assem_pass2(); 주석처리


	//동적할당 해제
	/*for (int i = 0; i < line_num; i++)
	{
		free(table[i]->operand[3]);
		free(table[i]->operand[2]);
		free(table[i]->operand[1]);
		free(table[i]->operand[0]);
		free(table[i]->comment);
		free(table[i]->operate);
		free(table[i]->label);
		free(table[i]);
	}
	return 0;*/

}

/* ----------------------------------------------------------------------------------
* 설명 : 프로그램 초기화를 위한 자료구조 생성 및 파일을 읽는 함수이다.
* 매계 : 없음
* 반환 : 정상종료 = 0 , 에러 발생 = -1
* 주의 : 각각의 명령어 테이블을 내부에 선언하지 않고 관리를 용이하게 하기
*		   위해서 파일 단위로 관리하여 프로그램 초기화를 통해 정보를 읽어 올 수 있도록
*		   구현하였다.
* ----------------------------------------------------------------------------------
*/
int init_my_assembler(void)
{
	int result = 1;

	if ((result = init_inst_file("inst.txt")) < 0)
	{
		return -1;
	}
	/*if ((result = init_input_file("input.txt")) < 0)
	{
		return -1;
	}*/ //이부분 잠시 주석.

	return result;
}

/* ----------------------------------------------------------------------------------
* 설명 : 머신을 위한 기계 코드목록 파일을 읽어 기계어 목록 테이블(inst_table)을
*        생성하는 함수이다.
* 매계 : 기계어 목록 파일
* 반환 : 정상종료 = 0 , 에러 < 0
* 주의 : 기계어 목록파일 형식
* || 이름 || opcode || 형식 || operand 개수 ||
* ----------------------------------------------------------------------------------
*/
int init_inst_file(char *inst_file)
{
	FILE * insp = fopen(inst_file, "rt");			//기계어 코드목록 파일
	int errno;
	int ccnt = 0;
	int str_cnt = 0;
	char op_str[4];
	char format_str[2];
	char op_cnt_str[2];
	op_str[0] = '\0';
	format_str[0] = '\0';
	op_cnt_str[0] = '\0';
	errno = 0;

	if (insp == NULL)								//파일이 없을 경우 -1 리턴
	{
		errno = -1;
		return errno;
	}

	for (int i = 0; i < MAX_INST; i++)
	{
		str_cnt = 0;
		char *stop;
		char str[20];

		if (fgets(str, 15, insp) != NULL)					//파일을 1줄씩 읽음
		{

			if (!feof(insp))
			{
				str[strlen(str) - 1] = '\0';				//파일 끝이 아닐 경우에는 개행 삭제
			}

			
			//명령어 이름을 공백이나 탭을 제거하고 inst테이블에 저장 
			for (int j = 0; j < 6; j++)
			{
				if (str[j] == '\t' || str[j] == ' ')
				{
					continue;
				}
				else
				{
					instruction[i].name[ccnt++] = str[j];
					if (str[j + 1] == '\t' || str[j + 1] == ' ')
					{
						str_cnt = j + 1;
						ccnt = 0;
						break;
					}
				}
			}
			
			//printf("%s\n", instruction[i].name);
			
			//명령어의 opcode를 공백이나 탭을 제거하고 inst테이블에 저장 
			for (int j = str_cnt; j < 10; j++)
			{
				if (str[j] == '\t' || str[j] == ' ')
				{
					continue;
				}
				else
				{
					instruction[i].op[ccnt++] = str[j];
					if (str[j + 1] == '\t' || str[j + 1] == ' ')
					{

						str_cnt = j + 1;
						ccnt = 0;
						op_str[0] = '\0';
						break;
					}
				}
			}

			//명령어의 형식을 공백이나 탭을 제거하고 inst테이블에 저장 
			for (int j = str_cnt; j < 12; j++)
			{

				if (str[j] == '\t' || str[j] == ' ')
				{

					continue;
				}
				else
				{
					format_str[ccnt++] = str[j];
					if (str[j + 1] == '\t' || str[j + 1] == ' ' || str[j + 1] == '\0')
					{
						instruction[i].format = atoi(format_str);
						str_cnt = j + 1;
						ccnt = 0;
						format_str[0] = '\0';
						break;
					}
				}
			}

			//명령어의 operand 갯수를 공백이나 탭을 제거하고 inst테이블에 저장 
			for (int j = str_cnt; j < 15; j++)
			{

				if (str[j] == '\t' || str[j] == ' ')
				{

					continue;
				}
				else
				{
					op_cnt_str[ccnt++] = str[j];
					if (str[j + 1] == '\t' || str[j + 1] == ' ' || str[j + 1] == '\0')
					{
						instruction[i].op_cnt = atoi(op_cnt_str);
						str_cnt = j + 1;
						ccnt = 0;
						op_cnt_str[0] = '\0';
						break;
					}
				}
			}

		}
		else
		{
			break;
		}


	}
	
	print_table();
	return errno;
}


void print_table(void)
{
	int number = 0;
	for (int i = 0; i < 40; i++)
	{

		printf("테이블에 저장된 명령어 %d : [%s], Opcode : [%s]\n", i+1, instruction[i].name, instruction[i].op);
	}

}