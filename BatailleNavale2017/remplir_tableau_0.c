#include "BatailleNavale.h"
/**
void remplir_tableau_text(char tab[101]);
void remplir_tableau_matrice(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
void vider_tableau_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
*/

/**
  * les procédure de ce fichier remplissent differents tableaux, de différentes tailles et dimensions.
  *
 */

void remplir_tableau_text(char tab[101])
{
    int i;
    for (i=0; i<101; i++)
        tab[i] = 0;
}


void remplir_tableau_matrice(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3])
{
    int joueur, bateau, num, coordX, coordY, etat;

    for (joueur = 0; joueur < 2 ; joueur ++)
    {
        for (bateau = 0; bateau < 5; bateau ++)
        {
            for (num = 0; num < 10; num ++)
            {
                for (coordX = 0; coordX < InfoGlobales.Options.taille_grille; coordX++)
                {
                    for (coordY = 0; coordY < InfoGlobales.Options.taille_grille; coordY++)
                    {
                        for (etat = 0; etat < 3; etat++)
                        {
                            grille[joueur][bateau][num][coordX][coordY][etat] = 0;
                        }
                    }
                }
            }
        }
    }
}

void vider_tableau_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3])
{

    int i,j;
    for (i=0; i<InfoGlobales.Options.taille_grille; i++)
    {
        for (j=0; j<InfoGlobales.Options.taille_grille; j++)
        {
            grille[InfoGlobales.tour_du_joueur][0][InfoGlobales.tour_du_joueur+1][i][j][0] = 0;

        }
    }

}
