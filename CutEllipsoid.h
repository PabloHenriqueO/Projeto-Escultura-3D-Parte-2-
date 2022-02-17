#ifndef CUTELLIPSOID_H_INCLUDED
#define CUTELLIPSOID_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutEllipsoid : public FiguraGeometrica{
protected:
    int xc, yc, zc, rx, ry, rz;
public:
    CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);
    ~CutEllipsoid(){};
    void draw(Sculptor &t);
};

#endif