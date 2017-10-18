/**
    PCS2478 - Tópicos de Programação
    Empresa.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 5.0 2017-10-11
*/

#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "CadastroPessoas.h"
#include "ContribuicaoSindical.h"
#include "Funcionario.h"
#include "ImpostoRenda.h"
#include "TabelaSalarial.h"

using namespace std;

class Empresa{
  string nome;                      // Nome da empresa
  vector<Funcionario> funcionarios; // Vetor contendo os funcionários da emrpesa
  unsigned long maxFuncionarios;    // Tamanho do array funcionarios

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
      Solicita os dados de todas as pessoas cadastradas e contrata aquelas que
      tiverem o estado funcional "empregado" (1)

      @return true se todos os funcionários foram devidamente contratados
  */
  bool iniciarFuncionarios();

  // Imprime os dados de todos os funcionários da empresa de forma formatada
  void obterDadosFuncionarios();

  /**
      Imprime os dados de todas as pessoas contidas em cadastroPessoa de forma
      formatada
      @param filtro (int): filtra as pessoas a serem apresentadas pelo seu
                           estado funcional. deve ser -1 para apresentar todos.
  */
  void obterDadosPessoas(int filtro = -1);


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
      Retorna uma string com formato monetário correspondente ao salário de um
      determinado funcionário.

      @param idFuncional (string): o id funcional do funcionário
      @return a string formatada correspondente ao salário do funcionário
      @throw caso não exista o id funcional (domain_error)
  */
  string calcularSalario(string idFuncional);

  /**
      Obtém e processa os dados dos funcionários de uma forma menos eficiente
      para ficar de acordo com as especificações.

      @return um vector de strings contendo os dados das pessoas
  */
  vector<string> getAndSplitPessoas();

};
