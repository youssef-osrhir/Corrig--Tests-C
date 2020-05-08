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
        T[i] = n % 10;
        n = n / 10;
        i++;
    }

    /*on parcours notre tableau de 0 vers i
      car i est le nombre de chiffres de n
       vue que i a été incrémenté à chaque fois
       qu'on ajoute un chiffre au tableau*/

    for (int j = 1; j < i; j++)
    {
        int k = j;
        /* on parcours le tableau de j vers 0, 
         k sera notre itérateur : il va 
        prendre les valeurs de j vers 0 */

        /*à chaque fois où une valeur est inférieure
         à celle juste avant elle(les valeurs de j vers 0), 
         on permute leurs  places: c'est le tri par insertion */

        while (k > 0)
        {
            if (T[k] < T[k - 1])
            {
                /*permutation classique de deux variables
                 utilisant une variable temporaire: tmp*/
                int tmp;
                tmp = T[k - 1];
                T[k - 1] = T[k];
                T[k] = tmp;
            }
            k--; // à chaque fois on décrémente k commençant de j et arrivant vers 0
        }
    }

    for (int j = 0; j < i; ++j)
    {
        printf("%d ", T[j]);
    }
}
