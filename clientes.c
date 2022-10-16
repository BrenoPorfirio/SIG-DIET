#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "funcoes.h"

//
//MODULO CLIENTES:
//
char modulo_clientes(void){
	char esc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Cliente                                                           |");
	printf("\n| 2-Ver Clientes                                                                |");
	printf("\n| 3-Modificar Cliente                                                           |");
	printf("\n| 4-Deletar Cliente                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

void modulo_cad_clientes(void){
	char cpf[12], nome[60], telefoneCad[14], emailCad[40];
	char valNome;
	int validaCpf;
	int dataValida;
  	int dia, mes, ano;
	float imc, peso, altura;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> CADASTRO DE CLIENTES <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| CPF do cliente(somente números): ");
	scanf("%[0-9]", cpf);
	getchar();
	validaCpf = validaCPF(cpf);
	if (validaCpf){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n| Nome completo: ");
	scanf("%s", nome);
	getchar();
	valNome = validarNome(nome);
	if ((valNome) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n| Telefone(somente números): ");
	scanf("%[0-9()]", telefoneCad);
	getchar();
	printf("| E-mail: ");
	scanf("%[a-zA-Z@.0-9_-]", emailCad);
	getchar();
	printf("| Informe sua data de nascimento: ");
	printf("\n| Dia: ");
	scanf("%d", &dia);
	printf("| Mês: ");
	scanf("%d", &mes);
	printf("| Ano: ");
	scanf("%d", &ano);
	dataValida = testaData(dia, mes, ano);
	if (!dataValida){
		printf("| A data %02d/%02d/%d == NOT OK \n", dia, mes, ano);
		printf("\n| !! TENTE NOVAMENTE !!\n\n");
	} else {
		printf("| A data %02d/%02d/%d == OK\n", dia, mes, ano);
	}
	getchar();
	printf("|");
	printf("\n| Hora de calcularmos seu IMC ");
	printf("\n| Informe seu peso atual: ");
	scanf("%f", &peso);
	getchar();
	printf("| Informe sua altura atual: (EX-> 1.85) ");
	scanf("%f", &altura);
	getchar();
	imc = calculoImc(peso, altura);
	printf("| Resultado do IMC: %f", imc);
  	if (imc <18.5){
    printf("\n| Resultado: ABAIXO DO PESO");  
 	} else if (imc >= 18.5 && imc <= 24.9){
    printf("\n| Resultado: PESO IDEAL");
	} else {
    printf("\n| Resultado: SOBREPESO");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_ver_clientes(void){
	char cpfVer[12];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> LEITURA DE CLIENTES <-                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente: ");
	scanf("%[0-9]", cpfVer);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_mod_clientes(void){
	char cpfMod[12];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                    -> MODIFICAÇÃO DE DADOS DO CLIENTES <-                    |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja modificar os dados do cliente: ");
	scanf("%[0-9]", cpfMod);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_del_clientes(void){
	char cpfDel[12];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE CLIENTES <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja deletar: ");
	scanf("%[0-9]", cpfDel);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}