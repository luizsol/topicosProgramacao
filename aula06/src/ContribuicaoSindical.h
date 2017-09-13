/**
    PCS2478 - Tópicos de Programação
    ContribuicaoSindical.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-09-13
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class ContribuicaoSindical{
  vector<string> tabelaCS;

public:
  // Construtores da classe CadastroPessoas
  ContribuicaoSindical();
  ContribuicaoSindical(string cargaInicial);

  // Destrutor da classe empresa
  ~ContribuicaoSindical();

  // Setters e Getters
  vector<string> getTabelaCS();
  void setTabelaCS(string TabelaCS);

  /**
      Determina a contribuição salarial de um funcionário baseado no seu salário
      e sua função.

      @param salario (float): o salário recebido pelo funcionário
      @param funcao (string): a função do funcionários
      @return a contribuição sindical devida pelo funcionário
  */
  float calcularCS(float salario, string funcao);

private:

};