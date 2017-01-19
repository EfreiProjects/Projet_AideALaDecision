#include <iostream>
#include "d1-minMax.h"
#include "d1-verifVictoire.h"

using namespace std;

void deplacement(int **plateau, int profondeur, int largeur,int longueur, int estTourHumain, int pieces)
{

    int x = 1; //abs
    int y = 1; //ordo

  //  cout << estTourHumain << " JOUEUR "<< endl;
    if(estTourHumain % 2 == 1) // c'est � l'humain de jouer
    {
        cout << " Le joueur joue les O" << endl;
        cout << " Saisir les coordonnees pour placer le pion. " << endl;

        //saisie s�cu pour ne pas sortir des limites du plateau de jeu + on ne r��crit pas sur un pion d�j� plac�

        do
        {
            do
            {
                cout << " Saisir l'abscisse de la case a jouer (x): ";
                cin >> x;
            }while(x < 1 || x > longueur); // X = 1     O = -1

            do
            {
                cout << endl << "Saisir l'ordonnee de la case a jouer (y): ";
                cin >> y;
                cout << endl << " Votre tour " << endl;

            }while(y < 1 || y > largeur);
        }while(plateau[y-1][x-1] != 0);

       plateau[y-1][x-1] = -1; // -1 pour commencer � 1
        verificationVictoire(plateau, largeur, longueur, pieces, x-1, y-1);
    }


    else if(estTourHumain % 2 == 0) //cpu joue
    {

    //A IMPLEMENTER : appel de la fonction MinMax pour choper les coordonn�es : A IMPLEMENTER
    iaJouer(plateau, profondeur, longueur, largeur, pieces);



    cout << " tour CPU" << endl;
    }

    else
    {
        cout << "bug tour de jeu deplacementPion.cpp" << endl;
    }

}
