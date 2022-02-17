#include "Interpretador.h"
#include "FiguraGeometrica.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PutBox.h"
#include "PutVoxel.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "CutBox.h"
#include "PutBox.h"
#include "CutVoxel.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include <iostream>

using namespace std;

Interpretador::Interpretador(){
}

vector <FiguraGeometrica *> Interpretador::parse(string filename){
  vector <FiguraGeometrica *> figs; //cada iteração é aramazenado no vetor
  ifstream fig; //manipulação de arquivo
  stringstream ss; //função para leitura de dados
  string s, token;

  fig.open("Figura.txt");

  if(!fig.is_open()){
    cout << "Não foi possível abrir o arquivo " << filename << endl;
    exit(0);
  }
    
  while(fig.good()){
    getline(fig, s); //pega as linhas do aquivo
    
    if(fig.good()){
      ss.clear(); //Cada iteração a variavel é limpada
      ss.str(s); 
      ss >> token; //le a primeira palavra da linha do arquivo
      
      if(ss.good()){
        if(token.compare("dim") == 0){
          ss >> dimx >> dimy >> dimz;
        }else if(token.compare("putvoxel") == 0){
          int x0, y0, z0;
          ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        }else if(token.compare("putsphere") == 0){
          int xc, yc, zc, radius;
          ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
          figs.push_back(new PutSphere(xc, yc, zc, radius, r, g, b, a));
        }else if (token.compare("cutsphere") == 0){
          int xc, yc, zc, radius;
          ss >> xc >> yc >> zc >> radius;
          figs.push_back(new CutSphere(xc, yc, zc, radius));
        }else if(token.compare("putbox") == 0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >>  y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }else if(token.compare("cutvoxel") == 0){
          int x, y, z;
          ss >> x >> y >> z;
          figs.push_back(new CutVoxel(x, y, z));
        }else if(token.compare("putellipsoid") == 0){
          int xc, yc, zc, rx, ry, rz;
          ss >> xc >> yc >> zc >> rx >> ry >> rz >>  r >> g >> b >> a;
          figs.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
        }else if (token.compare("cutellipsoid") == 0){
          int xc, yc, zc, rx, ry, rz;
          ss >> xc >> yc >> zc >> rx >> ry >> rz;
          figs.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
        }else if(token.compare("cutbox") == 0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
      }
    }
  }
  cout << "Escultura finalizada!" << endl;
  return(figs);
}

int Interpretador::getDimx(){
  return dimx;
}

int Interpretador::getDimy(){
  return dimy;
}

int Interpretador::getDimz(){
  return dimz;
}