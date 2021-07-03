#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void display();
void reshape(int, int);

void init()
{
    glClearColor(0.0, 0.0 ,0.0, 0.0);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Samip's Window");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //draw
    glPointSize(10.0);

    glBegin(GL_LINES);
    glVertex2f(0,10);
    glVertex2f(0,-10);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-10,0);
    glVertex2f(10,0);
    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2f(5,5);
    glVertex2f(-5,5);
    glVertex2f(5,3);
    //
    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
