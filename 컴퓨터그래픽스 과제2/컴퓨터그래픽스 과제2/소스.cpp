// idle 콜벡

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat Delta = 0.0;
GLfloat Gamma = 0.0;
GLfloat alpha = 0.0;
GLfloat beta = 0.0;
GLfloat seta = 0.0;
GLfloat omega = 0.0; //좌표를 조절하기 위한 변수들.

void MyKeyboard(unsigned char KeyPressed, int X, int Y); //함수원형선언
void MyDisplay();										 //함수원형선언
void MyIdle();											//함수원형선언
void processSpecialKeys(int key, int x, int y);			//함수원형선언
void YourIdle();										//함수원형선언


void MyDisplay() {                                      //출력함수
	
	glClear(GL_COLOR_BUFFER_BIT);						//설정한 색으로 칠하기
	glBegin(GL_POLYGON);								//도형을 GL_POLYGON으로 설정
	
	glColor3f(0.0, 0.5, 0.8);                           //색상지정
	glVertex3f(-1.0 + Delta - alpha +omega, -0.5 + Gamma + beta -seta, 0.0); //좌표위치
	glVertex3f(0.0 + Delta - alpha + omega, -0.5 + Gamma + beta - seta, 0.0);//좌표위치
	glVertex3f(0.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);//좌표위치
	glVertex3f(-1.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);//좌표위치
	
	glEnd();											//Begin과 End사이에 해당하는 도형의 점의 좌표들을 나타낸다.
	
	glutSwapBuffers();						//구글링해보니 프런트 버퍼와 백 퍼르를 스와핑하기 위한 것이라고 한다. 즉, 우리가 수업시간때 배운 더블버퍼링을 생각하면 될것같다.
}


void MyIdle() {								 //glutIdleFunc 인자로 이용할 시계방향으로 움직이는 알고리즘
	if (Delta <= 1)
		Delta = Delta + 0.0001;

	if (Delta >= 1 && Gamma >= -0.5) 
		Gamma = Gamma - 0.0001;

	else if (Delta >= 0.9 && alpha < 1)
		alpha = alpha + 0.0001;

	else if (alpha > 0.9 && beta < 1)
		beta = beta + 0.0001;

	glutPostRedisplay();                 //현재의 윈도우를 새로고침 하도록 요구하는 함수.
}
void YourIdle() {                        //glutIdleFunc 인자로 이용할 반시계방향으로 움직이는 알고리즘

	if (Gamma <= 0.5)
		Gamma = Gamma + 0.0001;
	if (Delta > 0 && Gamma >= 0.49)
		Delta = Delta - 0.0001;
	else if (Gamma >= 0.49 && seta <= 1)
		seta = seta + 0.0001;
	else if (seta > 0.9 && omega <=1)
	{
		omega = omega + 0.0001;
	}

	glutPostRedisplay(); //현재의 윈도우를 새로고침 하도록 요구하는 함수.
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {   //키보드 조작을 위해 추가된 부분. 즉, 아스키코드를 이용하여 내가 사용할 키보드를 등록할 수 있다.
	switch (KeyPressed) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	case 127:                                              //키보드에서 delete입력시 
		glutIdleFunc(YourIdle);							//glutIdleFunc에 의해 내가 등록한 반시계 방향으로 움직이는 아이들 콜백함수 YourIdle 이 작동.
		break;
	}
}
void processSpecialKeys(int key, int x, int y)
{
	switch (key) //키 값을 입력받아서 분류
	{
	case GLUT_KEY_LEFT:      //왼쪽으로 향하는 방향키
		if (Delta < 0.01)
			break;
		else
		{
			Delta = Delta - 0.01f;
			break;
		}
	
	case GLUT_KEY_RIGHT:     //오른쪽으로 향하는 방향키
		if (Delta > 1.0)
			break;
		else
		{
			Delta = Delta + 0.01f;
			break;
		}
	case GLUT_KEY_UP:       //위로 향하는 방향키
		if (Gamma > 0.49)
			break;
		else
		{
			Gamma = Gamma + 0.01f;
			break;
		}
	case GLUT_KEY_DOWN:     //아래로 향하는 방향키
		if (Gamma < -0.5)
			break;
		else
		{
			Gamma = Gamma - 0.01f;
			break;
		}
	case GLUT_KEY_INSERT:   //인설트를 누를시에는 
		glutIdleFunc(MyIdle);//MyIdle콜백함수가 호출됨. 즉, 사각형이 시계방향으로 회전한다.
		break;
	}
	glutPostRedisplay(); //현재의 윈도우를 새로고침 함.
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);//이걸 생략하면 도스상에서는 실행이 안된다고 한다. 윈도우상에서는 생략가능. 윈도우와 운영체제와 세션연결.
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//디스플레이모드설정
	glutInitWindowSize(500, 500);//윈도우의 크기설정
	glutInitWindowPosition(0, 0);//위도우의 위치설정
	glutCreateWindow("OpenGL Drawing Example");//실제 생성.
	
	glClearColor(1.0, 1.0, 1.0, 1.0);//바탕색설정
	
	glMatrixMode(GL_PROJECTION);//행렬모드를 설정하는데 모델 뷰, 투영, 텍스쳐 등을 설정할 수 있다고한다.
	glLoadIdentity();//변환행렬을 단위행렬로 설정한다고한다. 즉, 초기상태로 된다.
	
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //직각투영함수.
	
	glutDisplayFunc(MyDisplay);//출력함수 지정.

	glutKeyboardFunc(MyKeyboard);  //문자 및 숫자 키에 대한 콜백함수를 등록하기 위한 것. 키보드 이벤트가 발생했을 때 glut는 눌러진 키를 파라미터 ket를 통해서 콜백함수에게 전달.

	glutSpecialFunc(processSpecialKeys); //이 함수를 이용하면 glut.h에 정의되어 있는 여러 특수키들을 사용할 수 있다.

	//glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}
