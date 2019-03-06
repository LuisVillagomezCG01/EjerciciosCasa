/*
VILLAGOMEZ CHAVEZ LUIS FERNANDO
PRACTICA #04
VS 2017
INTRUCCIONES:
Q = Arriba en Y
E = Abajo en Y
W = Hacia dentro
S = Hacia Afuera
A = Izquierda
D = Derecha
Flecha arriba = rota en angulo X positivo
Flecha abajo = rota en angulo X negativo
Flecha derecha = rota en angulo Y positivo
Flecha izquierda= rota en angulo Y negativo
*/

#include <GL/glut.h>

float transZ = -10.0f;
float transX = 0.0f;
float transY = 0.0f;

float angleX = 0.0f;
float angleY = 0.0f;

float blanco[3] = { 1.0, 1.0, 1.0 };
float rosa[3] = { 1.0, 0.0, 1.0 };
float azul[3] = { 0.0, 0.0, 1.0 };
float rojo[3] = { 1.0, 0.0, 0.0 };
float verde[3] = { 0.0, 1.0, 0.0 };
float cafe[3] = { 0.5, 0.2, 0.0 };
float amarillo[3] = { 1.0, 1.0, 0.0 };

void inicializar(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//función para dibujar un cubo a partir de polígonos
void prisma(void)
{
	GLfloat vertice[8][3] = {
	 { 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON); //Enfrente
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON); //Derecha
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON); //Atrás
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Izquierda
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Abajo
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Arriba
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}


void dibujar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	//CABEZA
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 5.0f, 0.0f);
	glColor3fv(blanco);
	glScalef(1.0f, 1.0f, 1.0f);
	prisma();

	//CUELLO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 4.25f, 0.0f);
	glColor3fv(rosa);
	glScalef(0.7f, 0.5f, 0.5f);
	prisma();

	//TORZO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 2.8f, 0.0f);
	glColor3fv(azul);
	glScalef(2.5f, 2.5f, 2.5f);
	prisma();
	
	//HOMBRO DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(1.55f, 3.7f, 0.0f);
	glColor3fv(verde);
	glScalef(0.7f, 0.7f, 0.7f);
	prisma();

	//BICEP DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(2.65f, 3.7f, 0.0f);
	glColor3fv(amarillo);
	glScalef(1.5f, 0.7f, 0.7f);
	prisma();

	//ANTEBRAZO DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(4.15f, 3.7f, 0.0f);
	glColor3fv(rojo);
	glScalef(1.5f, 0.7f, 0.7f);
	prisma();

	//MANO DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(5.0f, 3.7f, 0.0f);
	glColor3fv(blanco);
	glScalef(0.3f, 0.7f, 0.5f);
	prisma();

	//HOMBRO IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-1.55f, 3.7f, 0.0f);
	glColor3fv(verde);
	glScalef(0.7f, 0.7f, 0.7f);
	prisma();

	//BICEP IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-2.65f, 3.7f, 0.0f);
	glColor3fv(amarillo);
	glScalef(1.5f, 0.7f, 0.7f);
	prisma();

	//ANTEBRAZO IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-4.15f, 3.7f, 0.0f);
	glColor3fv(rojo);
	glScalef(1.5f, 0.7f, 0.7f);
	prisma();

	//MANO IZQUIERDA
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-5.0f, 3.7f, 0.0f);
	glColor3fv(blanco);
	glScalef(0.3f, 0.7f, 0.5f);
	prisma();


	//PIERNA DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.75f, 0.9f, 0.0f);
	glColor3fv(rojo);
	glScalef(1.0f, 1.3f, 1.5f);
	prisma();

	//RODILLA DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.75f, 0.0f, 0.0f);
	glColor3fv(verde);
	glScalef(1.0f, 0.5f, 1.5f);
	prisma();

	//PANTORRILLA DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.75f, -0.9f, 0.0f);
	glColor3fv(azul);
	glScalef(1.0f, 1.3f, 1.5f);
	prisma();

	//PIE DERECHO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(1.0f, -1.7f, 0.0f);
	glColor3fv(cafe);
	glScalef(1.5f, 0.5f, 1.5f);
	prisma();

	//PIERNA IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-0.75f, 0.9f, 0.0f);
	glColor3fv(rojo);
	glScalef(-1.0f, 1.3f, 1.5f);
	prisma();

	//RODILLA IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-0.75f, 0.0f, 0.0f);
	glColor3fv(verde);
	glScalef(1.0f, 0.5f, 1.5f);
	prisma();

	//PANTORRILLA IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-0.75f, -0.9f, 0.0f);
	glColor3fv(azul);
	glScalef(1.0f, 1.3f, 1.5f);
	prisma();

	//PIE IZQUIERDO
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(-1.0f, -1.7f, 0.0f);
	glColor3fv(cafe);
	glScalef(1.5f, 0.5f, 1.5f);
	prisma();

	glFlush();
}

void remodelar(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, width, height);    //definir ventana (ancho, altura)
	glMatrixMode(GL_PROJECTION);        // guarda vista de como se ve la camara
	glLoadIdentity();

	// tipo de vista
	//glOrtho(-5,5,-5,5,0.1,20);
	glFrustum(-5, 5, -5, 5, 4.0, 20.0);
	glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'w':case'W':  //acerca al objeto con traslación en Z pos
		transZ += 0.2f;
		break;

	case's':case'S':  //aleja al objeto con traslación en Z neg
		transZ -= 0.2f;
		break;

	case'a':case'A':  //traslada al objeto hacia la derecha en X pos
		transX += 0.2f;
		break;

	case'd':case'D':  //traslada al objeto hacia la izquierda en X neg
		transX -= 0.2f;
		break;

	case'q':case'Q':  //traslada al objeto hacia arriba en Y pos
		transY -= 0.2f;
		break;

	case'e':case'E':  //traslada al objeto hacia abajo en Y neg
		transY += 0.2f;
		break;

	case 27:    //Si presiona la tecla ESC(ASCII 27) sale
		exit(0);
		break;

	default:    //Si es cualquier otra tecla no hace nada
		break;
	}
	glutPostRedisplay();
}

void teclasFlechas(int tecla, int x, int y)
{
	switch (tecla) {
	case GLUT_KEY_UP:
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	//
	glutInit(&argc, argv);

	//
	//
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);  // banderas

				   //
	glutInitWindowSize(650, 650);

	//
	glutInitWindowPosition(550, 50);

	//
	glutCreateWindow("Batman");

	inicializar();
	//Llamada a la función a ser dibujada
	glutDisplayFunc(dibujar);
	glutReshapeFunc(remodelar);

	//Llamada a función que maneja eventos del teclado
	glutKeyboardFunc(teclado);

	glutSpecialFunc(teclasFlechas);

	//LLamada a función que cede el control a GLUT y procesa eventos de
	glutMainLoop();

	//Termina la ejecucion devolviendo cero
	return 0;
}
