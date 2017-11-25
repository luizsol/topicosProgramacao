/**
    PCS2478 - Tópicos de Programação
    HorasTrabalhadas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-11-23
*/

#include "HorasTrabalhadas.h"

HorasTrabalhadas::HorasTrabalhadas() {}

HorasTrabalhadas::~HorasTrabalhadas() {}

float HorasTrabalhadas::lerHorasTrabalhadas(string idFuncional){
    string resultado = HorasTrabalhadas::tabHorasTrabalhadas.ler(HORAS_AUTO,
                                                                 idFuncional,
                                                                 C_IDFUNCHORAS);

    if(resultado == ""){
        throw std::invalid_argument("HorasTrabalhadas::lerHorasTrabalhadas: "
                                    "ID Funcional nao encontrado.");
    }

    vector<string> campos =  HorasTrabalhadas::splitDado(resultado);

    return std::stof(campos[C_HORASTRAB]);
}

/**
    Retorna um vector de strings contendo os diferentes campos de uma linha.

    @param dado (string): o dado a ser processado
    @return o vetor de strings contendo os diferentes campos de uma linha.
    @throw caso o argumento seja inválido (invalid_argument)
*/
vector<string> HorasTrabalhadas::splitDado(string dado){
  vector<string> result;
  unsigned int start = 0;
  unsigned int i = 1;

  while(i < dado.length()){
    if(dado.at(i) == '|'){
      if(start == i){
        throw std::invalid_argument("HorasTrabalhadas::splitDado: "
                                    "String invalida.");
      }
      result.push_back(dado.substr(start, i - start));
      start = i + 1;
    }
    i++;
  }

  return result;
}
