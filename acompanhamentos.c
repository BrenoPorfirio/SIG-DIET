#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "acompanhamentos.h"
#include "funcoes.h"
#include "diet.h"

//+---------------------+
//|MODULO ACOMPANHAMENTO|
//+---------------------+

typedef struct acompanhamento Acompanhamento;

//Menu do módulo de acompanhamento
char moduloAcompanhamento(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Iniciar avaliação antropométrica                                            |");
	printf("\n| 2-Visar avaliação                                                             |");
	printf("\n| 3-Editar avaliação                                                            |");
	printf("\n| 4-Deletar avaliação                                                           |");
	printf("\n| 5-Dieta indicada                                                              |");
	printf("\n| 6-Histórico                                                                   |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	return esc;
}

//Utilizado para buscar um acompanhamento e recomendar uma dieta
//baseado no IMC do cliente
void dietaInd(void){
	Acompanhamento* ac;
	ac = buscaAcompanhamento();
	dietaIndicada(ac);
	free(ac);
}

//Utilizado para cadastrar um acompanhamento e então salva-lo como um arquivo ".dat"
void cadAcompanhamento(void){
	Acompanhamento* ac;
	ac = cadastroAC();
	gravaAcompanhamento(ac);
	free(ac);
}

//Utilizado para buscar um acompanhamento das medidas de um cliente
//baseado em seu CPF
void verAcompanhamento(void){
	Acompanhamento* ac;
	ac = buscaAcompanhamento();
	VAcompanhamento(ac);
	free(ac);
}

//Utilizado para cadastrar um acompanhamento
Acompanhamento *cadastroAC(void){
	Acompanhamento* ac;
	int tam;
	//+---------+
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> AVALIAÇÃO ANTROPOMÉTRICA <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| CPF do cliente(somente números): ");
	scanf("%[0-9]", ac->cpf);
	getchar();
	if (!validaCPF(ac->cpf)){
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(ac->cpf));
	//+---------+
	do {
	printf("| Nome e sobrenome: ");
	fgets(ac->nome, 31, stdin);
	tam = strlen(ac->nome);
	ac->nome[tam-1] = '\0';
	if (!validarNome(ac->nome)) {
		printf("| Nome inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validarNome(ac->nome));
	//+---------+
	printf("| Cadastre a medida da cintura atual: ");
	scanf("%7[0-9.,]", ac->acMedCintura);
	getchar();
	//+---------+
	printf("| Cadastre a medida do quadril atual: ");
	scanf("%7[0-9.,]", ac->acMedQuadril);
	getchar();
	//+---------+
	printf("| Cadastre a medida do bíceps direito atual: ");
	scanf("%6[0-9.,]", ac->acMedbicepsD);
	getchar();
	//+---------+
	printf("| Cadastre a medida do bíceps esquerdo atual: ");
	scanf("%6[0-9.,]", ac->acMedbicepsE);
	getchar();
	//+---------+
	printf("| Cadastre a medida da coxa direita atual: ");
	scanf("%6[0-9.,]", ac->acMedpernaD);
	getchar();
	//+---------+
	printf("| Cadastre a medida da coxa esquerda atual: ");
	scanf("%6[0-9.,]", ac->acMedpernaE);
	getchar();
	//+---------+
	printf("| Agora vamos calcular seu IMC ");
	printf("\n| Informe seu peso atual: ");
	scanf("%f", &ac->peso);
	getchar();
	//+---------+
	printf("| Informe sua altura atual: (Exemplo = 1.85) ");
	scanf("%f", &ac->altura);
	getchar();
	//+---------+
	ac->imc = calculoImc(ac->peso, ac->altura);
	printf("| Resultado do IMC: %0.2f", ac->imc); 
	//+---------+
	time_t t;
	time(&t);
	printf("\n| Data e hora da avaliação: %s", ctime(&t));
	//+---------+
	ac->status = 'c';
	//+---------+
	printf("| MEDIDAS CADASTRADAS COM SUCESSO !");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return ac;
}

//Utilizado para gravar um acompanhamento em um arquivo ".dat"
void gravaAcompanhamento(Acompanhamento* ac){
	FILE* ACM;
	ACM = fopen("acompanhamento.dat", "ab");
	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	fwrite(ac, sizeof(Acompanhamento), 1, ACM);
	fclose(ACM);
}

//Utilizado para encontrar um acompanhamento baseado no CPF de um cliente
Acompanhamento* buscaAcompanhamento(void){
	FILE* ACM;
	Acompanhamento* ac;
	char cpf[12];
	//+---------+
	do{
	printf("| Informe o CPF do cliente que deseja ver sua avaliação: ");
	scanf("%s", cpf);
	if (!validaCPF(cpf)) {
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(cpf));
	//+---------+
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	ACM = fopen("acompanhamento.dat", "rb");
	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	while(!feof(ACM)){
		fread(ac, sizeof(Acompanhamento), 1, ACM);
		if (!strcmp(ac->cpf, cpf)){
			fclose(ACM);
			return ac;
		}
	}
	fclose(ACM);
	return NULL;
}

//Utilizado para ver um acompanhamento cadastrado
void VAcompanhamento(Acompanhamento* ac){
	if ((ac != NULL)){
		system("clear||cls");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n|                         -> LEITURA DE AVALIAÇÃO <-                            |");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n| Olá %s", ac->nome);
		printf("\n| Essas são suas medidas atuais");
		printf("\n| Seu IMC atual: %0.2f", ac->imc);
		printf("\n| Medida da cintura: %s", ac->acMedCintura);
		printf("\n| Medida do quadril: %s", ac->acMedQuadril);
		printf("\n| Medida do bíceps direito: %s", ac->acMedbicepsD);
		printf("\n| Medida do bíceps esquerdo: %s", ac->acMedbicepsE);
		printf("\n| Medida da coxa direita: %s", ac->acMedpernaD);
		printf("\n| Medida da coxa esquerda: %s", ac->acMedpernaE);
		if (ac->status=='c'){
			printf("\n| Status: Cadastrado");
		} else if (ac->status=='d'){
			printf("\n| Status: Desistiu");
		} else {
			printf("\n| Não encontrada");
		}
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n->Pressione ENTER para continuar<-");
		getchar();
		getchar();
	} else {
		printf("Cliente não existe");
		getchar();
	}
}

//Utilizado para modificar as medidas de um acompanhamento cadastrado
void modAcompanhamento(void){
	FILE* ACM;
	Acompanhamento* ac;
	long int menosum = -1;
	char escolha;
	int achou;
	int tam;	
	char mdCPF[12];
	//+---------+
	ACM = fopen("acompanhamento.dat","r+b");
	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                           -> MODIFICAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| Insira o CPF do cliente que deseja modificar a avaliação: ");
	scanf("%11[^\n]", mdCPF);
	getchar();
	if (!validaCPF(mdCPF)){
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(mdCPF));
	//+---------+
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	achou = 0;
	while((!achou) && (fread(ac, sizeof(Acompanhamento), 1, ACM))) {
		if ((strcmp(ac->cpf, mdCPF) == 0) && (ac->status != 'x')){
			achou = 1;
		}
	}
	if (achou) {
		//+---------+
		do {
		printf("| Nome e sobrenome: ");
		fgets(ac->nome, 31, stdin);
		tam = strlen(ac->nome);
		ac->nome[tam-1] = '\0';
		if (!validarNome(ac->nome)) {
			printf("| Nome inválido, tente novamente\n");
			printf("|\n");
		}
		} while (!validarNome(ac->nome));
		//+---------+
		printf("| Cadastre a medida da cintura atual: ");
		scanf("%7[0-9.,]", ac->acMedCintura);
		getchar();
		//+---------+
		printf("| Cadastre a medida do quadril atual: ");
		scanf("%7[0-9.,]", ac->acMedQuadril);
		getchar();
		//+---------+
		printf("| Cadastre a medida do bíceps direito atual: ");
		scanf("%6[0-9.,]", ac->acMedbicepsD);
		getchar();
		//+---------+
		printf("| Cadastre a medida do bíceps esquerdo atual: ");
		scanf("%6[0-9.,]", ac->acMedbicepsE);
		getchar();
		//+---------+
		printf("| Cadastre a medida da coxa direita atual: ");
		scanf("%6[0-9.,]", ac->acMedpernaD);
		getchar();
		//+---------+
		printf("| Cadastre a medida da coxa esquerda atual: ");
		scanf("%6[0-9.,]", ac->acMedpernaE);
		getchar();
		//+---------+
		printf("| Agora vamos calcular seu IMC ");
		printf("\n| Informe seu peso atual: ");
		scanf("%f", &ac->peso);
		getchar();
		//+---------+
		printf("| Informe sua altura atual: (Exemplo = 1.85) ");
		scanf("%f", &ac->altura);
		getchar();
		//+---------+
		ac->imc = calculoImc(ac->peso, ac->altura);
		printf("| Resultado do IMC: %0.2f", ac->imc);
		//+---------+
		printf("\n| Informe o status do cliente -");
		printf("\n| (c)adastrado ou (d)esistiu (c|d): ");
		scanf("%c", &escolha); 
		if (escolha == 'c' || escolha == 'C'){
			ac->status = 'c';
		} else if (escolha == 'd' || escolha == 'D'){
			ac->status = 'd';
		}
		//+---------+
		fseek(ACM, (menosum)*sizeof(Acompanhamento), SEEK_CUR);
		fwrite(ac, sizeof(Acompanhamento), 1, ACM);
		printf("|  -------------------- AVALIAÇÃO EDITADA COM SUCESSO --------------------  ");
		getchar();
	} else {
		printf("| Avaliação não foi encontrada");
	}
	free(ac);
	fclose(ACM);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//Utilizado para realizar a deleção lógica de um acompanhamento
void delAcompanhamento(void){
	FILE* ACM;
	Acompanhamento* ac;
	long int menosum = -1;
	char escolha;
	int achou;
	char delAC[12];
	//+---------+
	ACM = fopen("acompanhamento.dat","r+b");
	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	//+---------+
	do {
	printf("| Insira o CPF do cliente que deseja deletar sua avaliação: ");
	scanf("%11[^\n]", delAC);
	getchar();
	if (!validaCPF(delAC)){
		printf("| CPF inválido, tente novamente\n");
		printf("|\n");
	}
	} while (!validaCPF(delAC));
	//+---------+
	ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	achou = 0;
	while((!achou) && (fread(ac, sizeof(Acompanhamento), 1, ACM))) {
		if ((strcmp(ac->cpf, delAC) == 0) && (ac->status != 'x')){
			achou = 1;
		}
	}
	if (achou) {
		printf("| Tem certeza que gostaria de apagar a avaliação do cliente? (s|n) ");
    	scanf("%c", &escolha);
		if (escolha=='s' || escolha=='S'){
			ac->status = 'x';
			fseek(ACM, (menosum)*sizeof(Acompanhamento), SEEK_CUR);
			fwrite(ac, sizeof(Acompanhamento), 1, ACM);
			printf("|  -------------------- AVALIAÇÃO DELETADA COM SUCESSO --------------------  ");
			getchar();
		} else {
			printf("\n| A avaliação não foi apagada");
			getchar();
		}
	} else {
		printf("\n| Avaliação não foi encontrada");
		getchar();
	}
	free(ac);
	fclose(ACM);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//Utilizado para indicar uma dieta baseado no IMC do cliente em acompanhamento
void dietaIndicada(Acompanhamento* ac){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> DIETA INDICADA <-                               |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	if (ac->imc <= 18.5){
		printf("\n| Encontramos que seu IMC é = %0.2f", ac->imc);
		getchar();
		printf("\n| ------------------- PRESSIONE ENTER PARA VER SUA DIETA IDEAL------------------|");
		getchar();
		dietHipercalorica();
		printf("| Recomendamos a receita - Shake Hipercalorico (00006)");
		getchar();
		//+---------+
	} else if (ac->imc >= 18.6 && ac->imc <= 20.0){
		printf("\n| Encontramos que seu IMC é = %0.2f", ac->imc);
		getchar();
		printf("\n| ------------------- PRESSIONE ENTER PARA VER SUA DIETA IDEAL------------------|");
		getchar();
		dietHiperproteica();
		printf("| Recomendamos as receitas - Omelete Hiperproteico (00003) e Panqueca Proteica (00004)");
		getchar();
		//+---------+
	} else if (ac->imc >= 20.1 && ac->imc <= 24.9){
		printf("\n| Encontramos que seu IMC é = %0.2f", ac->imc);
		getchar();
		printf("\n| ------------------- PRESSIONE ENTER PARA VER SUA DIETA IDEAL------------------|");
		getchar();
		dietDash();
		printf("| Recomendamos a receita - Salada Dash (00005)");
		getchar();
		//+---------+
	} else if (ac->imc >= 25.0 && ac->imc <= 29.9){
		printf("\n| Encontramos que seu IMC é = %0.2f", ac->imc);
		getchar();
		printf("\n| ------------------- PRESSIONE ENTER PARA VER SUA DIETA IDEAL------------------|");
		getchar();
		dietMediterranea();
		printf("| Recomendamos as receitas - Salada Mediterranea (00001) e Sanduiche Mediterraneo (00002)");
		getchar();
		//+---------+
	} else if (ac->imc >= 30){
		printf("\n| Encontramos que seu IMC é = %0.2f", ac->imc);
		getchar();
		printf("\n| ------------------- PRESSIONE ENTER PARA VER SUA DIETA IDEAL------------------|");
		getchar();
		dietFlexitariana();
		printf("| Recomendamos as receitas - Hamburger Vegetariano (00007) e Escondidinho Vegetariano (00008)");
		getchar();
	}
}

void listaACC(void){
	char esc;
	do{
		submodACC();
		printf("\n| Escolha a opção desejada: ");
		scanf("%c", &esc);
		getchar();
		switch(esc){
			case '1' : listaTODOSAC();
				break;
			case '2' : listaUNI();
				break;
			default:
				printf("| Escolha uma opção válida...");
				break;
		}
	} while (esc != '0');
}

void submodACC(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> HISTÓRICO <-                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Listar todas as avaliações                                                  |");
	printf("\n| 2-Listar avaliações do cliente                                                |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
}

//Utilizado como template para o historico de acompanhamento
void exibeHistorico(Acompanhamento* ac) {
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| CPF: %s", ac->cpf);
	printf("\n| Nome e sobrenome: %s", ac->nome);
	printf("\n| Seu IMC atual: %0.2f", ac->imc);
	printf("\n| Medida da cintura: %s", ac->acMedCintura);
	printf("\n| Medida do quadril: %s", ac->acMedQuadril);
	printf("\n| Medida do bíceps direito: %s", ac->acMedbicepsD);
	printf("\n| Medida do bíceps esquerdo: %s", ac->acMedbicepsE);
	printf("\n| Medida da coxa direita: %s", ac->acMedpernaD);
	printf("\n| Medida da coxa esquerda: %s", ac->acMedpernaE);
	if (ac->status=='c'){
		printf("\n| Status: Cadastrado");
	} else if (ac->status=='d'){
		printf("\n| Status: Desistiu");
	} else {
		printf("\n| Não encontrada");
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

//Utilizado para mostrar o historico do acompanhamento de um cliente (historico de acompanhamento) 

void listaTODOSAC(void){
	FILE* ACM;
    Acompanhamento* ac;
    ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	ACM = fopen("acompanhamento.dat", "rb");
   	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n| HISTÓRICO DE TODOS OS CLIENTES ");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    while(fread(ac, sizeof(Acompanhamento), 1, ACM)) {        
        exibeHistorico(ac);
	}
	printf("\n| ----- TECLE ENTER PARA VOLTAR AO MENU -----");
	getchar();
    fclose(ACM);
    free(ac);
}

Acompanhamento* listaUNI(void){
	FILE* ACM;
    Acompanhamento* ac;
	char cpf[12];
    ac = (Acompanhamento*) malloc(sizeof(Acompanhamento));
	ACM = fopen("acompanhamento.dat", "rb");
   	if (ACM == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n| HISTÓRICO DE AVALIAÇÕES POR CLIENTE ");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	do{
		printf("|\n Informe o CPF do cliente que deseja ver sua avaliação: ");
		scanf("%s", cpf);
		if (!validaCPF(cpf)) {
			printf("| CPF inválido, tente novamente\n");
			printf("|\n");
		}
	} while (!validaCPF(cpf));
    while (fread(ac, sizeof(Acompanhamento), 1, ACM)){
		if (!strcmp(ac->cpf, cpf)){
			exibeHistorico(ac);
			getchar();
			printf("\n| ----- TECLE ENTER PARA VOLTAR AO MENU -----");
		}
	}
	return NULL;
	fclose(ACM);
	free(ac);
}