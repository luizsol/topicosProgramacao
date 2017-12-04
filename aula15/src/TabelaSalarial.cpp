/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#include "TabelaSalarial.h"

using namespace std;

// Construtores e destrutores
TabelaSalarial::TabelaSalarial(){}

TabelaSalarial::~TabelaSalarial(){}

/**
    Le o valor do salario nominal de mensalista associado a um determinado
    código da faixa salarial.

    @param faixaSalario (string): o código da faixa salarial a ser obtida
    @return o valor correspondente à faixa salarial
    @throw caso a faixa salaria não exista (invalid_argument)
*/
float TabelaSalarial::lerSalarioMensalista(string faixaSalario){
  string salario = this->acessoDados.ler(TAB_SALARIAL, faixaSalario,
                                         C_CATSALARIAL);

  if(salario == ""){
    throw std::invalid_argument("TabelaSalarial::lerSalario"
                                " faixa salarial inexistente");
  }

  vector<string> linha_salario = TabelaSalarial::splitDado(salario);
  return std::stof(linha_salario[1]);
}

/**
    Le o valor da hora de trabalho de um autônomo associado a um determinado
    código da faixa salarial.

    @param faixaSalario (string): o código da faixa salarial a ser obtida
    @return o valor correspondente à faixa salarial
    @throw caso a faixa salaria não exista (invalid_argument)
*/
float TabelaSalarial::lerValorHora(string faixaSalario){
  string resultado = TabelaSalarial::acessoDados.ler(HORAS_AUTO, faixaSalario,
                                                     C_IDFUNCHORAS);

  if(resultado == ""){
    throw std::invalid_argument("TabelaSalarial::lerValorHora"
                                " ID Funcional inexistente");
  }

  vector<string> campos = TabelaSalarial::splitDado(resultado);

  return std::stof(campos[C_HORASTRAB]);
}

// Lê todos os dados contidos no arquivo tabsalarial.dat
string TabelaSalarial::dadosTS(){
  return acessoDados.lerTudo(TAB_SALARIAL);;
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha.
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> TabelaSalarial::splitDado(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::invalid_argument("TabelaSalarial::splitDado: "
                                    "String invalida.");
      }
      result.push_back(dado.substr(start, i - start));
      start = i + 1;
    }
    i++;
  }

  return result;
}
