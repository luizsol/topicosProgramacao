/**
    PCS2478 - Tópicos de Programação
    ImpostoRenda.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-09-20
*/

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "AcessoDados.h"

using namespace std;

class ImpostoRenda{

public:
  // Construtores da classe ImpostoRenda
  ImpostoRenda();

  // Destrutor da classe ImpostoRenda
  ~ImpostoRenda();

  /**
      Calcula o imposto de renda com base no salário do indivídio.

      @param salarioBruto (float): o salário bruto do indivíduo
      @return o imposto de renda a ser pago pelo funcionário
  */
  float calculaIR(float salarioBruto);

private:
  string nomeArquivo;

  /**
      Busca e subdivide um daterminada linha da tabela de Imposto de Renda

      @param linha (int): o número da linha a ser buscada (começa em 0)
      @return o conteúdo da linha já subdividido em seus respectivos campos
      @throw caso a string recuperada do arquivo esteja em um formato inválido
        (domain_error)
  */
  vector<string> retrieveAndParseLine(int linha);

  /**
      Busca daterminada linha da tabela de Imposto de Renda

      @param linha (int): o número da linha a ser buscada (começa em 0)
      @return o conteúdo da linha desejada
      @throw caso não seja possível abrir o arquivo corretamente (domain_error)
      @throw caso a linha não exista (domain_error)
  */
  string retrieveLine(int linha);
};
