 #include <stdio.h>
#include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

 void printchar(unsigned char c)
 {
     if (isprint(c))
         printf("%c", c); // �ش��ϴ� ���� ���ڷ� ǥ��
      else
          printf("."); // ��� �Ұ����� ���ڴ� �׳� .���� ǥ��
 }
 // �޸� ���� �ּҿ� ����� ũ�⸦ ���ڷ� ����
 void dumpcode(unsigned char *buff, int len)
 {
    int i;
    for (i = 0; i<len; i++)
    {
       // 16����Ʈ ������ �ּ� ���
       if (i % 16 == 0)
          printf("0x%08x ", &buff[i]);
       // hex �� ���
       printf("%02x ", buff[i]);
       // �ش� 16�������� ���� ���ڷ� ���
       if (i % 16 - 15 == 0)
       {
          int j;
          printf(" ");
          for (j = i - 15; j <= i; j++)
             printchar(buff[j]);
          printf("\n");
       }
    }
    // ������ ������ 16����Ʈ ������ ��� ���� ����
   if (i % 16 != 0)
    {
       int j;
       int spaces = (len - i + 16 - i % 16) * 3 + 2;
       for (j = 0; j<spaces; j++)
          printf(" "); // ������ ������ŭ space�� �̵��� ��,
       for (j = i - i % 16; j<len; j++)
          printchar(buff[j]); // ���� ���� ���� ���
   }
    printf("\n");
 }

 int main(int argc, char *argv[])
	  {
	      char buffer[20] = { 0, }; // 0���� �ʱ�ȭ
	       int *pointer_to_ret = (int *)(buffer + 24); // ret�� ����ϱ� ���� ������ ����
	        if (argc < 2)
	           {
	               printf("argument error\n");
	                exit(-1);
	                 }
	        // dumpcode�� �޸� ����
	        dumpcode(buffer, 28);
	         printf("[*] BEFORE : the return address is 0x%08x\n\n", *pointer_to_ret);
	          // buffer overflow!!
	          strcpy(buffer, argv[1]);
	
	           // dumpcode�� �޸� ����
	           dumpcode(buffer, 28);
	            printf("[*] AFTER : the return address is 0x%08x\n\n", *pointer_to_ret);
	}
