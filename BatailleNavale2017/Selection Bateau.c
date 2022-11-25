#include "BatailleNavale.h"

/**
  * l'utilisateur rentre une coordonéee.
  * ENsuite, en fonction de l'action (attaque, deplacement, selection d'un bateau), on verifie s'il y a un bateau sur le plateau allié/ennemis et on renvoie le bateau présent.
 */

/**
int recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY);
void suppr_destroyer_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);

*/

int recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY)
{
    int erreur = 0;
    int coordX, coordY;
    int echap = 0;
    while (erreur != 1)
    {

        echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

        if (echap == -1)
        {
            return -1;
        }

        else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][0] == 0)
        {
            printf("Il n'y a aucun bateau a ces coordonnees. Veuillez les ressaisir.\n");
        }

        else if (grille[InfoGlobales.tour_du_joueur][0][0][coordX][coordY][1] == 4)
        {
            printf("Vous ne pouvez pas jouer avec un bateau coule!\n");
        }

        else
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


void suppr_destroyer_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY)
{
    int i;
    int numero_bateau;
    for (i=1; i < 9; i++)
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
        int coordXoppose = coordX;
        while (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordXoppose][coordY][0] != 0)
        {
            coordXoppose--;
        }
        coordXoppose++;
        while (coordX >= coordXoppose)
        {
            grille[InfoGlobales.tour_du_joueur][3][9][coordX][coordY][1] = 0;
            coordX--;
        }

    }


    else if (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][1] == 2) ///VERTICAL
    {
        while (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordY][0] != 0)
        {
            coordY++;
        }
        coordY--;

        int coordYoppose = coordY;
        while (grille[InfoGlobales.tour_du_joueur][3][numero_bateau][coordX][coordYoppose][0] != 0)
        {
            coordYoppose--;
        }
        coordYoppose++;
        while (coordY >= coordYoppose)
        {
            grille[InfoGlobales.tour_du_joueur][3][9][coordX][coordY][1] = 0;
            coordY--;
        }
    }
}




int recuperer_coordonnes(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *coordX, int *coordY)
{
    int taillegrille = InfoGlobales.Options.taille_grille-1;
    char str[101];
    int taille_mot;
    int recup_mot=0, mot_correct=0;
    int posX, posY;

    while (mot_correct != 1)
    {
        while (recup_mot != 1)
        {
            gets(str);

            int i;
            for (i=0; i<101; i++)
            {
                if (str[i] == '\0')
                {
                    taille_mot = i;
                    i=101;
                }
            }

            if (str[0] == '-' || taille_mot == 2 || taille_mot == 3)
            {
                recup_mot = 1;
            }
            else if (str[0] == '3' && str[1] == '.' && str[2] == '1' && str[3] == '4')
            {
                //Ajout d'un cheatcode qui permet d'afficher la grille adverse en tapant "3.14"
                InfoGlobales.tour_du_joueur = num_joueur_adverse(InfoGlobales);
                afficher_plateau(InfoGlobales, grille, 0, 3, 0);
                InfoGlobales.tour_du_joueur = num_joueur_adverse(InfoGlobales);
                printf("\n\n\n\n\n    \r");
            }
            else if (str[0] == 'y' && str[1] == 'z' && str[2] == 'a' && str[3] == 'b')
            {
                //Cheatcode qui détruit le plateau adverse.
                attaquer_grille_entiere(InfoGlobales, grille, 0, 0);
                taille_mot = 2;
                str[0] = 'a';
                str[1] = '1';
                recup_mot = 1;
            }
            else
            {
                printf("ERREUR1\n");
            }
        }
        recup_mot=0;

        if (str[0] == '-')
        {
            return -1;
        }

        else if(taille_mot == 2)
        {
            if (str[0] >= '1' && str[0] <= '9' && str[1] >= 'a' && str[1] <= 'a'+taillegrille)
            {
                posX = str[0] - '1';
                posY = str[1] - 'a';

            }
            else if (str[0] >= '1' && str[0] <= '9' && str[1] >= 'A' && str[1] <= 'A'+taillegrille)
            {
                posX = str[0] - '1';
                posY = str[1] - 'A';

            }
            else if (str[1] >= '1' && str[1] <= '9' && str[0] >= 'a' && str[0] <= 'a'+taillegrille)
            {
                posX = str[1] - '1';
                posY = str[0] - 'a';

            }
            else if (str[1] >= '1' && str[1] <= '9' && str[0] >= 'A' && str[0] <= 'A'+taillegrille)
            {
                posX = str[1] - '1';
                posY = str[0] - 'A';

            }
            else
                printf("ERREUR2\n");;


            if (posX < 0 || posX > taillegrille)
                printf("ERREUR3\n");

            else
            {
                mot_correct = 1;
                recup_mot=1;
                *coordX = posX;
                *coordY = posY;
            }
        }

        if(taille_mot == 3)
        {
            if (str[0] >= '0' && str[0] <= '9' && str[1] >= '0' && str[1] <= '9' && str[2] >= 'a' && str[2] <= 'a'+taillegrille)
                {
                    posX = (str[0]-'0')*10 + (str[1]-'0') -1 ;
                    posY = str[2] - 'a';
                }
            else if (str[0] >= '0' && str[0] <= '9' && str[1] >= '0' && str[1] <= '9' && str[2] >= 'A' && str[2] <= 'A'+taillegrille)
                {
                    posX = (str[0]-'0')*10 + (str[1]-'0') -1 ;
                    posY = str[2] - 'A';
                }
            else if (str[0] >= 'a' && str[0] <= 'a'+taillegrille && str[1] >= '0' && str[1] <= '9' && str[2] >= '0' && str[2] <= '9')
                {
                    posX = (str[1]-'0')*10 + (str[2]-'0') -1 ;
                    posY = str[0] - 'a';
                }
            else if (str[0] >= 'A' && str[0] <= 'A'+taillegrille && str[1] >= '0' && str[1] <= '9' && str[2] >= '0' && str[2] <= '9')
                {
                    posX = (str[1]-'0')*10 + (str[2]-'0') -1 ;
                    posY = str[0] - 'A';
                }
            else
                printf("ERREUR4\n");



            if (posX < 1 || posX > taillegrille)
                printf("ERREUR5\n");

            else
            {
                mot_correct = 1;
                recup_mot=1;
                *coordX = posX;
                *coordY = posY;
            }
        }
    }
    return 0;
}






