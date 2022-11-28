//
// Created by Nils on 28/11/2022.
//

#ifndef BAT2022_BAT2022_H
#define BAT2022_BAT2022_H

void grille(int tab[15][15])
{
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15");
    printf("\n");

    for (char j='A';j<'K';j++)
    {
        printf(" %c",j);
        printf(" X  X  X  X  X  X  X  X  X  X  X  X  X  X  X");
        printf("\n" );
    }
}

int menu()
{
    int choix=0;
    while(choix<1 || choix>6)
    {
        printf("Que voulez-vous faire: \n");
        printf("1 :Jouer\n");
        printf("2 :Charger\n");
        printf("3 :Aide\n");
        printf("4 :Quitter\n");
        printf("5 :Sauvegarder\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    }
    return choix;
}

int SaisirL()//chosir la ligne
{
    char j;
    do
    {
        printf("Choissisez la ligne: ");
        scanf("%c",&j);
    }while(j<0 ||j>15);
        return j;

}

int SaisirC()//chosir la colonne
{
    int i;
    do
    {
        printf("Choissisez la colone: ");
        scanf("%d",&i);
        printf("\n");
    }while(i<0 ||i>15);
    return i;
}

int SaisirOrien()//choisir l'orietation
{
    int k;
    do
    {
       printf("Choissisez une orientation: \n 0 si vous voulez le placer horizontalement et 1 si vous voulez le placer verticalement");
       scanf("%d",&k);
       printf("\n");
    }while(k>1 ||k<0);
    return k;
}


void placementbateau()
{
    SaisirC();
    SaisirL();
    SaisirOrien();

}
void Charger()
{

}

void Aide()
{

}

void Quitter()
{

}

void Sauvegarder()
{

}
#endif //BAT2022_BAT2022_H
