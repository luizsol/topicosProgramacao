/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 2.0 2017-09-13
*/

#include "TabelaSalarial.h"
#include <iostream>

using namespace std;

// Construtores da classe TabelaSalarial
TabelaSalarial::TabelaSalarial(){
   TabelaSalarial::adicionaFaixasSalario(faixasSalario);
}

// Destrutor da classe TabelaSalarial
TabelaSalarial::~TabelaSalarial(){}

/**
    Divide uma linha formatada de faixa salarial em um vector com seus
    respectivos campos

    @param indice (unsigned long): o índice no vector this->faixasSalario da
                                   da linha a ser dividida
    @return o vector com strings correspondentes ao campo da linha de faixa
            salarial
    @throw caso o índice do array seja inválido (invalid_argument)
*/
vector<string> TabelaSalarial::splitSalario(unsigned long indice){
  if(indice >= this->faixasSalario.size()){
    throw std::invalid_argument("TabelaSalarial::splitSalario:"
                                " indice invalido");
  }

  string salario = this->faixasSalario[indice];
  vector<string> resultado;
  // Adiciona o primeiro campo (início em 0 e com 2 caracteres)
  resultado.push_back(salario.substr(0, 2));
  // Adiciona o segundo campo (início em 3 e com salario.size()-5 caracteres)
  resultado.push_back(salario.substr(3, salario.size()-5));

  return resultado;
}

////// TODOOOOOOOOOOO

/**
    Le o valor do salario associado a um determinado código da faixa salarial

    @param faixaSalario (string): o código da faixa salarial a ser obtida
    @return o valor correspondente à faixa salarial
    @throw caso a faixa salaria não exista (invalid_argument)
*/
float TabelaSalarial::lerSalario(string faixaSalario){
  for(unsigned long i = 0; i < this->faixasSalario.size(); i++){
    vector<string> salario = TabelaSalarial::splitSalario(i);
    if(salario[0].compare(faixaSalario) == 0){
      return std::stof(salario[1]);
    }
  }

  throw std::invalid_argument("TabelaSalarial::lerSalario"
                              " faixa salarial inexistente");
}

string TabelaSalarial::dadosTS(){
  return   acessoDados.lerTudo(TAB_SALARIAL);;
}
