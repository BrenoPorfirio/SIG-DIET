#include <stdio.h>
#include <stdlib.h>
#include "acompanhamentos.h"
#include "funcoes.h"

//
//MODULO ACOMPANHAMENTO
//
char modulo_acompanhamento(void){
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
void modulo_cad_acompanhamento(void){
	char acMedCintura[8], acMedQuadril[8], acMedbicepsD[7], acMedbicepsE[7], acMedpernaD[7], acMedpernaE[7];
	//float imc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> AVALIAÇÃO ANTROPOMÉTRICA <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	//printf("\n| Seu IMC atual %f=", imc); //apontador para IMC informado no cadastro do cliente
	getchar();
	printf("| Cadastre a medida da cintura atual: ");
	scanf("%[0-9.,]", acMedCintura);
	getchar();
	printf("| Cadastre a medida do quadril atual: ");
	scanf("%[0-9.,]", acMedQuadril);
	getchar();
	printf("| Cadastre a medida do bíceps direito atual: ");
	scanf("%[0-9.,]", acMedbicepsD);
	getchar();
	printf("| Cadastre a medida do bíceps esquerdo atual: ");
	scanf("%[0-9.,]", acMedbicepsE);
	getchar();
	printf("| Cadastre a medida da coxa direita atual: ");
	scanf("%[0-9.,]", acMedpernaD);
	getchar();
	printf("| Cadastre a medida da coxa esquerda atual: ");
	scanf("%[0-9.,]", acMedpernaE);
	printf("| MEDIDAS CADASTRADAS COM SUCESSO !");
	getchar();
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_ver_acompanhamento(void){
	char cpf[12];
	int verAvalia;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> CONSULTAR AVALIAÇÃO <-                          |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja ver informações: ");
	scanf("%[0-9]", cpf);
	getchar();
	verAvalia = validaCPF(cpf);
	if ((verAvalia) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_mod_acompanhamento(void){
	char cpf[12];
	int modAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                           -> MODIFICAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja modificar avaliação: ");
	scanf("%[0-9]", cpf);
	getchar();
	modAC = validaCPF(cpf);
	if ((modAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_del_acompanhamento(void){
	char cpf[12];
	int delAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar avaliação: ");
	scanf("%[0-9]", cpf);
	getchar();
	delAC = validaCPF(cpf);
	if ((delAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void modulo_orienta(void){ //AQUI SERÃO APRESENTADAS ORIENTAÇÕES DESTINADAS A DIETA FÍSICA
	char cpf[12];
	int orientAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> ORIENTAÇÕES <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para análise dos dados e indicações relacionadas ao físico: ");
	scanf("%[0-9]", cpf);
	getchar();
	orientAC = validaCPF(cpf);
	if ((orientAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void modulo_historico(void){ //LISTAGEM DE TODOS OS DADOS DO CLIENTE JUNTO DAS DATAS
	char cpf[12];
	int histAC;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> HISTÓRICO <-                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para mostrar todo seu histórico: ");
	scanf("%[0-9]", cpf);
	getchar();
	histAC = validaCPF(cpf);
	if ((histAC) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}