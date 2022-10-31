#include <stdio.h>
#include <stdlib.h>
#include "receitas.h"
#include"funcoes.h"

//
//MODULO RECEITAS
//

char modulo_receitas(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Receita                                                           |");
	printf("\n| 2-Ver Receitas                                                                |");
	printf("\n| 3-Modificar Receita                                                           |");
	printf("\n| 4-Deletar Receita                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

typedef struct receitas Receitas;
Receitas *cadastroRC();

void modulo_cad_receitas(void){
	Receitas* rc;
	rc = cadastroRC();
	free(rc);
}

Receitas *cadastroRC(void){
	Receitas* rc;
	rc = (Receitas*) malloc(sizeof(Receitas));
	int valiNmC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> CADASTRO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da receita: ");
	scanf("%s", rc->nome);
	getchar();
	valiNmC = validarNome(rc->nome);
	if ((valiNmC) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n| Liste os ingrediente e quantidades: ");
	scanf("%299[a-zA-Z0-9 -.,]", rc->ingredientesCad);
	getchar();
	printf("| Modo de preparo: ");
	scanf("%699[a-zA-Z0-9 -.,]", rc->preparoCad);
	getchar();
	printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15): ");
	scanf("%5[0-9:]", rc->tempoCad);
	getchar();
	printf("| Quantas porções ela rende: ");
	scanf("%2[0-9]", rc->porcaoCad);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return rc;
}

void modulo_ver_receitas(void){
	struct receitas Receitas;
	int valiNmV;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> LEITURA DE RECEITAS <-                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que desejar verificar: ");
	scanf("%s", Receitas.nome);
	getchar();
	valiNmV = validarNome(Receitas.nome);
	if ((valiNmV) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_mod_receitas(void){
	struct receitas Receitas;
	int valiNmRD;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> MODIFICAÇÃO DE RECEITAS <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar: ");
	scanf("%s", Receitas.nome);
	getchar();
	valiNmRD = validarNome(Receitas.nome);
	if ((valiNmRD) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_del_receitas(void){
	struct receitas Receitas;
	int valiNmDR;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar: ");
	scanf("%s", Receitas.nome);
	getchar();
	valiNmDR = validarNome(Receitas.nome);
	if ((valiNmDR) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}