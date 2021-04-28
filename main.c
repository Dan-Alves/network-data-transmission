#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "TAD_arvore_binaria_busca.h"

void embaralha(char *s, int *numReplicacoes, TipoItem *item);
void imprimiNumReplicacoes(int *numReplicacoes, int tam);
void imprimiChave(TipoItem *item, int tam);
void imprimiMensagem(char* s, int tam);

int main(void)
{
    setlocale(LC_ALL, "");

    int i, *numReplicacoes, tam;
    char str[50];
    TipoItem *item1, *item2;

    /*printf("---------------------------\n");
    printf("  Árvore Binária de Busca\n");
    printf("---------------------------\n");*/

    printf("\n Entre com a msg: ");
    gets(str);

    tam = strlen(str);

    printf("\n MENSAGEM: \n");
    imprimiMensagem(str, tam);

    item1 = malloc(tam * sizeof(TipoItem));
    numReplicacoes = malloc(tam * sizeof(int));
    srand(time(NULL));

    /* Preenche item */
    for(i = 0; i < strlen(str); i++){
        item1[i].chave = i+1;
        item1[i].pacote = str[i];
        numReplicacoes[i] = 1 + (rand() % 10);
    }

    /* Embaralha e imprime mensagem */
    embaralha(str, numReplicacoes, item1);
    printf("\n\n MENSAGEM EMBARALHADA E ID: \n", str);
    imprimiMensagem(str, tam);printf("\n");
    imprimiChave(item1, tam);


    TipoCelula **arvore1 = (TipoCelula **)malloc(sizeof(TipoCelula *));

    printf("\n\n Criação da árvore vazia\n");
    CriaArvoreBinariaBuscaVazia(arvore1);
    printf("\n Verificação se a árvore criada é vazia -> %i\n", TestaArvoreBinariaBuscaVazia(arvore1));

    /*insere itens embaralhados na arvore*/
    for(i = 0; i < strlen(str); i++){
        InsereArvoreBinariaBusca(arvore1, item1[i]);
    }

    printf("\n Impressão da árvore após a inclusão dos nós\n\n");
    ImprimeArvoreBinariaBusca(arvore1, 0);

    /* reconstrução da mensagem original */
    for(i = 0; i < tam; i++){
        item2 = BuscaArvoreBinariaBusca(arvore1, i+1);
        str[i] = item2->pacote;
        RemoveArvoreBinariaBusca(arvore1, *item2);
    }
    printf("\n MENSAGEM RECONSTRUIDA: \n");
    imprimiMensagem(str, tam);
    getchar();

    return 0;
}




void embaralha(char *s, int *numReplicacoes, TipoItem *item) {

    int tam = strlen(s);

    if(tam > 1) {
        int i;

        for(i = 0; i < tam - 1; i++) {
            int j = rand() % tam;
            char* temp = s[j];
            int* tempInt = numReplicacoes[j];
            TipoItem tempItem = item[j];
            s[j] = s[i];
            s[i] = temp;
            numReplicacoes[j] = numReplicacoes[i];
            numReplicacoes[i] = tempInt;
            item[j] = item[i];
            item[i] = tempItem;
        }
    }

}

void imprimiNumReplicacoes(int *numReplicacoes, int tam) {

    int i;

    for(i = 0; i < tam; i++) {
        printf("%d ", numReplicacoes[i]);
    }
}

void imprimiChave(TipoItem *item, int tam) {

    int i;

    for(i = 0; i < tam; i++) {
        printf(" %d", item[i].chave);
    }

}

void imprimiMensagem(char* s, int tam) {

    int i;

    for(i = 0; i < tam; i++) {
        printf(" %c", s[i]);
    }

}


