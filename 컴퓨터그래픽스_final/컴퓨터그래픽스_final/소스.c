// 	베이지어 곡면을 그리기 위한 최소 4X4(16개)의 최소 단위의 mesh 가 
//  2개 연결된 임의의 3차원 좌표를 제시한 후 베이지어 곡면을 제시된 Control Points 기반으로 그린 소스임

#include<GL/glut.h>
#include<stdlib.h>

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

// 각 꼭지점의 4번째를 ctrlpoint2의 각 꼭지점의 첫 번째로 일치시키면 맨 위가 같아진다.
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


void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//1
	//glShadeModel(GL_SMOOTH); //구로 셰이딩을 의미.
	glShadeModel(GL_FLAT);     // 플랫 셰이딩을 의미.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, &MyTexture);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	
	glRotatef(85.0, 1.0, 1.0, 1.0);

	for (i = 0; i <= 8; i++) {
		glBegin(GL_LINE_STRIP);
		for (j = 0; j <= 30; j++) {
			glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 8.0);
		}
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (j = 0; j <= 30; j++) 
			glEvalCoord2f((GLfloat)i / 8.0, (GLfloat)j / 30.0);
	
		
		glEnd();
	}
	glPopMatrix();

	//2
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

	glPopMatrix();
	
	glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char** argv) {
	GLubyte MyTexture[8][8][3];
	int s, t;
	for (s = 0; s < 8; s++)
	{
		for (t = 0; t < 8; t++)
		{
			GLubyte Intensity = ((s + t) % 2) * 255;
			MyTexture[s][t][0] = Intensity;
			MyTexture[s][t][1] = Intensity;
			MyTexture[s][t][2] = Intensity;
		}
	}
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}