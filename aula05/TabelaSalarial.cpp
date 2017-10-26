/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-08-30
*/

#include "TabelaSalarial.h"
#include <iostream>

using namespace std;

// Construtores da classe TabelaSalarial
TabelaSalarial::TabelaSalarial() : TabelaSalarial(/* TODO */){}
vector<string> faixasSalario = {"01|390.00|\n",
								"02|460.00|\n",
								"03|800.00|\n",
								"04|1400.00|\n",
								"05|2300.00|\n",
								"06|2850.00|\n",
								"07|4600.00|\n",
								"08|6000.00|\n",
								"09|9000.00|\n"};
									
TabelaSalarial::TabelaSalarial(vector<string> faixasSalario){}

// Destrutor da classe TabelaSalarial
TabelaSalarial::~TabelaSalarial(){}

// Setters e Getters
vector<string> TabelaSalarial::getFaixasSalario(){
  return this->faixasSalario;
}

void TabelaSalarial::setFaixasSalario(vector<string> faixasSalario){
  this->faixasSalario = faixasSalario;
}

float TabelaSalarial::lerSalario(int faixa) {
	bool erro = false;
	bool encontrado = false;
	int i = 0;
	while (!encontrado && i < faixasSalario.size()) {
		if (i == faixa) {
			string salario = faixasSalario[i].substr(3, faixasSalario[i].size() - 1);
			encontrado = true;
			return stof(salario);
		}
		else{
			++i;
		}
	};
	erro = true;
	cout << "Faixa salarial nao encontrada." << endl;
	return false;
};
