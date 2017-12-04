/**
    PCS2478 - Tópicos de Programação
    Autonomo.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#pragma once

#include <string>
#include <iostream>

#include "Funcionario.h"
#include "HorasTrabalhadas.h"

using namespace std;

class Autonomo : public Funcionario {
public:
  // Construtores da classe Funcionario
  Autonomo(string idFuncional);
  Autonomo(string idPessoa, string idFuncional, string nome, string profissao,
    string endereco, string funcao, string cargo, string faixaSalario,
    string gratificacao);

  // Setters e Getters
  float getValorHora();

  /**
      Determina o salário do autônomo.

      @return o salário nominal do autônomo.
  */
  float calcularRemuneracao();

private:
  AcessoDados acessoDados;            // Um AcessoDados para ler o valor da hora
                                      // trabalhada
  HorasTrabalhadas horasTrabalhadas;  // O leitor de horas trabalhadas
};
