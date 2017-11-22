/**
    PCS2478 - Tópicos de Programação
    Mensalista.cpp

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
*/

#include "Mensalista.h"

using namespace std;

// Construtores da classe Funcionario
Mensalista::Mensalista(string idPessoa, string idFuncional, string nome,
	string profissao, string endereco, string funcao, string cargo,
	string faixaSalario) :
  Funcionario(idPessoa, idFuncional, nome, profissao, endereco, funcao, cargo, faixaSalario,  "1") {
    Mensalista::setSalarioBruto(salarioBruto);
}

// Destrutor da classe empresa
Mensalista::~Mensalista(){}

// Setters e Getters
float Mensalista::getSalarioBruto(){
  return this->salarioBruto;
}

void Mensalista::setSalarioBruto(float salarioBruto){
  this->salarioBruto = salarioBruto;
}

// Calcula o salário do funcionário
float Mensalista::calcularRemuneracao(){
  return Mensalista::getSalarioBruto();
}