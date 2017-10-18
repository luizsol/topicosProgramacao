/**
    PCS2478 - Tópicos de Programação
    AcessoDados.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-11
*/

#include "AcessoDados.h"

using namespace std;

// Construtores da classe AcessoDados
AcessoDados::AcessoDados(){
  this->nomesArqs[CAD_PESSOAS] = "cadpessoas.dat";
  this->nomesArqs[TAB_SALARIAL] = "tabsalarial.dat";
  this->nomesArqs[IMP_RENDA] = "tabir.dat";
  this->nomesArqs[CONTR_SINDICAL] = "tabcs.dat";
}

// Destrutor da classe AcessoDados
AcessoDados::~AcessoDados(){
  AcessoDados::desconectar();
}


bool AcessoDados::conectar(Arquivos arq, ModoAcesso modo){
  string nomeArq;

  switch(arq){
  case CAD_PESSOAS:
    nomeArq = this->nomesArqs[CAD_PESSOAS];
    break;
   case TAB_SALARIAL:
    nomeArq = this->nomesArqs[TAB_SALARIAL];
    break;
   case IMP_RENDA:
    nomeArq = this->nomesArqs[IMP_RENDA];
    break;
   case CONTR_SINDICAL:
    nomeArq = this->nomesArqs[CONTR_SINDICAL];
    break;
  default:
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexão a um arquivo inexistente");
  }

  switch(modo){
  case LEITURA:
    this->arquivo.open(nomeArq.c_str(), ios::in);
    break;
  case ESCRITA:
    this->arquivo.open(nomeArq.c_str(), ios::out);
    break;
  case INSERCAO:
    this->arquivo.open(nomeArq.c_str(), ios::app);
    break;
  default:
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexão a um arquivo em modo de de acesso "
                                "inexistente.");
  }

  if(this->arquivo.bad())  {
    return false;
  }

  this->arquivo.clear();

  return true;
}


bool AcessoDados::desconectar(){
  this->arquivo.close();
  return true;
}


string AcessoDados::lerTudo(Arquivos arq, ModoAcesso modo){
  AcessoDados::conectar(arq, modo);
  string result, line;
  if (this->arquivo.is_open()){
    while(getline(this->arquivo, line)){
      result.append(line);
      result.append("\n");
    }
    this->arquivo.clear();
    // this->arquivo.seekg(0, ios::beg);
    AcessoDados::desconectar();
    return result;
  }

  throw std::domain_error("AcessoDados::lerTudo: problema ao ler o arquivo.");

}
