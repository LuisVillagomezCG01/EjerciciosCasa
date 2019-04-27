/*
VILLAGOMEZ CHAVEZ LUIS FERNANDO
PRACTICA #11
VS 2017
INTRUCCIONES:
W = Hacia dentro
S = Hacia Afuera
A = Izquierda
D = Derecha
Flecha arriba = rota en angulo X positivo
Flecha abajo = rota en angulo X negativo
Flecha derecha = rota en angulo Y positivo
Flecha izquierda= rota en angulo Y negativo
R ó r = rotación en codo
T ó t = rotación en muñeca
Y ó y = rotación en dedo pulgar
U ó u = rotación en dedo indice
I ó i = rotación en dedo medio
O ó o = rotación en dedo anular
P ó p = rotación en dedo meñique
K = Guarda el estado del KeyFrame
L = Activa la animación
*/

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0f;
float angMuñeca = 0.0f;
float angDpulgar = 0.0f;
float angDindice = 0.0f;
float angDmedio = 0.0f;
float angDanular = 0.0f;
float angDmeñique = 0.0f;


char caracter[20];

#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{

	float angDpulgar = 0.0f;
	float angDindice = 0.0f;
	float angDmedio = 0.0f;
	float angDanular = 0.0f;
	float angDmeñique = 0.0f;

	float IncAngDpulgar = 0.0f;
	float IncAngDindice = 0.0f;
	float IncAngDmedio = 0.0f;
	float IncAngDanular = 0.0f;
	float IncAngDmeñique = 0.0f;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void saveFrame(void)
{
	printf("frameindex = %d\n", FrameIndex);

	KeyFrame[FrameIndex].angDpulgar = angDpulgar;
	KeyFrame[FrameIndex].angDindice = angDindice;
	KeyFrame[FrameIndex].angDmedio = angDmedio;
	KeyFrame[FrameIndex].angDanular = angDanular;
	KeyFrame[FrameIndex].angDmeñique = angDmeñique;

	printf("angDpulgar = %g\n", KeyFrame[FrameIndex].angDpulgar);
	printf("angDindice = %g\n", KeyFrame[FrameIndex].angDindice);
	printf("angDmedio = %g\n", KeyFrame[FrameIndex].angDmedio);
	printf("angDanular = %g\n", KeyFrame[FrameIndex].angDanular);
	printf("angDmeñique = %g\n", KeyFrame[FrameIndex].angDmeñique);


	FrameIndex++;
}

void resetElements(void)
{
	angDpulgar = KeyFrame[0].angDpulgar;
	angDindice = KeyFrame[0].angDindice;
	angDmedio = KeyFrame[0].angDmedio;
	angDanular = KeyFrame[0].angDanular;
	angDmeñique = KeyFrame[0].angDmeñique;


}

void interpolation(void)
{
	KeyFrame[playIndex].IncAngDmeñique = (KeyFrame[playIndex + 1].angDpulgar - KeyFrame[playIndex].angDpulgar) / i_max_steps;
	KeyFrame[playIndex].IncAngDindice = (KeyFrame[playIndex + 1].angDindice - KeyFrame[playIndex].angDindice) / i_max_steps;
	KeyFrame[playIndex].IncAngDmedio = (KeyFrame[playIndex + 1].angDmedio - KeyFrame[playIndex].angDmedio) / i_max_steps;
	KeyFrame[playIndex].IncAngDanular = (KeyFrame[playIndex + 1].angDanular - KeyFrame[playIndex].angDanular) / i_max_steps;
	KeyFrame[playIndex].IncAngDmeñique = (KeyFrame[playIndex + 1].angDmeñique - KeyFrame[playIndex].angDmeñique) / i_max_steps;

}


void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	for (int i = 0; i < MAX_FRAMES; i++)
	{
		
		KeyFrame[i].angDpulgar = 0.0f;
		KeyFrame[i].angDindice = 0.0f;
		KeyFrame[i].angDmedio = 0.0f;
		KeyFrame[i].angDanular = 0.0f;
		KeyFrame[i].angDmeñique = 0.0f;

		KeyFrame[i].IncAngDpulgar = 0.0f;
		KeyFrame[i].IncAngDindice = 0.0f;
		KeyFrame[i].IncAngDmedio = 0.0f;
		KeyFrame[i].IncAngDanular = 0.0f;
		KeyFrame[i].IncAngDmeñique = 0.0f;
	}

}
/*
void GuardaFrame()
{
	FILE *fp;

	fp = fopen("Frames.txt", "w");

	if ((fp) == NULL)
	{
		printf("Error al abrir el archivo");
		exit(1);
	}
	else
	{
		while (!feof(fp))
		{
			fputs(caracter, fp);
		}
	}

	fclose(fp);

}
*/
void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.


	glPushMatrix();//inicio

	//BRAZO
	glPushMatrix();//inicioBrazo

	//Hombro
	glPushMatrix();//inicioHombro
		glColor3f(1.0f, 1.0f, 0.0f);
		glScalef(1.0F, 1.0F, 1.0F);
		prisma();
	glPopMatrix();//terminoHombro

	glTranslatef(1.5f, 0.0f, 0.0f);

	//Bicep
	glPushMatrix();//inicioBicep
		glColor3f(0.0f, 1.0f, 0.0f);
		glScalef(2.0F, 1.0F, 1.0F);
		prisma();
	glPopMatrix();//terminoBicep

	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(angCodo, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.0f, 0.0f, 0.0f);

	//ANTEBRAZO
	glPushMatrix();//inicioAntebrazo
		glColor3f(1.0f, 0.0f, 0.0f);
		glScalef(2.0f, 1.0f, 1.0f);
		prisma();
	glPopMatrix();//terminoAntebrazo

	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(angMuñeca, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.5f, 0.0f, 0.0f);

	//Palma
	glPushMatrix();//iniciaPalma
		glColor3f(0.0f, 0.0f, 1.0f);
		glScalef(1.0f, 1.0f, 0.5f);
		prisma();
	glPopMatrix();//terminaPalma

	
	//pulgar
	glPushMatrix();//INICIA_PULGAR

	glTranslatef(-0.4f, 0.5f, 0);
	glRotatef(angDpulgar, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.1f, 0.0f);

	//falange1Inicia
	glPushMatrix();
		glColor3f(1.0f, 0.0f, 1.0f);
		glScalef(0.2f, 0.2f, 0.5f);
		prisma();
	glPopMatrix();

	glTranslatef(0.0f, 0.1f, 0.0f);
	glRotatef(angDpulgar*0.3f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.1f, 0.0f);

	//falange2Inicia
	glPushMatrix();
		glColor3f(0.0f, 0.5f, 0.1f);
		glScalef(0.2f, 0.2f, 0.5f);
		prisma();
	glPopMatrix();

	glPopMatrix();//TERMINA_PULGAR
	
	//indice
	glPushMatrix();//INDICE

	glTranslatef(0.5f, 0.45f, 0.0f);
	glRotatef(angDindice, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.5f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.15f, 0.0f, 0.0f);
	glRotatef(angDindice*0.3f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.4f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.15f, 0.0f, 0.0f);
	glRotatef(angDindice*0.3f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();

	glPopMatrix();//finalINDICE


	//MEDIO
	glPushMatrix();//INICIA_MEDIA

	glTranslatef(0.55f, 0.15f, 0.0f);
	glRotatef(angDmedio, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.5f, 0.1f);
	glScalef(0.4f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.25f, 0.0f, 0.0f);
	glRotatef(angDmedio*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.4f, 0.1f);
	glScalef(0.4f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.25f, 0.0f, 0.0f);
	glRotatef(angDmedio*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.1f);
	glScalef(0.4f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();

	glPopMatrix();//FINAL_MEDIO


	//ANULAR
	glPushMatrix();//INICIA_ANULAR

	glTranslatef(0.5f, -0.15f, 0.0f);
	glRotatef(angDanular, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.5f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.15f, 0.0f, 0.0f);
	glRotatef(angDanular*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.4f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.15f, 0.0f, 0.0f);
	glRotatef(angDanular*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.3f, 0.3f, 0.1f);
	glScalef(0.3f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();

	glPopMatrix();//FINAL_ANULAR


	//MEÑIQUE
	glPushMatrix();//INICIA_MEÑIQUE

	glTranslatef(0.45f, -0.45f, 0.0f);
	glRotatef(angDmeñique, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.5f, 0.1f);
	glScalef(0.2f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.05f, 0.0f, 0.0f);
	glRotatef(angDmeñique*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.4f, 0.1f);
	glScalef(0.2f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glTranslatef(0.05f, 0.0f, 0.0f);
	glRotatef(angDmeñique*0.3, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.15f, 0.0f, 0.0f);

	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.1f);
	glScalef(0.2f, 0.1f, 0.2f);
	prisma();
	glPopMatrix();


	glPopMatrix();//FINAL_MEÑIQUE

	glPopMatrix();//palma
	


	glPopMatrix();//final

	glutSwapBuffers();
	// Swap The Buffers
}

void animacion()
{
	//Movimiento del monito
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)
				//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			angDpulgar = KeyFrame[playIndex].angDpulgar;
			angDindice = KeyFrame[playIndex].angDindice;
			angDmedio = KeyFrame[playIndex].angDmedio;
			angDanular = KeyFrame[playIndex].angDanular;
			angDmeñique = KeyFrame[playIndex].angDmeñique;
			i_curr_steps++;
		}
	}


	glutPostRedisplay();
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

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;


	case 'r':
		if (angCodo <= 130)
			angCodo += 2.0f;

		break;
	case 'R':
		if (angCodo >= 0)
			angCodo -= 2.0f;

		break;

	case 't':
		if (angMuñeca <= 85)
			angMuñeca += 2.0f;

		break;
	case 'T':
		if (angMuñeca >= -30)
			angMuñeca -= 2.0f;

		break;

	case 'y':
		//printf("angDpulgar%d\n", angDpulgar);
		if (angDpulgar >= -90)
			angDpulgar -= 2.0f;
		break;
	case 'Y':
		//printf("angDpulgar%d\n", angDpulgar);
		if (angDpulgar <= 0)
			angDpulgar += 2.0f;
		break;

	case 'u':
		//printf("angDindice%d\n", angDindice);
		if (angDindice <= 90)
			angDindice += 2.0f;
		break;
	case 'U':
		//printf("angDindice%d\n", angDindice);
		if (angDindice >= 0)
			angDindice -= 2.0f;
		break;

	case 'i':
		//printf("angDmedio%d\n", angDmedio);
		if (angDmedio <= 90)
			angDmedio += 2.0f;
		break;
	case 'I':
		//printf("angDmedio%d\n", angDmedio);
		if (angDmedio >= 0)
			angDmedio -= 2.0f;
		break;

	case 'o':
		//printf("angDanular%d\n", angDanular);
		if (angDanular <= 90)
			angDanular += 2.0f;
		break;
	case 'O':
		//printf("angDanular%d\n", angDanular);
		if (angDanular >= 0)
			angDanular -= 2.0f;
		break;

	case 'p':
		//printf("angDmeñique %d\n", angDmeñique);
		if (angDmeñique <= 90)
			angDmeñique += 2.0f;
		break;
	case 'P':
		//printf("angDmeñique%d\n", angDmeñique);
		if (angDmeñique >= 0)
			angDmeñique -= 2.0f;
		break;

	case 'k':
		//
	case 'K':
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}

		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex > 1))
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;

			
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}


void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
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


void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:  //Save KeyFrame
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:  //Play animation
		if (play == false && FrameIndex > 1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 11"); // Nombre de la Ventana
	//printf("Resolution H: %i \n", screenW);
	//printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}