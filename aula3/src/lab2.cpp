/* Arquivo: lab2.cpp
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#include "Funcionario.h"
#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;


void sistema(){
  string nomeEmpresa;
  cout << "Forneca o nome da empresa:" << endl;
  getline(cin, nomeEmpresa);
  Empresa novaEmpresa(nomeEmpresa, 5);

  string option = "";

  while(true){
    cout << endl << "-------------------------" << endl;
    cout << novaEmpresa.getNome() << endl;
    cout << "-------------------------" << endl << endl;

    cout << "[C] Cadastrar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[T] Demitir Todos Funcionarios" << endl;
    cout << "[M] Mostrar Funcionarios" << endl;
    cout << "[X] Sair" << endl;
    getline(cin, option);
    cout << "-------------------------" << endl << endl;

    switch(option.at(0)){
    case 'C':
    case 'c':
      novaEmpresa.contratarFuncionarioIterativo();
      break;
    case 'D':
    case 'd':
      novaEmpresa.demitirFuncionarioIterativo();
      break;
    case 'T':
    case 't':
      novaEmpresa.demitirTodosFuncionarios();
      break;
    case 'M':
    case 'm':
      novaEmpresa.obterDadosFuncionarios();
      break;
    case 'X':
    case 'x':
      return;
    default:
      break;
    }
  }
}

int main(int argc, char * argv[]){
  sistema();
  return 0;
}