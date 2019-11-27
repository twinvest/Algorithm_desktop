
#pragma warning(disable:4996)
#pragma comment(lib, "mylib.lib")
#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include "mylib.h"
#define _CRT_SECRUE_NO_WARNINGS




void main()
{
	FILE* infile = NULL;
	FILE* outfile = NULL;

	//float score[30];
	float*score = NULL; //�迭 ��� ������ ���� ����.
	float max, min, sum, mean;

	int n; //�л���

	printf("�л���? ");
	scanf_s("%d", &n);

	score = (float*)malloc(n * sizeof(float));// �����Ҵ� ����.
	if (score == NULL)
	{
		printf("���� : �����޸� �Ҵ� ����!!\n\n");
		return;
	}


	infile = (FILE*)fopen("scores.txt", "r");
	//fopen_s(infile, "scores.txt", "r");
	if (infile == NULL)
	{
		printf("���� :�Է� ������ �� �� ����. \n\n");
		return;
	}

	input_scores_file(infile, score, n);
	print_scores(score, n);


	max = max_score(score, n);
	min = min_score(score, n);
	sum = sum_scores(score, n);
	mean = sum / (float)n;

	print_result(max, min, sum, mean);

	outfile = (FILE*)fopen("result.txt", "w");

	if (outfile == NULL)
	{
		printf("���� : ��������� �� �� ����!!!\n\n");
		return;
	}

	sava_result_file(outfile, max, min, sum, mean);

	fclose(infile);
	fclose(outfile);
	free(score);

}
