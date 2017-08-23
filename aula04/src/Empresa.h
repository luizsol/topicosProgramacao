/**
    PCS2478 - Tópicos de Programação
    Empresa.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 2.0 2017-08-23
*/

#pragma once
#include <string>
#include "Funcionario.h"

using namespace std;

class Empresa{
  string nome;                  // Nome da empresa
  Funcionario ** funcionarios;  // Array contendo os funcionários da emrpesa
  int maxFuncionarios;          // Tamanho do array funcionarios

public:
  // Construtores da classe Empresa
  Empresa();
  Empresa(string nome);
  Empresa(int maxFuncionarios);
  Empresa(string nome, int maxFuncionarios);

  // Destrutor da classe empresa
  ~Empresa();

  // Setters e Getters
  string getNome();
  void setNome(string nome);

  /**
      Cria e cadastra um funcionário na empresa.

      @param idFuncional (string): o ID Funcional do funcionário
      @param nome (string): o nome do funcionário
      @param endereco (string): o endereço do funcionário
      @param profissao (string): a profissão do funcionário
      @param funcao (string): a função do funcionário
      @param cargo (string): o cargo do funcionário
      @return true se o funcionário foi criado e cadastrado, false caso
              contrário
  */
  bool contratarFuncionario(string idPessoa, string idFuncional, string nome,
                            string profissao, string endereco, string funcao,
                            string cargo, string faixaSalario);

  /**
      Cria e cadastra um funcionário na empresa via CLI

      @return true se o funcionário foi criado e cadastrado, false caso
              contrário
  */
  bool contratarFuncionarioIterativo();

  /**
      Demite e apaga um funcionário da empresa.

      @param idFuncional (string): o ID Funcional do funcionário a ser demitido
      @return true se o funcionário foi demitido e apagado, false caso contrário
  */
  bool demitirFuncionario(string idFuncional);

  /**
      Demite e apaga um funcionário da empresa via CLI

      @return true se o funcionário foi demitido e apagado, false caso contrário
  */
  bool demitirFuncionarioIterativo();

  // Demite e apaga todos funcionário da empresa.
  void demitirTodosFuncionarios();

  // Imprime os dados de todos os funcionários da empresa de forma formatada
  void obterDadosFuncionarios();

private:
  /**
      Inicializa o array de funcionários.

      @param maxFuncionarios (int): a capacidade máxima de funcionários da
                                    empresa
      @return true se a inicialização foi bem sucedida, false caso contrário
  */
  bool initFuncArray(int maxFuncionarios);

  /**
      Verifica se existe um funcionário cadastrado com um determinado ID
      Funcional

      @param idFuncional (string): o idFuncional a ser verificado
      @return true se já existe um funcionário com o idFuncional, false caso
              contrário
  */
  bool idJaCadastrado(string idFuncional);

  /**
      Determina o índice no array de funcionários de determinado funcionário

      @param idFuncional (string): o idFuncional a ser localizado
      @return o índice do array de funcionário onde o funcionário está
              armazenado ou -1 caso ele não tenha sido encontrado
  */
  int buscaIdFuncional(string idFuncional);

  /**
      Imprime os dados de um determinado funcionário de forma formatada

      @param index (string): o índice no array de funcionários do funcionário a
                             ser impresso
  */
  void obterDadosFuncionario(int index);

};