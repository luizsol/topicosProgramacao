/**
    PCS2478 - Tópicos de Programação
    lab6.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @version 1.0 2017-10-01
*/


#include <iostream>
#include <string>

#include "AcessoDados.h"
#include "Empresa.h"

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
    cout << "Empresa " << aEmpresa->getNome() << " criada com sucesso." << endl;
  } catch (logic_error& ex){
      cout << "ERRO ao criar a empresa: " << ex.what() << endl;
      cout << "Saindo..." << endl;
      exit(1);
  }

  AcessoDados acessoDados;

  try{
    cout << "Dados das pessoas:" << endl;
    cout << acessoDados.lerTudo(CAD_PESSOAS) << endl;
  } catch (logic_error& ex){
      cout << "ERRO ao ler dados das pessoas: " << ex.what() << endl;
      exit(1);
  }

  try{
    cout << "Dados da tabela salarial:" << endl;
    cout << acessoDados.lerTudo(TAB_SALARIAL) << endl;
  } catch (logic_error& ex){
      cout << "ERRO ao ler dados da tabela salarial: " << ex.what() << endl;
      exit(1);
  }

  try{
    cout << "Dados da contribuicao sindical:" << endl;
    cout << acessoDados.lerTudo(CONTR_SINDICAL) << endl;
  } catch (logic_error& ex){
      cout << "ERRO ao ler dados da contribuicao sindical: " << ex.what() <<
        endl;
      exit(1);
  }

  try{
    cout << "Dados do imposto de renda:" << endl;
    cout << acessoDados.lerTudo(IMP_RENDA) << endl;
  } catch (logic_error& ex){
      cout << "ERRO ao ler dados da contribuicao sindical: " << ex.what() <<
        endl;
      exit(1);
  }
}


int main(int argc, char * argv[]){
  sistema();
  return 0;
}