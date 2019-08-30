#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();
void specialKeys();

double rotate_y=0;
double rotate_x=0;
float theta = 0.0f;
double t=0.1f;
double p=0.1f;
double x=1.0;

void display() {

     const double a = t*90.0;
    //  Primeiro, limpa a tela para não pegar lixo das aplicações passadas
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Reseta as transformações
    glLoadIdentity();

    //Plano abaixo do cubo:
    glBegin(GL_QUADS);
    glColor3f(  0.0,  0.0,  0.0 );
    glBegin(GL_QUADS);
    glVertex3f(0.5f, -1,0.5f);
    glVertex3f(0.5f, -1,-0.5f);
    glVertex3f(-0.5f, -1, -0.5f);
    glVertex3f(-0.5f, -1,0.5f);
    glEnd();

    // Rotaciona quando aperta as teclas direcionais
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( theta, 1.0, 0.0, 0.0 );      // Rotação em x
    glRotatef( theta, 0.0, 1.0, 0.0 );      // Rotação em y
    glRotatef( theta, 0.0, 0.0, 0.1 );      // Rotação em z

    glTranslated(0.0,0.3,0.0);      // Muda o objeto no espaço.

    glScaled(x,x,x);        // Escala do Cubo
    x+=0.005;               // Mudança de Escala
    if(x>1.1){
        x=-1.1;
    }

//---------------------------------------- FAZER O CUBO  -------------------------------------------//



    //LADO FRONTAL - 01: lado multicolorido
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glColor3f( 1.0, 0.0, 1.0 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.1, -0.1, -0.6 );
    glVertex3f(  0.1,  0.1, -0.6 );
    glVertex3f( -0.1,  0.1, -0.6 );
    glVertex3f( -0.1, -0.1, -0.6 );
    glEnd();


    // LADO TRASEIRO - 02: lado Preto
    glBegin(GL_POLYGON);              // Começa a desenhar
    glColor3f(   0,  0, 0 );          // Cor do Plano.
    glVertex3f(  0.5, -0.5, 0.5 );    // Ponto A1.
    glVertex3f(  0.5,  0.5, 0.5 );    // Ponto A2.
    glVertex3f( -0.5,  0.5, 0.5 );    // Ponto A3.
    glVertex3f( -0.5, -0.5, 0.5 );    // Ponto A4.
    glEnd();                          // Termina o Plano 01.

    // LADO DIREITO - 03: lado roxo
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    // LADO ESQUERDO - 04: lado verde
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    // LADO SUPERIOR - 05: lado azul
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    // LADO INFERIOR - 06: lado vermelho
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    glFlush();
    glutSwapBuffers();
    theta+=1.0f;
}

//--------------------------- COMANDOs PARA VIRAR O CUBO -------------------------------

void specialKeys( int key, int x, int y ) {

    //  Seta para à direita: rotaciona em 5 Graus para a Esquerda
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

    //  Seta para à esquerda: rotaciona em 5 Graus para a Direita
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    if(key == p)
        p+=1.0;
    //  Refresh na tela e atualiza o angulo do cubo
    glutPostRedisplay();
}
//----------------------------------- ILUMINAÇÃO ----------------------------------------------
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

//---------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
    // Tamanho da Tela
    glutInitWindowSize(720,720);
    glutInitWindowPosition(10,10);

    // Glut_Double - Certifica que a tela foi limpa e começa o desenho de novo
    // Glut_RGB - Utiliza o sistema de cores RGB
    // Glut_DEPTH - Trabalho com sistemas de 3D X,Y,A,Z onde Z é o Zoom
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Trabalhar com Iluminação
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Nome de janela quando rodar a aplicação
    glutCreateWindow("Cubo_Computação_Gráfica_UERN");

    //  Habilita a profundidade
    glEnable(GL_DEPTH_TEST);

    // Chamada de Funções
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glClearColor(1,1,1,1);
    glutMainLoop();

    //------------------------------------------ ILUMINAÇÃO ------------------------------------------

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    return 0;
}
