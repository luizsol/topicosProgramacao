/**
    PCS2478 - Tópicos de Programação
    AcessoDados.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-11-01
*/

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "globais.h"

using namespace std;

class AcessoDados{
private:
  fstream arquivo;
  fstream arquivoAux;
  string nomeArquivo;
  vector<string> nomesArqs = {"cadpessoas.dat", "tabsalarial.dat", "tabir.dat",
                              "tabcs.dat"};

  /**
      Realiza a conexão com o arquivo.

      @param arquivo (Arquivos): o enum que descreve o arquivo a ser aberto.
      @param modo (ModoAcesso): o enum que descreve o modo de acesso do arquivo
        a ser aberto.
      @return true se a conexão for realizada com sucesso.
      @throw caso o arquivo não exista
      @throw caso o modo de leitura não exista
      @throw caso não seja possível abrir o arquivo
  */
  bool conectar(Arquivos arq, ModoAcesso modo);

  /**
      Realiza a desconexão do arquivo.
  */
  void desconectar();

public:
  // Construtores e destrutores
  AcessoDados();
  ~AcessoDados();

  /**
      Lê todos os dados contidos em um determinado arquivo.

      @param arq (Arquivos): a enum que determina o arquivo a ser lido.
      @return true se a string for válida, false caso contrário
  */
  string lerTudo(Arquivos arq);

  /**
      Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
      registros.

      Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
      conteúdo do arquivo de registros.

      @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada.
      @return a concatenação de todas as linhas que se enquadram no critério da
        busca.
  */
  string ler(Arquivos arq, string valChave, Campos chave);

  /**
      Retorna um vector de strings contendo os diferentes campos de uma linha.

      @param dado (string): o dado a ser processado
      @return o vetor de strings contendo os diferentes campos de uma linha.
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitDado(string dado);

  /**
      Retorna um vector de strings diferentes linhas de um arquivo.

      @param dado (string): o dado a ser processado
      @return um vector de strings diferentes linhas de um arquivo.
      @throw caso o argumento seja inválido (invalid_argument)
  */
  vector<string> splitLinha(string dado);

  /**
      Insere uma nova linha em um arquivo.

      @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
      @param registro (string): a linha a ser adicionada ao arquivo.
      @return true se a operação for bem sucedida.
  */
  bool inserir(Arquivos arq, string registro);

  /**
      Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
      registros e atualiza as linhas resultantes da busca.

      Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
      conteúdo do arquivo de registros.

      @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada na
        busca.
      @param novoValor (string): o valor que substituirá o valor a ser subscrito.
      @param campo (Campos): o enum que representa a coluna onde o novo dado será
        inserido (não precisa ser necessariamente o mesmo que foi utilizado na
        busca).
      @return true se pelo menos uma linha for atualizada.
  */
  bool atualizar(Arquivos arq, string valChave, Campos chave, string novoValor,
                 Campos campo);

  /**
      Realiza uma busca por uma chave em uma determidada coluna de um arquivo de
      registros e exclui as linhas resultantes da busca.

      Caso o valor da chave seja uma string vazia a pesquisa retornará todo o
      conteúdo do arquivo de registros.

      @param arq (Arquivos): o enum que descreve o arquivo a ser aberto.
      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada na
        busca.
      @return true se pelo menos uma linha for excluida.
  */
  bool excluir(Arquivos arq, string valChave, Campos chave);
};
