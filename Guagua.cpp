/*
VILLAGOMEZ CHAVEZ LUIS FERNANDO
GRUPO:03
VS 2017

*/
#include <windows.h>
#include <Gl/glut.h>
void dibujar(void)
{
	glClearColor(0.1, 0.1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	glMatrixMode(GL_MODELVIEW);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-22.0, 22.0, -22.0, 22.0, 0.1, 2.0);

	//INICIA_NARIZ

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.7, 0.7);
		glVertex3f(-3.0f, -1.0f, -1.0f);
		glVertex3f(-3.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.7, 0.7);
		glVertex3f(-1.0f, -3.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(+1.0f, -1.0f, -1.0f);
		glVertex3f(+1.0f, -3.0f, -1.0f);
	glEnd();

	//TERMINA_NARIZ


	//INICIA_OJO_DERECHO

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(+3.0f, +3.0f, -1.0f);	
		glVertex3f(+3.0f, +6.0f, -1.0f);	
		glVertex3f(+5.0f, +6.0f, -1.0f);	
		glVertex3f(+5.0f, +3.0f, -1.0f);	
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(+4.5f, +4.0f, -1.0f);
		glVertex3f(+4.5f, +5.0f, -1.0f);
		glVertex3f(+3.5f, +5.0f, -1.0f);
		glVertex3f(+3.5f, +4.0f, -1.0f);
	glEnd();

	//TERMINA_OJO_DERECHO


	//INICIA_OJO_IZQUIERDO

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-5.0f, +3.0f, -1.0f);
		glVertex3f(-5.0f, +6.0f, -1.0f);	
		glVertex3f(-3.0f, +6.0f, -1.0f);	
		glVertex3f(-3.0f, +3.0f, -1.0f);	
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-4.5f, +4.0f, -1.0f);	
		glVertex3f(-4.5f, +5.0f, -1.0f);
		glVertex3f(-3.5f, +5.0f, -1.0f);
		glVertex3f(-3.5f, +4.0f, -1.0f);
	glEnd();

	//TERMINA_OJO_IZQUIERDO


	//INICIA_HOCICO_CARA

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-9.0f, -3.0f, -1.0f);
		glVertex3f(-9.0f, +8.0f, -1.0f);
		glVertex3f(-7.0f, +8.0f, -1.0f);
		glVertex3f(-7.0f, -3.0f, -1.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-7.0f, -5.0f, -1.0f);
		glVertex3f(-7.0f, -3.0f, -1.0f);
		glVertex3f(-5.0f, -3.0f, -1.0f);
		glVertex3f(-5.0f, -5.0f, -1.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-5.0f, -7.0f, -1.0f);
		glVertex3f(-5.0f, -5.0f, -1.0f);
		glVertex3f(+5.0f, -5.0f, -1.0f);
		glVertex3f(+5.0f, -7.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+5.0f, -5.0f, -1.0f);
		glVertex3f(+5.0f, -3.0f, -1.0f);
		glVertex3f(+7.0f, -3.0f, -1.0f);
		glVertex3f(+7.0f, -5.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+7.0f, -3.0f, -1.0f);
		glVertex3f(+7.0f, +8.0f, -1.0f);
		glVertex3f(+9.0f, +8.0f, -1.0f);
		glVertex3f(+9.0f, -3.0f, -1.0f);
	glEnd();

	//TERMINA_HOCICO_CARA


	//INICIA_LENGUA
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(+1.0f, -10.0f, -1.0f);
		glVertex3f(+1.0f, -7.0f, -1.0f);
		glVertex3f(+3.0f, -7.0f, -1.0f);
		glVertex3f(+3.0f, -10.0f, -1.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(+2.0f, -7.0f, -1.0f);
		glVertex3f(+2.0f, -9.0f, -1.0f);
	glEnd();
	
	//TERMINA_LENGUA


	//INICIA_OREJA_IZQUIERDA

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-11.0f, +4.0f, -1.0f);
		glVertex3f(-11.0f, +6.0f, -1.0f);
		glVertex3f(-9.0f, +6.0f, -1.0f);
		glVertex3f(-9.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-14.0f, +2.0f, -1.0f);
		glVertex3f(-14.0f, +4.0f, -1.0f);
		glVertex3f(-11.0f, +4.0f, -1.0f);
		glVertex3f(-11.0f, +2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-14.0f, +4.0f, -1.0f);
		glVertex3f(-14.0f, +10.0f, -1.0f);
		glVertex3f(-12.0f, +10.0f, -1.0f);
		glVertex3f(-12.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-12.0f, +10.0f, -1.0f);
		glVertex3f(-12.0f, +12.0f, -1.0f);
		glVertex3f(-10.0f, +12.0f, -1.0f);
		glVertex3f(-10.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-10.0f, +12.0f, -1.0f);
		glVertex3f(-10.0f, +14.0f, -1.0f);
		glVertex3f(-8.0f, +14.0f, -1.0f);
		glVertex3f(-8.0f, +12.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-8.0f, +10.0f, -1.0f);
		glVertex3f(-8.0f, +12.0f, -1.0f);
		glVertex3f(-6.0f, +12.0f, -1.0f);
		glVertex3f(-6.0f, +10.0f, -1.0f);
	glEnd();

	//TERMINA_OREJA_IZQUIERDA


	//INICIA_OREJA_DERECHA

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+11.0f, +4.0f, -1.0f);
		glVertex3f(+11.0f, +6.0f, -1.0f);
		glVertex3f(+9.0f, +6.0f, -1.0f);
		glVertex3f(+9.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+14.0f, +2.0f, -1.0f);
		glVertex3f(+14.0f, +4.0f, -1.0f);
		glVertex3f(+11.0f, +4.0f, -1.0f);
		glVertex3f(+11.0f, +2.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+14.0f, +4.0f, -1.0f);
		glVertex3f(+14.0f, +10.0f, -1.0f);
		glVertex3f(+12.0f, +10.0f, -1.0f);
		glVertex3f(+12.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+12.0f, +10.0f, -1.0f);
		glVertex3f(+12.0f, +12.0f, -1.0f);
		glVertex3f(+10.0f, +12.0f, -1.0f);
		glVertex3f(+10.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+10.0f, +12.0f, -1.0f);
		glVertex3f(+10.0f, +14.0f, -1.0f);
		glVertex3f(+8.0f, +14.0f, -1.0f);
		glVertex3f(+8.0f, +12.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(+8.0f, +10.0f, -1.0f);
		glVertex3f(+8.0f, +12.0f, -1.0f);
		glVertex3f(+6.0f, +12.0f, -1.0f);
		glVertex3f(+6.0f, +10.0f, -1.0f);
	glEnd();

	//TERMINA_OREJA_DERECHA


	//INICIA_NUCA

	glBegin(GL_QUADS);
	glColor3f(0.3, 0.15, 0.15);
		glVertex3f(-6.0f, +12.0f, -1.0f);
		glVertex3f(-6.0f, +14.0f, -1.0f);
		glVertex3f(+6.0f, +14.0f, -1.0f);
		glVertex3f(+6.0f, +12.0f, -1.0f);
	glEnd();

	//TERMINA_NUCA


	//INICIA_MANCHA

	glBegin(GL_QUADS);
	glColor3f(0.463, 0.235, 0.157);
		glVertex3f(-7.0f, +1.0f, -1.0f);
		glVertex3f(-7.0f, +8.0f, -1.0f);
		glVertex3f(-5.0f, +8.0f, -1.0f);
		glVertex3f(-5.0f, +1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.463, 0.235, 0.157);
		glVertex3f(-5.0f, +6.0f, -1.0f);
		glVertex3f(-5.0f, +8.0f, -1.0f);
		glVertex3f(-1.0f, +8.0f, -1.0f);
		glVertex3f(-1.0f, +6.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.463, 0.235, 0.157);
		glVertex3f(-3.0f, +3.0f, -1.0f);
		glVertex3f(-3.0f, +6.0f, -1.0f);
		glVertex3f(-1.0f, +6.0f, -1.0f);
		glVertex3f(-1.0f, +3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.463, 0.235, 0.157);
		glVertex3f(-5.0f, +3.0f, -1.0f);
		glVertex3f(-5.0f, +1.0f, -1.0f);
		glVertex3f(-1.0f, +1.0f, -1.0f);
		glVertex3f(-1.0f, +3.0f, -1.0f);
	glEnd();
	//TERMINA _MANCHA

	//INICIA_PELO_NUCA&OREJAS

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(-6.0f, +10.0f, -1.0f);
		glVertex3f(-6.0f, +12.0f, -1.0f);
		glVertex3f(+0.0f, +12.0f, -1.0f);
		glVertex3f(+0.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(-10.0f, +10.0f, -1.0f);
		glVertex3f(-10.0f, +12.0f, -1.0f);
		glVertex3f(-8.0f, +12.0f, -1.0f);
		glVertex3f(-8.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(-12.0f, +8.0f, -1.0f);
		glVertex3f(-12.0f, +10.0f, -1.0f);
		glVertex3f(+0.0f, +10.0f, -1.0f);
		glVertex3f(+0.0f, +8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(-12.0f, +4.0f, -1.0f);
		glVertex3f(-12.0f, +8.0f, -1.0f);
		glVertex3f(-11.0f, +8.0f, -1.0f);
		glVertex3f(-11.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-11.0f, +6.0f, -1.0f);
		glVertex3f(-11.0f, +8.0f, -1.0f);
		glVertex3f(-9.0f, +8.0f, -1.0f);
		glVertex3f(-9.0f, +6.0f, -1.0f);
	glEnd();

	//PELO_DERECHO
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(+6.0f, +10.0f, -1.0f);
		glVertex3f(+6.0f, +12.0f, -1.0f);
		glVertex3f(+0.0f, +12.0f, -1.0f);
		glVertex3f(+0.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(+10.0f, +10.0f, -1.0f);
		glVertex3f(+10.0f, +12.0f, -1.0f);
		glVertex3f(+8.0f, +12.0f, -1.0f);
		glVertex3f(+8.0f, +10.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(+12.0f, +8.0f, -1.0f);
		glVertex3f(+12.0f, +10.0f, -1.0f);
		glVertex3f(+0.0f, +10.0f, -1.0f);
		glVertex3f(+0.0f, +8.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4, 0.15, 0.05);
		glVertex3f(+12.0f, +4.0f, -1.0f);
		glVertex3f(+12.0f, +8.0f, -1.0f);
		glVertex3f(+11.0f, +8.0f, -1.0f);
		glVertex3f(+11.0f, +4.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
		glVertex3f(+11.0f, +6.0f, -1.0f);
		glVertex3f(+11.0f, +8.0f, -1.0f);
		glVertex3f(+9.0f, +8.0f, -1.0f);
		glVertex3f(+9.0f, +6.0f, -1.0f);
	glEnd();

	//PELO_DERECHO
	//TERMINA_PELO


	//INICIA_PELO_CARA

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(-1.0f, +1.0f, -1.0f);
		glVertex3f(-1.0f, +8.0f, -1.0f);
		glVertex3f(+3.0f, +8.0f, -1.0f);
		glVertex3f(+3.0f, +1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+7.0f, +6.0f, -1.0f);
		glVertex3f(+7.0f, +8.0f, -1.0f);
		glVertex3f(+3.0f, +8.0f, -1.0f);
		glVertex3f(+3.0f, +6.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+5.0f, +3.0f, -1.0f);
		glVertex3f(+5.0f, +6.0f, -1.0f);
		glVertex3f(+7.0f, +6.0f, -1.0f);
		glVertex3f(+7.0f, +3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+7.0f, +3.0f, -1.0f);
		glVertex3f(+7.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, +3.0f, -1.0f);
	glEnd();

	//TERMINA_PELO_CARA
	
	
	//INICA_PELO_HOCICO_DERECHO

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(-7.0f, -1.0f, -1.0f);
		glVertex3f(-7.0f, +1.0f, -1.0f);
		glVertex3f(-3.0f, +1.0f, -1.0f);
		glVertex3f(-3.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(-7.0f, -3.0f, -1.0f);
		glVertex3f(-7.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(-5.0f, -5.0f, -1.0f);
		glVertex3f(-5.0f, -3.0f, -1.0f);
		glVertex3f(+0.0f, -3.0f, -1.0f);
		glVertex3f(+0.0f, -5.0f, -1.0f);
	glEnd();

	//LADO_DERECHO
	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+7.0f, -1.0f, -1.0f);
		glVertex3f(+7.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, +1.0f, -1.0f);
		glVertex3f(+3.0f, -1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+7.0f, -3.0f, -1.0f);
		glVertex3f(+7.0f, -1.0f, -1.0f);
		glVertex3f(+1.0f, -1.0f, -1.0f);
		glVertex3f(+1.0f, -3.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.584, 0.373, 0.125);
		glVertex3f(+5.0f, -5.0f, -1.0f);
		glVertex3f(+5.0f, -3.0f, -1.0f);
		glVertex3f(+0.0f, -3.0f, -1.0f);
		glVertex3f(+0.0f, -5.0f, -1.0f);
	glEnd();

	//TERMINA_PELO_HOCICO
	
	glFlush();

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ARF_ARF");
	glutDisplayFunc(dibujar);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(teclado);
	glutMainLoop();
	return 0;
}
