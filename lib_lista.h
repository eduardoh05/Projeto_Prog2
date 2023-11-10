
#define MAX 30

struct lista{
    void* chave;
    lista* prox;
};

struct policial{
    char nome[MAX+1];
    int cpf = 0;
    char nome_de_guerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
};

struct viatura{
    int codigo;
    bool tipoBool;
    policial policiais[4];
    char tipo[15];
};

struct chamada{
    int tipo;
    int qtd_viaturas;
    char desc[MAX+1];
    char local[MAX+1];
};


void inserir(lista*& lst, void* chave);

