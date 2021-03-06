/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
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
      Le o valor do salario nominal de mensalista associado a um determinado
      código da faixa salarial.

      @param faixaSalario (string): o código da faixa salarial a ser obtida
      @return o valor correspondente à faixa salarial
      @throw caso a faixa salaria não exista (invalid_argument)
  */
  float lerSalarioMensalista(string faixaSalario);

  /**
      Le o valor da hora de trabalho de um autônomo associado a um determinado
      código da faixa salarial.

      @param faixaSalario (string): o código da faixa salarial a ser obtida
      @return o valor correspondente à faixa salarial
      @throw caso a faixa salaria não exista (invalid_argument)
  */
  float lerValorHora(string faixaSalario);

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
