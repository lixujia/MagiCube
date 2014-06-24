/*
 *  GlSurface.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#include <iostream>
using namespace std;

#include "GlVertex.h"
#include "GlSurface.h"

GlSurface::GlSurface() {
	// TODO Auto-generated constructor stub

}

GlSurface::~GlSurface() {
	// TODO Auto-generated destructor stub
}

GlSurface::GlSurface(GlVertex ver0, GlVertex ver1,
                     GlVertex ver2, GlVertex ver3,
                     char const* texPath) {
	this->selfSetVertex(ver0, ver1, ver2, ver3);
	this->setSubSquares(texPath);
}

GlSurface::GlSurface(GlVertex vertex[4],char const* texPath) {
	this->selfSetVertex(vertex[0], vertex[1], vertex[2], vertex[3]);
	this->setSubSquares(texPath);
}

void GlSurface::setSubSquares(char const* texPath) {
	GlVertex tmp[16];
	GlVertex __tmp[4];
	GlVector vx;
	GlVector vy;
	int i, j;

	tmp[0] = vertex[0];
	tmp[3] = vertex[1];
	tmp[15] = vertex[2];
	tmp[12] = vertex[3];

	vx = (vertex[1] - vertex[0]) * (1.0 / 3.0);
	vy = (vertex[3] - vertex[0]) * (1.0 / 3.0);

	tmp[1] = tmp[0] + vx;
	tmp[2] = tmp[1] + vx;
	tmp[4] = tmp[0] + vy;
	tmp[5] = tmp[4] + vx;
	tmp[6] = tmp[2] + vy;
	tmp[7] = tmp[3] + vy;
	tmp[8] = tmp[12] - vy;
	tmp[9] = tmp[8] + vx;
	tmp[11] = tmp[15] - vy;
	tmp[10] = tmp[11] - vx;
	tmp[13] = tmp[12] + vx;
	tmp[14] = tmp[15] - vx;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			__tmp[0] = tmp[i * 4 + j];
			__tmp[1] = tmp[i * 4 + j + 1];
			__tmp[2] = tmp[(i + 1) * 4 + j + 1];
			__tmp[3] = tmp[(i + 1) * 4 + j];

			this->squares[0][i][j] = new GlSquare(__tmp,texPath);
		}
	}

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			this->squares[1][i][j] = this->squares[0][2 - j][i];
		}
	}
}

void GlSurface::draw() {
	int i, j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			this->squares[0][i][j]->draw();
		}
	}
}

void GlSurface::setFrontColor(GLfloat r, GLfloat g, GLfloat b) {
	int i, j;

	this->color_r = r;
	this->color_g = g;
	this->color_b = b;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			//this->squares[0][i][j]->setFrontColor(r / (GLfloat)(i * 3 + j), g/ (GLfloat)(i * 3 + j), b/ (GLfloat)(i * 3 + j));
			this->squares[0][i][j]->setFrontColor(r,g,b);
		}
	}
}

void GlSurface::transposeLeft() {
	GlSquare square;

	square = *(this->squares[0][0][0]);
	*(this->squares[0][0][0]) = *(this->squares[0][0][2]);
	*(this->squares[0][0][2]) = *(this->squares[0][2][2]);
	*(this->squares[0][2][2]) = *(this->squares[0][2][0]);
	*(this->squares[0][2][0]) = square;

	square = *(this->squares[0][0][1]);
	*(this->squares[0][0][1]) = *(this->squares[0][1][2]);
	*(this->squares[0][1][2]) = *(this->squares[0][2][1]);
	*(this->squares[0][2][1]) = *(this->squares[0][1][0]);
	*(this->squares[0][1][0]) = square;
}

void GlSurface::transposeRight() {
	GlSquare square;

	square = *(this->squares[0][0][0]);
	*(this->squares[0][0][0]) = *(this->squares[0][2][0]);
	*(this->squares[0][2][0]) = *(this->squares[0][2][2]);
	*(this->squares[0][2][2]) = *(this->squares[0][0][2]);
	*(this->squares[0][0][2]) = square;

	square = *(this->squares[0][0][1]);
	*(this->squares[0][0][1]) = *(this->squares[0][1][0]);
	*(this->squares[0][1][0]) = *(this->squares[0][2][1]);
	*(this->squares[0][2][1]) = *(this->squares[0][1][2]);
	*(this->squares[0][1][2]) = square;
}
