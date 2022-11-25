#include "BatailleNavale.h"

/**
  * Fichier contenant quasi exculsivement des fonctions printf, qui permettent d'afficher les différents règles du jeu, ainsi que les indications comme les codes couleurs.
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
    ///Règles du jeu
    couleur(13, 0);
    printf("REGLES DU JEU :\n");
    couleur(15, 0);
    printf("Ce jeu de bataille navale est jouable à 1 (contre l'IA) ou 2 joueurs. Chaque joueur dispose d'une flotte de 10 navires, visibles dans la grille 1 (grille du bas).\n\n");
    printf("Pour remporter la victoire, il faut couler intégralement la flotte adverse. Les joueurs jouent chacun leur tour. Une seule action peut être réalisée pendant ce tour.\n\n");
    printf("Avant de réaliser une action, vous devez choisir le navire que vous souhaitez utiliser. Il existe 4 types de navire : le cuirassé, le croiseur, le destroyer et le sous-marin.\n\n");
    couleur(10, 0);
    printf("Le cuirassé :\n");
    couleur(15, 0);
    printf("Il est long de 7 cases et tire sur une zone de 9 cases (disposées en carre autour de la case visée).\n\n");
    couleur(10, 0);
    printf("Le croiseur :\n");
    couleur(15, 0);
    printf("Il est long de 5 cases et tire sur une zone de 4 cases (en carre, la case cibler occupant le coin supérieur gauche de ce carre).\n\n");
    couleur(10, 0);
    printf("Le destroyer :\n");
    couleur(15, 0);
    printf("Il est long de 3 cases et peut tirer sur une seule case. Il dispose d'une action spéciale : éclairer une zone composer de 16 cases (en carre, la case cibler occupant le coin supérieur gauche de ce carre), ce quidévoile les navires ennemis se trouvant dans cette zone. La zone n'est dévoilée que pour votre prochain tour. Attention, chaque destroyer ne dispose que d'une seule fusée éclairante et ne peut donc éclairer\nqu'une seule zone.\n\n");
    couleur(10, 0);
    printf("Le sous-marin :\n");
    couleur(15, 0);
    printf("Il est long de 1 case et peut tirer sur une seule case. Il ne peut être touche que part un autre sous-marin. Il est doncnécessaire, pour remporter la partie, de garder ses sous-marins intacts.\n\n");
    printf("Les navires sont disposés aléatoirement en début de partie.\n\n");
    couleur(10, 0);
    printf("Actions :\n");
    couleur(15, 0);
    printf("Apres avoir sélectionné un navire, il y a 2 actions possibles : tirer ou déplacer un navire.\n\n");
    couleur(10, 0);
    printf("Tirer :\n");
    couleur(15, 0);
    printf("Vous devez sélectionner la case ou vous souhaitez tirer à l'aide de 2 coordonnées : le chiffre en abscisse puis la lettre en ordonnée. Si vous avez sélectionné le destroyer, vous pouvez choisir entre tirer et\néclairer une zone.\n\n");
    couleur(10, 0);
    printf("Déplacer un navire :\n");
    couleur(15, 0);
    printf("Vous devez sélectionner la direction dans laquelle vous souhaitez déplacer le navire. Un navire ne peut se déplacer que d'une seule case par tour. Les navires de plus de 1 case ne peuvent se déplacer qu'en avantou en arrière, ils ne peuvent pas tourner. Les navires de 1 case peuvent aller dans n'importe quelle direction mais ne peuvent pas se déplacer en diagonale.\n\n");
    printf("Les navires en bon Etat apparaissent en vert sur la grille du bas. Les navires endommagés apparaissent en jaune, leurs cases touchées sont signalées en rouge. Enfin, les navires coulés apparaissent en gris, ils ne représentent plus un obstacle et un autre navire peut être déplacé sur leur position. En revanche, il est impossible de déplacer un navire sur ou sous un autre navire, ou de sortir un navire de la grille. Lesnavires touchés ne peuvent plus se déplacer, ils sont immobilisés.\n\n");
    printf("Sur la grille du haut apparaissent les tirs effectués ; les cases des navires ennemis touchés apparaissent en rouge et les navires éclairés apparaissent en bleu.\n\n");
    printf("Les actions de l’adversaire apparaissent sur la grille du bas.\n\n");
    printf("S’il y a 2 joueurs, comptez un délai de 5 secondes lors du changement d’interface.\n\n");
    couleur(9, 0);
    printf("Options supplémentaires :\n\n");
    couleur(15, 0);
    printf("Il est également possible de lancer des parties personnalisées où l’on peut définir le nombre de navires et la taille du plateau.\n\n");
    printf("-Nombre max de navires possibles : 3 cuirassés, 5 croiseurs, 7 destroyers, 9 sous-marins.\n");
    printf("-Taille minimum d’une grille : 10 cases.\n");
    printf("-Taille maximum d’une grille : 26 cases.\n\n\n");

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
    printf("Sélectionner une case :\n");
    couleur(15, 0);
    printf("-Entrer la ligne des abscisses (chiffre), puis entrer la ligne des ordonnées (lettre).\n\n");
    couleur(10, 0);
    printf("Naviguer dans le menu :\n");
    couleur(15, 0);
    printf("-Entrer le numéro du choix / naviguer avec les flèches.\n");
    printf("-Touche « Echap » pour revenir au menu précédent.\n\n\n");
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
    printf("-Cuirassé : %c%c\n", InfoGlobales.Affichage.cuirasse, InfoGlobales.Affichage.cuirasse);
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
    printf("-Navire endommagé :");
    couleur(14, 0);
    printf("case jaune\n");
    couleur(15, 0);
    printf("-Case touchée :");
    couleur(12, 0);
    printf("case rouge\n");
    couleur(15, 0);
    printf("-Navire coulé :");
    couleur(8, 0);
    printf("case grise\n\n");
    couleur(10, 0);
    printf("Repérage de l’ennemi :\n");
    couleur(15, 0);
    printf("-Navire éclairé : case blanche\n");
    couleur(15, 0);
    printf("-Navire touché :");
    couleur(12, 0);
    printf("case rouge\n");
    couleur(15, 0);
    printf("-Navire coulé :");
    couleur(8, 0);
    printf("case grise\n\n");
    couleur(15, 0);
}

