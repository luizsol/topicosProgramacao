/**
    PCS2478 - Tópicos de Programação
    Autonomo.h

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
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
  Autonomo(string idPessoa, string idFuncional, string nome,
	  string profissao, string endereco, string funcao, string cargo,
	  string faixaSalario);

  // Destrutor da classe empresa
  ~Autonomo();

  // Setters e Getters
  float getValorHora();
  void setValorHora(float valorHora);

  // Calcula o salário do funcionário
  float calcularRemuneracao();

private:
  float valorHora; // O valor da hora trabalhada do autônomo
};