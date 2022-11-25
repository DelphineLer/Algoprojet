#include "BatailleNavale.h"

int menu_nombre_utilisateurs()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(menu_prog, 0, "VOUS SEREZ.");
    transfert_tableau(menu_prog, 1, "1 joueur (vs IA).");
    transfert_tableau(menu_prog, 2, "2 joueurs.");

    choix_final = afficher_menu(VariableGlobales, menu_prog, nombre_lignes);

    return choix_final;
}
