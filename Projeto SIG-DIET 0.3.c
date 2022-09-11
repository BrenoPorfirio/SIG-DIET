#include <stdio.h>
#include <stdlib.h>

//|=================================================================================|
//|		Universidade Federal do Rio Grande do Norte (UFRN)							|
//|		Centro de Ensino Superior do Serido											|
//|		Departamento de Computacao e Tecnologia										|
//|		Disciplina DCT1106 -> Programacao											|
//|		Projeto Sistema de Planejamento de Dieta									|
//|		Developed by "BrenoPorfirio" and "GrandeDDD" (github) -> August, 2022		|
//|=================================================================================|
//|		Semana 3																	|
//|=================================================================================|

//MODULOS DAS FUNCOES
void modulo_menu(void);
void modulo_principal(void);
void modulo_clientes(void);
void modulo_cad_clientes(void);
void modulo_ver_clientes(void);
void modulo_mod_clientes(void);
void modulo_del_clientes(void);
void modulo_refeicoes(void);
void modulo_cad_refeicoes(void);
void modulo_ver_refeicoes(void);
void modulo_mod_refeicoes(void);
void modulo_del_refeicoes(void);
void modulo_receitas(void);
void modulo_cad_receitas(void);
void modulo_ver_receitas(void);
void modulo_mod_receitas(void);
void modulo_del_receitas(void);
void modulo_imc(void);

//INICIO DO PROGRAMA
int main(void){
	modulo_principal();
	
	int num;
	printf("\n\nEscolha uma opcao: ");
	scanf("%d", &num);
	if (num==1){
	modulo_clientes();
	modulo_cad_clientes();
	modulo_ver_clientes();
	modulo_mod_clientes();
	modulo_del_clientes();
	}
  	else if (num==2){
	  modulo_refeicoes();
	  modulo_cad_refeicoes();
	  modulo_ver_refeicoes();
	  modulo_mod_refeicoes();
	  modulo_del_refeicoes();
  	}
  	else if (num==3){
	  modulo_receitas();
	  modulo_cad_receitas();
	  modulo_ver_receitas();
	  modulo_mod_receitas();
	  modulo_del_receitas();
  	}
  	else if (num==4){
	  modulo_imc();
  	}
  	else if (num==5){
	  modulo_menu();
	}
	return 0;
}

//Para copiar:
//printf("\n||");

//DEFININDO MODULOS
//MODULO DE MENU:
void modulo_menu(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Projeto: SIG-DietPlan                       |");
	printf("\n|                                             |");
	printf("\n| Descricao: Um sistema capaz auxiliar na     |");
	printf("\n| escolha de um cardapio dependendo das       |");
	printf("\n| restricoes impostas por um nutricionista.   |");
	printf("\n|                                             |");
	printf("\n| Programadores: Breno Costa (20220042506)    |");
	printf("\n|                Diego Alves (20220043174)    |");
	printf("\n|                                             |");
	printf("\n| Professor: Flavius da Luz e Gorgonio        |");
	printf("\n| (1687186)                                   |");
	printf("\n|                                             |");
	printf("\n| Programa produzido com intuito academico.   |");
	printf("\n|                                             |");
	printf("\n| Produzido sem fins comerciais em mente.     |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

//MODULO PRINCIPAL
void modulo_principal(void){
	system("clear||cls");
	printf("\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|	Universidade Federal do Rio Grande do Norte (UFRN)                      |");
	printf("\n|	Centro de Ensino Superior do Serido                                     |");
	printf("\n|	Departamento de Computacao e Tecnologia                                 |");
	printf("\n|	Disciplina DCT1106 -> Programacao                                       |");
	printf("\n|	Projeto Sistema de Planejamento de Dieta                                |");
	printf("\n|	Developed by BrenoPorfirio and GrandeDDD (github) -> August, 2022)      |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|       ->Sistema de Gestao de Dietas<-                                         |");
	printf("\n|  1-Clientes                                                                   |");
	printf("\n|  2-Refeicoes                                                                  |");
	printf("\n|  3-Receitas                                                                   |");
	printf("\n|  4-IMC                                                                        |");
	printf("\n|  5-Sobre este programa                                                        |");
	printf("\n|  0-Sair                                                                       |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
}

//MODULO IMC:
void modulo_imc(void){
	system("clear||cls");
	float imc, altura, peso;
	printf("\n\n\nDigite suas informacoes para calcularmos seu IMC");
	printf("\nExemplo de altura -> 1.78");
	printf("\nDigite a altura: ");//NecessÃ¡rio pontuacÃ§Ã£o por enquanto//
	scanf("%f", &altura);
	printf("Digite o peso: ");
	scanf("%f", &peso);
	
	imc = peso/(altura*altura);
	printf("IMC = %.2f", imc);
}

//
//MODULO CLIENTES:
//
void modulo_clientes(void){
	char num;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Cliente                                                           |");
	printf("\n| 2-Ver Clientes                                                                |");
	printf("\n| 3-Modificar Cliente                                                           |");
	printf("\n| 4-Deletar Cliente                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &num);
	getchar();
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_cad_clientes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de clientes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| CPF do cliente(somente numeros):                                              |");
	printf("\n| Nome completo:                                                                |");
	printf("\n| Telefone(somente numeros):                                                    |");
	printf("\n| E-mail:                                                                       |");
	printf("\n| Data de nascimento(dd/mm/aaaa):                                               |");
	printf("\n| Peso do cliente(Ex-> 60.0):                                                   |");
	printf("\n| Altura(Ex-> 1.70):                                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_ver_clientes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de clientes<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente:                                                      |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_mod_clientes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de clientes<-                                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja modificar do cliente:                                 |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_del_clientes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de clientes<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja deletar do cliente:                                   |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

//
//MODULO REFEICOES
//
void modulo_refeicoes(void){
	char num;	
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Refeicao                                                          |");
	printf("\n| 2-Ver Refeicoes                                                               |");
	printf("\n| 3-Modificar Refeicao                                                          |");
	printf("\n| 4-Deletar Refeicao                                                            |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &num);
	getchar();
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}
void modulo_cad_refeicoes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de refeicoes<-                                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da refeicao:                                                             |");
	printf("\n| Quantidade de calorias:                                                       |");
	printf("\n| Escolha uma opcao -> (c)afe, (a)lmoco, (j)anta ou (l)anche:                   |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_ver_refeicoes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de refeicoes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao:                                                    |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_mod_refeicoes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de refeicoes<-                                        |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao que deseja modificar:                               |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_del_refeicoes(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de refeicoes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao que deseja deletar:                                 |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

//
//MODULO RECEITAS
//
void modulo_receitas(void){
	char num;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Receita                                                           |");
	printf("\n| 2-Ver Receitas                                                                |");
	printf("\n| 3-Modificar Receita                                                           |");
	printf("\n| 4-Deletar Receita                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &num);
	getchar();
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}
void modulo_cad_receitas(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de receitas<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da receita:                                                              |");
	printf("\n| Liste os ingrediente e quantidades:                                           |");
	printf("\n| Modo de preparo:                                                              |");
	printf("\n| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15):                   |");
	printf("\n| Quantas porcoes ela rende:                                                    |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_ver_receitas(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de receitas<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita:                                                     |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_mod_receitas(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de receitas<-                                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar:                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}

void modulo_del_receitas(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de receitas<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar:                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\n->Precione ENTER para continuar<-");
	getchar();
}
