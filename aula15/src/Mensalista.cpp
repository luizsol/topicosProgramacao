/**
    PCS2478 - Tópicos de Programação
    Mensalista.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#include "Mensalista.h"

using namespace std;

// Construtores da classe Funcionario
Mensalista::Mensalista(string idFuncional) : Funcionario(idFuncional) {}

Mensalista::Mensalista(string idPessoa, string idFuncional, string nome,
  string profissao, string endereco, string funcao, string cargo,
  string faixaSalario, string gratificacao) :
  Funcionario(idPessoa, idFuncional, nome, profissao, endereco, funcao, cargo,
    faixaSalario, gratificacao, "1") {}

// Setters e Getters
float Mensalista::getSalarioNominal(){
  return this->tabelaSalarial.lerSalarioMensalista(
    Funcionario::getFaixaSalario());
}

/**
    Determina o salário mensal do mensalista.

    @return o salário nominal do mensalista.
*/
float Mensalista::calcularRemuneracao(){
  return Mensalista::getSalarioNominal();
}
