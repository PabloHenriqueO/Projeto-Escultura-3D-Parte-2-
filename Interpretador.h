#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "FiguraGeometrica.h"
#include "Sculptor.h"
#include <string>
#include <stdlib.h>
using namespace std;

class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador(); 
    vector<FiguraGeometrica *> parse(std::string filename); //atribui a um vetor o interpretador do arquivo
    int getDimx();
    int getDimy();
    int getDimz();
};


#endif 