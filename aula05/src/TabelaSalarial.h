/**
    PCS2478 - Tópicos de Programação
    TabelaSalarial.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-08-30
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class TabelaSalarial{
  vector<string> faixasSalario; // Vetor contendo as faixas salariais

public:
  // Construtores da classe TabelaSalarial
  TabelaSalarial();
  TabelaSalarial(vector<string> faixasSalario);

  // Destrutor da classe TabelaSalarial
  ~TabelaSalarial();

  // Setters e Getters
  vector<string> getFaixasSalario();
  void setFaixasSalario(vector<string> faixasSalario);


};