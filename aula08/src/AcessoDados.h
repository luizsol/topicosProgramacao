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
	string nomeArquivo;
	vector<string> nomesArqs = {"cadpessoas.dat", "tabsalarial.dat", "tabcs.dat", "tabir.dat" };
	enum modosAcesso{LEITURA, ESCRITA, INSERCAO};

public:

	AcessoDados();

	~AcessoDados();
	
	string lerTudo(Arquivos arq);

	bool conectar(Arquivos arq, modosAcesso modo);

	void desconectar(Arquivos arq);


};