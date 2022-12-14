char moduloClientes(void);
typedef struct cliente Cliente;

struct cliente{
	char cpf[12];
	char nome[61];
	char telefone[20];
	char email[40];
	char sexo;
	int dia;
	int mes;
	int ano;
	char status;
	Cliente *prox;
};
Cliente *cadastro();
void gravaClientes(Cliente*);
Cliente* buscaCliente(void);
void cadClientes(void);

void verClientes(void);
void VCliente(Cliente*);

void modClientes(void);

void delClientes(void);

void listaCLI(void);
void modListaClientes(void);
void listaTODOS(void);
void listaSEXO(void);
void listaSTATUS(void);
void exibeCliente(Cliente*);
void listaAlfaClien(void);