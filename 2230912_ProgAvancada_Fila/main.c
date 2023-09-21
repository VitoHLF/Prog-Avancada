#include <stdio.h>
#include <stdlib.h>
//Definindo a estrutura para um nó na fila
typedef struct no {
    int valor;
    struct no *proximo
} No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL)
            *fila = novo;
        else{
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }else
        printf("\nErro ao alocar memoria.\n");
}

//Funç]ao para remover um nó da fila
No* remover_da_fila(No **fila){
    No *remover= NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }else
        printf("\tFila vazia\n");
    return remover;
}

void printFila(No **fila){
    No *aux = *fila;
    if(*fila){
        printf("\nPrimeiro->\t");
        while(aux->proximo){
            printf("%d", aux->valor);
            aux = aux->proximo;
        }
        printf("\t <- Ultimo\n");
    }else{
        printf("\nFila vazia!\n");
    }
    printf("\n");
}

int main()
{
    No *r, *fila = NULL;
    int opcao, valor;

    do{
        //Exibe as opções para o usuário
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_na_fila(&fila, valor);
                break;
            case 2:
                r = remover_da_fila(&fila);
                if(r){
                    printf("Removido: %d\n", r->valor);
                    free(r);
                }
                break;
            case 3:
                printFila(&fila);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}
