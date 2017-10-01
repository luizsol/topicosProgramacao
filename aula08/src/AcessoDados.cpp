/**
    PCS2478 - Tópicos de Programação
    AcessoDados.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-01
*/

#include "AcessoDados.h"
#include <iostream>

using namespace std;

// Construtores da classe AcessoDados
AcessoDados::AcessoDados(){}

AcessoDados::AcessoDados(string dados){
  AcessoDados::adicionarDadosPessoas(dados);
}

// Destrutor da classe AcessoDados
AcessoDados::~AcessoDados(){
}
