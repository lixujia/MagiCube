/* @(#)BackDesktop.h
 *
 * Created on: 24  6月 2014 13:33:01
 *     Author: Lixujia <lixujia.cn@gmail.com>
 *
 * 
 */

#ifndef _BACKDESKTOP_H
#define _BACKDESKTOP_H 1

#include "GlObject.h"
#include "GlVertex.h"
#include "GlRectangle.h"

class BackDesktop: public GlRectangle{
public:
    BackDesktop(GLfloat h,GLfloat w,GLfloat d,char const* texPath);

    void draw();
private:
    GLuint texture[1];

    GLfloat height;
    GLfloat width;
    GLfloat depth;
};

#endif /* _BACKDESKTOP_H */
