/* Arquivo: Empresa.h
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#pragma once
#include <string>
#include "Funcionario.h"

using namespace std;

class Empresa{
  string nome;
  Funcionario ** funcionarios;
  int maxFuncionarios;

public:
  Empresa();
  Empresa(string nome);
  Empresa(int maxFuncionarios);
  Empresa(string nome, int maxFuncionarios);
  ~Empresa();

  string getNome();
  void setNome(string nome);

  bool contratarFuncionario(string idFuncional, string nome, string endereco,
                            string profissao, string funcao, string cargo);
  bool contratarFuncionarioIterativo();

  bool demitirFuncionario(string idFuncional);
  bool demitirFuncionarioIterativo();
  void demitirTodosFuncionarios();

  void obterDadosFuncionarios();

private:
  bool initFuncArray(int maxFuncionarios);
  bool idJaCadastrado(string idFuncional);
  int buscaIdFuncional(string idFuncional);
  void obterDadosFuncionario(int index);

};