/**
    PCS2478 - Tópicos de Programação
    lab10.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 1.0 2017-11-08
*/

#define LINE "------------------------------------------------------------"

#include <sstream>
#include <iomanip>
#include <vector>

#include "Autonomo.h"
#include "Mensalista.h"
#include "Funcionario.h"

using namespace std;

void sistema() {
  vector<Funcionario*> funcionarios;

  while(funcionarios.size() < 4){
    cout << LINE << endl;
    string idFuncional, nome, tipoFuncionario, valorRemuneracao;

    cout << "Informe o ID Funcional do novo funcionario: " << endl;
    getline(cin, idFuncional);

    cout << "Informe o nome do novo funcionario: " << endl;
    getline(cin, nome);

    cout << "Informe o tipo do funcionario (1 = mensalista, 2 = autonomo):" <<
      endl;

    getline(cin, tipoFuncionario);

    if(tipoFuncionario == "1"){

      cout << "Informe o salario bruto do mensalista: " << endl;
      getline(cin, valorRemuneracao);

      funcionarios.push_back(new Mensalista(idFuncional, nome,
                                        std::stof(valorRemuneracao)));

      cout << "Mensalista adicionado!" << endl;

    } else if(tipoFuncionario == "2"){
      cout << "Informe o valor do salario hora do autonomo: " << endl;
      getline(cin, valorRemuneracao);

      funcionarios.push_back(new Autonomo(idFuncional, nome,
                                      std::stof(valorRemuneracao)));

      cout << "Autonomo adicionado!" << endl;

    } else {
      cout << "ERRO: tipo de funcionario invalido." << endl;
    }
  }

  for(unsigned long i = 0; i < funcionarios.size(); i++){
    cout << endl << LINE << endl;
    stringstream streamSalario;
    streamSalario << "R$ " << fixed << setprecision(2) <<
      funcionarios[i]->calcularRemuneracao();
    cout << "Remuneracao do Funcionario " << funcionarios[i]->getNome() << ": "
      << streamSalario.str() << endl;
  }

}

int main() {
  sistema();

  return 0;
}