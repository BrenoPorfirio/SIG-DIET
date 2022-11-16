char moduloClientes(void);
typedef struct cliente Cliente;
struct cliente{
	char cpf[12];
	char nome[61];
	char telefone[20];
	char email[40];
	int dia;
	int mes;
	int ano;
	float peso;		// retirar
	float altura;	// retirar
	float imc;		// retirar
	char status;
};
Cliente *cadastro();
void gravaClientes(Cliente*);
Cliente* buscaCliente(void);
void cadClientes(void);
void verClientes(void);
void VCliente(Cliente*);
void modClientes(void);
void delClientes(void);
void listaClientes(void);
void exibeCliente(Cliente*);