#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "acompanhamentos.h"
#include "receitas.h"
#include "diet.h"
#include "clientes.h"

//|=================================================================================|
//|     Universidade Federal do Rio Grande do Norte (UFRN)                          |
//|     Centro de Ensino Superior do Seridó                                         |
//|     Departamento de Computação e Tecnologia                                     |
//|     Disciplina DCT1106 -> Programação                                           |
//|     Projeto Sistema de Planejamento de Dietas                                   |
//|     Developed by "BrenoPorfirio" and "GrandeDDD" (github) -> August, 2022       |
//|=================================================================================|
//|     Semana 5                                                                    |
//|=================================================================================|

//MODULOS DAS FUNCOES
void modulo_menu(void);
int modulo_principal(void);

//INICIO DO PROGRAMA
int main(void){
	int num;
	char esc;
	do {
		num = modulo_principal();
		if (num==1){
			do{
				esc = modulo_clientes();
				if (esc=='1'){
					modulo_cad_clientes();
				}
				else if (esc=='2'){
					modulo_ver_clientes();
				}
				else if (esc=='3'){
					modulo_mod_clientes();
				}
				else if (esc=='4'){
					modulo_del_clientes();
				}
			} while (esc!='0');
		}
		else if (num==2){
			do {
				esc = modulo_acompanhamento();
				if (esc=='1'){
					modulo_cad_acompanhamento();
				}
				else if (esc=='2'){
					modulo_ver_acompanhamento();
				}
				else if (esc=='3'){
					modulo_mod_acompanhamento();
				}
				else if (esc=='4'){
					modulo_del_acompanhamento();
				}
				else if (esc=='5'){
					modulo_orienta();
				}
				else if (esc=='6'){
					modulo_historico();
				}
			} while (esc!='0');
		}
		else if (num==3){
			do {
				esc = modulo_receitas();
				if (esc=='1'){
					modulo_cad_receitas();
				}
				else if (esc=='2'){
					modulo_ver_receitas();
				}
				else if (esc=='3'){
					modulo_mod_receitas();
				}
				else if (esc=='4'){
					modulo_del_receitas();
				}
			} while (esc!='0');
		}
		else if (num==4){
			do{
				esc = modulo_diet();
				if (esc=='1'){
					modulo_iniciar_diet();
				} else if (esc=='2'){
					modulo_acompanha_diet();
				} else if (esc=='3'){
					modulo_edit_diet();
				} else if (esc=='4'){
					modulo_delet_diet();
				}
			} while (esc!='0');
		}
		else if (num==5){
			modulo_menu();
		}
		else if (num==0){
			printf("\nObrigado por usar nosso programa, até mais");
		}
	} while (num!=0);
	return 0;
}

//DEFININDO MODULOS
//MODULO DE MENU:
void modulo_menu(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Projeto: SIG-DietPlan                       |");
	printf("\n|                                             |");
	printf("\n| Descrição: Um sistema capaz auxiliar na     |");
	printf("\n| escolha de um cardápio dependendo das       |");
	printf("\n| restrições impostas por um nutricionista.   |");
	printf("\n|                                             |");
	printf("\n| Programadores: Breno Costa (20220042506)    |");
	printf("\n|                Diego Alves (20220043174)    |");
	printf("\n|                                             |");
	printf("\n| Professor: Flavius da Luz e Gorgonio        |");
	printf("\n| (1687186)                                   |");
	printf("\n|                                             |");
	printf("\n| Programa produzido com intuito acadêmico.   |");
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
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//MODULO PRINCIPAL
int modulo_principal(void){
	int num;
	system("clear||cls");
	printf("\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|	Universidade Federal do Rio Grande do Norte (UFRN)                      |");
	printf("\n|	Centro de Ensino Superior do Seridó                                     |");
	printf("\n|	Departamento de Computação e Tecnologia                                 |");
	printf("\n|	Disciplina DCT1106 -> Programação                                       |");
	printf("\n|	Projeto Sistema de Planejamento de Dietas                               |");
	printf("\n|	Developed by BrenoPorfirio and GrandeDDD (github) -> August, 2022)      |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|       ->Sistema de Gestão de Dietas<-                                         |");
	printf("\n|  1-Clientes                                                                   |");
	printf("\n|  2-Acompanhamento                                                             |");
	printf("\n|  3-Receitas                                                                   |");
	printf("\n|  4-Dietas                                                                     |");
	printf("\n|  5-Sobre este programa                                                        |");
	printf("\n|  0-Sair                                                                       |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha uma opção: ");
	scanf("%d", &num);
	getchar();
	return num;
}
