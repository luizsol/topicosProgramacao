/**
    PCS2478 - Tópicos de Programação
    Funcionario.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#pragma once

#include <string>

using namespace std;

class Funcionario{
public:
  // Construtores da classe Funcionario
  Funcionario(string idFuncional, string nome);
  Funcionario(string idFuncional, string tipoFuncionario, string nome);

  // Destrutor da classe empresa
  ~Funcionario();

  // Setters e Getters
  string getIdFuncional();
  void setIdFuncional(string idFuncional);

  string getTipoFuncionario();
  void setTipoFuncionario(string tipoFuncionario);

  string getNome();
  void setNome(string nome);

  /**
      Determina o salário mensal do funcionário.

      @param horasTrabalhadas (float): o total de horas trabalhadas pelo
        funcionário.
      @return o salário nominal do funcionário.
  */
  virtual float calcularRemuneracao(float horasTrabalhadas);

protected:
  string idFuncional;     // ID Funcional do funcionário
  string tipoFuncionario; // "1" = mensalista, "2" = autônomo
  string nome;            // Nome do funcionário
};
