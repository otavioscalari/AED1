#include <stdio.h>

int main() {

    int i, j;
    i = 1;
    for(j=60; j>=0; j--){
        if(j%5==0){
            printf("I=%d J=%d\n", i, j);
            i = i + 3;
        }
    }
    return 0;
}
