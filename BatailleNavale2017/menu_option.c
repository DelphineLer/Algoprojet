#include "BatailleNavale.h"

int menu_options()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(menu_prog, 0, "OPTIONS.");
    transfert_tableau(menu_prog, 1, "Taille du plateau.");
    transfert_tableau(menu_prog, 2, "Nombres de navires.");

    choix_final = afficher_menu(menu_prog, nombre_lignes);

    return choix_final;
}
