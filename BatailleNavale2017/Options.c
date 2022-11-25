#include "BatailleNavale.h"

/**
  * Ce fichier sert à configurer toutes les options (taille de la grille, nombres de bateaux).
  *
  * On definis la taille de la grille dès le debut car on definis les tableaux qui
  * Ne sachant pas gerer l'allocation dynamique, c'est la seule parade que j'ai trouve.
  *
  */

/**
int def_taille_grille();


*/


int def_taille_grille()
{
    int taille_grille;

    clearscreen();
    printf("Quelle taille voulez vous que votre grille fasse? (defaut = 15, min = 10, max = 20):\n\n__\r");

/** TENTATIVE DE BLINDAGE DE LETTRES
    int fin=0;
    char numero1 = '0', numero2= '0';

    while(fin != 1)
    {

        scanf("%c%c", &numero1, &numero2);

        if (numero1 >= '0' && numero1 <= '9' && numero2 >= '0' && numero2 <= '9')
        {
            numero1 = numero1 - '0';
            numero2 = numero2 - '0';

            taille_grille = (numero1 * 10) + (numero2 * 1);

            if (taille_grille > 9 && taille_grille < 27)
            {
                fin = 1;
                break;
            }
            else
            {
                //clearscreen();
                printf("\n\n%d %d %d\n\n\n", numero1 , numero2, taille_grille);
                printf("Quelle taille voulez vous que votre grille fasse? (defaut = 15, min = 10, max = 26):\n\n__\r");
                printf("ERREUR!\n\n__\r");
                numero1 = '0';
                numero2 = '0';
                taille_grille=0;
            }
        }

        else
        {
            //clearscreen();
            printf("\n\n%d %d %d\n\n\n", numero1 , numero2, taille_grille);
            printf("Quelle taille voulez vous que votre grille fasse? (defaut = 15, min = 10, max = 26):\n\n__\r");
            printf("ERREUR!\n\n__\r");
            numero1 = '0';
            numero2 = '0';
            taille_grille=0;
        }
    }
*/



    int fin=0;

    while(fin != 1)
    {
        scanf("%d", &taille_grille);

        if (taille_grille >= 10 && taille_grille <= 20)
        {
            fin = 1;
        }

        else
        {
            clearscreen();
            printf("Quelle taille voulez vous que votre grille fasse? (defaut = 15, min = 10, max = 26):\n\n__\r");
            printf("ERREUR!\n\n__\r");
            taille_grille=0;
        }
    }

    return taille_grille;
}
