/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-08-30
*/

#include "TabelaSalarial.h"
#include <iostream>

using namespace std;

// Construtores da classe TabelaSalarial
TabelaSalarial::TabelaSalarial() : TabelaSalarial(/* TODO */){}

TabelaSalarial::TabelaSalarial(vector<string> faixasSalario){}

// Destrutor da classe TabelaSalarial
TabelaSalarial::~TabelaSalarial(){}

// Setters e Getters
string TabelaSalarial::getFaixasSalario(){
  return this->faixasSalario;
}

void TabelaSalarial::setFaixasSalario(vector<string> faixasSalario){
  this->faixasSalario = faixasSalario;
}
