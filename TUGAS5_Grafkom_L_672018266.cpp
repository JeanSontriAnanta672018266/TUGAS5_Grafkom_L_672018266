#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>

void init (void);
void tampil (void);
void mouse (int button,int state,int x,int y);
void keyboard (unsigned char ,int ,int);
void ukuran (int,int);
void mouseMotion(int x,int y);

float xrot =0.0f;
float yrot = 0.0f;

float xdiff = 0.0f;
float ydiff = 0.0f;

bool mouseDown = false;
int is_depth;

int main (int argc , char **argv)
{
	glutInit(&argc ,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("JEAN SONTRI ANANTA - 672018266");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor (1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth =1;
	glMatrixMode (GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(3.0f);
	
	
}

void tampil(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 1.0f);
	if (is_depth)
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
	 glClear(GL_COLOR_BUFFER_BIT);
	 
//jendela dpn

glBegin(GL_QUADS);
glColor3f(0.0,1.0,1.0);
glVertex3f(1.0,0.0,10.1);
glVertex3f(-2.0,0.0,10.1);
glVertex3f(-2.0,-3.0,10.1);
glVertex3f(1.0,-3.0,10.1);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(1.0,0.0,10.1);
glVertex3f(-2.0,0.0,10.1);
glVertex3f(-2.0,0.0,10.1);
glVertex3f(-2.0,-3.0,10.1);
glVertex3f(-2.0,-3.0,10.1);
glVertex3f(1.0,-3.0,10.1);
glVertex3f(1.0,-3.0,10.1);
glVertex3f(1.0,0.0,10.1);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(-0.5,0.0,10.1);
glVertex3f(-0.5,-3.0,10.1);
glEnd();


//pintu
glBegin(GL_QUADS);
glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
glVertex3f(9.8, -10.0, 10.1);
glVertex3f(9.8,0.0,10.1);
glVertex3f(5,0.0,10.1);
glVertex3f(5,-10.0,10.1);
glEnd();
//kunci
glBegin(GL_POINTS);
glColor3f(0.0,0.0,0.0);
glVertex3f(9, -5.0, 10.2);
glEnd();
 
//tembok depan
glBegin(GL_POLYGON);
glColor3f(0.0,1.5,0.0);
glVertex3f(-10.0,-10.0,10.0);
glVertex3f(-10.0,10.0,10.0);
glVertex3f(10.0, 10.0, 10.0);
glVertex3f(10.0,-10.0,10.0);
glVertex3f(-10.0,-10.0,10.0);	
glEnd();

//belakang
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.5f, 1.0f);
glVertex3f(-10.0,-10.0,-20.0);
glVertex3f(-10.0, 10.0, -20.0);
glVertex3f(10.0, 10.0, -20.0);
glVertex3f(10.0,-10.0, -20.0);

glEnd();
//kanan
glBegin(GL_QUADS) ;
glColor3f(1.0,0.0,1.0);
glVertex3f(10.0, 10.0, 10.0);
glVertex3f(10.0,-10.0,10.0);
glVertex3f(10.0,-10.0,-20.0);
glVertex3f(10.0,10.0,-20.0);
glEnd();

//kiri
glBegin(GL_QUADS);
glColor3f(1.0,0.0,1.0);
glVertex3f(-10, 10.0, 10.0);
glVertex3f(-10,-10.0,10.0);
glVertex3f(-10,-10.0,-20.0);
glVertex3f(-10,10.0,-20.0);
glEnd();



//lantai
glBegin(GL_QUADS);
glColor3f(0.0,1.5,0.0);
glVertex3f(-10, -10.0, 10.0);
glVertex3f(10,-10.0,10.0);
glVertex3f(10,-10.0,-20.0);
glVertex3f(-10,-10.0,-20.0);
glEnd();

//karpet
glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.0);
glVertex3f(-4, -10.0, -2.0);
glVertex3f(3,-10.0,-2.0);
glVertex3f(3,-10.0,-15.0);
glVertex3f(-4,-10.0,-15.0);
glEnd();

glBegin(GL_LINES);
glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
glVertex3f(-3, -10.0, -4.0);
glVertex3f(2,-10.0,-4.0);
glVertex3f(2,-10.0,-4.0);
glVertex3f(2,-10.0,-13.0);
glVertex3f(2,-10.0,-13.0);
glVertex3f(-3,-10.0,-13.0);
glVertex3f(-3,-10.0,-13.0);
glVertex3f(-3, -10.0, -4.0);
glEnd();


//tempat tidur
glBegin(GL_QUADS);
glColor3f(0.0,0.0,0.0);

glVertex3f(-10.0,-10.0,-20.0);
glVertex3f(-5.0,-10.0,-20.0);
glVertex3f(-5.0,-10.0,-5.0);
glVertex3f(-10.0,-10.0,-5.0);

glColor3f(1.0,1.0,1.0);
glVertex3f(-10.0,-7.0,-5.0);
glVertex3f(-10.0,-7.0,-20);
glVertex3f(-5.0,-7.0,-20.0);
glVertex3f(-5.0,-7.0,-5.0);
//blkng
glVertex3f(-10.0,-10.0,-20.0);
glVertex3f(-5.0,-10.0,-20.0);
glVertex3f(-5.0,-7.0,-20.0);
glVertex3f(-10.0,-7.0,-20);
//dpn
glVertex3f(-10.0,-10.0,-5.0);
glVertex3f(-5.0,-10.0,-5.0);
glVertex3f(-5.0,-7.0,-5.0);
glVertex3f(-10.0,-7.0,-5.0);

//samping
glVertex3f(-10.0,-10.0,-20.0);
glVertex3f(-10.0,-7.0,-20.0);
glVertex3f(-10.0,-7.0,-5.0);
glVertex3f(-10.0,-10.0,-5.0);

glVertex3f(-5.0,-10.0,-20.0);
glVertex3f(-5.0,-7.0,-20.0);
glVertex3f(-5.0,-7.0,-5.0);
glVertex3f(-5.0,-10.0,-5.0);
glEnd();
//jendela belakang

glBegin(GL_QUADS);
glColor3f(0.0,1.0,1.0);
glVertex3f(1.0,0.0,-20.0);
glVertex3f(-2.0,0.0,-20.0);
glVertex3f(-2.0,-3.0,-20.0);
glVertex3f(1.0,-3.0,-20);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(1.0,0.0,-20.0);
glVertex3f(-2.0,0.0,-20.0);
glVertex3f(-2.0,0.0,-20.0);
glVertex3f(-2.0,-3.0,-20.0);
glVertex3f(-2.0,-3.0,-20.0);
glVertex3f(1.0,-3.0,-20);
glVertex3f(1.0,-3.0,-20);
glVertex3f(1.0,0.0,-20.0);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(-0.5,0.0,-20.0);
glVertex3f(-0.5,-3.0,-20.0);
glEnd();

//jendela kiri
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-10.1,-4,5);
    glVertex3f(-10.1,-4,0.5);
    glVertex3f(-10.1,3,0.5);
    glVertex3f(-10.1,3,5);
    glEnd();
    
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
    glVertex3f(-10.1,-4,2.8);
    glVertex3f(-10.1,3,2.8);
glEnd();

//jendela kanan
glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(10.1,-4,5);
    glVertex3f(10.1,-4,0.5);
    glVertex3f(10.1,3,0.5);
    glVertex3f(10.1,3,5);
    glEnd();
    
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
    glVertex3f(10.1,-4,2.8);
    glVertex3f(10.1,3,2.8);
glEnd();
//laci
glBegin(GL_QUADS);
glColor3f (1.0,0.0,0.0);

glVertex3f(-10.0,-2.0,-20.0);
glVertex3f(-5.0,-2.0,-20.0);
glVertex3f(-5.0,-2.0,-15.0);
glVertex3f(-10.0,-2.0,-15.0);

glColor3f(1.0,1.0,1.0);
glVertex3f(-10.0,1.0,-15.0);
glVertex3f(-10.0,-1.0,-20);
glVertex3f(-5.0,1.0,-20.0);
glVertex3f(-5.0,1.0,-15.0);
//blkng
glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
glVertex3f(-10.0,-2.0,-20.0);
glVertex3f(-5.0,-2.0,-20.0);
glVertex3f(-5.0,1.0,-20.0);
glVertex3f(-10.0,1.0,-20);

//samping
glColor3f(0.0f, 0.1f, 0.0f);
glVertex3f(-10.0,-2.0,-20.0);
glVertex3f(-10.0,1.0,-20.0);
glVertex3f(-10.0,1.0,-15.0);
glVertex3f(-10.0,-2.0,-15.0);

glVertex3f(-5.0,-2.0,-20.0);
glVertex3f(-5.0,1.0,-20.0);
glVertex3f(-5.0,1.0,-15.0);
glVertex3f(-5.0,-2.0,-15.0);
glEnd();

//meja
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f , 0.0f);
glVertex3f(-3.0,-10.0,-20.0);
glVertex3f(-3.0,-6.0 ,-20.0);
glVertex3f(-3.0,-6.0 ,-16.0);
glVertex3f(-3.0,-10.0,-16.0);

glColor3f(1.0f, 0.5f, 0.0f);
glVertex3f(2.0,-10.0,-20.0);
glVertex3f(2.0,-6.0 ,-20.0);
glVertex3f(2.0,-6.0 ,-16.0);
glVertex3f(2.0,-10.0,-16.0);

glColor3f(0.0,0.0,0.0);
glVertex3f(-3.0,-6.0,-20.0);
glVertex3f(-3.0,-6.0,-16.0);
glVertex3f(2.0,-6.0 ,-16.0);
glVertex3f(2.0,-6.0 ,-20.0);
glEnd();

//cermin
glBegin(GL_QUADS);
glColor3f(0.0,1.0,1.0);
glVertex3f(8.0,2.0,-20.0);
glVertex3f(5.0,2.0,-20.0);
glVertex3f(5.0,-5.0,-20.0);
glVertex3f(8.0,-5.0,-20);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(8.0,2.0,-20.0);
glVertex3f(5.0,2.0,-20.0);
glVertex3f(5.0,2.0,-20.0);
glVertex3f(5.0,-5.0,-20.0);
glVertex3f(5.0,-5.0,-20.0);
glVertex3f(8.0,-5.0,-20);
glVertex3f(8.0,-5.0,-20);
glVertex3f(8.0,2.0,-20.0);
glEnd();


//atap
glBegin(GL_POLYGON);
glColor3f(0.1f, 0.1f, 0.1f);

glVertex3f(00.0,20.0,0.0);

glVertex3f(-14, 10, -20);
glVertex3f(14, 10, -20);

glVertex3f(14, 10, -20);
glVertex3f(14, 10,  10);

glVertex3f(14, 10, 10);
glVertex3f(-14, 10, 10);

glVertex3f(-14, 10, 10);
glVertex3f(-14, 10, -20);

glEnd();

glPushMatrix();
glPopMatrix();
glutSwapBuffers();
}

//void idle(){
//	if(!mouseDown){
//		xrot += 0.3f;
//		yrot += 0.4f;
//	}
	//glutPostRedisplay();
//}

void mouse (int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = -x + yrot;
		ydiff = -y + xrot;
	} else {
		mouseDown = false;
	}
}

void mouseMotion(int x, int y){
	if(mouseDown){
		yrot = x - xdiff;
		xrot = y + xdiff;
		glLoadIdentity();
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 0.0);
		break;
	case 'd' :
	case 'D':
		glTranslatef(3.0, 0.0, 3.5);
		break; 
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.5);
		break;
	case 'a' :
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
		
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case '2':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case '8':
		glRotatef(-2.0, 1.8,8.0,0.0);
		break;
	case '6':
		glRotatef(2.0,0.0, 1.0, 0.0);
		break;
	case '4':
		glRotatef(-2.0,0.0,1.0,0.0);
		break;
	case '1':
		glRotatef(2.0,0.0,0.0, 1.0);
		break;	
	
	case '3':
		glRotatef(-2.0, 0.0,0.0, 1.0);
		break;
	case '5':
		if (is_depth){
		
			is_depth =0;
			glDisable(GL_DEPTH_TEST);
		}
		else{
		
		is_depth = 1;
		glEnable(GL_DEPTH_TEST);
		
		}	
    }
		tampil();
}
	
void ukuran(int lebar, int tinggi)
{

	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION) ;
	glLoadIdentity();
	gluPerspective(13.0, lebar / tinggi, 5.0,180.0);
	glTranslatef(0.0, -5.0,-150.0);
	glMatrixMode(GL_MODELVIEW);	
}
	
	
	
	
	
	
