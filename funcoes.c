#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

//+--------------------+
//|FUNÇÕES DE VALIDAÇÃO|
//+--------------------+

//CÁLCULO IMC:
float calculoImc(float peso, float altura){
  return peso/(altura*altura);
}

//TESTA DATAS 
//BASEADO NO CÓDIGO DE FLAVIUS GORGÔNIO
int bissexto(int aa){
	if ((aa % 4 == 0) && (aa % 100 != 100)) {
		return 1;
	} else if (aa % 400 == 0){
		return 1;
	} else{
		return 0;
	}
}

//TESTA DATAS
//BASEADO NO CÓDIGO DE FLAVIUS GORGÔNIO
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

//BASEADO NO CÓDIGO DE BRUNOWCST
///https://github.com/Brunowcst/Sistema-de-controle-de-clientes-
//VALIDA CPF
int validaCPF(char *cpf){
  int i, j, digito1 = 0, digito2 =0;
  if(strlen(cpf) !=11)
    return 0;
  else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||(strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||(strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||(strcmp(cpf,"99999999999") == 0))
    return 0;
  else {
    for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--)
        digito1 += (cpf[i]-48) * j;
    digito1 %= 11;
    if(digito1 < 2)
        digito1 = 0;
    else
        digito1 = 11 - digito1;
    if((cpf[9]-48) != digito1)
        return 0;
    else {
      for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)
              digito2 += (cpf[i]-48) * j;
    digito2 %= 11;
    if(digito2 < 2)
        digito2 = 0;
    else
        digito2 = 11 - digito2;
    if((cpf[10]-48) != digito2)
        return 0;
        }
    }
    return 1;
}

//VALIDAR NOME
//BASEADO NO CÓDIGO DE FLAVIUS GORGÔNIO
int testaLetra(char c){
  if (c >= 'A' && c <= 'Z'){
    return 1;
  } else if (c >= 'a' && c <= 'z'){
    return 1;
  } else if (c == ' '){
    return 1;
  } else {
    return 0;
  }
}

//BASEADO NO CÓDIGO DE FLAVIUS GORGÔNIO
int validarNome(char *nome){
  for (int i=0; nome[i]!='\0'; i++){
    if (!testaLetra(nome[i])){
      printf("<%c>", nome[i]);
      return 0;
    }
  }
    return 1;
}

//VALIDA TELEFONE
int validaTele(char* fone){ 
  int tam;
  tam = strlen(fone);
  if (tam != 11){
    return 0;
  }
  for (int i=0; i < tam; i++){
    if (!ehDg(fone[i])) {
      return 0;
    }
  }
  return 1;
}
int ehDg(char c){
  if (c>= '0' && c <= '9'){
    return 1;
  } else {
    return 0;
  }
}

//VALIDAÇÃO DE EMAIL
//BASEADO NO CÓDIGO DE VICTOR RYAN
int validaemail(char* email){
    int i;
    i = '\0';
    while (email[i] != '\0'){
        if(((email[i] >= '@' ) && (email[i] <= 'z')) || (email[i] == '.')){
            i += 1;
        } 
        else if ((email[i] >= 'A' ) && (email[i] <= 'Z')){
            i += 1;
        }
        else if ((email[i] >= '0') && (email[i] <= '9')){
            i += 1;
        }
        else{
            return 0;
        }
    }
    return 1;
}

/*int validasexo(char* sexo){
  if (sexo == 'm' || sexo == 'M'){
    return 1;
  } else if (sexo == 'f' || sexo == 'F'){
    return 1;
  } else {
    return 0;
  }
}*/