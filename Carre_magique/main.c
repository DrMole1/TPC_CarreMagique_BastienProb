//impl�mentations des biblioth�ques et fichier annexes (macros)
#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "function.c"




//Fonction
//Impl�mentation
// =============================================================
// Description : M�thode pour faire appara�tre un carr� magique sur l'�cran
// Entr�es : /
// Sorties : Un tableau qui est le carr� magique
// Note :
// =============================================================
int main()  //programme principal MAIN
{
    //d�claration des variables locales au main
    int nCarre[COTE][COTE];
    int nCpt=1;
    tJeton Jeton;

    //proc�dure d'initialisation
    initialiser(nCarre, &Jeton);

    //boucle de traitement principal
    for (nCpt = 1 ; nCpt<=COTE*COTE ; nCpt++)
    {
        avancer_droite (&Jeton);
        avancer(&Jeton);
        if (rechercher_vide (Jeton, nCarre)==0)
        {
            avancer_gauche(&Jeton);
            avancer(&Jeton);
        }
        placer (Jeton, nCarre, nCpt);
    }

    /*nCarre[4][5]=16;*/
    //affichage du Carre � l'�cran
    afficher(nCarre);

    return 0;
}
