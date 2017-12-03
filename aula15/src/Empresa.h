/**
    PCS2478 - Tópicos de Programação
    Empresa.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Autonomo.h"
#include "CadastroPessoas.h"
#include "ContribuicaoSindical.h"
#include "Funcionario.h"
#include "HorasTrabalhadas.h"
#include "ImpostoRenda.h"
#include "Mensalista.h"
#include "TabelaSalarial.h"

using namespace std;

class Empresa{
public:
  // Construtores e destrutores
  Empresa();

  Empresa(string nome);

  Empresa(int maxFuncionarios);

  Empresa(string nome, int maxFuncionarios);

  ~Empresa();

  // Setters e Getters
  string getNome();
  void setNome(string nome);

  /**
      Solicita os dados de todas as pessoas cadastradas e contrata aquelas que
      tiverem o estado funcional "empregado" (1).

      @return true se todos os funcionários foram devidamente contratados
  */
  bool iniciarFuncionarios();

  /**
      Cria e cadastra um funcionário na empresa.

      @param idPessoa (string): o ID Pessoal do funcionário
      @param idFuncional (string): o ID Funcional do funcionário
      @param nome (string): o nome do funcionário
      @param endereco (string): o endereço do funcionário
      @param profissao (string): a profissão do funcionário
      @param funcao (string): a função do funcionário
      @param cargo (string): o cargo do funcionário
      @param faixaSalario (string): a faixa salarial do funcionário
      @param gratificação (string): o gratificação salarial do funcionário
      @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
        "2"=Autônomo)
      @return true se o funcionário foi criado e cadastrado, false caso
        contrário
      @throw caso se tente contratar mais funcionários que o limite máximo
             (domain_error)
      @throw caso se tente contratar um funcionário com um ID Funcional já
             existente (domain_error)
  */
  bool contratarFuncionario(string idPessoa, string idFuncional, string nome,
    string profissao, string endereco, string funcao, string cargo,
    string faixaSalario, string gratificacao, string tipoFuncionario);

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
      Imprime os dados de todas as pessoas contidas em cadastroPessoa utilizando
      um filtro.

      @param filtro (int): o filtro a ser utilizado.
  */
  void obterDadosPessoas(int filtro = -1);

  /**
      Apresenta as informações sobre a remuneração de um determinado
      funcionário.

      @throw caso não exista o id funcional inserido pelo usuário (domain_error)
  */
  void calcularSalarioLiquido();

  /**
      Obtém todos os dados contidos em um determinado arquivo.

      0 -> cadastropessoas.dat
      1 -> tabsalarial.dat
      2 -> tabcs.dat
      3 -> tabir.dat

      @return o conteúdo do arquivo selecionado.
      @throw caso o argumento seja inválido (invalid_argument)
  */
  string obterDadosArquivo(int idArquivo);

  // Imprime os dados de todos os funcionários de forma ordenada.
  void obterDadosOrdenadosFunc();

  /**
      Imprime os dados de uma ou mais pessoas registradas no arquivo
      cadpessoas.dat

      @param valChave (string): o valor a ser buscado na coluna do arquivo de
        registros.
      @param chave (Campos): o enum que representa a coluna a ser avaliada.
  */
  void obterDadosPessoasEspecificas(string valorChave, Campos chave);

  /**
      Contrata uma pessoa já registrado no arquivo de cadastro de pessoas.

      @param idPessoal (string): o id pessoal da pessoa a ser contratada.
      @param idFuncional (string): o novo id funcional a ser atribuido à pessoa
        contratada.
      @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
        "2"=Autônomo)
      @return true se a pessoa for contratada com sucesso.
  */
  bool contratarFuncCadastrado(string idPessoal, string idFuncional,
                               string tipoFuncionario);

  /**
      Insere uma nova pessoa no arquivo de cadastro de pessoas.

      A pessoa inserida terá o idFuncional 0000, estado funcional 2 e a
      gratificação 0.

      @param idPessoal (string): o id da pessoa
      @param nome (string): o nome da pessoa
      @param profissao (string): a profissão da pessoa
      @param endereco (string): o endereco da pessoa
      @param funcao (string): a funcao da pessoa
      @param cargo (string): o cargo da pessoa
      @param faixaSalarial (string): a faixa salarial da pessoa
      @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
        "2"=Autônomo)
      @return true se a pessoa for inserida com sucesso
  */
  bool inserirPessoaCadastro(string idPessoal, string nome, string profissao,
    string endereco, string funcao, string cargo, string faixaSalarial,
    string tipoFuncionario);

  /**
      Retorna todos os dados contidos no arquivo cadpessoas.dat

      @return a string contendo todos os dados contidos no arquivo
        cadpessoas.dat
  */
  string lerDadosTodasPessoas();

  /**
      Retorna os dados de todos os funcionários listados no arquivo
      cadpessoas.dat

      @return a concatenação de todas as linhas que representam funcionários.
  */
  string lerDadosFunc();

  /**
      Divide um texto contendo múltiplas linhas em um vector em que cada
      elemento corresponde a uma linha.

      @param input (string): o texto a ser dividido
      @return um vector contendo as diferente linhas da entrada
  */
  vector<string> SplitPessoas(string input);

  /**
      Divide uma linha contendo dado de pessoa em um vector contendo os
      diferentes campos dessa linha.

      @param input (string): a linha a ser dividida
      @return um vector contendo os diferentes campos da entrada
  */
  vector<string> SplitPessoa(string input);

  /**
      Imprime as informações de uma string contendo os dados de uma pessoa.

      @param input (string): a linha contendo os dados de uma pessoa.
  */
  void displayPessoa(string linha);

  /**
      Realiza uma busca por uma pessoa contendo um determinado id pessoal e a
      exclui do registro de pessoas.

      @param idPessoal (string): o id pessoa da pessoa a ser excuída.
      @return true se pelo menos uma linha for excluida.
  */
  bool excluirPessoa(string idPessoal);

  // Apresenta a folha de pagamento da empresa
  void emitirFolhaPagamento();

private:
  string nome;                      // Nome da empresa
  vector<Funcionario*> funcionarios;// Vetor contendo os funcionários da empresa
  unsigned long maxFuncionarios;    // Tamanho do array funcionarios
  CadastroPessoas cadastroPessoas;
  TabelaSalarial tabelaSalarial;
  ContribuicaoSindical contribuicaoSindical;
  ImpostoRenda impostoRenda;
  HorasTrabalhadas horasTrabalhadas;

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

  /**
      Obtém a gratificação de um determinado funcionário.

      @return a string relativa à gratificação do funcionário
  */
  string getGratificacaoFuncionario(string idFuncional);

  /**
      Imprime os dados salariais do de um determinado funcionário

      @param idFuncional (string): o ID funcional do funcionário
  */
  vector<float> getValoresSalariais(string idFuncional);
};
