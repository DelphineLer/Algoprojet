#include "BatailleNavale.h"

/**
  * Meme chose que pour la fonction "tour 1 joueur", exepté qu'on retire tout systeme d'affichage et que les selection utilisateur sont faite aléatoirement.
 */

/**
int tour_IA(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *fin_du_jeu_boucle, int joueurAvant[3], int joueurApres[3])
*/

int tour_IA(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *fin_du_jeu_boucle, int joueurAvant[3], int joueurApres[3])
{

    int type_bateau, numero_bateau;
    int coordX, coordY, coordXdestroyer, coordYdestroyer;
    int fin_du_tour = 1;



    IA_recup_position_bateau_allie(InfoGlobales, grille, &type_bateau, &numero_bateau, &coordX, &coordY);
    switch (rand()%4)
    {
        case 0: //Cuirasse
            vider_tableau_eclairage(InfoGlobales, grille);

            switch (rand()%2)
            {
                case 0: //attaquer

                    coordX=rand()%InfoGlobales.Options.taille_grille;
                    coordY=rand()%InfoGlobales.Options.taille_grille;

                    IA_attaque_cuirasse(InfoGlobales, grille, coordX, coordY);
                    //attaque_cuirasse(InfoGlobales, grille, coordX, coordY);

                    joueurAvant[0] = 11;
                    joueurAvant[1] = coordX;
                    joueurAvant[2] = coordY;

                    break;


                case 1: //deplacer
                    IA_deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 21;
                    break;

            }
            break;

        case 1: //Croiseur
            vider_tableau_eclairage(InfoGlobales, grille);

            switch (rand()%2)
            {
                case 0: //attaquer

                    coordX=rand()%InfoGlobales.Options.taille_grille;
                    coordY=rand()%InfoGlobales.Options.taille_grille;

                    IA_attaque_croiseur(InfoGlobales, grille, coordX, coordY);

                    joueurAvant[0] = 12;
                    joueurAvant[1] = coordX;
                    joueurAvant[2] = coordY;



                case 1: //deplacer
                    IA_deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 22;
                    break;
            }
            break;

        case 2: //Destroyer
            vider_tableau_eclairage(InfoGlobales, grille);
            //afficher_2_plateaux(InfoGlobales, grille, 3);
            afficher_2_plateaux(InfoGlobales, grille, 0);

            if (grille[InfoGlobales.tour_du_joueur][3][9][coordX][coordY][1] == 1)
            {
                switch (rand()%2)
                {
                    case 0: //eclairer
                        coordXdestroyer = coordX;
                        coordYdestroyer = coordY;

                        coordX=rand()%InfoGlobales.Options.taille_grille;
                        coordY=rand()%InfoGlobales.Options.taille_grille;

                        eclairage_destroyer(InfoGlobales, grille, coordX, coordY);
                        suppr_eclairage_destroyer(InfoGlobales, grille, coordXdestroyer, coordYdestroyer);

                        joueurAvant[0] = 131;
                        joueurAvant[1] = coordX;
                        joueurAvant[2] = coordY;

                        break;

                    case 1: //deplacer
                        IA_deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                        joueurAvant[0] = 23;


                        break;
                }
            }
            else
            {
                switch (rand()%2)
                {
                    case 0: //attaquer

                        coordX=rand()%InfoGlobales.Options.taille_grille;
                        coordY=rand()%InfoGlobales.Options.taille_grille;

                        IA_attaque_destroyer(InfoGlobales, grille, coordX, coordY);

                        joueurAvant[0] = 132;
                        joueurAvant[1] = coordX;
                        joueurAvant[2] = coordY;

                        break;

                    case 1: //deplacer
                        IA_deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                        joueurAvant[0] = 23;
                        break;
                }
            }

            break;

        case 3: //Sous Marin
            vider_tableau_eclairage(InfoGlobales, grille);

            switch (rand()%2)
            {
                case 0: //attaquer

                    coordX=rand()%InfoGlobales.Options.taille_grille;
                    coordY=rand()%InfoGlobales.Options.taille_grille;

                    IA_attaque_sousmarin(InfoGlobales, grille, coordX, coordY);
                    joueurAvant[0] = 14;
                    joueurAvant[1] = coordX;
                    joueurAvant[2] = coordY;
                    break;

                case 2: //deplacer
                    IA_deplacer_sousmarin(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 24;
                    break;

            }
            break;
    }

    return fin_du_tour;
}
