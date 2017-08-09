/* Arquivo: Funcionario.h
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#pragma once
#include <string>

using namespace std;

class Funcionario{
  string idFuncional;
  string nome;
  string endereco;
  string profissao;
  string funcao;
  string cargo;

public:
  Funcionario();
  Funcionario(string idFuncional, string nome, string endereco,
              string profissao, string funcao, string cargo);
  ~Funcionario();

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

  void obterDadosFunc();

};