#include <Windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include <GL/glaux.h>

/*GLvoid drawScene(GLvoid);

void main(int argc, char*argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Example1");
	glutDisplayFunc(drawScene);
	glutMainLoop;

}

GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}*/

void Display() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main() {
	glutCreateWindow("OpenGL Hello World!");
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}

//glaux 라이브러리도 설정할것!

/*void drawScene();
int main()
{
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Example1");
	glutDisplayFunc(drawScene);
	glutMainLoop();
	return 0;

}

void drawScene(GLvoid)
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}*/