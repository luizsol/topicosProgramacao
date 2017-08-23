#include "Aluno.h"
#include <iostream>
Aluno::Aluno(void)
{
	this->nome = "Joao Silva";
	this-> curso = new Curso();
	curso->setNome("Engenharia");
}
Aluno::Aluno(string nome, string nomeDoCurso){
	this->nome = nome;
	this-> curso = new Curso();
	curso->setNome(nomeDoCurso);
}
void Aluno::mostrarNaTela(){
	cout<<"O nome do aluno: "<<this->getNome()<<endl;
	cout<<"O curso do aluno: "<<this->getCurso()->getNome()<<endl;
}


Curso* Aluno::getCurso(){
	return this->curso;
}
void Aluno::setCurso(Curso* curso){
	this->curso = curso;
}
string Aluno::getNome(){
	return this->nome;
}
void Aluno::setNome(string nome) {
	this->nome = nome;
}
Aluno::~Aluno(void)
{
}
