/*
 *  GlRectangle.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#ifndef GLRECTANGLE_H_
#define GLRECTANGLE_H_

#include <cstdlib>
#include <GL/glut.h>

#include "GlObject.h"
#include "GlVertex.h"

class GlRectangle: public GlObject {
public:
	GlRectangle();
	GlRectangle(GlVertex vertex[4]);
	GlRectangle(GlVertex ver0, GlVertex ver1, GlVertex ver2, GlVertex ver3);

	virtual ~GlRectangle();

	void draw();
	void setColor3f(GLfloat r, GLfloat g, GLfloat b);
	void setVertex(GlVertex[4]);
	void setVertex(GlVertex ver0, GlVertex ver1, GlVertex ver2, GlVertex ver3);
	void setFrontColor(GLfloat r, GLfloat g, GLfloat b);

	virtual void transposeLeft();
	virtual void transposeRight();

	GlRectangle& operator =(const GlRectangle& rect);

	static void draw_rectangle(GlVertex& ver0, GlVertex& ver1, GlVertex& ver2,
			GlVertex& ver3);
protected:
	void selfSetVertex(GlVertex ver0, GlVertex ver1, GlVertex ver2,
			GlVertex ver3);

protected:
	GlVertex vertex[4];

	GLfloat color_r;
	GLfloat color_g;
	GLfloat color_b;
};

#endif /* GLRECTANGLE_H_ */
