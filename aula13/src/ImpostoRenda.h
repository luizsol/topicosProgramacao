/**
    PCS2478 - T�picos de Programa��o
    Empresa.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)

    @version 2.0 2017-11-01
*/

#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "AcessoDados.h"

#pragma once

using namespace std;

class ImpostoRenda {
  AcessoDados acessoDados;// Objeto de acesso ao acesso dados

private:
  fstream arquivo;
  string nomeArquivo;

public:
  ImpostoRenda(string nomeArquivo);
  ImpostoRenda();
  ~ImpostoRenda();


  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha de
      dados de pessoa.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha de
              dados de pessoa
      @throw caso o argumento seja inv�lido (invalid_argument)
  */
  vector<float> splitDado(string dados);

  /**
      Calcula o imposto de renda a ser pago com base no sal�rio recebido.

      @param sal�rio (float): o sal�rio a ser utilizado no c�lculo do imposto de
        renda
      @return o imposto de renda a ser pago.
  */
  float calcularIR(float salario);


  // Le todos os dados contidos no arquivo tabir.dat
  string dadosIR();
};
