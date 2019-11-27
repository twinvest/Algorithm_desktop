// 	베이지어 곡면을 그리기 위한 최소 4X4(16개)의 최소 단위의 mesh 가 
//  2개 연결된 임의의 3차원 좌표를 제시한 후 베이지어 곡면을 제시된 Control Points 기반으로 그린 소스임

#include <stdlib.h>
#include <GL/glut.h>

//제어점 설정
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
// 각 꼭지점의 네 번째를 ctrlpoint 각꼭지점의 첫번째로 일치시키면 맨위가 같아진다.
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
{// 벡터{r,g,b,a,}를 빛을 위해 사용. light sourcesms 변화될수있다. 
	GLfloat ambient[] = { 0.3, 0.4, 0.1, 1.0 };
	GLfloat position[] = { 0.3, 0.2, 2.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glEnable(GL_LIGHT0); //서버측의 특정 GL 기능을 사용한다.

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient); // 광원 매개변수 설정

	GLfloat qaLightPosition[] = { 0.0, 1.0, -5, 1.0 };  //"위치" 벡터에 의한 방향광

	glLightfv(GL_LIGHT0, GL_POSITION, position);// 광원 매개변수 설정

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); //조명 모델의 재료 매개변수 지정
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //조명 모델의 재료 매개변수 지정
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //조명 모델의 재료 매개변수 지정

}

void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //버퍼를 미리 설정된 값으로 지우기

	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);// The glMap2d and glMap2f functions define a two-dimensional evaluator.
	glColor3f(0.5, 1.0, 1.0); //색상 설정
	glPushMatrix();  //함수가 불리기 전의 변환좌표를 저장해놓음.
	glRotatef(85.0, 1.0, 1.0, 1.0); //회전
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

				   //2에 관한, 사실 여기 및은 위랑 동일함.
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints2[0][0][0]);  // The glMap2d and glMap2f functions define a two-dimensional evaluator.
	glColor3f(1.0, 1.0, 1.0); //색 정의
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
	glClearColor(0.0, 0.0, 0.0, 0.0); //배경색 검은색으로 설정
	glEnable(GL_MAP2_VERTEX_3); //GL 기능 사용 가능 설정
	glEnable(GL_LIGHTING); //GL 기능 사용 가능 설정
	glEnable(GL_AUTO_NORMAL); //GL 기능 사용 가능 설정


	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST); //GL 기능 사용 가능 설정
	glShadeModel(GL_SMOOTH); //쉐이딩 방법 설정 
	initlights(); // 빛 설정 함수 호출

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //뷰포트 초기화
	glMatrixMode(GL_PROJECTION); //모드 설정
	glLoadIdentity();  //현재 행렬을 ID 행렬로 대체
	if (w <= h) //현재 행렬에 맞춤 행렬을 곱함.
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW); //모드 설정
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
	glutInit(&argc, argv); //프로그램 시작시 인자전달
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);// displaymode설정
	glutInitWindowSize(500, 500); // 창크기
	glutInitWindowPosition(100, 100); //창위치
	glutCreateWindow("201219289 김태우"); //창생성
	init(); //사용자정의함수
	glutReshapeFunc(reshape); //크기 변할때 어떻게 투영할지
	glutDisplayFunc(display); //디스플레이 콜백 설정
	glutKeyboardFunc(keyboard); //키보드 콜백 설정

	glutMainLoop(); //반복
	return 0;
}



