/*
 *  GlPickable.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#include <iostream>
using namespace std;

#include "GlPickable.h"

GlPickable::GlPickable() {
	// TODO Auto-generated constructor stub
	static int _pick_id = 0;

	this->pickID = ++_pick_id;
	this->sensitive = true;

	this->pickColorR = this->pickID & 0xFF;
	this->pickColorG = (this->pickID >> 8) & 0xFF;
	this->pickColorB = (this->pickID >> 8) & 0xFF;

	//cout << "A PickAble object: ID = "<<this->pickID<<" is created!" << endl;
}

GlPickable::~GlPickable() {
	// TODO Auto-generated destructor stub
}

inline
int GlPickable::getPickID() {
	return this->pickID;
}

void GlPickable::pickDraw() {

}

int GlPickable::compareDrawColor(GLubyte r,GLubyte g,GLubyte b) {
	if (this->pickColorR != r)
		return this->pickColorR - r;
	if (this->pickColorG != g)
		return this->pickColorG - g;
	if (this->pickColorB != b)
		return this->pickColorB - b;

	return 0;
}






















