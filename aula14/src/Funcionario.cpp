/**
PCS2478 - Tópicos de Programação
Funcionario.cpp

@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
@version 13.0 2017-11-01
*/

#include "Funcionario.h"

using namespace std;

// Construtores da classe Funcionario
Funcionario::Funcionario() : Funcionario("", "", "") {}

Funcionario::Funcionario(string nome, string idFuncional, string tipoFuncionario) {
	this->setNome(nome);
	this->setidFuncional(idFuncional);
	this->setTipo(tipoFuncionario);
}

Funcionario::~Funcionario()
{
}

string Funcionario::getidFuncional() {
	return this->idFuncional;
}

void Funcionario::setidFuncional(string idFuncional) {
	this->idFuncional = idFuncional;
}

string Funcionario::getNome() {
	return this->nome;
}

void Funcionario::setNome(string nome) {
	this->nome = nome;
}

string Funcionario::getTipo() {
	return this->tipoFuncionario;
}

void Funcionario::setTipo(string tipoFuncionario) {
	this->tipoFuncionario = tipoFuncionario;
}

float Funcionario::calcularRemuneracao()
{
	return 0.0f;
}

