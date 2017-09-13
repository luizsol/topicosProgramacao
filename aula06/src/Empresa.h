/**
    PCS2478 - Tópicos de Programação
    Empresa.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-09-13
*/

#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#include "CadastroPessoas.h"
#include "Funcionario.h"
#include "TabelaSalarial.h"

using namespace std;

class Empresa{
  string nome;                      // Nome da empresa
  vector<Funcionario> funcionarios; // Vetor contendo os funcionários da emrpesa
  unsigned long maxFuncionarios;    // Tamanho do array funcionarios
  CadastroPessoas cadastroPessoas;  // Objeto de acesso ao cadastro de pessoas
  TabelaSalarial tabelaSalarial;    // A tabela de tradução de faixas salariais

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

  /**
      Cria e cadastra um funcionário na empresa.

      @param idFuncional (string): o ID Funcional do funcionário
      @param nome (string): o nome do funcionário
      @param endereco (string): o endereço do funcionário
      @param profissao (string): a profissão do funcionário
      @param funcao (string): a função do funcionário
      @param cargo (string): o cargo do funcionário
      @param faixaSalario (string): a faixa salarial do funcionário
      @param gratificação (string): o gratificação salarial do funcionário
      @return true se o funcionário foi criado e cadastrado, false caso contrário
      @throw caso se tente contratar mais funcionários que o limite máximo
             (domain_error)
      @throw caso se tente contratar um funcionário com um ID Funcional já
             existente (domain_error)
  */
  bool contratarFuncionario(string idPessoa, string idFuncional, string nome,
                            string profissao, string endereco, string funcao,
                            string cargo, string faixaSalario,
                            string gratificacao);

  /**
      Cadastra um funcionário na empresa de maneira interativa (via CLI)
      utilizando os dados do cadastroPessoa.

      @return true se o funcionário foi cadastrado, false caso
              contrário
      @throw caso não haja funcionario elegivel para contratacao (domain_error)
      @throw caso o ID Pessoa seja inexistente (domain_error)
      @throw caso a pessoa não esteja com o status de aguardando vaga
             (domain_error)
  */
  bool contratarFuncionario();

  /**
      Demite e apaga um funcionário da empresa.

      @param idFuncional (string): o ID Funcional do funcionário a ser demitido
      @return true se o funcionário foi demitido e apagado, false caso contrário
      @throw caso o ID Funcional seja inexistente (domain_error)
  */
  bool demitirFuncionario(string idFuncional);

  /**
      Demite e apaga um funcionário da empresa via CLI

      @return true se o funcionário foi demitido e apagado, false caso contrário
  */
  bool demitirFuncionario();

  // Demite e apaga todos funcionário da empresa.
  void demitirTodosFuncionarios();

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
      Imprime os dados de um determinado funcionário de forma formatada

      @param index (string): o índice no array de funcionários do funcionário a
                             ser impresso
  */
  void obterDadosFuncionario(int index);

  /**
      Retorna uma string com formato monetário correspondente ao salário de um
      determinado funcionário

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

  /**
      Obtém a gratificação de um determinado funcionário.

      @return a string relativa à gratificação do funcionário
  */
  string getGratificacaoFuncionario(string idFuncional);

};