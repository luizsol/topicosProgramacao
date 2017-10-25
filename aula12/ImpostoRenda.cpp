/**
PCS2478 - Tópicos de Programação
Empresa.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)

@version 1.0 2017-09-20
*/

#include "ImpostoRenda.h"
#include <iostream>

using namespace std;

ImpostoRenda::ImpostoRenda()
{
}

ImpostoRenda::~ImpostoRenda()
{
}

ImpostoRenda::ImpostoRenda(string nomeArquivo) {
	this->nomeArquivo = nomeArquivo;
	arquivo.open(nomeArquivo.c_str(), ios::app);
}

vector<float> ImpostoRenda::splitDado(string dados)
{
	vector<float> result;
	unsigned int start = 0;
	unsigned int i = 1;

	while (i < dados.length()) {
		if (dados.at(i) == '|') {
			if (start == i) {
				throw std::invalid_argument("String invalida.");
			}
			result.push_back(stof(dados.substr(start, i - start)));
			start = i + 1;
		}
		i++;
	}

	return result;
}

float ImpostoRenda::calcularIR(float salario)
{
	float ir = 0.0;
	string linha = "";
	string nome = "tabdir.dat";
	arquivo.open(nome.c_str(), ios::in);

	while (arquivo.good()) {
		getline(arquivo, linha);
		vector<float> vlinha = splitDado(linha);
		if (salario >= vlinha[0]) {
			if (salario <= vlinha[1]) {
				ir = salario * vlinha[2]/100 - vlinha[3];
			}
		}
	}

	return ir;
}

string ImpostoRenda::dadosIR()
{
	return acessoDados.lerTudo(IMP_RENDA);
}


