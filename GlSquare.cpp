/*
 *  GlSquare.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#include <cstdlib>
#include <GL/glut.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#include "GlVector.h"
#include "GlSquare.h"

GlSquare::GlSquare() {

}

GlSquare::GlSquare(GlVertex vertex[4],char const* texPath) {
    FILE* fp = NULL;
    unsigned char data[128 * 128 * 4];

    memset(data,0xFF,sizeof(data));

    if (NULL != (fp = fopen(texPath,"rb")))
    {
        fseek(fp,54,SEEK_SET);
        fread(data,128*128*4,1,fp);
        fclose(fp);
    }

    glGenTextures(1,this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 128,128,
                 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 data);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// 线形滤波
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// 线形滤波
    
    this->setVertex(vertex);

    this->highLight = 0;
    //cout << "GlSquare constructor: " << this->pickID << endl;
}

GlSquare::~GlSquare() {
	// TODO Auto-generated destructor stub
}

void GlSquare::setHighLight(bool isHigh) {
	this->highLight = isHigh;
}

bool GlSquare::getHighLight() {
	return this->highLight;
}

void GlSquare::draw() {
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, this->texture[0]);
    
    glColor3f(color_r, color_g, color_b);
    GlRectangle::draw_rectangle(subsquare[0], subsquare[1], subsquare[2],
                                subsquare[3]);

    glFlush();
    glDisable(GL_TEXTURE_2D);
   
    if (this->highLight)
        glColor3f(1.0, 1.0, 1.0);
    else
        glColor3f(0.234, 0.234, 0.214);
    GlRectangle::draw_rectangle(vertex[0], vertex[1], subsquare[1],
                                subsquare[0]);
    GlRectangle::draw_rectangle(vertex[0], vertex[3], subsquare[3],
                                subsquare[0]);
    GlRectangle::draw_rectangle(vertex[2], vertex[1], subsquare[1],
                                subsquare[2]);
    GlRectangle::draw_rectangle(vertex[2], vertex[3], subsquare[3],
                                subsquare[2]);
}

void GlSquare::pickDraw() {
	if (false == this->sensitive) {
		return;
	}

	glColor3ub(this->pickColorR, this->pickColorG, this->pickColorB);
	GlRectangle::draw_rectangle(this->vertex[0], this->vertex[1],
			this->vertex[2], this->vertex[3]);
}

void GlSquare::setVertex(GlVertex vertex[4]) {
	GlVector tmp_vec1;
	GlVector tmp_vec2;
	GlVector tmp_vec;

	/*
	 this->vertex[0] = vertex[0];
	 this->vertex[1] = vertex[1];
	 this->vertex[2] = vertex[2];
	 this->vertex[3] = vertex[3];
	 */
	this->selfSetVertex(vertex[0], vertex[1], vertex[2], vertex[3]);

	this->subsquare[0] = vertex[0];
	this->subsquare[1] = vertex[1];
	this->subsquare[2] = vertex[2];
	this->subsquare[3] = vertex[3];

	tmp_vec1 = vertex[0] - vertex[2];
	tmp_vec2 = vertex[1] - vertex[3];

	tmp_vec = tmp_vec1 * tmp_vec2;

	this->subsquare[0] += (tmp_vec * 0.5 - tmp_vec1) * 0.03;
	this->subsquare[1] += (tmp_vec * 0.5 - tmp_vec2) * 0.03;
	this->subsquare[2] += (tmp_vec * 0.5 + tmp_vec1) * 0.03;
	this->subsquare[3] += (tmp_vec * 0.5 + tmp_vec2) * 0.03;
}

GlSquare& GlSquare::operator =(const GlSquare& square) {
	this->color_r = square.color_r;
	this->color_g = square.color_g;
	this->color_b = square.color_b;

        this->texture[0] = square.texture[0];
        
	return *this;
}
