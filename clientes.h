char moduloClientes(void);
typedef struct cliente Cliente;
struct cliente{
	char cpf[12];
	char nome[61];
	char telefone[20];
	char email[40];
};
Cliente *cadastro();
void gravaClientes(Cliente*);
Cliente* buscaCliente(void);
void cadClientes(void);
void verClientes(void);
void VCliente(Cliente*);
void modClientes(void);
void delClientes(void);