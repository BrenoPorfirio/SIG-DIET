#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "funcoes.h"


//
//MODULO CLIENTES:
//
char moduloClientes(void){
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
typedef struct cliente Cliente;

Cliente *cadastro();


void cadClientes(void){
	Cliente* cl;
	cl = cadastro();
	gravaClientes(cl);
	free(cl);
}
void verClientes(void){
	Cliente* cl;
	cl = buscaCliente();
	VCliente(cl);
	free(cl);
}

Cliente *cadastro(void) {
	Cliente* cl;
	cl = (Cliente*) malloc(sizeof(Cliente));
	int valtele;
	char valNome;
	int validaCpf;
	int dataValida;
  	int dia, mes, ano;
	float imc, peso, altura;
	int tam;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> CADASTRO DE CLIENTES <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| CPF do cliente(somente números): ");
	scanf("%[0-9]", cl->cpf);
	getchar();
	validaCpf = validaCPF(cl->cpf);
	if ((validaCpf) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n| Nome completo: ");
	//scanf("%s[a-z A-Z]", cl->nome);
	fgets(cl->nome, 60, stdin);
	tam = strlen(cl->nome);
	cl->nome[tam-1] = '\0';
	//getchar();
	valNome = validarNome(cl->nome);
	if ((valNome) == 1){
		printf("| NOME OK!");
	} else {
		printf("| HÁ ALGO INCOMUM NO NOME INFORMADO!");
	}
	printf("\n| Telefone(somente números): ");
	scanf("%[0-9()]", cl->telefone);
	getchar();
	valtele = validaTele(cl->telefone);
	if ((valtele) == 1){
		printf("| NÚMERO CORRETO ! ");
	} else {
		printf("| NÚMERO INCORRETO ! ");
	}
	printf("\n| E-mail: ");
	scanf("%[a-zA-Z@.0-9_-]", cl->email);
	getchar();
	printf("\n| Informe sua data de nascimento: ");
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
	cl->status = 'c';
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cl;
}

void gravaClientes(Cliente* cl){
	FILE* CLI;
	CLI = fopen("clientes.dat", "ab");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	fwrite(cl, sizeof(Cliente), 1, CLI);
	fclose(CLI);
}

Cliente* buscaCliente(void){
	FILE* CLI;
	Cliente* cl;
	char cpf[12];
	printf("Informe o CPF: ");
	scanf("%s", cpf);
	cl = (Cliente*) malloc(sizeof(Cliente));
	CLI = fopen("clientes.dat", "rb");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	while(!feof(CLI)){
		fread(cl, sizeof(Cliente), 1, CLI);
		if (!strcmp(cl->cpf, cpf)){
			fclose(CLI);
			return cl;
		}
	}
	fclose(CLI);
	return NULL;
}

void VCliente(Cliente* cl){
	char situacao[20];
	if ((cl != NULL)){
		system("clear||cls");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n|                          -> LEITURA DE CLIENTES <-                            |");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n| CPF: %s", cl->cpf);
		printf("\n| Nome: %s", cl->nome);
		printf("\n| Telefone: %s", cl->telefone);
		printf("\n| Email: %s", cl->email);
		if (cl->status=='c'){
			strcpy(situacao, "Cadastrado");
		}// else if (cl->status=='d'){
		//	strcpy(situacao, "Desistiu");
		//} 
		else {
			strcpy(situacao, "Não encontrada");
		}
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n->Pressione ENTER para continuar<-");
		getchar();
		getchar();
	} else {
		printf("Cliente não cadastrado ou inexistente");
		getchar();
	}
}

void modClientes(void){
	Cliente* cl;
	cl = (Cliente*) malloc(sizeof(Cliente));	
	int modcpf;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                    -> MODIFICAÇÃO DE DADOS DO CLIENTES <-                    |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja modificar os dados do cliente: ");
	scanf("%[0-9]", cl->cpf);
	getchar();
	modcpf = validaCPF(cl->cpf);
	if ((modcpf) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void delClientes(void){
	Cliente* cl;
	cl = (Cliente*) malloc(sizeof(Cliente));	
	int delcpf;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE CLIENTES <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja deletar: ");
	scanf("%[0-9]", cl->cpf);
	getchar();
	delcpf = validaCPF(cl->cpf);
	if ((delcpf) == 1){
		printf("| CPF ACEITO E CORRETO");
	} else {
		printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}