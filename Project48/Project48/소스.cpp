#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int flag2 = 0;
	int k = 0;
	int number = 0;
	int length=0;
	int result=0;
	
	while (1)                           //�������� �Է¹���.
	{
		scanf("%d", &length);
		if (length <= 1000 && length>=1)
			break;
	}
	
	int * p1 = (int*)malloc(sizeof(int)*length);
	int * p2 = (int*)malloc(sizeof(int)*length);   //�Ȱ��� ũ���� ������ �ϳ� �� �����.
	
	for (int i = 0; i < length; i++)              //���� �Է¹���.
	{
		scanf("%d", &p1[i]);
		if (p1[i] > 1000 && p1[i] < 1)
			break;
		p2[i] = 0;                                //�̶� p2�� �� 0���� �ʱ�ȭ.
	}
	
	for (int i = 0; i < length; i++)           //�ߺ����� �ʴ� �͵鸸 �ϴ� ������� ���� ���� ������ �������.
	{
		int flag = 0;
		int pocket=p1[i];
		for (int j = 0; j < length; j++)
		{
			if (pocket == p2[j])
				++flag;
		}
		if (flag == 0)
		{
			p2[number++] = pocket;
		}
	}
	/*for (int i = 0; i < length; i++)
	{
		printf("%d ", p2[i]);
	}
	printf("\n\n");*/
	
	for (int i = 0; i < length; i++)        //���� �ߺ����� �ʴ� ���ҵ��� ī�����ϰ�
	{
		if (p2[i] != 0)
			++result;
	}
	//printf("�ѹ� �ɷ��� p2�� ũ�� : %d\n\n", result);
	for (int j=1; j < result; j++)            //�ڿ� ���ͼ��� �ȵǴ� �͵��� ī�����Ѵ�. ��, ���������̾�� �ϴµ� �� ���� �͵��� ���ö� ���� ī������ ���ش�.
	{
		int flag = 0;
		int pocket = p2[j];
		for (int k = j; k >= 0; k--)
		{
			if (pocket < p2[k])
				flag++;
		}
		if (flag != 0)
			flag2++;
	}
	//printf("���ͼ��� �ȵ� �� : %d\n\n", flag2);

	printf("%d\n", result-flag2);         //�׸��� �� ���� ���ش�.
	return 0;
}