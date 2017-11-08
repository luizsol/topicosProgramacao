#include "Mensalista.h"
#include <iostream>

Mensalista::Mensalista() : Mensalista("","",0){}

Mensalista::Mensalista(string nome, string idFuncional, float sb): Funcionario(nome, idFuncional, "1")
{
	this->setSalario(sb);
}

Mensalista::~Mensalista()
{
}

float Mensalista::getSalario() {
	return this->salarioBruto;
}

void Mensalista::setSalario(float sb) {
	this->salarioBruto = sb;
}

float Mensalista::calcularRemuneracao()
{
	return salarioBruto;
}
