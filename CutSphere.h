#ifndef CUTSPHERE_H_INCLUDED
#define CUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica{
protected:
    int xc, yc, zc, radius;
public:
    CutSphere(int xc, int yc, int zc, int radius);
    void draw(Sculptor &t);
    ~CutSphere(){};
};

#endif