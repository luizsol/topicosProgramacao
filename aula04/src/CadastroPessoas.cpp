/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 1.0 2017-08-23
*/


#include "CadastroPessoas.h"
#include <iostream>

using namespace std;

// Construtores da classe CadastroPessoas
CadastroPessoas::CadastroPessoas(){
  string l01, l02, l03, l04, l05, lTotal;
  l01 = "0001|0021|1|Cristiana Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|\n";
  l02 = "0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|\n";
  l03 = "0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|\n";
  l04 = "0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|\n";
  l05 = "0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|\n";

  lTotal = l01 + l02 + l03 + l04 + l05;
  new CadastroPessoas(lTotal);
}

CadastroPessoas::CadastroPessoas(string cargaInicial){ // TODO
  cout << cargaInicial << endl;
}

vector<string> CadastroPessoas::splitDado(string dado){
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

bool CadastroPessoas::validarDados(string dados){
  if(dados.back() != '\n'){ // String termina em '/n'?
    return false;
  }

  vector<string> resultado;

  try { // String é parseável?
    resultado = CadastroPessoas::splitDado(dados);
  } catch (int e) {
    return false;
  }

  if(resultado.size() != 9){ // String tem 9 campos?
    return false;
  }

  try { // O estado funcional é um inteiro?
    std::stoi(resultado[2]);
  } catch (int e) {
    return false;
  }

  return true;
}

bool CadastroPessoas::adicionarDadosPessoa(string dados,
                                          bool sobrescrever){
  if(CadastroPessoas::validarDados(dados)){

    string idPessoa = CadastroPessoas::splitDado(dados)[0];
    int indice = CadastroPessoas::getIndicePessoa(idPessoa);

    if(indice == -1){ // Pessoa ainda não cadastrada
      this->dadosPessoais.push_back(dados);
      return true;
    } else if(sobrescrever) { // Pessoa já cadastrada, vamos sobrescrever
      this->dadosPessoais[indice] = dados;
      return true;
    }
  }
  return false;
}

bool CadastroPessoas::adicionarDadosPessoas(string dados,
                                           bool sobrescrever){
  vector<string> linhas;
  string linha;
  istringstream f(dados);

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  // Validando as linhas
  for(unsigned int i = 0; i < linhas.size(); i++){
    // A linha é válida?
    if(! CadastroPessoas::validarDados(linhas[i])){
      return false;
    }
    string idPessoa = CadastroPessoas::splitDado(linhas[i])[0];

    // Caso não possa sobrescrever, já existe algum usuário com esse idPessoa?
    if(!sobrescrever && CadastroPessoas::getIndicePessoa(idPessoa) != -1) {
      return false;
    }
  }

  for(unsigned int i = 0; i < linhas.size(); i++){ // Adicionando as linhas
    CadastroPessoas::adicionarDadosPessoa(linhas[i]);
  }
  return true;
}

int CadastroPessoas::getIndicePessoa(string idPessoa){
  for(unsigned int i = 0; i < this->dadosPessoais.size(); i++){
    if(CadastroPessoas::splitDado(this->dadosPessoais[i])[0] == idPessoa){
      return i;
    }
  }
  return -1;
}

string CadastroPessoas::lerDadosTodasPessoas(){
  string resultado;
  for(unsigned int i = 0; i < this->dadosPessoais.size(); i++){
    resultado += this->dadosPessoais[i];
  }
  return resultado;
}

string CadastroPessoas::lerDadosPessoa(string idPessoa){
  int indice = CadastroPessoas::getIndicePessoa(idPessoa);
  if(indice == -1){
    throw 404;
  } else {
    return this->dadosPessoais[indice];
  }

}

string CadastroPessoas::gerarLinha(string idPessoa, string idFuncional,
                                   string estadoFuncional, string nome,
                                   string profissao, string endereco,
                                   string funcao, string cargo,
                                   string faixaSalarial){
  return idPessoa + "|" + idFuncional + "|" + estadoFuncional + "|" + nome +
         "|" + profissao + "|" + endereco + "|" + funcao + "|" + cargo + "|" +
         faixaSalarial + "\n";
}

bool CadastroPessoas::atualizarDadosPessoa(string dados){
  if(!CadastroPessoas::validarDados(dados)){
    return false;
  }

  vector<string> resultado = CadastroPessoas::splitDado(dados);
  int indice = CadastroPessoas::getIndicePessoa(resultado[0]);

  if(indice != -1){
    return false;
  }

  return CadastroPessoas::adicionarDadosPessoa(dados, true);
}