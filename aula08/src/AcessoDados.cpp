/**
    PCS2478 - Tópicos de Programação
    AcessoDados.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 4.0 2017-10-10
*/

#include "AcessoDados.h"

using namespace std;

// Construtores da classe AcessoDados
AcessoDados::AcessoDados(Arquivos arq, ModosAcesso modo){
  this->nomesArqs[Arquivos.CAD_PESSOAS] = "cadpessoas.dat";
  this->nomesArqs[Arquivos.TAB_SALARIAL] = "tabsalarial.dat";
  this->nomesArqs[Arquivos.IMP_RENDA] = "imprenda.dat";
  this->nomesArqs[Arquivos.CONTR_SINDICAL] = "contrsindical.dat";
}

// Destrutor da classe AcessoDados
AcessoDados::~AcessoDados(){
  AcessoDados::desconectar();
}


bool AcessoDados::conectar(Arquivos arq, ModosAcesso modo){
  string nomeArq;

  swich(arq){
  case Arquivos.CAD_PESSOAS:
    nomeArq = this->nomesArqs[Arquivos.CAD_PESSOAS];
    break;
   case Arquivos.TAB_SALARIAL:
    nomeArq = this->nomesArqs[Arquivos.TAB_SALARIAL];
    break;
   case Arquivos.IMP_RENDA:
    nomeArq = this->nomesArqs[Arquivos.IMP_RENDA];
    break;
   case Arquivos.TAB_SALARIAL:
    nomeArq = this->nomesArqs[Arquivos.TAB_SALARIAL];
    break;
  default:
    throw std::invalid_argument("AcessoDados::conectar: tentativa de "
                                "conexão a um arquivo inexistente");
  }

  swich(modo){
  case modosAcesso.LEITURA:
    this->arquivo.open(nomeArq.c_str(), ios::in);
    break;
  case modosAcesso.ESCRITA:
    this->arquivo.open(nomeArq.c_str(), ios::out);
    break;
  case modosAcesso.INSERCAO:
    this->arquivo.open(nomeArq.c_str(), ios::app);
    break
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
}


string AcessoDados::lerTudo(Arquivos arq, ModosAcesso modo){
  AcessoDados::conectar(arq, modo);
  string result;
  if (this->arquivo.is_open()){
    while(getline(this->arquivo, line)){
      result.append(line);
      result.append("\n");
    }
    this->arquivo.clear();
    // this->arquivo.seekg(0, ios::beg);
    AcessoDados::desconectar()
    return result;
  }

  throw std::domain_error("AcessoDados::lerTudo: problema ao ler o arquivo.");

}
