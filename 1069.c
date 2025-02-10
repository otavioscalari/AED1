#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    int capacidade;
    char *dados;
} Pilha;

Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->dados = (char *)malloc(pilha->capacidade * sizeof(char));
    return pilha;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, char elemento) {
    pilha->dados[++pilha->topo] = elemento;
}

char desempilhar(Pilha *pilha) {
    if (!pilhaVazia(pilha))
        return pilha->dados[pilha->topo--];
    return '\0';
}

int contarDiamantes(char *sequencia) {
    Pilha *pilha = criarPilha(strlen(sequencia));
    int quantidadeDiamantes = 0;

    for (int indice = 0; sequencia[indice] != '\0'; indice++) {
        if (sequencia[indice] == '<') {
            empilhar(pilha, '<');
        } else if (sequencia[indice] == '>') {
            if (!pilhaVazia(pilha) && pilha->dados[pilha->topo] == '<') {
                quantidadeDiamantes++;
                desempilhar(pilha);
            }
        }
    }

    free(pilha->dados);
    free(pilha);
    return quantidadeDiamantes;
}

int main() {
    int quantidadeTestes;
    scanf("%d", &quantidadeTestes);
    getchar(); 

    char **entradas = (char **)malloc(quantidadeTestes * sizeof(char *));
    int *resultados = (int *)malloc(quantidadeTestes * sizeof(int));

    for (int indiceTeste = 0; indiceTeste < quantidadeTestes; indiceTeste++) {
        char *sequencia = (char *)malloc(1001 * sizeof(char));
        fgets(sequencia, 1001, stdin);
        entradas[indiceTeste] = sequencia;
        resultados[indiceTeste] = contarDiamantes(sequencia);
    }

    for (int indiceTeste = 0; indiceTeste < quantidadeTestes; indiceTeste++) {
        printf("%d\n", resultados[indiceTeste]);
        free(entradas[indiceTeste]);
    }

    free(entradas);
    free(resultados); 

    return 0;
}
