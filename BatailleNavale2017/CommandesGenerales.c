#include "BatailleNavale.h"
/**
  * J'ai mit ici les proc�dures dont on peut se servir un peu partout dans le code, comme changer la couleurs, effacer la console, etc.
 */

/**
void clearscreen();
void gotoligcol( int lig, int col );
void couleur(int t,int f);
int taille_console();
int setConsoleScreenBufferInfo(COORD dwSize);
void fullscreen();
int recuperer_coordonnes(INFG InfoGlobales, char grille[2][6][10][InfoGlobales.Options.taille_grille][InfoGlobales.Options.taille_grille][3], int *coordX, int *coordY);
int num_joueur_adverse(INFG InfoGlobales);
void convertir_seconde(int secondes, int temps[3]);
*/

///Efface 'lintegralitee de la console (commande Batch)
void clearscreen()
{
    system("cls");
}


///Permet d'aller � une position precise de la console et de reecrire par dessus. Donnee dans l'enonce du projet.
void gotoligcol( int lig, int col )
{
     // ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


///Permet de changer la couleurs de la console localement, et non pas l'entieretee de la console comme le ferais les commandes windows classique.
///Trouvee ici: https://openclassrooms.com/forum/sujet/couleur-dans-la-console-en-c-63227

/**
0: noir             8: gris
1: bleu fonce       9: bleu
2: vert             10: vert fluo
3: bleu-gris        11: turquoise
4: marron           12: rouge
5: pourpre          13: rose fluo
6: kaki             14: jaune fluo
7: gris clair       15: blanc
*/
void couleur(int t,int f)
{

    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

/// Permet de regler la taille de la console, pour l'avoir de mani�re fixe (utile dans l'utilisation du gotoligcol).
/// Trouve sur https://www.developpez.net/forums/d1045378/c-cpp/c/debuter/dimensions-console-sous-windows/

int taille_console()
{
    COORD dwSize = {240,83} ;

    SetConsoleTitle("Mon Terminal") ;	// Reglage du titre
    if(setConsoleScreenBufferInfo(dwSize)) {	// Reglage des coordonnees
        printf("setConsoleScreenBufferInfo (%ld)\n", GetLastError());
        return EXIT_FAILURE ;
    }

    return EXIT_SUCCESS ;
}

/*!
 * \fn          int setConsoleScreenBufferInfo(COORD dwSize)
 * \brief       Modifie la taille de la console en cours.
 * \param[in]   dwSize  Specifie la nouvelle taille de la console.
 * \return      Si l'operation a reussi, retourne \c EXIT_SUCCESS,
 *              sinon \c EXIT_FAILURE.
 * \note        To get extended error information, call GetLastError.
 */
int setConsoleScreenBufferInfo(COORD dwSize)
{   HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD bakDwSize = dwSize ;
    SMALL_RECT srctWindow ;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo ;

    // Obtenir les informations de la console
    if(!GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return EXIT_FAILURE ;

    // Adapter le buffer de la console en fonction des tailles maximales
    dwSize.X = (dwSize.X>csbiInfo.srWindow.Right)?dwSize.X:csbiInfo.dwSize.X ;
    dwSize.Y = (dwSize.Y>csbiInfo.srWindow.Bottom)?dwSize.Y:csbiInfo.dwSize.Y ;
    if(!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE ;

    // Modifier la taille de la console
    dwSize = bakDwSize ;
    srctWindow = csbiInfo.srWindow ;
    srctWindow.Right = dwSize.X - 1 ;
    srctWindow.Bottom = dwSize.Y - 1 ;
    if(!SetConsoleWindowInfo(hConsoleOutput, TRUE, &srctWindow)) return EXIT_FAILURE ;

    // Adapter la taille du buffer de la console � sa taille (pas d'ascenseurs)
    dwSize = bakDwSize ;
    if(!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE ;

    return EXIT_SUCCESS ;
}


///Permet de mettre la console en plein ecran.
/// Inspire de https://www.fortisfio.com/simuler-le-clavier-et-la-souris-en-c/
/// et de https://www.codeproject.com/Articles/7305/Keyboard-Events-Simulation-using-keybd-event-funct

void fullscreen()
{
    HWND hFore = GetForegroundWindow();
    PostMessage(hFore,WM_KEYDOWN,VK_CONTROL,0);
    keybd_event(VK_LWIN, 0,0 ,0);
    keybd_event(VK_UP, 0,0 ,0);
    keybd_event(VK_UP, 0,KEYEVENTF_KEYUP ,0);
    keybd_event(VK_LWIN, 0,KEYEVENTF_KEYUP ,0);
}




int num_joueur_adverse(INFG InfoGlobales)
{
    int joueuradverse;
    if  (InfoGlobales.tour_du_joueur == 1)
        joueuradverse = 0;

    if  (InfoGlobales.tour_du_joueur == 0)
        joueuradverse = 1;

//joueuradverse = InfoGlobales.tour_du_joueur;
    return joueuradverse;
}

void convertir_seconde(int secondes, int temps[3])
{
    if (secondes == 0)
    {
        temps[0] = 99;
        temps[1] = 59;
        temps[2] = 59;
    }
    else
    {
        int heure = 0, minute = 0, sec = 0;
        while (secondes >= 3600)
        {
            secondes = secondes - 3600;
            heure++;
        }

        while (secondes >= 60)
        {
            secondes = secondes - 60;
            minute++;
        }

        sec = secondes;

        temps[0] = heure;
        temps[1] = minute;
        temps[2] = sec;
    }
}

