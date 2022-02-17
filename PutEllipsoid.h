#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutEllipsoid : public FiguraGeometrica{
protected:
    int xc, yc, zc, rx, ry, rz;
public:
    PutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz,
    float r, float g, float b, float a);
    void draw(Sculptor &t);
    ~PutEllipsoid(){};
};



#endif 