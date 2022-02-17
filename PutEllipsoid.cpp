#include "PutEllipsoid.h"
#include "FiguraGeometrica.h"

PutEllipsoid::PutEllipsoid(int xc_, int yc_, int zc_, int rx_, int ry_, int rz_, float r_, float g_, float b_, float a_){
    xc = xc_;
    yc = yc_;
    zc = zc_;
    rx = rx_;
    ry = ry_;
    rz = rz_;
    r=r_;
    g=g_;
    b=b_;
    a=a_;
}

void PutEllipsoid::draw(Sculptor &t){
    float dx,dy,dz;
    int x1 = xc-rx;
    int x2 = xc+rx;
    int y1 = yc-ry;
    int y2 = yc+ry;
    int z1 = zc-rz;
    int z2 = zc+rz;
    
    t.setColor(r,g,b,a);
    
    for(int x=x1; x<x2; x++){
        dx=((static_cast<float>(x)-xc)/rx)*((static_cast<float>(x)-xc)/rx);
        for(int y=y1; y<y2; y++){
            dy=((static_cast<float>(y)-yc)/ry)*((static_cast<float>(y)-yc)/ry);
            for (int z=z1; z<z2; z++) {
                dz=((static_cast<float>(z)-zc)/rz)*((static_cast<float>(z)-zc)/rz);
                if(dx+dy+dz<1){
                    t.putVoxel(x,y,z);
                }
            }
        }
    }
}