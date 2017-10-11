/**
    PCS2478 - Tópicos de Programação
    Empresa.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 5.0 2017-10-10
*/

#include "Empresa.h"
#include <iostream>

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Empresa Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Empresa Nome", maxFuncionarios)
{}

Empresa::Empresa(string nome, int maxFuncionarios){
  Empresa::initFuncArray(maxFuncionarios);
  Empresa::setNome(nome);
  Empresa::iniciarFuncionarios();
}

// Destrutor da classe empresa
Empresa::~Empresa(){
  delete &(this->funcionarios);
}

// Setters e Getters
string Empresa::getNome(){
  return this->nome;
}

void Empresa::setNome(string nome){
  this->nome = nome;
}

/**
    Solicita os dados de todas as pessoas cadastradas e contrata aquelas que
    tiverem o estado funcional "empregado" (1)

    @return true se todos os funcionários foram devidamente contratados
*/
bool Empresa::iniciarFuncionarios(){
  vector<string> pessoas = Empresa::getAndSplitPessoas();
  CadastroPessoas cadastroPessoas;

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = cadastroPessoas.splitDado(pessoas[i]);
    if(pessoa[2].compare("1") == 0){
      Empresa::contratarFuncionario(pessoa[0], pessoa[1], pessoa[3], pessoa[4],
                                    pessoa[5], pessoa[6], pessoa[7], pessoa[8],
                                    pessoa[9]);
    }
  }
  return true;
}

// Imprime os dados de todos os funcionários da empresa de forma formatada
void Empresa::obterDadosFuncionarios(){
  cout << "Dados de todas os funcionarios:" << endl;
  cout << "------------------------------------------------------------" << endl
    << endl;
  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    cout << i+1 << "o Funcionario: " << endl << endl;
    Empresa::obterDadosFuncionario(i);
    cout << endl;
  }
  if(this->funcionarios.size() == 0){
    cout << "Nenhum funcionario cadastrado." << endl;
  }
}

/**
    Imprime os dados de todas as pessoas contidas em cadastroPessoa de forma
    formatada
*/
void Empresa::obterDadosPessoas(int filtro){
  vector<string> pessoas = Empresa::getAndSplitPessoas();
  CadastroPessoas cadastroPessoas;

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = cadastroPessoas.splitDado(pessoas[i]);

    // Verificando se o usuário deseja filtrar os resultados
    if(filtro != -1 && std::to_string(filtro).compare(pessoa[2]) != 0){
      // O usuário deseja filtrar e essa pessoa não se encaixa no filtro.
      continue;
    }
    cout << i+1 << "a pessoa:" << endl;
    cout << "ID Pessoa: \t\t" << pessoa[0] << endl;
    cout << "Id Funcional: \t\t" << pessoa[1] << endl;
    cout << "Estado Funcional:\t" << pessoa[2] << endl;
    cout << "Nome:\t\t\t" << pessoa[3] << endl;
    cout << "Endereco:\t\t" << pessoa[4] << endl;
    cout << "Profissao:\t\t" << pessoa[5] << endl;
    cout << "Funcao:\t\t\t" << pessoa[6] << endl;
    cout << "Cargo:\t\t\t" << pessoa[7] << endl;
    cout << "Faixa Salarial:\t\t" << pessoa[8] << endl;
    cout << "Gratificacao Salarial:\t" << pessoa[9] << endl << endl;
  }
}

/**
    Apresenta as informações sobre a remuneração de um determinado funcionário

    @throw caso não exista o id funcional inserido pelo usuário (domain_error)
*/
void Empresa::calcularSalarioLiquido(){
  string idFuncional;
  cout << "Insira o ID Funcional do funcionário: ";
  getline(cin, idFuncional);

  int index = Empresa::buscaIdFuncional(idFuncional);
  if(index == -1){
    throw std::domain_error("Empresa::calcularSalario: "
                            "ID Funcional inexistente");
  }
  string salarioBruto = Empresa::calcularSalario(idFuncional);

  float sb = stof(salarioBruto.substr(3, salarioBruto.length()-3));

  ContribuicaoSindical contribSindical;
  float cs = contribSindical.calcularCS(sb,
                                        this->funcionarios[index].getFuncao());

  // Ajustando a resolução
  stringstream streamCS;
  streamCS << "R$ " << fixed << setprecision(2) << cs;

  float sl = sb - cs;

  // Ajustando a resolução
  stringstream streamSL;
  streamSL << "R$ " << fixed << setprecision(2) << sl;

  cout << endl << endl << "Id Funcional: \t\t"
    << this->funcionarios[index].getIdFuncional() << endl;
  cout << "Nome:\t\t\t" << this->funcionarios[index].getNome() << endl;
  cout << "Salario Bruto:\t\t" << salarioBruto << endl;
  cout << "Desconto Sindical:\t" << streamCS.str() << endl;
  cout << "Salario Liquido:\t" << streamSL.str() << endl << endl;
}

/**
    Inicializa o array de funcionários.

    @param maxFuncionarios (int): a capacidade máxima de funcionários da empresa
    @return true se a inicialização foi bem sucedida, false caso contrário
*/
bool Empresa::initFuncArray(int maxFuncionarios){
  this->maxFuncionarios = maxFuncionarios;

  return true;
}

/**
    Verifica se existe um funcionário cadastrado com um determinado ID Funcional

    @param idFuncional (string): o idFuncional a ser verificado
    @return true se já existe um funcionário com o idFuncional, false caso
            contrário
*/
bool Empresa::idJaCadastrado(string idFuncional){
  if(Empresa::buscaIdFuncional(idFuncional) == -1){
    return false;
  }
  return true;
}

/**
    Determina o índice no array de funcionários de determinado funcionário

    @param idFuncional (string): o idFuncional a ser localizado
    @return o índice do array de funcionário onde o funcionário está armazenado
            ou -1 caso ele não tenha sido encontrado
*/
int Empresa::buscaIdFuncional(string idFuncional){
  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    if(this->funcionarios[i].getIdFuncional().compare(idFuncional) == 0){
      return i;
    }
  }
  return -1;
}

/**
    Imprime os dados de um determinado funcionário de forma formatada

    @param index (string): o índice no array de funcionários do funcionário a
                           ser impresso
*/
void Empresa::obterDadosFuncionario(int index){
  cout << "Id Pessoa: \t" << this->funcionarios[index].getIdPessoa()
    << endl;
  cout << "Id Funcional: \t" << this->funcionarios[index].getIdFuncional()
    << endl;
  cout << "Nome:\t\t" << this->funcionarios[index].getNome() << endl;
  cout << "Endereco:\t" << this->funcionarios[index].getEndereco() << endl;
  cout << "Profissao:\t" << this->funcionarios[index].getProfissao() << endl;
  cout << "Funcao:\t\t" << this->funcionarios[index].getFuncao() << endl;
  cout << "Cargo:\t\t" << this->funcionarios[index].getCargo() << endl;
  cout << "Salario:\t" << Empresa::calcularSalario(this->funcionarios[index].
                                                   getIdFuncional())
    << endl << endl;
}

/**
    Retorna uma string com formato monetário correspondente ao salário de um
    determinado funcionário

    @param idFuncional (string): o id funcional do funcionário
    @return a string formatada correspondente ao salário do funcionário
    @throw caso não exista o id funcional (domain_error)
*/
string Empresa::calcularSalario(string idFuncional){
  int i = Empresa::buscaIdFuncional(idFuncional);
  if(i == -1){
    throw std::domain_error("Empresa::calcularSalario: "
                            "ID Funcional inexistente");
  }

  string faixaSalario = this->funcionarios[i].getFaixaSalario();
  TabelaSalarial tabelaSalarial;
  float salario = tabelaSalarial.lerSalario(faixaSalario);
  if(Empresa::getGratificacaoFuncionario(
      this->funcionarios[i].getIdFuncional()).compare("1") == 0){
    salario *= 1.01;
  }

  stringstream stream;
  stream << "R$ " << fixed << setprecision(2) << salario;
  return stream.str();
}

/**
    Obtem e processa os dados dos funcionários de uma forma menos eficiente
    para ficar de acordo com as especificações.

    @return um vector de strings contendo os dados das pessoas
*/
vector<string> Empresa::getAndSplitPessoas(){
  vector<string> linhas;
  string linha;
  CadastroPessoas cadastroPessoas;
  istringstream f(cadastroPessoas.lerDadosTodasPessoas());

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }

  return linhas;
}

/**
    Obtém a gratificação de um determinado funcionário.

    @return a string relativa à gratificação do funcionário
*/
string Empresa::getGratificacaoFuncionario(string idFuncional){
  int index = Empresa::buscaIdFuncional(idFuncional);
  CadastroPessoas cadastroPessoas;
  return cadastroPessoas.splitDado(cadastroPessoas.lerDadosPessoa(
    this->funcionarios[index].getIdPessoa()))[9];
}
