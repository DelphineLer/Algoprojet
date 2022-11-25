#ifndef BATAILLENAVALE_H_INCLUDED
#define BATAILLENAVALE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <conio.h> // detecter pression touches
#include <unistd.h> // usleep commande
#include <windows.h> // couleur
#include <time.h> //generer nombre aleatoire

#define NOMBRE_MAX_CUIRASSE 3
#define NOMBRE_MAX_CROISEUR 5
#define NOMBRE_MAX_DESTROYER 7
#define NOMBRE_MAX_SOUSMARIN 9

///------STRUCTURES:

//Structure option: Permet de modifier le nombres de bateau
typedef struct Options OPTS;
struct Options
{
    int taille_grille;
    int nombre_croiseur;
    int nombre_cuirasse;
    int nombre_destroyer;
    int nombre_sousmarin;
};


typedef struct Affichage AFFICHAGE;
struct Affichage
{
    char cuirasse;
    char croiseur;
    char destroyer;
    char sousmarin;
};


//Structure global: Permet de passer des informations qui ne change pas dans tous les programmes, comme les options, le tour du joueur....
typedef struct InfoGlobales INFG;
struct InfoGlobales
{
    AFFICHAGE Affichage;
    OPTS Options;
    int tour_du_joueur;

};





///-----SOUS PROGRAMMES

void UnJoueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);

void IA_attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void IA_attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);

int IA_deplacer_bateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);
int IA_deplacer_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);

int IA_recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY);

int tour_IA(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *fin_du_jeu_boucle, int joueurAvant[3], int joueurApres[3]);



int tour_1_joueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *fin_du_jeu_boucle, int joueurAvant[3], int joueurApres[3]);

void remplir_tableau_text(char tab[101]);
void remplir_tableau_matrice(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
void vider_tableau_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);

int def_taille_grille();

void generer_grille(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
void creation_bateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int taille_bateau, int numero_bateau, int type_bateau, char lettre);

void animation_demarage(OPTS Options, int *taille_grille);
void Bateau_ascii(int X, int Y);

void clearscreen();
void gotoligcol( int lig, int col );
void couleur(int t,int f);
int taille_console();
int setConsoleScreenBufferInfo(COORD dwSize);
void fullscreen();
int num_joueur_adverse(INFG InfoGlobales);
void convertir_seconde(int secondes, int temps[3]);

void afficher_plateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher, int coordx, int coordy);
void afficher_bateau_dans_grille(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int compteur_damier_horizontale, int compteur_damier_vertical,  int grille_a_afficher);
void afficher_2_plateaux(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int grille_a_afficher);

void DeuxJoueurs(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);

//void UnJoueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);

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

void transfert_tableau(int nombre_de_lignes, char choix[nombre_de_lignes][50], int i, char choixvariable[]);
void afficher_texte(char tab[][50], int selection_choix, int nombre_lignes);
int afficher_menu(char tab_menu[][50], int nombre_lignes, int coordx, int coordy);

int recup_position_bateau_allie(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *type_bateau, int *numero_bateau, int *posX, int *posY);
void suppr_destroyer_eclairage(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
int recuperer_coordonnes(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *coordX, int *coordY);

void eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void suppr_eclairage_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);


int deplacer_bateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);
int deplacer_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY, int *fin_du_tour);

int attaque_1_case(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_cuirasse(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_croiseur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_destroyer(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaque_sousmarin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);
void attaquer_grille_entiere(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int coordX, int coordY);

void regles_du_jeu();
void commandes();
void code_couleur(INFG InfoGlobales);

int detecter_fin(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);

void top_temps(int temps_gagnant);



#endif // BATAILLENAVALE_H_INCLUDED
