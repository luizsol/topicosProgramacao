/**
    PCS2478 - Tópicos de Programação
    Mensalista.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#pragma once

#include <string>

#include "Funcionario.h"

using namespace std;

class Mensalista : public Funcionario {
public:
  // Construtores da classe Funcionario
  Mensalista();
  Mensalista(string idFuncional, string nome, float salarioNominal);

  // Destrutor da classe empresa
  ~Mensalista();

  // Setters e Getters
  float getSalarioNominal();
  void setSalarioNominal(float salarioNominal);

  /**
      Determina o salário mensal do mensalista.

      @param horasTrabalhadas (float): o total de horas trabalhadas pelo
        funcionário. Esse parâmetro é ignorado nessa classe uma vez que o
        mensalista recebe um salário fixo.
      @return o salário nominal do mensalista.
  */
  float calcularRemuneracao(float horasTrabalhadas = 0);

private:
  float salarioNominal; // O salário nominal mensal do mensalista
};
