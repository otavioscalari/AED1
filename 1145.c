#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y); 
    
    int count = 1; 

    while (count <= y) {

        for (int i = 0; i < x; i++) {
            if (count > y) break; 
            printf("%d", count);
            if (i < x - 1) {
                printf(" "); 
            }
            count++;
        }
        printf("\n"); 
    }

    return 0;
}
