/**
    PCS2478 - Tópicos de Programação
    AcessoDados.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-11
*/

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

#include "globais.h"

using namespace std;

class AcessoDados{
public:
  // Construtores da classe AcessoDados
  AcessoDados();

  // Destrutor da classe empresa
  ~AcessoDados();

  // Setters e Getters
  string lerTudo(Arquivos arq, ModoAcesso modo = LEITURA);


private:
  string nomesArqs[4];
  ifstream arquivo;

  bool conectar(Arquivos arq, ModoAcesso modo);

  bool desconectar();

};
