/**
    PCS2478 - Tópicos de Programação
    Mensalista.h

	@author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
	@author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
	@version 14.0 2017-11-22
*/


#pragma once

#include <string>

#include "Funcionario.h"

using namespace std;

class Mensalista : public Funcionario {
public:
  // Construtores da classe Funcionario
  Mensalista();
  Mensalista(string idPessoa, string idFuncional, string nome,
	  string profissao, string endereco, string funcao, string cargo,
	  string faixaSalario);

  // Destrutor da classe empresa
  ~Mensalista();

  // Setters e Getters
  float getSalarioBruto();
  void setSalarioBruto(float salarioBruto);

  // Calcula o salário do funcionário
  float calcularRemuneracao();

private:
  float salarioBruto; // O salário bruto mensal do mensalista
};