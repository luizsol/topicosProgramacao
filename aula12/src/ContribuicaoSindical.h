/**
    PCS2478 - Tópicos de Programação
    ContribuicaoSindical.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @version 1.0 2017-09-13
*/

#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "AcessoDados.h"

using namespace std;

class ContribuicaoSindical{
  vector<string> tabelaCS;
  AcessoDados acessoDados;// Objeto de acesso ao acesso dados

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

  string dadosCS();

private:
  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha de
      dados de contribuições sindicais.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha de
              contribuições sindicais
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitDado(string dado);

  /**
      Determina a porcentagem da contribuição sindical para uma dada função.

      @param funcao (string): a função cuja contribuição sindical deve ser
        determinada
      @return a proporção (0.0 a 1.0) da contribuição sindical devida
      @throw caso a função não está registrada na tabela de contribuições
        sindicais (domain_error)
  */
  float getPorcentagemCS(string funcao);


};