/**
PCS2478 - Tópicos de Programação
Empresa.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)

@version 1.0 2017-09-20
*/

#pragma once

#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>

#pragma once

using namespace std;

class ImpostoRenda {

private:
	fstream arquivo;
	string nomeArquivo;

public:
	ImpostoRenda();

	~ImpostoRenda();

	ImpostoRenda(string nomeArquivo);

	vector<float> splitDado(string dados);

	float calcularIR(float salario);

};