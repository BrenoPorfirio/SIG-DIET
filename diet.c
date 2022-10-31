#include <stdio.h>
#include <stdlib.h>
#include "diet.h"
#include "funcoes.h"

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

typedef struct diet Diet;
Diet *cadastroDT();

void modulo_iniciar_diet(void){
	Diet* dt;
	dt = cadastroDT();
	free(dt);
}

Diet *cadastroDT(void){
	Diet* dt;
	dt = (Diet*) malloc(sizeof(Diet));
	int idcpf;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> INICIAR DIETA <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe seu CPF para podermos dar início a sua dieta: ");
	scanf("%[0-9]", dt->cpf);
	getchar();
	idcpf = validaCPF(dt->cpf);
	if ((idcpf) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	// códgio onde mostrará o imc e medidas, e também, isso com apontadores ao que foi cadastrado no #mod_acompanhamento
	printf("\n|EXEMPLO DE TELA DA DIETA:");
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
	return dt;
}

void modulo_acompanha_diet(void){
	struct diet Diet;
	int cpfACD;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> ACOMPANHAR DIETA <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para acompanhar sua dieta: ");
	scanf("%[0-9]", Diet.cpf);
	getchar();
	cpfACD = validaCPF(Diet.cpf);
	if ((cpfACD) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	// aqui será o módulo onde veremos se a dieta está funcionando com base no histórico, e suas novas medidas
	printf("\n| SUA DIETA ESTÁ FUNCIONAL, CONTINUE NELA.");
	getchar();
	printf("| SUA DIETA NÃO ESTÁ FUNCIONANDO, TROQUE-A.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_edit_diet(void){
	struct diet Diet;
	int cpfED;
	int valiNmD;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> EDITAR DIETA <-                                 |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para editar sua dieta: ");
	scanf("%[0-9]", Diet.cpf);
	getchar();
	cpfED = validaCPF(Diet.cpf);
	if ((cpfED) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	// aqui será o módulo onde editaremos uma dieta caso ela não esteja funcionando.
	printf("\n| INFORME O NOME DA DIETA QUE NÃO FOI FUNCIONAL: ");
	scanf("%s", Diet.nome);
	getchar();
	valiNmD = validarNome(Diet.nome);
	if ((valiNmD) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n| JÁ QUE A DIETA ANTERIOR NÃO FUNCIONOU NÃO TENTE A: ");
	getchar();
	printf("| AQUI TERÁ UM IF DIRECIONANDO O CLIENTE A UMA NOVA DIETA.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_delet_diet(void){
	struct diet Diet;
	int cpfDE;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR DIETA <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar dieta: ");
	scanf("%[0-9]", Diet.cpf);
	getchar();
	cpfDE = validaCPF(Diet.cpf);
	if ((cpfDE) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
} // este módulo só será utilizado quando um cliente desistir 