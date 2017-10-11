/**
    PCS2478 - Tópicos de Programação
    ImpostoRenda.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-09-20
*/

#include "ImpostoRenda.h"

using namespace std;

// Construtores da classe ImpostoRenda
ImpostoRenda::ImpostoRenda(){}

// Destrutor da classe ImpostoRenda
ImpostoRenda::~ImpostoRenda(){}

/**
    Calcula o imposto de renda com base no salário do indivídio.

    @param salarioBruto (float): o salário bruto do indivíduo
    @return o imposto de renda a ser pago pelo funcionário
*/
float ImpostoRenda::calculaIR(float salarioBruto){
  vector<string> result;
  for(int i = 0; ; i++){
    result = ImpostoRenda::retrieveAndParseLine(i);
    if(salarioBruto >= stof(result[0]) && salarioBruto <= stof(result[1])){
      break;
    }
  }
  return salarioBruto * (stof(result[2]) / 100.0) - stof(result[3]);
}

/**
    Busca e subdivide um daterminada linha da tabela de Imposto de Renda

    @param linha (int): o número da linha a ser buscada (começa em 0)
    @return o conteúdo da linha já subdividido em seus respectivos campos
    @throw caso a string recuperada do arquivo esteja em um formato inválido
      (domain_error)
*/
vector<string> ImpostoRenda::retrieveAndParseLine(int linha){
  string dado = ImpostoRenda::retrieveLine(linha);
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()-1){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::domain_error("ImpostoRenda::retrieveAndParseLine:"
                                    " String invalida.");
      }
      result.push_back(dado.substr(start, i-start));
      start = i + 1;
    }
    i++;
  }
  return result;
}

/**
    Busca daterminada linha da tabela de Imposto de Renda

    @param linha (int): o número da linha a ser buscada (começa em 0)
    @return o conteúdo da linha desejada
    @throw caso não seja possível abrir o arquivo corretamente (domain_error)
    @throw caso a linha não exista (domain_error)
*/
string ImpostoRenda::retrieveLine(int linha){
  AcessoDados acessoDados;
  istringstream stream(acessoDados.lerTudo(Arquivos.IMP_RENDA));
  string line;
  for(int i = 0; i <= linha; i++){
    getline(stream, line);
  }
  return line.append("\n");
}
