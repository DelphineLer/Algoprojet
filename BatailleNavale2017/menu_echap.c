#include "BatailleNavale.h"

int menu_echap()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 4;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(menu_prog, 0, "PAUSE.");
    transfert_tableau(menu_prog, 1, "Retour au jeu.");
    transfert_tableau(menu_prog, 2, "Aide.");
    transfert_tableau(menu_prog, 3, "Sauvegarder.");
    transfert_tableau(menu_prog, 4, "Quitter la partie.");

    choix_final = afficher_menu(menu_prog, nombre_lignes);

    return choix_final;
}
