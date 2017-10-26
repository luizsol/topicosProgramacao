#include "ImpostoRenda.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	while (1) {
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	string salario;
	float ir;
	ImpostoRenda * Imposto = new ImpostoRenda();
	cout << "Digite o valor do salario" << endl;
	getline(cin, salario);
	ir = Imposto->calcularIR(stof(salario));
	cout << "Salario: \tR$" << stof(salario) << endl;
	cout << "Contribuicao: \tR$" << ir << endl<<endl;
	}

}
