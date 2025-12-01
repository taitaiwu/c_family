#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

int main() {
    while(1){
        int dec;
        char hex[9], nhex[9];
    
        printf("Input decimal: ");
        scanf("%d", &dec);
    
        sprintf(hex, "%08X", dec);
        strcpy(nhex, hex);
    
        swap(&nhex[0], &nhex[1]);
        swap(&nhex[2], &nhex[3]);
        swap(&nhex[4], &nhex[5]);
        swap(&nhex[6], &nhex[7]);
    
        int ndec = strtol(nhex, NULL, 16);
        printf("%d\n", ndec);
    }
}