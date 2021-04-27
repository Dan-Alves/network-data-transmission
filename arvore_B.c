#include <stdio.h>
#include "TAD_arvore_binaria_busca.h"

//cria uma árvore B vazia
void CriaArvoreBVazia(TipoPagina **arvore)
{
    *arvore = NULL;
}

//testa se a árvore B é vazia
int TestaArvoreBVazia(TipoPagina **arvore)
{
    return (*arvore == NULL);
}

//busca por um elemento na árvore B
TipoItem * BuscaArvoreB(TipoPagina *arvore, int chave)
{
    int i = 1;
    if (TestaArvoreBVazia(arvore))
        printf("Erro: item inexistente\n");
    while (i < arvore->n && chave > arvore->itens[i - 1].chave)
        i++;
    if (chave == arvore->itens[i - 1].chave)
        return &arvore->itens[i - 1];
    if (chave < arvore->itens[i - 1].chave)
        BuscaArvoreB(arvore, arvore->itens[i - 1].chave);
    else
        BuscaArvoreB(arvore, arvore->itens[i].chave);
}

//insere um elemento do tipo TipoItem na árvore B
void InsereArvoreB()//TipoCelula **arvore, TipoItem item, int *h);
{

}

//remove um elemento do tipo TipoItem da árvore B
void RemoveArvoreB()//TipoCelula **arvore, TipoItem item, int *h);
{

}

//imprime os elementos da árvore B
void ImprimeArvoreB(TipoPagina *arvore, int l)
{
    //MODIFICAR PARA ÁRVORE B
    /*
    int i;

    if(!TestaArvoreBinariaBuscaVazia(arvore))
    {
        ImprimeArvoreBinariaBusca(&(*arvore)->esquerda, l + 1);
        for (i = 0; i < l; i++)
            printf("   ");
        printf("%i\n", (*arvore)->item.chave);
        ImprimeArvoreBinariaBusca(&(*arvore)->direita, l + 1);
    }
    */
}
