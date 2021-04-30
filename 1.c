#include<GL/glut.h>
#include <stdio.h>
float xt=1.0,yt=1.0;            // Keyboard buttons
float x = 1.0,y = 1.0,z=1.0;    // Movement
float angle =0;  				
float Autorun = 300;			// For auto movement of small fish

float a=0;

void fish()
{	
	glScalef(0.2,0.2,0);
	glTranslatef(Autorun,100,500);
	glBegin(GL_POLYGON);				// Draw body
	glColor3f(0.12,0.38,0.60);
	glVertex2i(40,200);
	glVertex2i(120,280);
	glVertex2i(320,200);
	glVertex2i(100,160);
	glEnd();
	
	glPushMatrix();
	glRotatef(angle,0.0,0.0,0.0); 
	glBegin(GL_POLYGON);			// Draw tail
	glColor3f(0.12,0.38,0.60);
	glVertex2i(320,200);
	glVertex2i(360,240);
	glVertex2i(340,200);
	glVertex2i(360,160);
	glVertex2i(320,200);
	glEnd();
	
	glBegin(GL_POLYGON);		 // Draw top fin
	glColor3f(0.09,0.24,0.37);
	glVertex2i(120,280);
	glVertex2i(140,300);
	glVertex2i(280,216);
	glVertex2i(120,280);
	glEnd();

	glBegin(GL_POLYGON);		 // Draw mouth
	glColor3f(0.09,0.24,0.37);
	glVertex2i(100,160);
	glVertex2i(140,200);
	glVertex2i(120,164);
	glVertex2i(100,160);
	glEnd();
	glPopMatrix();
	glPopMatrix();

}


void animation(void)
{
	if(angle>=0 && angle<10)
		angle = angle+0.5;
	else angle = 0;
	glutPostRedisplay();
}
void Auto(void)
{
	if(Autorun<=300 && Autorun>-350)
		Autorun = Autorun-0.05;
	else Autorun = 300;
	glutPostRedisplay();
}
void settings(void)
{
	glClearColor(0.0,0.5,1.0,0.0);
	glPointSize(5.0);
	glLineWidth(1.0);
	glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
	gluOrtho2D(0.0,400.0,0.0,400.0);
}


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glPushMatrix();
	glRotatef(angle,0.0,0.0,0.0); 
	glTranslatef(0.0,0.0,0.0); 
	glTranslatef(xt,yt,0.0);			// Moving our fish 

	glBegin(GL_POLYGON);				// Draw body
	glColor3f(1.0,1.0,1.0);
	glVertex2i(40,200);
	glVertex2i(120,280);
	glVertex2i(320,200);
	glVertex2i(100,160);
	glEnd();
	
	glPushMatrix();
	glRotatef(angle,0.0,0.0,0.0); 
	glBegin(GL_POLYGON);			// Draw tail
	glColor3f(0.0,1.0,0.0);
	glVertex2i(320,200);
	glVertex2i(360,240);
	glVertex2i(340,200);
	glVertex2i(360,160);
	glVertex2i(320,200);
	glEnd();
	
	glBegin(GL_POLYGON);		 // Draw Top Fin
	glColor3f(1.0,0.0,0.0);
	glVertex2i(120,280);
	glVertex2i(140,300);
	glVertex2i(280,216);
	glVertex2i(120,280);
	glEnd();

	glBegin(GL_POLYGON);		 // Draw Mouth
	glColor3f(1.0,1.0,1.0);
	glVertex2i(100,160);
	glVertex2i(140,200);
	glVertex2i(120,164);
	glVertex2i(100,160);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	
	fish();
	
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}
void keyboard(GLubyte key, int x, int y)   // For keyboard inputs
{
	switch ( key )
	{
	case 'd':
			xt += 2.0;                  // Move 2 pixels each step
			glColor3f(0.0,1.0,0.0);
			glutPostRedisplay();
			break;

	case 'a':
			xt -= 2.0;	
			glColor3f(1.0,0.0,0.0);
			glutPostRedisplay();
			break;

	case 's':
			yt -= 2.0;
			glColor3f(0.0,0.0,0.0);
			glutPostRedisplay();
			break;

	case 'w':
			yt += 2.0;
			glColor3f(0.0,0.0,1.0);
			glutPostRedisplay();
			break;

	case 'e':
			xt += 2.0;
			yt += 2.0;
			glColor3f(1.0,0.0,1.0);
			glutPostRedisplay();
			break;

	case 'q':
			xt -= 2.0;
			yt += 2.0;
			glColor3f(0.0,1.0,1.0);
			glutPostRedisplay();
			break;
	case 'c':
			xt += 2.0;
			yt -= 2.0;
			glColor3f(1.0,0.0,1.0);
			glutPostRedisplay();
			break;
	case 'z':
			xt -= 2.0;
			yt -= 2.0;
			glColor3f(0.0,0.0,1.0);
			glutPostRedisplay();
			break;

	default:
				break;
	}
}

void main(int a,char ** b)
{
	glutInit(&a,b);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200,50);   // 200x50 Window Size
	glutInitWindowSize(500,500);
	glutCreateWindow("Machli jal ki rani hai");
	settings();
	glutDisplayFunc(Display);
	glutIdleFunc(animation);
	glutIdleFunc(Auto);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
