// 마우스 콜벡

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
void MyDisplay();//함수원형선언
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);//함수원형선언
void MyIdle();//함수원형선언
void YourIdle();//함수원형선언

GLfloat Vx = 0.0;
GLfloat Vy = 0.0; //좌표를 조절하기 위한 변수들.
void MyIdle() {//glutIdleFunc 인자로 이용할 시계방향으로 움직이는 알고리즘

	while (Vx < 1.0) {
		Vx = Vx + 0.0001;
		MyDisplay();
	}
	while (Vy > -0.5) {
		Vy = Vy - 0.0001;
		MyDisplay();
	}
	while (Vx > -0.0) {
		Vx = Vx - 0.0001;
		MyDisplay();
	}
	while (Vy < 0.5) {
		Vy = Vy + 0.0001;
		MyDisplay();
	}

	glutPostRedisplay();//현재의 윈도우를 새로고침 하도록 요구하는 함수.
}
void YourIdle() {//glutIdleFunc 인자로 이용할 반시계방향으로 움직이는 알고리즘

	while (Vx > 0.0) {
		Vx = Vx - 0.0001;
		MyDisplay();
	}
	while (Vy > -0.5) {
		Vy = Vy - 0.0001;
		MyDisplay();
	}
	while (Vx < 1.0) {
		Vx = Vx + 0.0001;
		MyDisplay();
	}
	while (Vy < 0.5) {
		Vy = Vy + 0.0001;
		MyDisplay();
	}

	glutPostRedisplay();//현재의 윈도우를 새로고침 하도록 요구하는 함수.
}
void MyDisplay() { //출력함수
	glViewport(0, 0, 300, 300);//수업시간때 공부했듯이 투영변환 후 실제 우리 윈도우창으로는 뷰포트 변환이 일어나야한다. 즉, 클리핑 및 투영된 평면 이미지를 윈도우의 어디쯤 출력할 것인지를 지정한다.
	glClear(GL_COLOR_BUFFER_BIT);//설정한 색으로 칠하기
	glColor3f(0.5, 0.5, 0.5); //색상지정
	glBegin(GL_POLYGON);//도형을 GL_POLYGON으로 설정
	
	glVertex3f(-1.0 + Vx, -0.5 + Vy, 0.0); //좌표위치
	glVertex3f(0.0 + Vx, -0.5 + Vy, 0.0);//좌표위치
	glVertex3f(0.0 + Vx, 0.5 + Vy, 0.0);//좌표위치
	glVertex3f(-1.0 + Vx, 0.5 + Vy, 0.0);//좌표위치
	
	glEnd();//Begin과 End사이에 해당하는 도형의 점의 좌표들을 나타낸다.
	glFlush();//쌓여있는 명령어들을 모두 비우고, 즉시 실행되도록 한다.
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //glutMouseFunc함수의 인자로 전달.
	if (State == GLUT_DOWN && Button == GLUT_MIDDLE_BUTTON)    //가운데 버튼 클릭시에는
		exit(1);												//종료

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {   //왼쪽 버튼 클릭시에는
		glutIdleFunc(MyIdle);									//시계방향회전
	}
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {  //오른쪽 버튼 클릭시에는
		glutIdleFunc(YourIdle);									//반시계방향회전
	}
}

/*void MyMouseMove(GLint X, GLint Y) {
	BottomRightX = X;
	BottomRightY = Y;
	glutPostRedisplay();
}*/

int main(int argc, char** argv) {
	glutInit(&argc, argv);//이걸 생략하면 도스상에서는 실행이 안된다고 한다. 윈도우상에서는 생략가능. 윈도우와 운영체제와 세션연결.
	glutInitDisplayMode(GLUT_RGB);//디스플레이모드설정
	glutInitWindowSize(300, 300);//윈도우의 크기설정
	glutInitWindowPosition(0, 0);//위도우의 위치설정
	glutCreateWindow("OpenGL Drawing Example");//실제 생성.

	glClearColor(1.0, 1.0, 1.0, 1.0);//바탕색설정
	glMatrixMode(GL_PROJECTION);//행렬모드를 설정하는데 모델 뷰, 투영, 텍스쳐 등을 설정할 수 있다고한다.
	glLoadIdentity();//변환행렬을 단위행렬로 설정한다고한다. 즉, 초기상태로 된다.
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);//직각투영함수.

	glutDisplayFunc(MyDisplay);//출력함수 지정.
	glutMouseFunc(MyMouseClick);//등록을 위한 함수. 마우스 이벤트는 마우스 버튼을 누를 때 또는 마우스가 움직일 때 발생.
	//glutMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}
