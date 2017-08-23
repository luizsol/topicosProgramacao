/**
    PCS2478 - Tópicos de Programação
    Funcionario.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 3.0 2017-08-23
*/

#include "Funcionario.h"
#include <iostream>

using namespace std;

// Construtores da classe Funcionario
Funcionario::Funcionario() : Funcionario("", "", "", "", "", "") {}

Funcionario::Funcionario(string idFuncional, string idPessoa, string estadoFuncional, string nome, string endereco,
                         string profissao, string funcao, string cargo, string faixaSalario){
  Funcionario::setIdF(idFuncional);
  Funcionario::setIdP(idPessoa);
  Funcionario::setEstado(estadoFuncional);
  Funcionario::setNome(nome);
  Funcionario::setEndereco(endereco);
  Funcionario::setProfissao(profissao);
  Funcionario::setFuncao(funcao);
  Funcionario::setCargo(cargo);
  Funcionario::setSalario(faixaSalario);
}

// Destrutor da classe empresa
Funcionario::~Funcionario(){}

// Setters e Getters
string Funcionario::getIdF(){
  return this->idFuncional;
}

void Funcionario::setIdF(string idFuncional){
  this->idFuncional = idFuncional;
}

string Funcionario::getIdP() {
	return this->idPessoa;
}

void Funcionario::setIdP(string idPessoa) {
	this->idPessoa = idPessoa;
}

string Funcionario::getEstado() {
	return this->estadoFuncional;
}

void Funcionario::setEstado(string estadoFuncional) {
	this->estadoFuncional = estadoFuncional;
}

string Funcionario::getNome(){
  return this->nome;
}

void Funcionario::setNome(string nome){
  this->nome = nome;
}

string Funcionario::getEndereco(){
  return this->endereco;
}

void Funcionario::setEndereco(string endereco){
  this->endereco = endereco;
}

string Funcionario::getProfissao(){
  return this->profissao;
}

void Funcionario::setProfissao(string profissao){
  this->profissao = profissao;
}

string Funcionario::getFuncao(){
  return this->funcao;
}
void Funcionario::setFuncao(string funcao){
  this->funcao = funcao;
}

string Funcionario::getCargo(){
  return this->cargo;
}
void Funcionario::setCargo(string cargo){
  this->cargo = cargo;
}

string Funcionario::getSalario() {
	return this->faixaSalario;
}
void Funcionario::setSalario(string faixaSalario) {
	this->faixaSalario = faixaSalario;
}
