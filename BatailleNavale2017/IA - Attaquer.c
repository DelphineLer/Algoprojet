#include "BatailleNavale.h"

/**
  * Meme chose que pour l'attaque normale, exepté qu'on retire tout systeme d'affichage et que les selection utilisateur sont faite aléatoirement.
 */

/**
void IA_attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
*/


void IA_attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int joueuradverse = num_joueur_adverse(InfoGlobales);
    int i, j;

    for (i = 0; i< 3; i++)
    {
        Y = coordY-1 + i;
        for (j = 0; j<3; j++)
        {
            X = coordX-1 + j;
            if (grille [joueuradverse][0][0][X][Y][0] != InfoGlobales.Affichage.sousmarin)
            {
                attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }
}

void IA_attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int joueuradverse = num_joueur_adverse(InfoGlobales);
    int i, j;

    for (i = 0; i< 2; i++)
    {
        Y = coordY + i;
        for (j = 0; j < 2; j++)
        {
            X = coordX + j;

            if (grille [joueuradverse][0][0][X][Y][0] != InfoGlobales.Affichage.sousmarin)
            {
                attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }
}

void IA_attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int joueuradverse = num_joueur_adverse(InfoGlobales);
    int i, j;

    for (i = 0; i< 1; i++)
    {
        Y = coordY + i;
        for (j = 0; j < 1; j++)
        {
            X = coordX + j;

            if (grille [joueuradverse][0][0][X][Y][0] != InfoGlobales.Affichage.sousmarin)
            {
                attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }
}

void IA_attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{

    attaque_1_case(InfoGlobales, grille, coordX, coordY);
}














