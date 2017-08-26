/**
    PCS2478 - Tópicos de Programação
    lab3.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 1.0 2017-08-23
*/

#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;


void sistema(){
  string nomeEmpresa;
  cout << "Forneca o nome da empresa:" << endl;
  getline(cin, nomeEmpresa);
  string tamanho;
  cout << "Forneca o numero maximo de funcionarios da empresa " << nomeEmpresa
    << ":" << endl;
  getline(cin, tamanho);
  Empresa aEmpresa(nomeEmpresa, atoi(tamanho.c_str()));

  string option = "";

  while(true){
    cout << endl << "-------------------------" << endl;
    cout << aEmpresa.getNome() << endl;
    cout << "-------------------------" << endl << endl;

    cout << "[M] Mostrar todas as Pessoas" << endl;
    cout << "[C] Cadastrar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[T] Demitir Todos Funcionarios" << endl;
    cout << "[F] Mostrar Funcionarios" << endl;
    cout << "[X] Sair" << endl;
    getline(cin, option);
    cout << "-------------------------" << endl << endl;

    switch(option.at(0)){
    case 'M':
    case 'm':
      aEmpresa.obterDadosPessoas();
      break;
    case 'C':
    case 'c':
      if(aEmpresa.contratarFuncionario()){
        cout << "Operacao realizada com sucesso!" << endl << endl;
      } else {
        cout << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'D':
    case 'd':
      if(aEmpresa.demitirFuncionario()){
        cout << "Operacao realizada com sucesso!" << endl << endl;
      } else {
        cout << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'T':
    case 't':
      aEmpresa.demitirTodosFuncionarios();
      cout << "SUCESSO: Todos funcionarios demitidos com sucesso" << endl;
      break;
    case 'F':
    case 'f':
      aEmpresa.obterDadosFuncionarios();
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