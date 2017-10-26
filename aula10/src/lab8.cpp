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
#include "AcessoDados.h"

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

		cout << "[D] Mostrar Dados Pessoais" << endl;
		cout << "[S] Mostrar Tabela Salarial" << endl;
		cout << "[C] Mostrar Tabela de Contribuicao Salarial" << endl;
		cout << "[I] Mostrar Tabela Imposto de Renda" << endl;
		getline(cin, option);
		cout << "-------------------------" << endl << endl;

		switch (option.at(0)) {
		case 'D':
		case 'd':
			cout << endl << "-------------------------" << endl;
			cout << "Escolha um campo para filtrar" << endl;
			cout << "-------------------------" << endl << endl;

			cout << "[0] Id Pessoal" << endl;
			cout << "[1] Id Funcional" << endl;
			cout << "[2] Estado Funcional" << endl;
			cout << "[3] Nome" << endl;
			cout << "[4] Profissao" << endl;
			cout << "[5] Endereco" << endl;
			cout << "[6] Funcao" << endl;
			cout << "[7] Cargo" << endl;
			cout << "[8] Faixa Salarial" << endl;
			cout << "[9] Gratificacao" << endl;
			cout << "[A] Mostrar tudo" << endl;
			getline(cin, filtro);

			if (filtro=="A" || filtro == "a") {
				valorChave = "";
			}
			else {
				cout << "-------------------------" << endl << endl;
				cout << "Digite o parametro do filtro" << endl;
				getline(cin, valorChave);
			}

			switch (filtro.at(0)) {
			case '0':
			case 'a':
			case 'A':
				chave = C_IDPESSOA;
				break;
			case '1':
				chave = C_IDFUNC;
				break;
			case'2':
				chave = C_EFUNC;
				break;
			case '3':
				chave = C_NOME;
				break;
			case '4':
				chave = C_PROFISSAO;
				break;
			case '5':
				chave = C_ENDERECO;
				break;
			case '6':
				chave = C_FUNCAO;
				break;
			case '7':
				chave = C_CARGO;
				break;
			case '8':
				chave = C_FAIXASALARIAL;
				break;
			case '9':
				chave = C_GRATIFICACAO;
				break;
			}
			aEmpresa->obterDadosPessoasEspecificas(valorChave, chave);
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