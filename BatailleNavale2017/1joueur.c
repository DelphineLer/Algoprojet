#include "BatailleNavale.h"

/**
  * Meme chose que pour le passage entre 2 joueurs, exepté qu'ici, on lance le programme d'IA à la place du second joueur.
/**
void UnJoueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
*/

void UnJoueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3])
{
    int fin_du_jeu = 0, fin_tour_joueur;
    int joueur1[3], joueur2[3];
    int temps[2], temps1, temps2;
    temps[0] = 0;
    temps[1] = 0;

    while (fin_du_jeu == 0)
    {

        InfoGlobales.tour_du_joueur = 0;
        fin_tour_joueur = 0;
        temps1 = time(NULL);
        while (fin_tour_joueur == 0)
        {
            fin_tour_joueur = tour_1_joueur(InfoGlobales, grille, &fin_du_jeu, joueur1, joueur2);
        }

        temps2 = time(NULL);
        temps[0] = temps[0] + (temps2-temps1);

        fin_du_jeu = detecter_fin(InfoGlobales, grille);

        if (fin_du_jeu == 1)
            break;




        InfoGlobales.tour_du_joueur = 1;
        fin_tour_joueur = 0;
        while (fin_tour_joueur == 0)
        {
            fin_tour_joueur = tour_IA(InfoGlobales, grille, &fin_du_jeu, joueur2, joueur1);
        }
        fin_du_jeu = detecter_fin(InfoGlobales, grille);

        if (fin_du_jeu == 1)
            break;

        clearscreen();

    }


    clearscreen();
    printf("  ______ _____ _   _ \n |  ____|_   _| \\ | |\n | |__    | | |  \\| |\n |  __|   | | | . ` |\n | |     _| |_| |\\  |\n |_|    |_____|_| \\_|\n");
    printf("\n\n");
    if (InfoGlobales.tour_du_joueur == 0)
    {
        int temps_joueur[3];
        printf("C'est le joueur qui gagne!\n");

        convertir_seconde(temps[0], temps_joueur);

        printf("Il a mit %d heure(s) %d minute(s) et %d seconde(s) a remporter le match.",temps_joueur[0], temps_joueur[1], temps_joueur[2]);

        top_temps(temps[0]);
    }

    else if (InfoGlobales.tour_du_joueur == 1)
    {
        printf("C'est l'IA qui gagne!\n");
    }
}
