/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-10-10
*/

#include "CadastroPessoas.h"
#include <iostream>

using namespace std;

// Construtores da classe CadastroPessoas
CadastroPessoas::CadastroPessoas(){}

// Destrutor da classe CadastroPessoas
CadastroPessoas::~CadastroPessoas(){}

/**
    Valida uma string de dados de cadastro.

    @param dados (string): a string a ser validada
    @return true se a string for válida, false caso contrário
*/
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

  if(resultado.size() != 10){ // String tem 9 campos?
    return false;
  }

  try { // O estado funcional é um inteiro?
    std::stoi(resultado[2]);
  } catch (int e) {
    return false;
  }

  return true;
}

/**
    Retorna uma string obtida pela concatenação de todos os dados no vetor de
    dados pessoais.

    @return a string resultante da concatenação de todos os dados contidos no
            vetor de dados pessoais
*/
string CadastroPessoas::lerDadosTodasPessoas(){
  AcessoDados acessoDados;
  return acessoDados.lerTudo(CAD_PESSOAS);
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha de
    dados de pessoa.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha de
            dados de pessoa
    @throw caso o argumento seja inválido (invalid_argument)
*/
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

/**
    Gera uma linha formatada contendo os dados relativos a uma pessoa.

    @param idPessoa (string): o id da pessoa
    @param idFuncional (string): o idFuncional da pessoa
    @param estadoFuncional (string): o estado funcional da pessoa
    @param nome (string): o nome da pessoa
    @param profissao (string): a profissão da pessoa
    @param endereco (string): o endereco da pessoa
    @param funcao (string): a funcao da pessoa
    @param cargo (string): o cargo da pessoa
    @param faixaSalarial (string): a faixa salarial da pessoa
    @param gratificacao (string): a gratificação salarial da pessoa
    @return a string formatada contendo os dados da pessoa
*/
string CadastroPessoas::gerarLinha(string idPessoa, string idFuncional,
                                   string estadoFuncional, string nome,
                                   string profissao, string endereco,
                                   string funcao, string cargo,
                                   string faixaSalarial, string gratificacao){
  return idPessoa + "|" + idFuncional + "|" + estadoFuncional + "|" + nome +
         "|" + profissao + "|" + endereco + "|" + funcao + "|" + cargo + "|" +
         faixaSalarial + "|" + gratificacao + "|\n";
}
