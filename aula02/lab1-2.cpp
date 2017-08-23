/* Arquivo: lab1-2.cpp
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#include "Funcionario.h"
#include <iostream>
#include <string>

using namespace std;

int main(int ){
  string idFuncional;
  string nome;
  string endereco;
  string profissao;
  string funcao;
  string cargo;

  cout << "Forneca o ID funcional:" << endl;
  getline(cin, idFuncional);
  cout << "Forneca o nome do funcionario:" << endl;
  getline(cin, nome);
  cout << "Forneca o endereco do funcionario:" << endl;
  getline(cin, endereco);
  cout << "Forneca a profissao do funcionario:" << endl;
  getline(cin, profissao);
  cout << "Forneca a funcao do funcionario:" << endl;
  getline(cin, funcao);
  cout << "Forneca o cargo do funcionario:" << endl;
  getline(cin, cargo);

  Funcionario Func1 = Funcionario(idFuncional, nome, endereco,
                                  profissao, funcao, cargo);

  Func1.obterDadosFunc();
  return 0;
}