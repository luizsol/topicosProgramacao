/**
PCS2478 - Tópicos de Programação
p2.cpp

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
		cout << "[O] Mostrar Funcionarios Ordenados por Salário" << endl;
		cout << "[S] Verificar Salário Líquido de Funcionários" << endl;
		cout << "[X] Excluir Pessoa" << endl;
		getline(cin, option);
		cout << "-------------------------" << endl << endl;

		string idPessoal, idFuncional, nome, profissão, endereco, função, cargo, faixaSalarial;
		string pessoas;
		vector<string> vpessoas;

		switch (option.at(0)) {
		case 'P':
		case 'p':
			pessoas = aEmpresa->lerDadosTodasPessoas();
			vpessoas = aEmpresa->SplitPessoas(pessoas);

			for (unsigned long i = 0; i < vpessoas.size()-1; i++){

				cout << i + 1 << "a pessoa:" << endl;
				aEmpresa->displayPessoa(vpessoas[i]);
			}

			break;
		case 'F':
		case 'f':
			pessoas = aEmpresa->lerDadosFunc();
			vpessoas = aEmpresa->SplitPessoas(pessoas);

			for (unsigned long i = 0; i < vpessoas.size(); i++) {
				cout << i + 1 << "a pessoa:" << endl;
				aEmpresa->displayPessoa(vpessoas[i]);
			}
			break;

		case 'C':
		case 'c':

			cout << "Digite o idPessoal a ser contratado:" << endl;
			getline(cin, idPessoal);

			cout << "Digite o idFuncional do contratado:" << endl;
			getline(cin, idFuncional);
			aEmpresa->contratarFuncCadastrado(idPessoal, idFuncional);
			break;

		case 'D':
		case 'd':
			cout << "Digite o idFuncional a ser demitido:" << endl;
			getline(cin, idFuncional);
			aEmpresa->demitirFuncionario(idFuncional);
			break;

		case 'I':
		case 'i':
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
		case 'O':
		case 'o':
			try {
				aEmpresa->obterDadosOrdenadosFunc();
				cout << endl << "Operacao realizada com sucesso!" << endl << endl;
			}
			catch (logic_error& ex) {
				cout << ex.what() << endl;
				cout << endl << "ERRO: A operacao falhou!" << endl << endl;
			}
			break;
		case 'S':
		case 's':
			aEmpresa->calcularSalarioLiquido();
			break;
		case 'X':
		case 'x':
			cout << "Digite o ID Pessoal a ser excluido:" << endl;
			getline(cin, idPessoal);
			bool ok;
			ok = aEmpresa->excluirPessoa(idPessoal);
			if (!ok) {
				cout<<"Erro ao excluir funcionário" << endl;
			}
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