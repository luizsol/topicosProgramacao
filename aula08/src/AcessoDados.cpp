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
	bool ok;
	ok = conectar(arq, LEITURA);
	if (!ok){
		cout << "ERRO NO ARQUIVO" << endl;
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
