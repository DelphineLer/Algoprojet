#include "BatailleNavale.h"

/**
  * Contient toutes les actions que peut effectuer un joueur pendant son tour.
  * Il fait appel aux fonctions d'actions.
 */

int tour_1_joueur(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *fin_du_jeu_boucle, int joueurAvant[3], int joueurApres[3])
{
    afficher_2_plateaux(InfoGlobales, grille, 0);
    int type_bateau, numero_bateau;
    int coordX, coordY, coordXdestroyer, coordYdestroyer;
    int retour, echap;
    int fin_du_tour = 1;

    if (joueurApres[0] != 0)
    {
        gotoligcol(15, InfoGlobales.Options.taille_grille*6 + 15);
        if (joueurApres[0] == 11)
        {
            printf("L'adversaire a attaque avec un cuirasse en %c%d.", joueurApres[2]+'A', joueurApres[1]+1);
        }
        else if (joueurApres[0] == 12)
        {
            printf("L'adversaire a attaque avec un croiseur en %c%d.", joueurApres[2]+'A', joueurApres[1]+1);
        }
        else if (joueurApres[0] == 131)
        {
            printf("L'adversaire a lance une fusee eclairante en %c%d.", joueurApres[2]+'A', joueurApres[1]+1);
        }
        else if (joueurApres[0] == 132)
        {
            printf("L'adversaire a attaque avec un destroyer en %c%d.", joueurApres[2]+'A', joueurApres[1]+1);
        }
        else if (joueurApres[0] == 14)
        {
            printf("L'adversaire a attaque avec un sous-marin en %c%d.", joueurApres[2]+'A', joueurApres[1]+1);
        }

        else if (joueurApres[0] > 20)
        {
            printf("L'adversaire a deplace un de ses bateaux.");
        }
    }

    gotoligcol(InfoGlobales.Options.taille_grille * 2 + 6, 0);
    printf("Saisissez une des coordonnees du bateau avec lequel vous souhaitez jouer.\n(Ne mettez pas d'espace. Par exemple, entrez B2.)\n");
    couleur(8,0);
    printf("Tapez un nombre negatif pour afficher le menu echap.\n\n");
    couleur(7,0);


    retour = recup_position_bateau_allie(InfoGlobales, grille, &type_bateau, &numero_bateau, &coordX, &coordY);

    switch (retour)
    {
        case -1:
            switch (menu_echap())
            {
                case -1: //Echap
                    fin_du_tour = 0;
                    break;
                case 1: //Retour au jeu
                    fin_du_tour = 0;
                    break;
                case 2: //Aide
                    //page_d_aide();
                    fin_du_tour = 0;
                    system("pause");
                    break;
                case 3: //Save
                    printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                    system("pause");
                    break;

                case 4: //Quitter
                    *fin_du_jeu_boucle = 1;
                    return 1;
                    break;
            }
            fin_du_tour = 0;
            break;

        case 1: //Cuirasse
            vider_tableau_eclairage(InfoGlobales, grille);
            //afficher_2_plateaux(InfoGlobales, grille, 1);
            afficher_2_plateaux(InfoGlobales, grille, 0);
            switch (menu_action_cuirasse(InfoGlobales))
            {
                case -1: //echap
                    fin_du_tour = 0;
                    break;

                case 1: //attaquer

                    printf("Saisissez une des coordonnees de l'endroit ou vous souhaitez attaquer.\n (Ne mettez pas d'espace. Par exemple, entrez B2)\n\n");
                    echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

                    if (echap==-1)
                    {
                        switch (menu_echap())
                        {
                            case -1: //Echap
                                fin_du_tour = 0;
                                break;
                            case 1: //Retour au jeu
                                fin_du_tour = 0;
                                break;
                            case 2: //Aide
                                //page_d_aide();
                                fin_du_tour = 0;
                                system("pause");
                                break;
                            case 3: //Save
                                printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                                system("pause");
                                break;

                            case 4: //Quitter
                                *fin_du_jeu_boucle = 1;
                                return 1;
                                break;
                        }
                    }

                    else
                    {
                        attaque_cuirasse(InfoGlobales, grille, coordX, coordY);
                        //attaque_cuirasse(InfoGlobales, grille, coordX, coordY);

                        joueurAvant[0] = 11;
                        joueurAvant[1] = coordX;
                        joueurAvant[2] = coordY;

                        break;
                    }


                case 2: //deplacer
                    deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 21;
                    break;

            }
            break;

        case 2: //Croiseur
            vider_tableau_eclairage(InfoGlobales, grille);
            //afficher_2_plateaux(InfoGlobales, grille, 2);
            afficher_2_plateaux(InfoGlobales, grille, 0);
            switch (menu_action_croiseur(InfoGlobales))
            {
                case -1: //echap
                    fin_du_tour = 0;
                    break;

                case 1: //attaquer
                    printf("Saisissez une des coordonnees de l'endroit ou vous souhaitez attaquer.\n (Ne mettez pas d'espace. Par exemple, entrez B2)\n\n");


                    echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

                    if (echap==-1)
                    {
                        switch (menu_echap())
                        {
                            case -1: //Echap
                                fin_du_tour = 0;
                                break;
                            case 1: //Retour au jeu
                                fin_du_tour = 0;
                                break;
                            case 2: //Aide
                                //page_d_aide();
                                fin_du_tour = 0;
                                system("pause");
                                break;
                            case 3: //Save
                                printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                                system("pause");
                                break;

                            case 4: //Quitter
                                *fin_du_jeu_boucle = 1;
                                return 1;
                                break;
                        }
                    }

                    else
                    {
                        attaque_croiseur(InfoGlobales, grille, coordX, coordY);

                        joueurAvant[0] = 12;
                        joueurAvant[1] = coordX;
                        joueurAvant[2] = coordY;

                        break;
                    }


                case 2: //deplacer
                    deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 22;
                    break;
            }
            break;

        case 3: //Destroyer
            vider_tableau_eclairage(InfoGlobales, grille);
            //afficher_2_plateaux(InfoGlobales, grille, 3);
            afficher_2_plateaux(InfoGlobales, grille, 0);

            if (grille[InfoGlobales.tour_du_joueur][3][9][coordX][coordY][1] == 1)
            {
                switch (menu_action_destroyer1(InfoGlobales))
                {
                    case -1: //echap
                        fin_du_tour = 0;
                        break;

                    case 1: //eclairer
                        coordXdestroyer = coordX;
                        coordYdestroyer = coordY;

                        printf("Saisissez une des coordonnees de la zone que vous souhaitez eclairer.\n (Ne mettez pas d'espace. Par exemple, entrez B2)\n\n");
                        echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

                        if (echap==-1)
                        {
                            switch (menu_echap())
                            {
                                case -1: //Echap
                                    fin_du_tour = 0;
                                    break;
                                case 1: //Retour au jeu
                                    fin_du_tour = 0;
                                    break;
                                case 2: //Aide
                                    //page_d_aide();
                                    fin_du_tour = 0;
                                    system("pause");
                                    break;
                                case 3: //Save
                                    printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                                    system("pause");
                                    break;

                                case 4: //Quitter
                                    *fin_du_jeu_boucle = 1;
                                    return 1;
                                    break;
                            }
                        }

                        else
                        {
                            eclairage_destroyer(InfoGlobales, grille, coordX, coordY);
                            suppr_eclairage_destroyer(InfoGlobales, grille, coordXdestroyer, coordYdestroyer);

                            joueurAvant[0] = 131;
                            joueurAvant[1] = coordX;
                            joueurAvant[2] = coordY;

                            break;
                        }

                        break;

                    case 2: //deplacer
                        deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                        joueurAvant[0] = 23;


                        break;
                }
            }
            else
            {
                switch (menu_action_destroyer2(InfoGlobales))
                {
                    case -1: //echap
                        fin_du_tour = 0;
                        break;

                    case 1: //attaquer
                        printf("Saisissez une des coordonnees de l'endroit ou vous souhaitez attaquer.\n (Ne mettez pas d'espace. Par exemple, entrez B2)\n\n");
                        echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

                        if (echap==-1)
                        {
                            switch (menu_echap())
                            {
                                case -1: //Echap
                                    fin_du_tour = 0;
                                    break;
                                case 1: //Retour au jeu
                                    fin_du_tour = 0;
                                    break;
                                case 2: //Aide
                                    //page_d_aide();
                                    fin_du_tour = 0;
                                    system("pause");
                                    break;
                                case 3: //Save
                                    printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                                    system("pause");
                                    break;

                                case 4: //Quitter
                                    *fin_du_jeu_boucle = 1;
                                    return 1;
                                    break;
                            }
                        }

                        else
                        {
                            attaque_destroyer(InfoGlobales, grille, coordX, coordY);

                            joueurAvant[0] = 132;
                            joueurAvant[1] = coordX;
                            joueurAvant[2] = coordY;
                            break;
                        }


                        break;

                    case 2: //deplacer
                        deplacer_bateau(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                        joueurAvant[0] = 23;
                        break;
                }
            }

            break;

        case 4: //Sous Marin
            vider_tableau_eclairage(InfoGlobales, grille);
            //afficher_2_plateaux(InfoGlobales, grille, 4);
            afficher_2_plateaux(InfoGlobales, grille, 0);
            switch (menu_action_sousmarin(InfoGlobales))
            {
                case -1: //echap
                    fin_du_tour = 0;
                    break;

                case 1: //attaquer

                    printf("Saisissez une des coordonnees de l'endroit ou vous souhaitez attaquer.\n (Ne mettez pas d'espace. Par exemple, entrez B2)\n\n");
                    echap = recuperer_coordonnes(InfoGlobales, grille, &coordX, &coordY);

                    if (echap==-1)
                    {
                        switch (menu_echap())
                        {
                            case -1: //Echap
                                fin_du_tour = 0;
                                break;
                            case 1: //Retour au jeu
                                fin_du_tour = 0;
                                break;
                            case 2: //Aide
                                //page_d_aide();
                                fin_du_tour = 0;
                                system("pause");
                                break;
                            case 3: //Save
                                printf("SAUVEGARDE IMPOSSIBLE! (pas encore code)\n");
                                system("pause");
                                break;

                            case 4: //Quitter
                                *fin_du_jeu_boucle = 1;
                                return 1;
                                break;
                        }
                    }

                    else
                    {
                        attaque_sousmarin(InfoGlobales, grille, coordX, coordY);
                        joueurAvant[0] = 14;
                        joueurAvant[1] = coordX;
                        joueurAvant[2] = coordY;
                        break;
                    }

                    break;

                case 2: //deplacer
                    deplacer_sousmarin(InfoGlobales, grille, coordX, coordY, &fin_du_tour);
                    joueurAvant[0] = 24;
                    break;

            }
            break;
    }

    return fin_du_tour;
}
