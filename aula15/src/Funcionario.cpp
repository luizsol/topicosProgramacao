/**
    PCS2478 - Tópicos de Programação
    Funcionario.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#include "Funcionario.h"

using namespace std;

// Construtores da classe Funcionario
Funcionario::Funcionario(string idFuncional){
  Funcionario::setIdFuncional(idFuncional);
}

// Destrutor da classe empresa
Funcionario::~Funcionario(){}

// Setters e Getters
string Funcionario::getIdPessoa(){
  return Funcionario::getCamposFuncionario()[C_IDPESSOA];
}

bool Funcionario::setIdPessoa(string idPessoal){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, idPessoal, C_IDPESSOA);
}

string Funcionario::getIdFuncional(){
  return this->idFuncional;
}

bool Funcionario::setIdFuncional(string idFuncional){
  this->idFuncional = idFuncional;
}

srting Funcionario::getEstadoFuncional(){
  return Funcionario::getCamposFuncionario()[C_EFUNC];
}

bool Funcionario::setEstadoFuncional(string estadoFuncional){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, estadoFuncional, C_EFUNC);
}

string Funcionario::getNome(){
  return Funcionario::getCamposFuncionario()[C_NOME];
}

bool Funcionario::setNome(string nome){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, nome, C_NOME);
}

string Funcionario::getProfissao(){
  return Funcionario::getCamposFuncionario()[C_PROFISSAO];
}

bool Funcionario::setProfissao(string profissao){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, profissao, C_PROFISSAO);
}

string Funcionario::getEndereco(){
  return Funcionario::getCamposFuncionario()[C_ENDERECO];
}

bool Funcionario::setEndereco(string endereco){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, endereco, C_ENDERECO);
}

string Funcionario::getFuncao(){
  return Funcionario::getCamposFuncionario()[C_FUNCAO];
}

bool Funcionario::setFuncao(string funcao){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, funcao, C_FUNCAO);
}

string Funcionario::getCargo(){
  return Funcionario::getCamposFuncionario()[C_CARGO];
}

bool Funcionario::setCargo(string cargo){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, cargo, C_CARGO);
}

string Funcionario::getFaixaSalario(){
  return Funcionario::getCamposFuncionario()[C_FAIXASALARIAL];
}

bool Funcionario::setFaixaSalario(string faixaSalario){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, faixaSalario, C_FAIXASALARIAL);
}

string Funcionario::getGratificacao(){
  return Funcionario::getCamposFuncionario()[C_GRATIFICACAO];
}

bool Funcionario::setGratificacao(string gratificacao){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, gratificacao, C_GRATIFICACAO);
}

// "1" = mensalista, "2" = autônomo
string Funcionario::getTipoFuncionario(){
  return Funcionario::getCamposFuncionario()[C_TIPOFUNC];
}

bool Funcionario::setTipoFuncionario(string tipoFuncionario){
  return Funcionario::cadastroPessoas.atualizarDadosPessoas(
    Funcionario::getIdFuncional(), C_IDFUNC, tipoFuncionario, C_TIPOFUNC);
}

/**
    Lê a linha no cadastro de pessoas associada a este funcionário.

    @return a linha no cadastro de pessoas associada a este funcionário.
*/
string Funcionario::getLinhaFuncionario(){
  return Funcionario::cadastroPessoas.lerDadosPessoas(Funcionario::idFuncional,
                                                      C_IDFUNC);
}

/**
    Lê a linha no cadastro de pessoas associada a este funcionário e retorna os
    diferentes campos.

    @return os campos da linha no cadastro de pessoas associada a este
      funcionário.
*/
vector<string> Funcionario::getCamposFuncionario(){
  return Funcionario::cadastroPessoas.splitDado(
    Funcionario::getLinhaFuncionario());
}

/**
    Determina o salário mensal do funcionário.

    @return o salário nominal do funcionário.
*/
float Funcionario::calcularRemuneracao(){
  return 0.0;
}
