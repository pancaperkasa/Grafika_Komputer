#include<windows.h>
#include <GL/glut.h>>
#include <iostream>
#include <iostream>
using namespace std;

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("PANCA RIZKI PERKASA - 672019023");
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
    glClearColor(0.75, 0.75, 0.75, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();


    //atap
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(-80, 20.0, 85.0);
    glVertex3f(-14, 20.0, 85.0);
    glVertex3f(-14, 40.0, 20.0);
    glVertex3f(-80, 40.0, 20.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(-80, 20.0, -75.0);
    glVertex3f(-14, 20.0, -75.0);
    glVertex3f(-14, 40.0, 20.0);
    glVertex3f(-80, 40.0, 20.0);
    glEnd();
    //kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-80, 20.0, 85.0);
    glVertex3f(-80, 40.0, 20.0);
    glVertex3f(-80, 20.0, -75.0);
    glEnd();
    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14, 20.0, 85.0);
    glVertex3f(-14, 40.0, 20.0);
    glVertex3f(-14, 20.0, -75.0);
    glEnd();
    //kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(-14, 20.0, -75.0);
    glVertex3f(10, 20.0, -75.0);
    glVertex3f(10, 40.0, 20.0);
    glVertex3f(-14, 40.0, 20.0);
    glEnd();
    //tutupnya
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14, 20.0, 20.0);
    glVertex3f(10, 20.0, 20.0);
    glVertex3f(10, 40.0, 20.0);
    glVertex3f(-14, 40.0, 20.0);
    glEnd();
    //sisinya 
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10, 20.0, -35.0);
    glVertex3f(10, 29.0, -35.0);
    glVertex3f(10, 20.0, -75.0);
    glEnd();

    //tembok depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(-80.0, -10.0, 75.0);
    glVertex3f(-80.0, 20.0, 75.0);
    glVertex3f(-13.0, 20.0, 75.0);
    glVertex3f(-13.0, -10.0, 75.0);
    glEnd();
    //taman
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.0);
    glVertex3f(-80, -10.0, 75.0);
    glVertex3f(10, -10.0, 75.0);
    glVertex3f(10, -10.0, 130.0);
    glVertex3f(-80, -10.0, 130.0);
    glEnd();
    //pagar kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-80, -10.0, 75.0);
    glVertex3f(-80, 10.0, 75.0);
    glVertex3f(-80, 10.0, 130.0);
    glVertex3f(-80, -10.0, 130.0);
    glEnd();
    //pagar kanan 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(80, -10.0, 75.0);
    glVertex3f(80, 10.0, 75.0);
    glVertex3f(80, 10.0, 100.0);
    glVertex3f(80, -10.0, 100.0);
    glEnd();
    //pagar kanan 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(80, -10.0, 100.0);
    glVertex3f(80, 0.0, 100.0);
    glVertex3f(80, 0.0, 130.0);
    glVertex3f(80, -10.0, 130.0);
    glEnd();
    //pagar depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-80, -10.0, 130.0);
    glVertex3f(-80, 5.0, 130.0);
    glVertex3f(10, 5.0, 130.0);
    glVertex3f(10, -10.0, 130.0);
    glEnd();
    //jendela kiri
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(-70.0, 0.0, 75.1);
    glVertex3f(-70.0, 10.0, 75.1);
    glVertex3f(-60.0, 10.0, 75.1);
    glVertex3f(-60.0, 0.0, 75.1);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-70.0, 10.0, 75.1);
    glVertex3f(-70.0, 11.0, 75.1);
    glVertex3f(-60.0, 11.0, 75.1);
    glVertex3f(-60.0, 10.0, 75.1);
    //2
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-70.0, -1.0, 75.1);
    glVertex3f(-70.0, 0.0, 75.1);
    glVertex3f(-60.0, 0.0, 75.1);
    glVertex3f(-60.0, -1.0, 75.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-60.0, -1.0, 75.1);
    glVertex3f(-60.0, 11.0, 75.1);
    glVertex3f(-59.0, 11.0, 75.1);
    glVertex3f(-59.0, -1.0, 75.1);
    //2
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-65.5, -1.0, 75.2);
    glVertex3f(-65.5, 11.0, 75.2);
    glVertex3f(-64.5, 11.0, 75.2);
    glVertex3f(-64.5, -1.0, 75.2);
    //3
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-71.0, -1.0, 75.1);
    glVertex3f(-71.0, 11.0, 75.1);
    glVertex3f(-70.0, 11.0, 75.1);
    glVertex3f(-70.0, -1.0, 75.1);
    glEnd();
    //jendela 2
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(-30.0, 0.0, 75.1);
    glVertex3f(-30.0, 10.0, 75.1);
    glVertex3f(-20.0, 10.0, 75.1);
    glVertex3f(-20.0, 0.0, 75.1);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-30.0, 10.0, 75.1);
    glVertex3f(-30.0, 11.0, 75.1);
    glVertex3f(-20.0, 11.0, 75.1);
    glVertex3f(-20.0, 10.0, 75.1);
    //2
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-30.0, -1.0, 75.1);
    glVertex3f(-30.0, 0.0, 75.1);
    glVertex3f(-20.0, 0.0, 75.1);
    glVertex3f(-20.0, -1.0, 75.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-20.0, -1.0, 75.1);
    glVertex3f(-20.0, 11.0, 75.1);
    glVertex3f(-19.0, 11.0, 75.1);
    glVertex3f(-19.0, -1.0, 75.1);
    //2
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-25.5, -1.0, 75.2);
    glVertex3f(-25.5, 11.0, 75.2);
    glVertex3f(-24.5, 11.0, 75.2);
    glVertex3f(-24.5, -1.0, 75.2);
    //3
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-31.0, -1.0, 75.1);
    glVertex3f(-31.0, 11.0, 75.1);
    glVertex3f(-30.0, 11.0, 75.1);
    glVertex3f(-30.0, -1.0, 75.1);
    glEnd();

    //meja
        //alas
    glBegin(GL_QUADS);
    glColor3f(0.8, 1.0, 0.7);
    glVertex3f(-4, -4.0, 55.0);
    glVertex3f(8, -4.0, 55.0);
    glVertex3f(8, -4.0, 45.0);
    glVertex3f(-4, -4.0, 45.0);
    glEnd();
    //kaki kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.4, 0.0);
    glVertex3f(-2, -10.0, 55.0);
    glVertex3f(-2, -4.0, 55.0);
    glVertex3f(-2, -4.0, 45.0);
    glVertex3f(-2, -10.0, 45.0);
    glEnd();
    //kaki kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.4, 0.0);
    glVertex3f(6, -10.0, 55.0);
    glVertex3f(6, -4.0, 55.0);
    glVertex3f(6, -4.0, 45.0);
    glVertex3f(6, -10.0, 45.0);
    glEnd();


    //kursi 1
       //kaki depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.0);
    glVertex3f(-1, -10.0, 40.0);
    glVertex3f(-1, -4.0, 40.0);
    glVertex3f(5, -4.0, 40.0);
    glVertex3f(5, -10.0, 40.0);
    glEnd();
    //kaki belakang
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.0);
    glVertex3f(-1, -10.0, 35.0);
    glVertex3f(-1, 2.0, 35.0);
    glVertex3f(5, 2.0, 35.0);
    glVertex3f(5, -10.0, 35.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.75);
    glVertex3f(-1, -4.0, 40.0);
    glVertex3f(5, -4.0, 40.0);
    glVertex3f(5, -4.0, 35.0);
    glVertex3f(-1, -4.0, 35.0);
    glEnd();

    //lemari
        //kaki depan
    glBegin(GL_QUADS);
    glColor3f(0.35, 0.15, 1.0);
    glVertex3f(5, -10.0, 30.0);
    glVertex3f(5, 8.0, 30.0);
    glVertex3f(10, 8.0, 30.0);
    glVertex3f(10, -10.0, 30.0);
    glEnd();
    //kaki belakang
    glBegin(GL_QUADS);
    glColor3f(0.35, 0.15, 1.0);
    glVertex3f(5, -10.0, 10.0);
    glVertex3f(5, 8.0, 10.0);
    glVertex3f(10, 8.0, 10.0);
    glVertex3f(10, -10.0, 10.0);
    glEnd();
    //kaki tengah
    glBegin(GL_QUADS);
    glColor3f(0.35, 0.15, 1.0);
    glVertex3f(5, -10.0, 20.0);
    glVertex3f(5, 8.0, 20.0);
    glVertex3f(10, 8.0, 20.0);
    glVertex3f(10, -10.0, 20.0);
    glEnd();
    //tutup atas 
    glBegin(GL_QUADS);
    glColor3f(0.45, 1.0, 0.45);
    glVertex3f(5, 8.0, 30.0);
    glVertex3f(10, 8.0, 30.0);
    glVertex3f(10, 8.0, 10.0);
    glVertex3f(5, 8.0, 10.0);
    glEnd();
    //tutup bawah
    glBegin(GL_QUADS);
    glColor3f(0.45, 1.0, 0.45);
    glVertex3f(5, -9.9, 30.0);
    glVertex3f(10, -9.9, 30.0);
    glVertex3f(10, -9.9, 10.0);
    glVertex3f(5, -9.9, 10.0);
    glEnd();
    //rak atas kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.35);
    glVertex3f(5, 3.0, 30.0);
    glVertex3f(10, 3.0, 30.0);
    glVertex3f(10, 3.0, 20.0);
    glVertex3f(5, 3.0, 20.0);
    glEnd();
    //rak bawah kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.35);
    glVertex3f(5, -5.0, 30.0);
    glVertex3f(10, -5.0, 30.0);
    glVertex3f(10, -5.0, 20.0);
    glVertex3f(5, -5.0, 20.0);
    glEnd();

    //rak atas kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.35);
    glVertex3f(5, 3.0, 20.0);
    glVertex3f(10, 3.0, 20.0);
    glVertex3f(10, 3.0, 10.0);
    glVertex3f(5, 3.0, 10.0);
    glEnd();
    //rak bawah kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.35);
    glVertex3f(5, -5.0, 20.0);
    glVertex3f(10, -5.0, 20.0);
    glVertex3f(10, -5.0, 10.0);
    glVertex3f(5, -5.0, 10.0);
    glEnd();
    //kursi 2
       //kaki depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.0);
    glVertex3f(-6, -10.0, 55.0);
    glVertex3f(-6, -4.0, 55.0);
    glVertex3f(-6, -4.0, 45.0);
    glVertex3f(-6, -10.0, 45.0);
    glEnd();
    //kaki belakang
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.0, 0.0);
    glVertex3f(-10, -10.0, 55.0);
    glVertex3f(-10, 2.0, 55.0);
    glVertex3f(-10, 2.0, 45.0);
    glVertex3f(-10, -10.0, 45.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.75);
    glVertex3f(-10, -4.0, 55.0);
    glVertex3f(-6, -4.0, 55.0);
    glVertex3f(-6, -4.0, 45.0);
    glVertex3f(-10, -4.0, 45.0);
    glEnd();

    //teras 
       //alas
    glBegin(GL_QUADS);
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(10, -7.0, 75.0);
    glVertex3f(-13, -7.0, 75.0);
    glVertex3f(-13, -7.0, 85.0);
    glVertex3f(10, -7.0, 85.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(10, -7.0, 85.0);
    glVertex3f(-13, -7.0, 85.0);
    glVertex3f(-13, -10.0, 85.0);
    glVertex3f(10, -10.0, 85.0);
    glEnd();
    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(10, -7.0, 80.0);
    glVertex3f(10, -10.0, 80.0);
    glVertex3f(10, -10.0, 85.0);
    glVertex3f(10, -7.0, 85.0);
    glEnd();
    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-13, -7.0, 80.0);
    glVertex3f(-13, -10.0, 80.0);
    glVertex3f(-13, -10.0, 85.0);
    glVertex3f(-13, -7.0, 85.0);
    glEnd();
    //tembok kiri
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(-13, 20.0, 75.0);
    glVertex3f(-13, -10.0, 75.0);
    glVertex3f(-13, -10.0, 80.0);
    glVertex3f(-13, 20.0, 80.0);
    glEnd();
    //tembok kanan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(10, -10.0, 75.0);
    glVertex3f(10, -10.0, 80.0);
    glVertex3f(10, 20.0, 80.0);
    glEnd();
    //pintu depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-12, 14.9, 75.0);
    glVertex3f(-5, 14.9, 75.0);
    glVertex3f(-5, -7.0, 75.0);
    glVertex3f(-12, -7.0, 75.0);
    glEnd();
    glBegin(GL_POINTS);
    //gagang pintu
    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(-10, 3, 76);
    glEnd();
    //Kusen depan berdiri keatas, kiri => kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-13, 20.0, 75.0);
    glVertex3f(-12, 20.0, 75.0);
    glVertex3f(-12, -7.0, 75.0);
    glVertex3f(-13, -7.0, 75.0);
    //2
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-5, 20.0, 75.0);
    glVertex3f(-4, 20.0, 75.0);
    glVertex3f(-4, -7.0, 75.0);
    glVertex3f(-5, -7.0, 75.0);
    //3
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(2, 20.0, 75.0);
    glVertex3f(3, 20.0, 75.0);
    glVertex3f(3, -7.0, 75.0);
    glVertex3f(2, -7.0, 75.0);
    //4
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(9, 20.0, 75.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(10, -7.0, 75.0);
    glVertex3f(9, -7.0, 75.0);
    glEnd();
    // Kusen jendela ke samping, atas => bawah
    glBegin(GL_QUADS);
    //1
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-4, 5, 75.0);
    glVertex3f(2, 5, 75.0);
    glVertex3f(2, 4, 75.0);
    glVertex3f(-4, 4, 75.0);
    //2
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(-4, -6, 75.0);
    glVertex3f(2, -6, 75.0);
    glVertex3f(2, -7, 75.0);
    glVertex3f(-4, -7, 75.0);
    //3
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(3, 5, 75.0);
    glVertex3f(9, 5, 75.0);
    glVertex3f(9, 4, 75.0);
    glVertex3f(3, 4, 75.0);
    //4
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(3, -6, 75.0);
    glVertex3f(9, -6, 75.0);
    glVertex3f(9, -7, 75.0);
    glVertex3f(3, -7, 75.0);
    glEnd();
    // Ventilasi depan, kiri => kanan
    glBegin(GL_LINES);
    glColor3f(0.00, 0.00, 1.00);
    //1
    glVertex3i(-12, 19, 75);
    glVertex3i(-5, 19, 75);
    glVertex3i(-12, 17, 75);
    glVertex3i(-5, 17, 75);
    glVertex3i(-12, 15, 75);
    glVertex3i(-5, 15, 75);
    //2
    glVertex3i(-4, 19, 75);
    glVertex3i(2, 19, 75);
    glVertex3i(-4, 17, 75);
    glVertex3i(2, 17, 75);
    glVertex3i(-4, 15, 75);
    glVertex3i(2, 15, 75);
    //3
    glVertex3i(3, 19, 75);
    glVertex3i(9, 19, 75);
    glVertex3i(3, 17, 75);
    glVertex3i(9, 17, 75);
    glVertex3i(3, 15, 75);
    glVertex3i(9, 15, 75);
    glEnd();


    //tembok depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10.0, -10.0, 75.0);
    glVertex3f(10.0, 20.0, 75.0);
    glVertex3f(80.0, 20.0, 75.0);
    glVertex3f(80.0, -10.0, 75.0);
    //rolling door kiri
    glColor3f(0.85, 0.85, 0.85);
    glVertex3f(12.0, -10.0, 75.1);
    glVertex3f(12.0, 18.0, 75.1);
    glVertex3f(35.0, 18.0, 75.1);
    glVertex3f(35.0, -10.0, 75.1);
    //tuas rolling door kiri
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(22.5, -6.0, 75.2);
    glVertex3f(24.5, -6.0, 75.2);
    glVertex3f(24.5, -7.0, 75.2);
    glVertex3f(22.5, -7.0, 75.2);
    //rolling door kanan
    glColor3f(0.85, 0.85, 0.85);
    glVertex3f(40.0, -10.0, 75.1);
    glVertex3f(40.0, 18.0, 75.1);
    glVertex3f(63.0, 18.0, 75.1);
    glVertex3f(63.0, -10.0, 75.1);
    //tuas rolling door kiri
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(50.5, -6.0, 75.2);
    glVertex3f(52.5, -6.0, 75.2);
    glVertex3f(52.5, -7.0, 75.2);
    glVertex3f(50.5, -7.0, 75.2);
    //pintu garasi
    glColor3f(0.75, 0.0, 0.3);
    glVertex3f(67.0, 15.0, 75.2);
    glVertex3f(76.0, 15.0, 75.2);
    glVertex3f(76.0, -10.0, 75.2);
    glVertex3f(67.0, -10.0, 75.2);
    glEnd();
    glBegin(GL_POINTS);
    //gagang pintu
    glColor3f(0.0, 0.0, 0.0);
    glVertex3i(70, 2.25, 76);
    glEnd();
    //garasi mobil luar
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(10, -10.0, 75.0);
    glVertex3f(80, -10.0, 75.0);
    glVertex3f(80, -10.0, 130.0);
    glVertex3f(10, -10.0, 130.0);
    glEnd();
    //atap garasi luar
    glBegin(GL_QUADS);
    glColor3f(0.95, 0.0, 0.5);
    glVertex3f(10, 15.0, 130.0);
    glVertex3f(80, 15.0, 130.0);
    glVertex3f(80, 20.0, 75.0);
    glVertex3f(10, 20.0, 75.0);
    glEnd();



    //tembok rumah kanan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(10, -10.0, 75.0);
    glVertex3f(10, -10.0, -35.0);
    glVertex3f(10, 20.0, -35.0);
    glEnd();


    //tembok rumah belakang
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(-80.0, -10.0, -35.0);
    glVertex3f(-80.0, 20.0, -35.0);
    glVertex3f(10.0, 20.0, -35.0);
    glVertex3f(10.0, -10.0, -35.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-50, -10.0, -35.1);
    glVertex3f(-60, -10.0, -35.1);
    glVertex3f(-60, 15.0, -35.1);
    glVertex3f(-50, 15.0, -35.1);
    glEnd();
    //gagang pintu
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-52, 4.0, -35.2);
    glVertex3f(-54, 4.0, -35.2);
    glVertex3f(-54, 6.0, -35.2);
    glVertex3f(-52, 6.0, -35.2);
    glEnd();


    //tembok rumah kiri
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(-80, 20.0, 75.0);
    glVertex3f(-80, -10.0, 75.0);
    glVertex3f(-80, -10.0, -35.0);
    glVertex3f(-80, 20.0, -35.0);
    glEnd();


    //tembok rumah bawah
    glBegin(GL_QUADS);
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-80, -10.0, 75.0);
    glVertex3f(80, -10.0, 75.0);
    glVertex3f(106, -10.0, -115.0);
    glVertex3f(-80, -10.0, -115.0);
    glEnd();


    //pagar
        //pagar kiri
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-80, 20.0, -170.0);
    glVertex3f(-80, -10.0, -170.0);
    glVertex3f(-80, -10.0, -35.0);
    glVertex3f(-80, 20.0, -35.0);
    glEnd();
    //pagar kanan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1, 1);
    glVertex3f(80.0, 20.0, 75.0);
    glVertex3f(80.0, -10.0, 75.0);
    glVertex3f(100.0, -10.0, -75.0);
    glVertex3f(100.0, 20.0, -75.0);
    glEnd();
    //pagar belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-80.0, -10.0, -170.0);
    glVertex3f(-80.0, 20.0, -170.0);
    glVertex3f(106.0, 20.0, -170.0);
    glVertex3f(106.0, -10.0, -170.0);
    glEnd();
    //pagar kanan belakang kamar
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(106, 20.0, -170.0);
    glVertex3f(106, -10.0, -170.0);
    glVertex3f(106, -10.0, -115.0);
    glVertex3f(106, 20.0, -115.0);
    glEnd();
    //tanah halaman belakang
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.0);
    glVertex3f(-80, -10.0, -115.0);
    glVertex3f(106, -10.0, -115.0);
    glVertex3f(106, -10.0, -170.0);
    glVertex3f(-80, -10.0, -170.0);
    glEnd();


    //tembok rumah atas
    glBegin(GL_QUADS);
    glColor3f(0.95, 0.95, 0.95);
    glVertex3f(-80, 20.0, 75.0);
    glVertex3f(63, 20.0, 75.0);
    glVertex3f(63, 20.0, -35.0);
    glVertex3f(-80, 20.0, -35.0);
    glEnd();


    //kamar belakang
       //atas
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(40, 70.0, -115.0);
    glVertex3f(106, 70.0, -115.0);
    glVertex3f(100, 70.0, -75.0);
    glVertex3f(40, 70.0, -75.0);
    glEnd();

    //atap sambung
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(40, 40.0, -75.0);
    glVertex3f(100, 40.0, -75.0);
    glVertex3f(98, 30.0, -60.0);
    glVertex3f(40, 30.0, -60.0);
    glEnd();
    //kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 30.0, -75.0);
    glVertex3f(98, 30.0, -60.0);
    glVertex3f(100, 40.0, -75.0);
    glEnd();
    //kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 30.0, -75.0);
    glVertex3f(40, 30.0, -60.0);
    glVertex3f(40, 40.0, -75.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.55, 1.0, 1.0);
    glVertex3f(40.0, -10.0, -75.0);
    glVertex3f(40.0, 70.0, -75.0);
    glVertex3f(100.0, 70.0, -75.0);
    glVertex3f(100.0, -10.0, -75.0);
    glEnd();
    //jendela kiri
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(50, 45.0, -74.1);
    glVertex3f(50, 65.0, -74.1);
    glVertex3f(60, 65.0, -74.1);
    glVertex3f(60, 45.0, -74.1);
    glEnd();
    //garis jendela
    glBegin(GL_LINES);
    glColor3f(0.85, 0.85, 0.85);
    glVertex3i(55, 45, -74.2);
    glVertex3i(55, 65, -74.2);
    glVertex3i(50, 52.5, -74.3);
    glVertex3i(60, 52.5, -74.3);
    glVertex3i(50, 57.5, -74.3);
    glVertex3i(60, 57.5, -74.3);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(50.0, 65.0, -74.1);
    glVertex3f(50.0, 66.0, -74.1);
    glVertex3f(60.0, 66.0, -74.1);
    glVertex3f(60.0, 65.0, -74.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(50.0, 44.0, -74.1);
    glVertex3f(50.0, 45.0, -74.1);
    glVertex3f(60.0, 45.0, -74.1);
    glVertex3f(60.0, 44.0, -74.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(50.0, 44.0, -74.1);
    glVertex3f(50.0, 66.0, -74.1);
    glVertex3f(49.0, 66.0, -74.1);
    glVertex3f(49.0, 44.0, -74.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(61.0, 44.0, -74.1);
    glVertex3f(61.0, 66.0, -74.1);
    glVertex3f(60.0, 66.0, -74.1);
    glVertex3f(60.0, 44.0, -74.1);
    glEnd();
    //jendela kanan
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(80, 45.0, -74.1);
    glVertex3f(80, 65.0, -74.1);
    glVertex3f(90, 65.0, -74.1);
    glVertex3f(90, 45.0, -74.1);
    glEnd();
    //garis jendela
    glBegin(GL_LINES);
    glColor3f(0.85, 0.85, 0.85);
    glVertex3i(85, 45, -74.2);
    glVertex3i(85, 65, -74.2);
    glVertex3i(80, 52.5, -74.3);
    glVertex3i(90, 52.5, -74.3);
    glVertex3i(80, 57.5, -74.3);
    glVertex3i(90, 57.5, -74.3);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(80.0, 65.0, -74.1);
    glVertex3f(80.0, 66.0, -74.1);
    glVertex3f(90.0, 66.0, -74.1);
    glVertex3f(90.0, 65.0, -74.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(80.0, 44.0, -74.1);
    glVertex3f(80.0, 45.0, -74.1);
    glVertex3f(90.0, 45.0, -74.1);
    glVertex3f(90.0, 44.0, -74.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(80.0, 44.0, -74.1);
    glVertex3f(80.0, 66.0, -74.1);
    glVertex3f(79.0, 66.0, -74.1);
    glVertex3f(79.0, 44.0, -74.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(91.0, 44.0, -74.1);
    glVertex3f(91.0, 66.0, -74.1);
    glVertex3f(90.0, 66.0, -74.1);
    glVertex3f(90.0, 44.0, -74.1);
    glEnd();



    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.55, 1.0, 1.0);
    glVertex3f(100.0, 70.0, -75.0);
    glVertex3f(100.0, -10.0, -75.0);
    glVertex3f(106.0, -10.0, -115.0);
    glVertex3f(106.0, 70.0, -115.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.55, 1.0, 1.0);
    glVertex3f(40, 70.0, -75.0);
    glVertex3f(40, -10.0, -75.0);
    glVertex3f(40, -10.0, -115.0);
    glVertex3f(40, 70.0, -115.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.55, 1.0, 1.0);
    glVertex3f(40.0, -10.0, -115.0);
    glVertex3f(40.0, 70.0, -115.0);
    glVertex3f(106.0, 70.0, -115.0);
    glVertex3f(106.0, -10.0, -115.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.55, 1.0, 1.0);
    glVertex3f(40, 70.0, -115.0);
    glVertex3f(106, 70.0, -115.0);
    glVertex3f(100, 70.0, -75.0);
    glVertex3f(40, 70.0, -75.0);
    glEnd();
    //atap depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(40, 80.0, -95.0);
    glVertex3f(103, 80.0, -95.0);
    glVertex3f(100, 70.0, -70.0);
    glVertex3f(40, 70.0, -70.0);
    glEnd();
    //atap belakang
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(40, 80.0, -95.0);
    glVertex3f(103, 80.0, -95.0);
    glVertex3f(107, 70.0, -120.0);
    glVertex3f(40, 70.0, -120.0);
    glEnd();
    //atap sisi kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(100, 70.0, -70.0);
    glVertex3f(103, 80.0, -95.0);
    glVertex3f(107, 70.0, -120.0);
    glEnd();
    //atap sisi kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 70.0, -70.0);
    glVertex3f(40, 80.0, -95.0);
    glVertex3f(40, 70.0, -120.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(70, -10.0, -74.1);
    glVertex3f(70, 15.0, -74.1);
    glVertex3f(80, 15.0, -74.1);
    glVertex3f(80, -10.0, -74.1);
    glEnd();
    glBegin(GL_POINTS);
    //gagang pintu
    glColor3f(0.6, 0.6, 0.6);
    glVertex3i(73, 3, -73);
    glEnd();

    //tembok rumah lantai 2
       //depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(63, 20.0, 75.0);
    glVertex3f(63, 50.0, 75.0);
    glVertex3f(10, 50.0, 75.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(63, 50.0, 75.0);
    glVertex3f(63, 20.0, 75.0);
    glVertex3f(63, 20.0, -35.0);
    glVertex3f(63, 50.0, -35.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10.0, 20.0, -35.0);
    glVertex3f(10.0, 50.0, -35.0);
    glVertex3f(63.0, 50.0, -35.0);
    glVertex3f(63.0, 20.0, -35.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10, 50.0, 75.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(10, 20.0, -35.0);
    glVertex3f(10, 50.0, -35.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.75, 1.0, 1.0);
    glVertex3f(10, 50.0, 75.0);
    glVertex3f(63, 50.0, 75.0);
    glVertex3f(63, 50.0, -35.0);
    glVertex3f(10, 50.0, -35.0);
    glEnd();
    //atap depan
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(10, 50.0, 85.0);
    glVertex3f(63, 50.0, 85.0);
    glVertex3f(63, 65.0, 20.0);
    glVertex3f(10, 65.0, 20.0);
    glEnd();
    //atap belakang
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.0, 0.0);
    glVertex3f(10, 50.0, -40.0);
    glVertex3f(63, 50.0, -40.0);
    glVertex3f(63, 65.0, 20.0);
    glVertex3f(10, 65.0, 20.0);
    glEnd();
    //sisi kanan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(63, 50.0, 85.0);
    glVertex3f(63, 65.0, 20.0);
    glVertex3f(63, 50.0, -40.0);
    glEnd();
    //sisi kiri
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10, 50.0, 85.0);
    glVertex3f(10, 65.0, 20.0);
    glVertex3f(10, 50.0, -40.0);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.975, 0.975, 0.975);
    glVertex3f(9.9, 45.0, 65.0);
    glVertex3f(9.9, 20.0, 65.0);
    glVertex3f(9.9, 20.0, 55.0);
    glVertex3f(9.9, 45.0, 55.0);
    glEnd();
    //gagang pintu
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(9.8, 36.0, 59.0);
    glVertex3f(9.8, 33.5, 59.0);
    glVertex3f(9.8, 33.5, 57.0);
    glVertex3f(9.8, 36.0, 57.0);
    glEnd();
    //balkon alas
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-13, 20.0, 100.0);
    glVertex3f(10, 20.0, 100.0);
    glVertex3f(10, 20.0, 75.0);
    glVertex3f(-13, 20.0, 75.0);
    glEnd();
    //balkon kiri
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-13, 20.0, 100.0);
    glVertex3f(-13, 20.0, 75.0);
    glVertex3f(-13, 25.0, 75.0);
    glVertex3f(-13, 25.0, 100.0);
    glEnd();
    //balkon kanan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10, 20.0, 100.0);
    glVertex3f(10, 20.0, 85.0);
    glVertex3f(10, 25.0, 85.0);
    glVertex3f(10, 25.0, 100.0);
    glEnd();
    //balkon depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-13, 20.0, 100.0);
    glVertex3f(10, 20.0, 100.0);
    glVertex3f(10, 25.0, 100.0);
    glVertex3f(-13, 25.0, 100.0);
    glEnd();
    //balkon kedua alas
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(10, 20.0, 85.0);
    glVertex3f(63, 20.0, 85.0);
    glVertex3f(63, 20.0, 75.0);
    glVertex3f(10, 20.0, 75.0);
    glEnd();
    //balkon kedua kanan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(63, 20.0, 85.0);
    glVertex3f(63, 20.0, 75.0);
    glVertex3f(63, 25.0, 75.0);
    glVertex3f(63, 25.0, 85.0);
    glEnd();
    //balkon kedua depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10, 20.0, 85.0);
    glVertex3f(63, 20.0, 85.0);
    glVertex3f(63, 25.0, 85.0);
    glVertex3f(10, 25.0, 85.0);
    glEnd();


    //jendela tembok depan 1
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(20.0, 30.0, 75.1);
    glVertex3f(20.0, 40.0, 75.1);
    glVertex3f(30.0, 40.0, 75.1);
    glVertex3f(30.0, 30.0, 75.1);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(20.0, 40.0, 75.1);
    glVertex3f(20.0, 41.0, 75.1);
    glVertex3f(30.0, 41.0, 75.1);
    glVertex3f(30.0, 40.0, 75.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(20.0, 29.0, 75.1);
    glVertex3f(20.0, 30.0, 75.1);
    glVertex3f(30.0, 30.0, 75.1);
    glVertex3f(30.0, 29.0, 75.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(20.0, 29.0, 75.1);
    glVertex3f(20.0, 41.0, 75.1);
    glVertex3f(19.0, 41.0, 75.1);
    glVertex3f(19.0, 29.0, 75.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(25.5, 29.0, 75.2);
    glVertex3f(25.5, 41.0, 75.2);
    glVertex3f(24.5, 41.0, 75.2);
    glVertex3f(24.5, 29.0, 75.2);
    //3
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(31.0, 29.0, 75.1);
    glVertex3f(31.0, 41.0, 75.1);
    glVertex3f(30.0, 41.0, 75.1);
    glVertex3f(30.0, 29.0, 75.1);
    glEnd();


    //jendela tembok depan 2
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(40.0, 30.0, 75.1);
    glVertex3f(40.0, 40.0, 75.1);
    glVertex3f(50.0, 40.0, 75.1);
    glVertex3f(50.0, 30.0, 75.1);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(40.0, 40.0, 75.1);
    glVertex3f(40.0, 41.0, 75.1);
    glVertex3f(50.0, 41.0, 75.1);
    glVertex3f(50.0, 40.0, 75.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(40.0, 29.0, 75.1);
    glVertex3f(40.0, 30.0, 75.1);
    glVertex3f(50.0, 30.0, 75.1);
    glVertex3f(50.0, 29.0, 75.1);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(40.0, 29.0, 75.1);
    glVertex3f(40.0, 41.0, 75.1);
    glVertex3f(39.0, 41.0, 75.1);
    glVertex3f(39.0, 29.0, 75.1);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(45.5, 29.0, 75.2);
    glVertex3f(45.5, 41.0, 75.2);
    glVertex3f(44.5, 41.0, 75.2);
    glVertex3f(44.5, 29.0, 75.2);
    //3
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(51.0, 29.0, 75.1);
    glVertex3f(51.0, 41.0, 75.1);
    glVertex3f(50.0, 41.0, 75.1);
    glVertex3f(50.0, 29.0, 75.1);
    glEnd();



    //jendela tembok kanan 1
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(63.1, 40.0, 65);
    glVertex3f(63.1, 30.0, 65);
    glVertex3f(63.1, 30.0, 55);
    glVertex3f(63.1, 40.0, 55);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 40.0, 65);
    glVertex3f(63.1, 41.0, 65);
    glVertex3f(63.1, 41.0, 55);
    glVertex3f(63.1, 40.0, 55);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 65);
    glVertex3f(63.1, 30.0, 65);
    glVertex3f(63.1, 30.0, 55);
    glVertex3f(63.1, 29.0, 55);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 65);
    glVertex3f(63.1, 41.0, 65);
    glVertex3f(63.1, 41.0, 66);
    glVertex3f(63.1, 29.0, 66);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.2, 29.0, 59.5);
    glVertex3f(63.2, 41.0, 59.5);
    glVertex3f(63.2, 41.0, 60.5);
    glVertex3f(63.2, 29.0, 60.5);
    //3
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 55);
    glVertex3f(63.1, 41.0, 55);
    glVertex3f(63.1, 41.0, 54);
    glVertex3f(63.1, 29.0, 54);
    glEnd();

    //jendela tembok kanan 2
    glBegin(GL_QUADS);
    glColor3f(1.00, 1.00, 0.75);
    glVertex3f(63.1, 40.0, 15);
    glVertex3f(63.1, 30.0, 15);
    glVertex3f(63.1, 30.0, 5);
    glVertex3f(63.1, 40.0, 5);
    glEnd();
    // kusen ke samping, atas=> bawah
    //1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 40.0, 15);
    glVertex3f(63.1, 41.0, 15);
    glVertex3f(63.1, 41.0, 5);
    glVertex3f(63.1, 40.0, 5);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 15);
    glVertex3f(63.1, 30.0, 15);
    glVertex3f(63.1, 30.0, 5);
    glVertex3f(63.1, 29.0, 5);
    glEnd();
    //kusen berdiri, kiri=> kanan
    glBegin(GL_QUADS);
    //1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 15);
    glVertex3f(63.1, 41.0, 15);
    glVertex3f(63.1, 41.0, 16);
    glVertex3f(63.1, 29.0, 16);
    //2
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.2, 29.0, 9.5);
    glVertex3f(63.2, 41.0, 9.5);
    glVertex3f(63.2, 41.0, 10.5);
    glVertex3f(63.2, 29.0, 10.5);
    //3
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(63.1, 29.0, 5);
    glVertex3f(63.1, 41.0, 5);
    glVertex3f(63.1, 41.0, 4);
    glVertex3f(63.1, 29.0, 4);
    glEnd();
















    glPopMatrix();
    glutSwapBuffers();

}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
    cout << "Hello";  // prints Hello
   
}

