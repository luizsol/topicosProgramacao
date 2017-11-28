/**
    PCS2478 - Tópicos de Programação
    Autonomo.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#include "Autonomo.h"

using namespace std;

// Construtores da classe Funcionario
Autonomo::Autonomo(string idFuncional) : Funcionario(idFuncional) {}

// Destrutor da classe empresa
Autonomo::~Autonomo(){}

// Setters e Getters
float Autonomo::getValorHora(){
  string linha = Autonomo::acessoDados.ler(TAB_VALORHORA,
                                           Funcionario::getFaixaSalario(),
                                           C_FAIXASALARIAL);

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
