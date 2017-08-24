#include "../src/Empresa.h"
#include "../src/CadastroPessoas.h"
#include "../src/Funcionario.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
  // Construtor da empresa funciona
  Empresa testeEmpresa1;
  Empresa testeEmpresa2("Empresona2");
  Empresa testeEmpresa3("Empresona3", 2);

  // Setter funciona
  testeEmpresa1.setNome("Empresona1");

  cout << testeEmpresa1.getNome() << endl;
  cout << testeEmpresa2.getNome() << endl;
  cout << testeEmpresa3.getNome() << endl << endl;

  // Consigo adicionar funcionário

  testeEmpresa1.contratarFuncionario("0001", "0002", "Ana Maria Braga",
                                     "Escavador", "Rua dos bobos, No 0",
                                     "Cavador de buracos", "Junior",
                                     "01");

  // e obter os dados dos funcionários

  testeEmpresa1.obterDadosFuncionarios();



  // Não consigo contratar duas vezes um funcionário com mesmo id funcional
  if(! testeEmpresa1.contratarFuncionario("0010", "0002", "Joao Pimpao",
                                          "Minerador", "Rua dos bobos, No 1",
                                          "Minerador de Cobre", "Pleno",
                                          "02")){
    cout << "Funcionario nao contratado!" << endl << endl;
  }

  // Não consigo contratar mais funcionários que o limite máximo
  testeEmpresa3.contratarFuncionario("0001", "0002", "Ana Maria Braga",
                                     "Escavador", "Rua dos bobos, No 0",
                                     "Cavador de buracos", "Junior",
                                     "01");

  testeEmpresa3.contratarFuncionario("0010", "0003", "Joao Pimpao", "Minerador",
                                     "Rua dos bobos, No 1",
                                     "Minerador de Cobre", "Pleno", "02");

  if(! testeEmpresa3.contratarFuncionario("0100", "0004", "Antonio Alborgueti",
                                          "Locutor", "Rua dos bobos, No 2",
                                          "Locutor de Noticias", "Senior", "99")
    ){
    cout << "Funcionario nao contratado!" << endl;
  }

  testeEmpresa3.obterDadosFuncionarios();

  // Consigo demitir funcionário
  testeEmpresa3.demitirFuncionario("0002");
  testeEmpresa3.obterDadosFuncionarios();

  // Consigo demitir todo mundo
  testeEmpresa3.demitirTodosFuncionarios();
  testeEmpresa3.obterDadosFuncionarios();

  return 0;
}