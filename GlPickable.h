/*
 *  GlPickable.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#ifndef GLPICKABLE_H_
#define GLPICKABLE_H_

#include <GL/glut.h>

class GlPickable {
public:
	GlPickable();
	virtual ~GlPickable();

	int getPickID();
	virtual void pickDraw();

	int compareDrawColor(GLubyte r,GLubyte g,GLubyte b);
protected:
	GLubyte pickColorR;
	GLubyte pickColorG;
	GLubyte pickColorB;

	int pickID;
	bool sensitive;
};

#endif /* GLPICKABLE_H_ */
