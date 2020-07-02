#include <SFML/Graphics.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

#include <GL/glut.h>

using namespace std;
using namespace sf;
using namespace cv;

void resetTransforms()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void drawBox(float ox, float oy, float oz, float x, float y, float z)
{
    
    // Задняя стена
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.4, 0.3);
    glVertex3f(ox+x, oy-y, oz+z);
    glVertex3f(ox+x, oy+y, oz+z);
    glVertex3f(ox-x, oy+y, oz+z);
    glVertex3f(ox-x, oy-y, oz+z);
    glEnd();

    // Передняя стена
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.4, 0.3);
    glVertex3f(ox-x, oy+y, oz-z);
    glVertex3f(ox-x, oy-y, oz-z);
    glVertex3f(ox+x, oy-y, oz-z);
    glVertex3f(ox+x, oy+y, oz-z);
    glEnd();

    // Левая стена
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.4, 0.3);
    glVertex3f(ox-x, oy-y, oz-z);
    glVertex3f(ox-x, oy-y, oz+z);
    glVertex3f(ox-x, oy+y, oz+z);
    glVertex3f(ox-x, oy+y, oz-z);
    glEnd();


    // Правая стена
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.4, 0.3);
    glVertex3f(ox+x, oy-y, oz-z);
    glVertex3f(ox+x, oy-y, oz+z);
    glVertex3f(ox+x, oy+y, oz+z);
    glVertex3f(ox+x, oy+y, oz-z);
    glEnd();


    // Пол
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(ox-x, oy-y, oz-z);
    glVertex3f(ox-x, oy-y, oz+z);
    glVertex3f(ox+x, oy-y, oz+z);
    glVertex3f(ox+x, oy-y, oz-z);
    glEnd();
}

void drawSphere(float radius, float x, float y, float z)
{
    glColor3f(1, 0, 0);
    glTranslatef(x,y,z);
    glutSolidSphere(radius,20,20);
    resetTransforms();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0, 0.0, -5.0);

        GLfloat ambientColor[] = {0.4, 0.4, 0.4, 1.0};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

        GLfloat lightColor0[] = {0.5, 0.5, 0.5, 5.0};
        GLfloat lightPos0[] = {4.0, 0.0, 8.0, 5.0};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    
        drawBox(0,3,-5,10,4,10);
        drawSphere(0.25,3,-1,-4);
    
        //Правый верхний край: drawSphere(5,10,-1,-15);

        glFlush();
    glutSwapBuffers();
}

void initRendering()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        // Фон
        glClearColor(0.7f, 0.8f, 1.0f, 1.0f);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
}


void handleResize(int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0, (double)w / (double)h, 1.0, 200.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL");
        initRendering();

    glutDisplayFunc(draw);
        glutReshapeFunc(handleResize);

    glutMainLoop();
    return 0;
}
