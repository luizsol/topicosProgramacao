/**
    PCS2478 - Tópicos de Programação
    HorasTrabalhadas.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "globais.h"
#include "AcessoDados.h"

using namespace std;

class HorasTrabalhadas{
public:
  // Construtores e destrutores
  HorasTrabalhadas();

  ~HorasTrabalhadas();

  float lerHorasTrabalhadas(string idFuncional);

private:
  AcessoDados tabHorasTrabalhadas;

  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha.
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitDado(string dado);
};
