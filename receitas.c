#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include"funcoes.h"

//
//MODULO RECEITAS
//

char moduloReceitas(void){
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
	return esc;
}

typedef struct receitas Receitas;
Receitas *cadastroRC();

void cadReceitas(void){
	Receitas* rc;
	rc = cadastroRC();
	gravaReceitas(rc);
	free(rc);
}

void verReceitas(void){
	Receitas* rc;
	rc = buscaReceitas();
	VReceitas(rc);
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
	printf("| Informe o ID da receita: ");
	scanf("%6[0-9]", rc->id);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return rc;
}

void gravaReceitas(Receitas* rc){
	FILE* RCT;
	RCT = fopen("receitas.dat", "ab");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	fwrite(rc, sizeof(Receitas), 1, RCT);
	fclose(RCT);
}

Receitas* buscaReceitas(void){
	FILE* RCT;
	Receitas* rc;
	char id[6];
	printf("\nInforme o id da receita: ");
	scanf("%s", id);
	rc = (Receitas*) malloc(sizeof(Receitas));
	RCT = fopen("receitas.dat", "rb");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	while(!feof(RCT)){
		fread(rc, sizeof(Receitas), 1, RCT);
		if (!strcmp(rc->id, id)){
			fclose(RCT);
			return rc;
		}
	}
	fclose(RCT);
	return NULL;
}

void VReceitas(Receitas* rc){
	if ((rc != NULL)){
		system("clear||cls");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n|                          -> LEITURA DE RECEITAS <-                            |");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n| Nome: %s", rc->nome);
		printf("\n| Ingredientes: %s", rc->ingredientesCad);
		printf("\n| Modo de preparo: %s", rc->preparoCad);
		printf("\n| Tempo de preparo: %s", rc->tempoCad);
		printf("\n| Quantidade de porções: %s", rc->porcaoCad);
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n->Pressione ENTER para continuar<-");
		getchar();
		getchar();
	} else {
		printf("Receita não existe");
		getchar();
	}
}

void modReceitas(void){
	Receitas* rc;
	rc = (Receitas*) malloc(sizeof(Receitas));	
	int valiNmRD;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> MODIFICAÇÃO DE RECEITAS <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar: ");
	scanf("%s", rc->nome);
	getchar();
	valiNmRD = validarNome(rc->nome);
	if ((valiNmRD) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void delReceitas(void){
	Receitas* rc;
	rc = (Receitas*) malloc(sizeof(Receitas));	int valiNmDR;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar: ");
	scanf("%s", rc->nome);
	getchar();
	valiNmDR = validarNome(rc->nome);
	if ((valiNmDR) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}