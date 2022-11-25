#include "BatailleNavale.h"

int main()
{
    srand(time(NULL));
    //setlocale(LC_CTYPE,"");
    taille_console();
    fullscreen();


    INFG InfoGlobales;

    InfoGlobales.Affichage.cuirasse = '*';
    InfoGlobales.Affichage.croiseur = 'c';
    InfoGlobales.Affichage.destroyer = 'd';
    InfoGlobales.Affichage.sousmarin = 's';


    InfoGlobales.Options.taille_grille = 15;
    InfoGlobales.Options.nombre_cuirasse = 1;
    InfoGlobales.Options.nombre_croiseur = 2;
    InfoGlobales.Options.nombre_destroyer = 3;
    InfoGlobales.Options.nombre_sousmarin = 4;


    InfoGlobales.tour_du_joueur = 0;
    clearscreen();
    animation_demarage(InfoGlobales.Options, &InfoGlobales.Options.taille_grille);

    char grille_matrice [2]     [6]     [10]            [InfoGlobales.Options.taille_grille] [InfoGlobales.Options.taille_grille] [3];
    //                  Joueur  Bateau  N° du bateau    Coord X                                Coord Y                              Etat bateau / orientation


    remplir_tableau_matrice (InfoGlobales, grille_matrice);

    clearscreen();


    int fin = 0, boucle = 0;
    char buffer;
    while (fin != 1)
    {
        fin = 1;
        couleur(7,0);
        switch (menu_accueil())
        {
            case -1: ///ECHAP
                clearscreen();
                printf("Fin du programme...");
                break;
            case 1: ///Commencer une partie
                switch (menu_nombre_utilisateurs())
                {
                    case -1:
                        fin=0;
                        break;

                    case 1:
                        generer_grille(InfoGlobales, grille_matrice);
                        InfoGlobales.tour_du_joueur = 1;
                        generer_grille(InfoGlobales, grille_matrice);
                        InfoGlobales.tour_du_joueur = 0;

                        UnJoueur(InfoGlobales, grille_matrice);
                        break;

                    case 2:
                        generer_grille(InfoGlobales, grille_matrice);
                        InfoGlobales.tour_du_joueur = 1;
                        generer_grille(InfoGlobales, grille_matrice);
                        InfoGlobales.tour_du_joueur = 0;

                        DeuxJoueurs(InfoGlobales, grille_matrice);
                        break;
                }
                break;

            case 2: ///Charger une partie
                printf("\nNON CODE!");
                break;

            case 3: ///Aide
                fin=0;
                switch (menu_afficher_aide())
                {
                    case -1:

                        break;

                    case 1:
                        clearscreen();
                        regles_du_jeu();
                        system("pause");
                        break;

                    case 2:
                        clearscreen();
                        commandes();
                        system("pause");
                        break;

                    case 3:
                        clearscreen();
                        code_couleur(InfoGlobales);
                        system("pause");
                        break;
                }
                break;


            case 4: ///Options
                fin = 0;
                boucle = 0;
                while(boucle !=2)
                {
                    switch(menu_options_bateaux())
                    {
                        case -1:
                            boucle = 2;
                            break;
                        case 1:
                            boucle = 0;
                            while (boucle != 1)
                            {
                                printf("Combien voulez vous de cuirasses?\n");
                                couleur(8,0);
                                printf("(Defaut = 1, min = 1, max = 3\n");
                                couleur(7,0);
                                scanf("%c", &buffer);
                                buffer = buffer - '0';

                                if (buffer >=1 && buffer <=3)
                                {
                                    boucle = 1;
                                    InfoGlobales.Options.nombre_cuirasse = buffer;
                                }
                                else
                                    printf("Erreur\n");
                            }
                            break;
                        case 2:
                            boucle = 0;
                            while (boucle != 1)
                            {
                                printf("Combien voulez vous de croiseurs?\n");
                                couleur(8,0);
                                printf("(Defaut = 2, min = 1, max = 5\n");
                                couleur(7,0);
                                scanf("%c", &buffer);
                                buffer = buffer - '0';

                                if (buffer >=1 && buffer <=5)
                                {
                                    boucle = 1;
                                    InfoGlobales.Options.nombre_croiseur = buffer;
                                }
                                else
                                    printf("Erreur!\n");
                            }
                            break;
                        case 3:
                            boucle = 0;
                            while (boucle != 1)
                            {
                                printf("Combien voulez vous de destroyers?\n");
                                couleur(8,0);
                                printf("(Defaut = 1, min = 1, max = 7\n");
                                couleur(7,0);
                                scanf("%c", &buffer);
                                buffer = buffer - '0';

                                if (buffer >=1 && buffer <=7)
                                {
                                    boucle = 1;
                                    InfoGlobales.Options.nombre_destroyer = buffer;
                                }
                                else
                                    printf("Erreur!\n");
                            }
                            break;
                        case 4:
                            boucle = 0;
                            while (boucle != 1)
                            {
                                printf("Combien voulez vous de sous-Marin?\n");
                                couleur(8,0);
                                printf("(Defaut = 1, min = 1, max = 9\n");
                                couleur(7,0);
                                scanf("%c", &buffer);
                                buffer = buffer - '0';

                                if (buffer >=1 && buffer <=9)
                                {
                                    boucle = 1;
                                    InfoGlobales.Options.nombre_sousmarin = buffer;
                                }
                                else
                                    printf("Erreur!\n");
                            }
                            break;
                        case 5:
                            boucle=2;
                            break;
                    }
                }
                break;

            case 5: ///Quitter
                clearscreen();
                printf("Fin du programme...");
                break;
        }
    }

/**/

    printf("\n");
    system("pause");
    return 0;
}
