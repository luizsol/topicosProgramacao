#include "Autonomo.h"
#include <iostream>

Autonomo::Autonomo() : Autonomo("", "", 0) {}

Autonomo::Autonomo(string nome, string idFuncional, float valorHora) : Funcionario(nome, idFuncional, "2")
{
	this->setValor(valorHora);
}

Autonomo::~Autonomo()
{
}

float Autonomo::getValor() {
	return this->valorHora;
}

void Autonomo::setValor(float valorHora) {
	this->valorHora = valorHora;
}

float Autonomo::calcularRemuneracao()
{
	string hora;
	cout << "Digite a quantidade de horas trabalhadas por " << this->getNome() << endl;
	getline(cin, hora);
	return valorHora*stof(hora);
}
