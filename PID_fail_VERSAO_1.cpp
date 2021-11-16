//  PID nao funcionou, ideia cortada dessa versão!
//  main.cpp
//  Trabalho 2
//
//

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct Queue {
    int tamanho, first, last, quantidade;
    float *data;
};
void criarQueue( struct Queue *f, int c ) {
    f->tamanho; //= c;
    f->data = (float*) malloc (f->tamanho * sizeof(float));
    f->first = 0;
    f->last = -1;
    f->quantidade = 0;
}
void inserir(struct Queue *f, int v, int s) {
    if(f->last == f->tamanho-1)
        f->last = -1;
    f->last++;
    f->data[f->last] = v;
    f->data[f->last] = s;// INCREMENTA O LAST
    f->quantidade++; // INSERE MAIS ITENS
}
int remover( struct Queue *f ) { // ITEM DO COME«O DA FILA
    int temp = f->data[f->first++]; // VALOR MAIS FIRST
    if(f->first == f->tamanho)
        f->first = 0;
    f->quantidade--;  // RETIRA UM VALOR
    return temp;
}
int estaVazia( struct Queue *f ) { // VERDADEIRO PARA FILA VAZIA
    return (f->quantidade==0);
}
int estaCheia( struct Queue *f ) { // VERDADEIRO PARA FILA CHEIA
    return (f->quantidade == f->tamanho);
}
void mostrarQueue(struct Queue *f){
    int cont, i;
    for ( cont=0, i= f->first; cont < f->quantidade; cont++){
        printf("%0.2f\t",f->data[i++]);
        if (i == f->tamanho)
            i=0;
    }
    printf("\n\n");
}

struct Queue2 {
    int tamanho2, first2, last2, quantidade2;
    float *data2;
};
void criarQueue2( struct Queue2 *f, int c ) {
    f->tamanho2; //= c;
    f->data2 = (float*) malloc (f->tamanho2 * sizeof(float));
    f->first2 = 0;
    f->last2 = -1;
    f->quantidade2 = 0;
}
void inserir2(struct Queue2 *f, int v2) {
    if(f->last2 == f->tamanho2-1)
        f->last2 = -1;
    f->last2++;
    f->data2[f->last2] = v2; // INCREMENTA O LAST
    f->quantidade2++; // INSERE MAIS ITENS
}
int remover2( struct Queue2 *f ) { // ITEM DO COME«O DA FILA
    int temp2 = f->data2[f->first2++]; // VALOR MAIS FIRST
    if(f->first2 == f->tamanho2)
        f->first2 = 0;
    f->quantidade2--;  // RETIRA UM VALOR
    return temp2;
}
int estaVazia2( struct Queue2 *f ) { // VERDADEIRO PARA FILA VAZIA
    return (f->quantidade2==0);
}
int estaCheia2( struct Queue2 *f ) { // VERDADEIRO PARA FILA CHEIA
    return (f->quantidade2 == f->tamanho2);
}
void mostrarQueue2(struct Queue2 *f){
    int cont, i;
    for ( cont=0, i= f->first2; cont < f->quantidade2; cont++){
        printf("%0.2f\t",f->data2[i++]);
        if (i == f->tamanho2)
            i=0;
    }
    printf("\n\n");
}


int main () {
    setlocale(LC_ALL, "Portuguese");
    int opcao, capa, pid;
    float valor;
   // float pid;
    struct Queue umaQueue;
    struct Queue2 umaQueue2;

    // CRIA A FILA
    // printf("\ntamanho da Fila ");
    // scanf("%d",&capa);
    
    criarQueue(&umaQueue, capa);
    criarQueue2(&umaQueue2, capa);
    // MENU
    while( 1 ){
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Executar\n0 - Sair\n\nOpcao? ");
        scanf("%d", &opcao);
        switch(opcao){
            case 0: exit(0);
            case 1: //FILA CHEIA OU VAZIA
                if (estaCheia(&umaQueue)){
                    printf("\n Fila Cheia!!!\n\n");
                }
                else {
                    printf("\n Valor do elemento a ser inserido? ");
                    scanf("%f", &valor);
//A intenção era adicionar um PID que seria utilizado na
//segunda versão do programa para que o elemento pudesse ser
//trocado de fila a partir do PID, mas nao deu certo entao
//foi removido da segunda versão
                    printf("\n PID? ");
                    scanf("%d", &pid);
                    printf("\n 1-Prioritaria 2- Normal ");
                    int x;
                    scanf("%d", &x);
                    if (x==1) {
                        inserir(&umaQueue, valor, pid);
                    }
                    else
                    inserir2(&umaQueue2,valor);
                }
                break;

            case 2: // VAZIA OU REMOVE ELEMENTO
                if (estaVazia(&umaQueue) && estaVazia2(&umaQueue2)){
                    printf("\n Fila vazia!!!\n\n");
                }
                else {
                    printf("\n Remover de qual fila? 1- Prioritaria 2- Normal");
                    int x;
                    scanf("%d", &x);
                    if (x == 1) {
                        valor = remover(&umaQueue);
                        printf("\n%0.2f removido com sucesso\n\n", valor) ;
                    }
                    
                }
                break;
                case 3: // VAZIA MOSTRA A FILA
                    if (estaVazia(&umaQueue) && estaVazia2(&umaQueue2)){
                        printf("\n Fila vazia!!!\n\n");
                    }
                    else {
                        printf("\n processos da Fila Prioritaria Executados==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n processos da Fila normal Executados==> \n");
                        mostrarQueue2(&umaQueue2);
                    }
                    break;
                default:
                    printf("\n Opcao Invalida\n\n");
        }
    }
}

