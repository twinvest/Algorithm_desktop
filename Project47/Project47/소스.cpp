#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int test_case = 10;
	//scanf("%d", &test_case);

	for (int i = 0; i<test_case; i++)
	{
		int result = 0;
		int length;
		//cin >> length;
		scanf("%d", &length);
		int * p = new int[length];
		//int * p = (int*)malloc(sizeof(int)*length);

		for (int i = 0; i < length; i++)   //������� �ؼ� p[i]�Է¿Ϸ�.
		{
			//cin >> p[i];
			scanf("%d", &p[i]);
			/*if ((p[0] != 0) && (p[1] != 0) && (p[length] != 0) && (p[length - 1] != 0))
				exit(1);*/
		}

		for (int i = 2; i < length - 2; i++)
		{
			int result1 = 0;
			int result2 = 0;
			if ((p[i] > p[i - 1]) && (p[i] > p[i - 2]) && (p[i]>p[i + 1]) && (p[i]>p[i + 2]))  //�̰��� �ǹ��ϴ� �ٴ� p[i]�� ���� 2���� ������ 2������ ���� ��
			{
				if (p[i - 1] >= p[i - 2])          //������ ����
					result1 = p[i - 1];
				else if (p[i - 1] < p[i - 2])
					result1 = p[i - 2];

				if (p[i + 1] >= p[i + 2])           //������ ������
					result2 = p[i + 1];
				else if (p[i + 1] < p[i + 2])
					result2 = p[i + 2];

				if (result1 >= result2)
					result = result + p[i] - result1;
				else
					result = result + p[i] - result2;
			}
		}

		printf("#%d %d\n", i + 1, result);
		//cout<<"#"<<i+1<<" "<<result<<"\n";
		free(p);
	}
}