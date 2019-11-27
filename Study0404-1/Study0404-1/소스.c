#include<stdio.h>

void main(void)
{
	FILE*src = fopen("twinvest.txt", "rb");
	FILE*des = fopen("twinvest2.txt", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (1)
	{
		readCnt = frad(buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf))
		{
			if (feof(src) != 0)
			{
				fwrite(buf, 1, readCnt, des);
				puts("���Ϻ���Ϸ�!");
				break;
			}
			else
				puts("���Ϻ������");
			
			break;
		
		}

		fwrite(buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);
	return 0;
}