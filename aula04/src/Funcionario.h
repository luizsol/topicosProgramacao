/**
    PCS2478 - Tópicos de Programação
    Funcionario.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 3.0 2017-08-23
*/

#pragma once
#include <string>

using namespace std;

class Funcionario{
  string idFuncional; // ID Funcional do funcionário
  string nome;        // Nome do funcionário
  string endereco;    // Endereço do funcionário
  string profissao;   // Profissão do funcionário
  string funcao;      // Funcao do funcionário
  string cargo;       // Cargo do funcionário

public:
  // Construtores da classe Funcionario
  Funcionario();
  Funcionario(string idFuncional, string nome, string endereco,
              string profissao, string funcao, string cargo);

  // Destrutor da classe empresa
  ~Funcionario();

  // Setters e Getters
  string getId();
  void setId(string idFuncional);

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

};