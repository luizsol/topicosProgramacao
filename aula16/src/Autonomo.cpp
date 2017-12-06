/**
    PCS2478 - Tópicos de Programação
    Autonomo.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#include "Autonomo.h"

using namespace std;

// Construtores da classe Funcionario
Autonomo::Autonomo(string idFuncional) : Funcionario(idFuncional) {}
Autonomo::Autonomo(string idPessoa, string idFuncional, string nome,
  string profissao, string endereco, string funcao, string cargo,
  string faixaSalario) :
  Funcionario(idPessoa, idFuncional, nome, profissao, endereco, funcao, cargo,
    faixaSalario, "2") {}

Autonomo::~Autonomo() {
	this->horasTrabalhadas.apagaHorasTrabalhadas(getIdFuncional());
}

// Setters e Getters
float Autonomo::getValorHora(){
  string linha = Autonomo::acessoDados.ler(TAB_VALORHORA,
                                           Funcionario::getFaixaSalario(),
                                           C_CATSALARIAL);

  vector<string> campos = Autonomo::acessoDados.splitDado(linha);

  return std::stof(campos[C_VALORHORA]);
}

/**
    Determina o salário do autônomo.

    @return o salário nominal do autônomo.
*/
float Autonomo::calcularRemuneracao(){
  return Autonomo::getValorHora() *
    Autonomo::horasTrabalhadas.lerHorasTrabalhadas(
      Funcionario::getIdFuncional());
}
