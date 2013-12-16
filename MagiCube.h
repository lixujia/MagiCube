/*
 *  MagiCube.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef MAGICUBE_H_
#define MAGICUBE_H_

#include "s-list.h"
#include "GlObject.h"
#include "GlFloor.h"
#include "GlMatrix.h"
#include "GlSurface.h"

class MagiCube: public GlObject {
public:
	MagiCube();
	MagiCube(GlVertex vertex[8]);
	virtual ~MagiCube();

	void draw();

	void cubeHorizionRotate(GLfloat rot);
	void cubeVerticalRotate(GLfloat rot);

	void cubeSelectPress(int x, int y);
	void cubeSelectMotion(int x, int y);
	void cubeSelectRelease(int x, int y);
private:
	void pickDraw();
	GlSquare* pickSquare(int x, int y);
private:
	/*
	 *     +---+
	 *     |21 |
	 * +---+---+---+---+
	 * |11 |00 |10 |01 |
	 * +---+---+---+---+
	 *     |20 |
	 *     +---+
	 */
	GlSurface* surface[3][2];
	GlRectangle* rects[3][4];
	GlRectangle* __rects[3][6];

	GlFloor* floors[3][3];

	GlMatrix matSaved;

	GlSquare* pressedSquare;
	GlSquare* motionedSquare;
	GlSquare* releasedSquare;

	bool rotating;

	GLfloat rotateAngle;
	int rotateFloorM;
	int rotateFloorS;
	int rotateStep;

	int pressedBelongFloorM[2];
	int pressedBelongFloorS[2];
	int pressedIndex[2];

	SList* rotateQueue;
};

#endif /* MAGICUBE_H_ */
