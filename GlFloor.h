/*
 *  GlFloor.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#ifndef GLFLOOR_H_
#define GLFLOOR_H_

#include "GlSurface.h"

class GlFloor {
	friend class MagiCube;
public:
	GlFloor();
	virtual ~GlFloor();

	void draw();
	void setRotatef(GLfloat angle);
	void setRotateAxis(GLfloat x,GLfloat y,GLfloat z);

	void transposePlus();
	void transposeMinus();
private:
	GlRectangle* rect1;
	GlRectangle* rect2;
	GlSquare* squares[12];

	GLfloat rotateAngle;
	GLfloat rotateX;
	GLfloat rotateY;
	GLfloat rotateZ;
};

#endif /* GLFLOOR_H_ */
