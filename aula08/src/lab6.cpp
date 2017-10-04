/**
PCS2478 - Tópicos de Programação
Empresa.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)

@version 1.0 2017-09-20
*/

#include "Empresa.h"
#include <iostream>
#include <string>

using namespace std;


void sistema() {
	string nomeEmpresa;
	cout << "Forneca o nome da empresa:" << endl;
	getline(cin, nomeEmpresa);
	string tamanho;
	cout << "Forneca o numero maximo de funcionarios da empresa " << nomeEmpresa
		<< ":" << endl;

	getline(cin, tamanho);

	Empresa * aEmpresa;

	try {
		aEmpresa = new Empresa(nomeEmpresa, atoi(tamanho.c_str()));
	}
	catch (logic_error& ex) {
		cout << "ERRO ao criar a empresa: " << ex.what() << endl;
		cout << "Saindo..." << endl;
		exit(1);
	}
	string option = "";

	while (true) {
		cout << endl << "-------------------------" << endl;
		cout << aEmpresa->getNome() << endl;
		cout << "-------------------------" << endl << endl;

		cout << "[D] Mostrar Dados Pessoais" << endl;
		cout << "[S] Mostrar Tabela Salarial" << endl;
		cout << "[C] Mostrar Tabela de Contribuicao Salarial" << endl;
		cout << "[I] Mostrar Tabela Imposto de Renda" << endl;
		getline(cin, option);
		cout << "-------------------------" << endl << endl;

		switch (option.at(0)) {
		case 'D':
		case 'd':
			cout << aEmpresa->obterDadosArquivo(0);
			break;
		case 'S':
		case 's':
			cout << aEmpresa->obterDadosArquivo(1);
			break;
		case 'C':
		case 'c':
			cout << aEmpresa->obterDadosArquivo(2);
			break;
		case 'I':
		case 'i':
			cout << aEmpresa->obterDadosArquivo(3);
			break;
		}
	}
}

int main(int argc, char * argv[]) {
	sistema();
	return 0;
}