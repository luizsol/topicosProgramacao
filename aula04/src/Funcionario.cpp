/**
    PCS2478 - Tópicos de Programação
    Funcionario.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 3.0 2017-08-23
*/

#include "Funcionario.h"
#include <iostream>

using namespace std;

// Construtores da classe Funcionario
Funcionario::Funcionario() : Funcionario("", "", "", "", "", "") {}

Funcionario::Funcionario(string idFuncional, string nome, string endereco,
                         string profissao, string funcao, string cargo){
  Funcionario::setId(idFuncional);
  Funcionario::setNome(nome);
  Funcionario::setEndereco(endereco);
  Funcionario::setProfissao(profissao);
  Funcionario::setFuncao(funcao);
  Funcionario::setCargo(cargo);
}

// Destrutor da classe empresa
Funcionario::~Funcionario(){}

// Setters e Getters
string Funcionario::getId(){
  return this->idFuncional;
}

void Funcionario::setId(string idFuncional){
  this->idFuncional = idFuncional;
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
