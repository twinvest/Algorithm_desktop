#include <Windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawScene(); //�Լ��� ����

int main()
{
	glutInitDisplayMode(GLUT_RGBA); //�� �Լ��� ���� ���÷��� ��带 ������ �� �ִ�. ���ڴ� PPT����.
	glutInitWindowPosition(100, 100);//�������� ��ġ�� �����Ѵ�.
	glutInitWindowSize(250, 250);//�������� ũ�⸦ �����Ѵ�.
	glutCreateWindow("Example1");//���ڴ� â�� ������ �ǰ�, �� �Լ��� ���� ���� ���� �����ߴ� ������ ���� â�� �����ȴ�.
	glutDisplayFunc(drawScene); //���� ������ �Լ��� ���ڷ� �޾� �� �Լ��� ȣ���Ͽ� �������� ó���Ѵ�.
	glutMainLoop(); //�����Լ� ���ѷ���. ��� OpenGL�� �����Լ��� �� �Լ��� ������. ���� �̺�Ʈ�� �Ͼ �� ���� ��� ��ٸ���.
	return 0; //���α׷� ����.

}

void drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);//���� ���� �Լ�. ���ڴ� ���ʴ�� ����, �ʷ�, �Ķ�, ����.
	glClear(GL_COLOR_BUFFER_BIT);// ������ ���� �Լ����� ������ ���� ����°� �� �Լ��� �Ѵ�. ��, �� �Լ��� ������ � ���۸� ������ �����ϰ� ����. ���ڴ� PPT����.
	glFlush();//C����� FLUSH�Լ��� �����. ��ɾ ���ۿ� �׾Ƶξ��ٰ� �� �Լ��� ȣ���ϸ� ���۸� ��� ���� ���������� ��Ŵ. ������ �� �Լ��� �ּ�ó���ϸ�, ������ �ȵ�.
}