#pragma once
#include <string>
using namespace std;

class Funcionario
{
protected:
	string tipoFuncionario;
	string idFuncional;
	string nome;

public:
	Funcionario();
	Funcionario(string nome, string idFuncional, string tipoFuncionario);
	~Funcionario();
	string getNome();
	void setNome(string nome);
	string getidFuncional();
	void setidFuncional(string idFuncional);
	string getTipo();
	void setTipo(string tipoFuncionario);
	virtual float calcularRemuneracao();

};