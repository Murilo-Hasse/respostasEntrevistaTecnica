#include <stdio.h>
#include <stdlib.h>

int main (void){
    int index = 13, sum = 0, k = 0;

    while (k < index)
    {
        k++;
        sum += k;
    }
    printf("sum = %d", sum); //91

    return 0;
}