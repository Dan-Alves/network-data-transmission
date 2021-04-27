//TAD �rvore bin�ria de busca com aloca��o encadeada (din�mica)

//define a ordem de um TAD �rvore B
#define ORDEM 2

//tipo exportado
//define o TipoItem que � o tipo dos elementos do TAD �rvore bin�ria de busca (cl�ssica, AVL e B)
typedef struct
{
    int chave;
    char pacote;
    //outros campos
}TipoItem;

//tipo exportado
//define o TipoCelula que � o tipo das c�lulas que cont�m os elementos que s�o manipulados pelo TAD �rvore bin�ria de busca (cl�ssica ou AVL)
typedef struct celula
{
    TipoItem item;
    struct celula *esquerda;
    struct celula *direita;
    int balanco; // para o caso de a �rvore ser AVL
}TipoCelula;

//tipo exportado
//define o TipoPagina que � o tipo das p�ginas que cont�m os elementos que s�o manipulados pelo TAD �rvore B
typedef struct pagina
{
    int n;
    TipoItem itens[2 * ORDEM];
    struct pagina *paginas[2 * ORDEM + 1];
}TipoPagina;

//-----TAD �rvore bin�ria de busca-----

//fun��es exportadas
//cria uma �rvore bin�ria de busca vazia
void CriaArvoreBinariaBuscaVazia(TipoCelula **arvore);

//testa se a �rvore bin�ria de busca � vazia
int TestaArvoreBinariaBuscaVazia(TipoCelula **arvore);

//busca por um elemento na �rvore bin�ria de busca
TipoItem * BuscaArvoreBinariaBusca(TipoCelula **arvore, int chave);

//insere um elemento do tipo TipoItem na �rvore bin�ria de busca
void InsereArvoreBinariaBusca(TipoCelula **arvore, TipoItem item);

//remove um elemento do tipo TipoItem da �rvore bin�ria de busca
void RemoveArvoreBinariaBusca(TipoCelula **arvore, TipoItem item);

//imprime os elementos da �rvore bin�ria de busca
void ImprimeArvoreBinariaBusca(TipoCelula **arvore, int l);

//-----�rvore AVL-----

//insere um elemento do tipo TipoItem na �rvore AVL
void InsereArvoreAVL(TipoCelula **arvore, TipoItem item, int *h);

//remove um elemento do tipo TipoItem da �rvore AVL
void RemoveArvoreAVL(TipoCelula **arvore, TipoItem item, int *h);

//-----�rvore B-----

//cria uma �rvore B vazia
void CriaArvoreBVazia(TipoPagina **arvore);

//testa se a �rvore B � vazia
int TestaArvoreBVazia(TipoPagina **arvore);

//busca por um elemento na �rvore B
TipoItem * BuscaArvoreB(TipoPagina *arvore, int chave);

//insere um elemento do tipo TipoItem na �rvore B
void InsereArvoreB();//TipoCelula **arvore, TipoItem item, int *h);

//remove um elemento do tipo TipoItem da �rvore B
void RemoveArvoreB();//TipoCelula **arvore, TipoItem item, int *h);

//imprime os elementos da �rvore B
void ImprimeArvoreB(TipoPagina *arvore, int l);
