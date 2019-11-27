#include"���.h";
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


	
	//make_opcode_output("output(hw4).txt"); �ּ�ó��

	//assem_pass1(); �ּ�ó�� 
	//assem_pass2(); �ּ�ó��


	//�����Ҵ� ����
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
* ���� : ���α׷� �ʱ�ȭ�� ���� �ڷᱸ�� ���� �� ������ �д� �Լ��̴�.
* �Ű� : ����
* ��ȯ : �������� = 0 , ���� �߻� = -1
* ���� : ������ ��ɾ� ���̺��� ���ο� �������� �ʰ� ������ �����ϰ� �ϱ�
*		   ���ؼ� ���� ������ �����Ͽ� ���α׷� �ʱ�ȭ�� ���� ������ �о� �� �� �ֵ���
*		   �����Ͽ���.
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
	}*/ //�̺κ� ��� �ּ�.

	return result;
}

/* ----------------------------------------------------------------------------------
* ���� : �ӽ��� ���� ��� �ڵ��� ������ �о� ���� ��� ���̺�(inst_table)��
*        �����ϴ� �Լ��̴�.
* �Ű� : ���� ��� ����
* ��ȯ : �������� = 0 , ���� < 0
* ���� : ���� ������� ����
* || �̸� || opcode || ���� || operand ���� ||
* ----------------------------------------------------------------------------------
*/
int init_inst_file(char *inst_file)
{
	FILE * insp = fopen(inst_file, "rt");			//���� �ڵ��� ����
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

	if (insp == NULL)								//������ ���� ��� -1 ����
	{
		errno = -1;
		return errno;
	}

	for (int i = 0; i < MAX_INST; i++)
	{
		str_cnt = 0;
		char *stop;
		char str[20];

		if (fgets(str, 15, insp) != NULL)					//������ 1�پ� ����
		{

			if (!feof(insp))
			{
				str[strlen(str) - 1] = '\0';				//���� ���� �ƴ� ��쿡�� ���� ����
			}

			
			//��ɾ� �̸��� �����̳� ���� �����ϰ� inst���̺� ���� 
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
			
			//��ɾ��� opcode�� �����̳� ���� �����ϰ� inst���̺� ���� 
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

			//��ɾ��� ������ �����̳� ���� �����ϰ� inst���̺� ���� 
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

			//��ɾ��� operand ������ �����̳� ���� �����ϰ� inst���̺� ���� 
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

		printf("���̺� ����� ��ɾ� %d : [%s], Opcode : [%s]\n", i+1, instruction[i].name, instruction[i].op);
	}

}