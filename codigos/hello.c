#include <stdio.h>
int main()
{
    int idade = 0;
    printf("informe sua idade  ");
    scanf("&idade");
    if (idade >= 18)
    {
        printf("acesso liberado ");
    }
    else if (idade < 17)
    {
        printf("acesso negado ");
    }

    return (0);
}
