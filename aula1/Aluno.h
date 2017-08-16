#pragma once
#include <string>
#include "Curso.h"
using namespace std;
class Aluno
{
private:
	string nome;
	Curso * curso;
public:
	Aluno(void);
	Aluno(string,string);
	~Aluno(void);
	string getNome();
	void setNome(string nome);
	Curso* getCurso();
	void setCurso(Curso* curso);
	void mostrarNaTela();
};

