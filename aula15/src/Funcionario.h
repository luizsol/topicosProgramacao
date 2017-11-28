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

  // Destrutor da classe empresa
  ~Funcionario();

  // Setters e Getters
  string getIdPessoa();
  void setIdPessoa(string idPessoal);

  string getIdFuncional();
  void setIdFuncional(string idFuncional);

  srting getEstadoFuncional();
  void setEstadoFuncional(string estadoFuncional);

  string getNome();
  void setNome(string nome);

  string getProfissao();
  void setProfissao(string profissao);

  string getEndereco();
  void setEndereco(string endereco);

  string getFuncao();
  void setFuncao(string funcao);

  string getCargo();
  void setCargo(string cargo);

  string getFaixaSalario();
  void setFaixaSalario(string faixaSalario);

  string getGratificacao();
  void setGratificacao(string gratificacao);

  // "1" = mensalista, "2" = autônomo
  string getTipoFuncionario();
  void setTipoFuncionario(string tipoFuncionario);

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
  string idFuncional;               // ID Funcional do funcionário
  CadastroPessoas cadastroPessoas;  // Objeto de acesso ao cadastro de pessoas
};
