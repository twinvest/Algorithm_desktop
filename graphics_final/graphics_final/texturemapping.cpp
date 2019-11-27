//    베이지어 곡면을 그리기 위한 최소 4X4(16개)의 최소 단위의 mesh 가 
//  2개 연결된 임의의 3차원 좌표를 제시한 후 베이지어 곡면을 제시된 Control Points 기반으로 그린 소스임

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


static GLuint texture;

void display(void) {
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //버퍼를 미리 설정된 값으로 지우기

														//1
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]); //2차원 평가요소 정의
	glColor3f(1.0, 1.0, 1.0); //색상 설정
	glPushMatrix(); //함수가 불리기 전의 변환좌표를 저장해놓음.
	glRotatef(85.0, 1.0, 1.0, 1.0); //회전
	for (i = 0; i <= 8; i++) { 
		glBegin(GL_LINE_STRIP); 
		for (j = 0; j <= 30; j++)
			glEvalCoord2f((GLfloat)j / 30.0, (GLfloat)i / 8.0); //The glEvalCoord2f function evaluates enabled two-dimensional maps using two domain values, u and v. Define maps with glMap2. 
		glEnd();
		glBegin(GL_LINE_STRIP); //선
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
	glEvalMesh2(GL_FILL, 0, 20, 0, 20); //메쉬
	glPopMatrix();
	glFlush();

}


void loadImage() //텍스쳐 맵핑 하고픈 이미지의 절대 경로
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
	glClearColor(0.0, 0.0, 0.0, 0.0); //배경색 검은색으로 설정
	glEnable(GL_DEPTH_TEST); //GL 기능 사용 가능 설정
	glShadeModel(GL_FLAT); //쉐이딩 모델

						   // Get "names" for the textures
	glGenTextures(1, &texture); //텍스쳐 모드
	glBindTexture(GL_TEXTURE_2D, texture); //텍스쳐 바인딩

										   // Enable everything
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glEnable(GL_MAP2_VERTEX_3);

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); //1차원 메쉬를 규정

	loadImage(); //이미지불러오기

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

	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); //1차원 메쉬를 규정

											 // Enable everything
	glEnable(GL_TEXTURE_2D); //GL기능 사용가능 설정
	glEnable(GL_MAP2_TEXTURE_COORD_2); //GL기능 사용가능 설정
	glEnable(GL_MAP2_VERTEX_3); //GL기능 사용가능 설정

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //뷰포트초기화
	glMatrixMode(GL_PROJECTION); //GL_PROJECTION으로 모드 설정
	glLoadIdentity();  //현재 행렬을 ID 행렬로 대체
	if (w <= h) //현재 행렬에 맞춤 행렬을 곱함.
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW); //모드 설정
	glLoadIdentity();

}


void keyboard(unsigned char key, int x, int y) {
	switch (key) { // esc키 종료
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700); // 창크기
	glutInitWindowPosition(100, 100); //창위치
	glutCreateWindow("Texture_Mapping_201219289_김태우"); //생성
	init(); //사용자정의함수
	glutDisplayFunc(display); //디스플레이 콜백 설정
	glutReshapeFunc(reshape); //창 크기가 변할 때 투영을 계산
	glutKeyboardFunc(keyboard); //키보드 콜백 설정
	glutMainLoop();
	return 0;

}