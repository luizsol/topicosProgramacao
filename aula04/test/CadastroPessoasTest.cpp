#include "../src/Empresa.h"
#include "../src/CadastroPessoas.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
  // Construtor da classe funciona;
  CadastroPessoas * cadastroPessoas = new CadastroPessoas();

  // Splitter funciona;
  vector<string> resultado = cadastroPessoas->splitDado("0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|\n");
  cout << "Resultado do split:" << endl;
  for(unsigned int i = 0; i < resultado.size(); i++){
    cout << resultado[i] << endl;
  }

  // Cadastro de funcionário funciona
  cadastroPessoas->adicionarDadosPessoa(
    "0002|0042|1|Heroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|\n"
  );
  cout << cadastroPessoas->lerDadosTodasPessoas();

  // Cadastro de varios funcionários
  string l01, l02, l03, l04, lTotal;
  l01 = "0001|0021|1|Cristiana Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|\n";
  l02 = "0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|\n";
  l03 = "0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|\n";
  l04 = "0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|\n";
  lTotal = l01 + l02 + l03 + l04;

  cadastroPessoas->adicionarDadosPessoas(lTotal);
  cout << cadastroPessoas->lerDadosTodasPessoas();


  return 0;
}