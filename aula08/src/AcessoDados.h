/**
    PCS2478 - Tópicos de Programação
    AcessoDados.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-10
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
  string lerTudo(Arquivos arq, ModosAcesso modo = ModosAcesso.LEITURA);


private:
  string[4] nomesArqs;
  ifstream arquivo;

  bool conectar(Arquivos arq, ModosAcesso modo);

  bool desconectar();

};
