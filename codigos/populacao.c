#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int tamanho_Inicial, tamanho_Final;
    int anos = 0;

    do
    {
        tamanho_Inicial = get_int("Start size:  ");
    }
    while (tamanho_Inicial < 9);

    do
    {
        tamanho_Final = get_int("End size: ");
    }
    while (tamanho_Inicial > tamanho_Final);

    if (tamanho_Inicial == tamanho_Final)
    {
        printf("year o");
    }
    else
    {
        do
        {
            tamanho_Inicial = (tamanho_Inicial + tamanho_Inicial / 3) - tamanho_Inicial / 4;
            anos++;
        }
        while (tamanho_Inicial < tamanho_Final);
        printf("YEARS: %i\n", anos);
    }
}
