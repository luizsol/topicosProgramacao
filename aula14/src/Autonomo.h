#pragma once
#include "Funcionario.h"
class Autonomo :
	public Funcionario
{
private:
	float valorHora;
public:
	Autonomo();
	Autonomo(string nome, string idFuncional, float valorHora);
	~Autonomo();
	float calcularRemuneracao();
	float getValor();
	void setValor(float valorHora);
};
