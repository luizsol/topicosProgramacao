/**
    PCS2478 - Tópicos de Programação
    Empresa.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 5.0 2017-10-10
*/

#include "Empresa.h"
#include <iostream>

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Empresa Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Empresa Nome", maxFuncionarios)
{}

Empresa::Empresa(string nome, int maxFuncionarios){
  Empresa::initFuncArray(maxFuncionarios);
  Empresa::setNome(nome);
}

// Destrutor da classe empresa
Empresa::~Empresa(){
  delete &(this->funcionarios);
}

// Setters e Getters
string Empresa::getNome(){
  return this->nome;
}

void Empresa::setNome(string nome){
  this->nome = nome;
}

/**
    Imprime os dados de todas as pessoas contidas em cadastroPessoa de forma
    formatada
*/
void Empresa::obterDadosPessoas(int filtro){
  vector<string> pessoas = Empresa::getAndSplitPessoas();
  CadastroPessoas cadastroPessoas;

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = cadastroPessoas.splitDado(pessoas[i]);

    // Verificando se o usuário deseja filtrar os resultados
    if(filtro != -1 && std::to_string(filtro).compare(pessoa[2]) != 0){
      // O usuário deseja filtrar e essa pessoa não se encaixa no filtro.
      continue;
    }
    cout << i+1 << "a pessoa:" << endl;
    cout << "ID Pessoa: \t\t" << pessoa[0] << endl;
    cout << "Id Funcional: \t\t" << pessoa[1] << endl;
    cout << "Estado Funcional:\t" << pessoa[2] << endl;
    cout << "Nome:\t\t\t" << pessoa[3] << endl;
    cout << "Endereco:\t\t" << pessoa[4] << endl;
    cout << "Profissao:\t\t" << pessoa[5] << endl;
    cout << "Funcao:\t\t\t" << pessoa[6] << endl;
    cout << "Cargo:\t\t\t" << pessoa[7] << endl;
    cout << "Faixa Salarial:\t\t" << pessoa[8] << endl;
    cout << "Gratificacao Salarial:\t" << pessoa[9] << endl << endl;
  }
}

/**
    Inicializa o array de funcionários.

    @param maxFuncionarios (int): a capacidade máxima de funcionários da empresa
    @return true se a inicialização foi bem sucedida, false caso contrário
*/
bool Empresa::initFuncArray(int maxFuncionarios){
  this->maxFuncionarios = maxFuncionarios;

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
  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    if(this->funcionarios[i].getIdFuncional().compare(idFuncional) == 0){
      return i;
    }
  }
  return -1;
}

/**
    Obtem e processa os dados dos funcionários de uma forma menos eficiente
    para ficar de acordo com as especificações.

    @return um vector de strings contendo os dados das pessoas
*/
vector<string> Empresa::getAndSplitPessoas(){
  vector<string> linhas;
  string linha;
  CadastroPessoas cadastroPessoas;
  istringstream f(cadastroPessoas.lerDadosTodasPessoas());

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  return linhas;
}
