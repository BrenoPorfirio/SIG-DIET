#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

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