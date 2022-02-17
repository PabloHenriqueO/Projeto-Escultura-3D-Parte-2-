#include <iostream>
#include "CutBox.h"
#include "CutEllipsoid.h"
#include "CutSphere.h"
#include "CutVoxel.h"
#include "FiguraGeometrica.h"
#include "PutBox.h"
#include "PutEllipsoid.h"
#include "PutSphere.h"
#include "PutVoxel.h"
#include "Sculptor.h"
#include "Interpretador.h"

using namespace std;

int main(){
    Sculptor *t_; //Criação do objeto

    Interpretador parser;

    vector <FiguraGeometrica*> figs; //Armazena cada posição da variável figs

    figs = parser.parse ("Figura.txt");

    t_ = new Sculptor (parser.getDimx(), parser.getDimy(), parser.getDimz()); //Definição das dimensões da matriz

    for (size_t i=0; i <figs.size(); i++){  //Laço que percorre figs
        figs[i] -> draw(*t_);
    }

    t_ -> writeOFF ((char*)"FiguraGeometrica.off");  //Cria o novo arquivo OFF

    for (size_t i=0; i < figs.size(); i++){
        delete figs[i];
    }
    delete t_;

    return 0;
}