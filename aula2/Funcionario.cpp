/* Arquivo: Funcionario.cpp
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 1
 */

#include "Funcionario.h"
#include <iostream>

using namespace std;

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

Funcionario::~Funcionario(){}

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

void Funcionario::obterDadosFunc(){
  cout << "Id Funcional: \t" << Funcionario::getId() << endl;
  cout << "Nome:\t\t" << Funcionario::getNome() << endl;
  cout << "Endereco:\t" << Funcionario::getEndereco() << endl;
  cout << "Profissao:\t" << Funcionario::getProfissao() << endl;
  cout << "Funcao:\t\t" << Funcionario::getFuncao() << endl;
  cout << "Cargo:\t\t" << Funcionario::getCargo() << endl;
}
