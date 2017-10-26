/**
PCS2478 - Tópicos de Programação
AcessoDados.h

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 1.0 2017-10-11
*/

#pragma once
#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "globais.h"

using namespace std;

class AcessoDados {
private:
	fstream arquivo;
	fstream arquivoAux;
	string nomeArquivo;
	vector<string> nomesArqs = {"cadpessoas.dat", "tabsalarial.dat", "tabcs.dat", "tabir.dat" };
	enum modosAcesso{LEITURA, ESCRITA, INSERCAO};

	bool conectar(Arquivos arq, modosAcesso modo);

	void desconectar(Arquivos arq);

public:

	AcessoDados();

	~AcessoDados();
	
	string lerTudo(Arquivos arq);

	string ler(Arquivos arq, string valChave, Campos chave);

	vector<string> splitDado(string dado);

	vector<string> splitLinha(string dado);

	bool inserir(Arquivos arq, string registro);

	bool atualizar(Arquivos arq, string valChave, Campos chave, string novoValor, Campos campo);

};