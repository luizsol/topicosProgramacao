/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-11
*/

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "AcessoDados.h"

using namespace std;

class CadastroPessoas{
public:
  // Construtores da classe CadastroPessoas
  CadastroPessoas();

  // Destrutor da classe empresa
  ~CadastroPessoas();

  /**
      Valida uma string de dados de cadastro.

      @param dados (string): a string a ser validada
      @return true se a string for válida, false caso contrário
  */
  bool validarDados(string dados);

  /**
      Adiciona uma string contendo várias strings de dados ao array de dados
      pessoais.

      @param dados (string): a string dos dados a serem adicionados
      @param sobrescrever (bool): true se a adição deve sobrescrever os dados de
                                  um usuário com o mesmo idPessoa
      @return true se todos os dados foram adicionados, false caso contrário
      @throw caso sejam passados dados inválidos (invalid_argument)
      @throw caso outro cadastro já possua esse ID Pessoa (domain_error)
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
      Retorna um vector de strings contendo os diferentes campos de uma linha de
      dados de pessoa.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha de
              dados de pessoa
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitDado(string dado);

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
  string gerarLinha(string idPessoa, string idFuncional, string estadoFuncional,
                    string nome, string profissao, string endereco,
                    string funcao, string cargo, string faixaSalarial,
                    string gratificacao);

private:

};
