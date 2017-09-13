/**
    PCS2478 - Tópicos de Programação
    p1.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @version 1.0 2017-09-13
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
  Empresa * aEmpresa;

  try{
    aEmpresa = new Empresa(nomeEmpresa, atoi(tamanho.c_str()));
  } catch (logic_error& ex){
      cout << "ERRO ao criar a empresa: " << ex.what() << endl;
      cout << "Saindo..." << endl;
      exit(1);
  }
  string option = "";

  while(true){
    cout << endl << "-------------------------" << endl;
    cout << aEmpresa->getNome() << endl;
    cout << "-------------------------" << endl << endl;

    cout << "[M] Mostrar todas as Pessoas" << endl;
    cout << "[F] Mostrar Funcionarios" << endl;
    cout << "[S] Mostrar Dados Salariais de um Funcionario" << endl;
    cout << "[C] Contratar Funcionario" << endl;
    cout << "[D] Demitir Funcionario" << endl;
    cout << "[T] Demitir Todos Funcionarios" << endl;
    cout << "[X] Sair" << endl;
    getline(cin, option);
    cout << "-------------------------" << endl << endl;

    switch(option.at(0)){
    case 'M':
    case 'm':
      aEmpresa->obterDadosPessoas();
      break;
    case 'C':
    case 'c':
      try{
        aEmpresa->contratarFuncionario();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex){
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'D':
    case 'd':
      try{
        aEmpresa->demitirFuncionario();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex){
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'T':
    case 't':
      try{
        aEmpresa->demitirTodosFuncionarios();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex){
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'F':
    case 'f':
      try{
        aEmpresa->obterDadosFuncionarios();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex){
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'S':
    case 's':
      try{
        aEmpresa->calcularSalarioLiquido();
        cout << endl << "Operacao realizada com sucesso!" << endl << endl;
      } catch (logic_error& ex){
        cout << ex.what() << endl;
        cout << endl << "ERRO: A operacao falhou!" << endl << endl;
      }
      break;
    case 'X':
    case 'x':
      cout << endl << "Saindo..." << endl;
      return;
    default:
      cout << endl << "Opcao inválida" << endl;
      break;
    }
  }
}

int main(int argc, char * argv[]){
  sistema();
  return 0;
}