/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-08-30
*/

#include "TabelaSalarial.h"
#include <iostream>

using namespace std;

// Construtores da classe TabelaSalarial
TabelaSalarial::TabelaSalarial() : TabelaSalarial(
  "01|390.00|\n"
  "02|460.00|\n"
  "03|800.00|\n"
  "04|1400.00|\n"
  "05|2300.00|\n"
  "06|2850.00|\n"
  "07|4600.00|\n"
  "08|6000.00|\n"
  "09|9000.00|\n"
){}

TabelaSalarial::TabelaSalarial(string faixasSalario){
   TabelaSalarial::adicionaFaixasSalario(faixasSalario);
}

// Destrutor da classe TabelaSalarial
TabelaSalarial::~TabelaSalarial(){}

// Setters e Getters
vector<string> TabelaSalarial::getFaixasSalario(){
  return this->faixasSalario;
}

void TabelaSalarial::setFaixasSalario(vector<string> faixasSalario){
  this->faixasSalario = faixasSalario;
}

/**
    Adiciona uma linha de faixa salarial.

    @param linhaFaixaSalario (string): a linha formatada de faixa salarial
                                       a ser adiciona
    @throw caso a linhaFaixaSalario seja inválida (invalid_argument)
*/
void TabelaSalarial::adicionaFaixaSalario(string linhaFaixaSalario){
  if(!TabelaSalarial::validaStringFaixaSalario(linhaFaixaSalario)){
    throw std::invalid_argument("TabelaSalarial::adicionaFaixaSalario:"
                                  " linha invalida");
  }

  this->faixasSalario.push_back(linhaFaixaSalario);
}

/**
    Adiciona várias linhas de faixa salarial.

    @param linhasFaixaSalario (string): as linhas formatadas de faixas salariais
                                        a serem adicionas
    @throw caso uma das linhas de linhasFaixaSalario seja inválida
           (invalid_argument)
*/
void TabelaSalarial::adicionaFaixasSalario(string linhasFaixaSalario){
  vector<string> linhas;
  string linha;
  istringstream f(linhasFaixaSalario);

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  // Validando as linhas
  for(unsigned int i = 0; i < linhas.size(); i++){
    // A linha é válida?
    if(! TabelaSalarial::validaStringFaixaSalario(linhas[i])){
      throw std::invalid_argument("TabelaSalarial::adicionaFaixasSalario"
                                  " dados invalidos");
    }
  }

  for(unsigned int i = 0; i < linhas.size(); i++){ // Adicionando as linhas
    TabelaSalarial::adicionaFaixaSalario(linhas[i]);
  }
}

/**
    Valida uma linha formatada de faixa salarial.

    @param linhaFaixaSalario (string): a linha formatada de faixa salarial
                                       a ser validada
    @return true se a linha estiver em um formato válido, false caso contrário
*/
bool TabelaSalarial::validaStringFaixaSalario(string linhaFaixaSalario){
  // Formato padrão:
  // 01|390.00|\n
  if(linhaFaixaSalario.at(2) != '|'){
    return false;
  }

  if(linhaFaixaSalario.back() != '\n'){
    return false;
  }

  if(linhaFaixaSalario.at(linhaFaixaSalario.size()-2) != '|'){
    return false;
  }

  try{
    std::stof(linhaFaixaSalario.substr(3, linhaFaixaSalario.size()-5));
  } catch(logic_error& ex){
    return false;
  }

  return true;
}

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