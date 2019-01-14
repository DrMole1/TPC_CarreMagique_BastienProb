#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED



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
#endif // HEAD_H_INCLUDED
