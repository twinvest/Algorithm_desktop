#include<stdio.h>
#pragma comment(lib, "ws2_32.lib")

int main(void)
{
	FILE*src = fopen("01.png", "rb");
	FILE*des = fopen("twinvest2.png", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL)
	{
		puts("파일오픈 실패!");
		return -1;
	}

	while (1)
	{
		readCnt = fread(buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf))
		{
			if (feof(src) != 0)
			{
				fwrite(buf, 1, readCnt, des);
				puts("파일복사완료!");
				break;
			}
			else
				puts("파일복사실패");

			break;

		}

		fwrite(buf, 1, sizeof(buf), des);
	}
	fclose(src);
	fclose(des);
	return 0;
}