/**
    PCS2478 - Tópicos de Programação
    ImpostoRenda.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 13.0 2017-11-01
*/

#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#include "AcessoDados.h"

using namespace std;

class ImpostoRenda {
public:
  // Construtores e destrutores
  ImpostoRenda();

  ~ImpostoRenda();

  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha de
      dados de pessoa.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha de
              dados de pessoa
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<float> splitDado(string dados);

  /**
      Calcula o imposto de renda a ser pago com base no salário recebido.

      @param salário (float): o salário a ser utilizado no cálculo do imposto de
        renda
      @return o imposto de renda a ser pago.
  */
  float calcularIR(float salario);


  // Le todos os dados contidos no arquivo tabir.dat
  string dadosIR();

private:
  AcessoDados acessoDados;// Objeto de acesso ao acesso dados
};
