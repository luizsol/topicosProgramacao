/* Arquivo: Funcionario.cpp
 *
 *  Autores:
 *    Luiz Eduardo Sol      8586861
 *    Augusto Ruy Machado   7576829
 *
 * Versao: 2
 */

#include "Empresa.h"
#include <iostream>

using namespace std;

Empresa::Empresa() : Empresa("Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Sem Nome", maxFuncionarios) {}

Empresa::Empresa(string nome, int maxFuncionarios){
  Empresa::setNome(nome);
  Empresa::initFuncArray(maxFuncionarios);
}

Empresa::~Empresa(){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL){
      delete this->funcionarios[i];
    }
  }
  free(this->funcionarios);
}

string Empresa::getNome(){
  return this->nome;
}

void Empresa::setNome(string nome){
  this->nome = nome;
}

bool Empresa::contratarFuncionario(string idFuncional, string nome,
                                   string endereco, string profissao,
                                   string funcao, string cargo){
  int i = 0;
  while(this->funcionarios[i] != NULL && i < this->maxFuncionarios){
    i++;
  }

  if(i >= this->maxFuncionarios){
    cout << "ERRO: Limite de funcionarios excedido" << endl;
    return false;
  }

  if(Empresa::idJaCadastrado(idFuncional)){
    cout << "ERRO: Id Funcional ja cadastrado" << endl;
    return false;
  }



  this->funcionarios[i] =  new Funcionario(idFuncional, nome,
                                           endereco, profissao,
                                           funcao, cargo);

  return true;
}

bool Empresa::contratarFuncionarioIterativo(){
  string idFuncional;
  string nome;
  string endereco;
  string profissao;
  string funcao;
  string cargo;

  bool idExistente = true;
  while(idExistente){
    cout << "Forneca o ID funcional:" << endl;
    getline(cin, idFuncional);
    idExistente =  Empresa::idJaCadastrado(idFuncional);
    if(idExistente){
      cout << "Id Funcional ja existente. Digite outro." << endl;
    }
  }

  cout << "Forneca o nome do funcionario:" << endl;
  getline(cin, nome);
  cout << "Forneca o endereco do funcionario:" << endl;
  getline(cin, endereco);
  cout << "Forneca a profissao do funcionario:" << endl;
  getline(cin, profissao);
  cout << "Forneca a funcao do funcionario:" << endl;
  getline(cin, funcao);
  cout << "Forneca o cargo do funcionario:" << endl;
  getline(cin, cargo);

  if(Empresa::contratarFuncionario(idFuncional, nome, endereco, profissao,
                                   funcao, cargo)){
    cout << endl << "SUCESSO: Funcionario " << nome <<
    " cadastrado com sucesso!" << endl;
    return true;
  } else {
    cout << endl << "ERRO: erro ao cadastrar o funcionario " <<
    ", limite de funcionarios excedido"  << endl;
    return false;
  }
}

bool Empresa::demitirFuncionario(string idFuncional){
  if(!Empresa::idJaCadastrado(idFuncional)){
    return false;
  }

  int index = Empresa::buscaIdFuncional(idFuncional);
  delete this->funcionarios[index];

  this->funcionarios[index] = NULL;
  return true;
}

bool Empresa::demitirFuncionarioIterativo(){
  string idFuncional;
  cout << "Forneca o id Funcional de quem deseja demitir:" << endl;
  getline(cin, idFuncional);

  if(Empresa::demitirFuncionario(idFuncional)){
    cout << endl << "SUCESSO: Funcionario com ID funcional " << idFuncional <<
      " demitido!" << endl;
    return true;
  } else {
    cout << endl << "ERRO: Funcionario com ID funcional " << idFuncional <<
      " inexistente!" << endl;
    return false;
  }
}

void Empresa::demitirTodosFuncionarios(){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL){
      Empresa::demitirFuncionario(this->funcionarios[i]->getId());
    }
  }
}

void Empresa::obterDadosFuncionarios(){
  int j = 1;
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL){
      cout << j << "o Funcionario: " << endl << endl;
      Empresa::obterDadosFuncionario(i);
      cout << endl;
      j++;
    }
  }
  if(j == 1){
    cout << "Nenhum funcionario cadastrado." << endl;
  }
}

bool Empresa::initFuncArray(int maxFuncionarios){
  this->funcionarios = (Funcionario**) malloc(maxFuncionarios *
                                              sizeof(Funcionario*));
  this->maxFuncionarios = maxFuncionarios;
  for(int i = 0; i < this->maxFuncionarios; i++){
    this->funcionarios[i] = NULL;
  }

  return true;
}

bool Empresa::idJaCadastrado(string idFuncional){
  if(Empresa::buscaIdFuncional(idFuncional) == -1){
    return false;
  }
  return true;
}

int Empresa::buscaIdFuncional(string idFuncional){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL &&
       this->funcionarios[i]->getId().compare(idFuncional) == 0){
      return i;
    }
  }
  return -1;
}

void Empresa::obterDadosFuncionario(int index){
  cout << "Id Funcional: \t" << this->funcionarios[index]->getId() << endl;
  cout << "Nome:\t\t" << this->funcionarios[index]->getNome() << endl;
  cout << "Endereco:\t" << this->funcionarios[index]->getEndereco() << endl;
  cout << "Profissao:\t" << this->funcionarios[index]->getProfissao() << endl;
  cout << "Funcao:\t\t" << this->funcionarios[index]->getFuncao() << endl;
  cout << "Cargo:\t\t" << this->funcionarios[index]->getCargo() << endl;
}


