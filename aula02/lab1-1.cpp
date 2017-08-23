/* Arquivo: lab1-1.cpp
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
  Funcionario Func1 = Funcionario("0312", "Carlos", "Rua dos Bobos, #0",
                                  "Eletricista",
                                  "Montar sistemas eletricos",
                                  "Eletricista Senior");

  Func1.obterDadosFunc();
  return 0;
}