
//BUT : Cr�er un carr� magique, tableau d'entiers de 5 par 5 ou 7 par 7, incr�ment� par des valeurs de 1 � 25 ou 1 � 49.
//PRINCIPE : Le premier entier 1 se trouve au nord du milieu de la table
//On place les chiffres de fa�on croissante en allant au nord est de la position courante, une seule fois
//Si la place est d�j� prise, on se d�place au nord-ouest jusqu'� trouver cette place libre
//La grille est consid�r�e comme sph�rique
//Cr�er algo du carr� magique en tableau � 2 DIM qui mat�rialisera la grille
//Structure enregistrement contenant les positions x et y
//Fonctionne pour 5 par 5 ou 7 par 7
//Fonctions initialiser, avancer gauche, avancer droite, avancer corriger (donc enclencher avancer gauche), rechercher, placer, afficher,
//ENTREES : Aucune entr�e
//SORTIE : Le carr� magique

//impl�mentations des biblioth�ques (macros)
#include <stdio.h>
#include <stdlib.h>

//d�clarations des constantes
#define COTE 5  //� changer par 7 pour une grille de 7x7 !
#define SUP 6
#define CMIN 1
#define CSMIN 0
#define CMAX 5
#define CSMAX 6
#define MIN 1
#define XSTART 3
#define YSTART 2
#define XSTARTSUP 4
#define YSTARTSUP 3

//on d�finit la structure tJeton
typedef struct tJeton
{
    int nX;
    int nY;

}tJeton;

//Enum�ration du bool�en
typedef enum Bool {false,true} Bool;

// Prototype : signatures des m�thodes
// ======================================================================
void initialiser(int pnCarre[COTE][COTE], tJeton *pJeton);
void afficher(const int nCarre[COTE][COTE]);
void avancer_droite (tJeton *pJeton);
void avancer_gauche(tJeton *pJeton);
Bool rechercher_vide(const tJeton Jeton, const int nCarre[COTE][COTE]);
void avancer(tJeton *pJeton);
void placer(const tJeton Jeton, int pnCarre[COTE][COTE], const int nCpt);
// ======================================================================



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
    for (nCpt = 1 ; nCpt<COTE*COTE +1 ; nCpt++)
    {
        avancer_droite (&Jeton);
        avancer(&Jeton);
        if (rechercher_vide (Jeton, nCarre)==0)
        {
            avancer_gauche(&Jeton);
            avancer(&Jeton);
            placer (Jeton, nCarre, nCpt);
        }
        else
        {
            placer (Jeton, nCarre, nCpt);
        }
    }

    //affichage du Carre � l'�cran
    afficher(nCarre);

    return 0;
}


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
    for (nCpt=MIN ; nCpt < SUP ; nCpt++)
    {
        for (nCpt2=1 ; nCpt2 < SUP ; nCpt2++)
        {
            pnCarre[nCpt][nCpt2] = 0;
        }
    }

    //Initialisation des propri�t�s du Jeton
    pJeton->nX = XSTART;  // Convention pour passer une valeur dans un pointeur dans une structure !
    pJeton->nY = YSTART;
    if (COTE == 7)
    {
        pJeton->nX = XSTARTSUP;  // si jamais la grille est de 7x7
        pJeton->nY = YSTARTSUP;
    }
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
    for (nCpt=MIN ; nCpt < SUP ; nCpt++)
    {
        printf("\n");  //retour chariot
        for (nCpt2=1 ; nCpt2 < SUP ; nCpt2++)
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
    if (pJeton->nX == CSMIN)
    {
        //on le fait revenir en WRAP � droite de la grille
        pJeton->nX = CMAX;
    }
    else if (pJeton->nX == CSMAX)
    {
        pJeton->nX = CMIN;
        //on le fait revenir en WRAP � gauche de la grille
    }

    if (pJeton->nY == CSMIN)
    {
        pJeton->nY = CMAX;
        //on le fait revenir en WRAP en bas de la grille
    }
    else if (pJeton->nY == CSMAX)
    {
        pJeton->nY = CMIN;
        //on le fait revenir en WRAP en haut de la grille
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

//fichier .h qui d�tient les biblioth�ques/d�clarations
//fichier .c qui contient les fonctions
//fichier .c qui contient le programme principal
