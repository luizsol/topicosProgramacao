#include "../src/TabelaSalarial.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[]){
  // Consigo construir o objeto?
  TabelaSalarial tabela;

  // Ele adicionou as linhas?
  cout << tabela.getFaixasSalario()[0] << endl;

  // Consigo ler o salário de alguém?
  cout << tabela.lerSalario("06") << endl;

  return 0;
}