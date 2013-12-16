/*
 *  GlVertex.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#include "GlVertex.h"

GlVertex::GlVertex() {
	// TODO Auto-generated constructor stub
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

GlVertex::GlVertex(GLfloat x,GLfloat y,GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

GlVertex::~GlVertex() {
	// TODO Auto-generated destructor stub
}

GlVector  GlVertex::operator -(const GlVertex& ver) {
	return GlVector(this->x - ver.x,this->y - ver.y,this->z - ver.z);
}

GlVertex& GlVertex::operator =(const GlVertex &ori) {
	this->x = ori.x;
	this->y = ori.y;
	this->z = ori.z;

	return *this;
}

GlVertex& GlVertex::operator +=(const GlVector& vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;

	return *this;
}

GlVertex  GlVertex::operator +(const GlVector& vec) {
	return GlVertex(this->x + vec.x,this->y + vec.y,this->z + vec.z);
}

GlVertex  GlVertex::operator -(const GlVector& vec) {
	return GlVertex(this->x - vec.x,this->y - vec.y,this->z - vec.z);
}

std::ostream& operator <<(std::ostream& os,const GlVertex& ver) {
	return os<<"("<<ver.x<<","<<ver.y<<","<<ver.z<<")";
}
