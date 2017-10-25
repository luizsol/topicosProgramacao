/**
PCS2478 - Tópicos de Programação
lab7.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 1.0 2017-10-11
*/

#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;

// void sistema() {

// }

void teste() {
	AcessoDados dados;
	cout << dados.lerTudo(CAD_PESSOAS);
	dados.atualizar(CAD_PESSOAS, "0002", C_IDPESSOA, "34", C_EFUNC);
	// dados.inserir(TAB_SALARIAL, "99|666.666|");
	dados.excluir(TAB_SALARIAL, "666.666", C_SALARIO);
}


int main(int argc, char * argv[]) {
	teste();

	return 0;
}