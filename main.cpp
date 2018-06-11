

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<GL/glu.h>
#endif

#include <stdlib.h>

int flag = 1,flag1=0;
GLfloat angle, angle2;
int moving, startx, starty;
void *currentfont;
void display();
void mydisplay();





void drawstring(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 1.0, 0.0);
		glutBitmapCharacter(currentfont, *c);
	}
}
void renderscene()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0, 0.3, 0.0);

	int i;
	char c1[] = "COMPUTER GRAPHICS PROJECT";
	glRasterPos2f(-3, 19);
	for (int i = 0; c1[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c1[i]);

	char c2[] = "FRACATAL TREE";
	glRasterPos2f(-2, 17);
	for (int i = 0; c2[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c2[i]);

	char c3[] = "NAME:ADITYA RAJ";
	glRasterPos2f(-10, 15);
	for (int i = 0; c3[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c3[i]);

	char c4[] = "NAME:ABHISHEK RAO HS";
	glRasterPos2f(-10,14);
	for (int i = 0; c4[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c4[i]);

	char c5[] = "COLLEGE:NIE INSTITUTE OF TECHNOLOGY";
	glRasterPos2f(-4, 10);
	for (i = 0; c5[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c5[i]);

	char c6[] = "GUIDE:RAKESH K R";
	glRasterPos2f(7, 14);
	for (int i = 0; c6[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c6[i]);

	char c7[] = "";
	glRasterPos2f(250.0, 225.0);
	for (i = 0; c7[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c7[i]);

	char c8[] = "Press  Enter to start";
	glRasterPos2f(-2, 5);
	for (i = 0; c8[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c8[i]);
	glFlush();
	glutSwapBuffers();

}



/*void frontscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glColor3f(0, 0, 1);
	drawstring(-0.4, -0.5, 0.0, "NIE INSTITUTE OF TECHNOLOGY ");
	glColor3f(0.7, 0, 1);
	drawstring(21, 82, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f(1, 0.5, 0);
	drawstring(38, 70, 0.0, "COMPUTER GRAPHICS MINI PROJECT ");
	glColor3f(1, 0, 0);
	drawstring(40, 60, 0.0, "Fractal Tree in C++ using OpenGLE");
	glColor3f(1, 0.5, 0);
	drawstring(20, 50, 0.0, "BY:");
	glColor3f(0.5, 0, 0.5);
	drawstring(10, 40, 0.0, "ADITYA RAJ      (USN-4NN15CS006)");
	drawstring(10, 34, 0.0, "ABHISHEK RAO         (USN-4NN15CS004)");
	glColor3f(1, 0.5, 0);
	drawstring(68, 50, 0.0, "GUIDES:");
	glColor3f(0.5, 0.2, 0.2);
	drawstring(63, 40, 0.0, "Mr. RAKESH");
	drawstring(63, 34, 0.0, "Mr. AJAY AV");
	glColor3f(1, 0.1, 1);
	drawstring(32, 10, 0.0, "PRESS ENTER TO START");
	glFlush();
}*/
void myKeyboardFunc(unsigned char key, int x, int y)

{
	switch (key)
	{
	case 13:if (flag1 == 0) //Ascii of 'enter' key is 13
		flag1 = 1;
		break;
	}
	mydisplay();
}
void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (flag1 == 0)
	
	if (flag1 == 1)
		display();
}

/* GLUT callback Handlers */



static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15.0, 15.0, -1.0, 20.0, -15.0, 15.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void makecylinder(float height, float Base)
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	glColor3f(0.64f, 0.16f, 0.16f);
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
	glPopMatrix();
}
void maketree(float height, float Base)
{

	glPushMatrix();



	float angle;
	makecylinder(height, Base);
	glTranslatef(0.0f, height, 0.0f);
	height -= height*0.2f;
	Base -= Base*0.3f;
	for (int a = 0; a<3; a++)
	{


		angle = 20 + ((rand() % 50));
		if (angle >48)
			angle = -(20 + ((rand() % 50)));
		if (height > 1)
		{
			glPushMatrix();
			if (flag)
				glRotatef(angle, 1.0f, 0.0f, 1.0f);
			else
				glRotatef(angle, 0.0f, 1.0f, 1.0f);
			flag = !flag;
			maketree(height, Base); //recursive call
			glPopMatrix();

		}
		else
		{
			glColor3f(0.0f, 1.0f / a, 0.0f);
			glutSolidSphere(0.1f, 10, 10);// for fruits.

		}
	}
	//Glut.glutSwapBuffers();
	glPopMatrix();
}
static void display(void)
{
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	const double a = t*90.0;
	srand(GLUT_ELAPSED_TIME);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle2, 0, 0, 1);

	maketree(4.0f, 0.1f);
	glutSwapBuffers();
	glFlush();
}


static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	case 'q':
		exit(0);
		break;
	case 13:
		glutDisplayFunc(display);


	}

	glutPostRedisplay();
}



void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
	{
		moving = 1;
		startx = x;
		starty = y;
	}
	if (btn == GLUT_LEFT_BUTTON&&state == GLUT_UP)
	{
		moving = 0;
	}
}
void motion(int x, int y)
{
	if (moving)
	{
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}




/* Program entry point */

int main(int argc, char *argv[])
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("MAIN");
	
	glClearColor(0, 0, 0, 0);
	//glutDisplayFunc(mydisplay);
	glutDisplayFunc(renderscene);
	glutKeyboardFunc(myKeyboardFunc);
	//glutDisplayFunc(mydisplay);
	

	//glutCreateWindow("GLUT Shapes");
	

	glutReshapeFunc(resize);
	//glutDisplayFunc(display);
	glutKeyboardFunc(key);

	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glClearColor(1, 1, 1, 1);


	glEnable(GL_DEPTH_TEST);


	glutMainLoop();

	return EXIT_SUCCESS;
}
