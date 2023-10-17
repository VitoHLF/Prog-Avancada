#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
 	int data;
 	struct Node* next;
}Node;

typedef struct List{
	Node* front;
	int size;
}List;

void createList(List* lista){
	lista->front = NULL;
	lista->size = 0;
}

void addFirst(List* lista, int data){
	Node* novo = malloc(sizeof(Node));
	if(novo){
		novo->data = data;
		novo->next = lista->front;
		lista->front = novo;
		lista->size++;
	}else{
		printf("Erro ao criar novo no\n");
	}
}

void addLast(List* lista, int data){
	Node *novo, *aux;
	aux = lista->front;
	novo = malloc(sizeof(Node));
	if(novo){
		novo->data = data;
		novo->next = NULL;

		if(lista->front == NULL){
			lista->front = novo;
		}
		else{
			while(aux->next){
				aux = aux->next;
			}
			aux->next = novo;
		}
		lista->size++;
	}
	else{
		printf("Erro ao criar no.\n");
	}
}

void addMiddle(List* lista, int data, int previous){
	Node *aux, *novo = malloc(sizeof(Node));

	if(novo){
		novo->data = data;

		if(lista->front == NULL){
			novo->next = NULL;
			lista->front = novo;
		}
		else{
			aux = lista->front;
			while(aux->data != previous && aux->next){
				aux = aux->next;
			}
			novo->next = aux->next;
			aux->next = novo;
		}
		lista->size++;
	}else{
		printf("Erro ao criar no.\n");
	}
}

void printList(Node* no){
	Node* aux = no;
	printf("\n");
	while(aux){
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("\n\n");
}

void main(){
	int opcao, valor, anterior;
	List lista;

	createList(&lista);

	do{
		printf("\n\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no fim\n\t3 - Inserir no meio\n\t4 - Imprimir\n");
		scanf("%d", &opcao);

		switch(opcao){
		case 1:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			addFirst(&lista, valor);
			break;
		case 2:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			addLast(&lista, valor);
			break;
		case 3:
			printf("Digite um valor e o valor de referencia: ");
			scanf("%d%d", &valor, &anterior);
			addMiddle(&lista, valor, anterior);
			break;
		case 4:
			printList(lista.front);
			break;
		default:
			if(opcao != 0) printf("Opcao invalida!\n");
		}
	}while(opcao != 0);
}
