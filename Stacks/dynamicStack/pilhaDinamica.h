/****************************************************************
Prototipos e definicoes das operacoes sobre Pilhas
*****************************************************************/

typedef char elem_t;
typedef struct no	{
	 elem_t info;
	 struct no *prox;
} No_lista;

typedef No_lista *Pilha;

/*Inicializa a pilha*/
void cria_pilha(Pilha *ps);
/*Verifica se a pilha esta' vazia*/
int pilha_vazia(Pilha *ps);
/*Verifica se a pilha esta' cheia*/
int pilha_cheia(Pilha *ps);
/*Adiciona um item na pilha*/
int insere_pilha(Pilha *ps, elem_t x);
/*Remove um item da pilha e retorna-o*/
elem_t remove_pilha(Pilha *ps);
/*Remove todos os elementos da Pilha*/
void libera_pilha(Pilha *ps);
/*Retorna o ultimo item da pilha*/
elem_t elemTopo(Pilha *ps);
