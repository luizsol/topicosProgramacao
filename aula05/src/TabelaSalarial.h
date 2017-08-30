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
#include <sstream>
#include <iostream>

using namespace std;

class TabelaSalarial{
  vector<string> faixasSalario; // Vetor contendo as faixas salariais

public:
  // Construtores da classe TabelaSalarial
  TabelaSalarial();
  TabelaSalarial(string faixasSalario);

  // Destrutor da classe TabelaSalarial
  ~TabelaSalarial();

  // Setters e Getters
  vector<string> getFaixasSalario();
  void setFaixasSalario(vector<string> faixasSalario);

  /**
      Adiciona uma linha de faixa salarial.

      @param linhaFaixaSalario (string): a linha formatada de faixa salarial
                                         a ser adiciona
      @throw caso a linhaFaixaSalario seja inválida (invalid_argument)
  */
  void adicionaFaixaSalario(string linhaFaixaSalario);

  /**
      Adiciona várias linhas de faixa salarial.

      @param linhasFaixaSalario (string): as linhas formatadas de faixas
                                          salariais a serem adicionas
      @throw caso uma das linhas de linhasFaixaSalario seja inválida
             (invalid_argument)
  */
  void adicionaFaixasSalario(string linhasFaixaSalario);

  /**
      Valida uma linha formatada de faixa salarial.

      @param linhaFaixaSalario (string): a linha formatada de faixa salarial
                                         a ser validada
      @return true se a linha estiver em um formato válido, false caso contrário
  */
  bool validaStringFaixaSalario(string linhaFaixaSalario);

  /**
      Divide uma linha formatada de faixa salarial em um vector com seus
      respectivos campos

      @param indice (unsigned long): o índice no vector this->faixasSalario da
                                     da linha a ser dividida
      @return o vector com strings correspondentes ao campo da linha de faixa
              salarial
      @throw caso o índice do array seja inválido (invalid_argument)
  */
  vector<string> splitSalario(unsigned long indice);

  /**
      Le o valor do salario associado a um determinado código da faixa salarial

      @param faixaSalario (string): o código da faixa salarial a ser obtida
      @return o valor correspondente à faixa salarial
      @throw caso a faixa salaria não exista (invalid_argument)
  */
  float lerSalario(string faixaSalario);
};