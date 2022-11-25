#include "BatailleNavale.h"

/**
  * Ici, on testles bateaux afin de verifier si ils sont tous coulés ou pas.
  * Idem pour les sous-marins.
 */

int detecter_fin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3])
{
    int i, j;
    int joueur_ennemi = num_joueur_adverse(InfoGlobales);
    int nombre_sousmarin = 0;


    for(i=0; i<InfoGlobales.Options.taille_grille; i++)
    {
        for (j=0; j<InfoGlobales.Options.taille_grille; j++)
        {
            if(grille[joueur_ennemi][4][0][j][i][1]==1 && grille[joueur_ennemi][0][0][j][i][1] != 4)
            {
                nombre_sousmarin++;
            }
        }
    }

    if (nombre_sousmarin > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

    for (i=0; i<InfoGlobales.Options.taille_grille; i++)
    {
        for (j=0; j<InfoGlobales.Options.taille_grille; j++)
        {
            if (grille[joueur_ennemi][0][0][i][j][1] == 1 || grille[joueur_ennemi][0][0][i][j][1] == 2)
            {
                return 0;
            }
        }
    }




    return 1;
}
