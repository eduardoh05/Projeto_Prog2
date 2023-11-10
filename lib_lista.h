
#define MAX 30

struct lista{
    void * chave;
    lista* prox;
};

struct viatura{
    int codigo;
    bool tipoBool;
    char tipo[15];
};

struct policial{
    char nome[MAX+1];
    int cpf;
    char nome_de_guerra[MAX+1];
    char cidade[MAX+1];
    int idade;
    char cargo[MAX+1];
    char senha[MAX+1];
};

void inserir(lista*& lst, void* chave);

