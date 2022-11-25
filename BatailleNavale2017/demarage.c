#include "BatailleNavale.h"

/**
  * Ce fichier sert à afficher l'ecran de demarage du jeu.
  * Il affiche d'abord le dessin, indique qu'on peut se deplacer avec les touches directionnelles,
  * et affiche une animations de chargement, inutile, mais qui laisse le temps à l'utilisateur de lire l'indication precedente.
  * Sinon, ce fichier sous programme n'a absolument aucune utilité. C'est une sorte d'introduction.
*/

/**
void animation_demarage(OPTS Options, int *taille_grille);
void Bateau_ascii(int X, int Y);
*/

/**
Essais de dessins

    Sur 2 lignes
        "BATAILLE"
        printf("\n______         _          _  _  _        \n| ___ \\       | |        (_)| || |       \n| |_/ /  __ _ | |_  __ _  _ | || |  ___  \n| ___ \\ / _` || __|/ _` || || || | / _ \\ \n| |_/ /| (_| || |_| (_| || || || ||  __/ \n\\____/  \\__,_| \\__|\\__,_||_||_||_| \\___| \n");
        "Navale"
        printf("  _   _                      _           \n | \\ | |                    | |          \n |  \\| |  __ _ __   __ __ _ | |  ___     \n | . ` | / _` |\\ \\ / // _` || | / _ \\    \n | |\\  || (_| | \\ V /| (_| || ||  __/    \n \\_| \\_/ \\__,_|  \\_/  \\__,_||_| \\___| \n");

    Sur une seule:
        "Bataille Navale"
        printf("\n______         _          _  _  _         _   _                      _       \n| ___ \\       | |        (_)| || |       | \\ | |                    | |      \n| |_/ /  __ _ | |_  __ _  _ | || |  ___  |  \\| |  __ _ __   __ __ _ | |  ___ \n| ___ \\ / _` || __|/ _` || || || | / _ \\ | . ` | / _` |\\ \\ / // _` || | / _ \\\n| |_/ /| (_| || |_| (_| || || || ||  __/ | |\\  || (_| | \\ V /| (_| || ||  __/\n\\____/  \\__,_| \\__|\\__,_||_||_||_| \\___| \\_| \\_/ \\__,_|  \\_/  \\__,_||_| \\___|\n");


    Il execute ensuite les commandes de demarage, tel que la taille de la console, ou encore celle de la grille.
*/

void animation_demarage(OPTS Options, int *taille_grille)
{
    int X = 0, Y = 30;
    //Animations
    int i, j;
    gotoligcol(X, Y);
    printf("______         _          _  _  _         _   _                      _       "); X++; gotoligcol(X, Y);
    printf("| ___ \\       | |        (_)| || |       | \\ | |                    | |      "); X++; gotoligcol(X, Y);
    printf("| |_/ /  __ _ | |_  __ _  _ | || |  ___  |  \\| |  __ _ __   __ __ _ | |  ___ "); X++; gotoligcol(X, Y);
    printf("| ___ \\ / _` || __|/ _` || || || | / _ \\ | . ` | / _` |\\ \\ / // _` || | / _ \\"); X++; gotoligcol(X, Y);
    printf("| |_/ /| (_| || |_| (_| || || || ||  __/ | |\\  || (_| | \\ V /| (_| || ||  __/"); X++; gotoligcol(X, Y);
    printf("\\____/  \\__,_| \\__|\\__,_||_||_||_| \\___| \\_| \\_/ \\__,_|  \\_/  \\__,_||_| \\___|");

    gotoligcol(15, 70);
    printf("-  Vous pouvez vous d%cplacer dans les menus %c l'aide des touches directionnelles de votre clavier.   -", 130, 133);
    gotoligcol(16, 70);
    printf("-                                 Appuyez echap pour passer ce menu.                                 -");
    gotoligcol(17, 70);
    printf("-          Appuyez sur n'importe quelle touche pour changer la taille de la grille de jeu.           -");



    Bateau_ascii(7,0);

    gotoligcol(20, 70);
    printf("Chargement");
    for (i=0; i<10; i++)
    {
        for (j=0; j<3; j++)
        {
            usleep(250000);
            printf(".");

            if ((kbhit()))
            {
                int ch;
                ch = getch();
                if (ch != 27) ///Si on appuit sur n'importe quelle touche sauf echap.
                {
                    *taille_grille = def_taille_grille();
                    i = 10; j=3;
                }
                i=10; j=3;
            }
        }

        usleep(250000);
        gotoligcol(20,80);
        printf("   ");
        gotoligcol(20,79);
        printf("t");

        if ((kbhit()))
        {
            int ch;
            ch = getch();
            if (ch != 27) ///Si on appuit sur n'importe quelle touche sauf echap.
            {
                *taille_grille = def_taille_grille();
                i = 10; j=3;
            }
            i=10; j=3;
        }
    }

}

void Bateau_ascii(int X, int Y)
{
gotoligcol(X, Y);
printf("--    .-""-.'')");
X++; gotoligcol(X, Y);
printf("   ) (     )");
X++; gotoligcol(X, Y);
printf("  (   )   (");
X++; gotoligcol(X, Y);
printf("     /     )");
X++; gotoligcol(X, Y);
printf("    (_    _)                     0_,-.__");
X++; gotoligcol(X, Y);
printf("      (_  )_                     |_.-._/");
X++; gotoligcol(X, Y);
printf("       (    )                    |_--..\\");
X++; gotoligcol(X, Y);
printf("        (__)                     |__--_/");
X++; gotoligcol(X, Y);
printf("     |''   ``\\                   |");
X++; gotoligcol(X, Y);
printf("     |   ECE  \\                  |      /b.");
X++; gotoligcol(X, Y);
printf("     |         \\  ,,,---===?A`\\  |  ,==y'");
X++; gotoligcol(X, Y);
printf("   ___,,,,,---==""\\        |M] \\ | ;|\\ |>");
X++; gotoligcol(X, Y);
printf("           _   _   \\   ___,|H,,---==""""bno,");
X++; gotoligcol(X, Y);
printf("    o  O  (_) (_)   \\ /          _     AWAW/");
X++; gotoligcol(X, Y);
printf("                     /         _(+)_  dMM/");
X++; gotoligcol(X, Y);
printf("      \\@_,,,,,,---=='   \\      \\\\| /  MW/");
X++; gotoligcol(X, Y);
printf("--'''''                         ===  d/");
X++; gotoligcol(X, Y);
printf("                                    //");
X++; gotoligcol(X, Y);
printf("                                    ,'__________________________");
X++; gotoligcol(X, Y);
printf("   \\    \\    \\     \\               ,/~~~~~~~~~~~~~~~~~~~~~~~~~~~");
X++; gotoligcol(X, Y);
printf("                         _____    ,'  ~~~   .-""-.~~~~~~  .-""-.");
X++; gotoligcol(X, Y);
printf("      .-""-.           ///==---   /`-._ ..-'      -.__..-'");
X++; gotoligcol(X, Y);
printf("            `-.__..-' =====\\\\\\\\\\\\ V/  .---\\.");
X++; gotoligcol(X, Y);
printf("                      ~~~~~~~~~~~~, _',--/_.\\  .-""-.");
X++; gotoligcol(X, Y);

}
