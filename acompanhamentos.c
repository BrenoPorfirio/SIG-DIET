#include <stdio.h>
#include <stdlib.h>
#include "acompanhamentos.h"
#include "funcoes.h"

//
//MODULO ACOMPANHAMENTO
//

typedef struct acompanhamento Acompanhamento;

char moduloAcompanhamento(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Iniciar avaliação antropométrica                                            |");
	printf("\n| 2-Visar avaliação                                                             |");
	printf("\n| 3-Editar avaliação                                                            |");
	printf("\n| 4-Deletar avaliação                                                           |");
	printf("\n| 5-Orientações físicas                                                         |");
	printf("\n| 6-Histórico                                                                   |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}


void cadAcompanhamento(void){
	Acompanhamento* ac;
	ac = cadastroAC();
	// gravar
	free(ac);
}

Acompanhamento *cadastroAC(void){
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	//float imc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> AVALIAÇÃO ANTROPOMÉTRICA <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	//printf("\n| Seu IMC atual %f=", imc); //apontador para IMC informado no cadastro do cliente
	getchar();
	printf("| Cadastre a medida da cintura atual: ");
	scanf("%7[0-9.,]", ac->acMedCintura);
	getchar();
	printf("| Cadastre a medida do quadril atual: ");
	scanf("%7[0-9.,]", ac->acMedQuadril);
	getchar();
	printf("| Cadastre a medida do bíceps direito atual: ");
	scanf("%6[0-9.,]", ac->acMedbicepsD);
	getchar();
	printf("| Cadastre a medida do bíceps esquerdo atual: ");
	scanf("%6[0-9.,]", ac->acMedbicepsE);
	getchar();
	printf("| Cadastre a medida da coxa direita atual: ");
	scanf("%6[0-9.,]", ac->acMedpernaD);
	getchar();
	printf("| Cadastre a medida da coxa esquerda atual: ");
	scanf("%6[0-9.,]", ac->acMedpernaE);
	printf("| MEDIDAS CADASTRADAS COM SUCESSO !");
	getchar();
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return ac;
}

void verAcompanhamento(void){
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	int verAvalia;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> CONSULTAR AVALIAÇÃO <-                          |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja ver informações: ");
	scanf("%[0-9]", ac->cpf);
	getchar();
	verAvalia = validaCPF(ac->cpf);
	if ((verAvalia) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modAcompanhamento(void){
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	int modAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                           -> MODIFICAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja modificar avaliação: ");
	scanf("%[0-9]", ac->cpf);
	getchar();
	modAC = validaCPF(ac->cpf);
	if ((modAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void delAcompanhamento(void){
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	int delAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar avaliação: ");
	scanf("%[0-9]", ac->cpf);
	getchar();
	delAC = validaCPF(ac->cpf);
	if ((delAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void orienta(void){ //AQUI SERÃO APRESENTADAS ORIENTAÇÕES DESTINADAS A DIETA FÍSICA
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	int orientAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> ORIENTAÇÕES <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para análise dos dados e indicações relacionadas ao físico: ");
	scanf("%[0-9]", ac->cpf);
	getchar();
	orientAC = validaCPF(ac->cpf);
	if ((orientAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void historico(void){ //LISTAGEM DE TODOS OS DADOS DO CLIENTE JUNTO DAS DATAS
	Acompanhamento* ac;
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	int histAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> HISTÓRICO <-                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para mostrar todo seu histórico: ");
	scanf("%[0-9]",ac->cpf);
	getchar();
	histAC = validaCPF(ac->cpf);
	if ((histAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}