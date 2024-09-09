#include <stdio.h>
#include <stdlib.h>

#define INTMAX 2147483647
#define UINTMAX 4294967295

int fribo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int a = 0, b = 1;
    unsigned int c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        if (c > INTMAX)
        {
            printf("Erro: Estouro de valor maximo permitido.\n");
            return -1;
        }
        a = b;
        b = c;
    }

    return b;
}

void teste1(void)
{
    for (int i = 0;; i++)
    {
        int fib_value = fribo(i);
        if (fib_value == -1)
        {
            break;
        }
        printf("%i\n", fib_value);
    }
}

int teste2(int n)
{
    return fribo(n);
}

int main()
{
    teste1();

    int fib;
    printf("\nInforme o numero que desejar ate %d: \n", 46);
    scanf("%d", &fib);
    printf("%i", teste2(fib));

    return 0;
}