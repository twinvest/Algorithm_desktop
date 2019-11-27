#include <stdio.h>
#include <stdarg.h> // va_list, va_start, va_arg, va_end 를 사용하기 위해서

void printNumbers(int args, ...)// 가변인자의 개수를 받을 수 있는 첫번째 인자, 두번째 매개 변수는 실제 가변인자를 전달받는 부분.
{//가변인자 처리 매크로에대해 알아보자 ...으로 들어온 가변인자를 사용하려면 stdarg.h헤더 파일의 매크로를 사용해야함.
	va_list ap; // 가변인자 목록. 가변인자의 메모리 주소를 저장하는 포인터
	va_start(ap, args);// 가변 인자를 가져 올 수 있도록 포인터를 설정.
	for (int i = 0; i < args; i++)
	{
		int num = va_arg(ap, int);//가변인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
		printf("%d", num);
	}

	va_end(ap);// 가변인자 처리가 끝났을 때 null포인터로 초기화
	printf("\n");
}

int main(void)
{
	printNumbers(4, 10, 20, 30, 40, 50, 60);
}

