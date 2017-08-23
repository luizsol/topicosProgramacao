/* Arquivo: lab1-4.cpp
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
  string idFuncional1;
  string nome1;
  string endereco1;
  string profissao1;
  string funcao1;
  string cargo1;

  string idFuncional2;
  string nome2;
  string endereco2;
  string profissao2;
  string funcao2;
  string cargo2;

  cout << "Forneca o ID funcional do Funcionario 1:" << endl;
  getline(cin, idFuncional1);
  cout << "Forneca o nome do Funcionario 1:" << endl;
  getline(cin, nome1);
  cout << "Forneca o endereco do Funcionario 1:" << endl;
  getline(cin, endereco1);
  cout << "Forneca a profissao do Funcionario 1:" << endl;
  getline(cin, profissao1);
  cout << "Forneca a funcao do Funcionario 1:" << endl;
  getline(cin, funcao1);
  cout << "Forneca o cargo do Funcionario 1:" << endl;
  getline(cin, cargo1);

  idFuncional2.assign(idFuncional1);
  while(idFuncional1.compare(idFuncional2) == 0){
    cout << "Forneca o ID funcional do Funcionario 2:" << endl;
    getline(cin, idFuncional2);
    if(idFuncional1.compare(idFuncional2) == 0){
      cout << "ID ja inserido" << endl;
    }
  }
  cout << "Forneca o nome do Funcionario 2:" << endl;
  getline(cin, nome2);
  cout << "Forneca o endereco do Funcionario 2:" << endl;
  getline(cin, endereco2);
  cout << "Forneca a profissao do Funcionario 2:" << endl;
  getline(cin, profissao2);
  cout << "Forneca a funcao do Funcionario 2:" << endl;
  getline(cin, funcao2);
  cout << "Forneca o cargo do Funcionario 2:" << endl;
  getline(cin, cargo2);

  Funcionario Func1 = Funcionario(idFuncional1, nome1, endereco1,
                                  profissao1, funcao1, cargo1);
  Funcionario Func2 = Funcionario(idFuncional2, nome2, endereco2,
                                  profissao2, funcao2, cargo2);

  cout << endl;
  cout << "Funcionario1" << endl;
  Func1.obterDadosFunc();
  cout << endl;
  cout << "Funcionario2" << endl;
  Func2.obterDadosFunc();

  return 0;
}