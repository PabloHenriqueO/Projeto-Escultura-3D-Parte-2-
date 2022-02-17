#include <iostream>
#include "CutEllipsoid.h"
#include "FiguraGeometrica.h"

CutEllipsoid::CutEllipsoid(int xc_, int yc_, int zc_, int rx_, int ry_, int rz_){
   xc = xc_;
   yc = yc_;
   zc = zc_;
   rx = rx_;
   ry = ry_;
   rz = rz_;
}

void CutEllipsoid::draw(Sculptor &t){
    int x,y,z;
    double dx, dy, dz;

    for(x = xc - rx; x<xc + rx; x++){
        for(y = yc - ry; y<yc + ry; y++){
            for(z = zc - rz; z<zc + rz; z++){

                dx = (((double)(x-xc)*(double)(x-xc))/(rx*rx));
                dy = (((double)(y-yc)*(double)(y-yc))/(ry*ry));
                dz = (((double)(z-zc)*(double)(z-zc))/(rz*rz));

                if((dx + dy + dz) <=1){
                  t.cutVoxel(x, y, z);
                }
            }
        }
    }
}