/*
 *  GlVector.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#include <iostream>
using namespace std;

#include "GlVector.h"

GlVector::GlVector() {
	// TODO Auto-generated constructor stub

	x = 0.0;
	y = 0.0;
	z = 0.0;
}

GlVector::GlVector(GLfloat x,GLfloat y,GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

GlVector::~GlVector() {
	// TODO Auto-generated destructor stub
}

GlVector& GlVector::operator =(const GlVector& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;

	return *this;
}

GlVector GlVector::operator +(const GlVector& vec) {
	return GlVector(this->x + vec.x,this->y + vec.y,this->z + vec.z);
}

GlVector GlVector::operator -(const GlVector& vec) {
	return GlVector(this->x - vec.x,this->y - vec.y,this->z - vec.z);
}

GlVector GlVector::operator *(const GlVector& vec) {
	GLfloat x,y,z;

	x = this->y * vec.z - this->z * vec.y;
	y = this->z * vec.x - this->x * vec.z;
	z = this->x * vec.y - this->y * vec.x;

	return GlVector(x,y,z);
}

GlVector GlVector::operator *(GLfloat radious) {
	return GlVector(this->x * radious,this->y * radious,this->z * radious);
}

GlVector& GlVector::operator *=(GLfloat radious) {
	this->x *= radious;
	this->y *= radious;
	this->z *= radious;

	return *this;
}

GlVector& GlVector::operator -=(const GlVector& vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;

	return *this;
}

GlVector& GlVector::operator +=(const GlVector& vec) {
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;

	return *this;
}

std::ostream& operator <<(std::ostream& os,const GlVector& vec) {
	return os<<"<"<<vec.x<<","<<vec.y<<","<<vec.z<<">";
}
