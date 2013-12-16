/*
 *  GlSquare.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef GLSQUARE_H_
#define GLSQUARE_H_

#include "GlObject.h"
#include "GlPickable.h"
#include "GlVertex.h"
#include "GlRectangle.h"

class GlSquare: public GlRectangle, public GlPickable {
public:
	GlSquare();
	GlSquare(GlVertex vertex[4]);
	virtual ~GlSquare();

	GlSquare& operator =(const GlSquare& square);

	void setVertex(GlVertex vertex[4]);
	void draw();
	void pickDraw();
	void setHighLight(bool isHigh);
	bool getHighLight();
private:
	bool highLight;
	GlVertex subsquare[4];
};

#endif /* GLSQUARE_H_ */
