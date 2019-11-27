
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
	float*score = NULL; //배열 대신 포인터 변수 선언.
	float max, min, sum, mean;

	int n; //학생수

	printf("학생수? ");
	scanf_s("%d", &n);

	score = (float*)malloc(n * sizeof(float));// 동적할당 시작.
	if (score == NULL)
	{
		printf("에러 : 동적메모리 할당 실패!!\n\n");
		return;
	}


	infile = (FILE*)fopen("scores.txt", "r");
	//fopen_s(infile, "scores.txt", "r");
	if (infile == NULL)
	{
		printf("에러 :입력 파일을 열 수 없음. \n\n");
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
		printf("에러 : 출력파일을 열 수 없음!!!\n\n");
		return;
	}

	sava_result_file(outfile, max, min, sum, mean);

	fclose(infile);
	fclose(outfile);
	free(score);

}
