/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-10-01
*/

#include "TabelaSalarial.h"

using namespace std;

// Construtores da classe TabelaSalarial
TabelaSalarial::TabelaSalarial(){}

// Destrutor da classe TabelaSalarial
TabelaSalarial::~TabelaSalarial(){}

// Setters e Getters
vector<string> TabelaSalarial::getFaixasSalario(){
  vector<string> lines;
  string line;
  AcessoDados acessoDados;
  istringstream stream(acessoDados.lerTudo(TAB_SALARIAL));
  while(getline(stream, line)){
    line.append("\n");
    lines.push_back(line);
  }
  return lines;
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
  string salario = TabelaSalarial::getFaixasSalario()[indice];
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
  vector<string> faixasSalario = TabelaSalarial::getFaixasSalario();
  for(unsigned long i = 0; i < faixasSalario.size(); i++){
    vector<string> salario = TabelaSalarial::splitSalario(i);
    if(salario[0].compare(faixaSalario) == 0){
      return std::stof(salario[1]);
    }
  }

  throw std::invalid_argument("TabelaSalarial::lerSalario"
                              " faixa salarial inexistente");
}
