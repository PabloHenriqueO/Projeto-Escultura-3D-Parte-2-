#ifndef PUTSPHERE_H_INCLUDED
#define PUTSPHERE_H_INCLUDED
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutSphere : public FiguraGeometrica{
protected:
    int xc, yc, zc, radius;
public:
    PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float a);
    ~PutSphere(){};
    void draw(Sculptor &t);

};


#endif