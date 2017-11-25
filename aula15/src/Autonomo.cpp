/**
    PCS2478 - Tópicos de Programação
    Autonomo.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#include "Autonomo.h"

using namespace std;

// Construtores da classe Funcionario
Autonomo::Autonomo(string idFuncional, string nome, float valorHora) :
  Funcionario(idFuncional, "2", nome) {
    Autonomo::setValorHora(valorHora);
}

// Destrutor da classe empresa
Autonomo::~Autonomo(){}

// Setters e Getters
float Autonomo::getValorHora(){
  return this->valorHora;
}

void Autonomo::setValorHora(float valorHora){
  this->valorHora = valorHora;
}

/**
    Determina o salário do autônomo.

    @param horasTrabalhadas (float): o total de horas trabalhadas pelo
      funcionário autônomo.
    @return o salário nominal do autônomo.
*/
float Autonomo::calcularRemuneracao(float horasTrabalhadas){
  return horasTrabalhadas * Autonomo::getValorHora();
}
