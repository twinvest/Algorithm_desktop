#include <stdio.h>
#include <stdarg.h> // va_list, va_start, va_arg, va_end �� ����ϱ� ���ؼ�

void printNumbers(int args, ...)// ���������� ������ ���� �� �ִ� ù��° ����, �ι�° �Ű� ������ ���� �������ڸ� ���޹޴� �κ�.
{//�������� ó�� ��ũ�ο����� �˾ƺ��� ...���� ���� �������ڸ� ����Ϸ��� stdarg.h��� ������ ��ũ�θ� ����ؾ���.
	va_list ap; // �������� ���. ���������� �޸� �ּҸ� �����ϴ� ������
	va_start(ap, args);// ���� ���ڸ� ���� �� �� �ֵ��� �����͸� ����.
	for (int i = 0; i < args; i++)
	{
		int num = va_arg(ap, int);//�������� �����Ϳ��� Ư�� �ڷ��� ũ�⸸ŭ ���� ������
		printf("%d", num);
	}

	va_end(ap);// �������� ó���� ������ �� null�����ͷ� �ʱ�ȭ
	printf("\n");
}

int main(void)
{
	printNumbers(4, 10, 20, 30, 40, 50, 60);
}

