#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10  // Tamanho da fila

typedef struct {
    int dados[MAX];
    int frente;
    int tras;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Insere um elemento na fila
void enfileirar(Fila *f, int valor) {
    if (f->tras < MAX - 1) {
        f->tras++;
        f->dados[f->tras] = valor;
    } else {
        printf("Fila cheia!\n");
    }
}

// Verifica se os elementos estão em ordem crescente
int estaOrdenadaCrescente(Fila *f) {
    for (int i = f->frente; i < f->tras; i++) {
        if (f->dados[i] > f->dados[i + 1]) {
            return 0; // Não está ordenada
        }
    }
    return 1; // Está ordenada
}

// Exibe os elementos da fila
void mostrarFila(Fila *f) {
    printf("Fila: ");
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    srand(time(NULL)); // Inicializa gerador de números aleatórios

    // Gera números aleatórios e insere na fila
    for (int i = 0; i < MAX; i++) {
        int valor = rand() % 100; // Números entre 0 e 99
        enfileirar(&fila, valor);
    }

    mostrarFila(&fila);

    if (estaOrdenadaCrescente(&fila)) {
        printf("A fila está ordenada de forma crescente.\n");
    } else {
        printf("A fila NÃO está ordenada de forma crescente.\n");
    }

    return 0;
}