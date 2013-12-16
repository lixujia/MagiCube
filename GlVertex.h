/*
 *  GlVertex.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef GLVERTEX_H_
#define GLVERTEX_H_

#include <cstdlib>
#include <GL/glut.h>
#include <iostream>

#include "GlVector.h"

class GlVertex {
public:
	GlVertex();
	GlVertex(GLfloat x,GLfloat y,GLfloat z);

	GlVector  operator -(const GlVertex& ver);
	GlVertex& operator =(const GlVertex& ver);
	GlVertex& operator +=(const GlVector& vec);
	GlVertex  operator +(const GlVector& vec);
	GlVertex  operator -(const GlVector& vec);

	GLfloat getX() { return x; };
	GLfloat getY() { return y; };
	GLfloat getZ() { return z; };

	void setX(GLfloat x) { this->x = x; };
	void setY(GLfloat y) { this->y = y; };
	void setZ(GLfloat z) { this->z = z; };

	void setValue(GLfloat x,GLfloat y,GLfloat z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	friend std::ostream& operator <<(std::ostream& os,const GlVertex& ver);

	virtual ~GlVertex();

private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

#endif /* GLVERTEX_H_ */
