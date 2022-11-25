#include "BatailleNavale.h"

/**
  * Fonction d'action: attaque.
  * La première procédure créer l'attaque sur une seule case, et les précédures suivantes executent cette procédure plusieurs fois en fonction du bateau qui attaque.
 */

/**
int attaque_1_case(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaquer_grille_entiere(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
*/

int attaque_1_case(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int retour, bateau_ko;
    int type_bateau, numero_bateau;

    int coordXoppose, coordYoppose;

    int joueuradverse = num_joueur_adverse(InfoGlobales);


    if (coordX >= InfoGlobales.Options.taille_grille)
    {
        coordX = InfoGlobales.Options.taille_grille-1;
    }
    if (coordY >= InfoGlobales.Options.taille_grille)
    {
        coordY = InfoGlobales.Options.taille_grille-1;
    }
    if (coordX < 0)
    {
        coordX = 0;
    }
    if (coordY < 0)
    {
        coordY = 0;
    }


    if (grille[joueuradverse][0][0][coordX][coordY][0] == 0)
    {
        retour = 0;
    }

    else
    {

        retour = 1;
        if (grille[joueuradverse][0][0][coordX][coordY][0] == InfoGlobales.Affichage.cuirasse)
        {
            type_bateau = 1;
        }

        else if (grille[joueuradverse][0][0][coordX][coordY][0] == InfoGlobales.Affichage.croiseur)
        {
            type_bateau = 2;
        }

        else if (grille[joueuradverse][0][0][coordX][coordY][0] == InfoGlobales.Affichage.destroyer)
        {
            type_bateau = 3;
        }

        else if (grille[joueuradverse][0][0][coordX][coordY][0] == InfoGlobales.Affichage.sousmarin)
        {
            type_bateau = 4;
        }


        int i;
        for (i=1; i< 10; i++)
        {
            if (grille[joueuradverse][type_bateau][i][coordX][coordY][0] != 0)
            {
                numero_bateau = i;
            }
        }

        if (grille[joueuradverse][0][0][coordX][coordY][1] != 4)
        {
            grille[joueuradverse][0][0][coordX][coordY][1] = 3;
            grille[joueuradverse][type_bateau][0][coordX][coordY][0] = 3;
        }



        if (grille[joueuradverse][type_bateau][numero_bateau][coordX][coordY][1] == 1) ///HORIZONTALE
        {
            while (grille[joueuradverse][type_bateau][numero_bateau][coordX][coordY][0] != 0)
            {
                coordX++;
            }
            coordX--;

            coordXoppose = coordX;
            while (grille[joueuradverse][type_bateau][numero_bateau][coordXoppose][coordY][0] != 0)
            {
                coordXoppose--;
            }
            coordXoppose++;

            bateau_ko = 0;
            i = coordX;
            while (i >= coordXoppose)
            {
                if (grille[joueuradverse][0][0][i][coordY][1] != 3 && grille[joueuradverse][0][0][i][coordY][1] != 4)
                {
                    bateau_ko = 1;
                    grille[joueuradverse][0][0][i][coordY][1] = 2;
                    grille[joueuradverse][type_bateau][0][i][coordY][1] = 2;
                }
                i--;
            }

            if (bateau_ko == 0)
            {
                i = coordX;
                while (i >= coordXoppose)
                {
                    grille[joueuradverse][0][0][i][coordY][1] = 4;
                    grille[joueuradverse][type_bateau][0][i][coordY][1] = 4;
                    grille[joueuradverse][type_bateau][numero_bateau][i][coordY][1] = 3;
                    i--;
                }
            }

        }


        else if (grille[joueuradverse][type_bateau][numero_bateau][coordX][coordY][1] == 2) ///VERTICAL
        {
            while (grille[joueuradverse][type_bateau][numero_bateau][coordX][coordY][0] != 0)
            {
                coordY++;
            }
            coordY--;


            coordYoppose = coordY;
            while (grille[joueuradverse][type_bateau][numero_bateau][coordX][coordYoppose][0] != 0)
            {
                coordYoppose--;
            }
            coordYoppose++;

            int bateau_ko = 0;
            i = coordY;

            while (i >= coordYoppose)
            {
                if (grille[joueuradverse][0][0][coordX][i][1] != 3 && grille[joueuradverse][0][0][coordX][i][1] != 4)
                {
                    bateau_ko = 1;
                    grille[joueuradverse][0][0][coordX][i][1] = 2;
                    grille[joueuradverse][type_bateau][0][coordX][i][1] = 2;
                }
                i--;
            }

            if (bateau_ko == 0)
            {
                i = coordY;
                while (i >= coordYoppose)
                {
                    grille[joueuradverse][0][0][coordX][i][1] = 4;
                    grille[joueuradverse][type_bateau][0][coordX][i][1] = 4;
                    grille[joueuradverse][type_bateau][numero_bateau][coordX][i][1] = 3;
                    i--;
                }
            }
        }
    }
    return retour;
}

void attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int nombre_touches = 0;
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
                nombre_touches = nombre_touches + attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }

    if (nombre_touches == 0)
    {
        printf("\nVous n'avez touche que de l'eau.");
    }

    else
    {
        printf("\nVous avez fait %d cases de degats.", nombre_touches);
    }

    system("pause");
}

void attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int nombre_touches = 0;
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
                nombre_touches = nombre_touches + attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }

    if (nombre_touches == 0)
    {
        printf("\nVous n'avez touche que de l'eau.");
    }

    else
    {
        printf("\nVous avez fait %d cases de degats.", nombre_touches);
    }

    system("pause");
}

void attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int nombre_touches = 0;
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
                nombre_touches = nombre_touches + attaque_1_case(InfoGlobales, grille, X, Y);
            }
        }
    }

    if (nombre_touches == 0)
    {
        printf("\nVous n'avez touche que de l'eau.");
    }

    else
    {
        printf("\nVous avez fait %d cases de degats.", nombre_touches);
    }

    system("pause");
}

void attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int nombre_touches = 0;

    nombre_touches = attaque_1_case(InfoGlobales, grille, coordX, coordY);

    if (nombre_touches == 0)
    {
        printf("\nVous n'avez touche que de l'eau.");
    }

    else
    {
        printf("\nVous avez fait %d cases de degats.", nombre_touches);
    }

    system("pause");
}

void attaquer_grille_entiere(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int X, Y;
    int nombre_touches = 0;
    int i, j;

    for (i = 0; i< InfoGlobales.Options.taille_grille; i++)
    {
        Y = coordY + i;
        for (j = 0; j < InfoGlobales.Options.taille_grille; j++)
        {
            X = coordX + j;

            nombre_touches = nombre_touches + attaque_1_case(InfoGlobales, grille, X, Y);
        }
    }

    if (nombre_touches == 0)
    {
        printf("\nVous n'avez touche que de l'eau.");
    }

    else
    {
        printf("\nVous avez fait %d cases de degats.", nombre_touches);
    }

    system("pause");
}












