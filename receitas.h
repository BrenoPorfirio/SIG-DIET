char modulo_receitas(void);
void modulo_cad_receitas(void);
void modulo_ver_receitas(void);
void modulo_mod_receitas(void);
void modulo_del_receitas(void);

typedef struct receitas Receitas;
struct receitas {
	char ingredientesCad[300];
	char preparoCad[800];
	char tempoCad[6];
	char porcaoCad[3];
	char nome[70];
};
char modulo_receitas();