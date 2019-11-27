// 	�������� ����� �׸��� ���� �ּ� 4X4(16��)�� �ּ� ������ mesh �� 
//  2�� ����� ������ 3���� ��ǥ�� ������ �� �������� ����� ���õ� Control Points ������� �׸� �ҽ���

#include <stdlib.h>
#include <GL/glut.h>

//������ ����
GLfloat ctrlpoints[4][4][3] = {
	{
		{ -1.5,-1.5,4.0 },
{ -0.5,-1.5,2.0 },
{ 0.5,-1.5,-1.0 },
{ 1.5,-1.5,2.0 }
	},

{
	{ -1.5,-0.5,1.0 },
{ -0.5,-0.5,3.0 },
{ 0.5,-0.5,0.0 },
{ 1.5,-0.5,-1.0 }
},

{
	{ -1.5,0.5,4.0 },
{ -0.5,0.5,0.0 },
{ 0.5,0.5,3.0 },
{ 1.5,0.5,4.0 }
},

{
	{ -1.5,1.5,-2.0 },
{ -0.5,1.5,-2.0 },
{ 0.5,1.5,0.0 },
{ 1.5,1.5,-1.0 }
} };
// �� �������� �� ��°�� ctrlpoint ���������� ù��°�� ��ġ��Ű�� ������ ��������.
GLfloat ctrlpoints2[4][4][3] = {
	{
		{ 1.5,-1.5,2.0 },
{ 2.5,-1.5,3.0 },
{ 3.5,-1.5,1.0 },
{ 4.5,-1.5,2.0 }
	},

{
	{ 1.5,-0.5,-1.0 },
{ 2.5,-0.5,1.0 },
{ 3.5,-0.5,3.0 },
{ 4.5,-0.5,-2.0 }
},

{
	{ 1.5,0.5,4.0 },
{ 2.5,0.5,2.0 },
{ 3.5,0.5,3.0 },
{ 4.5,0.5,1.0 }
},

{
	{ 1.5,1.5,-1.0 },
{ 2.5,1.5,-2.0 },
{ 3.5,1.5,3.0 },
{ 4.5,1.5,-3.0 }
}

};

void initlights(void)
{// ����{r,g,b,a,}�� ���� ���� ���. light sourcesms ��ȭ�ɼ��ִ�. 
	GLfloat ambient[] = { 0.3, 0.4, 0.1, 1.0 };
	GLfloat position[] = { 0.3, 0.2, 2.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glEnable(GL_LIGHT0); //�������� Ư�� GL ����� ����Ѵ�.

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); // ���� �Ű����� ����

	GLfloat qaLightPosition[] = { 0.0, 1.0, -5, 1.0 };  //"��ġ" ���Ϳ� ���� ���Ɽ

	glLightfv(GL_LIGHT0, GL_POSITION, position);// ���� �Ű����� ����

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); //���� ���� ��� �Ű����� ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //���� ���� ��� �Ű����� ����
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //���� ���� ��� �Ű����� ����

}

void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //���۸� �̸� ������ ������ �����

	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);// The glMap2d and glMap2f functions define a two-dimensional evaluator.
	glColor3f(0.5, 1.0, 1.0); //���� ����
	glPushMatrix();  //�Լ��� �Ҹ��� ���� ��ȯ��ǥ�� �����س���.
	glRotatef(85.0, 1.0, 1.0, 1.0); //ȸ��
	for (i = 0; i <= 8; i++) { 
		glBegin(GL_LINE_STRIP); 
		for (j = 0; j <= 30; j++) 
			glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 8.0); //The glEvalCoord2f function evaluates enabled two-dimensional maps using two domain values, u and v. Define maps with glMap2. 
		glEnd();
		glBegin(GL_LINE_STRIP); 
		for (j = 0; j <= 30; j++) 
			glEvalCoord2f((GLfloat)i / 8.0, (GLfloat)j / 30.0); //The glEvalCoord2f function evaluates enabled two-dimensional maps using two domain values, u and v. Define maps with glMap2. 
		glEnd();
	}
	glEvalMesh2(GL_FILL, 0, 20, 0, 20); //Computes a two-dimensional grid of points or lines.
	glPopMatrix(); //The glPushMatrix and glPopMatrix functions push and pop the current matrix stack.

				   //2�� ����, ��� ���� ���� ���� ������.
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints2[0][0][0]);  // The glMap2d and glMap2f functions define a two-dimensional evaluator.
	glColor3f(1.0, 1.0, 1.0); //�� ����
	glPushMatrix();
	glRotatef(85.0, 1.0, 1.0, 1.0);
	for (i = 0; i <= 8; i++) {
		glBegin(GL_LINE_STRIP);
		for (j = 0; j <= 30; j++)
			glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 8.0);

		glEnd();
		glBegin(GL_LINE_STRIP);
		for (j = 0; j <= 30; j++)
			glEvalCoord2f((GLfloat)i / 8.0, (GLfloat)j / 30.0);

		glEnd();
	}

	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
	glFlush();
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //���� ���������� ����
	glEnable(GL_MAP2_VERTEX_3); //GL ��� ��� ���� ����
	glEnable(GL_LIGHTING); //GL ��� ��� ���� ����
	glEnable(GL_AUTO_NORMAL); //GL ��� ��� ���� ����


	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST); //GL ��� ��� ���� ����
	glShadeModel(GL_SMOOTH); //���̵� ��� ���� 
	initlights(); // �� ���� �Լ� ȣ��

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //����Ʈ �ʱ�ȭ
	glMatrixMode(GL_PROJECTION); //��� ����
	glLoadIdentity();  //���� ����� ID ��ķ� ��ü
	if (w <= h) //���� ��Ŀ� ���� ����� ����.
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW); //��� ����
	glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); //���α׷� ���۽� ��������
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);// displaymode����
	glutInitWindowSize(500, 500); // âũ��
	glutInitWindowPosition(100, 100); //â��ġ
	glutCreateWindow("201219289 ���¿�"); //â����
	init(); //����������Լ�
	glutReshapeFunc(reshape); //ũ�� ���Ҷ� ��� ��������
	glutDisplayFunc(display); //���÷��� �ݹ� ����
	glutKeyboardFunc(keyboard); //Ű���� �ݹ� ����

	glutMainLoop(); //�ݺ�
	return 0;
}



