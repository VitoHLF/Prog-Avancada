#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

// 345

typedef struct no{
	int valor;
	struct no *proximo;
} No;

typedef struct {
	int tamanho;
	No *inicio;
	No *fim;
} Fila;

void enfileirar(No **fila, int valor){
	No *aux, *novo = malloc(sizeof(No));
	if(novo){
		novo->valor = valor;
		novo->proximo = NULL;
		if(*fila == NULL) *fila = novo;
		else{
			aux = *fila;
			while(aux->proximo) aux = aux->proximo;
			aux->proximo = novo;
		}
	}else{
		printf("Erro ao alocar memoria");
	}
}

No* remover_da_fila(No **fila){
	No* remover = NULL;

	if(*fila){
		remover = *fila;
		*fila = remover->proximo;
	}
	else{
		printf("Fila vazia");

	}
	return remover
}

/*void enfileirar(Fila *fila, int valor){
	No* no = malloc(sizeof(No));
	no->valor = valor;
	no->proximo = fila->fim;
	if(!fila->inicio){
		fila->inicio = no;
	}
	fila->fim = no;
	fila->tamanho++;
}*/

/*void desenfileirar(Fila *fila){
	No* no =
	if(fila->inicio){

	}else{
		printf("Não há elementos na fila.")
		getch();
	}
}*/

int main()
{

}
