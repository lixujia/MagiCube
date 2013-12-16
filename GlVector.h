/*
 *  GlVector.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef GLVECTOR_H_
#define GLVECTOR_H_

#include <GL/glut.h>
#include <iostream>

class GlVector {
	friend class GlVertex;
public:
	GlVector();
	GlVector(GLfloat x,GLfloat y,GLfloat z);

	virtual ~GlVector();

	GlVector& operator =(const GlVector& vec);
	GlVector& operator +=(const GlVector& vec);
	GlVector& operator -=(const GlVector& vec);
	GlVector  operator +(const GlVector& vec);
	GlVector  operator -(const GlVector& vec);
	GlVector  operator *(const GlVector& vec);
	GlVector  operator *(GLfloat radious);
	GlVector& operator *=(GLfloat radious);

	friend std::ostream& operator <<(std::ostream& os,const GlVector& vec);

private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

#endif /* GLVECTOR_H_ */
