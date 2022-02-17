#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutVoxel : public FiguraGeometrica{
protected:
    int x, y, z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel(){};
    void draw(Sculptor &t);
};

#endif