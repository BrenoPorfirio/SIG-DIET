#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

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
char modulo_clientes(void);
void modulo_cad_clientes(void);
void modulo_ver_clientes(void);
void modulo_mod_clientes(void);
void modulo_del_clientes(void);
char modulo_acompanhamento(void);
void modulo_cad_acompanhamento(void);
void modulo_ver_acompanhamento(void);
void modulo_mod_acompanhamento(void);
void modulo_del_acompanhamento(void);
void modulo_orienta(void);
void modulo_historico(void);
char modulo_receitas(void);
void modulo_cad_receitas(void);
void modulo_ver_receitas(void);
void modulo_mod_receitas(void);
void modulo_del_receitas(void);
char modulo_diet(void);
void modulo_iniciar_diet(void);
void modulo_acompanha_diet(void);
void modulo_edit_diet(void);
void modulo_delet_diet(void);


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

//CALCULO IMC:
float calculoImc(float peso, float altura){
  return peso/(altura*altura);
}

//TESTA DATAS (CREDITS TO FLAVIUS GORGONIO)
int bissexto(int aa){
	if ((aa % 4 == 0) && (aa % 100 != 100)) {
		return 1;
	} else if (aa % 400 == 0){
		return 1;
	} else{
		return 0;
	}
}

int testaData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11) {
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
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
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

void modulo_cad_clientes(void){
	char cpfCad[12], nomeCad[60], telefoneCad[14], emailCad[40];
	int dataValida;
  	int dia, mes, ano;
	float imc, peso, altura;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> CADASTRO DE CLIENTES <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| CPF do cliente(somente números): ");
	scanf("%[0-9]", cpfCad);
	getchar();
	printf("| Nome completo: ");
	scanf("%[a-z A-Z]", nomeCad);
	getchar();
	printf("| Telefone(somente números): ");
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

//
//MODULO ACOMPANHAMENTO
//
char modulo_acompanhamento(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Iniciar avaliação antropométrica                                            |");
	printf("\n| 2-Visar avaliação                                                             |");
	printf("\n| 3-Editar avaliação                                                            |");
	printf("\n| 4-Deletar avaliação                                                           |");
	printf("\n| 5-Orientações físicas                                                         |");
	printf("\n| 6-Histórico                                                                   |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}
void modulo_cad_acompanhamento(void){
	char acMedCintura[8], acMedQuadril[8], acMedbicepsD[7], acMedbicepsE[7], acMedpernaD[7], acMedpernaE[7];
	//float imc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> AVALIAÇÃO ANTROPOMÉTRICA <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	//printf("\n| Seu IMC atual %f=", imc); //apontador para IMC informado no cadastro do cliente
	getchar();
	printf("| Cadastre a medida da cintura atual: ");
	scanf("%[0-9.,]", acMedCintura);
	getchar();
	printf("| Cadastre a medida do quadril atual: ");
	scanf("%[0-9.,]", acMedQuadril);
	getchar();
	printf("| Cadastre a medida do bíceps direito atual: ");
	scanf("%[0-9.,]", acMedbicepsD);
	getchar();
	printf("| Cadastre a medida do bíceps esquerdo atual: ");
	scanf("%[0-9.,]", acMedbicepsE);
	getchar();
	printf("| Cadastre a medida da coxa direita atual: ");
	scanf("%[0-9.,]", acMedpernaD);
	getchar();
	printf("| Cadastre a medida da coxa esquerda atual: ");
	scanf("%[0-9.,]", acMedpernaE);
	printf("| MEDIDAS CADASTRADAS COM SUCESSO !");
	getchar();
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_ver_acompanhamento(void){
	char verAvalia[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> CONSULTAR AVALIAÇÃO <-                          |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja ver informações: ");
	scanf("%[0-9.-]", verAvalia);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_mod_acompanhamento(void){
	char modAvalia[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                           -> MODIFICAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o CPF do cliente que deseja modificar avaliação: ");
	scanf("%[0-9.-]", modAvalia);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_del_acompanhamento(void){
	char delAvalia[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR AVALIAÇÃO <-                           |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar avaliação: ");
	scanf("%[0-9.-]", delAvalia);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void modulo_orienta(void){ //AQUI SERÃO APRESENTADAS ORIENTAÇÕES DESTINADAS A DIETA FÍSICA
	char cpfOrient[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> ORIENTAÇÕES <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para análise dos dados e indicações relacionadas ao físico: ");
	scanf("%[0-9.-]", cpfOrient);
	getchar();
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}
void modulo_historico(void){ //LISTAGEM DE TODOS OS DADOS DO CLIENTE JUNTO DAS DATAS
	char cpfHis[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                              -> HISTÓRICO <-                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe o CPF do cliente para mostrar todo seu histórico: ");
	scanf("%[0-9.-]", cpfHis);
	getchar();
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
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
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}
void modulo_cad_receitas(void){
	char nomereceitaCad[70], ingredientesCad[300], preparoCad[800], tempoCad[6], porcaoCad[3];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                        -> CADASTRO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Nome da receita: ");
	scanf("%[a-z A-Z]", nomereceitaCad);
	getchar();
	printf("| Liste os ingrediente e quantidades: ");
	scanf("%[a-zA-Z0-9 -.,]", ingredientesCad);
	getchar();
	printf("| Modo de preparo: ");
	scanf("%[a-zA-Z0-9 -.,]", preparoCad);
	getchar();
	printf("| Tempo de preparo(Ex-> Uma hora e quinze minutos fica 1:15): ");
	scanf("%[0-9:]", tempoCad);
	getchar();
	printf("| Quantas porções ela rende: ");
	scanf("%[0-9]", porcaoCad);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_ver_receitas(void){
	char nomereceitaVer[70];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                          -> LEITURA DE RECEITAS <-                            |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que desejar verificar: ");
	scanf("%[a-z A-Z]", nomereceitaVer);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_mod_receitas(void){
	char nomereceitaMod[70];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> MODIFICAÇÃO DE RECEITAS <-                         |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja modificar: ");
	scanf("%[a-z A-Z]", nomereceitaMod);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

void modulo_del_receitas(void){
	char nomereceitaDel[70];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         -> DELEÇÃO DE RECEITAS <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira o nome da receita que deseja deletar: ");
	scanf("%[a-z A-Z]", nomereceitaDel);
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}

char modulo_diet(void){
	char esc;
	system("clear||cls");
	printf("\n\n\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Iniciar dieta                                                               |");
	printf("\n| 2-Acompanhar dieta                                                            |");
	printf("\n| 3-Editar dieta                                                                |");
	printf("\n| 4-Deletar dieta                                                               |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
	return esc;
}

//
//MODULO DIETAS
//
void modulo_iniciar_diet(void){
	char cpfDiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> INICIAR DIETA <-                                |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|Informe seu CPF para podermos dar início a sua dieta: ");
	scanf("%[0-9.-]", cpfDiet);
	getchar();
	// códgio onde mostrará o imc e medidas, e também, isso com apontadores ao que foi cadastrado no #mod_acompanhamento
	printf("|EXEMPLO DE TELA DA DIETA:");
	printf("\n| SUAS MEDIDAS ATUAIS: ");
	printf("\n|=-=-= SEU IMC ATUAL: 30.342 =-=-=");
	getchar();
	printf("|=-=-= CINTURA ATUAL: 100.98 =-=-=");
	getchar();
	printf("|=-=-= QUADRIL ATUAL: 89.42  =-=-=");
	getchar();
	printf("|Com base no seu IMC e medidas sua dieta ideal será: ");
	// código onde calculará uma dieta ideal, com base no imc e medidas
	printf("\n|SUA DIETA IDEAL É A DIETA MEDITERRÂNEA !");
	// código explicando como será está dieta.
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();
}

void modulo_acompanha_diet(void){
	char cpfACdiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> ACOMPANHAR DIETA <-                             |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para acompanhar sua dieta: ");
	scanf("%[0-9.-]", cpfACdiet);
	getchar();
	// aqui será o módulo onde veremos se a dieta está funcionando com base no histórico, e suas novas medidas
	printf("| SUA DIETA ESTÁ FUNCIONAL, CONTINUE NELA.");
	getchar();
	printf("| SUA DIETA NÃO ESTÁ FUNCIONANDO, TROQUE-A.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_edit_diet(void){
	char cpfEDdiet[15], nomeDiet[30];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                            -> EDITAR DIETA <-                                 |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Informe seu CPF para editar sua dieta: ");
	scanf("%[0-9.-]", cpfEDdiet);
	getchar();
	// aqui será o módulo onde editaremos uma dieta caso ela não esteja funcionando.
	printf("| INFORME O NOME DA DIETA QUE NÃO FOI FUNCIONAL: ");
	scanf("%[a-z A-Z]", nomeDiet);
	getchar();
	printf("| JÁ QUE A DIETA ANTERIOR NÃO FUNCIONOU NÃO TENTE A: ");
	getchar();
	printf("| AQUI TERÁ UM IF DIRECIONANDO O CLIENTE A UMA NOVA DIETA.");
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| -> Pressione ENTER para continuar<-");
	getchar();	
}

void modulo_delet_diet(void){
	char delDiet[15];
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                             -> DELETAR DIETA <-                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| Insira CPF do cliente que deseja deletar dieta: ");
	scanf("%[0-9.-]", delDiet);
	// este módulo só será utilizado quando um cliente desistir 
	getchar();
	printf("|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n->Pressione ENTER para continuar<-");
	getchar();
}