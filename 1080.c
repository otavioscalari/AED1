#include <stdio.h>

int main() {
    int valores[100];
    int maiorValor, posicao;
    for (int i = 0; i < 100; i++) {
        scanf("%d", &valores[i]);
    }
    maiorValor = valores[0];
    posicao = 1;
    for (int i = 1; i < 100; i++) {
        if (valores[i] > maiorValor) {
            maiorValor = valores[i];
            posicao = i + 1;
        }
    }
    printf("%d\n%d\n", maiorValor, posicao);
    return 0;
}
