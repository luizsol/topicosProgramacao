/**
    PCS2478 - Tópicos de Programação
    Mensalista.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-29
*/

#pragma once

#include <string>

#include "Funcionario.h"

using namespace std;

class Mensalista : public Funcionario {
public:
  // Construtores da classe Funcionario
  Mensalista(string idFuncional);

  // Destrutor da classe empresa
  ~Mensalista();

  // Setters e Getters
  float getSalarioNominal();

  /**
      Determina o salário mensal do mensalista.

      @return o salário nominal do mensalista.
  */
  float calcularRemuneracao();

private:
};
