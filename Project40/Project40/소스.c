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
GLfloat omega = 0.0;

void MyKeyboard(unsigned char KeyPressed, int X, int Y);
void MyDisplay();
void MyIdle();
void processSpecialKeys(int key, int x, int y);
void YourIdle();


void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + Delta - alpha + omega, -0.5 + Gamma + beta - seta, 0.0);
	glVertex3f(0.0 + Delta - alpha + omega, -0.5 + Gamma + beta - seta, 0.0);
	glVertex3f(0.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);
	glVertex3f(-1.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);

	glEnd();

	glutSwapBuffers();
}


void MyIdle() {

	if (Delta <= 1)
		Delta = Delta + 0.0001;

	if (Delta >= 1 && Gamma >= -0.5)
		Gamma = Gamma - 0.0001;

	else if (Delta >= 0.9 && alpha < 1)
		alpha = alpha + 0.0001;

	else if (alpha > 0.9 && beta < 1)
		beta = beta + 0.0001;

	glutPostRedisplay();
}
void YourIdle() {

	if (Gamma <= 0.5)
		Gamma = Gamma + 0.0001;
	if (Delta > 0 && Gamma >= 0.49)
		Delta = Delta - 0.0001;
	else if (Gamma >= 0.49 && seta <= 1)
		seta = seta + 0.0001;
	else if (seta > 0.9 && omega <= 1)
	{
		omega = omega + 0.0001;
	}

	glutPostRedisplay();
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {   //키보드 조작을 위해 추가된 부분.
	switch (KeyPressed) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	case 127:
		glutIdleFunc(YourIdle);
		break;
	}
}
void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (Delta < 0.01)
			break;
		else
		{
			Delta = Delta - 0.01f;
			break;
		}

	case GLUT_KEY_RIGHT:
		if (Delta > 1.0)
			break;
		else
		{
			Delta = Delta + 0.01f;
			break;
		}
	case GLUT_KEY_UP:
		if (Gamma > 0.49)
			break;
		else
		{
			Gamma = Gamma + 0.01f;
			break;
		}
	case GLUT_KEY_DOWN:
		if (Gamma < -0.5)
			break;
		else
		{
			Gamma = Gamma - 0.01f;
			break;
		}
	case GLUT_KEY_INSERT:
		glutIdleFunc(MyIdle);
		break;
	}
	glutPostRedisplay(); //이걸 추가해줘야 동작함 ㅅㅂ
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);

	glutDisplayFunc(MyDisplay);

	glutKeyboardFunc(MyKeyboard);  //키보드 등록

	glutSpecialFunc(processSpecialKeys); //키보드 조작을 위해 추가된 부분. 조작키 등록.

										 //glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}
