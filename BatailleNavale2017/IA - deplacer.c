#include "BatailleNavale.h"

/**
  * Meme chose que pour les deplacement normaux, exept� qu'on retire tout systeme d'affichage et que les selection utilisateur sont faite al�atoirement.
 */

/**
int IA_deplacer_bateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);
int IA_deplacer_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);
*/


int IA_deplacer_bateau(INFG InfoGlobales,
                      char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3],
                      int coordX, int coordY, int *fin_du_tour)

{
    int type_bateau, taille_bateau, numero_bateau, destroyer_eclairage = 0;
    char lettre_bateau;
    int retour = 0;

    if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][1] != 1)
    {
        *fin_du_tour = 0;
        return 0;
    }

    //if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.cuirasse)
    //Bug sans aucune raison sur les cuirrasses de la grille du premier joueur, mais marche sans soucis sur celle du second.
    if (grille[InfoGlobales.tour_du_joueur][1][0][coordX][coordY][0] != 0)
    {
        type_bateau = 1;
        lettre_bateau = InfoGlobales.Affichage.cuirasse;
        taille_bateau = 7;
    }

    else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.croiseur)
    {
        type_bateau = 2;
        lettre_bateau = InfoGlobales.Affichage.croiseur;
        taille_bateau = 5;
    }

    else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.destroyer)
    {
        type_bateau = 3;
        lettre_bateau = InfoGlobales.Affichage.destroyer;
        taille_bateau = 3;
    }

    else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == InfoGlobales.Affichage.sousmarin)
    {
        type_bateau = 4;
        lettre_bateau = InfoGlobales.Affichage.sousmarin;
        taille_bateau = 1;
    }

    int i;
    for (i=1; i< 10; i++)
    {
        if (grille[InfoGlobales.tour_du_joueur][type_bateau][i][coordX][coordY][0] != 0)
        {
            numero_bateau = i;
        }
    }

    int save_bateau[taille_bateau][3];

    if (grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][1] == 1) ///HORIZONTALE
    {
        while (grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][0] != 0)
        {
            coordX++;
        }
        coordX--;


        for (i=0; i<taille_bateau; i++)
        {
            save_bateau[i][0] = coordX-i;
            save_bateau[i][1] = coordY;
            save_bateau[i][2] = grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX-i][coordY][1];


            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX-i][coordY][1] = 0;
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX-i][coordY][0] = 0;

            grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX-i][coordY][1] = 0;
            grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX-i][coordY][0] = 0;

            grille[InfoGlobales.tour_du_joueur][0][0][coordX-i][coordY][1] = 0;
            grille[InfoGlobales.tour_du_joueur][0][0][coordX-i][coordY][0] = 0;

            if (type_bateau == 3 && grille[InfoGlobales.tour_du_joueur][type_bateau][9][coordX-i][coordY][1] == 1)
            {
                destroyer_eclairage = 1;
                grille[InfoGlobales.tour_du_joueur][type_bateau][9][coordX-i][coordY][1] = 0;
            }
        }


        switch (rand()%2)
        {
            case 0: //droite

                if (coordX +1 == InfoGlobales.Options.taille_grille)
                {
                    retour = 1;
                }
                else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX +1] [coordY] [1] != 0)
                {
                    retour = 2;
                }
                else
                {
                    for (i=0; i<taille_bateau; i++)
                    {
                        save_bateau[i][0]++;
                    }
                }
                break;

            case 1: //gauche
                if (coordX - taille_bateau + 1 == 0)
                {
                    retour = 1;
                }
                else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX - taille_bateau] [coordY] [1] != 0)
                {
                    retour = 2;
                }
                else
                {
                    for (i=0; i<taille_bateau; i++)
                    {
                        save_bateau[i][0]--;
                    }
                    break;
                }

        }

        for (i=0; i<taille_bateau; i++)
        {
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[i][0]] [save_bateau[i][1]] [1] = 1;
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[i][0]] [save_bateau[i][1]] [0] = 1;

            grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[i][0]] [save_bateau[i][1]] [1] = save_bateau[i][2];
            grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[i][0]] [save_bateau[i][1]] [0] = lettre_bateau;

            grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[i][0]] [save_bateau[i][1]] [1] = save_bateau[i][2];
            grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[i][0]] [save_bateau[i][1]] [0] = lettre_bateau;

            if (destroyer_eclairage == 1)
            {
                grille[InfoGlobales.tour_du_joueur][type_bateau][9] [save_bateau[i][0]] [save_bateau[i][1]] [1] = 1;
            }
        }
    }





    else if (grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][1] == 2) ///Vertical
    {
        while (grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][0] != 0)
        {
            coordY++;
        }
        coordY--;


        for (i=0; i<taille_bateau; i++)
        {
            save_bateau[i][0] = coordX;
            save_bateau[i][1] = coordY-i;
            save_bateau[i][2] = grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY-i][1];


            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY-i][1] = 0;
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY-i][0] = 0;

            grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY-i][1] = 0;
            grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY-i][0] = 0;

            grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY-i][1] = 0;
            grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY-i][0] = 0;

            if (type_bateau == 3 && grille[InfoGlobales.tour_du_joueur][type_bateau][9][coordX][coordY-i][1] == 1)
            {
                destroyer_eclairage = 1;
                grille[InfoGlobales.tour_du_joueur][type_bateau][9][coordX][coordY-i][1] = 0;
            }
        }


        switch (rand()%2)
        {
            case 0: //Haut
                if (coordY - taille_bateau + 1 == 0)
                {
                    retour = 1;
                }
                else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX] [coordY - taille_bateau] [1] != 0)
                {
                    retour = 2;
                }
                else
                {
                    for (i=0; i<taille_bateau; i++)
                    {
                        save_bateau[i][1]--;
                    }
                }
                break;

            case 1: //Bas
                if (coordY+1 == InfoGlobales.Options.taille_grille)
                {
                    retour = 1;
                }
                else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX] [coordY+1] [1] != 0)
                {
                    retour = 2;
                }
                else
                {
                    for (i=0; i<taille_bateau; i++)
                    {
                        save_bateau[i][1]++;
                    }
                    break;
                }

        }

        for (i=0; i<taille_bateau; i++)
        {
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[i][0]] [save_bateau[i][1]] [1] = 2;
            grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[i][0]] [save_bateau[i][1]] [0] = 1;

            grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[i][0]] [save_bateau[i][1]] [1] = save_bateau[i][2];
            grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[i][0]] [save_bateau[i][1]] [0] = lettre_bateau;

            grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[i][0]] [save_bateau[i][1]] [1] = save_bateau[i][2];
            grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[i][0]] [save_bateau[i][1]] [0] = lettre_bateau;

            if (destroyer_eclairage == 1)
            {
                grille[InfoGlobales.tour_du_joueur][type_bateau][9] [save_bateau[i][0]] [save_bateau[i][1]] [1] = 1;
            }
        }
    }

    if (retour == 1 || retour == 2)
    {
        *fin_du_tour = 0;
    }

    return 0;
}

int IA_deplacer_sousmarin(INFG InfoGlobales,
                      char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3],
                      int coordX, int coordY, int *fin_du_tour)

{
    int type_bateau = 4, taille_bateau = 1, numero_bateau;
    char lettre_bateau = InfoGlobales.Affichage.sousmarin;
    int retour;

    if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][1] != 1)
    {
        *fin_du_tour = 0;
        return 0;
    }

    int i;
    for (i=1; i< 10; i++)
    {
        if (grille[InfoGlobales.tour_du_joueur][type_bateau][i][coordX][coordY][0] != 0)
        {
            numero_bateau = i;
        }
    }

    int save_bateau[1][3];


    save_bateau[0][0] = coordX;
    save_bateau[0][1] = coordY;
    save_bateau[0][2] = grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY][1];


    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][1] = 0;
    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][coordX][coordY][0] = 0;

    grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY][1] = 0;
    grille[InfoGlobales.tour_du_joueur][type_bateau][0][coordX][coordY][0] = 0;

    grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][1] = 0;
    grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] = 0;



    switch (rand()%4)
    {
        case 0: //Haut
            if (coordY - taille_bateau + 1 == 0)
            {
                retour = 1;
            }
            else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX] [coordY - taille_bateau] [1] != 0)
            {
                retour = 2;
            }
            else
            {
                save_bateau[0][1]--;
            }
            break;

        case 1: //Bas
            if (coordY+1 == InfoGlobales.Options.taille_grille)
            {
                retour = 1;
            }
            else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX] [coordY+1] [1] != 0)
            {
                retour = 2;
            }
            else
            {
                save_bateau[0][1]++;
                break;
            }
        case 2: //droite

            if (coordX +1 == InfoGlobales.Options.taille_grille)
            {
                retour = 1;
            }
            else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX +1] [coordY] [1] != 0)
            {
                retour = 2;
            }
            else
            {
                save_bateau[0][0]++;
            }
            break;

        case 3: //gauche
            if (coordX - taille_bateau + 1 == 0)
            {
                retour = 1;
            }
            else if (grille[InfoGlobales.tour_du_joueur][0][0] [coordX - taille_bateau] [coordY] [1] != 0)
            {
                retour = 2;
            }
            else
            {
                save_bateau[0][0]--;

                break;
            }




    }


    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[0][0]] [save_bateau[0][1]] [1] = 1;
    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau] [save_bateau[0][0]] [save_bateau[0][1]] [0] = 1;

    grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[0][0]] [save_bateau[0][1]] [1] = save_bateau[0][2];
    grille[InfoGlobales.tour_du_joueur][type_bateau][0] [save_bateau[0][0]] [save_bateau[0][1]] [0] = lettre_bateau;

    grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[0][0]] [save_bateau[0][1]] [1] = save_bateau[0][2];
    grille[InfoGlobales.tour_du_joueur][0][0] [save_bateau[0][0]] [save_bateau[0][1]] [0] = lettre_bateau;


    if (retour == 1 || retour == 2)
    {
        *fin_du_tour = 0;
    }

    return 0;

}
