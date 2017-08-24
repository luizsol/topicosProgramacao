/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 1.0 2017-08-23
*/

#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Funcionario.h"

using namespace std;

class CadastroPessoas{
  vector<string> dadosPessoais;

public:
  // Construtores da classe CadastroPessoas
  CadastroPessoas();
  CadastroPessoas(string cargaInicial);

  // Destrutor da classe empresa
  ~CadastroPessoas();

  // Setters e Getters
  vector<string> getDadosPessoais();

  /**
      Valida uma string de dados de cadastro.

      @param dados (string): a string a ser validada
      @return true se a string for válida, false caso contrário
  */
  bool validarDados(string dados);

  /**
      Adiciona uma string de dados ao array de dados pessoais.

      @param dados (string): a string a ser adicionada
      @param sobrescrever (bool): true se a adição deve sobrescrever os dados de
                                  um usuário com o mesmo idPessoa
      @return true se a string foi adicionada, false caso contrário
  */
  bool adicionarDadosPessoa(string dados, bool sobrescrever=true);

  /**
      Adiciona uma string contendo várias strings de dados ao array de dados
      pessoais.

      @param dados (string): a string dos dados a serem adicionados
      @param sobrescrever (bool): true se a adição deve sobrescrever os dados de
                                  um usuário com o mesmo idPessoa
      @return true se todos os dados foram adicionados, false caso contrário
  */
  bool adicionarDadosPessoas(string dados, bool sobrescrever=true);

  /**
      Retorna uma string obtida pela concatenação de todos os dados no vetor de
      dados pessoais.

      @return a string resultante da concatenação de todos os dados contidos no
              vetor de dados pessoais
  */
  string lerDadosTodasPessoas();

  /**
      Retorna uma string com os dados de uma pessoa.

      @param idPessoa (string): o id da pessoa a ser buscada
      @return a string contendo os dados da pessoa
      @throw: 404 caso a pessoa não esteja cadastrada
  */
  string lerDadosPessoa(string idPessoa);

  /**
      Atualiza os dados de uma pessoa.

      @param dados (string): os novos dados a serem atualizados
      @return true se a operação foi bem sucedida, false caso contrario
  */
  bool atualizarDadosPessoa(string dados);

  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha de
      dados de pessoa.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha de
              dados de pessoa
      @throw: std::invalid_argument caso o argumento seja inválido
  */
  vector<string> splitDado(string dado);

  /**
      Determina o índice do vector dadosPessoais em que está uma linha contendo
      os dados de uma determinada pessoa.

      @param idPessoa (string): o id da pessoa a ser localizada
      @return o índice da string contida no dadosPessoais caso ela exista, -1
              caso contrário
  */
  int getIndicePessoa(string idPessoa);

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
      @return a string formatada contendo os dados da pessoa
  */
  string gerarLinha(string idPessoa, string idFuncional, string estadoFuncional,
                    string nome, string profissao, string endereco,
                    string funcao, string cargo, string faixaSalarial);

private:

};