/**
    PCS2478 - Tópicos de Programação
    CadastroPessoas.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado
    @version 1.0 2017-08-23
*/


#include "CadastroPessoas.h"
#include <iostream>

using namespace std;

// Construtores da classe CadastroPessoas
CadastroPessoas::CadastroPessoas(){
  string l01, l02, l03, l04, l05, lTotal;
  l01 = "0001|0021|1|Cristiana Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|\n";
  l02 = "0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|\n";
  l03 = "0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|\n";
  l04 = "0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|\n";
  l05 = "0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|\n";

  lTotal = l01 + l02 + l03 + l04 + l05;
  new CadastroPessoas(lTotal);
}

CadastroPessoas::CadastroPessoas(string cargaInicial){ // TODO
  cout << cargaInicial << endl;
}

vector<string> CadastroPessoas::splitDado(string dado){

}

bool CadastroPessoas::validarDados(string dados){
  if(dados.back() != '\n'){
    return false;
  }
  dados.pop_back();
  if(dados.split)
}

