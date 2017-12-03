/**
    PCS2478 - Tópicos de Programação
    Funcionario.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#pragma once

#include <string>
#include <vector>

#include "CadastroPessoas.h"

using namespace std;

class Funcionario{
public:
  // Construtores da classe Funcionario
  Funcionario(string idFuncional);
  Funcionario(string idPessoa, string idFuncional, string nome,
    string profissao, string endereco, string funcao, string cargo,
    string faixaSalario, string gratificacao, string tipoFuncionario);

  // Setters e Getters
  string getIdPessoa(bool doArquivo = false);
  bool setIdPessoa(string idPessoal, bool noArquivo = false);

  string getIdFuncional();
  bool setIdFuncional(string idFuncional);

  string getNome(bool doArquivo = false);
  bool setNome(string nome, bool noArquivo = false);

  string getProfissao(bool doArquivo = false);
  bool setProfissao(string profissao, bool noArquivo = false);

  string getEndereco(bool doArquivo = false);
  bool setEndereco(string endereco, bool noArquivo = false);

  string getFuncao(bool doArquivo = false);
  bool setFuncao(string funcao, bool noArquivo = false);

  string getCargo(bool doArquivo = false);
  bool setCargo(string cargo, bool noArquivo = false);

  string getFaixaSalario(bool doArquivo = false);
  bool setFaixaSalario(string faixaSalario, bool noArquivo = false);

  string getGratificacao(bool doArquivo = false);
  bool setGratificacao(string gratificacao, bool noArquivo = false);

  string getTipoFuncionario(bool doArquivo = false);
  bool setTipoFuncionario(string tipoFuncionario, bool noArquivo = false);

  /**
      Lê a linha no cadastro de pessoas associada a este funcionário.

      @return a linha no cadastro de pessoas associada a este funcionário.
  */
  string getLinhaFuncionario();

  /**
      Lê a linha no cadastro de pessoas associada a este funcionário e retorna
      os diferentes campos.

      @return os campos da linha no cadastro de pessoas associada a este
        funcionário.
  */
  vector<string> getCamposFuncionario();

  /**
      Determina o salário mensal do funcionário.

      @return o salário nominal do funcionário.
  */
  virtual float calcularRemuneracao();

protected:
  string idPessoal;
  string idFuncional;               // ID Funcional do funcionário
  string nome;
  string profissao;
  string endereco;
  string funcao;
  string cargo;
  string faixaSalario;
  string gratificacao;
  string tipoFuncionario;           // "1" = mensalista, "2" = autônomo
  CadastroPessoas cadastroPessoas;  // Objeto de acesso ao cadastro de pessoas
};
