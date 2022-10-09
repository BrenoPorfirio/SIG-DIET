#include <stdio.h>
#include <stdlib.h>
#include "diet.h"

//
//MODULO DIETAS
//
char modulo_diet(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Iniciar dieta                                                               |");
	printf("\n| 2-Acompanhar dieta                                                            |");
	printf("\n| 3-Editar dieta                                                                |");
	printf("\n| 4-Deletar dieta                                                               |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

void modulo_iniciar_diet(void){
	char cpfDiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> INICIAR DIETA <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe seu CPF para podermos dar início a sua dieta: ");
	scanf("%[0-9.-]", cpfDiet);
	getchar();
	// códgio onde mostrará o imc e medidas, e também, isso com apontadores ao que foi cadastrado no #mod_acompanhamento
	printf("|EXEMPLO DE TELA DA DIETA:");
	printf("\n| SUAS MEDIDAS ATUAIS: ");
	printf("\n|=-=-= SEU IMC ATUAL: 30.342 =-=-=");
	getchar();
	printf("|=-=-= CINTURA ATUAL: 100.98 =-=-=");
	getchar();
	printf("|=-=-= QUADRIL ATUAL: 89.42  =-=-=");
	getchar();
	printf("|Com base no seu IMC e medidas sua dieta ideal será: ");
	// código onde calculará uma dieta ideal, com base no imc e medidas
	printf("\n|SUA DIETA IDEAL É A DIETA MEDITERRÂNEA !");
	// código explicando como será está dieta.
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();
}

void modulo_acompanha_diet(void){
	char cpfACdiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> ACOMPANHAR DIETA <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para acompanhar sua dieta: ");
	scanf("%[0-9.-]", cpfACdiet);
	getchar();
	// aqui será o módulo onde veremos se a dieta está funcionando com base no histórico, e suas novas medidas
	printf("| SUA DIETA ESTÁ FUNCIONAL, CONTINUE NELA.");
	getchar();
	printf("| SUA DIETA NÃO ESTÁ FUNCIONANDO, TROQUE-A.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_edit_diet(void){
	char cpfEDdiet[15], nomeDiet[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> EDITAR DIETA <-                                 |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para editar sua dieta: ");
	scanf("%[0-9.-]", cpfEDdiet);
	getchar();
	// aqui será o módulo onde editaremos uma dieta caso ela não esteja funcionando.
	printf("| INFORME O NOME DA DIETA QUE NÃO FOI FUNCIONAL: ");
	scanf("%[a-z A-Z]", nomeDiet);
	getchar();
	printf("| JÁ QUE A DIETA ANTERIOR NÃO FUNCIONOU NÃO TENTE A: ");
	getchar();
	printf("| AQUI TERÁ UM IF DIRECIONANDO O CLIENTE A UMA NOVA DIETA.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_delet_diet(void){
	char delDiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR DIETA <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar dieta: ");
	scanf("%[0-9.-]", delDiet);
	// este módulo só será utilizado quando um cliente desistir 
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}