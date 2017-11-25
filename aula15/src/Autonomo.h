/**
    PCS2478 - Tópicos de Programação
    Autonomo.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#pragma once

#include <string>
#include <iostream>

#include "Funcionario.h"

using namespace std;

class Autonomo : public Funcionario {
public:
  // Construtores da classe Funcionario
  Autonomo();
  Autonomo(string idFuncional, string nome, float valorHora);

  // Destrutor da classe empresa
  ~Autonomo();

  // Setters e Getters
  float getValorHora();
  void setValorHora(float valorHora);

  /**
      Determina o salário do autônomo.

      @param horasTrabalhadas (float): o total de horas trabalhadas pelo
        funcionário autônomo.
      @return o salário nominal do autônomo.
  */
  float calcularRemuneracao(float horasTrabalhadas);

private:
  float valorHora; // O valor da hora trabalhada do autônomo
};
