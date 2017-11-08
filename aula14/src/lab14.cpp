#include <iostream>
#include <iomanip>
#include "Funcionario.h"
#include "Mensalista.h"
#include "Autonomo.h"

using namespace std;

static Funcionario* funcionarios[10];

void iniciarFuncionario(int i) {
	string nome, idFuncional, tipoFuncionario, salario, valor;
	cout <<endl<< "Digite o idFuncional:" << endl;
	getline(cin, idFuncional);
	cout << "Digite o nome do funcionario:" << endl;
	getline(cin, nome);
	cout << "Digite o tipo do funcionario:" << endl;
	getline(cin, tipoFuncionario);
	switch (tipoFuncionario.at(0)) {
	case '1':
		cout << "Digite o valor do salario:" << endl;
		getline(cin, salario);
		funcionarios[i] = new Mensalista(nome, idFuncional, stof(salario));
		break;
	case '2':
		cout << "Digite o valor da hora:" << endl;
		getline(cin, valor);
		funcionarios[i] = new Autonomo(nome, idFuncional, stof(valor));
		break;
	default:
		cout << "Tipo inválido." << endl << endl;
	}
}

void main() {
	string qt;
	cout << "Quantos funcionarios deseja iniciar? (Max 10)" << endl;
	getline(cin, qt);
	for (int i = 0; i < stoi(qt); i++) {
		iniciarFuncionario(i);
	}

	string idFuncional;
	float remuneracao;
	cout <<endl<< "Iniciando modo de calculo de salario" << endl << endl;
	while (true) {
		cout <<endl<< "Digite o idFuncional para calcular a remuneracao:" << endl;
		getline(cin, idFuncional);
		for (int j = 0; j < stoi(qt); j++) {
			if (idFuncional == funcionarios[j]->getidFuncional()) {
				remuneracao = funcionarios[j]->calcularRemuneracao();
			}
		}
		cout << "Remuneracao: " << "R$ " << fixed << setprecision(2) << remuneracao << endl;
	}
}