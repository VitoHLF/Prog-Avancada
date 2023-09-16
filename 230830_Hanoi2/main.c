#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define largura 106

/*
TAMANHO DA CAIXA DE JOGO
LARGURA ATUAL = 106
ALTURA ATUAL = 26
*/



typedef struct no{
    int valor;
    struct no *proximo;
} No;

typedef struct{
    int tamanho;
    No *topo;
}Pilha;

void empilhar(Pilha *pilha, int valor){
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->tamanho++;
}

void desempilhar(Pilha *pilha){
    if(pilha->topo){
        No *no = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        pilha->tamanho--;
        free(no);
    }
}

void imprimir(No *no){      //função de print de pilha, não utilizada no código
    if(no){
        printf("%d", no->valor);
        imprimir(no->proximo);
    }
}

void jogoSetup(Pilha *p1, Pilha *p2, Pilha *p3){    //aloca todos os blocos na primeira pilha para setup inicial do jogo
    for(int i=6; i>0; i--){
        empilhar(p1, i);
    }
}

void bordasHorizontais(char c){ //print de linhas da largura da tela
    printf("%c%c", 219, 219);
    for(int i = 0; i<largura-4; i++){
        printf("%c", c);
    }
    printf("%c%c", 219, 219);
    printf("\n");
}

void printLegendaPilhas(){
    //linha 1
    bordaVertical(219);
    printf("               %c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,191);
    printf("                       %c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,191);
    printf("                       %c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,191);
    printf("              %c%c\n", 219, 219);
    //linha 2
    bordaVertical(219);
    printf("               %c   %c   %c",179,203,179);
    printf("                       %c  %c %c  %c",179,203,203,179);
    printf("                       %c %c %c %c %c",179,203,203,203,179);
    printf("              %c%c\n", 219, 219);
    //linha 3
    bordaVertical(219);
    printf("               %c   %c   %c",179,186,179);
    printf("                       %c  %c %c  %c",179,186,186,179);
    printf("                       %c %c %c %c %c",179,186,186,186,179);
    printf("              %c%c\n", 219, 219);
    //linha4
    bordaVertical(219);
    printf("               %c   %c   %c",179,202,179);
    printf("                       %c  %c %c  %c",179,202,202,179);
    printf("                       %c %c %c %c %c",179,202,202,202,179);
    printf("              %c%c\n", 219, 219);
    //linha5
    bordaVertical(219);
    printf("               %c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,217);
    printf("                       %c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,217);
    printf("                       %c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,217);
    printf("              %c%c\n", 219, 219);

    /*printf("%c%c", 219, 219);
    for(int i=0; i<18; i++){
        printf(" ");
    }
    printf("1");
    for(int i=0; i<32; i++){
        printf(" ");
    }
    printf("2");
    for(int i=0; i<31; i++){
        printf(" ");
    }
    printf("3");
    for(int i=0; i<18; i++){
        printf(" ");
    }
    printf("%c%c\n", 219, 219);*/
    //modificar para arte ascii dos numeros
}

void printInterface(Pilha *p1, Pilha *p2, Pilha *p3){     //print da interface
    No *auxNo1, *auxNo2, *auxNo3;   //nós auxiliares para iteração nos loops

    auxNo1 = p1->topo;
    auxNo2 = p2->topo;
    auxNo3 = p3->topo;

    //bordasHorizontais(219);
    bordasHorizontais(219);
    bordasHorizontais(' ');

    //cada iteração compara a "altura" (tamanho) de cada pilha com a altura do quadro impresso no prompt
    for(int i=8; i>=1; i--){ //loop de print principal

        //
        //
        //
        printf("%c%c\t", 219, 219);     //borda esquerda
        if(p1->tamanho >= i){ // loop da pilha 1
            for(int j=6; j>auxNo1->valor; j--){     //lado esquerdo da pilha "vazio", imprime espaços vazios com base no tamanho do anel naquela linha
                printf("  ");
            }
            for(int j=0; j<2*(auxNo1->valor-1)+4;j++){      //loop de print da pilha, imprime o anel com o tamanho baseado no valor do nó (anel)
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo1->valor; j--){     //lado direito da pilha "vazio", identico ao lado vazio esquerdo
                printf("  ");
            }
        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }

        printf("\t");
        if(p2->tamanho >= i){ // loop da pilha 2
            for(int j=6; j>auxNo2->valor; j--){     //lado esquerdo da pilha "vazio"
                printf("  ");
            }
            for(int j=0; j<2*(auxNo2->valor-1)+4;j++){      //loop de print da pilha
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo2->valor; j--){     //lado direito da pilha "vazio"
                printf("  ");
            }
        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }

        printf("\t");
        if(p3->tamanho >= i){ // loop da pilha 3
            for(int j=6; j>auxNo3->valor; j--){     //lado esquerdo da pilha "vazio"
                printf("  ");
            }
            for(int j=0; j<2*(auxNo3->valor-1)+4;j++){      //loop de print da pilha
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo3->valor; j--){     //lado direito da pilha "vazio"
                printf("  ");
            }

        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }
        printf("\t%c%c\n", 219, 219); //borda direita
        //
        //
        //
        printf("%c%c\t", 219, 219);   //borda esquerda
        if(p1->tamanho >= i){ // loop da pilha 1
            for(int j=6; j>auxNo1->valor; j--){     //lado esquerdo da pilha "vazio", imprime espaços vazios com base no tamanho do anel naquela linha
                printf("  ");
            }
            for(int j=0; j<2*(auxNo1->valor-1)+4;j++){      //loop de print da pilha, imprime o anel com o tamanho baseado no valor do nó (anel)
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo1->valor; j--){     //lado direito da pilha "vazio", identico ao lado vazio esquerdo
                printf("  ");
            }
            auxNo1 = auxNo1->proximo; //utiliza o proximo nó da pilha como referencia para a proxima iteração
        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }

		printf("\t");

        if(p2->tamanho >= i){ // loop da pilha 2
            for(int j=6; j>auxNo2->valor; j--){     //lado esquerdo da pilha "vazio"
                printf("  ");
            }
            for(int j=0; j<2*(auxNo2->valor-1)+4;j++){      //loop de print da pilha
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo2->valor; j--){     //lado direito da pilha "vazio"
                printf("  ");
            }
            auxNo2 = auxNo2->proximo;
        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }

        printf("\t");

        if(p3->tamanho >= i){ // loop da pilha 3
            for(int j=6; j>auxNo3->valor; j--){     //lado esquerdo da pilha "vazio"
                printf("  ");
            }
            for(int j=0; j<2*(auxNo3->valor-1)+4;j++){      //loop de print da pilha
				printf("%c%c", 177,177);
            }
            for(int j=6; j>auxNo3->valor; j--){     //lado direito da pilha "vazio"
                printf("  ");
            }
            auxNo3 = auxNo3->proximo;
        }else{
            printf("             %c%c           ", 186, 186);       //print da haste
        }

    printf("\t%c%c\n", 219,219); //borda direita
    }

    //bordasHorizontais(' ');

    printLegendaPilhas();

    //bordasHorizontais(' ');
    //bordasHorizontais(' ');
    //bordasHorizontais(219);
    bordasHorizontais(219);
}

void mover(Pilha *pOrigem, Pilha *pDestino, int* movimentos){    //função de movimento de "peças"
    if(!(pDestino->topo) || pOrigem->topo->valor < pDestino->topo->valor){  //condições de validade de movimento
        empilhar(pDestino, pOrigem->topo->valor);
        desempilhar(pOrigem);
        *movimentos += 1;
    }else{
        printf("Movimento invalido, aperte qualquer tecla para continuar.\n");
        getch();
    }
}

void checaMovimento(Pilha *pilha, Pilha *p1, Pilha *p2, Pilha *p3, int *movimentos){     //primeira condição de checagem do movimento, recebe o input de destino do bloco
    char comando;

    if(pilha->topo){  //se a pilha escolhida na função tiver algum nó
        printf("Para qual pilha voce quer enviar?\n1/2/3\n0: Cancelar   =>  \t");
        comando = getch(); //escolhe um comando

        switch(comando){
        case '1':   //para a pilha 1
            mover(pilha, p1, movimentos);
            break;

        case '2':   //para a pilha 2
            mover(pilha, p2, movimentos);
            break;

        case '3':   //para a pilha 3
            mover(pilha, p3, movimentos);
            break;

        case '0':   //cancelar
                break;

        default:
            printf("Comando invalido, aperte qualquer tecla para continuar\n");
            getch();
        }
    }else{
        printf("A pilha escolhida esta vazia, aperte qualquer tecla para continuar.\n");
        getch();
    }
}

int checaVitoria(No *no){ //recebe um nó de topo de pilha e retorna a soma dos valores do topo ao fim
    No *auxNo;
    auxNo = no;
    int iter = 0;

    while(auxNo){
        iter += auxNo->valor;
        auxNo = auxNo->proximo;
    }
    return iter;
}

void bordaVertical(char c){
    printf("%c%c", c, c);
}

void printTitulo(){
printf("%c%c     ___  ____ _ _      _____ _             _    _                                                    ",219,219); //1
bordaVertical(219);
printf("\n%c%c     |  \\/  (_) | |    /  ___| |           | |  (_)                                                   ",219,219);//2
bordaVertical(219);
printf("\n%c%c     | .  . |_| | | __ \\ `--.| |_ __ _  ___| | ___ _ __   __ _                                        ",219,219);//3
bordaVertical(219);
printf("\n%c%c     | |\\/| | | | |/ /  `--. \\ __/ _` |/ __| |/ / | '_ \\ / _` |                                       ",219,219);//4
bordaVertical(219);
printf("\n%c%c     | |  | | | |   <  /\\__/ / || (_| | (__|   <| | | | | (_| |                                       ",219,219);//5
bordaVertical(219);
printf("\n%c%c     \\_|  |_/_|_|_|\\_\\ \\____/ \\__\\__,_|\\___|_|\\_\\_|_| |_|\\__, |                                       ",219,219);//6
bordaVertical(219);
printf("\n%c%c                                                          __/ |                                       ",219,219);//7
bordaVertical(219);
printf("\n%c%c                                                         |___/                                        ",219,219);//8
bordaVertical(219);
printf("\n%c%c       _____ _           _ _                                                                          ",219,219);//9
bordaVertical(219);
printf("\n%c%c     /  __ \\ |         | | |                                                                          ",219,219);//10
bordaVertical(219);
printf("\n%c%c     | /  \\/ |__   __ _| | | ___ _ __   __ _  ___                                                     ",219,219);//11
bordaVertical(219);
printf("\n%c%c     | |   | '_ \\ / _` | | |/ _ \\ '_ \\ / _` |/ _ \\                                                    ",219,219);//12
bordaVertical(219);
printf("\n%c%c     | \\__/\ | | | (_| | | |  __/ | | | (_| |  __/                                                     ",219,219);//13
bordaVertical(219);
printf("\n%c%c     \\____/_| |_|\\__,_|_|_|\\___|_| |_|\\__, |\\___|                                                     ",219,219);//14
bordaVertical(219);
printf("\n%c%c                                       __/ |                                                          ",219,219);//15
bordaVertical(219);
printf("\n%c%c                                      |___/                                                           ",219,219);//16
bordaVertical(219);
printf("\n");
//getch();

}

void animacaoInicial(){ //PLACEHOLDER


    system("@echo off");
    system("cls");
    bordasHorizontais(219);
    printTitulo();
    bordaVertical(219);
    printf("          (__)"); printf("                                                                                        "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("          (oo)"); printf("                                                                                        "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("  /--------\\/"); printf("                                                                                         "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf(" / |       ||"); printf("                                                                                         "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("^  ||W----||"); printf("                                                                                          "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("   ||     ||"); printf("                                                                                          "); bordaVertical(219); printf("\n");
    bordasHorizontais(219);
    system("timeout /t 1 > NUL");
    system("cls");


    bordasHorizontais(219);
    printTitulo();
    bordaVertical(219);
    printf("                         (__) "); printf("                                                                        "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                         (oo) "); printf("                                                                        "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                 /--------\\/ "); printf("                                                                         "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                / |       || "); printf("                                                                         "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("               ^ // W---- \\\\ "); printf("                                                                         "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                //         \\\\ "); printf("                                                                        "); bordaVertical(219); printf("\n");
    bordasHorizontais(219);
    system("timeout /t 1 > NUL");
    system("cls");


    bordasHorizontais(219);
    printTitulo();
    bordaVertical(219);
    printf("                                      (__) "); printf("                                                           "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                      (--) "); printf("                                                           "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                              /--------\\/ "); printf("                                                            "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                             / |       || "); printf("                                                            "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                            ^  ||W----|| "); printf("                                                             "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                               ||     || "); printf("                                                             "); bordaVertical(219); printf("\n");
    bordasHorizontais(219);
    system("timeout /t 1 > NUL");
    system("cls");


    bordasHorizontais(219);
    printTitulo();
    bordaVertical(219);
    printf("                                                    (__)"); printf("                                              "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                                    (--)"); printf("                                              "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                            /--------\\/ "); printf("                                              "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                           / |       || "); printf("                                              "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                          ^ // W---- \\\\ "); printf("                                              "); bordaVertical(219); printf("\n");
    bordaVertical(219);
    printf("                                           //         \\\\ "); printf("                                             "); bordaVertical(219); printf("\n");
    bordasHorizontais(219);
    system("timeout /t 1 > NUL");
    system("cls");
}//PLACEHOLDER

void telaInicial(){
    bordasHorizontais(219);
    bordaVertical(219);
    printf("                                                                                                      %c%c\n", 219, 219);
    bordaVertical(219);
    printf("\tExplore a emocao e desafio da vida rural com o jogo \"Milk Stacking Challenge\"!                  %c%c\n", 219, 219);
    bordaVertical(219);
    printf("                                                                                                      %c%c\n",219 ,219);
    bordaVertical(219);
    printf("    Assuma o papel de um gerente de fazenda encarregado de preservar o frescor do leite recem         %c%c\n", 219, 219);
    bordaVertical(219);
    printf("ordenhado.                                                                                            %c%c\n", 219, 219);
    bordaVertical(219);
    printf("Enfrente um emocionante desafio quando o refrigerador onde o leite esta armazenado apresenta defeito. %c%c\n", 219, 219);
    bordaVertical(219);
    printf("    Sua missao: transferir as caixas de leite empilhadas em forma de piramide para outro refrigerador,%c%c\n", 219, 219);
    bordaVertical(219);
    printf("mantendo a estrutura, movendo cada caixa de um para outro sem deixa-las fora do refrigerador por      %c%c\n", 219, 219);
    bordaVertical(219);
    printf("muito tempo, evitando a deterioracão do leite, de forma que todas as caixas fiquem                    %c%c\n", 219, 219);
    bordaVertical(219);
    printf("empilhadas novamente no terceiro refrigerador.                                                        %c%c\n", 219, 219);
    bordaVertical(219);
    printf("    Comande a operacao com agilidade e estrategia, escolhendo o refrigerador ideal e movendo as       %c%c\n", 219, 219);
    bordaVertical(219);
    printf("caixas com precisao.                                                                                  %c%c\n", 219, 219);
    bordaVertical(219);
    printf("Cada movimento importa, cada decisao impacta o resultado. O frescor do leite esta em suas maos.       %c%c\n", 219, 219);
    for(int i = 0; i<7; i++){
        bordasHorizontais(' ');
    }
    bordaVertical(219);
    printf("                                      Aperte qualquer tecla para continuar...                         ");
    bordaVertical(219);
    printf("\n");
    bordasHorizontais(' ');
    bordasHorizontais(219);
    getch();
}

int main()
{
    Pilha p1, p2, p3;
    int movimentos = 0;
    char comando=0;

    p1.tamanho = 0;
    p1.topo = NULL;
    p2.tamanho = 0;
    p2.topo = NULL;
    p3.tamanho = 0;
    p3.topo = NULL;

    //função de tela inicial ( system("timeout /t 1 > NUL"); )
    telaInicial();
    animacaoInicial();

    jogoSetup(&p1, &p2, &p3);
    //imprimir(p1.topo);

    do{

        system("cls"); //limpar console
        printInterface(&p1, &p2, &p3); //printar interface
        printf("\nMovimentos: %d\n", movimentos);
        printf("\nDe qual pilha voce quer mover?\n1/2/3\n0: Sair    =>  \t"); //bloco de comando
        comando = getch();
        printf("%c\n", comando);

        switch(comando){ //switch de execução do comando
        case '1':
            checaMovimento(&p1, &p1, &p2, &p3, &movimentos);
            break;

        case '2':
            checaMovimento(&p2, &p1, &p2, &p3, &movimentos);
            break;

        case '3':
            checaMovimento(&p3, &p1, &p2, &p3, &movimentos);
            break;

        case '0':
            break;

        default:
            printf("Comando invalido, aperte qualquer tecla para continuar.\n");
            getch();
        }


        if(checaVitoria(p3.topo) == 21){ //21 condição de vitória (soma de 6+5+4+3+2+1), comentario da lógica na função checaVitoria
            comando = '0';
            system("cls");
            printInterface(&p1, &p2, &p3);
            printf("\nVOCE VENCEU!!!\n\nTotal de movimentos: %d\n", movimentos);

        }

    }while(comando!='0');


    printf("Obrigado por jogar.\n"); //substituir por uma função de tela final
}

