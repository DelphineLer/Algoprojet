#include "BatailleNavale.h"

/**
void eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
*/

void eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int i, j;

    int joueuradverse = num_joueur_adverse(InfoGlobales);

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            if (grille[joueuradverse][0][0][coordX+i][coordY+j][0] != 0)
            {
                grille[InfoGlobales.tour_du_joueur][0][InfoGlobales.tour_du_joueur+1][coordX+i][coordY+j][0] = 1;
            }
        }
    }
}
