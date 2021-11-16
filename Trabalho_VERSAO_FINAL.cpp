/*
 Integrantes:
 
 Sérgio Glésio de Oliveira Júnior - 2011671
 Gustavo Alves Cardoso Segantini - 2010012
 João Cândido de Jesus Neto - 2011321
 Ana Beatriz Ferreira Pessoa - 2011475
 Marcelo Araujo

Problemas:
 
 Não foi possivel adicionar um PID e tambem não foi possivel trocar o elemento
 de fila, o PID seria utilizado para selecionar o elemento e troca-lo de uma fila
 para outra, porem não conseguimos adicionar, os arquivos de teste de versões
 anteriores estão aqui no git para serem conferidos sobre o que estava sendo feito.
 
 Titulo dos arquivos de outras versões:
 
 PID_fail_VERSAO_1
 Trocar_de_fila_fil_VERSAO_2



 */

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
void inserir(struct Queue *f, int v) {
    if(f->last == f->tamanho-1)
        f->last = -1;
    f->last++;
    f->data[f->last] = v; // INCREMENTA O LAST
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
    int opcao, capa;
    float valor;
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
                    printf("\n 1-Prioritaria 2- Normal ");
                    int x;
                    scanf("%d", &x);
                    if (x==1) {
                        inserir(&umaQueue,valor);
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
                        if (estaVazia(&umaQueue)) {
                            printf("\n Fila vazia!!!\n\n");
                        }
                        else {
                        valor = remover(&umaQueue);
                        printf("\n%0.2f removido com sucesso\n\n", valor) ;
                        }
                    }
                    else {
                        if (estaVazia2(&umaQueue2)) {
                            printf("\n Fila vazia!!!\n\n");
                        }
                        else {
                        valor = remover2(&umaQueue2);
                        printf("\n%0.2f removido com sucesso\n\n", valor) ;
                        }
                    }
                }
                break;
                case 3: // VAZIA MOSTRA A FILA
                    if (estaVazia(&umaQueue) && estaVazia2(&umaQueue2)){
                        printf("\n Fila vazia!!!\n\n");
                    }
                    else if (estaVazia(&umaQueue)) {
                        printf("\n Executando processos da Fila Normal==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n processos da Fila normal Executados==> \n");
                        mostrarQueue2(&umaQueue2);
                        printf("\n Fim do programa :) \n");
                        }
                    else if (estaVazia2(&umaQueue2)) {
                        printf("\n Executando processos da Fila Prioritaria==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n processos da Fila Prioritaria Executados==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n Fim do programa :) \n");
                    }
                    else {
                        printf("\n Executando processos da Fila Prioritaria==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n processos da Fila Prioritaria Executados==> \n");
                        mostrarQueue(&umaQueue);
                        
                        printf("\n Proxima fila==> \n");
    
                        printf("\n Executando processos da Fila Normal==> \n");
                        mostrarQueue(&umaQueue);
                        printf("\n processos da Fila normal Executados==> \n");
                        mostrarQueue2(&umaQueue2);
                        printf("\n Fim do programa :) \n");
                    }
                break;
            default:
                printf("\n Opcao Invalida\n\n");
        }
    }
}

/*
 Implementar um escalonador de processos por prioridades.

 Requisitos

 O processo deve conter um id do processo (PID) e o nome do processo.
 O escalonador deve conter pelo menos duas filas de prioridade.
 Devem constar as seguintes funções
 Adicionar processo: adiciona um novo processo a uma fila. Caso não seja definida a fila o processo será adicionado à fila de menor prioridade
 Executar processo: executa o primeiro processo da fila de maior prioridade que esteja com processos pendentes. O processo é movido para o final da fila de prioridade imediatamente inferior.
 Mover processo entre filas: transfere um processo de uma fila para outra. O processo movido pode estar em qualquer posição da fila de origem e será colocado no final da fila de destino.
 Finalizar processo: Encerra o primeiro processo da fila de maior prioridade, removendo-o completamente do sistema.
 Finalizar processo específico: Encerra um processo a partir do ID escolhido, removendo-o completamente do sistema. O processo pode estar em qualquer fila no momento da remoção.
 */
