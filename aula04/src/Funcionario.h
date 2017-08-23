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
  string idPessoa;		  // ID Pessoal do funcionário
  string idFuncional;	  // ID Funcional do funcionário
  string estadoFuncional; // Estado do funcionário, 0 demitido, 1 empregado, 2 pendente
  string nome;			  // Nome do funcionário
  string endereco;		  // Endereço do funcionário
  string profissao;		  // Profissão do funcionário
  string funcao;		  // Funcao do funcionário
  string cargo;			  // Cargo do funcionário
  string faixaSalario;	  // Faixa salarial do funcionário
  

public:
  // Construtores da classe Funcionario
  Funcionario();
  Funcionario(string idFuncional, string nome, string endereco,
              string profissao, string funcao, string cargo);

  // Destrutor da classe empresa
  ~Funcionario();

  // Setters e Getters
  string getIdP();
  void setIdP(string idFuncional);

  string getIdF();
  void setIdF(string idFuncional);

  string getEstado();
  void setEstado(string estadoFuncional);

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

  string getSalario();
  void setSalario(string faixaSalario);

};