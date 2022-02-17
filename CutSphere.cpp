#include "CutSphere.h"
#include "FiguraGeometrica.h"

CutSphere::CutSphere (int xc_, int yc_, int zc_, int radius_){
   xc = xc_;
   yc = yc_;
   zc = zc_;
   radius = radius_;
}

void CutSphere::draw(Sculptor &t){
    double calc;
    int x,y,z;
    calc = radius*radius;
    for(x = xc - radius; x<xc + radius; x++){
        for(y = yc - radius; y<yc + radius; y++){
            for(z = zc - radius; z<zc + radius; z++){
                if(static_cast<double>(x-xc)*static_cast<double>(x+xc) +
                   static_cast<double>(y-yc)*static_cast<double>(y+yc)+
                   static_cast<double>(z-xc)*static_cast<double>(z+xc) < calc){
                    t.cutVoxel(x, y, z);
                }
            }
        }
    }
}