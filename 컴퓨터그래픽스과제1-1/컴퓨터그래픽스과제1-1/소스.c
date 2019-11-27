#include <Windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawScene(); //함수의 원형

int main()
{
	glutInitDisplayMode(GLUT_RGBA); //이 함수를 통해 디스플레이 모드를 설정할 수 있다. 인자는 PPT참고.
	glutInitWindowPosition(100, 100);//윈도우의 위치를 지정한다.
	glutInitWindowSize(250, 250);//윈도우의 크기를 지정한다.
	glutCreateWindow("Example1");//인자는 창의 제목이 되고, 이 함수를 통해 위에 실제 설정했던 값들을 토대로 창이 생성된다.
	glutDisplayFunc(drawScene); //내가 정의한 함수를 인자로 받아 그 함수를 호출하여 랜더링을 처리한다.
	glutMainLoop(); //메인함수 무한루프. 모든 OpenGL의 메인함수는 이 함수로 끝난다. 다음 이벤트가 일어날 때 까지 계속 기다린다.
	return 0; //프로그램 종료.

}

void drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);//배경색 정의 함수. 인자는 차례대로 빨강, 초록, 파랑, 투명도.
	glClear(GL_COLOR_BUFFER_BIT);// 설정은 위에 함수에서 하지만 실제 지우는건 이 함수로 한다. 즉, 이 함수를 설정해 어떤 버퍼를 지울지 결정하고 실행. 인자는 PPT참고.
	glFlush();//C언어의 FLUSH함수와 비슷함. 명령어를 버퍼에 쌓아두었다가 이 함수를 호출하면 버퍼를 모두 비우고 강제실행을 시킴. 실제로 이 함수를 주석처리하면, 실행이 안됨.
}