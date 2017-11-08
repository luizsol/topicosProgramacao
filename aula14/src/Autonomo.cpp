/**
    PCS2478 - Tópicos de Programação
    Autonomo.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 14.0 2017-11-08
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

// Calcula o salário do funcionário
float Autonomo::calcularRemuneracao(){
  string strHoras;

  cout << "Informe o numero de horas trabalhadas do funcionario " <<
    Autonomo::getNome() << ": ";

  getline(cin, strHoras);

  cout << endl;

  float floatHoras = std::stof(strHoras);

  return floatHoras * Autonomo::getValorHora();
}