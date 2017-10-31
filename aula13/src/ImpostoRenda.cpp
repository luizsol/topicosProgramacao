/**
    PCS2478 - Tópicos de Programação
    ImpostoRenda.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 13.0 2017-11-01
*/

#include "ImpostoRenda.h"

using namespace std;

// Construtores e Destrutores
ImpostoRenda::ImpostoRenda(){}

ImpostoRenda::~ImpostoRenda(){}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha de
    dados de pessoa.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha de
            dados de pessoa
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<float> ImpostoRenda::splitDado(string dados){
  vector<float> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while (i < dados.length()) {
    if (dados.at(i) == '|') {
      if (start == i) {
        throw std::invalid_argument("String invalida.");
      }
      result.push_back(stof(dados.substr(start, i - start)));
      start = i + 1;
    }
    i++;
  }

  return result;
}

/**
    Calcula o imposto de renda a ser pago com base no salário recebido.

    @param salário (float): o salário a ser utilizado no cálculo do imposto de
      renda
    @return o imposto de renda a ser pago.
*/
float ImpostoRenda::calcularIR(float salario){
  string linha = "";
  istringstream arquivo(ImpostoRenda::dadosIR());

  while(std::getline(arquivo, linha)) {
    vector<float> vlinha = splitDado(linha);
    if (salario >= vlinha[0]) {
      if (salario <= vlinha[1]) {
        return salario * vlinha[2]/100 - vlinha[3];
      }
    }
  }
  throw std::invalid_argument("ImpostoRenda::calcularIR: "
                              "Salario invalido.");
}

// Le todos os dados contidos no arquivo tabir.dat
string ImpostoRenda::dadosIR(){
  return acessoDados.lerTudo(IMP_RENDA);
}
