#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diet.h"

//
//MODULO DIETAS
//
char moduloDiet(void){
	char esc;
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| 1-Ver dietas cadastradas                                                      |");
	printf("\n| 0-Sair para o menu principal                                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n\nEscolha a opção desejada: ");
	scanf("%c", &esc);
	getchar();
	return esc;
}

void verDiet(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                     BEM VINDO A DIETA MEDITERRÂNEA                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Sua dieta consiste em mudar seu estilo de vida e melhorar seu metabolismo       ");
	printf("\n| assim, sua perda de peso e disposição surgem como consequência da vida saudável.");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -PEIXES E FRUTOS DO MAR");
	printf("\n| -AZEITE E GORDURAS BOAS");
	printf("\n| -ALIMENTOS INTEGRAIS");
	printf("\n| -FRUTAS E VERDURAS");
	printf("\n| -PROTEÍNAS E LEGUMINOSAS");
	printf("\n|");
	printf("\n| -------------------------- O QUE VOCÊ NÃO DEVE COMER: ---------------------------");
	printf("\n| -PRODUTOS INDUSTRIALIZADOS");
	printf("\n| -CARNES VERMELHAS");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| Seus pratos estão ligados a: ");
	printf("\n| -OSSOS MAIS FORTES");
	printf("\n| -CORAÇÃO MAIS SAUDÁVEL");
	printf("\n| -VIDA MAIS LONGA");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| TECLE ENTER PARA VER A PRÓXIMA DIETA");
	getchar();
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         BEM VINDO A DIETA DASH                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Propõe o baixo consumo de sódio, açúcares e de gordura saturada                 ");
	printf("\n| encontrada em frituras, carnes vermelhas e industrializados.                    ");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -CARNES MAGRAS");
	printf("\n| -OLEAGINOSAS");
	printf("\n| -FRUTAS, LEGUMES E VERDURAS");
	printf("\n| -LEITE E DERIVADOS MAGROS");
	printf("\n| -CEREAIS INTEGRAIS");
	printf("\n| -ÓLEOS VEGETAIS");
	printf("\n|");
	printf("\n| -------------------------- O QUE VOCÊ NÃO DEVE COMER: ---------------------------");
	printf("\n| -ALIMENTOS PREPARADOS COM FARINHA BRANCA, COMO PÃO, BISCOITOS E MACARRÃO");
	printf("\n| -ALIMENTOS RICOS EM GORDURA SATURADA");
	printf("\n| -DOCES E AÇUCAR");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| O principal objetivo da Dash não é o emagrecimento, mas a redução da pressão arterial."); 
	printf("\n| Assim, se a finalidade for apenas e perda de peso, é preciso fazer uma restrição de calorias.");
	printf("\n| -DIMINUIÇÃO NOS RISCOS DE OSTEOPOROSE");
	printf("\n| -COMBATER A OBESIDADE");
	printf("\n| -INCENTIVA O CONSUMO ADEQUADO DE GORDURAS E DO SAL.");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n| TECLE ENTER PARA VER A PRÓXIMA DIETA");
	getchar();
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                     BEM VINDO A DIETA FLEXITARIANA                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Uma dieta que reduz o consumo de carne vermelha sem abrir mão de proteína animal");
	printf("\n| combinação de “flexível” e “vegetariano”.                                       ");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -ALIMENTOS DE ORIGEM VEGETAL ");
	printf("\n| -FRUTAS, VERDURAS, LEGUMES");
	printf("\n| -GRÃOS, NOZES");
	printf("\n| -FRUTAS E VERDURAS");
	printf("\n| -PRODUTOS DE SOJA");
	printf("\n|");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| O flexitarianismo defende a adição de uma maior ");
	printf("\n| variedade de alimentos às refeições o que pode ser ");
	printf("\n| extremamente benéfico para a saúde.");
	printf("\n| -COMBATER O COLESTEROL ALTO ");
	printf("\n| -MANTER OS NÍVEIS DE COLESTEROL SAUDÁVEIS");
	printf("\n| -FORNECEM ÁCIDOS GRAXOS ESSENCIAIS");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	getchar();
}

void dietMediterranea(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                     BEM VINDO A DIETA MEDITERRÂNEA                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Sua dieta consiste em mudar seu estilo de vida e melhorar seu metabolismo       ");
	printf("\n| assim, sua perda de peso e disposição surgem como consequência da vida saudável.");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -PEIXES E FRUTOS DO MAR");
	printf("\n| -AZEITE E GORDURAS BOAS");
	printf("\n| -ALIMENTOS INTEGRAIS");
	printf("\n| -FRUTAS E VERDURAS");
	printf("\n| -PROTEÍNAS E LEGUMINOSAS");
	printf("\n|");
	printf("\n| -------------------------- O QUE VOCÊ NÃO DEVE COMER: ---------------------------");
	printf("\n| -PRODUTOS INDUSTRIALIZADOS");
	printf("\n| -CARNES VERMELHAS");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| Seus pratos estão ligados a: ");
	printf("\n| -OSSOS MAIS FORTES");
	printf("\n| -CORAÇÃO MAIS SAUDÁVEL");
	printf("\n| -VIDA MAIS LONGA");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	getchar();
}

void dietDash(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                         BEM VINDO A DIETA DASH                                  |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Propõe o baixo consumo de sódio, açúcares e de gordura saturada                 ");
	printf("\n| encontrada em frituras, carnes vermelhas e industrializados.                    ");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -CARNES MAGRAS");
	printf("\n| -OLEAGINOSAS");
	printf("\n| -FRUTAS, LEGUMES E VERDURAS");
	printf("\n| -LEITE E DERIVADOS MAGROS");
	printf("\n| -CEREAIS INTEGRAIS");
	printf("\n| -ÓLEOS VEGETAIS");
	printf("\n|");
	printf("\n| -------------------------- O QUE VOCÊ NÃO DEVE COMER: ---------------------------");
	printf("\n| -ALIMENTOS PREPARADOS COM FARINHA BRANCA, COMO PÃO, BISCOITOS E MACARRÃO");
	printf("\n| -ALIMENTOS RICOS EM GORDURA SATURADA");
	printf("\n| -DOCES E AÇUCAR");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| O principal objetivo da Dash não é o emagrecimento, mas a redução da pressão arterial."); 
	printf("\n| Assim, se a finalidade for apenas e perda de peso, é preciso fazer uma restrição de calorias.");
	printf("\n| -DIMINUIÇÃO NOS RISCOS DE OSTEOPOROSE");
	printf("\n| -COMBATER A OBESIDADE");
	printf("\n| -INCENTIVA O CONSUMO ADEQUADO DE GORDURAS E DO SAL.");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	getchar();
}

void dietflexitariana(void){
	system("clear||cls");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|                     BEM VINDO A DIETA FLEXITARIANA                              |");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	printf("\n|");
	printf("\n| Uma dieta que reduz o consumo de carne vermelha sem abrir mão de proteína animal");
	printf("\n| combinação de “flexível” e “vegetariano”.                                       ");
	printf("\n| -------------------------- O QUE VOCÊ DEVE COMER: -------------------------------");
	printf("\n| -ALIMENTOS DE ORIGEM VEGETAL ");
	printf("\n| -FRUTAS, VERDURAS, LEGUMES");
	printf("\n| -GRÃOS, NOZES");
	printf("\n| -FRUTAS E VERDURAS");
	printf("\n| -PRODUTOS DE SOJA");
	printf("\n|");
	printf("\n| ------------------------------ BENEFÍCIOS: --------------------------------------");
	printf("\n| O flexitarianismo defende a adição de uma maior ");
	printf("\n| variedade de alimentos às refeições o que pode ser ");
	printf("\n| extremamente benéfico para a saúde.");
	printf("\n| -COMBATER O COLESTEROL ALTO ");
	printf("\n| -MANTER OS NÍVEIS DE COLESTEROL SAUDÁVEIS");
	printf("\n| -FORNECEM ÁCIDOS GRAXOS ESSENCIAIS");
	printf("\n|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|");
	getchar();
}
