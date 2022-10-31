char moduloClientes(void);
typedef struct cliente Cliente;
struct cliente{
	char cpf[12];
	char nome[61];
	char telefone[20];
	char email[40];
};
Cliente *cadastro();
void cadClientes(void);
void verClientes(void);
void modClientes(void);
void delClientes(void);