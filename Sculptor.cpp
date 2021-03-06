#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sculptor.h"
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Alocação dinâmica de memória
    v = new Voxel**[nx];
    for (int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
    }

    for (int i = 0; i < nx; i++){
        for (int j=0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

//Destrutor para liberar a memória alocada
Sculptor::~Sculptor(){
  for(int i = 0; i < nx; i++){
    for (int j = 0; j < ny; j++){
      delete[] v[i][j];
    }
  }
  
  for (int i=0; i<nx; i++){
    delete[] v[i];
  }
  
  delete[] v;
  nx=ny=nz=0;
}
   
//Define a cor atual de desenho.
void  Sculptor::setColor (float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

//Ativa o voxel e atribui ao mesmo a cor atual de desenho.
void  Sculptor::putVoxel (int x0, int y0, int z0) {
    v[x0][y0][z0].isOn = true;
    v[x0][y0][z0].r = r;
    v[x0][y0][z0].g = g;
    v[x0][y0][z0].b = b;
    v[x0][y0][z0].a = a;

}

//Desativa o voxel na posição indicada
void  Sculptor::cutVoxel (int x0, int y0, int z0) {
    v[x0][y0][z0].isOn = false;
}

//Cria o arquivo .OFF.
void Sculptor::writeOFF(char *filename){
    int total, index;
    ofstream arquivo;
    total = 0;
    arquivo.open(filename);
    
    arquivo << "OFF\n";

    for (int i=0; i < nx; i++){
        for (int j = 0; j <ny; j++){
            for (int k=0; k <nz; k++){
              if(v[i][j][k].isOn == true){
                total++;
              }
            }
        }
    }

    arquivo << total * 8 << " " << total * 6 << " " << 0 << "\n";

    for (int i=0; i < nx; i++){
        for (int j = 0; j <ny; j++){
            for (int k=0; k <nz; k++){
              if(v[i][j][k].isOn == true){
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n" << flush;
              }
            }
        }
    }

    total = 0;

    for (int i=0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k=0; k < nz; k++){
              if(v[i][j][k].isOn == true){
                index = total*8;
                arquivo << fixed;

                arquivo << 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " << index + 1 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " << index + 7 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 0 << " " << index + 1 << " " << index + 5 << " " << index + 4 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 0 << " " << index + 4 << " " << index + 7 << " " << index + 3 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 7 << " " << index + 6 << " " << index + 2 << " " << index + 3 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " <<setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 1 << " " << index + 2 << " " << index + 6 << " " << index + 5 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                total++;
              }
            }
        }
    }

    arquivo.close();
}
