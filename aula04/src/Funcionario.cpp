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
Funcionario::Funcionario() : Funcionario("", "", "", "", "", "", "", "") {}

Funcionario::Funcionario(vector<string> dados) : Funcionario(dados[0], dados[1],
                                                             dados[3], dados[4],
                                                             dados[5], dados[6],
                                                             dados[7],
                                                             dados[8]){}

Funcionario::Funcionario(string idPessoa, string idFuncional, string nome,
                         string profissao, string endereco, string funcao,
                         string cargo, string faixaSalario){
  Funcionario::setIdPessoa(idPessoa);
  Funcionario::setIdFuncional(idFuncional);
  Funcionario::setNome(nome);
  Funcionario::setProfissao(profissao);
  Funcionario::setEndereco(endereco);
  Funcionario::setFuncao(funcao);
  Funcionario::setCargo(cargo);
  Funcionario::setFaixaSalario(faixaSalario);
}

// Destrutor da classe empresa
Funcionario::~Funcionario(){}

// Setters e Getters
string Funcionario::getIdPessoa(){
  return this->idPessoa;
}

void Funcionario::setIdPessoa(string idPessoa){
  this->idPessoa = idPessoa;
}

string Funcionario::getIdFuncional(){
  return this->idFuncional;
}

void Funcionario::setIdFuncional(string idFuncional){
  this->idFuncional = idFuncional;
}

string Funcionario::getEstadoFuncional(){
  return this->estadoFuncional;
}
void Funcionario::setEstadoFuncional(string estadoFuncional){
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

string Funcionario::getFaixaSalario(){
  return this->faixaSalario;
}

void Funcionario::setFaixaSalario(string faixaSalario){
  this->faixaSalario = faixaSalario;
}
