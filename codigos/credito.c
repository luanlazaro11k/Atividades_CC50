#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num_Digitos(long num_Cartao);
int dois_Primeiros(long num_Cartao, int numeros_de_Digitos);
int multiplicar(long num_Cartao);
int somar(long num_Cartao);
int valido(int resultado_Algoritmo, int dois_Primeiros_Digitos, int numero_de_Digitos);

int main(void)
{
    long num_Cartao = get_long("numero:  ");
    int numeros_de_Digitos = num_Digitos(num_Cartao);
    int dois_Primeiros_Digitos = dois_Primeiros(num_Cartao, numeros_de_Digitos);
    int multiplicacao = multiplicar(num_Cartao);
    int soma = somar(num_Cartao);
    int resultado_Algoritimo = multiplicacao + soma;
    valido(resultado_Algoritimo, dois_Primeiros_Digitos, numeros_de_Digitos);
}

int num_Digitos(long num_Cartao)
{
    int num_Digitos = 0;
    while (num_Cartao > 0)
    {
        num_Cartao = num_Cartao / 10;
        num_Digitos++;
    }
    return num_Digitos;
}

int dois_Primeiros(long num_Cartao, int numeros_de_Digitos)
{
    int dois_Primeiros = num_Cartao / pow(10, numeros_de_Digitos - 2);

    return dois_Primeiros;
}

int multiplicar(long num_Cartao)
{
    int multiplicacao = 0;
    int operacao;
    while (num_Cartao > 0)
    {
        num_Cartao /= 10;
        operacao = (num_Cartao % 10) * 2;
        if (operacao > 9)
        {
            operacao = (operacao % 10) + (operacao / 10);
        }
        multiplicacao = operacao + multiplicacao;
        num_Cartao /= 10;
    }
    return multiplicacao;
}
int somar(long num_Cartao)
{
    int soma = 0;
    while (num_Cartao > 0)
    {
        soma = (num_Cartao % 10) + soma;
        num_Cartao /= 100;
    }
    return soma;
}

int valido(int resultado_Algoritmo, int dois_Primeiros_Digitos, int numeros_de_Digitos)
{
    if (resultado_Algoritmo % 10 == 0)
    {

        if ((dois_Primeiros_Digitos == 34 || dois_Primeiros_Digitos == 37) &&
            (numeros_de_Digitos == 15))
        {
            return printf("AMEX\n");
        }
        else if ((dois_Primeiros_Digitos >= 51 && dois_Primeiros_Digitos <= 55) &&
                 (numeros_de_Digitos == 16))
        {
            return printf("MASTERCARD\n");
        }
        else if ((dois_Primeiros_Digitos >= 40 && dois_Primeiros_Digitos <= 49) &&
                 (numeros_de_Digitos <= 16 && numeros_de_Digitos >= 13))
        {
            return printf("VISA\n");
        }
        else
        {
            return printf("INVALIDO\n");
        }
    }
    else
    {
        return printf("INVALIDO\n");
    }
}
