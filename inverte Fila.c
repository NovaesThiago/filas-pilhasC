#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura da fila
typedef struct {
    int dados[MAX];
    int frente;
    int tras;
} Fila;

// Estrutura da pilha
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializa fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Inicializa pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Enfileira elemento
void enfileirar(Fila *f, int valor) {
    if (f->tras < MAX - 1) {
        f->tras++;
        f->dados[f->tras] = valor;
    }
}

// Desenfileira elemento
int desenfileirar(Fila *f) {
    if (f->frente <= f->tras) {
        return f->dados[f->frente++];
    }
    return -1; // Fila vazia
}

// Empilha elemento
void empilhar(Pilha *p, int valor) {
    if (p->topo < MAX - 1) {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

// Desempilha elemento
int desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->dados[p->topo--];
    }
    return -1; // Pilha vazia
}

// Inverte fila F1 usando pilha auxiliar e cria F2
void inverterFila(Fila *f1, Fila *f2) {
    Pilha p;
    inicializarPilha(&p);

    // Passa elementos da fila para a pilha
    while (f1->frente <= f1->tras) {
        empilhar(&p, desenfileirar(f1));
    }

    // Passa elementos da pilha para a nova fila
    while (p.topo >= 0) {
        enfileirar(f2, desempilhar(&p));
    }
}

// Exibe fila
void mostrarFila(Fila *f) {
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila f1, f2;
    inicializarFila(&f1);
    inicializarFila(&f2);

    // Exemplo: preenchendo F1
    enfileirar(&f1, 10);
    enfileirar(&f1, 20);
    enfileirar(&f1, 30);
    enfileirar(&f1, 40);

    printf("Fila original F1: ");
    mostrarFila(&f1);

    inverterFila(&f1, &f2);

    printf("Fila invertida F2: ");
    mostrarFila(&f2);

    return 0;
}