#include "BatailleNavale.h"

int menu_accueil()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 5;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(menu_prog, 0, "ACCUEIL.");
    transfert_tableau(menu_prog, 1, "Nouvelle Partie.");
    transfert_tableau(menu_prog, 2, "Charger Partie.");
    transfert_tableau(menu_prog, 3, "Aide.");
    transfert_tableau(menu_prog, 4, "Options.");
    transfert_tableau(menu_prog, 5, "Quitter le jeu.");
/**/
    choix_final = afficher_menu(menu_prog, nombre_lignes);

    return choix_final;
}
