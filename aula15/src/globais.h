/**
    PCS2478 - Tópicos de Programação
    globais.h

    @author 8586861 - Luiz Eduardo Sol (luizedusol@gmail.com)
    @author 7576829 - Augusto Ruy Machado (augustormachado@gmail.com)
    @version 15.0 2017-12-04
*/

#pragma once

enum Arquivos{CAD_PESSOAS, TAB_SALARIAL, IMP_RENDA, CONTR_SINDICAL,
              TAB_VALORHORA, HORAS_AUTO};

enum Campos{
  //cadastro pessoas
  C_IDPESSOA=0, C_IDFUNC=1, C_EFUNC=2, C_NOME=3, C_PROFISSAO=4, C_ENDERECO=5,
  C_FUNCAO=6, C_CARGO=7, C_FAIXASALARIAL=8, C_GRATIFICACAO=9, C_TIPOFUNC=10,
  // tabela salarial
  C_CATSALARIAL=0, C_SALARIO=1,
  // tabela de contribuição sindical
  C_CARGO_CS=0, C_CONTRIBUICAO_CS=1,
  // tabela de IR
  C_LIM_MIN=0, C_LIM_MAX=1,C_PORCENTAGEM=2,C_DEDUCAO=3,
  // tabala valor hora
  /* C_CATSALARIAL=0,*/ C_VALORHORA=1,
  // tabela horas dos autônomos
  C_IDFUNCHORAS=0, C_HORASTRAB=1
};

enum ModoAcesso{
  LEITURA,
  ESCRITA,
  INSERCAO
};
