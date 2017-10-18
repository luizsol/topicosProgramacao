/**
    PCS2478 - Tópicos de Programação
    ContribuicaoSindical.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @version 2.0 2017-10-11
*/

#include "ContribuicaoSindical.h"
#include <iostream>

using namespace std;

// Construtores da classe ContribuicaoSindical
ContribuicaoSindical::ContribuicaoSindical(){}

// Destrutor da classe ContribuicaoSindical
ContribuicaoSindical::~ContribuicaoSindical(){}

// Setters e Getters
vector<string> ContribuicaoSindical::getTabelaCS(){
  AcessoDados acessoDados;
  return ContribuicaoSindical::splitDado(
    acessoDados.lerTudo(CONTR_SINDICAL));
}

/**
    Determina a contribuição salarial de um funcionário baseado no seu salário
    e sua função.

    @param salario (float): o salário recebido pelo funcionário
    @param funcao (string): a função do funcionários
    @return a contribuição sindical devida pelo funcionário
*/
float ContribuicaoSindical::calcularCS(float salario, string funcao){
  return salario * ContribuicaoSindical::getPorcentagemCS(funcao);
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha de
    dados de contribuições sindicais.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha de
            contribuições sindicais
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> ContribuicaoSindical::splitDado(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()-1){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::invalid_argument("String invalida.");
      }
      result.push_back(dado.substr(start, i-start));
      start = i + 1;
    }
    i++;
  }
  return result;
}

/**
    Determina a porcentagem da contribuição sindical para uma dada função.

    @param funcao (string): a função cuja contribuição sindical deve ser
      determinada
    @return a proporção (0.0 a 1.0) da contribuição sindical devida
    @throw caso a função não está registrada na tabela de contribuições
      sindicais (domain_error)
*/
float ContribuicaoSindical::getPorcentagemCS(string funcao){
  vector<string> tabelaCS = ContribuicaoSindical::getTabelaCS();
  for(unsigned int i = 0; i < tabelaCS.size(); i++){
    vector<string> record = ContribuicaoSindical::splitDado(tabelaCS[i]);
    if(record[0].compare(funcao) == 0){
      return stof(record[1])/100.0;
    }
  }
  throw std::domain_error("ContribuicaoSindical::getPorcentagemCS: "
                          "Funcao inexistente");
}
