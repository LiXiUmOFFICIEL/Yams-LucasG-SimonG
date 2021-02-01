#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define  _CRT_SECURE_NO_WARNINGS


/* ----------------------------------------------------------------------------------------------------------------

███████╗████████╗██████╗ ██╗   ██╗ ██████╗████████╗
██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝
███████╗   ██║   ██████╔╝██║   ██║██║        ██║
╚════██║   ██║   ██╔══██╗██║   ██║██║        ██║
███████║   ██║   ██║  ██║╚██████╔╝╚██████╗   ██║
╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝

----------------------------------------------------------------------------------------------------------------*/
typedef struct Joueur Joueur;

struct Joueur  {
   int id;
   char nom[10];
};

struct Des {
    int id;
    int val;
    int gard;
};

typedef struct Des Des;

struct Fiche {
    int as;
    int deux;
    int trois;
    int quatre;
    int cinq;
    int six;
    int totalColonne;
    int aBonus;
    int totalPart1;
    int brelan;
    int petiteSuite;
    int grdSuite;
    int full;
    int yam;
    int totalPart2;
    int totalGen;
};

typedef struct Fiche Fiche;

/*----------------------------------------------------------------------------------------------------------------

██╗   ██╗ █████╗ ██████╗ ██╗ █████╗ ██████╗ ██╗     ███████╗███████╗
██║   ██║██╔══██╗██╔══██╗██║██╔══██╗██╔══██╗██║     ██╔════╝██╔════╝
██║   ██║███████║██████╔╝██║███████║██████╔╝██║     █████╗  ███████╗
╚██╗ ██╔╝██╔══██║██╔══██╗██║██╔══██║██╔══██╗██║     ██╔══╝  ╚════██║
 ╚████╔╝ ██║  ██║██║  ██║██║██║  ██║██████╔╝███████╗███████╗███████║
  ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚══════╝╚══════╝

---------------------------------------------------------------------------------------------------------------- */
Joueur Joueur1;
Joueur Joueur2;

Fiche ficheJ1;
Fiche ficheJ2;

Des des1;
Des des2;
Des des3;
Des des4;
Des des5;

/*----------------------------------------------------------------------------------------------------------------

███████╗ ██████╗ ███╗   ██╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗███████╗
██╔════╝██╔═══██╗████╗  ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝
█████╗  ██║   ██║██╔██╗ ██║██║        ██║   ██║██║   ██║██╔██╗ ██║███████╗
██╔══╝  ██║   ██║██║╚██╗██║██║        ██║   ██║██║   ██║██║╚██╗██║╚════██║
██║     ╚██████╔╝██║ ╚████║╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║███████║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝

---------------------------------------------------------------------------------------------------------------- */
char choisirNom(nbrJoueur, choixMode)
{

    char nom[10];
    printf("\nQuel est votre nom Joueur %d ? (10 caractères max)\n", nbrJoueur);
    scanf("%s", nom);

    if (nbrJoueur == 1){
        strcpy(Joueur1.nom, nom);
        printf("Joueur 1, votre nom est %s\n", Joueur1.nom);
    }

    if (nbrJoueur == 2 && choixMode == 2){
        strcpy(Joueur2.nom, nom);
        printf("Joueur 2, votre nom est %s\n", Joueur2.nom);
    }
    if (choixMode == 1) {
        strcpy(Joueur2.nom, "BOT");
        printf("Vous jouez contre %s\n", Joueur2.nom);
    }

    return 0;
}

int veutRelancer(/*Des leDes1, Des leDes2, Des leDes3, Des leDes4, Des leDes5*/){
    int result;
    int veutRejouer;
    printf("\nJoueur 1, voulez-vous garder le dé 1 qui vaut: %d ?\n 1: Oui\n 0: Non\n", des1.val);
    scanf("%d", &result);
    des1.gard = result;

    printf("\nJoueur 1, voulez-vous garder le dé 2 qui vaut: %d ?\n 1: Oui\n 0: Non\n", des2.val);
    scanf("%d", &result);
    des2.gard = result;

    printf("\nJoueur 1, voulez-vous garder le dé 3 qui vaut: %d ?\n 1: Oui\n 0: Non\n", des3.val);
    scanf("%d", &result);
    des3.gard = result;

    printf("\nJoueur 1, voulez-vous garder le dé 4 qui vaut: %d ?\n 1: Oui\n 0: Non\n", des4.val);
    scanf("%d", &result);
    des4.gard = result;

    printf("\nJoueur 1, voulez-vous garder le dé 5 qui vaut: %d?\n 1: Oui\n 0: Non\n", des5.val);
    scanf("%d", &result);
    des5.gard = result;

    if (des1.gard == 1 && des2.gard == 1 && des3.gard == 1 && des4.gard == 1 && des5.gard == 1) {
        veutRejouer = 0;
    }
    else {
        veutRejouer = 1;
    }
    return veutRejouer;
}

void afficheDes(Des leDes1, Des leDes2, Des leDes3, Des leDes4, Des leDes5){
    printf("DE%d = %d\n", leDes1.id, leDes1.val);
    printf("DE%d = %d\n", leDes2.id, leDes2.val);
    printf("DE%d = %d\n", leDes3.id, leDes3.val);
    printf("DE%d = %d\n", leDes4.id, leDes4.val);
    printf("DE%d = %d\n", leDes5.id, leDes5.val);
}

void marquePoint(){
    printf("\n\nChoisissez où vous souhaitez marquer votre score :"
           "\n 1: AS"
           "\n 2: DEUX"
           "\n 3: TROIS"
           "\n 4: QUATRE"
           "\n 5: CINQ"
           "\n 6: SIX"
           "\n 7: BRELAN"
           "\n 8: PETITE SUITE"
           "\n 9: GRANDE SUITE"
           "\n 10: FULL"
           "\n 11: CARRÉ"
           "\n 12: YAM\n\n");
}

int lanceDe(Des leDe){

    const int MAX = 6, MIN = 1;
    if (leDe.gard != 1) {
        int num = (rand() % (MAX - MIN + 1)) + MIN;
        leDe.val = num;
    }

    return leDe.val;

}

int tourJ1(numeroTour){

printf("JOUEUR 1 - TOUR %d\n", numeroTour);

int numeroLance;

    int nbrDesRelance;
    printf("Voici le résultat de votre 1er lancé\n\n");
    des1.val = lanceDe(des1);
    des2.val = lanceDe(des2);
    des3.val = lanceDe(des3);
    des4.val = lanceDe(des4);
    des5.val = lanceDe(des5);
    afficheDes(des1, des2, des3, des4, des5);
    int resultVeutRelancer = veutRelancer();

    if (resultVeutRelancer == 0) {
    marquePoint();
    }
    else
        {
        printf("\nRELANCE DES DÉS QUE VOUS AVEZ GARDÉ EN COURS...\n");
        printf("Voici le résultat de votre 2ème lancé\n\n");
        if (des1.gard == 0){
            des1.val = lanceDe(des1);
        }
        if (des2.gard == 0){
            des2.val = lanceDe(des2);
        }
        if (des3.gard == 0){
            des3.val = lanceDe(des3);
        }
        if (des4.gard == 0){
            des4.val = lanceDe(des4);
        }
        if (des5.gard == 0){
            des5.val = lanceDe(des5);
        }
        afficheDes(des1, des2, des3, des4, des5);
    }

    resultVeutRelancer = veutRelancer();
    if (resultVeutRelancer == 0) {
        marquePoint();
    }
    else {
        printf("\nRELANCE DES DÉS QUE VOUS AVEZ GARDÉ EN COURS...\n");
        printf("Voici le résultat de votre 3ème lancé\n\n");
        if (des1.gard == 0) {
            des1.val = lanceDe(des1);
        }
        if (des2.gard == 0) {
            des2.val = lanceDe(des2);
        }
        if (des3.gard == 0) {
            des3.val = lanceDe(des3);
        }
        if (des4.gard == 0) {
            des4.val = lanceDe(des4);
        }
        if (des5.gard == 0) {
            des5.val = lanceDe(des5);
        }
        afficheDes(des1, des2, des3, des4, des5);
    }

    resultVeutRelancer = veutRelancer();
    if (resultVeutRelancer == 0) {
        marquePoint();
    }
    else {
        printf("\nRELANCE DES DÉS QUE VOUS AVEZ GARDÉ EN COURS...\n");
        printf("Voici le résultat de votre 3ème lancé\n\n");
        if (des1.gard == 0) {
            des1.val = lanceDe(des1);
        }
        if (des2.gard == 0) {
            des2.val = lanceDe(des2);
        }
        if (des3.gard == 0) {
            des3.val = lanceDe(des3);
        }
        if (des4.gard == 0) {
            des4.val = lanceDe(des4);
        }
        if (des5.gard == 0) {
            des5.val = lanceDe(des5);
        }
        afficheDes(des1, des2, des3, des4, des5);
        marquePoint();
    }

return  0;
}

/*----------------------------------------------------------------------------------------------------------------


███╗   ███╗ █████╗ ██╗███╗   ██╗
████╗ ████║██╔══██╗██║████╗  ██║
██╔████╔██║███████║██║██╔██╗ ██║
██║╚██╔╝██║██╔══██║██║██║╚██╗██║
██║ ╚═╝ ██║██║  ██║██║██║ ╚████║
╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝

---------------------------------------------------------------------------------------------------------------- */

int main(void){

    srand(time(NULL));

/*--------------------------------
MESSAGE DE BIENVENUE
 ---------------------------------- */
printf("\nBienvenue dans le jeu du Yams\n\n Choisissez un modde de jeu :\n 1: 1 joueur\n 2: 2 joueurs\n");
int choixMode = 0;
scanf("%d", &choixMode);
printf("Vous avez choisi le mode %d\n", choixMode);

/*--------------------------------
 INITIALISATION DES VARIABLES
---------------------------------- */

/* JOUEUR 1 */

Joueur1.id = 1;
choisirNom(1, choixMode);
/* JOUEUR 2 */

Joueur2.id = 2;
if (choixMode == 2) {
    choisirNom(2, choixMode);
}

/* RECAP JOUEURS */

printf("%s et %s, c'est parti !\n\n", Joueur1.nom, Joueur2.nom);

/* FicheJ1 */

ficheJ1.as = -1;
ficheJ1.deux = -1;
ficheJ1.trois = -1;
ficheJ1.quatre = -1;
ficheJ1.cinq = -1;
ficheJ1.six = -1;
ficheJ1.totalColonne = 0;
ficheJ1.aBonus = 0;
ficheJ1.totalPart1 = 0;
ficheJ1.brelan = -1;
ficheJ1.petiteSuite = -1;
ficheJ1.grdSuite = -1;
ficheJ1.full = -1;
ficheJ1.yam = -1;
ficheJ1.totalPart2 = 0;
ficheJ1.totalGen = 0;

/* FicheJ2 */

ficheJ2.as = -1;
ficheJ2.deux = -1;
ficheJ2.trois = -1;
ficheJ2.quatre = -1;
ficheJ2.cinq = -1;
ficheJ2.six = -1;
ficheJ2.totalColonne = 0;
ficheJ2.aBonus = 0;
ficheJ2.totalPart1 = 0;
ficheJ2.brelan = -1;
ficheJ2.petiteSuite = -1;
ficheJ2.grdSuite = -1;
ficheJ2.full = -1;
ficheJ2.yam = -1;
ficheJ2.totalPart2 = 0;
ficheJ2.totalGen = 0;

/* Dés */

des1.val = 0;
des2.val = 0;
des3.val = 0;
des4.val = 0;
des5.val = 0;

des1.id = 1;
des2.id = 2;
des3.id = 3;
des4.id = 4;
des5.id = 5;

des1.gard = 0;
des2.gard = 0;
des3.gard = 0;
des4.gard = 0;
des5.gard = 0;

/* DEBUT PARTIE */

    for (int numeroTour = 1; numeroTour <= 1/*12*/; numeroTour++){
        tourJ1(numeroTour);
    }


}