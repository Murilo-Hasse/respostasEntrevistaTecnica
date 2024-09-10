#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inversor(char* string){
    int n = strlen(string);
    char *aux;
    aux = (char*)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (string[n-i-1] != '\0')
        {
            aux[i] = string[n-i-1];        
        }else{
            aux[i] = '\0';
        }
        
    }
    return aux;
}

int main(void){
    char string[100];
    printf("Digite uma string: ");
    fgets(string, 100, stdin);
    char *inverted_string = inversor(string);
    printf("Sua string invertida eh: %s\n", inverted_string);

    free(inverted_string);
    return 0;
}