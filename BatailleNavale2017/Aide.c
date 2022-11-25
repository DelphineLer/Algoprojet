#include "BatailleNavale.h"

/**
  * Fichier contenant quasi exculsivement des fonctions printf, qui permettent d'afficher les diff�rents r�gles du jeu, ainsi que les indications comme les codes couleurs.
  *
 */

/**
void regles_du_jeu();
void commandes();
void code_couleur(INFG InfoGlobales);
*/

void regles_du_jeu()
{
    ///Accents
    setlocale(LC_CTYPE,"");
    ///R�gles du jeu
    couleur(13, 0);
    printf("REGLES DU JEU :\n");
    couleur(15, 0);
    printf("Ce jeu de bataille navale est jouable � 1 (contre l'IA) ou 2 joueurs. Chaque joueur dispose d'une flotte de 10 navires, visibles dans la grille 1 (grille du bas).\n\n");
    printf("Pour remporter la victoire, il faut couler int�gralement la flotte adverse. Les joueurs jouent chacun leur tour. Une seule action peut �tre r�alis�e pendant ce tour.\n\n");
    printf("Avant de r�aliser une action, vous devez choisir le navire que vous souhaitez utiliser. Il existe 4 types de navire : le cuirass�, le croiseur, le destroyer et le sous-marin.\n\n");
    couleur(10, 0);
    printf("Le cuirass� :\n");
    couleur(15, 0);
    printf("Il est long de 7 cases et tire sur une zone de 9 cases (dispos�es en carre autour de la case vis�e).\n\n");
    couleur(10, 0);
    printf("Le croiseur :\n");
    couleur(15, 0);
    printf("Il est long de 5 cases et tire sur une zone de 4 cases (en carre, la case cibler occupant le coin sup�rieur gauche de ce carre).\n\n");
    couleur(10, 0);
    printf("Le destroyer :\n");
    couleur(15, 0);
    printf("Il est long de 3 cases et peut tirer sur une seule case. Il dispose d'une action sp�ciale : �clairer une zone composer de 16 cases (en carre, la case cibler occupant le coin sup�rieur gauche de ce carre), ce quid�voile les navires ennemis se trouvant dans cette zone. La zone n'est d�voil�e que pour votre prochain tour. Attention, chaque destroyer ne dispose que d'une seule fus�e �clairante et ne peut donc �clairer\nqu'une seule zone.\n\n");
    couleur(10, 0);
    printf("Le sous-marin :\n");
    couleur(15, 0);
    printf("Il est long de 1 case et peut tirer sur une seule case. Il ne peut �tre touche que part un autre sous-marin. Il est doncn�cessaire, pour remporter la partie, de garder ses sous-marins intacts.\n\n");
    printf("Les navires sont dispos�s al�atoirement en d�but de partie.\n\n");
    couleur(10, 0);
    printf("Actions :\n");
    couleur(15, 0);
    printf("Apres avoir s�lectionn� un navire, il y a 2 actions possibles : tirer ou d�placer un navire.\n\n");
    couleur(10, 0);
    printf("Tirer :\n");
    couleur(15, 0);
    printf("Vous devez s�lectionner la case ou vous souhaitez tirer � l'aide de 2 coordonn�es : le chiffre en abscisse puis la lettre en ordonn�e. Si vous avez s�lectionn� le destroyer, vous pouvez choisir entre tirer et\n�clairer une zone.\n\n");
    couleur(10, 0);
    printf("D�placer un navire :\n");
    couleur(15, 0);
    printf("Vous devez s�lectionner la direction dans laquelle vous souhaitez d�placer le navire. Un navire ne peut se d�placer que d'une seule case par tour. Les navires de plus de 1 case ne peuvent se d�placer qu'en avantou en arri�re, ils ne peuvent pas tourner. Les navires de 1 case peuvent aller dans n'importe quelle direction mais ne peuvent pas se d�placer en diagonale.\n\n");
    printf("Les navires en bon Etat apparaissent en vert sur la grille du bas. Les navires endommag�s apparaissent en jaune, leurs cases touch�es sont signal�es en rouge. Enfin, les navires coul�s apparaissent en gris, ils ne repr�sentent plus un obstacle et un autre navire peut �tre d�plac� sur leur position. En revanche, il est impossible de d�placer un navire sur ou sous un autre navire, ou de sortir un navire de la grille. Lesnavires touch�s ne peuvent plus se d�placer, ils sont immobilis�s.\n\n");
    printf("Sur la grille du haut apparaissent les tirs effectu�s ; les cases des navires ennemis touch�s apparaissent en rouge et les navires �clair�s apparaissent en bleu.\n\n");
    printf("Les actions de l�adversaire apparaissent sur la grille du bas.\n\n");
    printf("S�il y a 2 joueurs, comptez un d�lai de 5 secondes lors du changement d�interface.\n\n");
    couleur(9, 0);
    printf("Options suppl�mentaires :\n\n");
    couleur(15, 0);
    printf("Il est �galement possible de lancer des parties personnalis�es o� l�on peut d�finir le nombre de navires et la taille du plateau.\n\n");
    printf("-Nombre max de navires possibles : 3 cuirass�s, 5 croiseurs, 7 destroyers, 9 sous-marins.\n");
    printf("-Taille minimum d�une grille : 10 cases.\n");
    printf("-Taille maximum d�une grille : 26 cases.\n\n\n");

    couleur(15, 0);
}


void commandes()
{
    ///Accents
    setlocale(LC_CTYPE,"");
    ///Commandes
    couleur(13, 0);
    printf("Commande :\n\n");
    couleur(10, 0);
    printf("S�lectionner une case :\n");
    couleur(15, 0);
    printf("-Entrer la ligne des abscisses (chiffre), puis entrer la ligne des ordonn�es (lettre).\n\n");
    couleur(10, 0);
    printf("Naviguer dans le menu :\n");
    couleur(15, 0);
    printf("-Entrer le num�ro du choix / naviguer avec les fl�ches.\n");
    printf("-Touche � Echap � pour revenir au menu pr�c�dent.\n\n\n");
    couleur(15, 0);
}


void code_couleur(INFG InfoGlobales)
{
    ///Accents
    setlocale(LC_CTYPE,"");
    ///Code couleurs
    couleur(13, 0);
    printf("Code couleur :\n\n");
    couleur(10, 0);
    printf("Navires :\n");
    couleur(15, 0);
    printf("-Cuirass� : %c%c\n", InfoGlobales.Affichage.cuirasse, InfoGlobales.Affichage.cuirasse);
    printf("-Croiseur : %c%c\n", InfoGlobales.Affichage.croiseur, InfoGlobales.Affichage.croiseur);
    printf("-Destroyer : %c%c\n", InfoGlobales.Affichage.destroyer, InfoGlobales.Affichage.destroyer);
    printf("-Sous-marin : %c%c\n\n", InfoGlobales.Affichage.sousmarin, InfoGlobales.Affichage.sousmarin);
    couleur(10, 0);
    printf("Etat du navire :\n");
    couleur(15, 0);
    printf("-Navire en bon Etat :");
    couleur(10, 0);
    printf("case verte\n");
    couleur(15, 0);
    printf("-Navire endommag� :");
    couleur(14, 0);
    printf("case jaune\n");
    couleur(15, 0);
    printf("-Case touch�e :");
    couleur(12, 0);
    printf("case rouge\n");
    couleur(15, 0);
    printf("-Navire coul� :");
    couleur(8, 0);
    printf("case grise\n\n");
    couleur(10, 0);
    printf("Rep�rage de l�ennemi :\n");
    couleur(15, 0);
    printf("-Navire �clair� : case blanche\n");
    couleur(15, 0);
    printf("-Navire touch� :");
    couleur(12, 0);
    printf("case rouge\n");
    couleur(15, 0);
    printf("-Navire coul� :");
    couleur(8, 0);
    printf("case grise\n\n");
    couleur(15, 0);
}

