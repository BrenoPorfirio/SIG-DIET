char moduloReceitas(void);
void cadReceitas(void);
void verReceitas(void);
void modReceitas(void);
void delReceitas(void);

typedef struct receitas Receitas;
struct receitas {
	char ingredientesCad[400];
	char preparoCad[1000];
	char tempoCad[6];
	char porcaoCad[3];
	char nome[71];
	char id[6];
	char status;
};
char moduloReceitas();
Receitas* cadastroRC();
void VReceitas(Receitas*);
void gravaReceitas(Receitas*);
Receitas* buscaReceitas(void);
void exibeReceitas(Receitas*);
void listaReceitas(void);