#include "BatailleNavale.h"

/**
  * L'éclairage ajoute dans une grille annexe les bateaux éclairés. Ils sont indiqué dans cette grille par une valeur booléenne.
  * Ensuite, l'affichage de la grille verra verifiera s'il faut afficher ces bateaux, et les afficheras en fonction.
  * Ensuite, on supprime la capacitée du destroyer à lancer des fusées eclairantes.
 */

/**
void eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void suppr_eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
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


void suppr_eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int numero_bateau;

    int i;
    for (i=1; i< 10; i++)
    {
        if (grille[InfoGlobales.tour_du_joueur][3][i][coordX][coordY][0] != 0)
        {
            numero_bateau = i;
        }
    }

    if (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][1] == 1) ///HORIZONTALE
    {

        while (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][0] != 0)
        {
            coordX++;
        }
        coordX--;

       for (i=0; i<3; i++)
        {
            grille[InfoGlobales.tour_du_joueur][3][9][coordX-i][coordY][1] = 0;
        }

    }


    else if (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][1] == 2) ///VERTICAL
    {
        while (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][0] != 0)
        {
            coordY++;
        }
        coordY--;

       for (i=0; i<3; i++)
        {
            grille[InfoGlobales.tour_du_joueur][3][9][coordX][coordY-i][1] = 0;
        }
    }
}
