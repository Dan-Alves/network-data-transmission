#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "TAD_arvore_binaria_busca.h"

void embaralha(char *s, int *numReplicacoes, TipoItem *item);
void imprimiNumReplicacoes(int *numReplicacoes, int tam);
void imprimiChave(TipoItem *item, int tam);

int main(void)
{
    setlocale(LC_ALL, "");

    int i, *numReplicacoes, tam;
    char str[50];
    TipoItem *item1;

    /*printf("---------------------------\n");
    printf("  Árvore Binária de Busca\n");
    printf("---------------------------\n");*/

    printf("Entre com a msg: ");
    gets(str);
    printf("\nMENSAGEM: %s\n", str);

    tam = strlen(str);

    item1 = malloc(tam * sizeof(TipoItem));
    numReplicacoes = malloc(tam * sizeof(int));
    srand(time(NULL));

    /* Preenche item */
    for(i = 0; i < strlen(str); i++){
        item1[i].chave = i;
        item1[i].pacote = str[i];
        numReplicacoes[i] = 1 + (rand() % 10);
    }

    /* Embaralha e imprime mensagem */
    embaralha(str, numReplicacoes, item1);
    printf("\nMENSAGEM EMBARALHADA: \n%s\n", str);
    imprimiChave(item1, tam);


    TipoCelula **arvore1 = (TipoCelula **)malloc(sizeof(TipoCelula *));

    printf("\n\nCriação da árvore vazia\n");
    CriaArvoreBinariaBuscaVazia(arvore1);
    printf("\nVerificação se a árvore criada é vazia -> %i\n", TestaArvoreBinariaBuscaVazia(arvore1));

    /*insere itens embaralhados na arvore*/
    for(i = 0; i < strlen(str); i++){
        InsereArvoreBinariaBusca(arvore1, item1[i]);
    }

    printf("\nImpressão da árvore após a inclusão dos nós\n\n");
    ImprimeArvoreBinariaBusca(arvore1, 0);

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
        printf("%d", item[i].chave);
    }

}


