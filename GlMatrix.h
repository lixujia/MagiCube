/*
 *  GlMatrix.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef GLMATRIX_H_
#define GLMATRIX_H_

#include <GL/glut.h>
#include <iostream>

class GlMatrix {
public:
	GlMatrix();
	GlMatrix(GLfloat m[16]);
	GlMatrix(GLfloat angle,GLfloat x,GLfloat y,GLfloat z);

	virtual ~GlMatrix();

	GlMatrix& operator =(const GlMatrix& mat);
	GlMatrix& operator *=(const GlMatrix& mat);

	friend std::ostream& operator <<(std::ostream& os,const GlMatrix& mat);

	GLfloat* getMatrix();
private:
	GLfloat matrix[16];
};

#endif /* GLMATRIX_H_ */
