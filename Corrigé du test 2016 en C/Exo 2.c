#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 1000

bool isprime(int x) //fonction qui vérifie si un nombre x est premier ou pas.
{
    if (x == 1)
        return false;
    for (int i = 2; i <= sqrt(x); ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
} 

int main()
{
    int T[N];
    int n, m;

    /* Cette boucle while empêche d'avoir une valeur de n qui est
    négative ou supérieure à N, et une valeur de m inférieure à 2. */
    while (n < 2 || n > N || m < 2)
    {
        scanf("%d", &n);
        scanf("%d", &m);
    }

    int cpt = 0; // on initialise le compteur qui va compter le nombre de nombres premiers
    int i = m;   // on commence à m, car on nous a demandé  les n premiers nombre premiers > à m.

    /*on va parcourir les nombres commencant à m et à chaque fois où
      on trouve un nombre premier (vérification par la fonction isprime()) 
      on le stocke dans notre tableau et on incrémente notre compteur : "cpt", 
      jusqu'a ce qu'il atteigne la valeur de n, on aura ainsi trouvé n nombres premiers.*/
    while (cpt < n)
    {
        if (isprime(i) == true)
        {
            T[cpt] = i; // le stockage dans le tableau de i car il est premier.
            cpt++;      // l'incrémentation du compteur car on a trouvé un nombre premier.
        }
        i++;
    }

    //arrivé à ce stade on a notre tableau T qui contient les n premiers nombre premiers > à m.

    /*On va maintenant trouver les deux nombres successifs à plus grande différence entre eux
    du tableau*/

    /*on initialise notre variable qui va contenir la différence maximale par la différence
      entre la première et la seconde case du tableau puis on parcours notre tableau et à
      chaque itération, on compare notre différence actuelle avec la prochaine : par exemple
       notre différence actuelle c'est T[1]-T[0], la prochaine sera T[2]-T[1], et si la prochaine
       est supérieure à l'actuelle alors on affecte diff_max avec cette dernière, à la fin
       diff_max contiendra forcément la plus grande différence. */

    int diff_max = T[1] - T[0]; //initialisation de diff_max.

    /* on utlisera une variable pos pour marquer la position de diff_max
        car, il est demandé de donner de quelle nombres provient diff_max. */
    int pos = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if ((T[i + 1] - T[i]) > diff_max)
        {
            diff_max = T[i + 1] - T[i];
            pos = i;
        }
    }

    //affichage des résultats selon le format demandé.
    printf("Les valeurs du tableau sont : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("\n");
    printf("La difference maximale est %d entre %d et %d\n", diff_max, T[pos], T[pos + 1]);
}
