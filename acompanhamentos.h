char moduloAcompanhamento(void);
void cadAcompanhamento(void);
void verAcompanhamento(void);
void modAcompanhamento(void);
void delAcompanhamento(void);
//void orienta(void);
void historico(void);
void dietaInd(void);
typedef struct acompanhamento Acompanhamento;

struct acompanhamento {
	char cpf[12];
	char nome[31];
	char acMedCintura[8]; 
	char acMedQuadril[8]; 
	char acMedbicepsD[7]; 
	char acMedbicepsE[7]; 
	char acMedpernaD[7]; 
	char acMedpernaE[7];
	float peso;
	float altura;
	float imc;
	char status;
};

Acompanhamento *cadastroAC();
void gravaAcompanhamento(Acompanhamento*);
Acompanhamento* buscaAcompanhamento(void);
void VAcompanhamento(Acompanhamento*);
void dietaIndicada(Acompanhamento*);
 void exibeHistorico(Acompanhamento*);