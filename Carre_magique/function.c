#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour initialiser le tableau et le jeton
// Entr�es : Le Tableau du carr� et le jeton
// Sorties : Le Tableau du carr� et le jeton tous deux initialis�s
// Note : Pas de pointeur pour un tableau !
// =============================================================

void initialiser(int pnCarre[COTE][COTE], tJeton *pJeton)
{
    //d�claration des variables locales � la m�thode
    int nCpt=0, nCpt2=0;

    //boucles imbriqu�es de traitement pour assigner � chaque cellule la valeur 0
    for (nCpt=MIN ; nCpt <= COTE ; nCpt++)
    {
        for (nCpt2=1 ; nCpt2 <= COTE ; nCpt2++)
        {
            pnCarre[nCpt][nCpt2] = 0;
        }
    }

    //Initialisation des propri�t�s du Jeton pour qu'il soit au nord du centre, peu importe le c�t�
    //utilisation d'un cast pour faire passer un double en int
    //le floor sert � tronquer � l'entier inf�rieur (floor=�tage)
    pJeton->nX = (int)(floor(COTE/2)+1);
    pJeton->nY = (int)(floor(COTE/2));
}



//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour afficher le tableau
// Entr�es : Le Tableau du carr�
// Sorties : Le Tableau du carr�, affich�
// Note :
// =============================================================

void afficher(const int nCarre[COTE][COTE])
//m�thode pour afficher un tableau
{
    //d�claration des variables locales � la m�thode
    int nCpt=0, nCpt2=0;

    //boucles imbriqu�es pour afficher la grille
    for (nCpt=MIN ; nCpt <= COTE ; nCpt++)
    {
        printf("\n");  //retour chariot
        for (nCpt2=1 ; nCpt2 <= COTE ; nCpt2++)
        {
            printf("%d ", nCarre[nCpt][nCpt2]);
        }
    }
}



//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour d�placer le jeton vers la droite
// Entr�es : Le jeton
// Sorties : Le jeton
// Note :
// =============================================================

void avancer_droite (tJeton *pJeton)
{

    pJeton->nX = pJeton->nX - 1;
    pJeton->nY = pJeton->nY + 1;

}



//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour d�placer le jeton vers la gauche
// Entr�es : Le jeton
// Sorties : Le jeton
// Note :
// =============================================================

void avancer_gauche(tJeton *pJeton)
{

    pJeton->nX = pJeton->nX - 1;
    pJeton->nY = pJeton->nY - 1;

}



//Fonction
//Impl�mentation
// =============================================================
// Description : M�thode pour voir si la cellule est vide ou occup�e
// Entr�es : Le Tableau du carr�, le jeton et la variable EstVide
// Sorties : La variable Vide
// Note : Fonction car renvoie un r�sultat
// =============================================================

Bool rechercher_vide(const tJeton Jeton, const int nCarre[COTE][COTE])
{
    Bool IsEmpty;
    if (nCarre[Jeton.nX][Jeton.nY] == 0)
    {
        // Si la valeur de la grille est 0, on appellera la proc�dure placer dans le programme principal
        IsEmpty = 1;
        // TO DO
    }
    else
    {
        //sinon, nous corrigeons la trajectoire du cheminement dans la programme principal
        IsEmpty = 0;
    }

    return IsEmpty;
}



//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour avancer le jeton
// Entr�es : Le jeton
// Sorties : La nouvelle position du jeton
// Note : Avancement en "wrap"
// =============================================================

void avancer(tJeton *pJeton)
{
    if (pJeton->nX>CMAX)
    {
        pJeton->nX=CMIN;
        //si le jeton d�passe vers la droite, on le fait revenir en WRAP vers la gauche
    }
    else if (pJeton->nX<CMIN)
    {
        pJeton->nX=CMAX;
        //si le jeton d�passe vers la gauche, on le fait revenir en WRAP vers la droite
    }

    if (pJeton->nY>CMAX)
    {
        pJeton->nY=CMIN;
        //si le jeton d�passe vers le bas, on le fait revenir en WRAP vers le haut
    }
    else if (pJeton->nY<CMIN)
    {
        pJeton->nY=CMAX;
        //si le jeton d�passe vers le haut, on le fait revenir en WRAP vers le bas
    }


}



//Proc�dure
//Impl�mentation
// =============================================================
// Description : M�thode pour placer une valeur dans le carr�
// Entr�es : Le Tableau du carr�, le jeton et le compteur
// Sorties : La Tableau ayant une nouvelle valeur
// Note :
// =============================================================

void placer(const tJeton Jeton, int pnCarre[COTE][COTE], const int nCpt)
{
    //on affecte la valeur dans la cellule
    pnCarre[Jeton.nX][Jeton.nY] = nCpt;
}
