/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.h

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
*/

#pragma once

#include <string>
#include <vector>

#include "AcessoDados.h"

using namespace std;

class TabelaSalarial{
public:
  // Construtores e destrutores
  TabelaSalarial();

  ~TabelaSalarial();

  /**
      Le o valor do salario associado a um determinado código da faixa salarial

      @param faixaSalario (string): o código da faixa salarial a ser obtida
      @return o valor correspondente à faixa salarial
      @throw caso a faixa salaria não exista (invalid_argument)
  */
  float lerSalario(string faixaSalario);

  // Lê todos os dados contidos no arquivo tabsalarial.dat
  string dadosTS();

  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha.
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitDado(string dado);

private:
  AcessoDados acessoDados; // Objeto de acesso ao acesso dados
};
