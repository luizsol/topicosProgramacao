/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.h

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
*/

#pragma once

#include <string>
#include <vector>

#include "AcessoDados.h"

using namespace std;

class CadastroPessoas {
public:
  // Construtores e Destrutores
  CadastroPessoas();

  ~CadastroPessoas();

  /**
      Retorna todos os dados contidos no arquivo cadpessoas.dat

      @return a string contendo todos os dados contidos no arquivo
        cadpessoas.dat
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
      Realiza uma busca por uma chave em uma determidada coluna do arquivo de
      cadastro de pessoas.

      Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
      conteúdo do arquivo.

      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada.
      @return a concatenação de todas as linhas que se enquadram no critério da
        busca.
  */
  string lerDadosPessoas(string valorChave, Campos chave);

  /**
      Retorna todos os dados contidos no arquivo cadpessoas.dat

      @return a string contendo todos os dados contidos no arquivo
        cadpessoas.dat
  */
  string dadosCP();

  /**
      Realiza uma busca por uma chave em uma determidada coluna do arquivo de
      cadastro de pessoas e atualiza as linhas resultantes da busca.

      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada na
        busca.
      @param novoValor (string): o valor que substituirá o valor a ser
        subscrito.
      @param campo (Campos): o enum que representa a coluna onde o novo dado
        será inserido (não precisa ser necessariamente o mesmo que foi utilizado
        na busca).
      @return true se pelo menos uma linha for atualizada.
  */
  bool atualizarDadosPessoas(string valChave, Campos chave, string novoValor,
                             Campos campo);

  /**
      Insere uma nova linha no arquivo de cadastro de pessoas.

      @param registro (string): a linha a ser adicionada ao arquivo.
      @return true se a operação for bem sucedida.
  */
  bool inserir(string idPessoal, string idFuncional, string estadoFuncional,
    string nome, string profissao, string endereco, string funcao, string cargo,
    string faixaSalarial, string gratificacao);

  /**
      Realiza uma busca por uma pessoa contendo um determinado id pessoal e a
      exclui do registro.

      @param idPessoal (string): o id pessoa da pessoa a ser excuída.
      @return true se pelo menos uma linha for excluida.
  */
  bool excluirPessoa(string idPessoal);

  /**
      Gera uma linha formatada contendo os dados relativos a uma pessoa.

      @param idPessoal (string): o id da pessoa
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
  string gerarLinha(string idPessoal, string idFuncional,
    string estadoFuncional, string nome, string profissao, string endereco,
    string funcao, string cargo, string faixaSalarial, string gratificacao);

private:
  AcessoDados acessoDados;  // Objeto de acesso ao acesso dados
};
