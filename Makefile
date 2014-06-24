### Makefile --- 

## Author: Lixujia <lixujia.cn@gmail.com>
## Version: $Id: Makefile,v 0.0 16 12月 2013 09:44:14 Exp $
## Keywords: 
## X-URL: 

CC = g++

CFLAGS = -Wall
CLIBS  = -lGL -lglut -lGLU

TARGET = Cubie

all:${TARGET}

objs =  GlFloor.o       \
        GlMatrix.o	\
        GlObject.o	\
        GlPickable.o	\
        GlRectangle.o	\
        GlSquare.o	\
        GlSurface.o	\
        GlVector.o	\
        GlVertex.o	\
        MagiCube.o	\
        BackDesktop.o   \
        main.o          \
        s-list.o



${TARGET}:${objs}
	${CC} ${objs} ${CLIBS} -o ${TARGET}

clean:
	rm ${objs} ${TARGET} -f

### Makefile ends here
