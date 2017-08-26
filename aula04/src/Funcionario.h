/**
    PCS2478 - Tópicos de Programação
    Funcionario.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-08-23
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class Funcionario{
  string idPessoa;        // ID da pessoa
  string idFuncional;     // ID Funcional do funcionário
  string estadoFuncional; // O estado funcional do funcionário
  string nome;            // Nome do funcionário
  string profissao;       // Profissão do funcionário
  string endereco;        // Endereço do funcionário
  string funcao;          // Funcao do funcionário
  string cargo;           // Cargo do funcionário
  string faixaSalario;    // Faixa salarial do funcionário

public:
  // Construtores da classe Funcionario
  Funcionario();
  Funcionario(vector<string> dados);
  Funcionario(string idPessoa, string idFuncional, string nome,
              string profissao, string endereco, string funcao, string cargo,
              string faixaSalario);

  // Destrutor da classe empresa
  ~Funcionario();

  // Setters e Getters
  string getIdPessoa();
  void setIdPessoa(string idPessoa);

  string getIdFuncional();
  void setIdFuncional(string idFuncional);

  string getEstadoFuncional();
  void setEstadoFuncional(string estadoFuncional);

  string getNome();
  void setNome(string nome);

  string getEndereco();
  void setEndereco(string endereco);

  string getProfissao();
  void setProfissao(string profissao);

  string getFuncao();
  void setFuncao(string funcao);

  string getCargo();
  void setCargo(string cargo);

  string getFaixaSalario();
  void setFaixaSalario(string faixaSalario);
};