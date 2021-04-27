#include <stdio.h>
#include <stdlib.h>
#include "TAD_arvore_binaria_busca.h"

void RotacaoEsquerda(TipoCelula **arvore, int *h);
void RotacaoDireita(TipoCelula **arvore, int *h);

//insere um elemento do tipo TipoItem na �rvore AVL
void InsereArvoreAVL(TipoCelula **arvore, TipoItem item, int *h)
{
    if (TestaArvoreBinariaBuscaVazia(arvore))
    {
        (*arvore) = (TipoCelula *)malloc(sizeof(TipoCelula));
        (*arvore)->item = item;
        (*arvore)->balanco = 0;
        (*arvore)->esquerda = NULL;
        (*arvore)->direita = NULL;
        *h = 1;
    }
    else if (item.chave < (*arvore)->item.chave)
    {
        InsereArvoreAVL(&(*arvore)->esquerda, item, h);
        if (*h)
            switch ((*arvore)->balanco)
            {
                case 1:
                { (*arvore)->balanco = 0; *h = 0; break; }
                case 0:
                { (*arvore)->balanco = -1; break; }
                case -1:
                { RotacaoDireita(arvore, h); break; }
            }
    }
    else if (item.chave > (*arvore)->item.chave)
    {
        InsereArvoreAVL(&(*arvore)->direita, item, h);
        if (*h)
            switch ((*arvore)->balanco)
            {
                case -1:
                { (*arvore)->balanco = 0; *h = 0; break; }
                case 0:
                { (*arvore)->balanco = 1; break; }
                case 1:
                { RotacaoEsquerda(arvore, h); break; }
            }
    }
    else
        printf("Erro: item existente\n");
}

//***** REMO��O DE N�S - IN�CIO *****

// REPARE QUE A REMO��O TEM O MESMO C�DIGO DA REMO��O EM "arvore_binaria_busca.c"
// A DIFEREN�A EST� NA INCLUS�O DOS TESTES PARA SABER SE � OU N�O NECESS�RIO EFETUAR ALGUMA ROTA��O
// SUSPEITO QUE O PROBLEMA ESTEJA NO VALOR DE h E/OU NO VALOR DO balanco

void Antecessor2(TipoCelula **arvore1, TipoCelula *arvore2);

//remove um elemento do tipo TipoItem da �rvore AVL
void RemoveArvoreAVL(TipoCelula **arvore, TipoItem item, int *h)
{
    TipoCelula *aux;

    if (TestaArvoreBinariaBuscaVazia(arvore))
    {
        printf("Erro: item inexistente\n");
        *h = 0;
    }
    else if (item.chave < (*arvore)->item.chave)
    {
        RemoveArvoreAVL(&(*arvore)->esquerda, item, h);
        if (*h)
            RotacaoEsquerda(arvore, h);
            switch ((*arvore)->balanco)
            {
                case 1:
                { (*arvore)->balanco = 0; break; }
                case 0:
                { /*(*arvore)->balanco = -1;*/ (*arvore)->balanco = 1; *h = 0; break; }
                case -1:
                { RotacaoEsquerda(arvore, h); break; }
                //{ (*arvore)->balanco = 0; break; }
            }
    }
    else if (item.chave > (*arvore)->item.chave)
    {
        RemoveArvoreAVL(&(*arvore)->direita, item, h);
        if (*h)
            RotacaoDireita(arvore, h);
            switch ((*arvore)->balanco)
            {
                case -1:
                { (*arvore)->balanco = 0; break; }
                case 0:
                { (*arvore)->balanco = 1; *h = 0; break; }
                case 1:
                { /*RotacaoDireita(arvore, h);*/ (*arvore)->balanco = 0; break; }
                //{ (*arvore)->balanco = 0; break; }
            }
    }
    else if (TestaArvoreBinariaBuscaVazia(&(*arvore)->direita))
    {
        aux = *arvore;
        *arvore = (*arvore)->esquerda;
        free(aux);
        *h = 1;
    }
    else if (!TestaArvoreBinariaBuscaVazia(&(*arvore)->esquerda))
    {
        Antecessor2(&(*arvore)->esquerda, *arvore);
        *h = 1;
    }
    else
    {
        aux = *arvore;
        *arvore = (*arvore)->direita;
        free(aux);
        *h = 1;
    }
}

//***** REMO��O DE N�S - FIM *****

    /*
    else //elemento a ser removido encontrado
    {
        if (TestaArvoreBinariaBuscaVazia((*arvore)->direita))
        {
            if (!TestaArvoreBinariaBuscaVazia((*arvore)->esquerda))
                //escolhe o n� � esquerda como substituto
                //raiz->esq->pai = raiz->pai;
            //raiz = raiz->esq;
            *h = 1;
        }
        else if (TestaArvoreBinariaBuscaVazia((*arvore)->esquerda))
        {
            if (!TestaArvoreBinariaBuscaVazia((*arvore)->direita))
                //escolhe o n� � direita como substituto
                //raiz->dir->pai = raiz->pai;
            //raiz = raiz->dir;
            *h = 1;
        }
        else
        {
            //busca pelo elemento mais � direita do n� esquerdo
            //raiz->esq = busca_remove(raiz->esq, raiz, h);
            //se necess�rio efetua balanceamento (esquerdo pois a fun��o busca_remove foi para o n� esquerdo)
            if (*h)
                RotacaoEsquerda(arvore, h);
        }
    }
    */


//------------------------------

void Antecessor2(TipoCelula **arvore1, TipoCelula *arvore2)
{
    if (!TestaArvoreBinariaBuscaVazia(&(*arvore1)->direita))
        Antecessor2(&(*arvore1)->direita, arvore2);
    else
    {
        arvore2->item = (*arvore1)->item;
        arvore2 = *arvore1 ;
        *arvore1 = (*arvore1)->esquerda;
        free(arvore2);
    }
}

void RotacaoEsquerda(TipoCelula **arvore, int *h)
{
    TipoCelula *no1;
    no1 = (*arvore)->direita;
    if (no1->balanco == 1)
    {
        // rota��o simples esquerda
        (*arvore)->direita = no1->esquerda;
        no1->esquerda = *arvore;
        (*arvore)->balanco = 0;
        (*arvore) = no1;
    }
    else
    {
        // rota��o dupla esquerda
        TipoCelula *no2;
        no2 = no1->esquerda;
        no1->esquerda = no2->direita;
        no2->direita = no1;
        (*arvore)->direita = no2->esquerda;
        no2->esquerda = *arvore;
        if (no2->balanco == 1)
            (*arvore)->balanco = -1;
        else
            (*arvore)->balanco = 0;
        if (no2->balanco == -1)
            no1->balanco = 1;
        else
            no1->balanco = 0;
        *arvore = no2;
    }
    (*arvore)->balanco = 0;
    *h = 0;
}

void RotacaoDireita(TipoCelula **arvore, int *h)
{
    TipoCelula *no1;
    no1 = (*arvore)->esquerda;
    if (no1->balanco == -1)
    {
        // rota��o simples direita
        (*arvore)->esquerda = no1->direita;
        no1->direita = *arvore;
        (*arvore)->balanco = 0;
        (*arvore) = no1;
    }
    else
    {
        // rota��o dupla direita
        TipoCelula *no2;
        no2 = no1->direita;
        no1->direita = no2->esquerda;
        no2->esquerda = no1;
        (*arvore)->esquerda = no2->direita;
        no2->direita = *arvore;
        if (no2->balanco == -1)
            (*arvore)->balanco = 1;
        else
            (*arvore)->balanco = 0;
        if (no2->balanco == 1)
            no1->balanco = -1;
        else
            no1->balanco = 0;
        *arvore = no2;
    }
    (*arvore)->balanco = 0;
    *h = 0;
}

//http://www.lcad.icmc.usp.br/~nonato/ED/AVL/algo-remocao.html
//remove um elemento do tipo TipoItem da �rvore AVL
/*
void RemoveArvoreAVL(TipoCelula **arvore, TipoItem item, int *h)
{
    if (TestaArvoreBinariaBuscaVazia(arvore)
    {
        printf("Erro: item inexistente\n");
        *h = 0;
    }
    else
    {
        if (item.chave < (*arvore)->item.chave)
        {
            RemoveArvoreAVL((*arvore)->esquerda, item, h);
            if (*h)
                RotacaoEsquerda(arvore, h);
        }
        else if (item.chave > (*arvore)->item.chave)
        {
            RemoveArvoreAVL((*arvore)->direita, item, h);
            if (*h)
                RotacaoDireita(arvore, h);
        }
        else
        { //Encontrou o elemento a ser removido
            if (TestaArvoreBinariaBuscaVazia((*arvore)->direita)
            {
                if (!TestaArvoreBinariaBuscaVazia((*arvore)->esquerda)) //Escolhe o n� � esquerda como substituto
              //      raiz->esq->pai = raiz->pai;
              //  raiz = raiz->esq;
                *h = 1;
            }
            else if (TestaArvoreBinariaBuscaVazia((*arvore)->esquerda))
            {
                if (!TestaArvoreBinariaBuscaVazia((*arvore)->direita)) //Escolhe o n� � direita como substituto
              //      raiz->dir->pai = raiz->pai;
              //  raiz = raiz->dir;
                *h = 1;
            }
            else
            { // Busca o elemento mais � direita do n� esquerdo
              //  raiz->esq = busca_remove(raiz->esq, raiz, h);
                //Se necess�rio efetua balanceamento (Esquerdo pois a fun��o
                //busca_remove foi para o n� esquerdo)
                if (*h)
                    RotacaoEsquerda(arvore, h);
            }
        }
    }
}
*/

