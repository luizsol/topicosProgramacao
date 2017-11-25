/**
    PCS2478 - Tópicos de Programação
    Mensalista.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#include "Mensalista.h"

using namespace std;

// Construtores da classe Funcionario
Mensalista::Mensalista(string idFuncional, string nome, float salarioNominal) :
  Funcionario(idFuncional, "1", nome) {
    Mensalista::setSalarioNominal(salarioNominal);
}

// Destrutor da classe empresa
Mensalista::~Mensalista(){}

// Setters e Getters
float Mensalista::getSalarioNominal(){
  return this->salarioNominal;
}

void Mensalista::setSalarioNominal(float salarioNominal){
  this->salarioNominal = salarioNominal;
}

/**
    Determina o salário mensal do mensalista.

    @param horasTrabalhadas (float): o total de horas trabalhadas pelo
      funcionário. Esse parâmetro é ignorado nessa classe uma vez que o
      mensalista recebe um salário fixo.
    @return o salário nominal do mensalista.
*/
float Mensalista::calcularRemuneracao(float horasTrabalhadas){
  return Mensalista::getSalarioNominal();
}
