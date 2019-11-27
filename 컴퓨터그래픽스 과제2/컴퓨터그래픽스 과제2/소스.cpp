// idle �ݺ�

#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat Delta = 0.0;
GLfloat Gamma = 0.0;
GLfloat alpha = 0.0;
GLfloat beta = 0.0;
GLfloat seta = 0.0;
GLfloat omega = 0.0; //��ǥ�� �����ϱ� ���� ������.

void MyKeyboard(unsigned char KeyPressed, int X, int Y); //�Լ���������
void MyDisplay();										 //�Լ���������
void MyIdle();											//�Լ���������
void processSpecialKeys(int key, int x, int y);			//�Լ���������
void YourIdle();										//�Լ���������


void MyDisplay() {                                      //����Լ�
	
	glClear(GL_COLOR_BUFFER_BIT);						//������ ������ ĥ�ϱ�
	glBegin(GL_POLYGON);								//������ GL_POLYGON���� ����
	
	glColor3f(0.0, 0.5, 0.8);                           //��������
	glVertex3f(-1.0 + Delta - alpha +omega, -0.5 + Gamma + beta -seta, 0.0); //��ǥ��ġ
	glVertex3f(0.0 + Delta - alpha + omega, -0.5 + Gamma + beta - seta, 0.0);//��ǥ��ġ
	glVertex3f(0.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);//��ǥ��ġ
	glVertex3f(-1.0 + Delta - alpha + omega, 0.5 + Gamma + beta - seta, 0.0);//��ǥ��ġ
	
	glEnd();											//Begin�� End���̿� �ش��ϴ� ������ ���� ��ǥ���� ��Ÿ����.
	
	glutSwapBuffers();						//���۸��غ��� ����Ʈ ���ۿ� �� �۸��� �������ϱ� ���� ���̶�� �Ѵ�. ��, �츮�� �����ð��� ��� ������۸��� �����ϸ� �ɰͰ���.
}


void MyIdle() {								 //glutIdleFunc ���ڷ� �̿��� �ð�������� �����̴� �˰���
	if (Delta <= 1)
		Delta = Delta + 0.0001;

	if (Delta >= 1 && Gamma >= -0.5) 
		Gamma = Gamma - 0.0001;

	else if (Delta >= 0.9 && alpha < 1)
		alpha = alpha + 0.0001;

	else if (alpha > 0.9 && beta < 1)
		beta = beta + 0.0001;

	glutPostRedisplay();                 //������ �����츦 ���ΰ�ħ �ϵ��� �䱸�ϴ� �Լ�.
}
void YourIdle() {                        //glutIdleFunc ���ڷ� �̿��� �ݽð�������� �����̴� �˰���

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
		if (Delta < 0.01)
			break;
		else
		{
			Delta = Delta - 0.01f;
			break;
		}
	
	case GLUT_KEY_RIGHT:     //���������� ���ϴ� ����Ű
		if (Delta > 1.0)
			break;
		else
		{
			Delta = Delta + 0.01f;
			break;
		}
	case GLUT_KEY_UP:       //���� ���ϴ� ����Ű
		if (Gamma > 0.49)
			break;
		else
		{
			Gamma = Gamma + 0.01f;
			break;
		}
	case GLUT_KEY_DOWN:     //�Ʒ��� ���ϴ� ����Ű
		if (Gamma < -0.5)
			break;
		else
		{
			Gamma = Gamma - 0.01f;
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
