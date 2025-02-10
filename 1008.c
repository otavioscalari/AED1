#include <stdio.h>
 
int main() {
 
    int num, horas;
    double vhora, salario;
    scanf("%d\n%d\n%lf", &num, &horas, &vhora);
    salario = horas * vhora;
    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %.2lf\n", salario);
 
    return 0;
}
