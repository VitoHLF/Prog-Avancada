#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>


typedef struct no {
    char item;
    struct no *proximo
} No;

void enfileirar(No **fila, char item){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->item = item;
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
No* desenfileirar(No **fila){
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
        printf("%c", aux->item);
        while(aux->proximo){
            printf("%c", aux->proximo->item);
            aux = aux->proximo;
        }
        //printf("\t <- Ultimo\n");
    }/* else{
        printf("\nFila vazia!\n");
    } */
    printf("\n");
}

void geraItens(No** fila, int dificuldade){
    for(int i = 0; i<dificuldade; i++){
        switch(rand()%6){
            case 0:
                enfileirar(fila, 'A');
                break;
            case 1:
                enfileirar(fila, 'S');
                break;
            case 2:
                enfileirar(fila, 'D');
                break;
            case 3:
                enfileirar(fila, 'J');
                break;
            case 4:
                enfileirar(fila, 'K');
                break;
            case 5:
                enfileirar(fila, 'L');
                break;
        }
    }
}

char toUpper(char letra){
    switch (letra){
        case 'a':
            return 'A';
            break;
        case 's':
            return 'S';
            break;
        case 'd':
            return 'D';
            break;
        case 'j':
            return 'J';
            break;
        case 'k':
            return 'K';
            break;
        case 'l':
            return 'L';
    }
    return letra;
}

bool comparaInput(No** fila, char input){
    if(*fila){
        No *remover, *aux = *fila;
        if(input == aux->item){
            remover = desenfileirar(fila);
            free(remover);
            return true;
        }
    }else{
        printf("Esse nao e o proximo item");
    }
    return false;
}

int main()
{
    No *remover, *pessoas = NULL, *compras = NULL;
    char opcao, dificuldade=4;
    int pontuacao = 0;
    //bool haCompras = false;

    srand(time(NULL));
    //haCompras = geraItens(&compras, dificuldade);

    do{
        system("CLS");
        printFila(&compras);
        printf("Pontos: %d\n", pontuacao);
        
        if(compras){
            opcao = getch();
            printf("%c", opcao);
            opcao = toUpper(opcao);
            if(comparaInput(&compras, opcao)) pontuacao += 50;
            else if(opcao == '0');
            else pontuacao -= 50;
        }else{
            dificuldade++;
            geraItens(&compras, dificuldade);
        }
        

    }while(opcao != '0');

    printf("\n\tObrigado por jogar, sua pontuacao foi de: %d\n", pontuacao);

    return 0;
}
