#include <stdio.h>

int main() {

    char nome[20];
    double salario, totalVendas, receber;
    scanf("%s\n%lf\n%lf", &nome, &salario, &totalVendas);
    receber = salario + 0.15 * totalVendas;
    printf("TOTAL = R$ %.2lf\n", receber);

    return 0;
}
