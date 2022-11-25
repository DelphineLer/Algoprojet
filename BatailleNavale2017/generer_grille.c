#include "BatailleNavale.h"
/**
void generer_grille(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3]);
void creation_bateau(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int taille_bateau, int numero_bateau, int type_bateau, char lettre);
*/

void generer_grille(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3])
{
    int i, j;

    for(i=1; i<InfoGlobales.Options.nombre_croiseur+1; i++)
    {
        creation_bateau(InfoGlobales, grille, 5, i, 2, InfoGlobales.Affichage.croiseur);
    }

    for(i=1; i<InfoGlobales.Options.nombre_destroyer+1; i++)
    {
        creation_bateau(InfoGlobales, grille, 3, i, 3, InfoGlobales.Affichage.destroyer);
    }

    for(i=1; i<InfoGlobales.Options.nombre_sousmarin+1; i++)
    {
        creation_bateau(InfoGlobales, grille, 1, i, 4, InfoGlobales.Affichage.sousmarin);
    }

        for(i=1; i<InfoGlobales.Options.nombre_cuirasse+1; i++)
    {
        creation_bateau(InfoGlobales, grille, 7, i, 1, InfoGlobales.Affichage.cuirasse);
    }

    for (i=0; i<InfoGlobales.Options.taille_grille; i++)
    {
        for (j=0; j<InfoGlobales.Options.taille_grille; j++)
        {
            grille[InfoGlobales.tour_du_joueur][3][9][i][j][1] = grille[InfoGlobales.tour_du_joueur][3][0][i][j][1];
        }
    }
}

void creation_bateau(INFG InfoGlobales,
                     char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3],
                     int taille_bateau,
                     int numero_bateau,
                     int type_bateau,
                     char lettre)
{
    int fin=0;
    while (fin!=1)
    {
        fin = 1;
        int modulo = InfoGlobales.Options.taille_grille -(taille_bateau-1);

        int orientation=rand()%2;
        orientation = orientation%2;

        int X=rand();

        int Y=rand();

        int i;
        if (orientation==0)
        {
            Y=Y%modulo;
            X=X%InfoGlobales.Options.taille_grille;

            for (i=0; i<taille_bateau; i++)                                         ///Sert à verifier que le bateau ne
            {                                                                       ///se supperposera pas à un autre bateau.
                if (grille[InfoGlobales.tour_du_joueur][0][0][Y+i][X][1] != 0)      ///bateau.
                {                                                                   ///Dans le cas ou il se superposerait, on redemare
                    fin=0;                                                          ///la generation d'un nouveau bateau avec des nouvelles coordonnees
                }                                                                   ///jusqu'à ce qu'une coordonee marche.
            }

            if (fin==1)
            {
                for(i=0; i<taille_bateau; i++)
                {
                    grille[InfoGlobales.tour_du_joueur][type_bateau][0][Y+i][X][1] = 1;
                    grille[InfoGlobales.tour_du_joueur][type_bateau][0][Y+i][X][0] = lettre;

                    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][Y+i][X][0] = 1;
                    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][Y+i][X][1] = orientation+1;

                    grille[InfoGlobales.tour_du_joueur][0][0][Y+i][X][1] = 1;
                    grille[InfoGlobales.tour_du_joueur][0][0][Y+i][X][0] = lettre;
                }
            }
        }



        if (orientation==1)
        {
            Y=Y%InfoGlobales.Options.taille_grille;
            X=X%modulo;

            for (i=0; i<taille_bateau; i++)
            {
                if (grille[InfoGlobales.tour_du_joueur][0][0][Y][X+i][1] != 0)
                {
                    fin=0;
                }
            }

            if (fin==1)
            {
                for(i=0; i<taille_bateau; i++)
                {
                    grille[InfoGlobales.tour_du_joueur][type_bateau][0][Y][X+i][1] =1;
                    grille[InfoGlobales.tour_du_joueur][type_bateau][0][Y][X+i][0] = lettre;

                    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][Y][X+i][0] =1;
                    grille[InfoGlobales.tour_du_joueur][type_bateau][numero_bateau][Y][X+i][1] = orientation+1;

                    grille[InfoGlobales.tour_du_joueur][0][0][Y][X+i][1] =1;
                    grille[InfoGlobales.tour_du_joueur][0][0][Y][X+i][0] = lettre;
                }
            }
        }
    }
}









