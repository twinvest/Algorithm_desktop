// ���콺 �ݺ�

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
void MyDisplay();//�Լ���������
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y);//�Լ���������
void MyIdle();//�Լ���������
void YourIdle();//�Լ���������

GLfloat Vx = 0.0;
GLfloat Vy = 0.0; //��ǥ�� �����ϱ� ���� ������.
void MyIdle() {//glutIdleFunc ���ڷ� �̿��� �ð�������� �����̴� �˰���

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

	glutPostRedisplay();//������ �����츦 ���ΰ�ħ �ϵ��� �䱸�ϴ� �Լ�.
}
void YourIdle() {//glutIdleFunc ���ڷ� �̿��� �ݽð�������� �����̴� �˰���

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

	glutPostRedisplay();//������ �����츦 ���ΰ�ħ �ϵ��� �䱸�ϴ� �Լ�.
}
void MyDisplay() { //����Լ�
	glViewport(0, 0, 300, 300);//�����ð��� �����ߵ��� ������ȯ �� ���� �츮 ������â���δ� ����Ʈ ��ȯ�� �Ͼ���Ѵ�. ��, Ŭ���� �� ������ ��� �̹����� �������� ����� ����� �������� �����Ѵ�.
	glClear(GL_COLOR_BUFFER_BIT);//������ ������ ĥ�ϱ�
	glColor3f(0.5, 0.5, 0.5); //��������
	glBegin(GL_POLYGON);//������ GL_POLYGON���� ����
	
	glVertex3f(-1.0 + Vx, -0.5 + Vy, 0.0); //��ǥ��ġ
	glVertex3f(0.0 + Vx, -0.5 + Vy, 0.0);//��ǥ��ġ
	glVertex3f(0.0 + Vx, 0.5 + Vy, 0.0);//��ǥ��ġ
	glVertex3f(-1.0 + Vx, 0.5 + Vy, 0.0);//��ǥ��ġ
	
	glEnd();//Begin�� End���̿� �ش��ϴ� ������ ���� ��ǥ���� ��Ÿ����.
	glFlush();//�׿��ִ� ��ɾ���� ��� ����, ��� ����ǵ��� �Ѵ�.
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) { //glutMouseFunc�Լ��� ���ڷ� ����.
	if (State == GLUT_DOWN && Button == GLUT_MIDDLE_BUTTON)    //��� ��ư Ŭ���ÿ���
		exit(1);												//����

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {   //���� ��ư Ŭ���ÿ���
		glutIdleFunc(MyIdle);									//�ð����ȸ��
	}
	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {  //������ ��ư Ŭ���ÿ���
		glutIdleFunc(YourIdle);									//�ݽð����ȸ��
	}
}

/*void MyMouseMove(GLint X, GLint Y) {
	BottomRightX = X;
	BottomRightY = Y;
	glutPostRedisplay();
}*/

int main(int argc, char** argv) {
	glutInit(&argc, argv);//�̰� �����ϸ� �����󿡼��� ������ �ȵȴٰ� �Ѵ�. ������󿡼��� ��������. ������� �ü���� ���ǿ���.
	glutInitDisplayMode(GLUT_RGB);//���÷��̸�弳��
	glutInitWindowSize(300, 300);//�������� ũ�⼳��
	glutInitWindowPosition(0, 0);//�������� ��ġ����
	glutCreateWindow("OpenGL Drawing Example");//���� ����.

	glClearColor(1.0, 1.0, 1.0, 1.0);//����������
	glMatrixMode(GL_PROJECTION);//��ĸ�带 �����ϴµ� �� ��, ����, �ؽ��� ���� ������ �� �ִٰ��Ѵ�.
	glLoadIdentity();//��ȯ����� ������ķ� �����Ѵٰ��Ѵ�. ��, �ʱ���·� �ȴ�.
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);//���������Լ�.

	glutDisplayFunc(MyDisplay);//����Լ� ����.
	glutMouseFunc(MyMouseClick);//����� ���� �Լ�. ���콺 �̺�Ʈ�� ���콺 ��ư�� ���� �� �Ǵ� ���콺�� ������ �� �߻�.
	//glutMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}
