#include "BatailleNavale.h"

/**
  * Permet de coder les menus affichés avec la fonction "afficher_menu"
 */

/**
int menu_accueil();
int menu_echap();
int menu_options_bateaux();
int menu_afficher_aide();
int menu_options();
int menu_nombre_utilisateurs();
int menu_selection_bateau(INFG InfoGlobales);
int menu_action_cuirasse(INFG InfoGlobales);
int menu_action_croiseur(INFG InfoGlobales);
int menu_action_destroyer1(INFG InfoGlobales);
int menu_action_destroyer2(INFG InfoGlobales);
int menu_action_sousmarin(INFG InfoGlobales);
int menu_deplacement_horizontal(INFG InfoGlobales);
int menu_deplacement_vertical(INFG InfoGlobales);
int menu_deplacement_tout(INFG InfoGlobales);
*/

int menu_accueil()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 5;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "ACCUEIL.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Nouvelle Partie.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Charger Partie.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Aide.");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Options.");
    transfert_tableau(nombre_lignes, menu_prog, 5, "Quitter le jeu.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}

int menu_echap()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 4;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "PAUSE.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Retour au jeu.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Aide.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Sauvegarder.");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Quitter.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}

int menu_afficher_aide()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 3;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "AIDE.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Regle du jeu.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Commandes.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Code couleur.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}

int menu_options()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "OPTIONS.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Nombres de navires.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}

int menu_options_bateaux()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 5;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "NOMBRE DE BATEAU.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Cuirasse.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Croiseur.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Destroyer.");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Sous Marin.");
    transfert_tableau(nombre_lignes, menu_prog, 5, "Retour.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}


int menu_nombre_utilisateurs()
{
    clearscreen();

    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "VOUS SEREZ.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "1 joueur (vs IA).");
    transfert_tableau(nombre_lignes, menu_prog, 2, "2 joueurs.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, 0, 0);

    return choix_final;
}


int menu_selection_bateau(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 4;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "QUEL BATEAU VOULEZ VOUS JOUER?.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Cuirasse.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Croiseur.");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Destroyer.");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Sous-marin.");


    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_action_cuirasse(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "CUIRASSE:.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Attaquer.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Deplacer.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_action_croiseur(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "CROISEUR:.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Attaquer.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Deplacer.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_action_destroyer1(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "DESTROYER:.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Eclairer.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Deplacer.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}


int menu_action_destroyer2(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "DESTROYER:.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Attaquer.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Deplacer.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_action_sousmarin(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "SOUS-MARIN:.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Attaquer.");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Deplacer.");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_deplacement_horizontal(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "Vers ou voulez vous vous deplacer.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Est (Droite).");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Ouest (Gauche).");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_deplacement_vertical(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 2;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "Vers ou voulez vous vous deplacer.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Nord (Haut).");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Sud (Bas).");

    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}

int menu_deplacement_tout(INFG InfoGlobales)
{
    int choix_final;
    int nombre_lignes = 4;
    nombre_lignes = nombre_lignes+1;
    char menu_prog [nombre_lignes][50];
    transfert_tableau(nombre_lignes, menu_prog, 0, "Vers ou voulez vous vous deplacer.");
    transfert_tableau(nombre_lignes, menu_prog, 1, "Nord (Haut).");
    transfert_tableau(nombre_lignes, menu_prog, 2, "Sud (Bas).");
    transfert_tableau(nombre_lignes, menu_prog, 3, "Est (Droite).");
    transfert_tableau(nombre_lignes, menu_prog, 4, "Ouest (Gauche).");


    choix_final = afficher_menu(menu_prog, nombre_lignes, InfoGlobales.Options.taille_grille*2 + 7, 0);

    return choix_final;
}
