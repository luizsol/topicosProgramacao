#include "Curso.h"

Curso::Curso(string nome){
	this->nome = nome;
}
string Curso::getNome(){
	return this->nome;
}
void Curso::setNome(string nome){
	this->nome = nome;
}

Curso::Curso(void)
{
}


Curso::~Curso(void)
{
}
