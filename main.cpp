/*
 *  main.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-2
 */

#include "MagiCube.h"
#include "BackDesktop.h"

MagiCube* cube = NULL;
BackDesktop* desk = NULL;

static int left_button = 0; // 1: down 0: up
static int right_button = 0; // 1: down 0: up

static int last_x;
static int last_y;

void init(void) {
    GlVertex vertex[8];

    vertex[0].setValue(1.0, 1.0, -1.0);
    vertex[1].setValue(1.0, 1.0, 1.0);
    vertex[2].setValue(-1.0, 1.0, 1.0);
    vertex[3].setValue(-1.0, 1.0, -1.0);
    vertex[4].setValue(1.0, -1.0, -1.0);
    vertex[5].setValue(1.0, -1.0, 1.0);
    vertex[6].setValue(-1.0, -1.0, 1.0);
    vertex[7].setValue(-1.0, -1.0, -1.0);

    cube = new MagiCube(vertex);
    desk = new BackDesktop(10,10,-2.0,"./desktop.bmp");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    glShadeModel(GL_FLAT);

//	glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_DEPTH_TEST);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity(); /* clear the matrix */
    /* viewing transformation  */

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    desk->draw();
    cube->draw();
    
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.8, 0.8, -0.8, 0.8, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

static void motion_func(int x, int y) {
    if (1 == left_button) {
        cube->cubeHorizionRotate((x - last_x) / 3.0);
        cube->cubeVerticalRotate((y - last_y) / 3.0);

        last_x = x;
        last_y = y;
    } else if (1 == right_button) {
        cube->cubeSelectMotion(x, y);
    }
}

static void mouse_func(int button, int state, int x, int y) {
    if (GLUT_LEFT_BUTTON == button) {
        if (1 == right_button)
            return;

        if (GLUT_DOWN == state && 0 == left_button) {
            last_y = y;
            last_x = x;

            left_button = 1;
        } else if (GLUT_UP == state && 1 == left_button) {
            left_button = 0;
        }
    } else if (GLUT_RIGHT_BUTTON == button) {
        if (1 == left_button)
            return;

        if (GLUT_DOWN == state && 0 == right_button) {
            right_button = 1;

            cube->cubeSelectPress(x, y);
        } else if (GLUT_UP == state && 1 == right_button) {
            right_button = 0;

            cube->cubeSelectRelease(x, y);
        }
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("MagiCube");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion_func);
    glutMouseFunc(mouse_func);

    glutMainLoop();

    return 0;
}

