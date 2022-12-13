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
};
// typedef struct nocliente NoCliente;

// struct nocliente{
// 	char cpf[12];
// 	char nome[61];
// 	char telefone[20];
// 	char email[40];
// 	char sexo;
// 	int dia;
// 	int mes;
// 	int ano;
// 	char status;
// 	NoCliente* prox;
// };

// NoCliente* listaAlfaClien(void);
Cliente *cadastro();
void gravaClientes(Cliente*);
Cliente* buscaCliente(void);
void cadClientes(void);
void verClientes(void);
void VCliente(Cliente*);
void modClientes(void);
void delClientes(void);
void relatorioClientes(void);
void exibeCliente(Cliente*);
void exibeClienteCF(Cliente*);
void exibeClienteCM(Cliente*);
void exibeClienteDF(Cliente*);
void exibeClienteDM(Cliente*);