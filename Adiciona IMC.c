#include <stdio.h>

//|=================================================================================|
//|		Universidade Federal do Rio Grande do Norte (UFRN)							|
//|		Centro de Ensino Superior do Serido											|
//|		Departamento de Computacao e Tecnologia										|
//|		Disciplina DCT1106 -> Programacao											|
//|		Projeto Sistema de Planejamento de Dieta									|
//|		Developed by "BrenoPorfirio" and "GrandeDDD" (github) -> August, 2022		|
//|=================================================================================|
//|		Semana 1																	|
//|=================================================================================|

//MODULOS DAS FUNCOES
void modulo_menu(void);
void modulo_principal(void);
void modulo_imc(void);

//INICIO DO PROGRAMA
int main(void){
	modulo_menu();
	modulo_principal();
	modulo_imc();
	return 0;
}

//DEFININDO MODULOS
//MODULO DE MENU:
void modulo_menu(void){
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
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
}

//MODULO PRINCIPAL
void modulo_principal(void){
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|	Universidade Federal do Rio Grande do Norte (UFRN)                          |");
	printf("\n|	Centro de Ensino Superior do Serido                                         |");
	printf("\n|	Departamento de Computacao e Tecnologia                                     |");
	printf("\n|	Disciplina DCT1106 -> Programacao                                           |");
	printf("\n|	Projeto Sistema de Planejamento de Dieta                                    |");
	printf("\n|	Developed by BrenoPorfirio and GrandeDDD (github) -> August, 2022)          |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 	->Sistema de Gestao de Dietas<-                                             |");
	printf("\n|  1-Clientes                                                                   |");
	printf("\n|  2-Refeicoes                                                                  |");
	printf("\n|  3-Receitas                                                                   |");
	printf("\n|  0-Sair                                                                       |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
}

//MODULO IMC:
void modulo_imc(void){
	float imc, altura, peso;
  printf("\n\n\nDigite suas informacoes para calcularmos seu IMC");
  printf("\nExemplo de altura -> 1.78");
  printf("\nDigite a altura: ");//Necessário pontuacção por enquanto//
  scanf("%f", &altura);
  printf("Digite o peso: ");
  scanf("%f", &peso);

  imc = peso/(altura*altura);
  printf("IMC = %.2f", imc);
}
