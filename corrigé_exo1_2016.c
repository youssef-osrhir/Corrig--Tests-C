#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    scanf("%d", &n);

    /*au pire des cas n prendra la valeur maximale que peut 
       stocker le type int qui est de 2147483647, ainsi le nombre
       max de chiffre qu'on aura à stocker sera de 10 dans le pire des cas
       c'est pourquoi j'ai déclaré un tableau de 10 cases. */

    int T[10];

    /*la première phase va consister à stocker chacun des chiffres
      de n dans le tableau grace au divisions succesives par 10*/

    int i = 0;
    while (n != 0)
    {
        n = n / 10;
        T[i] = n % 10;
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("%d ", T[i]);
    }
}