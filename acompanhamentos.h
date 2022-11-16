char moduloAcompanhamento(void);
void cadAcompanhamento(void);
void verAcompanhamento(void);
void modAcompanhamento(void);
void delAcompanhamento(void);
void orienta(void);
void historico(void);

typedef struct acompanhamento Acompanhamento;
struct acompanhamento {
	char acMedCintura[8]; 
	char acMedQuadril[8]; 
	char acMedbicepsD[7]; 
	char acMedbicepsE[7]; 
	char acMedpernaD[7]; 
	char acMedpernaE[7];
	char cpf[12];
	// float peso;
	// float altura;
	// float imc;
	// data e hora
	// dieta sugerida (codigo)
};
Acompanhamento *cadastroAC();
void gravaAcompanhamento(Acompanhamento*);
Acompanhamento* buscaAcompanhamento(void);
void VAcompanhamento(Acompanhamento*);