/*
 *  MagiCube.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#include <ctime>
#include <cstdlib>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#include "GlMatrix.h"
#include "GlSquare.h"
#include "GlVertex.h"
#include "GlVector.h"
#include "MagiCube.h"
#include "GlRectangle.h"

typedef struct _RotateOper RotateOper;
struct _RotateOper {
    int rotateSteps;
    int rotateFloorM;
    int rotateFloorS;
};

MagiCube::MagiCube() {
    // TODO Auto-generated constructor stub

}

MagiCube::MagiCube(GlVertex ver[8]) {
    GlVertex* ver2;
    GlVertex tmp_ver[4];

    int i, j;
    int lastRandFloor = 0;
        
    ver2 = ver + 4;

    this->pressedSquare = NULL;
    this->releasedSquare = NULL;

    this->rotating = false;
    this->rotateAngle = 0.0;

    this->rotateFloorM = 0;
    this->rotateFloorS = 0;

    this->rotateQueue = NULL;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            this->rects[i][j] = new GlRectangle;
            this->rects[i][j]->setColor3f(0.234, 0.234, 0.214);
        }
    }

    surface[0][0] = new GlSurface(ver[1], ver[0], ver[3], ver[2], "blue.bmp");
    surface[0][0]->setFrontColor(1.0, 0.0, 0.0);
    surface[0][1] = new GlSurface(ver2[0], ver2[1], ver2[2], ver2[3], "red.bmp");
    surface[0][1]->setFrontColor(0.0, 1.0, 0.0);

    tmp_ver[0] = ver2[0] + (ver[0] - ver2[0]) * (2.0 / 3.0);
    tmp_ver[1] = ver2[1] + (ver[1] - ver2[1]) * (2.0 / 3.0);
    tmp_ver[2] = ver2[2] + (ver[2] - ver2[2]) * (2.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver[3] - ver2[3]) * (2.0 / 3.0);

    this->rects[0][0]->setVertex(tmp_ver);
    this->rects[0][1]->setVertex(tmp_ver);

    tmp_ver[0] = ver2[0] + (ver[0] - ver2[0]) * (1.0 / 3.0);
    tmp_ver[1] = ver2[1] + (ver[1] - ver2[1]) * (1.0 / 3.0);
    tmp_ver[2] = ver2[2] + (ver[2] - ver2[2]) * (1.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver[3] - ver2[3]) * (1.0 / 3.0);

    this->rects[0][2]->setVertex(tmp_ver);
    this->rects[0][3]->setVertex(tmp_ver);

    surface[1][0] = new GlSurface(ver[1], ver2[1], ver2[0], ver[0], "green.bmp");
    surface[1][0]->setFrontColor(0.0, 0.0, 1.0);
    surface[1][1] = new GlSurface(ver2[2], ver[2], ver[3], ver2[3], "white.bmp");
    surface[1][1]->setFrontColor(1.0, 1.0, 0.0);

    tmp_ver[0] = ver2[2] + (ver2[1] - ver2[2]) * (2.0 / 3.0);
    tmp_ver[1] = ver[2] + (ver[1] - ver[2]) * (2.0 / 3.0);
    tmp_ver[2] = ver[3] + (ver[0] - ver[3]) * (2.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver2[0] - ver2[3]) * (2.0 / 3.0);

    this->rects[1][0]->setVertex(tmp_ver);
    this->rects[1][1]->setVertex(tmp_ver);

    tmp_ver[0] = ver2[2] + (ver2[1] - ver2[2]) * (1.0 / 3.0);
    tmp_ver[1] = ver[2] + (ver[1] - ver[2]) * (1.0 / 3.0);
    tmp_ver[2] = ver[3] + (ver[0] - ver[3]) * (1.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver2[0] - ver2[3]) * (1.0 / 3.0);

    this->rects[1][2]->setVertex(tmp_ver);
    this->rects[1][3]->setVertex(tmp_ver);

    surface[2][0] = new GlSurface(ver[1], ver[2], ver2[2], ver2[1], "yellow.bmp");
    surface[2][0]->setFrontColor(1.0, 0.0, 1.0);
    surface[2][1] = new GlSurface(ver[3], ver[0], ver2[0], ver2[3], "purple.bmp");
    surface[2][1]->setFrontColor(0.0, 1.0, 1.0);

    tmp_ver[0] = ver[3] + (ver[2] - ver[3]) * (2.0 / 3.0);
    tmp_ver[1] = ver[0] + (ver[1] - ver[0]) * (2.0 / 3.0);
    tmp_ver[2] = ver2[0] + (ver2[1] - ver2[0]) * (2.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver2[2] - ver2[3]) * (2.0 / 3.0);

    this->rects[2][0]->setVertex(tmp_ver);
    this->rects[2][1]->setVertex(tmp_ver);

    tmp_ver[0] = ver[3] + (ver[2] - ver[3]) * (1.0 / 3.0);
    tmp_ver[1] = ver[0] + (ver[1] - ver[0]) * (1.0 / 3.0);
    tmp_ver[2] = ver2[0] + (ver2[1] - ver2[0]) * (1.0 / 3.0);
    tmp_ver[3] = ver2[3] + (ver2[2] - ver2[3]) * (1.0 / 3.0);

    this->rects[2][2]->setVertex(tmp_ver);
    this->rects[2][3]->setVertex(tmp_ver);

    for (i = 0; i < 3; ++i) {
        this->__rects[i][0] = this->surface[i][0];
        this->__rects[i][5] = this->surface[i][1];

        for (j = 0; j < 4; ++j) {
            this->__rects[i][j + 1] = this->rects[i][j];
        }
    }

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            GlFloor* floor = new GlFloor;
            this->floors[i][j] = floor;

            floor->setRotateAxis(1 == i, 0 == i, 2 == i);

            floor->rect1 = this->__rects[i][j * 2];
            floor->rect2 = this->__rects[i][j * 2 + 1];

            floor->squares[0] = surface[(i + 1) % 3][0]->squares[0][2][j];
            floor->squares[1] = surface[(i + 1) % 3][0]->squares[0][1][j];
            floor->squares[2] = surface[(i + 1) % 3][0]->squares[0][0][j];
            floor->squares[3] = surface[(i + 2) % 3][0]->squares[0][j][0];
            floor->squares[4] = surface[(i + 2) % 3][0]->squares[0][j][1];
            floor->squares[5] = surface[(i + 2) % 3][0]->squares[0][j][2];
            floor->squares[6] = surface[(i + 1) % 3][1]->squares[0][0][2 - j];
            floor->squares[7] = surface[(i + 1) % 3][1]->squares[0][1][2 - j];
            floor->squares[8] = surface[(i + 1) % 3][1]->squares[0][2][2 - j];
            floor->squares[9] = surface[(i + 2) % 3][1]->squares[0][j][0];
            floor->squares[10] = surface[(i + 2) % 3][1]->squares[0][j][1];
            floor->squares[11] = surface[(i + 2) % 3][1]->squares[0][j][2];
        }
    }

    srand(time(NULL));
    for (i = 0; i < 40; ++i) {
        RotateOper* oper;

        oper = (RotateOper*) malloc(sizeof(RotateOper));
        oper->rotateFloorM = rand() % 3;
        if (lastRandFloor == oper->rotateFloorM)
        {
            oper->rotateFloorM = (oper->rotateFloorM + 2) % 3;
        }
        lastRandFloor = oper->rotateFloorM;
                
        oper->rotateFloorS = rand() % 3;
        oper->rotateSteps = rand() % 3;
        --oper->rotateSteps;

        this->rotating = true;

        this->rotateQueue = s_list_append(this->rotateQueue, oper);
    }
}

MagiCube::~MagiCube() {
    // TODO Auto-generated destructor stub
}

void MagiCube::draw() {
    int i;

    glMultMatrixf(this->matSaved.getMatrix());

    if (this->rotating) {
        if (1.0 < this->rotateAngle) {
            this->rotateAngle -= 2.0;
        } else if (-1.0 > this->rotateAngle) {
            this->rotateAngle += 2.0;
        } else {
            this->floors[rotateFloorM][rotateFloorS]->setRotatef(0.0);

            if (NULL == this->rotateQueue) {
                this->rotating = false;
                this->rotateStep = 0;
                this->rotateAngle = 0.0;
            } else {
                RotateOper* oper;
                void* tmp;

                this->rotateQueue = s_list_pop(this->rotateQueue, &tmp);
                oper = (RotateOper*) tmp;

                rotateFloorM = oper->rotateFloorM;
                rotateFloorS = oper->rotateFloorS;
                this->rotateAngle = oper->rotateSteps * 90;
                this->rotateStep = oper->rotateSteps;

                if (0 > this->rotateStep) {
                    for (; 0 > this->rotateStep; ++this->rotateStep) {
                        this->floors[this->rotateFloorM][this->rotateFloorS]->transposeMinus();
                    }
                } else {
                    for (; 0 < this->rotateStep; --this->rotateStep) {
                        this->floors[this->rotateFloorM][this->rotateFloorS]->transposePlus();
                    }
                }
                free(oper);

            }
        }
        this->floors[rotateFloorM][rotateFloorS]->setRotatef(rotateAngle);

    }

    for (i = 0; i < 3; ++i)
        this->floors[this->rotateFloorM][i]->draw();
}

void MagiCube::pickDraw() {
    int i, j;
    int k, l;

    glMultMatrixf(this->matSaved.getMatrix());

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; ++j) {
            for (k = 0; k < 3; ++k) {
                for (l = 0; l < 3; ++l) {
                    this->surface[i][j]->squares[0][k][l]->pickDraw();
                }
            }
        }
    }
}

void MagiCube::cubeHorizionRotate(GLfloat rot) {
    this->matSaved *= GlMatrix(rot, 0.0, 1.0, 0.0);
}

void MagiCube::cubeVerticalRotate(GLfloat rot) {
    this->matSaved *= GlMatrix(rot, 1.0, 0.0, 0.0);
}

GlSquare* MagiCube::pickSquare(int x, int y) {
    int i, j, k, l;
    //GlSquare* picked = NULL;
    GLint viewport[4];
    GLubyte pixel[3];

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    this->pickDraw();

    glGetIntegerv(GL_VIEWPORT, viewport);

    glReadPixels(x, viewport[3] - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE,
                 (void *) pixel);

    glutPostRedisplay();

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; ++j) {
            for (k = 0; k < 3; ++k) {
                for (l = 0; l < 3; ++l) {
                    if (!this->surface[i][j]->squares[0][k][l]->compareDrawColor(
                            pixel[0], pixel[1], pixel[2])) {
                        return this->surface[i][j]->squares[0][k][l];
                    }
                }
            }
        }
    }

    return NULL;
}

void MagiCube::cubeSelectPress(int x, int y) {
    int i, j, k;
    int found = 0;

    if (this->rotating)
        return;

    if (NULL != (this->pressedSquare = this->pickSquare(x, y))) {
        this->pressedSquare->setHighLight(true);
    }

    // Try to find the two floors that the pressed square belongs to.
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            for (k = 0; k < 12; ++k) {
                if (this->floors[i][j]->squares[k] == this->pressedSquare) {
                    this->pressedBelongFloorM[found] = i;
                    this->pressedBelongFloorS[found] = j;
                    this->pressedIndex[found] = k;

                    if (2 == ++found) {
                        i = 3;
                    }

                    j = 3;
                    break;
                }
            }
        }
    }
}

void MagiCube::cubeSelectMotion(int x, int y) {
    GlSquare* tmp;
    GlFloor* pFloor;

    int i, j, k;
    int found = 0;

    if (this->rotating)
        return;

    if (NULL == this->pressedSquare) {
        return;
    }

    tmp = this->pickSquare(x, y);
    if (this->motionedSquare == tmp) {
        return;
    } else if (NULL == tmp || this->pressedSquare == tmp) {
        for (i = 0; i < 12; ++i) {
            floors[rotateFloorM][rotateFloorS]->squares[i]->setHighLight(false);
        }

        this->pressedSquare->setHighLight(true);
        this->motionedSquare = tmp;

        return;
    } else {
        this->motionedSquare = tmp;
    }

    for (i = 0; i < 2; ++i) {
        pFloor = floors[pressedBelongFloorM[i]][pressedBelongFloorS[i]];

        for (j = 0; j < 12; ++j) {
            if (motionedSquare == pFloor->squares[j]) {
                int index;

                this->rotateFloorM = this->pressedBelongFloorM[i];
                this->rotateFloorS = this->pressedBelongFloorS[i];
                found = 1;

                for (k = 0; k < 12; ++k) {
                    pFloor->squares[k]->setHighLight(false);
                }

                for (k = 0; k < 12; ++k) {
                    index = (pressedIndex[i] + k) % 12;
                    pFloor->squares[index]->setHighLight(true);

                    if (index == j)
                        break;
                }

                if (k > 5) {
                    for (k = 0; k < 12; ++k) {
                        GlSquare* square;

                        square = pFloor->squares[k];
                        square->setHighLight(!square->getHighLight());
                    }

                    this->pressedSquare->setHighLight(true);
                    this->motionedSquare->setHighLight(true);
                }

                i = 2;
                break;
            }
        }
    }

    if (0 == found) {
        for (i = 0; i < 12; ++i) {
            floors[rotateFloorM][rotateFloorS]->squares[i]->setHighLight(false);
        }

        this->pressedSquare->setHighLight(true);
    }
}

void MagiCube::cubeSelectRelease(int x, int y) {
    int i;

    if (this->rotating)
        return;

    if (NULL == this->pressedSquare) {
        return;
    }

    if (NULL == (this->releasedSquare = this->pickSquare(x, y))) {
        for (i = 0; i < 12; ++i) {
            floors[rotateFloorM][rotateFloorS]->squares[i]->setHighLight(false);
        }

        this->pressedSquare = NULL;
        this->motionedSquare = NULL;

        return;
    }
    else if (this->pressedSquare == this->releasedSquare) {
        this->pressedSquare->setHighLight(false);
        this->pressedSquare = NULL;
        this->motionedSquare = NULL;
        this->releasedSquare = NULL;

        return;
    }
    else if (this->motionedSquare == this->releasedSquare) {
        int pressIndex;

        if (this->rotateFloorM == this->pressedBelongFloorM[0]) {
            pressIndex = this->pressedIndex[0];
        } else {
            pressIndex = this->pressedIndex[1];
        }

        for (i = 0; i < 12; ++i) {
            if (motionedSquare
                == floors[rotateFloorM][rotateFloorS]->squares[(i
                                                                + pressIndex) % 12]) {

                if (i > 6)
                    i -= 12;

                RotateOper* oper;

                oper = (RotateOper*) malloc(sizeof(RotateOper));
                oper->rotateFloorM = rotateFloorM;
                oper->rotateFloorS = rotateFloorS;
                oper->rotateSteps = i;

                this->rotateQueue = s_list_append(this->rotateQueue, oper);

                this->rotating = true;
                break;
            }
        }

        for (i = 0; i < 12; ++i) {
            floors[rotateFloorM][rotateFloorS]->squares[i]->setHighLight(false);
        }

    }

    this->pressedSquare = NULL;
    this->motionedSquare = NULL;
    this->releasedSquare = NULL;
}

