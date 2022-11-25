#include "BatailleNavale.h"

/**
  * Permet d'afficher le plateau de jeux aux coordonées indiquées en paramètres.
 */

/**
void afficher_plateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher, int coordx, int coordy);
void afficher_bateau_dans_grille(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int compteur_damier_horizontale,  int grille_a_afficher);
void afficher_2_plateaux(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher);
*/



void afficher_plateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher, int coordx, int coordy)
{
    /**
    Après analyse et tatonement de la fonction setlocal ici: https://www.tutorialspoint.com/c_standard_library/c_function_setlocale.htm
    J'en ai conclu que de ne pas envoyer un NULL permettait de remettre les caracteres par defauts.
    Cependant, celà me genere un warning, et je ne sais pas comment le regler, ne connaissant pas assez bien la fonction.
    */
    setlocale(NULL, " ");

    char bordure_vertical_vide= 186;///║
    char bordure_vertical_centre = 206; /// ╬
    char bordure_vertical_gauche = 204; ///╠
    char bordure_vertical_droite = 185; ///╣
    char bordure_vertical_bas = 202; ///╩
    char bordure_vertical_haut = 203; ///╦
    char bordure_horizontale= 205;///═
    char coin_bas_gauche = 200; ///╚
    char coin_bas_droit = 188; ///╝
    char coin_haut_gauche = 201; ///╔
    char coin_haut_droite = 187; ///╗


/**
    char bordure_vertical_vide= 179;///│
    char bordure_vertical_centre = 197; /// ┼
    char bordure_vertical_gauche = 195; ///├
    char bordure_vertical_droite = 180; ///┤
    char bordure_vertical_bas = 193; ///┴
    char bordure_vertical_haut = 194; ///┬
    char bordure_horizontale= 196;///─
    char coin_bas_gauche = 192; ///└
    char coin_bas_droit = 217; ///┘
    char coin_haut_gauche = 218; ///┌
    char coin_haut_droite = 191; ///┐
*/


    int compteur_damier_horizontale, compteur_damier_vertical;
    int cote = InfoGlobales.Options.taille_grille;

    gotoligcol(coordx, coordy);
    printf("   ");
    //On alligne la ligne des nombres avec le reste.

    for(compteur_damier_horizontale=1; compteur_damier_horizontale < cote+1; compteur_damier_horizontale++)
        {
            printf("%2d ", compteur_damier_horizontale);
        }
        //On Affiche tous les nombres, centres à 2 cases.

    coordx++;
    gotoligcol(coordx, coordy);
    printf("  %c",coin_haut_gauche);
    //On affiche le premier coins de la grille.


    for(compteur_damier_horizontale=0; compteur_damier_horizontale < cote-1; compteur_damier_horizontale++)
        printf("%c%c%c", bordure_horizontale, bordure_horizontale, bordure_vertical_haut);
    //On affiche la premiere ligne.

    printf("%c%c%c", bordure_horizontale, bordure_horizontale, coin_haut_droite);

    coordx++;
    gotoligcol(coordx, coordy);
    //On termine la première ligne avec un coin particulier.

    for (compteur_damier_vertical = 0; compteur_damier_vertical < cote-1; compteur_damier_vertical++)
    {
        printf("%2c%c", compteur_damier_vertical + 'a', bordure_vertical_vide); //"%c" ... +'a'

        for(compteur_damier_horizontale=0; compteur_damier_horizontale < cote; compteur_damier_horizontale++)
        {
            afficher_bateau_dans_grille(InfoGlobales, grille, compteur_damier_horizontale, compteur_damier_vertical, grille_a_afficher);
            printf("%c",bordure_vertical_vide);
        }

        coordx++;
        gotoligcol(coordx, coordy);
        printf("  %c", bordure_vertical_gauche);

        for(compteur_damier_horizontale=0; compteur_damier_horizontale < cote-1; compteur_damier_horizontale++)
            printf("%c%c%c", bordure_horizontale, bordure_horizontale, bordure_vertical_centre);
        printf("%c%c%c", bordure_horizontale, bordure_horizontale, bordure_vertical_droite);

        coordx++;
        gotoligcol(coordx, coordy);

    }


    printf(" %c%c", cote-1+'a', bordure_vertical_vide);
    for(compteur_damier_horizontale=0; compteur_damier_horizontale < cote; compteur_damier_horizontale++)
    {
        afficher_bateau_dans_grille(InfoGlobales, grille, compteur_damier_horizontale, compteur_damier_vertical, grille_a_afficher);
        printf("%c",bordure_vertical_vide);
    }

    coordx++;
    gotoligcol(coordx, coordy);
    printf("  %c", coin_bas_gauche);

    for(compteur_damier_horizontale=0; compteur_damier_horizontale < cote-1; compteur_damier_horizontale++)
        printf("%c%c%c", bordure_horizontale, bordure_horizontale, bordure_vertical_bas);
    printf("%c%c%c", bordure_horizontale, bordure_horizontale, coin_bas_droit);

    printf("\n");
}


void afficher_bateau_dans_grille(INFG InfoGlobales,
                                 char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3],
                                 int compteur_damier_horizontale,
                                 int compteur_damier_vertical,
                                 int grille_a_afficher)
{
    int tourdujoueur = num_joueur_adverse(InfoGlobales);

    if (grille_a_afficher == -1) //Afficher grille ennemis (bateaus qu'on a touches)
    {
        if ( grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 3) //Zone touchee (rouge)
        {
            couleur(15,12);
            printf("%c%c", grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0], grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0]);
        }

        else if (grille[InfoGlobales.tour_du_joueur][0][InfoGlobales.tour_du_joueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1) //Eclairage
        {
            couleur(0,15);
            printf("%c%c", grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0], grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0]);
        }

        else if ( grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 4) //BateauKO
        {
            couleur(15,8);
            printf("%c%c", grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0], grille[tourdujoueur][0][0][compteur_damier_horizontale][compteur_damier_vertical][0]);
        }


        else
        {
            couleur(7,0);
            printf("  ");
        }
        couleur(7,0);


    }
    else
    {
        if ( grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 1) // Bateau Complet (vert)
        {
            if (grille[tourdujoueur][0][tourdujoueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1)
                couleur(5,2);
            else
                couleur(15,2);
        }

        else if ( grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 2) // Bateau touche (Jaune)
        {
            if (grille[tourdujoueur][0][tourdujoueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1)
                couleur(5,14);
            else
                couleur(0,14);
        }

        if ( grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 3) //Zone touchee (rouge)
        {
            if (grille[tourdujoueur][0][tourdujoueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1)
                couleur(5,12);
            else
                couleur(15,12);
        }

        if ( grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 4) // Beateau coule (gris)
        {
            if (grille[tourdujoueur][0][tourdujoueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1)
                couleur(5,8);
            else
                couleur(15,8);
        }

        if ( grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][1] == 10) // Sous-Marin
        {
            if (grille[tourdujoueur][0][tourdujoueur+1][compteur_damier_horizontale][compteur_damier_vertical][0] == 1)
                couleur(5,3);
            else
                couleur(15,3);
        }

        printf("%c%c", grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][0], grille[InfoGlobales.tour_du_joueur][grille_a_afficher][0][compteur_damier_horizontale][compteur_damier_vertical][0]);
        couleur(7,0);
    }
}


void afficher_2_plateaux(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher)
{

    clearscreen();
    gotoligcol(0, (InfoGlobales.Options.taille_grille*3/2)-4);
    printf("Plateau adverse:");

    afficher_plateau(InfoGlobales, grille, -1, 3, 0);

    gotoligcol(0, (InfoGlobales.Options.taille_grille*3/2 ) + (InfoGlobales.Options.taille_grille*3 + 6) -3);
    printf("Plateau alies:");

    int i;
    for (i=1; i< InfoGlobales.Options.taille_grille*2+5 ; i++)
    {
        gotoligcol (i, InfoGlobales.Options.taille_grille*3+ 6);
        printf("%c", 179);

        gotoligcol (i, InfoGlobales.Options.taille_grille*6+ 13);
        printf("%c", 179);
    }


    afficher_plateau(InfoGlobales, grille, grille_a_afficher, 3, InfoGlobales.Options.taille_grille*3 + 8);
}

