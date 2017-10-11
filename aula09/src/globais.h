#pragma once

enum Arquivos { CAD_PESSOAS, TAB_SALARIAL, IMP_RENDA, CONTR_SINDICAL };

enum Campos {
	//cadastro pessoas
	C_IDPESSOA, C_IDFUNC, C_EFUNC, C_NOME, C_PROFISSAO, C_ENDERECO, C_FUNCAO, C_CARGO, C_FAIXASALARIAL, C_GRATIFICACAO,
	// tabela salarial
	C_CATSALARIAL=0, C_SALARIO=1,
	//tabela de contribuição sindical
	C_CARGO_CS=0, C_CONTRIBUICAO_CS=1,
	// tabela de IR
	C_LIM_MIN=0, C_LIM_MAX=1,C_PORCENTAGEM=2,C_DEDUCAO=3

};