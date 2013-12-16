/*
 *  GlObject.h
 *
 *  John Lee <lixujia.cn@gmail.com>
 *  Created on: 2010-8-31
 */

#ifndef GLOBJECT_H_
#define GLOBJECT_H_

class GlObject {
public:
	GlObject();
	virtual ~GlObject();

	virtual void draw();
};

#endif /* GLOBJECT_H_ */
