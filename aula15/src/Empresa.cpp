/**
    PCS2478 - Tópicos de Programação
    Empresa.cpp

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#include "Empresa.h"

using namespace std;

// Construtores da classe Empresa
Empresa::Empresa() : Empresa("Sem Nome", 10) {}

Empresa::Empresa(string nome) : Empresa(nome, 10) {}

Empresa::Empresa(int maxFuncionarios) : Empresa("Sem Nome", maxFuncionarios) {}

Empresa::Empresa(string nome, int maxFuncionarios){
  Empresa::initFuncArray(maxFuncionarios);
  Empresa::setNome(nome);
  Empresa::iniciarFuncionarios();
}

// Destrutor da classe empresa
Empresa::~Empresa(){
  Empresa::demitirTodosFuncionarios();
  delete &(this->funcionarios);
  delete &(this->cadastroPessoas);
  delete &(this->tabelaSalarial);
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
    tiverem o estado funcional "empregado" (1).

    @return true se todos os funcionários foram devidamente contratados
*/
bool Empresa::iniciarFuncionarios(){
  string dados;
  dados = this->cadastroPessoas.lerDadosTodasPessoas();
  vector<string> pessoas = Empresa::SplitPessoas(dados);

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
    if(pessoa[C_EFUNC].compare("1") == 0){ // O funcionário está com estado
                                           // funcional contratado ("1")

      Empresa::contratarFuncionario(pessoa[C_IDPESSOA], pessoa[C_IDFUNC],
        pessoa[C_NOME], pessoa[C_PROFISSAO], pessoa[C_ENDERECO],
        pessoa[C_FUNCAO], pessoa[C_CARGO], pessoa[C_FAIXASALARIAL],
        pessoa[C_GRATIFICACAO], pessoa[C_TIPOFUNC]);
    }
  }
  return true;
}

/**
    Cria e cadastra um funcionário na empresa.

    @param idPessoa (string): o ID Pessoal do funcionário
    @param idFuncional (string): o ID Funcional do funcionário
    @param nome (string): o nome do funcionário
    @param endereco (string): o endereço do funcionário
    @param profissao (string): a profissão do funcionário
    @param funcao (string): a função do funcionário
    @param cargo (string): o cargo do funcionário
    @param faixaSalario (string): a faixa salarial do funcionário
    @param gratificação (string): o gratificação salarial do funcionário
    @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
      "2"=Autônomo)
    @return true se o funcionário foi criado e cadastrado, false caso contrário
    @throw caso se tente contratar mais funcionários que o limite máximo
           (domain_error)
    @throw caso se tente contratar um funcionário com um ID Funcional já
           existente (domain_error)
*/
bool Empresa::contratarFuncionario(string idPessoa, string idFuncional,
  string nome, string profissao, string endereco, string funcao, string cargo,
  string faixaSalario, string gratificacao, string tipoFuncionario){

  if(this->maxFuncionarios == this->funcionarios.size()){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "Limite de funcionarios atingido");
  }

  if(Empresa::idJaCadastrado(idFuncional)){
    throw std::domain_error("Empresa::contratarFuncionario: "
                            "ID Funcional ja cadastrado");
  }

  if(tipoFuncionario == "1"){ // Mensalista
    this->funcionarios.push_back(new Mensalista(idPessoa, idFuncional, nome,
      profissao, endereco, funcao, cargo, faixaSalario, gratificacao));
  } else { // Autônomo
    this->funcionarios.push_back(new Autonomo(idPessoa, idFuncional, nome,
      profissao, endereco, funcao, cargo, faixaSalario, gratificacao));
  }

  return true;
}

/**
    Demite e apaga um funcionário da empresa.

    @param idFuncional (string): o ID Funcional do funcionário a ser demitido
    @return true se o funcionário foi demitido e apagado, false caso contrário
    @throw caso o ID Funcional seja inexistente (domain_error)
*/
bool Empresa::demitirFuncionario(string idFuncional){
  int index = Empresa::buscaIdFuncional(idFuncional);
  string pessoa = this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC);
  if(pessoa == "" || index == -1){
    throw std::domain_error("Empresa::demitirFuncionario: "
                            "ID Funcional inexistente");
  }

  delete this->funcionarios[index];

  this->funcionarios.erase(this->funcionarios.begin() + index);

  string idPessoal = this->cadastroPessoas.splitDado(pessoa)[0];

  return (this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA,
                                                     "0", C_EFUNC) &&
          this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA,
                                                     "0", C_TIPOFUNC));
}

/**
    Demite e apaga um funcionário da empresa via CLI

    @return true se o funcionário foi demitido e apagado, false caso contrário
*/
bool Empresa::demitirFuncionario(){
  Empresa::obterDadosFuncionarios();
  cout << "Forneca o ID Funcional do funcionario que deseja demitir:" << endl;
  string idFuncional;
  getline(cin, idFuncional);
  return Empresa::demitirFuncionario(idFuncional);

}

// Demite e apaga todos funcionário da empresa.
void Empresa::demitirTodosFuncionarios(){
  while(this->funcionarios.size() > 0){
    Empresa::demitirFuncionario(this->funcionarios[0]->getIdFuncional());
  }
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
    Imprime os dados de todas as pessoas contidas em cadastroPessoa utilizando
    um filtro.

    @param filtro (int): o filtro a ser utilizado.
*/
void Empresa::obterDadosPessoas(int filtro){
  vector<string> pessoas = Empresa::getAndSplitPessoas();

  for(unsigned long i = 0; i < pessoas.size(); i++){
    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);

    // Verificando se o usuário deseja filtrar os resultados
    if(filtro != -1 && std::to_string(filtro).compare(pessoa[2]) != 0){
      // O usuário deseja filtrar e essa pessoa não se encaixa no filtro.
      continue;
    }
    cout << i+1 << "a pessoa:" << endl;
    cout << "ID Pessoa: \t\t" << pessoa[C_IDPESSOA] << endl;
    cout << "Id Funcional: \t\t" << pessoa[C_IDFUNC] << endl;
    cout << "Estado Funcional:\t" << pessoa[C_EFUNC] << endl;
    cout << "Nome:\t\t\t" << pessoa[C_NOME] << endl;
    cout << "Endereco:\t\t" << pessoa[C_PROFISSAO] << endl;
    cout << "Profissao:\t\t" << pessoa[C_ENDERECO] << endl;
    cout << "Funcao:\t\t\t" << pessoa[C_FUNCAO] << endl;
    cout << "Cargo:\t\t\t" << pessoa[C_CARGO] << endl;
    cout << "Faixa Salarial:\t\t" << pessoa[C_FAIXASALARIAL] << endl;
    cout << "Gratificacao Salarial:\t" << pessoa[C_GRATIFICACAO] << endl;
    cout << "Tipo de Funcionario:\t" << pessoa[C_TIPOFUNC] << endl << endl;
  }
}

/**
    Apresenta as informações sobre a remuneração de um determinado funcionário.

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
  float cs = this->contribuicaoSindical.calcularCS(
    sb, this->funcionarios[index]->getFuncao());

  // Ajustando a resolução
  stringstream streamCS;
  streamCS << "R$ " << fixed << setprecision(2) << cs;

  float ir = this->impostoRenda.calcularIR(sb);

  float sl = sb - cs - ir;

  // Ajustando a resolução
  stringstream streamSL;
  streamSL << "R$ " << fixed << setprecision(2) << sl;
  stringstream streamIR;
  streamIR << "R$ " << fixed << setprecision(2) << ir;

  cout << endl << endl << "Id Funcional: \t\t"
    << this->funcionarios[index]->getIdFuncional() << endl;
  cout << "Nome:\t\t\t" << this->funcionarios[index]->getNome() << endl;
  cout << "Salario Bruto:\t\t" << salarioBruto << endl;
  cout << "Desconto Sindical:\t" << streamCS.str() << endl;
  cout << "Imposto de Renda:\t" << streamIR.str() << endl;
  cout << "Salario Liquido:\t" << streamSL.str() << endl << endl;
}

/**
    Obtém todos os dados contidos em um determinado arquivo.

    0 -> cadastropessoas.dat
    1 -> tabsalarial.dat
    2 -> tabcs.dat
    3 -> tabir.dat

    @return o conteúdo do arquivo selecionado.
    @throw caso o argumento seja inválido (invalid_argument)
*/
string Empresa::obterDadosArquivo(int idArquivo){
  switch (idArquivo) {
  case 0:
    return this->cadastroPessoas.dadosCP();
    break;
  case 1:
    return this->tabelaSalarial.dadosTS();
    break;
  case 2:
    return this->contribuicaoSindical.dadosCS();
    break;
  case 3:
    return this->impostoRenda.dadosIR();
    break;
  default:
    throw std::invalid_argument("Empresa::obterDadosArquivo: "
                                "ID Arquivo inexistente");
  }
}

// Imprime os dados de todos os funcionários de forma ordenada.
void Empresa::obterDadosOrdenadosFunc() {
  cout << "Dados de todos os funcionarios (ordenados pelo salario):" << endl;
  cout << "------------------------------------------------------------" << endl
    << endl;

  string dados, salario;
  dados = this->cadastroPessoas.lerDadosTodasPessoas();
  vector<string> pessoas = Empresa::SplitPessoas(dados);
  int n = 1;
  cout << "Autonomos:" << endl << endl;
  for (int j = 9; j > 0; j--) {
    for (unsigned long i = 0; i < pessoas.size(); i++) {
      vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
      if (pessoa[2] == "1" && pessoa[C_TIPOFUNC] == "2") {
        if (stoi(pessoa[8]) == j) {
          cout << n << "o Funcionario: " << endl << endl;
          cout << "Id Pessoa: \t" << pessoa[C_IDPESSOA] << endl;
          cout << "Id Funcional: \t" << pessoa[C_IDFUNC] << endl;
          if(pessoa[C_TIPOFUNC] == "1"){
            cout << "Tipo Funcional:\t" << "Mensalista" << endl;
          } else {
            cout << "Tipo Funcional:\t" << "Autonomo" << endl;
          }
          cout << "Nome:\t\t" << pessoa[C_NOME] << endl;
          cout << "Endereco:\t" << pessoa[C_ENDERECO] << endl;
          cout << "Profissao:\t" << pessoa[C_PROFISSAO] << endl;
          cout << "Funcao:\t\t" << pessoa[C_FUNCAO] << endl;
          cout << "Cargo:\t\t" << pessoa[C_CARGO] << endl;
          try{
            salario = Empresa::calcularSalario(pessoa[C_IDFUNC]);
          } catch(int e) {
            salario = "Nao cadastrado";
          }
          cout << "Salario:\t" << salario << endl << endl;
          cout << endl;
          n++;
        }
      }
    }
  }

  cout << "Mensalistas:" << endl << endl;

  for (int j = 9; j > 0; j--) {
    for (unsigned long i = 0; i < pessoas.size(); i++) {
      vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);
      if (pessoa[2] == "1" && pessoa[C_TIPOFUNC] == "1") {
        if (stoi(pessoa[8]) == j) {
          cout << n << "o Funcionario: " << endl << endl;
          cout << "Id Pessoa: \t" << pessoa[C_IDPESSOA] << endl;
          cout << "Id Funcional: \t" << pessoa[C_IDFUNC] << endl;
          if(pessoa[C_TIPOFUNC] == "1"){
            cout << "Tipo Funcional:\t" << "Mensalista" << endl;
          } else {
            cout << "Tipo Funcional:\t" << "Autonomo" << endl;
          }
          cout << "Nome:\t\t" << pessoa[C_NOME] << endl;
          cout << "Endereco:\t" << pessoa[C_ENDERECO] << endl;
          cout << "Profissao:\t" << pessoa[C_PROFISSAO] << endl;
          cout << "Funcao:\t\t" << pessoa[C_FUNCAO] << endl;
          cout << "Cargo:\t\t" << pessoa[C_CARGO] << endl;
          try{
            salario = Empresa::calcularSalario(pessoa[C_IDFUNC]);
          } catch(int e) {
            salario = "Nao cadastrado";
          }
          cout << "Salario:\t" << salario << endl << endl;
          cout << endl;
          n++;
        }
      }
    }
  }

  if (this->funcionarios.size() == 0) {
    cout << "Nenhum funcionario cadastrado." << endl;
  }
}

/**
    Imprime os dados de uma ou mais pessoas registradas no arquivo
    cadpessoas.dat

    @param valChave (string): o valor a ser buscado na coluna do arquivo de
      registros.
    @param chave (Campos): o enum que representa a coluna a ser avaliada.
*/
void Empresa::obterDadosPessoasEspecificas(string valorChave, Campos chave){
  string resultado = this->cadastroPessoas.lerDadosPessoas(valorChave, chave);
  vector<string> pessoas = this->SplitPessoas(resultado);

  for (unsigned long i = 0; i < pessoas.size(); i++) {

    vector<string> pessoa = this->cadastroPessoas.splitDado(pessoas[i]);

    cout << i + 1 << "a pessoa:" << endl;
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
    Contrata uma pessoa já registrado no arquivo de cadastro de pessoas.

    @param idPessoal (string): o id pessoal da pessoa a ser contratada.
    @param idFuncional (string): o novo id funcional a ser atribuido à pessoa
      contratada.
    @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
      "2"=Autônomo)
    @return true se a pessoa for contratada com sucesso.
*/
bool Empresa::contratarFuncCadastrado(string idPessoal, string idFuncional,
                                      string tipoFuncionario){
  if (this->cadastroPessoas.lerDadosPessoas(idPessoal, C_IDPESSOA) == "") {
    throw std::domain_error("Empresa::contratarFuncCadastrado: "
                            "ID Pessoal inexistente");
  }

  if (this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC) != "") {
    throw std::domain_error("Empresa::contratarFuncCadastrado: "
                            "ID Funcional em uso");
  }

  if(!this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA,
                                                  idFuncional, C_IDFUNC)){
    throw std::domain_error("Empresa::contratarFuncCadastrado: "
                            "Falha na atualizacao do ID funcional no arquivo");
  }

  if(!this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA, "1",
                                                  C_EFUNC)){
    throw std::domain_error("Empresa::contratarFuncCadastrado: "
                            "Falha na atualizacao do estado funcional no "
                            "arquivo");
  }

  if(!this->cadastroPessoas.atualizarDadosPessoas(idPessoal, C_IDPESSOA,
                                                  tipoFuncionario, C_TIPOFUNC)){
    throw std::domain_error("Empresa::contratarFuncCadastrado: "
                            "Falha na atualizacao do tipo de funcionario no "
                            "arquivo");
  }

  string pessoa = this->cadastroPessoas.lerDadosPessoas(idPessoal, C_IDPESSOA);

  vector<string> npessoa = this->cadastroPessoas.splitDado(pessoa);

  Empresa::contratarFuncionario(npessoa[C_IDPESSOA], npessoa[C_IDFUNC],
    npessoa[C_NOME], npessoa[C_PROFISSAO], npessoa[C_ENDERECO],
    npessoa[C_FUNCAO], npessoa[C_CARGO], npessoa[C_FAIXASALARIAL],
    npessoa[C_GRATIFICACAO], npessoa[C_TIPOFUNC]);

  return true;
}

/**
    Insere uma nova pessoa no arquivo de cadastro de pessoas.

    A pessoa inserida terá o idFuncional 0000, estado funcional 2 e a
    gratificação 0.

    @param idPessoal (string): o id da pessoa
    @param nome (string): o nome da pessoa
    @param profissao (string): a profissão da pessoa
    @param endereco (string): o endereco da pessoa
    @param funcao (string): a funcao da pessoa
    @param cargo (string): o cargo da pessoa
    @param faixaSalarial (string): a faixa salarial da pessoa
    @param tipoFuncionario(string): o tipo de funcionário ("1"=Mensalista e
      "2"=Autônomo)
    @return true se a pessoa for inserida com sucesso
*/
bool Empresa::inserirPessoaCadastro(string idPessoal, string nome,
    string profissao, string endereco, string funcao, string cargo,
    string faixaSalarial, string tipoFuncionario){

  string idFuncional = "0000";
  string estadoFuncional = "2";
  string gratificacao = "0";
  return this->cadastroPessoas.inserir(idPessoal, idFuncional, estadoFuncional,
    nome, profissao, endereco, funcao, cargo, faixaSalarial, gratificacao,
    tipoFuncionario);
}

/**
    Retorna todos os dados contidos no arquivo cadpessoas.dat

    @return a string contendo todos os dados contidos no arquivo cadpessoas.dat
*/
string Empresa::lerDadosTodasPessoas(){
  return this->cadastroPessoas.lerDadosTodasPessoas();
}

/**
    Retorna os dados de todos os funcionários listados no arquivo cadpessoas.dat

    @return a concatenação de todas as linhas que representam funcionários.
*/
string Empresa::lerDadosFunc(){
  return this->cadastroPessoas.lerDadosPessoas("1", C_EFUNC);
}

/**
    Divide um texto contendo múltiplas linhas em um vector em que cada elemento
    corresponde a uma linha.

    @param input (string): o texto a ser dividido
    @return um vector contendo as diferente linhas da entrada
*/
vector<string> Empresa::SplitPessoas(string input){
  vector<string> linhas;
  string linha;
  istringstream f(input);

  // Transformando a string de linhas em vetores
  while (std::getline(f, linha)) {
    linha.push_back('\n');
    linhas.push_back(linha);
  }
  return linhas;
}

/**
    Divide uma linha contendo dado de pessoa em um vector contendo os diferentes
    campos dessa linha.

    @param input (string): a linha a ser dividida
    @return um vector contendo os diferentes campos da entrada
*/
vector<string> Empresa::SplitPessoa(string input){
  vector<string> pessoa;
  pessoa = this->cadastroPessoas.splitDado(input);
  return pessoa;
}

/**
    Imprime as informações de uma string contendo os dados de uma pessoa.

    @param input (string): a linha contendo os dados de uma pessoa.
*/
void Empresa::displayPessoa(string linha){
  vector<string> pessoa;
  pessoa = this->SplitPessoa(linha);

  cout << "ID Pessoa: \t\t" << pessoa[C_IDPESSOA] << endl;
  cout << "Id Funcional: \t\t" << pessoa[C_IDFUNC] << endl;
  cout << "Estado Funcional:\t" << pessoa[C_EFUNC] << endl;
  cout << "Nome:\t\t\t" << pessoa[C_NOME] << endl;
  cout << "Endereco:\t\t" << pessoa[C_ENDERECO] << endl;
  cout << "Profissao:\t\t" << pessoa[C_PROFISSAO] << endl;
  cout << "Funcao:\t\t\t" << pessoa[C_FUNCAO] << endl;
  cout << "Cargo:\t\t\t" << pessoa[C_CARGO] << endl;
  cout << "Faixa Salarial:\t\t" << pessoa[C_FAIXASALARIAL] << endl;
  cout << "Gratificacao Salarial:\t" << pessoa[C_GRATIFICACAO] << endl;
  cout << "Tipo de Funcionario:\t" << pessoa[C_TIPOFUNC] << endl << endl;
}

/**
    Realiza uma busca por uma pessoa contendo um determinado id pessoal e a
    exclui do registro de pessoas.

    @param idPessoal (string): o id pessoa da pessoa a ser excuída.
    @return true se pelo menos uma linha for excluida.
*/
bool Empresa::excluirPessoa(string idPessoal){
  return this->cadastroPessoas.excluirPessoa(idPessoal);
}

// Apresenta a folha de pagamento da empresa
void Empresa::emitirFolhaPagamento(){
  cout << "Folha de Pagamento da Empresa " << Empresa::getNome() << endl <<
    endl;

  vector<float> resultAcum({0, 0, 0, 0});

  for(unsigned long i = 0; i < this->funcionarios.size(); i++){
    vector<float> resultParcial = Empresa::getValoresSalariais(
        this->funcionarios[i]->getIdFuncional());
        resultAcum[0] += resultParcial[0];
        resultAcum[1] += resultParcial[1];
        resultAcum[2] += resultParcial[2];
        resultAcum[3] += resultParcial[3];
  }

  stringstream salarioBruto;
  salarioBruto << "R$ " << fixed << setprecision(2) << resultAcum[0];

  stringstream descontoSindical;
  descontoSindical << "R$ " << fixed << setprecision(2) << resultAcum[1];

  stringstream impostoRenda;
  impostoRenda << "R$ " << fixed << setprecision(2) << resultAcum[2];

  stringstream salarioLiquido;
  salarioLiquido << "R$ " << fixed << setprecision(2) << resultAcum[3];

  cout << endl << "Total de salários brutos:\t" << salarioBruto.str() << endl;
  cout << "Total de descontos sindicais:\t" << descontoSindical.str() << endl;
  cout << "Total de impostos de renda:\t" << impostoRenda.str() << endl;
  cout << "Total de salários liquidos:\t" << salarioLiquido.str() << endl;

}

/**
    Insere um novo registro de horas trabalhadas para um autônomo.

    @param idFuncional (string): o id funcional do autonomo.
    @param horas (string): a quantidade de horas trabalhadas.
    @return true se a inserção for realizada com sucesso.
*/
bool Empresa::insereHorasAuto(string idFuncional, string horas){
  return this->horasTrabalhadas.insereHorasTrabalhadas(idFuncional, horas);
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
    if(this->funcionarios[i]->getIdFuncional().compare(idFuncional) == 0){
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
  cout << "Id Pessoa: \t" << this->funcionarios[index]->getIdPessoa()
    << endl;
  cout << "Id Funcional: \t" << this->funcionarios[index]->getIdFuncional()
    << endl;
  cout << "Nome:\t\t" << this->funcionarios[index]->getNome() << endl;
  cout << "Endereco:\t" << this->funcionarios[index]->getEndereco() << endl;
  cout << "Profissao:\t" << this->funcionarios[index]->getProfissao() << endl;
  cout << "Funcao:\t\t" << this->funcionarios[index]->getFuncao() << endl;
  cout << "Cargo:\t\t" << this->funcionarios[index]->getCargo() << endl;
  cout << "Salario:\t" << Empresa::calcularSalario(this->funcionarios[index]->
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

  float salario = this->funcionarios[i]->calcularRemuneracao();
  if(Empresa::getGratificacaoFuncionario(
      this->funcionarios[i]->getIdFuncional()).compare("1") == 0){
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
  istringstream f(this->cadastroPessoas.lerDadosTodasPessoas());

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
  string pessoa;
  vector <string> vpessoa;
  pessoa = this->cadastroPessoas.lerDadosPessoas(idFuncional, C_IDFUNC);
  vpessoa = Empresa::SplitPessoa(pessoa);
  return vpessoa[9];
}

/**
    Imprime os dados salariais do de um determinado funcionário

    @param idFuncional (string): o ID funcional do funcionário
*/
vector<float> Empresa::getValoresSalariais(string idFuncional){
  int index = Empresa::buscaIdFuncional(idFuncional);
  if(index == -1){
    throw std::domain_error("Empresa::calcularSalario: "
                            "ID Funcional inexistente");
  }
  string salarioBruto = Empresa::calcularSalario(idFuncional);

  float sb = stof(salarioBruto.substr(3, salarioBruto.length()-3));

  ContribuicaoSindical contribSindical;
  float cs = this->contribuicaoSindical.calcularCS(
    sb, this->funcionarios[index]->getFuncao());

  // Ajustando a resolução
  stringstream streamCS;
  streamCS << "R$ " << fixed << setprecision(2) << cs;

  float ir = this->impostoRenda.calcularIR(sb);

  float sl = sb - cs - ir;

  // Ajustando a resolução
  stringstream streamSL;
  streamSL << "R$ " << fixed << setprecision(2) << sl;
  stringstream streamIR;
  streamIR << "R$ " << fixed << setprecision(2) << ir;

  cout << endl << endl << "Id Funcional: \t\t"
    << this->funcionarios[index]->getIdFuncional() << endl;
  cout << "Nome:\t\t\t" << this->funcionarios[index]->getNome() << endl;
  cout << "Salario Bruto:\t\t" << salarioBruto << endl;
  cout << "Desconto Sindical:\t" << streamCS.str() << endl;
  cout << "Imposto de Renda:\t" << streamIR.str() << endl;
  cout << "Salario Liquido:\t" << streamSL.str() << endl << endl;

  vector<float> resultado({sb, cs, ir, sl});

  return resultado;
}
