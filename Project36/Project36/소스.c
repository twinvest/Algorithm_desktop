 #include <stdio.h>
#include <string.h>
 #include <stdlib.h>
 #include <ctype.h>

 void printchar(unsigned char c)
 {
     if (isprint(c))
         printf("%c", c); // 해당하는 값을 문자로 표시
      else
          printf("."); // 출력 불가능한 문자는 그냥 .으로 표시
 }
 // 메모리 시작 주소와 출력할 크기를 인자로 받음
 void dumpcode(unsigned char *buff, int len)
 {
    int i;
    for (i = 0; i<len; i++)
    {
       // 16바이트 단위로 주소 출력
       if (i % 16 == 0)
          printf("0x%08x ", &buff[i]);
       // hex 값 출력
       printf("%02x ", buff[i]);
       // 해당 16진수들을 각각 문자로 출력
       if (i % 16 - 15 == 0)
       {
          int j;
          printf(" ");
          for (j = i - 15; j <= i; j++)
             printchar(buff[j]);
          printf("\n");
       }
    }
    // 마지막 라인이 16바이트 이하일 경우 정렬 유지
   if (i % 16 != 0)
    {
       int j;
       int spaces = (len - i + 16 - i % 16) * 3 + 2;
       for (j = 0; j<spaces; j++)
          printf(" "); // 부족한 공간만큼 space로 이동한 후,
       for (j = i - i % 16; j<len; j++)
          printchar(buff[j]); // 남은 문자 값들 출력
   }
    printf("\n");
 }

 int main(int argc, char *argv[])
	  {
	      char buffer[20] = { 0, }; // 0으로 초기화
	       int *pointer_to_ret = (int *)(buffer + 24); // ret을 출력하기 위한 포인터 변수
	        if (argc < 2)
	           {
	               printf("argument error\n");
	                exit(-1);
	                 }
	        // dumpcode로 메모리 덤프
	        dumpcode(buffer, 28);
	         printf("[*] BEFORE : the return address is 0x%08x\n\n", *pointer_to_ret);
	          // buffer overflow!!
	          strcpy(buffer, argv[1]);
	
	           // dumpcode로 메모리 덤프
	           dumpcode(buffer, 28);
	            printf("[*] AFTER : the return address is 0x%08x\n\n", *pointer_to_ret);
	}
