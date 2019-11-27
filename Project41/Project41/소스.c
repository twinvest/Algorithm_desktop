// idle �ݺ�

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat Vx = 0.0;
GLfloat Vy = 0.0;
GLfloat Delta = 0.0;
GLfloat Gamma = 0.0;

void MyKeyboard(unsigned char KeyPressed, int X, int Y); //�Լ���������
void MyDisplay();										 //�Լ���������
void MyIdle();											//�Լ���������
void processSpecialKeys(int key, int x, int y);			//�Լ���������
void YourIdle();										//�Լ���������


void MyDisplay() {                                      //����Լ�

	glClear(GL_COLOR_BUFFER_BIT);						//������ ������ ĥ�ϱ�
	glBegin(GL_POLYGON);								//������ GL_POLYGON���� ����

	glColor3f(0.0, 0.5, 0.8);                           //��������
	
	
	glVertex3f(-1.0 + Vx, -0.5 + Vy, 0.0); //��ǥ��ġ
	glVertex3f(0.0 + Vx, -0.5 + Vy, 0.0);//��ǥ��ġ
	glVertex3f(0.0 + Vx, 0.5 + Vy, 0.0);//��ǥ��ġ
	glVertex3f(-1.0 + Vx, 0.5 + Vy, 0.0);//��ǥ��ġ

	glEnd();											//Begin�� End���̿� �ش��ϴ� ������ ���� ��ǥ���� ��Ÿ����.

	glutSwapBuffers();						//���۸��غ��� ����Ʈ ���ۿ� �� �۸��� �������ϱ� ���� ���̶�� �Ѵ�. ��, �츮�� �����ð��� ��� ������۸��� �����ϸ� �ɰͰ���.
}


void MyIdle() {								 //glutIdleFunc ���ڷ� �̿��� �ð�������� �����̴� �˰���
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

	glutPostRedisplay();                 //������ �����츦 ���ΰ�ħ �ϵ��� �䱸�ϴ� �Լ�.
}
void YourIdle() {                        //glutIdleFunc ���ڷ� �̿��� �ݽð�������� �����̴� �˰���

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

	glutPostRedisplay(); //������ �����츦 ���ΰ�ħ �ϵ��� �䱸�ϴ� �Լ�.
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {   //Ű���� ������ ���� �߰��� �κ�. ��, �ƽ�Ű�ڵ带 �̿��Ͽ� ���� ����� Ű���带 ����� �� �ִ�.
	switch (KeyPressed) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	case 127:                                              //Ű���忡�� delete�Է½� 
		glutIdleFunc(YourIdle);							//glutIdleFunc�� ���� ���� ����� �ݽð� �������� �����̴� ���̵� �ݹ��Լ� YourIdle �� �۵�.
		break;
	}
}
void processSpecialKeys(int key, int x, int y)
{
	switch (key) //Ű ���� �Է¹޾Ƽ� �з�
	{
	case GLUT_KEY_LEFT:      //�������� ���ϴ� ����Ű
		if (Vx < 0.01)
			break;
		else
		{
			Vx = Vx - 0.01f;
			break;
		}

	case GLUT_KEY_RIGHT:     //���������� ���ϴ� ����Ű
		if (Vx > 1.0)
			break;
		else
		{
			Vx = Vx + 0.01f;
			break;
		}
	case GLUT_KEY_UP:       //���� ���ϴ� ����Ű
		if (Vy > 0.49)
			break;
		else
		{
			Vy = Vy + 0.01f;
			break;
		}
	case GLUT_KEY_DOWN:     //�Ʒ��� ���ϴ� ����Ű
		if (Vy < -0.5)
			break;
		else
		{
			Vy = Vy - 0.01f;
			break;
		}
	case GLUT_KEY_INSERT:   //�μ�Ʈ�� �����ÿ��� 
		glutIdleFunc(MyIdle);//MyIdle�ݹ��Լ��� ȣ���. ��, �簢���� �ð�������� ȸ���Ѵ�.
		break;
	}
	glutPostRedisplay(); //������ �����츦 ���ΰ�ħ ��.
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);//�̰� �����ϸ� �����󿡼��� ������ �ȵȴٰ� �Ѵ�. ������󿡼��� ��������. ������� �ü���� ���ǿ���.
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//���÷��̸�弳��
	glutInitWindowSize(500, 500);//�������� ũ�⼳��
	glutInitWindowPosition(0, 0);//�������� ��ġ����
	glutCreateWindow("OpenGL Drawing Example");//���� ����.

	glClearColor(1.0, 1.0, 1.0, 1.0);//����������

	glMatrixMode(GL_PROJECTION);//��ĸ�带 �����ϴµ� �� ��, ����, �ؽ��� ���� ������ �� �ִٰ��Ѵ�.
	glLoadIdentity();//��ȯ����� ������ķ� �����Ѵٰ��Ѵ�. ��, �ʱ���·� �ȴ�.

	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); //���������Լ�.

	glutDisplayFunc(MyDisplay);//����Լ� ����.

	glutKeyboardFunc(MyKeyboard);  //���� �� ���� Ű�� ���� �ݹ��Լ��� ����ϱ� ���� ��. Ű���� �̺�Ʈ�� �߻����� �� glut�� ������ Ű�� �Ķ���� ket�� ���ؼ� �ݹ��Լ����� ����.

	glutSpecialFunc(processSpecialKeys); //�� �Լ��� �̿��ϸ� glut.h�� ���ǵǾ� �ִ� ���� Ư��Ű���� ����� �� �ִ�.

										 //glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}
