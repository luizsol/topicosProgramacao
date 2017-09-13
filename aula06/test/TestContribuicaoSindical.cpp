#include "../src/ContribuicaoSindical.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[]){
  // Consigo construir o objeto?
  ContribuicaoSindical contribuicao;

  // Ele calcula do jeito correto?
  cout << contribuicao.calcularCS(100.0, "Administrador") << endl;

  return 0;
}