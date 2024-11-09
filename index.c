#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;
    int topo;      
    int capacidade; 
} Pilha;

Pilha* criarPilha(int capacidadeInicial) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL;

    pilha->dados = (void *) malloc(sizeof(void) * capacidadeInicial);
    if (pilha->dados == NULL) {
        free(pilha);
        return NULL; 
    }

    pilha->topo = -1;
    pilha->capacidade = capacidadeInicial;

    return pilha;
}

int empilhar(Pilha *pilha, void *elemento) {
    if (pilha->topo == pilha->capacidade - 1) {
        
        void *novaPilha = (void *) realloc(pilha->dados, sizeof(void*) * pilha->capacidade * 2);
        if (novaPilha == NULL) return 0; 
        pilha->dados = novaPilha;
        pilha->capacidade *= 2;
    }

    
    pilha->dados[++pilha->topo] = elemento;
    return 1; 
}

void* desempilhar(Pilha *pilha) {
    if (pilha->topo == -1) return NULL; 

    return pilha->dados[pilha->topo--];
}

int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

void* topo(Pilha *pilha) {
    if (pilha->topo == -1) return NULL;
    return pilha->dados[pilha->topo];
}

void limparPilha(Pilha *pilha) {
    if (pilha != NULL) {
        free(pilha->dados);  
        free(pilha);         
    }
}

int main() {
    Pilha *pilha = criarPilha(2);
    if (pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    int a = 1, b = 2, c = 3;

    empilhar(pilha, &a);
    empilhar(pilha, &b);
    empilhar(pilha, &c);

    int *elementoRemovido = (int *) desempilhar(pilha);
    if (elementoRemovido != NULL) {
        printf("Elemento removido: %d\n", *elementoRemovido);
    }

    int *elementoTopo = (int *) topo(pilha);
    if (elementoTopo != NULL) {
        printf("Elemento no topo da pilha: %d\n", *elementoTopo);
    }

    limparPilha(pilha);
    return 0;
}