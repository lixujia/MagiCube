/*
 *  GlRectangle.cpp
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-9-1
 */

#include "GlRectangle.h"

GlRectangle::GlRectangle() {

}

GlRectangle::GlRectangle(GlVertex vertex[4]) {
    // TODO Auto-generated constructor stub
    this->selfSetVertex(vertex[0], vertex[1], vertex[2], vertex[3]);
}

GlRectangle::GlRectangle(GlVertex ver0, GlVertex ver1, GlVertex ver2,
                         GlVertex ver3) {
    this->selfSetVertex(ver0, ver1, ver2, ver3);
}

GlRectangle::~GlRectangle() {
    // TODO Auto-generated destructor stub
}

inline
void GlRectangle::selfSetVertex(GlVertex ver0, GlVertex ver1, GlVertex ver2,
                                GlVertex ver3) {
    this->vertex[0] = ver0;
    this->vertex[1] = ver1;
    this->vertex[2] = ver2;
    this->vertex[3] = ver3;
}

void GlRectangle::draw_rectangle(GlVertex& ver0, GlVertex& ver1,
                                 GlVertex& ver2, GlVertex& ver3) {
    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(ver0.getX(), ver0.getY(), ver0.getZ());
        glTexCoord2f(1.0f, 0.0f); glVertex3f(ver1.getX(), ver1.getY(), ver1.getZ());
        glTexCoord2f(1.0f, 1.0f); glVertex3f(ver2.getX(), ver2.getY(), ver2.getZ());
        glTexCoord2f(0.0f, 1.0f); glVertex3f(ver3.getX(), ver3.getY(), ver3.getZ());
            
        glEnd();
    }
}

void GlRectangle::pick_draw_rectangle(GlVertex& ver0, GlVertex& ver1,
                                      GlVertex& ver2, GlVertex& ver3) {
    glBegin(GL_QUADS);
    {
        glVertex3f(ver0.getX(), ver0.getY(), ver0.getZ());
        glVertex3f(ver1.getX(), ver1.getY(), ver1.getZ());
        glVertex3f(ver2.getX(), ver2.getY(), ver2.getZ());
        glVertex3f(ver3.getX(), ver3.getY(), ver3.getZ());
            
        glEnd();
    }
}

void GlRectangle::draw() {
    glColor3f(this->color_r, this->color_g, this->color_b);
    GlRectangle::draw_rectangle(this->vertex[0], this->vertex[1],
                                this->vertex[2], this->vertex[3]);
}

void GlRectangle::setColor3f(GLfloat r, GLfloat g, GLfloat b) {
    this->color_r = r;
    this->color_g = g;
    this->color_b = b;
}

void GlRectangle::setVertex(GlVertex vertex[4]) {
    this->vertex[0] = vertex[0];
    this->vertex[1] = vertex[1];
    this->vertex[2] = vertex[2];
    this->vertex[3] = vertex[3];
}

void GlRectangle::setVertex(GlVertex ver0, GlVertex ver1, GlVertex ver2,
                            GlVertex ver3) {
    this->vertex[0] = ver0;
    this->vertex[1] = ver1;
    this->vertex[2] = ver2;
    this->vertex[3] = ver3;
}

void GlRectangle::setFrontColor(GLfloat r, GLfloat g, GLfloat b) {
    this->color_r = r;
    this->color_g = g;
    this->color_b = b;
}

void GlRectangle::transposeLeft() {
    GlVertex tmp;

    tmp = vertex[0];

    vertex[0] = vertex[1];
    vertex[1] = vertex[2];
    vertex[2] = vertex[3];
    vertex[3] = tmp;
}

void GlRectangle::transposeRight() {
    GlVertex tmp;

    tmp = vertex[3];

    vertex[3] = vertex[2];
    vertex[2] = vertex[1];
    vertex[1] = vertex[0];
    vertex[0] = tmp;
}

GlRectangle& GlRectangle::operator =(const GlRectangle& rect) {
    this->vertex[0] = rect.vertex[0];
    this->vertex[1] = rect.vertex[1];
    this->vertex[2] = rect.vertex[2];
    this->vertex[3] = rect.vertex[3];

    this->color_r = rect.color_r;
    this->color_g = rect.color_g;
    this->color_b = rect.color_b;

    return *this;
}
