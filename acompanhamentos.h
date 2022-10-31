char modulo_acompanhamento(void);
void modulo_cad_acompanhamento(void);
void modulo_ver_acompanhamento(void);
void modulo_mod_acompanhamento(void);
void modulo_del_acompanhamento(void);
void modulo_orienta(void);
void modulo_historico(void);

typedef struct acompanhamento Acompanhamento;
struct acompanhamento {
	char acMedCintura[8]; 
	char acMedQuadril[8]; 
	char acMedbicepsD[7]; 
	char acMedbicepsE[7]; 
	char acMedpernaD[7]; 
	char acMedpernaE[7];
	char cpf[12];
};
Acompanhamento *cadastroAC();