// idle �ݺ�

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat Delta = 0.0;
GLfloat Gamma = 0.0;
GLfloat alpha=0.0;
GLfloat beta=0.0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + Delta+ alpha, -0.5 + Gamma+ beta, 0.0);
	glVertex3f(0.0 + Delta + alpha, -0.5 + Gamma+ beta, 0.0);
	glVertex3f(0.0 + Delta + alpha, 0.5 + Gamma+ beta, 0.0);
	glVertex3f(-1.0 + Delta + alpha, 0.5 + Gamma+beta, 0.0);
	glEnd();
	glutSwapBuffers();
}

void MyIdle() {
	if (Delta <= 1)  //��Ÿ�� 1���� �������� ��Ÿ���� ����.
		Delta = Delta + 0.001; //��Ÿ 1�̵�

	else(Delta >= 0.9 && Gamma >= 0.4 && alpha > -1) {
		alpha = alpha - 0.001;
	}


	if(Delta >= 0.9 && Gamma >= -0.5) //�׷��� 0.9���� Ŀ���� -0.5���� ������ Ŭ���� ������ ����.
		Gamma = Gamma - 0.001;
	
	

	
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}
