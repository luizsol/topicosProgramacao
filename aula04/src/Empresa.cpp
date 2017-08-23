/**
    PCS2478 - Tópicos de Programação
    Empresa.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 2.0 2017-08-23
*/

#include "Empresa.h"
#include <iostream>

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Sem Nome", maxFuncionarios) {}

Empresa::Empresa(string nome, int maxFuncionarios){
  Empresa::setNome(nome);
  Empresa::initFuncArray(maxFuncionarios);
}


// Destrutor da classe empresa
Empresa::~Empresa(){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL){
      delete this->funcionarios[i];
    }
  }
  free(this->funcionarios);
}

// Setters e Getters
string Empresa::getNome(){
  return this->nome;
}

void Empresa::setNome(string nome){
  this->nome = nome;
}


/**
    Cria e cadastra um funcionário na empresa.

    @param idFuncional (string): o ID Funcional do funcionário
    @param nome (string): o nome do funcionário
    @param endereco (string): o endereço do funcionário
    @param profissao (string): a profissão do funcionário
    @param funcao (string): a função do funcionário
    @param cargo (string): o cargo do funcionário
    @return true se o funcionário foi criado e cadastrado, false caso contrário
*/
bool Empresa::contratarFuncionario(string idPessoa, string idFuncional,
                                   string nome, string profissao,
                                   string endereco, string funcao, string cargo,
                                   string faixaSalario){
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



  this->funcionarios[i] =  new Funcionario(idPessoa, idFuncional, nome,
                                           profissao, endereco, funcao, cargo,
                                           faixaSalario);

  return true;
}


/**
    Cria e cadastra um funcionário na empresa via CLI

    @return true se o funcionário foi criado e cadastrado, false caso contrário
*/
bool Empresa::contratarFuncionarioIterativo(){
  string idPessoa;
  string idFuncional;
  string nome;
  string endereco;
  string profissao;
  string funcao;
  string cargo;
  string faixaSalario;

  bool idExistente = true;
  while(idExistente){
    cout << "Forneca o ID funcional:" << endl;
    getline(cin, idFuncional);
    idExistente =  Empresa::idJaCadastrado(idFuncional);
    if(idExistente){
      cout << "Id Funcional ja existente. Digite outro." << endl;
    }
  }

  cout << "Forneca o ID Pessoa do funcionario:" << endl;
  getline(cin, idPessoa);
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
  cout << "Forneca faixa de salario do funcionario:" << endl;
  getline(cin, faixaSalario);

  return Empresa::contratarFuncionario(idPessoa, idFuncional, nome, profissao,
                                       endereco, funcao, cargo, faixaSalario);
}

/**
    Demite e apaga um funcionário da empresa.

    @param idFuncional (string): o ID Funcional do funcionário a ser demitido
    @return true se o funcionário foi demitido e apagado, false caso contrário
*/
bool Empresa::demitirFuncionario(string idFuncional){
  if(!Empresa::idJaCadastrado(idFuncional)){
    cout << "ERRO: Id funcional nao cadastrado" << endl;
    return false;
  }

  int index = Empresa::buscaIdFuncional(idFuncional);
  delete this->funcionarios[index];

  this->funcionarios[index] = NULL;
  return true;
}

/**
    Demite e apaga um funcionário da empresa via CLI

    @return true se o funcionário foi demitido e apagado, false caso contrário
*/
bool Empresa::demitirFuncionarioIterativo(){
  string idFuncional;
  cout << "Forneca o id Funcional de quem deseja demitir:" << endl;
  getline(cin, idFuncional);

  return Empresa::demitirFuncionario(idFuncional);
}


// Demite e apaga todos funcionário da empresa.
void Empresa::demitirTodosFuncionarios(){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL){
      Empresa::demitirFuncionario(this->funcionarios[i]->getIdFuncional());
    }
  }
}

// Imprime os dados de todos os funcionários da empresa de forma formatada
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

/**
    Inicializa o array de funcionários.

    @param maxFuncionarios (int): a capacidade máxima de funcionários da empresa
    @return true se a inicialização foi bem sucedida, false caso contrário
*/
bool Empresa::initFuncArray(int maxFuncionarios){
  this->funcionarios = (Funcionario**) malloc(maxFuncionarios *
                                              sizeof(Funcionario*));
  this->maxFuncionarios = maxFuncionarios;
  for(int i = 0; i < this->maxFuncionarios; i++){
    this->funcionarios[i] = NULL;
  }

  return true;
}

/**
    Verifica se existe um funcionário cadastrado com um determinado ID Funcional

    @param idFuncional (string): o idFuncional a ser verificado
    @return true se já existe um funcionário com o idFuncional, false caso
            contrário
*/
bool Empresa::idJaCadastrado(string idFuncional){
  if(Empresa::buscaIdFuncional(idFuncional) == -1){
    return false;
  }
  return true;
}


/**
    Determina o índice no array de funcionários de determinado funcionário

    @param idFuncional (string): o idFuncional a ser localizado
    @return o índice do array de funcionário onde o funcionário está armazenado
            ou -1 caso ele não tenha sido encontrado
*/
int Empresa::buscaIdFuncional(string idFuncional){
  for(int i = 0; i < this->maxFuncionarios; i++){
    if(this->funcionarios[i] != NULL &&
       this->funcionarios[i]->getIdFuncional().compare(idFuncional) == 0){
      return i;
    }
  }
  return -1;
}

/**
    Imprime os dados de um determinado funcionário de forma formatada

    @param index (string): o índice no array de funcionários do funcionário a
                           ser impresso
*/
void Empresa::obterDadosFuncionario(int index){
  cout << "Id Funcional: \t" << this->funcionarios[index]->getIdFuncional()
    << endl;
  cout << "Nome:\t\t" << this->funcionarios[index]->getNome() << endl;
  cout << "Endereco:\t" << this->funcionarios[index]->getEndereco() << endl;
  cout << "Profissao:\t" << this->funcionarios[index]->getProfissao() << endl;
  cout << "Funcao:\t\t" << this->funcionarios[index]->getFuncao() << endl;
  cout << "Cargo:\t\t" << this->funcionarios[index]->getCargo() << endl;
}


