#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLfloat count;
GLfloat spin = 0.0;
GLfloat speed = 0.0;
int running = 1;
int i, j;

unsigned char key2;
void Fan_Physics();
void Fan_Render();
void turbine();
void* currentfont;
void draw();
void waterflow1();
void box();
void waterflow2();
void dam();
void power_house();
void generator();
void control_gate();
void reservoir();
void poles();
void text();
void outflow();


void Fan_Physics(void)
{
    speed = speed + 0.1;
    speed = speed + 0.9;
    speed = speed + 1;
    if (speed > 360.0)
        speed = 360.0 + i;
    spin = spin + speed / 100;
    glutPostRedisplay();
}

void Fan_Render(void)
{
    glRotatef(-spin, 0.0, 0.0, 1.0);
    turbine();
}

void outflow()
{
    glColor3f(0.0, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex3f(825, -10, 50);
    glVertex3f(1399, -10, 50);
    glVertex3f(1399, -100, 50);
    glVertex3f(730, -100, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196078, 0.6, 0.8);
    glVertex3f(620, -100, 100);
    glColor3f(0.22, 0.69, 0.87);
    glVertex3f(1399, -100, 300);
    glColor3f(0.196078, 0.6, 0.8);
    glVertex3f(1399, -900, 100);
    glColor3f(0.22, 0.69, 0.87);
    glVertex3f(620, -900, 100);
    glEnd();
}

void dam()
{
    //connection to turbine
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(50, -450, 40);
    glVertex3f(50, 0, 40);
    glVertex3f(30, 0, 40);
    glVertex3f(30, -450, 40);
    glEnd();

    // connecting dam face
    glColor3f(0.329412, 0.329412, 0.329412);
    glBegin(GL_POLYGON);
    glColor3f(0.847059, 0.847059, 0.74902);
    glVertex3f(-1200, 750, 150);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1050, 900, 150);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-865, 900, 300);
    glColor3f(0.847059, 0.847059, 0.74902);
    glVertex3f(-1060, 750, 300);
    glEnd();

    //constructing dam side face
    glColor3f(0.329412, 0.329412, 0.329412);
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1060, 750, 100);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-875, 900, 100);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-400, 60, 130);
    glColor3f(0.847059, 0.847059, 0.74902);
    glVertex3f(-600, -100, 130);
    glEnd();

    //connecting dam front face

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1200, 750, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1060, 750, 300);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1200, 101, 300);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1200, -100, -300);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1200, 101, 300);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1102, 101, -300);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1102, -160, 130);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.80, 0.8);
    glVertex3f(-1050, -170, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1050, 101, 300);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-708, 101, 130);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-600, -100, 300);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-600, -260, 150);
    glEnd();

    //Dam front face down the penstock
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-600, -260, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-600, -100, 300);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, -100, 50);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-200, -335, 50);
    glEnd();

    //Dam filled Below
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-200, -900, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-200, -440, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1048, -300, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1048, -900, 50);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1045, -900, -50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1045, -500, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1100, -500, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1230, -500, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1300, -500, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1300, -900, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1100, -500, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1100, -350, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1200, -400, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-1230, -500, 50);
    glEnd();

    //Foot of the Dam
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-400, 60, 0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-200, 60, 0);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-200, -100, 0);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-600, -100, 00);
    glEnd();

    //Foot of the dam beyond powerhouse
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(730, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(825, -10, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(740, 100, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(600, 0, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-1100, -350, 50);
    glVertex3f(-1200, -400, 50);
    glVertex3f(-1200, -400, 50);
    glVertex3f(-1230, -500, 50);
    glVertex3f(-1230, -500, 50);
    glVertex3f(-1300, -500, 50);
    glVertex3f(-1300, -500, 50);
    glVertex3f(-1300, -900, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(730, -100, 50); //Dam right to float
    glVertex3f(620, -100, 50);
    glVertex3f(620, -100, 50);
    glVertex3f(620, -750, 50);
    glVertex3f(-1300, -900, 50);
    glEnd();

    //Dam top of the turbine
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-200, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, 0, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(640, 0, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(730, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-620, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-730, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, -200, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(620, -100, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(620, -200, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(300, -200, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(620, -200, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(620, -750, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(300, -600, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(200, -700, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(620, -900, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(-200, -900, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-200, -700, 50);
    glEnd();
}

void power_house()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-300, 0, 50);
    glVertex3f(-300, 450, 50);
    glVertex3f(400, 450, 50);
    glVertex3f(400, 0, 50);
    glEnd();

    //Inner face of powerhouse
    glBegin(GL_POLYGON);
    glColor3f(0.184314, 0.309804, 0.309804);
    glVertex3f(-250, 0, 50);
    glColor3f(1, 1, 1);
    glVertex3f(-250, 400, 50);
    glColor3f(1, 1, 1);
    glVertex3f(350, 400, 50);
    glColor3f(0.184314, 0.309804, 0.309804);
    glVertex3f(350, 0, 50);
    glEnd();


    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-250, 0, 50);
    glVertex3f(-250, 400, 50);
    glVertex3f(350, 400, 50);
    glVertex3f(350, 0, 50);
    glEnd();


    //Top face of powerhouse
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-300, 450, 50);
    glVertex3f(-180, 550, 50);
    glVertex3f(520, 550, 50);
    glVertex3f(400, 450, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0);
    glVertex3f(-300, 450, 50);
    glColor3f(0.85, 0.53, 0.10);
    glVertex3f(-180, 550, 50);
    glColor3f(0.5, 0.5, 0.0);
    glVertex3f(520, 550, 50);
    glColor3f(0.85, 0.53, 0.10);
    glVertex3f(400, 450, 50);
    glEnd();

    //side of powerhouse
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0);
    glVertex3f(400, 450, 50);
    glColor3f(0.85, 0.53, 0.10);
    glVertex3f(520, 550, 50);
    glColor3f(0.5, 0.5, 0.0);
    glVertex3f(520, 100, 50);
    glColor3f(0.85, 0.53, 0.10);
    glVertex3f(400, 0, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(520, 100, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(400, 0, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(600, 0, 50);
    glColor3f(0.36, 0.20, 0.09);
    glVertex3f(740, 100, 50);
    glEnd();
}

void generator()
{
    //generator
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-100, 4, 150);
    glVertex3f(-100, 200, 150);
    glVertex3f(-85, 200, 150);
    glVertex3f(-85, 4, 150);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(-100, 4, 150);
    glVertex3f(-100, 200, 150);
    glVertex3f(-85, 200, 150);
    glVertex3f(-85, 4, 150);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(-85, 4, 150);
    glVertex3f(-85, 198, 150);
    glVertex3f(180, 198, 150);
    glVertex3f(180, 4, 150);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(180, 4, 150);
    glVertex3f(180, 200, 150);
    glVertex3f(200, 200, 150);
    glVertex3f(200, 4, 150);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(180, 4, 150);
    glVertex3f(180, 200, 150);
    glVertex3f(200, 200, 150);
    glVertex3f(200, 4, 150);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(180, 4, 150);
    glVertex3f(180, 200, 150);
    glVertex3f(-85, 200, 150);
    glVertex3f(-85, 4, 150);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(4, 200, 150);
    glVertex3f(4, 220, 150);
    glVertex3f(100, 220, 150);
    glVertex3f(100, 200, 150);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(4, 200, 150);
    glVertex3f(4, 220, 150);
    glVertex3f(100, 220, 150);
    glVertex3f(100, 200, 150);
    glEnd();
}
void control_gate()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-1050, -300, 50);
    glVertex3f(-1050, -500, 50);
    glVertex3f(-1100, -500, 50);
    glVertex3f(-1100, -350, 50);
    glEnd();

    glColor3f(0, 0, 0);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(9);
    glBegin(GL_POINTS);
    glVertex3f(-1075, -140, 50);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glLineWidth(50);
    glEnable(GL_LINE_SMOOTH);
    glVertex3f(-1075, -155, 40);
    glVertex3f(-1075, -480, 40);
    glEnd();

    //control gate outerline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-1100, -160, 50);
    glVertex3f(-1100, 100, -50);
    glVertex3f(-1100, 100, -50);
    glVertex3f(-1050, 100, 50);
    glVertex3f(-1050, 100, 50);
    glVertex3f(-1050, -170, 50);
    glEnd();

    //penstock outer lines
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-1050, -300, 50);
    glVertex3f(-300, -480, 50);
    glVertex3f(-1050, -330, 50);
    glVertex3f(-1050, -500, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-1080, -140, 50);
    glVertex3f(-1080, 70, 50);
    glEnd();
}

void reservoir()
{
    glColor3f(0.0, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex3f(-1200, 500, 50);
    glVertex3f(-1200, 600, 50);
    glVertex3f(-1500, 600, 50);
    glVertex3f(-1500, 500, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196078, 0.6, 0.8);
    glVertex3f(-1200, -100, 50);
    glVertex3f(-1500, -100, 300);
    glVertex3f(-1500, 500, 50);
    glVertex3f(-1200, 500, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.196078, 0.6, 0.8);
    glVertex3f(-1500, -100, 50);
    glVertex3f(-1200, -100, 300);
    glVertex3f(-1080, -160, 50);
    glVertex3f(-1080, -350, 50);
    glVertex3f(-1200, -400, 50);
    glVertex3f(-1230, -500, 50);
    glVertex3f(-1500, -500, 50);
    glEnd();

    glColor3f(0.196078, 0.6, 0.8);
    glBegin(GL_POLYGON);
    glVertex3f(-1500, -500, 50);
    glVertex3f(-1300, -500, 300);
    glVertex3f(-1300, -900, 50);
    glVertex3f(-1500, -900, 50);
    glEnd();
}

void poles()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(1120, 800, -150);
    glVertex3f(1145, 1000, -150);
    glVertex3f(1170, 800, -150);
    glVertex3f(1125, 850, -150);
    glVertex3f(1160, 850, -150);
    glVertex3f(1140, 900, -150);
    glVertex3f(1155, 900, -150);
    glVertex3f(1140, 950, -150);
    glVertex3f(1150, 950, -50);
    glVertex3f(1140, 900, -150);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(1155, 900, -150);
    glVertex3f(1125, 850, -150);
    glVertex3f(1160, 850, -150);
    glVertex3f(1120, 800, -150);
    glVertex3f(1095, 950, -150);
    glVertex3f(1195, 950, -150);
    glEnd();

    glDisable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glPointSize(1);
    glVertex3f(1120, 950, -150);
    glVertex3f(1170, 950, -150);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(945, 600, -100);
    glVertex3f(970, 800, -100);
    glVertex3f(995, 600, -100);
    glVertex3f(950, 650, -100);
    glVertex3f(990, 650, -100);
    glVertex3f(955, 700, -100);
    glVertex3f(980, 700, -100);
    glVertex3f(965, 750, -100);
    glVertex3f(970, 750, -100);
    glVertex3f(955, 700, -100);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(980, 700, -100);
    glVertex3f(950, 650, -100);
    glVertex3f(990, 650, -100);
    glVertex3f(945, 600, -100);
    glVertex3f(920, 750, -100);
    glVertex3f(1020, 750, -100);
    glEnd();

    glBegin(GL_POINTS);
    glPointSize(2);
    glVertex3f(945, 750, -100);
    glVertex3f(995, 750, -100);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(1120, 950, -150);
    glVertex3f(945, 750, -100);
    glVertex3f(450, 250, 0);
    glVertex3f(995, 750, -100);
    glVertex3f(1170, 950, -150);
    glEnd();
}

void turbine()
{
    glColor3f(1, 0, 0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 200);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 200); //fan1
    glVertex3f(0, 100, 200);
    glVertex3f(70, 70, 200);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 200);
    glVertex3f(100, 0, 200);
    glVertex3f(70, -70, 200);//fan2
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 200);
    glVertex3f(0, -100, 200);//fan3
    glVertex3f(-70, -70, 200);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 200);
    glVertex3f(-100, 0, 200);//fan4
    glVertex3f(-70, 70, 200);
    glEnd();
}

void drawstring(float x, float y, float z, char* string)
{
    char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        glColor3f(0.0, 1.0, 1.0);
        glutBitmapCharacter(currentfont, *c);
    }
}

void setFont(void* font)
{
    currentfont = font;
}

void text()
{
    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-890, 1000, 50, "Dam");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(100, 700, 50, "Power house");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-400, 700, 50, "Generator");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-1400, 1000, 50, "Reservoir");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-1400, -1100, 150, "Intake");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-1100, -1100, 150, "Controlgate");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-600, -1100, 150, "Penstock");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(-200, -1100, 150, "Turbine");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(500, -1100, 150, "Outflow");

    glColor3f(0.3, 0.1, 0.1);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(800, 1100, 50, "Powerlines");
}

void waterflow1()
{
    for (i = 0; i < 180; i = i + 1)
    {
        glBegin(GL_QUADS);
        glColor3f(0.196078, 0.6, 0.8);
        glVertex3f(-1080, -160, 50);
        glVertex3f(-1080, -300, 50);
        glVertex3f(-1080 + (5 * i), -300 - i, 50);
        glVertex3f(-1080 + (5 * i), -160 - i, 50);
        glEnd();
    }
}

void box()
{
    glBegin(GL_POLYGON);
    glColor3f(0.196078, 0.6, 0.8);
    glVertex3f(-200, -700, 50);
    glVertex3f(-200, -200, 50);
    glColor3f(0.22, 0.69, 0.87);
    glVertex3f(300, -200, 50);
    glVertex3f(300, -700, 50);
    glEnd();
}

void waterflow2()
{
    for (i = 0; i < 205; i = i + 1);
    {
        glBegin(GL_POLYGON);
        glColor3f(0.196078, 0.6, 0.8);
        glVertex3f(200, -700, 51);
        glVertex3f(300, -600, 51);
        glVertex3f(300 + (2.5 * i), -600 - i, 51);
        glVertex3f(200 + (2 * i), -700 - i, 51);
        glEnd();
    }
}

void power()
{
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(7, 0XAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor3f(0, 0, 0);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(1);
    glEnable(GL_LINES);
    glVertex3f(500, 350, 50);
    glVertex3f(800, 650, 50);
    glVertex3f(800, 650, 50);
    glVertex3f(940, 800, 50);
    glVertex3f(940, 800, 50);
    glVertex3f(1135, 1015, 50);
    glEnd();
    glPopAttrib();
}

void draw()
{
    dam();
    power_house();
    generator();
    control_gate();
    reservoir();
    poles();
    text();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-870, 900, 50);
    glVertex3f(-870, 980, 150); //Dam
    glVertex3f(300, 680, 50);
    glVertex3f(300, 450, 50);//powerhouse
    glVertex3f(-50, 200, 51);
    glVertex3f(-50, 700, 51);
    glVertex3f(-50, 700, 51);
    glVertex3f(-100, 700, 100);//generator
    glVertex3f(-1300, 940, 50);
    glVertex3f(-1300, 580, 50);//reservoir
    glVertex3f(-1250, -400, 100);
    glVertex3f(-1250, -1000, 100);//Intake
    glVertex3f(-900, -1000, 100);
    glVertex3f(-900, -450, 100);
    glVertex3f(-900, -450, 100);
    glVertex3f(-1060, -450, 100);//Controlgate
    glVertex3f(-450, -1000, 100);
    glVertex3f(-450, -380, 100);//Penstock
    glVertex3f(0, -1000, 100);
    glVertex3f(0, -620, 100);//turbine
    glVertex3f(620, -850, 100);
    glVertex3f(620, -1000, 100);//outflow
    glVertex3f(1000, 1080, 50);
    glVertex3f(1000, 850, 50);//Power lines
    glEnd();

    //sand
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.60, 0.45);
    glVertex3f(-1400, -1400, 50);
    glColor3f(1, 1, 1);
    glVertex3f(-1400, -900, 50);
    glColor3f(0.70, 0.60, 0.45);
    glVertex3f(1400, -900, 50);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(1400, -1400, 50);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glViewport(310, 175, 200, 200);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -200, 200);
    Fan_Render();
    glViewport(0, 0, 800, 800);
    glLoadIdentity();
    glOrtho(-1400.0, 1400.0, -1400.0, 1400.0, -1400.0, 1400.0);
    draw();
    if (key2 == 'q' || key2 == 'Q')
        exit(0);
    if (key2 == 'w' || key2 == 'W')
    {
        count = count + 1;
        draw();
        if (count > 35)
            box();
        waterflow1();
        if (count > 100)
            glutIdleFunc(Fan_Physics);
        if (count > 105)
            power();
        if (count > 125)
            waterflow2();
        if (count > 135)
            outflow();
    }
    glMatrixMode(GL_MODELVIEW);
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    key2 = key;

    if (key == 'q' || key == 'Q')
        exit(0);
    if (key == 'w' || key == 'W')
    {
        draw();
        waterflow1();
        box();
        glutIdleFunc(Fan_Physics);
        power();
        waterflow2();
        outflow();
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hydro Power Plant");
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}