/**
PCS2478 - Tópicos de Programação
AcessoDados.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 1.0 2017-10-11
*/

#include "AcessoDados.h"
#include <iostream>
#include <string>

using namespace std;

AcessoDados::AcessoDados()
{
}

AcessoDados::~AcessoDados()
{
}

string AcessoDados::lerTudo(Arquivos arq)
{
	modosAcesso modo = LEITURA;
	if (!conectar(arq, modo)) {
		throw std::invalid_argument("Erro ao conectar arquivo");
	}
	string linha = "";
	string out = "";
	while (arquivo.good()) {
		getline(arquivo, linha);
		out.append(linha);
		out.append("\n");
	}
	desconectar(arq);

	return string(out);
}

bool AcessoDados::conectar(Arquivos arq, modosAcesso modo)
{
	string nomeArq;
	switch (arq) {
	case CAD_PESSOAS:
		nomeArq = nomesArqs[CAD_PESSOAS];
		break;
	case TAB_SALARIAL:
		nomeArq = nomesArqs[TAB_SALARIAL];
		break;
	case IMP_RENDA:
		nomeArq = nomesArqs[IMP_RENDA];
		break;
	case CONTR_SINDICAL:
		nomeArq = nomesArqs[CONTR_SINDICAL];
		break;
	}
	switch (modo) {
	case LEITURA:
		arquivo.open(nomeArq.c_str(), ios::in);
		break;
	case ESCRITA:
		arquivo.open(nomeArq.c_str(), ios::out);
		break;
	case INSERCAO:
		arquivo.open(nomeArq.c_str(), ios::app);
		break;
	default:
		break;
	}
	if (arquivo.good()) {
		return true;
	}
	else {
		return false;
	}
}

void AcessoDados::desconectar(Arquivos arq)
{
	arquivo.clear();
	arquivo.close();
}

string AcessoDados::ler(Arquivos arq, string valChave, Campos chave)
{
	if (valChave == "") {
		return lerTudo(arq);
	}
	string resultado;
	modosAcesso modo = LEITURA;
	if (!conectar(arq, modo)) {
		throw std::invalid_argument("Erro ao conectar arquivo");
	}
	string linha = "";
	string out = "erro";
	vector<string> vetorlinha;
	while (arquivo.good()) {
		getline(arquivo, linha);
		vetorlinha = splitDado(linha);
		if (vetorlinha[chave] == valChave) {
			out.append(linha);
			out.append("\n");
		}
	}
	desconectar(arq);

	return out;
}

vector<string> AcessoDados::splitDado(string dado)
{
	vector<string> result;
	unsigned int start = 0;
	unsigned int i = 1;

	while (i < dado.length()) {
		if (dado.at(i) == '|') {
			if (start == i) {
				throw std::invalid_argument("String invalida.");
			}
			result.push_back(dado.substr(start, i - start));
			start = i + 1;
		}
		i++;
	}

	return result;
}

vector<string> AcessoDados::splitLinha(string dado)
{
	vector<string> result;
	unsigned int start = 0;
	unsigned int i = 1;

	while (i < dado.length()) {
		if (dado.at(i) == '\n') {
			if (start == i) {
				throw std::invalid_argument("String invalida.");
			}
			result.push_back(dado.substr(start, i - start));
			start = i + 1;
		}
		i++;
	}

	return result;
}

bool AcessoDados::inserir(Arquivos arq, string registro)
{
	if (!conectar(arq, INSERCAO)) {
		return false;
	}
	else {
		arquivo << registro << endl;
		desconectar(arq);
		return true;
	};
}

bool AcessoDados::atualizar(Arquivos arq, string valChave, Campos chave, string novoValor, Campos campo)
{
	string dados = ler(arq, valChave, chave);
	vector<string> linhas;
	linhas = splitLinha(dados);
	

	unsigned int i = 0;
	string novoArquivo = "new.dat";
	arquivoAux.open(novoArquivo.c_str(), ios::app);

	while (i <= linhas.size()) {
		conectar(arq, LEITURA);
		string linha = "";
		while (arquivo.good()) {
			getline(arquivo, linha);
			if (linha != linhas[i]) {
				arquivoAux << linha<<endl;
			}
			if (linha == linhas[i]) {
				vector <string> vecLinha = splitDado(linhas[i]);
				int indice;

				switch (campo) {
				case 0:
					indice = 0;
					break;
				case 1:
					indice = 1;
					break;
				case C_EFUNC:
					indice = 2;
					break;
				case 3:
					indice = 3;
					break;
				case 4:
					indice = 4;
					break;
				case 5:
					indice = 5;
					break;
				case 6:
					indice = 6;
					break;
				case 7:
					indice = 7;
					break;
				case 8:
					indice = 8;
					break;
				case 9:
					indice = 9;
					break;
				}
				vecLinha[indice] = novoValor;
				for (int j = 0; j < vecLinha.size(); j++) {
					arquivoAux << vecLinha[j] << "|";
				}
				arquivoAux << endl;
			}
		}
		i++;
	}
	string nomeArq;
	switch (arq) {
	case CAD_PESSOAS:
		nomeArq = nomesArqs[CAD_PESSOAS];
		break;
	case TAB_SALARIAL:
		nomeArq = nomesArqs[TAB_SALARIAL];
		break;
	case IMP_RENDA:
		nomeArq = nomesArqs[IMP_RENDA];
		break;
	case CONTR_SINDICAL:
		nomeArq = nomesArqs[CONTR_SINDICAL];
		break;
	}
	//string old = "old.dat";
	//rename(nomeArq.c_str(), old.c_str());
	desconectar(arq);
	arquivoAux.clear();
	arquivoAux.close();
	remove(nomeArq.c_str());
	rename(novoArquivo.c_str(), nomeArq.c_str());
	desconectar(arq);
	return true;
}