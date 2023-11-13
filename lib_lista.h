
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
    char boletimOcorrencia[51];
};

struct chamada{
    int tipo;
    int qtd_viaturas;
    char desc[MAX+1];
    char local[MAX+1];
};

struct viatura{
    int codigo;
    bool tipoBool;
    char policiais[4][MAX+1];
    char tipo[15];
    bool statusLivre = false;
    // struct chamada chamadaV;
};

struct pessoa{
    char nome[MAX+1];
    char cpf[12];
    char cidade[MAX+1];
    int idade;
    int qtdPassagens;
    char passagens[3][MAX+1];
    int qtdInad;
    char inadimplencias[3][MAX+1];
};

void inserir(lista*& lst, void* chave);
void inserirComeco(lista*& lst, void* chave);
void desalocar(lista*& lst);
