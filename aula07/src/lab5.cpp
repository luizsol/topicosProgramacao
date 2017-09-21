/**
    PCS2478 - Tópicos de Programação
    lab5.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-09-20
*/

#include "ImpostoRenda.h"
#include <iostream>
#include <string>
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

using namespace std;

void sistema(){
  string nomeArquivo;
  cout << "Forneca o nome do arquivo: ";
  getline(cin, nomeArquivo);

  ImpostoRenda impostoRenda(nomeArquivo);

  string option = "";

  cout << std::fixed;
  cout << std::setprecision(2);

  while(true){
    cout << "-------------------------" << endl << endl;
    cout << "[C] Calcular Imposto de Renda" << endl;
    cout << "[X] Sair" << endl;
    getline(cin, option);
    cout << "-------------------------" << endl << endl;

    switch(option.at(0)){
    case 'C':
    case 'c':
      try{
        cout << "Insira o salario do funcionario: ";
        string salario;
        getline(cin, salario);
        float ir = impostoRenda.calculaIR(stof(salario));
        cout << endl << "Imposto de renda a pagar: R$ " << ir << endl;
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