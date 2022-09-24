#include <stdio.h>
#include <stdlib.h>

//|=================================================================================|
//|     Universidade Federal do Rio Grande do Norte (UFRN)                          |
//|     Centro de Ensino Superior do Serido                                         |
//|     Departamento de Computacao e Tecnologia                                     |
//|     Disciplina DCT1106 -> Programacao                                           |
//|     Projeto Sistema de Planejamento de Dieta                                    |
//|     Developed by "BrenoPorfirio" and "GrandeDDD" (github) -> August, 2022       |
//|=================================================================================|
//|     Semana 4                                                                    |
//|=================================================================================|

//MODULOS DAS FUNCOES
void modulo_menu(void);
int modulo_principal(void);
char modulo_clientes(void);
char modulo_cad_clientes(void);
void modulo_ver_clientes(void);
void modulo_mod_clientes(void);
void modulo_del_clientes(void);
char modulo_refeicoes(void);
void modulo_cad_refeicoes(void);
void modulo_ver_refeicoes(void);
void modulo_mod_refeicoes(void);
void modulo_del_refeicoes(void);
char modulo_receitas(void);
void modulo_cad_receitas(void);
void modulo_ver_receitas(void);
void modulo_mod_receitas(void);
void modulo_del_receitas(void);
int modulo_imc(void);

//VARIAVEIS GLOBAIS

//INICIO DO PROGRAMA
int main(void){
	int num;
	char esc;
	num = modulo_principal();
	if (num==1){
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
	}
  	else if (num==2){
		esc = modulo_refeicoes();
		if (esc=='1'){
			modulo_cad_refeicoes();
		}
		else if (esc=='2'){
			modulo_ver_refeicoes();
		}
		else if (esc=='3'){
			modulo_mod_refeicoes();
		}
		else if (esc=='4'){
			modulo_del_refeicoes();
		}
  	}
  	else if (num==3){
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
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

//MODULO PRINCIPAL
int modulo_principal(void){
	int num;
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
	printf("\n\nEscolha uma opcao: ");
	scanf("%d", &num);
	getchar();
	return num;
}

//MODULO IMC:
int modulo_imc(void){
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
	if (imc<18.5){
		printf("\nSeu IMC encontra-se abaixo do peso");
	} else if (imc>=18.5 && imc<=24.9){
		printf("\nSeu IMC encontra-se normal");
	} else if (imc>=25.0 && imc<=29.9){
		printf("\nSeu IMC encontra-se em SOBREPESO");
	} else if (imc>=30.0 && imc<=34.9){
		printf("\nSeu IMC encontra-se em OBESIDADE GRAU I");
	} else if (imc>=35.0 && imc<=39.9){
		printf("\nSeu IMC encontra-se em OBESIDADE GRAU II");	
	} else {
		printf("\nSeu IMC encontra-se em OBESIDADE GRAU III");
	}

}

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
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

char modulo_cad_clientes(void){
	char cpfCad[11], nomeCad[40], telefoneCad[11], emailCad[30], nascimentoCad[11], pesoCad[5], alturaCad[4];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de clientes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| CPF do cliente(somente numeros): ");
	scanf("%s", cpfCad);
	printf("| Nome completo: ");
	scanf("%s", nomeCad);
	printf("| Telefone(somente numeros): ");
	scanf("%s", telefoneCad);
	printf("| E-mail: ");
	scanf("%s", emailCad);
	printf("| Data de nascimento(dd/mm/aaaa): ");
	scanf("%s", nascimentoCad);
	printf("| Peso do cliente(Ex-> 60.0): ");
	scanf("%s", pesoCad);
	printf("| Altura(Ex-> 1.70): ");
	scanf("%s", alturaCad);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cpfCad, nomeCad, telefoneCad, emailCad, nascimentoCad, pesoCad, alturaCad;
}

void modulo_ver_clientes(void){
	char cpfVer[11];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de clientes<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente: ");
	scanf("%s", cpfVer);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cpfVer;
}

void modulo_mod_clientes(void){
	char cpfMod[11];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de clientes<-                                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja modificar do cliente: ");
	scanf("%s", cpfMod);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cpfMod;
}

void modulo_del_clientes(void){
	char cpfDel[11];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de clientes<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF que deseja deletar do cliente: ");
	scanf("%s", cpfDel);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return cpfDel;
}

//
//MODULO REFEICOES
//
char modulo_refeicoes(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Refeicao                                                          |");
	printf("\n| 2-Ver Refeicoes                                                               |");
	printf("\n| 3-Modificar Refeicao                                                          |");
	printf("\n| 4-Deletar Refeicao                                                            |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}
void modulo_cad_refeicoes(void){
	char refeicaoCad[30], caloriasCad[6], cajCad[1];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de refeicoes<-                                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da refeicao: ");
	scanf("%s", refeicaoCad);
	printf("| Quantidade de calorias: ");
	scanf("%s", caloriasCad);
	printf("| Escolha uma opcao -> (c)afe, (a)lmoco, (j)anta ou (l)anche: ");
	scanf("%s", &cajCad);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return refeicaoCad[30], caloriasCad[6], cajCad;
}

void modulo_ver_refeicoes(void){
	char refeicaoVer[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de refeicoes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao: ");
	scanf("%s", refeicaoVer);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return refeicaoVer;
}

void modulo_mod_refeicoes(void){
	char refeicaoMod[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de refeicoes<-                                        |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao que deseja modificar: ");
	scanf("%s", refeicaoMod);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return refeicaoMod;
}

void modulo_del_refeicoes(void){
	char refeicaoDel[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de refeicoes<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da refeicao que deseja deletar: ");
	scanf("%s", refeicaoDel);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return refeicaoDel;
}

//
//MODULO RECEITAS
//
char modulo_receitas(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Cadastrar Receita                                                           |");
	printf("\n| 2-Ver Receitas                                                                |");
	printf("\n| 3-Modificar Receita                                                           |");
	printf("\n| 4-Deletar Receita                                                             |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opcao desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}
void modulo_cad_receitas(void){
	char nomereceitaCad[30], ingredientesCad[100], preparoCad[500], tempoCad[5], porcaoCad[2];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de cadastro de receitas<-                                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da receita: ");
	scanf("%s", nomereceitaCad);
	printf("| Liste os ingrediente e quantidades: ");
	scanf("%s", ingredientesCad);
	printf("| Modo de preparo: ");
	scanf("%s", preparoCad);
	printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15): ");
	scanf("%s", tempoCad);
	printf("| Quantas porcoes ela rende: ");
	scanf("%s", porcaoCad);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return nomereceitaCad, ingredientesCad, preparoCad, tempoCad, porcaoCad;
}

void modulo_ver_receitas(void){
	char nomereceitaVer[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de leitura de receitas<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita: ");
	scanf("%s", nomereceitaVer);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return nomereceitaVer;
}

void modulo_mod_receitas(void){
	char nomereceitaMod[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de modificacao de receitas<-                                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar: ");
	scanf("%s", nomereceitaMod);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return nomereceitaMod;
}

void modulo_del_receitas(void){
	char nomereceitaDel[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| ->Modulo de delecao de receitas<-                                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar: ");
	scanf("%s", nomereceitaDel);
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return nomereceitaDel;
}
