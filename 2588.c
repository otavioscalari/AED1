#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int minLettersToAdd(char sequence[]) {
    int freq[26] = {0}; 
    int oddCount = 0; 

    for (int i = 0; i < strlen(sequence); i++) {
        freq[sequence[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    return (oddCount == 0) ? 0 : oddCount - 1;
}

int main() {
    char sequence[MAX_LENGTH];

    while (scanf("%s", sequence) != EOF) {
        printf("%d\n", minLettersToAdd(sequence));
    }

    return 0;
}
