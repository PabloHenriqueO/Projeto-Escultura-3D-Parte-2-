#include <iostream>
#include "PutSphere.h"
#include "FiguraGeometrica.h"

PutSphere::PutSphere(int xc_, int yc_, int zc_, int radius_, float r_, float g_, float b_, float a_){

   xc = xc_;
   yc = yc_;
   zc = zc_;
   radius = radius_;
   r = r_;
   g = g_;
   b = b_;
   a = a_;
}

void PutSphere::draw(Sculptor &t){
    int x,y,z;
    double dx, dy, dz;
    t.setColor(r,g,b,a);

    for(x = xc - radius; x<xc + radius; x++){
        for(y = yc - radius; y<yc + radius; y++){
            for(z = zc - radius; z<zc + radius; z++){
              
                dx = ((double)(x-xc)*(double)(x-xc));
                dy = ((double)(y-yc)*(double)(y-yc));
                dz = ((double)(z-zc)*(double)(z-zc));

                if((dx + dy + dz) < (radius*radius)){
                    t.putVoxel(x, y, z);
                }
            }
        }
    }
}