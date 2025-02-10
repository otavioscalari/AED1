#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *proximo;
} No;

void Empilhar(No **topo, char dado) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = dado;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

char Desempilhar(No **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    No *remover = *topo;
    char dado = remover->dado;
    *topo = remover->proximo;
    free(remover);
    return dado;
}

int main() {
    int quantidadeCaracteres, indiceEntrada, indiceSaida;
    char sequenciaEntrada[27], sequenciaSaida[27];
    No *pilha;

    while (scanf("%d", &quantidadeCaracteres) && quantidadeCaracteres != 0) {
        for (indiceEntrada = 0; indiceEntrada < quantidadeCaracteres; indiceEntrada++){
            scanf("%s", &sequenciaEntrada[indiceEntrada]);
        }
        for (indiceEntrada = 0; indiceEntrada < quantidadeCaracteres; indiceEntrada++){
            scanf("%s", &sequenciaSaida[indiceEntrada]);
        }

        char operacoes[2 * quantidadeCaracteres + 1];
        int indiceOperacoes = 0;

        pilha = NULL;
        indiceEntrada = 0;
        indiceSaida = 0;

        while (indiceEntrada < quantidadeCaracteres) {
            Empilhar(&pilha, sequenciaEntrada[indiceEntrada]);
            operacoes[indiceOperacoes++] = 'I';

            while (pilha != NULL && pilha->dado == sequenciaSaida[indiceSaida]) {
                Desempilhar(&pilha);
                operacoes[indiceOperacoes++] = 'R';
                indiceSaida++;
            }
            indiceEntrada++;
        }

        while (pilha != NULL && pilha->dado == sequenciaSaida[indiceSaida]) {
            Desempilhar(&pilha);
            operacoes[indiceOperacoes++] = 'R';
            indiceSaida++;
        }

        operacoes[indiceOperacoes] = '\0';

        if (indiceSaida == quantidadeCaracteres) {
            printf("%s\n", operacoes);
        } else {
            printf("%s Impossible\n", operacoes);
        }
    }

    return 0;
}
