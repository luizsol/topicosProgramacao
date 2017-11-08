#pragma once
#include "Funcionario.h"
class Mensalista :
	public Funcionario
{
private:
	float salarioBruto;
public:
	Mensalista();
	Mensalista(string nome, string idFuncional, float sb);
	~Mensalista();
	float getSalario();
	void setSalario(float sb);
	float calcularRemuneracao();
};

