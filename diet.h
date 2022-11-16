char moduloDiet(void);
void iniciarDiet(void);
void acompanhaDiet(void);
void editDiet(void);
void deletDiet(void);

typedef struct diet Diet;
struct diet {
    char cpf[12];   //retirar
    char nome[30];  //retirar
    // cod_dieta
    // nome_dieta
    // descricao_dieta
};
Diet *cadastroDT();
void gravaDiet(Diet*);
Diet* buscaDiet(void);
void VDiet(Diet*);