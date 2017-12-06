/**
    PCS2478 - Tópicos de Programação
    HorasTrabalhadas.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
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

  /**
      Lê o número de horas trabalhadas por um autônomo.

      @param idFuncional (string): o id funcional do autônomo
      @return um float representando a quantidade de horas trabalhadas.
  */
  float lerHorasTrabalhadas(string idFuncional);

  /**
      Insere um novo registro de horas trabalhadas para um autônomo.

      @param idFuncional (string): o id funcional do autonomo.
      @param horas (string): a quantidade de horas trabalhadas.
      @return true se a inserção for realizada com sucesso.
  */
  bool insereHorasTrabalhadas(string idFuncional, string horas);

  bool apagaHorasTrabalhadas(string idFuncional);

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
