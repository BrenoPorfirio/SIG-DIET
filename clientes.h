char modulo_clientes(void);
typedef struct cliente Cliente;
struct cliente{
	char cpf[12];
	char nome[61];
	char telefone[20];
	char email[40];
};
Cliente *cadastro();
void modulo_cad_clientes(void);
void modulo_ver_clientes(void);
void modulo_mod_clientes(void);
void modulo_del_clientes(void);