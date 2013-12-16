/*
 *  GlFloor.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#include <cstring>
#include <iostream>
using namespace std;

#include "GlFloor.h"

GlFloor::GlFloor() {
	// TODO Auto-generated constructor stub
	this->rect1 = NULL;
	this->rect2 = NULL;
	memset(this->squares, 0, sizeof(this->squares));

	this->rotateAngle = 0.0;

	this->rotateX = 1.0;
	this->rotateY = 0.0;
	this->rotateZ = 0.0;
}

GlFloor::~GlFloor() {
	// TODO Auto-generated destructor stub
}

void GlFloor::draw() {
	int i;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	if (-0.001 > this->rotateAngle || 0.001 < this->rotateAngle) {
		glRotatef(this->rotateAngle, this->rotateX, this->rotateY,
				this->rotateZ);
	}

	this->rect1->draw();
	this->rect2->draw();

	for (i = 0; i < 12; ++i) {
		if (NULL == this->squares[i])
			continue;

		this->squares[i]->draw();
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void GlFloor::setRotatef(GLfloat angle) {
	this->rotateAngle = angle;
}

void GlFloor::setRotateAxis(GLfloat x, GLfloat y, GLfloat z) {
	this->rotateX = x;
	this->rotateY = y;
	this->rotateZ = z;
}

void GlFloor::transposePlus() {
	GlSquare tmp;
	int i, j;

	for (i = 0; i < 3; ++i) {
		tmp = *(this->squares[9 + i]);
		for (j = 3; j > 0; --j) {
			*(this->squares[j * 3 + i]) = *(this->squares[j * 3 - 3 + i]);
		}
		*(this->squares[i]) = tmp;
	}

	this->rect2->transposeRight();
	this->rect1->transposeLeft();
}

void GlFloor::transposeMinus() {
	GlSquare tmp;
	int i, j;

	for (i = 0; i < 3; ++i) {
		tmp = *(this->squares[i]);
		for (j = 0; j < 3; ++j) {
			*(this->squares[j * 3 + i]) = *(this->squares[j * 3 + 3 + i]);
		}
		*(this->squares[9 + i]) = tmp;
	}

	this->rect2->transposeLeft();
	this->rect1->transposeRight();
}

