/**
    PCS2478 - Tópicos de Programação
    Funcionario.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#include "Funcionario.h"

using namespace std;

// Construtores da classe Funcionario
Funcionario::Funcionario(string idFuncional){
  Funcionario::setIdFuncional(idFuncional);
}

Funcionario::Funcionario(string idPessoa, string idFuncional, string nome,
  string profissao, string endereco, string funcao, string cargo,
  string faixaSalario, string tipoFuncionario){

  Funcionario::setIdFuncional(idFuncional);
  Funcionario::setIdPessoa(idPessoa);
  Funcionario::setNome(nome);
  Funcionario::setProfissao(profissao);
  Funcionario::setEndereco(endereco);
  Funcionario::setFuncao(funcao);
  Funcionario::setCargo(cargo);
  Funcionario::setFaixaSalario(faixaSalario);
  Funcionario::setTipoFuncionario(tipoFuncionario);
}

// Setters e Getters
string Funcionario::getIdPessoa(bool doArquivo){
  if(doArquivo){
    this->idPessoal = Funcionario::getCamposFuncionario()[C_IDPESSOA];
  }

  return this->idPessoal;
}

bool Funcionario::setIdPessoa(string idPessoal, bool noArquivo){
  this->idPessoal = idPessoal;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, idPessoal, C_IDPESSOA);
  }

  return true;
}

string Funcionario::getIdFuncional(){
  return this->idFuncional;
}

bool Funcionario::setIdFuncional(string idFuncional){
  this->idFuncional = idFuncional;
  return true;
}

string Funcionario::getNome(bool doArquivo){
  if(doArquivo){
    this->nome = Funcionario::getCamposFuncionario()[C_NOME];
  }
  return this->nome;
}

bool Funcionario::setNome(string nome, bool noArquivo){
  this->nome = nome;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, nome, C_NOME);
  }

  return true;
}

string Funcionario::getProfissao(bool doArquivo){
  if(doArquivo){
    this->profissao = Funcionario::getCamposFuncionario()[C_PROFISSAO];
  }

  return this->profissao;
}

bool Funcionario::setProfissao(string profissao, bool noArquivo){
  this->profissao = profissao;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, profissao, C_PROFISSAO);
  }

  return true;
}

string Funcionario::getEndereco(bool doArquivo){
  if(doArquivo){
    this->endereco = Funcionario::getCamposFuncionario()[C_ENDERECO];
  }
  return this->endereco;
}

bool Funcionario::setEndereco(string endereco, bool noArquivo){
  this->endereco = endereco;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, endereco, C_ENDERECO);
  }

  return true;
}

string Funcionario::getFuncao(bool doArquivo){
  if(doArquivo){
    this->funcao = Funcionario::getCamposFuncionario()[C_FUNCAO];
  }

  return this->funcao;
}

bool Funcionario::setFuncao(string funcao, bool noArquivo){
  this->funcao = funcao;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, funcao, C_FUNCAO);
  }

  return true;
}

string Funcionario::getCargo(bool doArquivo){
  if(doArquivo){
    this->cargo = Funcionario::getCamposFuncionario()[C_CARGO];
  }

  return this->cargo;
}

bool Funcionario::setCargo(string cargo, bool noArquivo){
  this->cargo = cargo;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, cargo, C_CARGO);
  }

  return true;
}

string Funcionario::getFaixaSalario(bool doArquivo){
  if(doArquivo){
    this->faixaSalario = Funcionario::getCamposFuncionario()[C_FAIXASALARIAL];
  }

  return this->faixaSalario;
}

bool Funcionario::setFaixaSalario(string faixaSalario, bool noArquivo){
  this->faixaSalario = faixaSalario;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, faixaSalario, C_FAIXASALARIAL);
  }

  return true;
}

// "1" = mensalista, "2" = autônomo
string Funcionario::getTipoFuncionario(bool doArquivo){
  if(doArquivo){
    this->tipoFuncionario = Funcionario::getCamposFuncionario()[C_TIPOFUNC];
  }

  return this->tipoFuncionario;
}

bool Funcionario::setTipoFuncionario(string tipoFuncionario,
                                     bool noArquivo){
  this->tipoFuncionario = tipoFuncionario;

  if(noArquivo){
    return Funcionario::cadastroPessoas.atualizarDadosPessoas(
      Funcionario::getIdFuncional(), C_IDFUNC, tipoFuncionario, C_TIPOFUNC);
  }

  return true;
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
