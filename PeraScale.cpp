/*
VILLAGOMEZ CHAVEZ LUIS FERNANDO
PRACTICA #03
VS 2017
INTRUCCIONES:
Q = Arriba en y
E = Abajo en y
W = Hacia dentro
S = Hacia Afuera
A = Izquierda
D = Derecha
*/



#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
float fruto[3] = { 0.8, 0.7, 0.008 };
float hoja[3] = { 0.3, 0.2, 0.1 };
float tallo[3] = { 0.07, 0.3, 0.2 };



void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prismaPera(void)
{
	GLfloat vertice[8][3] = {
				{0.5,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBegin(GL_POLYGON);	//Front
	glColor3fv(fruto);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3fv(hoja);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3fv(fruto);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3fv(hoja);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3fv(tallo);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3fv(tallo);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}



void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glScalef(1.0, 5.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(1.0, 6.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(2.0f, 0.0f, 0.0f);
	glScalef(1.0, 8.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(3.0f, 0.0f, 0.0f);
	glScalef(1.0, 9.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();	

	
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(4.0f, 1.0f, 0.0f);
	glScalef(1.0, 8.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(5.0f, 0.0f, 0.0f);
	glScalef(1.0, 9.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(6.0f, 0.0f, 0.0f);
	glScalef(1.0, 8.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(7.0f, 0.0f, 0.0f);
	glScalef(1.0, 6.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(8.0f, 0.0f, 0.0f);
	glScalef(1.0, 5.0, 1.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(4.0f, 1.0f, -0.5f);
	glScalef(1.0, 11.0, 1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(3.0f, 6.0f, 0.0f);
	glScalef(1.0, 1.0, 1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(2.0f, 7.0f, 0.0f);
	glScalef(1.0, 1.0, 1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(5.0f, 5.0f, -0.5f);
	glScalef(1.0, 2.0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(6.0f, 6.0f, -0.5f);
	glScalef(1.0, 2.0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(7.0f, 6.0f, -0.5f);
	glScalef(1.0, 3.0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(8.0f, 6.5f, -0.5f);
	glScalef(1.0, 2.0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	prismaPera();
	glLoadIdentity();

	glutSwapBuffers();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	/*case 'Z':
	case 'z':
		X -= 0.2f;
		printf("DECREMENTA %f\n", X);
		break;
	case 'X':
	case 'x':
		X += 0.2f;
		printf("INCREMENTA %f\n", X);
		break;
		*/
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transY -= 0.2f;
		printf("Posicion en Z: %f\n", transY);
		break;
	case 'e':
	case 'E':
		transY += 0.2f;
		printf("Posicion en Z: %f\n", transY);
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}