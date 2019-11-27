//    �������� ����� �׸��� ���� �ּ� 4X4(16��)�� �ּ� ������ mesh �� 
//  2�� ����� ������ 3���� ��ǥ�� ������ �� �������� ����� ���õ� Control Points ������� �׸� �ҽ���

#include<GL/glut.h>
#include<stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <SOIL.h>
#include <windows.h>

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
}

};

// �� �������� 4��°�� ctrlpoint2�� �� �������� ù ��°�� ��ġ��Ű�� �� ���� ��������.
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


static GLuint texture;

void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //���۸� �̸� ������ ������ �����

														//1
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]); //2���� �򰡿�� ����
	glColor3f(1.0, 1.0, 1.0); //���� ����
	glPushMatrix(); //�Լ��� �Ҹ��� ���� ��ȯ��ǥ�� �����س���.
	glRotatef(85.0, 1.0, 1.0, 1.0); //ȸ��
	for (i = 0; i <= 8; i++) { 
		glBegin(GL_LINE_STRIP); 
		for (j = 0; j <= 30; j++)
			glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 8.0); //The glEvalCoord2f function evaluates enabled two-dimensional maps using two domain values, u and v. Define maps with glMap2. 
		glEnd();
		glBegin(GL_LINE_STRIP); //��
		for (j = 0; j <= 30; j++)
			glEvalCoord2f((GLfloat)i / 8.0, (GLfloat)j / 30.0); //The glEvalCoord2f function evaluates enabled two-dimensional maps using two domain values, u and v. Define maps with glMap2. 
		glEnd();
	}
	glEvalMesh2(GL_FILL, 0, 20, 0, 20); //Computes a two-dimensional grid of points or lines.
	glPopMatrix();  //The glPushMatrix and glPopMatrix functions push and pop the current matrix stack.

	
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints2[0][0][0]);
	glColor3f(1.0, 1.0, 1.0);
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
	glEvalMesh2(GL_FILL, 0, 20, 0, 20); //�޽�
	glPopMatrix();
	glFlush();

}


void loadImage() //�ؽ��� ���� �ϰ��� �̹����� ���� ���
{
	// load an image file directly as a new OpenGL texture
	texture = SOIL_load_OGL_texture
	(
		"C:\Users\taewoo\Pictures\Saved Pictures\comp3.raw",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS
	);
}



void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0); //���� ���������� ����
	glEnable(GL_DEPTH_TEST); //GL ��� ��� ���� ����
	glShadeModel(GL_FLAT); //���̵� ��

						   // Get "names" for the textures
	glGenTextures(1, &texture); //�ؽ��� ���
	glBindTexture(GL_TEXTURE_2D, texture); //�ؽ��� ���ε�

										   // Enable everything
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); //1���� �޽��� ����

	loadImage(); //�̹����ҷ�����

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); // The glTexEnvf function sets a texture environment parameter.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //Sets texture parameters.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Sets texture parameters.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //Sets texture parameters.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //Sets texture parameters.

																	   // The glMap2d and glMap2f functions define a two-dimensional evaluator.
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,
		0, 1, 4, 2, &ctrlpoints[0][0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,
		0, 1, 4, 2, &ctrlpoints2[0][0][0]);

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); //1���� �޽��� ����

											 // Enable everything
	glEnable(GL_TEXTURE_2D); //GL��� ��밡�� ����
	glEnable(GL_MAP2_TEXTURE_COORD_2); //GL��� ��밡�� ����
	glEnable(GL_MAP2_VERTEX_3); //GL��� ��밡�� ����

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //����Ʈ�ʱ�ȭ
	glMatrixMode(GL_PROJECTION); //GL_PROJECTION���� ��� ����
	glLoadIdentity();  //���� ����� ID ��ķ� ��ü
	if (w <= h) //���� ��Ŀ� ���� ����� ����.
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW); //��� ����
	glLoadIdentity();

}


void keyboard(unsigned char key, int x, int y) {
	switch (key) { // escŰ ����
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700); // âũ��
	glutInitWindowPosition(100, 100); //â��ġ
	glutCreateWindow("Texture_Mapping_201219289_���¿�"); //����
	init(); //����������Լ�
	glutDisplayFunc(display); //���÷��� �ݹ� ����
	glutReshapeFunc(reshape); //â ũ�Ⱑ ���� �� ������ ���
	glutKeyboardFunc(keyboard); //Ű���� �ݹ� ����
	glutMainLoop();
	return 0;

}