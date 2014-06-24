/*
 *  GlSurface.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#ifndef GLSURFACE_H_
#define GLSURFACE_H_

#include "GlRectangle.h"
#include "GlSquare.h"

class GlSurface: public GlRectangle {
	friend class MagiCube;
public:
	GlSurface();
	GlSurface(GlVertex vertex[4],char const* texPath);
	GlSurface(GlVertex ver0, GlVertex ver1, GlVertex ver2, GlVertex ver3,char const* texPath);
	virtual ~GlSurface();
	void transposeLeft();
	void transposeRight();

	void setFrontColor(GLfloat r, GLfloat g, GLfloat b);

	void draw();
private:
	void setSubSquares(char const* texPath);

	GlSquare* squares[2][3][3];
};

#endif /* GLSURFACE_H_ */
