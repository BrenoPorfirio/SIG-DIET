char moduloReceitas(void);
void cadReceitas(void);
void verReceitas(void);
void modReceitas(void);
void delReceitas(void);

typedef struct receitas Receitas;
struct receitas {
	char ingredientesCad[300];
	char preparoCad[800];
	char tempoCad[6];
	char porcaoCad[3];
	char nome[70];
};
char moduloReceitas();