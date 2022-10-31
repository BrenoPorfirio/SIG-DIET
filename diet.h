char moduloDiet(void);
void iniciarDiet(void);
void acompanhaDiet(void);
void editDiet(void);
void deletDiet(void);

typedef struct diet Diet;
struct diet {
    char cpf[12];
    char nome[30];
};
Diet *cadastroDT();