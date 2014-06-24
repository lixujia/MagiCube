/* @(#)BackDesktop.cpp
 *
 * Created on: 24  6月 2014 13:47:54
 *     Author: Lixujia <lixujia.cn@gmail.com>
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "BackDesktop.h"

BackDesktop::BackDesktop(GLfloat h,GLfloat w,GLfloat d,char const* texPath)
{
    FILE* fp = NULL;
    unsigned char data[512 * 512 * 4];

    memset(data,0xFF,sizeof(data));

    if (NULL != (fp = fopen(texPath,"rb")))
    {
        fseek(fp,54,SEEK_SET);
        fread(data,512*512*4,1,fp);
        fclose(fp);
    }

    glGenTextures(1,this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 512,512,
                 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 data);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// 线形滤波
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// 线形滤波

    this->height = h;
    this->width = w;
    this->depth = d;
}

void BackDesktop::draw()
{
    GlVertex *vertex1 = NULL;
    GlVertex *vertex2 = NULL;
    GlVertex *vertex3 = NULL;
    GlVertex *vertex4 = NULL;
    
    vertex1 = new GlVertex(0 - this->width / 2,0 - this->height / 2,this->depth);
    vertex2 = new GlVertex(this->width / 2    ,0 - this->height / 2,this->depth);
    vertex3 = new GlVertex(this->width / 2    ,this->height / 2,this->depth);
    vertex4 = new GlVertex(0 - this->width / 2,this->height / 2,this->depth);

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, this->texture[0]);
    
    GlRectangle::draw_rectangle(*vertex1, *vertex2, *vertex3,*vertex4);

    glFlush();
    glDisable(GL_TEXTURE_2D);
}
