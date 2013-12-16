/*
 *  GlMatrix.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

#include "GlMatrix.h"

#ifdef _WIN32
#define M_PI        3.14159265358979323846
#endif

GlMatrix::GlMatrix() {
	// TODO Auto-generated constructor stub
	memset(this->matrix, 0, sizeof(GLfloat) * 16);

	this->matrix[0] = 1;
	this->matrix[5] = 1;
	this->matrix[10] = 1;
	this->matrix[15] = 1;
}

GlMatrix::GlMatrix(GLfloat m[16]) {
	memcpy(this->matrix, m, sizeof(GLfloat) * 16);
}

GlMatrix::GlMatrix(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	GLfloat* mat = this->matrix;
	float radious;

	memset(mat, 0, sizeof(float) * 16);
	radious = M_PI * angle / 180.0;

	if (-0.01 > x || 0.01 < x) {
		mat[0] = 1.0;
		mat[15] = 1.0;

		mat[5] = cosf(radious);
		mat[6] = sinf(radious);
		mat[9] = 0 - mat[6];
		mat[10] = mat[5];
	} else if (-0.01 > y || 0.01 < y) {
		mat[5] = 1.0;
		mat[15] = 1.0;

		mat[0] = cosf(radious);
		mat[8] = sinf(radious);
		mat[2] = 0 - mat[8];
		mat[10] = mat[0];
	} else if (-0.01 > z || 0.01 < z) {
		mat[10] = 1.0;
		mat[15] = 1.0;

		mat[0] = cosf(radious);
		mat[4] = sinf(radious);
		mat[1] = 0 - mat[4];
		mat[5] = mat[0];
	} else {
		mat[0] = mat[5] = mat[10] = mat[15] = 1.0;
	}
}

GlMatrix::~GlMatrix() {
	// TODO Auto-generated destructor stub
}

GlMatrix& GlMatrix::operator =(const GlMatrix& mat) {
	memcpy(this->matrix, mat.matrix, 16);

	return *this;
}

GlMatrix& GlMatrix::operator *=(const GlMatrix& mat) {
	GLfloat tmp[16];
	int o_r;
	int m_c;
	int i;

	memset(tmp, 0, sizeof(tmp));

	for (o_r = 0; o_r < 4; ++o_r) {
		for (m_c = 0; m_c < 4; ++m_c) {
			for (i = 0; i < 4; ++i) {
				tmp[o_r * 4 + m_c] += this->matrix[o_r * 4 + i] * mat.matrix[i * 4 + m_c];
			}
		}
	}

	memcpy(this->matrix,tmp,sizeof(tmp));

	return *this;
}

std::ostream& operator <<(std::ostream& os, const GlMatrix& mat) {
	return os << endl << mat.matrix[0] << "\t" << mat.matrix[1] << "\t"
			<< mat.matrix[2] << "\t" << mat.matrix[3] << endl << mat.matrix[4]
			<< "\t" << mat.matrix[5] << "\t" << mat.matrix[6] << "\t"
			<< mat.matrix[7] << endl << mat.matrix[8] << "\t" << mat.matrix[9]
			<< "\t" << mat.matrix[10] << "\t" << mat.matrix[11] << endl
			<< mat.matrix[12] << "\t" << mat.matrix[13] << "\t"
			<< mat.matrix[14] << "\t" << mat.matrix[15] << endl;
}

GLfloat* GlMatrix::getMatrix() {
	return this->matrix;
}
