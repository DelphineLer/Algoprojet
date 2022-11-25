#include "BatailleNavale.h"

/**
  * Meme chose que pour la selection normale, exepté qu'on retire tout systeme d'affichage et que les selection utilisateur sont faite aléatoirement.
 */

/**
int IA_recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY);
*/

int IA_recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY)
{
    int erreur = 0;
    int coordX, coordY;
    while (erreur != 1)
    {

        coordX=rand()%InfoGlobales.Options.taille_grille;
        coordY=rand()%InfoGlobales.Options.taille_grille;

        int i, j;
        for (i= coordX; i<InfoGlobales.Options.taille_grille; i++)
        {
            for (j=coordY; j<InfoGlobales.Options.taille_grille; j++)
            {
                if (grille[InfoGlobales.tour_du_joueur][0][0][i][j][0] != 0)
                {
                    coordX=i; coordY=j;
                    i = InfoGlobales.Options.taille_grille;
                    j = InfoGlobales.Options.taille_grille;
                }
            }
        }

        if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] != 0 && grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][1] != 4)
        {
            erreur = 1;

            if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.cuirasse)
            {
                *type_bateau = 1;
            }

            else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.croiseur)
            {
                *type_bateau = 2;
            }

            else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.destroyer)
            {
                *type_bateau = 3;
            }

            else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.sousmarin)
            {
                *type_bateau = 4;
            }


            int i;
            for (i=1; i< 10; i++)
            {
                if (grille[InfoGlobales.tour_du_joueur][*type_bateau][i][coordX][coordY][0] != 0)
                {
                    *numero_bateau = i;
                }
            }
        }
    }
    *posX = coordX;
    *posY = coordY;

    return *type_bateau;
}



