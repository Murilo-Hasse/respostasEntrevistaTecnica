#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct faturamento
{
    char uf[3];
    float value;
    float percentualRepresentatividade;
}faturamento;

float soma(faturamento faturamento[], int n){
    float soma = 0.0;
    for (int i = 0; i < n; i++){
        soma += faturamento[i].value;
    }
    return soma;
}

void calcularPercentual(faturamento faturamento[], int n, float total){
    for (int i = 0; i < n; i++)
    {
        faturamento[i].percentualRepresentatividade = (faturamento[i].value * 100) / total;
    }
}


int main(void){

    faturamento faturamento[5] = {
        {"SP", 67836.43, 0},
        {"RJ", 36678.66, 0},
        {"MG", 29229.88, 0},
        {"ES", 27165.48, 0},
        {"00", 19849.53, 0}
    };

    float total = soma(faturamento, 5);
    calcularPercentual(faturamento, 5, total);
    printf("O faturamento total da empresa foi de %.2f e o percentual por estado foi de:\n", total);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(faturamento[i].uf, "00") == 0)
        {
            printf("OUTROS: %.2f\n", faturamento[i].percentualRepresentatividade);
            break;
        }
        
        printf("%s: %.2f\n", faturamento[i].uf, faturamento[i].percentualRepresentatividade);
    }


    return 0;
}
