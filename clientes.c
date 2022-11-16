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
	printf("\n| 5-Listar Clientes                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
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
	printf("|");
	printf("\n| Informe sua data de nascimento - ");
	printf("\n| Dia: ");
	scanf("%d", &cl->dia);
	getchar();
	printf("| Mês: ");
	scanf("%d", &cl->mes);
	getchar();
	printf("| Ano: ");
	scanf("%d", &cl->ano);
	getchar();
	dataValida = testaData(cl->dia, cl->mes, cl->ano);
	if (!dataValida){
		printf("| A data %02d/%02d/%d == NOT OK \n", cl->dia, cl->mes, cl->ano);
		printf("\n| !! TENTE NOVAMENTE !!\n\n");
	} else {
		printf("| A data %02d/%02d/%d == OK", cl->dia, cl->mes, cl->ano);
	}
	getchar();
	printf("|");
	printf("\n| Hora de calcularmos seu IMC ");
	printf("\n| Informe seu peso atual: ");
	scanf("%f", &cl->peso);
	getchar();
	printf("| Informe sua altura atual: (EX-> 1.85) ");
	scanf("%f", &cl->altura);
	getchar();
	cl->imc = calculoImc(cl->peso, cl->altura);
	printf("| Resultado do IMC: %f", cl->imc);
  	if (cl->imc <18.5){
    printf("\n| Resultado: ABAIXO DO PESO");  
 	} else if (cl->imc >= 18.5 && cl->imc <= 24.9){
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
	printf("| Informe o CPF: ");
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
	if ((cl != NULL && cl->status=='c') || (cl != NULL && cl->status=='d')){
		system("clear||cls");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n|                          -> LEITURA DE CLIENTES <-                            |");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n| CPF: %s", cl->cpf);
		printf("\n| Nome: %s", cl->nome);
		printf("\n| Telefone: %s", cl->telefone);
		printf("\n| Email: %s", cl->email);
		printf("\n| Data de Nascimento: %02d/%02d/%d", cl->dia, cl->mes, cl->ano);
		printf("\n| Seu IMC atual:  %f", cl->imc);
		if (cl->status=='c'){
			printf("\n| Status: Cadastrado");
		} else if (cl->status=='d'){
			printf("\n| Status: Desistiu");
		} else {
			printf("\n| Não encontrada");
		}
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n->Pressione ENTER para continuar<-");
		getchar();
		getchar();
	} else {
		printf("| Cliente não cadastrado ou inexistente");
		getchar();
		getchar();
	}
}

void modClientes(void){
	FILE* CLI;
	Cliente* cl;
	//int modcpf;
	long int menosum = -1;
	char escolha;
	int achou;
	int tam;	
	int valtele;
	char valNome;
	int validaCpf;
	int dataValida;
	char mCPF[12];
	CLI = fopen("clientes.dat","r+b");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                    -> MODIFICAÇÃO DE DADOS DO CLIENTES <-                    |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja modificar os dados do cliente: ");
	scanf("%11[^\n]", mCPF);
	getchar();
	cl = (Cliente*) malloc(sizeof(Cliente));
	achou = 0;
	//modcpf = validaCPF(cl->cpf);
	//if ((modcpf) == 1){
	//	printf("| CPF ACEITO E CORRETO");
	//} else {
	//	printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	//}
	while((!achou) && (fread(cl, sizeof(Cliente), 1, CLI))) {
		if ((strcmp(cl->cpf, mCPF) == 0) && (cl->status != 'x')){
			achou = 1;
		}
	}
	if (achou) {
		//printf("|");
		printf("| CPF do cliente(somente números): ");
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
		printf("| Informe sua data de nascimento: ");
		printf("\n| Dia: ");
		scanf("%d", &cl->dia);
		getchar();
		printf("| Mês: ");
		scanf("%d", &cl->mes);
		getchar();
		printf("| Ano: ");
		scanf("%d", &cl->ano);
		getchar();
		dataValida = testaData(cl->dia, cl->mes, cl->ano);
		if (!dataValida){
			printf("| A data %02d/%02d/%d == NOT OK \n", cl->dia, cl->mes, cl->ano);
			printf("| !! TENTE NOVAMENTE !!");
		} else {
			printf("| A data %02d/%02d/%d == OK", cl->dia, cl->mes, cl->ano);
		}
		getchar();
		printf("| Informe seus dados para alterarmos seu IMC: ");
		printf("\n| Informe seu peso atual: ");
		scanf("%f", &cl->peso);
		getchar();
		printf("| Informe sua altura atual: (EX-> 1.85) ");
		scanf("%f", &cl->altura);
		getchar();
		cl->imc = calculoImc(cl->peso, cl->altura);
		printf("| Resultado do IMC: %f", cl->imc);
  		if (cl->imc <18.5){
    	printf("\n| Resultado: ABAIXO DO PESO");  
 		} else if (cl->imc >= 18.5 && cl->imc <= 24.9){
   		printf("\n| Resultado: PESO IDEAL");
		} else {
  	 	printf("\n| Resultado: SOBREPESO");
		}
		printf("|");
		printf("\n| Informe o status do cliente -");
		printf("\n| (c)adastrado ou (d)esistiu (c|d): ");
		scanf("%c", &escolha);
		if (escolha == 'c' || escolha == 'C'){
			cl->status = 'c';
		} else if (escolha == 'd' || escolha == 'D'){
			cl->status = 'd';
		}
		fseek(CLI, (menosum)*sizeof(Cliente), SEEK_CUR);
		fwrite(cl, sizeof(Cliente), 1, CLI);
		printf("| Cliente editado com sucesso");
		getchar();
	} else {
		printf("| O Cliente não foi encontrado");
	}
	free(cl);
	fclose(CLI);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void delClientes(void){
	FILE* CLI;
	Cliente* cl;
	long int menosum = -1;
	char escolha;
	int achou;
	char dCPF[12];
	CLI = fopen("clientes.dat","r+b");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE CLIENTES <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja deletar: ");
	scanf("%11[^\n]", dCPF);
	getchar();
	cl = (Cliente*) malloc(sizeof(Cliente));
	achou = 0;
	//modcpf = validaCPF(cl->cpf);
	//if ((modcpf) == 1){
	//	printf("| CPF ACEITO E CORRETO");
	//} else {
	//	printf("| CPF INCORRETO, TENTE NOVAMENTE !");
	//}
	while((!achou) && (fread(cl, sizeof(Cliente), 1, CLI))) {
		if ((strcmp(cl->cpf, dCPF) == 0) && (cl->status != 'x')){
			achou = 1;
		}
	}

	if (achou) {
		printf("| Tem certeza que gostaria de apagar o cliente? (s|n) ");
    	scanf("%c", &escolha);
		if (escolha=='s' || escolha=='S'){
			cl->status = 'x';
			fseek(CLI, (menosum)*sizeof(Cliente), SEEK_CUR);
			fwrite(cl, sizeof(Cliente), 1, CLI);
			printf("| -----Cliente deletado com sucesso-----");
			getchar();
		} else {
			printf("\n| Os dados não foram alterados");
			getchar();
		}
		
	} else {
		printf("Cliente não encontrado");
	}
	free(cl);
	fclose(CLI);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void exibeCliente(Cliente* cl) {
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| CPF: %s", cl->cpf);
	printf("\n| Nome: %s", cl->nome);
	printf("\n| Telefone: %s", cl->telefone);
	printf("\n| Email: %s", cl->email);
	printf("\n| Data de Nascimento: %02d/%02d/%d", cl->dia, cl->mes, cl->ano);
	printf("\n| Seu IMC atual:  %f", cl->imc);
	if (cl->status=='c'){
		printf("\n| Status: Cadastrado");
	} else if (cl->status=='d'){
		printf("\n| Status: Desistiu");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n");
}


void listaClientes(void){
	FILE* CLI;
	Cliente* cl;
	char status;
	CLI = fopen("clientes.dat", "rb");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                       -> LISTAGEM DE CLIENTES <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Deseja ver clientes cadastrados ou que desistiu? (c/d): ");
	scanf("%c", &status);
	getchar();
	cl = (Cliente*) malloc(sizeof(Cliente));
	while (fread(cl, sizeof(Cliente), 1, CLI)){
		if ((cl != NULL) && (cl->status=='c')){
			exibeCliente(cl);
		} else if ((cl != NULL) && (cl->status=='d')) {
			exibeCliente(cl);
		}
	}
	getchar();
	free(cl);
	fclose(CLI);
}