#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "funcoes.h"


//+---------------+
//|MODULO CLIENTES|
//+---------------+

//Menu do módulo de clientes
char moduloClientes(void){
	char esc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Cliente                                                           |");
	printf("\n| 2-Ver Clientes                                                                |");
	printf("\n| 3-Modificar Cliente                                                           |");
	printf("\n| 4-Deletar Cliente                                                             |");
	printf("\n| 5-Relatório                                                                   |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	return esc;
}
typedef struct cliente Cliente;

Cliente *cadastro();

//Utilizado para cadastrar um cliente e então salva-lo em um arquivo ".dat"
void cadClientes(void){
	Cliente* cl;
	cl = cadastro();
	gravaClientes(cl);
	free(cl);
}

//Utilizado para visualizar o cadastro de um cliente especifico por meio de seu CPF
void verClientes(void){
	Cliente* cl;
	cl = buscaCliente();
	VCliente(cl);
	free(cl);
}

//Utilizado para realizar o cadastro de um cliente 
Cliente *cadastro(void) {
	Cliente* cl;
	cl = (Cliente*) malloc(sizeof(Cliente));
	int tam;
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> CADASTRO DE CLIENTES <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| CPF do cliente(somente números): ");
	scanf("%[0-9]", cl->cpf);
	getchar();
	if (!validaCPF(cl->cpf)) {
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(cl->cpf));
	//+---------+
	do {
	printf("| Nome completo: ");
	fgets(cl->nome, 60, stdin);
	tam = strlen(cl->nome);
	cl->nome[tam-1] = '\0';
	if (!validarNome(cl->nome)){
		printf("| Nome inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validarNome(cl->nome));
	//+---------+
	do {
	printf("| Telefone(FORMATO = 84999999999): ");
	scanf("%[0-9()]", cl->telefone);
	getchar();
	if (!validaTele(cl->telefone)){
		printf("| Telefone inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaTele(cl->telefone));
	//+---------+
	do {
	printf("| E-mail: ");
	scanf("%[a-zA-Z@.0-9_-]", cl->email);
	getchar();
	if (!validaemail(cl->email)){
		printf("| Email inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaemail(cl->email));
	//+---------+
	printf("| Sexo (m)asculino ou (f)eminino (m|f): ");
	scanf("%c", &cl->sexo);
	getchar();
	//+---------+
	do { 
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
	if (!testaData(cl->dia, cl->mes, cl->ano)) {
		printf("| Data inválida, tente novamente\n");
		printf("|\n");
	}
	} while (!testaData(cl->dia, cl->mes, cl->ano));
	//+---------+
	cl->status = 'c';
	//+---------+
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cl;
}

//Utilizado para gravar um cliente cadastrado em um arquivo ".dat"
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

//Utilizado para encontrar o cadastro de um cliente especifico
//por meio do CPF cadastrado
Cliente* buscaCliente(void){
	FILE* CLI;
	Cliente* cl;
	char cpf[12];
	//+---------+
	do{
	printf("| Informe o CPF do cliente que deseja ver: ");
	scanf("%s", cpf);
	if (!validaCPF(cpf)) {
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(cpf));
	//+---------+
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

//Utilizado para ver o cadastro individual de um cliente
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
		printf("\n| Sexo: %c", cl->sexo);
		printf("\n| Data de Nascimento: %02d/%02d/%d", cl->dia, cl->mes, cl->ano);
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

//Utilizado para modificar um cliente cadastrado
void modClientes(void){
	FILE* CLI;
	Cliente* cl;
	long int menosum = -1;
	char escolha;
	int achou;
	int tam;	
	char mCPF[12];
	//+---------+
	CLI = fopen("clientes.dat","r+b");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                    -> MODIFICAÇÃO DE DADOS DO CLIENTE <-                      |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| Insira o CPF que deseja modificar os dados do cliente: ");
	scanf("%11[^\n]", mCPF);
	getchar();
	if (!validaCPF(mCPF)) {
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(mCPF));
	//+---------+
	cl = (Cliente*) malloc(sizeof(Cliente));
	achou = 0;
	while((!achou) && (fread(cl, sizeof(Cliente), 1, CLI))) {
		if ((strcmp(cl->cpf, mCPF) == 0) && (cl->status != 'x')){
			achou = 1;
		}
	}
	if (achou) {
		//+---------+
		do {
		printf("| Nome completo: ");
		fgets(cl->nome, 60, stdin);
		tam = strlen(cl->nome);
		cl->nome[tam-1] = '\0';
		if (!validarNome(cl->nome)){
			printf("| Nome inválido, tente novamente\n");
			printf("|\n");
		}
		} while (!validarNome(cl->nome));
		//+---------+
		do {
		printf("| Telefone(somente números): ");
		scanf("%[0-9()]", cl->telefone);
		getchar();
		if (!validaTele(cl->telefone)){
			printf("| Telefone inválido, tente novamente\n");
			printf("|\n");
		}
		} while (!validaTele(cl->telefone));
		//+---------+
		do{
		printf("| E-mail: ");
		scanf("%[a-zA-Z@.0-9_-]", cl->email);
		getchar();
		if (!validaemail(cl->email)){
			printf("| Email inválido, tente novamente\n");
			printf("|\n");
		}
		} while (!validaemail(cl->email));
		//+---------+		
		printf("| Sexo (m)asculino ou (f)eminino (m|f): ");
		scanf("%c", &cl->sexo);
		getchar();
		//+---------+
		do { 
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
		if (!testaData(cl->dia, cl->mes, cl->ano)) {
			printf("Data inválida, tente novamente\n");
			printf("|\n");
		}
		} while (!testaData(cl->dia, cl->mes, cl->ano));
		//+---------+
		printf("| Informe o status do cliente -");
		printf("\n| (c)adastrado ou (d)esistiu (c|d): ");
		scanf("%c", &escolha);
		if (escolha == 'c' || escolha == 'C'){
			cl->status = 'c';
		} else if (escolha == 'd' || escolha == 'D'){
			cl->status = 'd';
		}
		//+---------+
		fseek(CLI, (menosum)*sizeof(Cliente), SEEK_CUR);
		fwrite(cl, sizeof(Cliente), 1, CLI);
		printf("|  -------------------- CLIENTE EDITADO COM SUCESSO --------------------  ");
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

//Utilizado para realizar a deleção lógica de um cliente
void delClientes(void){
	FILE* CLI;
	Cliente* cl;
	long int menosum = -1;
	char escolha;
	int achou;
	char dCPF[12];
	//+---------+
	CLI = fopen("clientes.dat","r+b");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE CLIENTES <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| Insira o CPF do cliente que deseja deletar: ");
	scanf("%11[^\n]", dCPF);
	getchar();
	if (!validaCPF(dCPF)) {
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(dCPF));
	//+---------+
	cl = (Cliente*) malloc(sizeof(Cliente));
	achou = 0;
	while((!achou) && (fread(cl, sizeof(Cliente), 1, CLI))) {
		if ((strcmp(cl->cpf, dCPF) == 0) && (cl->status != 'x')){
			exibeCliente(cl);
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
			printf("|  -------------------- CLIENTE DELETADO COM SUCESSO --------------------  ");
			getchar();
		} else {
			printf("\n| Cliente não apagado");
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

//Utilizado como template na listagem de relatórios
//para exibir clientes cadastrados e que desistiram
//tanto do sexo feminino quando masculino

void listaCLI(void){
	char esc;
	do{
		modListaClientes();
		printf("\n| Escolha a opção desejada: ");
		scanf("%c", &esc);
		getchar();
		switch(esc){
			case '1' : listaTODOS();
				break;
			case '2' : listaSEXO();
				break;
			case '3' : listaAlfaClien();
				break;
			case '4' : listaSTATUS();
				break;
			default:
				printf("| Escolha uma opção válida...");
				break;
		}	
	} while (esc != '0');
}
void modListaClientes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                      -> RELATÓRIO DE CLIENTES <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Listar todos os clientes                                                    |");
	printf("\n| 2-Listar por sexo                                                             |");
	printf("\n| 3-Listar por  ordem alfabética                                                |");
	printf("\n| 4-Listar por status                                                           |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
}
void exibeCliente(Cliente* cl) {
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| CPF: %s", cl->cpf);
	printf("\n| Nome: %s", cl->nome);
	printf("\n| Telefone: %s", cl->telefone);
	printf("\n| Email: %s", cl->email);
	printf("\n| Sexo: %c", cl->sexo);
	printf("\n| Data de Nascimento: %02d/%02d/%d", cl->dia, cl->mes, cl->ano);
	if (cl->status=='c'){
		printf("\n| Status: Cadastrado");
	} else if (cl->status=='d'){
		printf("\n| Status: Desistiu");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| ----- TECLE ENTER PARA EXIBIR O PRÓXIMO OU VOLTAR AO MENU -----");
}

void listaAlfaClien(void){
	FILE* CLI;
	Cliente* novocl;
	Cliente* lista;
	
	CLI = fopen("clientes.dat", "rb");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| RELATÓRIO DE TODOS OS CLIENTE POR ORDEM ALFABÉTICA");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	lista = NULL;
	novocl = (Cliente*) malloc(sizeof(Cliente));
	while(fread(novocl, sizeof(Cliente), 1, CLI)){
		if ((lista == NULL) || strcmp(novocl->nome, lista->nome) <0 ){
			novocl->prox = lista;
			lista = novocl;
		} else {
			Cliente* anter = lista;
			Cliente* atual = lista->prox;
			while ((atual != NULL) && strcmp(atual->nome,novocl->nome) <0 ){
				anter = atual;
				atual = atual->prox;
			}
		anter->prox = novocl;
		novocl->prox = atual;
		}
		novocl = (Cliente*) malloc(sizeof(Cliente));
	}
	fclose(CLI);
	novocl=lista;
	while (novocl != NULL){
		exibeCliente(novocl);
		getchar();
		novocl = novocl->prox;
	}
	novocl = lista;
	while(lista != NULL){
		lista = lista->prox;
		free(novocl);
		novocl = lista;
	}
}

void listaTODOS(void){
	FILE* CLI;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
	CLI = fopen("clientes.dat", "rb");
   	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n| RELATÓRIO DE TODOS OS CLIENTES ");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    while(fread(cl, sizeof(Cliente), 1, CLI)) {        
        exibeCliente(cl);
		getchar();
	}
    fclose(CLI);
    free(cl);
}

void listaSEXO(void){
	FILE* CLI;
	Cliente* cl;
	char sexo;

	cl = (Cliente*) malloc(sizeof(Cliente));
	CLI = fopen("clientes.dat", "rb");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| RELATÓRIO DE TODOS OS CLIENTES COM FILTRO DE SEXO");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| Deseja ver clientes (m)asculinos ou (f)emininos ? ");
	scanf("%c", &sexo);
	getchar();
	while (fread(cl, sizeof(Cliente), 1, CLI)){
		if (cl->sexo == sexo){
			exibeCliente(cl);
			getchar();
		}
	}
	fclose(CLI);
	free(cl);
}

void listaSTATUS(void){
	FILE* CLI;
	Cliente* cl;
	char status;

	cl = (Cliente*) malloc(sizeof(Cliente));
	CLI = fopen("clientes.dat", "rb");
	if (CLI == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| RELATÓRIO DE TODOS OS CLIENTES CADASTRADOS OU DESISTENTES");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| Deseja ver clientes (c)adastrados ou (d)esistentes ? ");
	scanf("%c", &status);
	getchar();
	while (fread(cl, sizeof(Cliente), 1, CLI)){
		if (cl->status == status){
			exibeCliente(cl);
			getchar();
		}
	}
	fclose(CLI);
	free(cl);
}