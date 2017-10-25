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

void sistema() {
	string nomeEmpresa;
	cout << "Forneca o nome da empresa:" << endl;
	getline(cin, nomeEmpresa);
	string tamanho;
	cout << "Forneca o numero maximo de funcionarios da empresa " << nomeEmpresa
		<< ":" << endl;

	getline(cin, tamanho);

	Empresa * aEmpresa;
	string filtro = "";
	string valorChave = "";
	Campos chave;
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

		cout << "[P] Mostrar Dados Pessoais" << endl;
		cout << "[F] Mostrar Funcionarios Contratados" << endl;
		cout << "[C] Contratar Funcionario" << endl;
		cout << "[D] Demitir Funcionario" << endl;
		cout << "[I] Inserir Pessoa" << endl;
		getline(cin, option);
		cout << "-------------------------" << endl << endl;

		switch (option.at(0)) {
		case 'P':
		case 'p':
			aEmpresa->cadastroPessoas.lerDadosTodasPessoas();
			break;
		case 'F':
		case 'f':
			aEmpresa->cadastroPessoas.lerDadosPessoas("1",C_EFUNC);
			break;

		case 'C':
		case 'c':
			string idPessoal;
			cout << "Digite o idPessoal a ser contratado:" << endl;
			getline(cin, idPessoal);
			string idFuncional;
			cout << "Digite o idFuncional do contratado:" << endl;
			aEmpresa->contratarFuncCadastrado(idPessoal, idFuncional);
			break;

		case 'D':
		case 'd':
			string idFuncional;
			cout << "Digite o idFuncional a ser demitido:" << endl;
			getline(cin, idFuncional);
			aEmpresa->demitirFuncionario(idFuncional);
			break;

		case 'I':
		case 'i':
			string idPessoal, nome, profissão, endereco, função, cargo, faixaSalarial;
			cout << "Digite o idPessoal:";
			getline(cin, idPessoal);
			cout <<endl<< "Digite o nome:";
			getline(cin, nome);
			cout << endl << "Digite a profissao:";
			getline(cin, profissão);
			cout << endl << "Digite o endereco:";
			getline(cin, endereco);
			cout << endl << "Digite a funcao:";
			getline(cin, função);
			cout << endl << "Digite o cargo:";
			getline(cin, cargo);
			cout << endl << "Digite a faixa salarial:";
			getline(cin, faixaSalarial);
			cout << endl;

			aEmpresa->inserirPessoaCadastro(idPessoal, nome, profissão, endereco, função, cargo, faixaSalarial);
			break;
		}
	}
}
/*
void teste(); {
	AcessoDados * DADOS;
	DADOS = new AcessoDados();
	DADOS->atualizar(CAD_PESSOAS, "0002", C_IDPESSOA, "3", C_EFUNC);
	DADOS->inserir(TAB_SALARIAL, "10|666.00|");
	return 0; 
}
*/

int main(int argc, char * argv[]) {
	sistema();

	return 0;
}