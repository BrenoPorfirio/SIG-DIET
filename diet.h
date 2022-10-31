char modulo_diet(void);
void modulo_iniciar_diet(void);
void modulo_acompanha_diet(void);
void modulo_edit_diet(void);
void modulo_delet_diet(void);

typedef struct diet Diet;
struct diet {
    char cpf[12];
    char nome[30];
};
Diet *cadastroDT();