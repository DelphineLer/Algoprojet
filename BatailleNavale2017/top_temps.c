#include "BatailleNavale.h"

/**
  * Dans ce fichier, on calcul et enregistre les 10 meilleurs temps qui ont été joués.
 */

void top_temps(int temps_gagnant)
{
    int temps[11];
    FILE* top_temps;
    int i;
    int temps_variable[3];

    for (i=0; i<11; i++)
    {
        temps[i] = 0;
    }

    temps[10] = temps_gagnant;


    top_temps = fopen("top_temps.txt", "r");

    if(top_temps == NULL)
    {

        printf("ERREUR: On ne peut pas stocker ce temps.");
        top_temps = fopen("top_temps.txt", "w");

        if (top_temps == NULL)
            printf("ON NE PEUT PAS ENREGISTRER DE SCORES.");

        else
        {
            fprintf(top_temps, "%d\n", temps_gagnant);
            for (i=0; i<9; i++)
                fprintf(top_temps, "%d\n", temps[i]);
        }
    }

    else
    {
        for (i=0; i<10; i++)
        {
            fscanf(top_temps, "%d\n", &temps[i]);
        }

        printf("\n\n\n ---   TOP DES TEMPS JOUES!  ---\n");
        for (i=0; i<10; i++)
        {
            convertir_seconde(temps[i], temps_variable);
            printf("\n%2d - %dh %dmin %ds", i+1, temps_variable[0], temps_variable[1], temps_variable[2]);
        }
        convertir_seconde(temps_gagnant, temps_variable);
        printf("\n\n Votre temps: %dh %dmin %ds\n", temps_variable[0], temps_variable[1], temps_variable[2]);

    }
    fclose(top_temps);



    top_temps = fopen("top_temps.txt", "w");

        if (top_temps == NULL)
            printf("ON NE PEUT PAS ENREGISTRER DE SCORES.");

        else
        {
            i=0;
            int fin = 0;
            int buffer;
            while (fin != 1)
            {

                for (i=10; i>=0; i--)
                {
                    if (temps_gagnant < temps[i])
                    {
                        buffer = temps[i];
                        temps[i] = temps[i+1];
                        temps[i+1] = buffer;
                    }
                }

                int nombre_ok=0;

                for (i=0; i<11; i++)
                {
                    if (temps[i] <= temps[i+1])
                    {
                        nombre_ok++;
                    }
                }
                if (nombre_ok >= 9)
                    fin = 1;
            }
        }

        for (i= 0; i<11; i++)
        {
            fprintf(top_temps, "%d\n", temps[i]);
        }

        fclose(top_temps);
}



