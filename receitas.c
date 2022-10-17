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
void modulo_cad_receitas(void){
	char nome[70], ingredientesCad[300], preparoCad[800], tempoCad[6], porcaoCad[3];
	int valiNmC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> CADASTRO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da receita: ");
	scanf("%s", nome);
	getchar();
	valiNmC = validarNome(nome);
	if ((valiNmC) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n| Liste os ingrediente e quantidades: ");
	scanf("%[a-zA-Z0-9 -.,]", ingredientesCad);
	getchar();
	printf("| Modo de preparo: ");
	scanf("%[a-zA-Z0-9 -.,]", preparoCad);
	getchar();
	printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15): ");
	scanf("%[0-9:]", tempoCad);
	getchar();
	printf("| Quantas porções ela rende: ");
	scanf("%[0-9]", porcaoCad);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_ver_receitas(void){
	char nome[70];
	int valiNmV;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> LEITURA DE RECEITAS <-                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que desejar verificar: ");
	scanf("%s", nome);
	getchar();
	valiNmV = validarNome(nome);
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
	char nome[70];
	int valiNmRD;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> MODIFICAÇÃO DE RECEITAS <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar: ");
	scanf("%s", nome);
	getchar();
	valiNmRD = validarNome(nome);
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
	char nome[70];
	int valiNmDR;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar: ");
	scanf("%s", nome);
	getchar();
	valiNmDR = validarNome(nome);
	if ((valiNmDR) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}