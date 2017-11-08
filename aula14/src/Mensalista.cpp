/**
    PCS2478 - Tópicos de Programação
    Mensalista.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 14.0 2017-11-08
*/

#include "Mensalista.h"

using namespace std;

// Construtores da classe Funcionario
Mensalista::Mensalista(string idFuncional, string nome, float salarioBruto) :
  Funcionario(idFuncional, "1", nome) {
    Mensalista::setSalarioBruto(salarioBruto);
}

// Destrutor da classe empresa
Mensalista::~Mensalista(){}

// Setters e Getters
float Mensalista::getSalarioBruto(){
  return this->salarioBruto;
}

void Mensalista::setSalarioBruto(float salarioBruto){
  this->salarioBruto = salarioBruto;
}

// Calcula o salário do funcionário
float Mensalista::calcularRemuneracao(){
  return Mensalista::getSalarioBruto();
}