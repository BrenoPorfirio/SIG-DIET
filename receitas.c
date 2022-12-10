#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include"funcoes.h"

//+---------------+
//|MODULO RECEITAS|
//+---------------+

//Menu do módulo de receitas
char moduloReceitas(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Receita                                                           |");
	printf("\n| 2-Ver Receitas                                                                |");
	printf("\n| 3-Modificar Receita                                                           |");
	printf("\n| 4-Deletar Receita                                                             |");
	printf("\n| 5-Listar Receitas                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	return esc;
}

typedef struct receitas Receitas;
Receitas *cadastroRC();

//Utilizado para cadastrar uma receita e então salva-la em arquivo ".dat"
void cadReceitas(void){
	Receitas* rc;
	rc = cadastroRC();
	gravaReceitas(rc);
	free(rc);
}

//Utilizado para realizar a leitura de uma receita individualmente por meio de seu código de cadastro
void verReceitas(void){
	Receitas* rc;
	rc = buscaReceitas();
	VReceitas(rc);
	free(rc);
}

//Utilizado para cadastrar uma receita
Receitas *cadastroRC(void){
	Receitas* rc;
	rc = (Receitas*) malloc(sizeof(Receitas));
	int tam;
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> CADASTRO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n");
	do {
		printf("| Nome da receita: ");
		//scanf("%s", rc->nome);
		fgets(rc->nome, 70, stdin);
		tam = strlen(rc->nome);
		rc->nome[tam-1] = '\0';
		if (!validarNome(rc->nome)){
			printf("| Nome inválido, tente novamente\n");
			printf("|\n");
		}
	} while (!validarNome(rc->nome));
	//+---------+
	printf("| Liste os ingrediente e quantidades (Separe os ingredientes por ;): ");
	scanf("%399[^\n]", rc->ingredientesCad);
	getchar();
	//+---------+
	printf("| Modo de preparo (Aperte Enter apenas quando finalizar): ");
	scanf("%999[^\n]", rc->preparoCad);
	getchar();
	//+---------+
	printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15): ");
	scanf("%5[0-9:]", rc->tempoCad);
	getchar();
	//+---------+
	printf("| Quantas porções ela rende: ");
	scanf("%2[0-9]", rc->porcaoCad);
	getchar();
	//+---------+
	printf("| Informe o ID da receita(Ex-> 00001): ");
	scanf("%5[0-9]", rc->id);
	getchar();
	//+---------+
	rc->status = 'c';
	//+---------+
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return rc;
}

//Utilizado para gravar uma receita cadastrada em um arquivo "".dat"
void gravaReceitas(Receitas* rc){
	FILE* RCT;
	RCT = fopen("receitas.dat", "ab");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	fwrite(rc, sizeof(Receitas), 1, RCT);
	fclose(RCT);
}

//Utilizado para encontrar uma receita especifica por meio de seu código de cadastro
Receitas* buscaReceitas(void){
	FILE* RCT;
	Receitas* rc;
	char id[6];
	//+---------+
	printf("\nInforme o id da receita: ");
	scanf("%s", id);
	rc = (Receitas*) malloc(sizeof(Receitas));
	RCT = fopen("receitas.dat", "rb");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	while(!feof(RCT)){
		fread(rc, sizeof(Receitas), 1, RCT);
		if (!strcmp(rc->id, id)){
			fclose(RCT);
			return rc;
		}
	}
	fclose(RCT);
	return NULL;
}

//Utilizado para realizar a leitura de uma receita individualmente
void VReceitas(Receitas* rc){
	if ((rc != NULL && rc->status=='c')){
		system("clear||cls");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n|                          -> LEITURA DE RECEITAS <-                            |");
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n| Nome: %s", rc->nome);
		printf("\n| Ingredientes: %s", rc->ingredientesCad);
		printf("\n| Modo de preparo: %s", rc->preparoCad);
		printf("\n| Tempo de preparo: %s", rc->tempoCad);
		printf("\n| Quantidade de porções: %s", rc->porcaoCad);
		if (rc->status=='c'){
			printf("\n| Status: Cadastrado");
		} else {
			printf("\n| Não encontrada");
		}
		printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
		printf("\n->Pressione ENTER para continuar<-");
		getchar();
		getchar();
	} else {
		printf("Receita não existe");
		getchar();
		getchar();
	}
}

//Utilizado para modificar uma receita existente
void modReceitas(void){
	FILE* RCT;
	Receitas* rc;
	long int menosum = -1;
	//char escolha;
	int achou;
	int tam;
	char mID[6];
	//+---------+
	RCT = fopen("receitas.dat","r+b");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> MODIFICAÇÃO DE RECEITAS <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o ID da receita que deseja modificar: ");
	scanf("%5[^\n]", mID);
	getchar();
	rc = (Receitas*) malloc(sizeof(Receitas));
	achou = 0;

	while((!achou) && (fread(rc, sizeof(Receitas), 1, RCT))) {
		if ((strcmp(rc->id, mID) == 0) && (rc->status != 'x')){
			achou = 1;
		}
	}

	if (achou){
		do {
			printf("| Nome da receita: ");
			fgets(rc->nome, 70, stdin);
			tam = strlen(rc->nome);
			rc->nome[tam-1] = '\0';
			if (!validarNome(rc->nome)){
				printf("| Nome inválido, tente novamente\n");
				printf("|\n");
			}
		} while (!validarNome(rc->nome));
		//+---------+
		printf("| Liste os ingrediente e quantidades(Separe os ingredientes por ;): ");
		scanf("%399[^\n]", rc->ingredientesCad);
		getchar();
		//+---------+
		printf("| Modo de preparo (Aperte Enter apenas quando finalizar): ");
		scanf("%999[^\n]", rc->preparoCad);
		getchar();
		//+---------+
		printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 01:15): ");
		scanf("%5[0-9:]", rc->tempoCad);
		getchar();
		//+---------+
		printf("| Quantas porções ela rende: ");
		scanf("%2[0-9]", rc->porcaoCad);
		getchar();
		//+---------+
		fseek(RCT, (menosum)*sizeof(Receitas), SEEK_CUR);
		fwrite(rc, sizeof(Receitas), 1, RCT);
		printf("| Receita editada com sucesso");
	} else {
		printf("| A receita não foi encotrada");
	}
	free(rc);
	fclose(RCT);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//Utilizado para deleção lógica de uma receita
void delReceitas(void){
	FILE* RCT;
	Receitas* rc;
	long int menosum = -1;
	char escolha;
	int achou;
	char dID[6];
	//int valiNmDR;
	//+---------+
	RCT = fopen("receitas.dat","r+b");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o ID da receita que deseja deletar: ");
	scanf("%5[^\n]", dID);
	getchar();
	rc = (Receitas*) malloc(sizeof(Receitas));
	achou =0;

	while((!achou) && (fread(rc, sizeof(Receitas), 1, RCT))) {
		if ((strcmp(rc->id, dID) == 0) && (rc->status != 'x')){
			achou = 1;
		}
	}

	if (achou) {
		printf("| Tem certeza que gostaria de apagar a receita? (s|n) ");
    	scanf("%c", &escolha);
		if (escolha=='s' || escolha=='S'){
			rc->status = 'x';
			fseek(RCT, (menosum)*sizeof(Receitas), SEEK_CUR);
			fwrite(rc, sizeof(Receitas), 1, RCT);
			printf("| -----Cliente deletado com sucesso-----");
			getchar();
		} else {
			printf("\n| Os dados não foram alterados");
			getchar();
		}
		
	} else {
		printf("Cliente não encontrado");
	}
	free(rc);
	fclose(RCT);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//Utilizado como template na listagem de receitas
void exibeReceitas(Receitas* rc) {
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n| Nome: %s", rc->nome);
	printf("\n| Ingredientes: %s", rc->ingredientesCad);
	printf("\n| Modo de preparo: %s", rc->preparoCad);
	printf("\n| Tempo de preparo: %s", rc->tempoCad);
	printf("\n| Quantidade de porções: %s", rc->porcaoCad);
	printf("\n| ID: %s", rc->id);
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n");
}

//Utilizada para listar todas as receitas cadastradas (listagem de receitas)
void listaReceitas(void){
	FILE* RCT;
	Receitas* rc;
	//char status;
	//+---------+
	RCT = fopen("receitas.dat", "rb");
	if (RCT == NULL){
		printf("\nErro na abertura do arquivo!");
		printf("\nImpossível continuar este programa...!");
		exit(1);
	}
	//+---------+
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                       -> LISTAGEM DE RECEITAS <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	rc = (Receitas*) malloc(sizeof(Receitas));
	while (fread(rc, sizeof(Receitas), 1, RCT)){
		if ((rc != NULL) && (rc->status=='c')){
			exibeReceitas(rc);
		}
	}
	getchar();
	free(rc);
	fclose(RCT);
}