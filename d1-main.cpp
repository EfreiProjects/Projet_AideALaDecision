#include <iostream>
#include "d1-generationPlateau.h"
#include "d1-deplacementPion.h"
#include "d1-verifVictoire.h"
#include "d1-lectureFichier.h"
#include "d1-minMax.h"
#include "d1-verifVictoire.h"
//#include "string.h"

using namespace std;

int main()
{
    int difficulte = -1;
    int **plateau = NULL;
    int largeur = 0;
    int longueur = 0;
    int estTourHumain = 0;
    bool victoire = 0;
    int pieces = 0; // Lors d'un alignement de pièces, nombre de pièces requises pour gagner (P dans le sujet)
    int choixDebut = -1;
    int profondeur;
    int echecOuverture = 0;
    string quitter = "init";

    do
    {

        cout << "            *** MENU TIC TAC TOE ***" << endl << endl << endl;
        cout << "  _____________________________________________________" << endl;
        cout << " |   Lecture fichier    |  Commencer nouvelle partie   |" << endl;
        cout << " |       Taper 1        |              Taper 0         | " << endl;
        cout << " |_____________________________________________________| " << endl << endl;

        do
        {
            cout << " Votre choix :";
            cin >> choixDebut;
        }while(choixDebut != 1 && choixDebut != 0);


        do
        {
        cout << " Choississez une difficulte de jeu, nombre entier positif: ";
        cin >> profondeur;
        }while(profondeur <= 0);

    //Lecture de fichier
        if(choixDebut == 1)
        {
            int taille = 0;
            int alignement = 0;

            string nom;
            cout << " Nom du fichier, format .txt: ";
            cin >> nom;
            cout << endl;

            int** plateau = lecture(nom, taille, alignement);

            largeur = taille;
            longueur = taille;
            pieces = alignement;

            if(plateau == NULL)
            {
                cout << " Echec lors de l'initialisation, retour a l'ecran principal..." << endl;
            }

            else
            {
            affichagePlateau(plateau, largeur, longueur);

            estTourHumain = choixDuJoueur(); //sert lors de l'appel du placement des pions, pour savoir si l'IA ou le joueur doit jouer

            do
            {
                deplacement(plateau, profondeur, largeur, longueur, estTourHumain, pieces);
                affichagePlateau(plateau, largeur, longueur);
                estTourHumain++;
            }while(victoire == false);
            }

        }


    //Debut nouvelle partie
        if(choixDebut == 0)
        {
            cout << endl;
            cout << " Creation d'un plateau de jeu." << endl;
            cout << " Choisir la taille, largeur x longueur" << endl;
            cout << " NB : taille minimum autorisee : 3x3" << endl;

            do
            {
                cout << " Saisir sa largeur: ";
                cin >> largeur;
            }while(largeur < 3);

            cout << endl;

            do
            {
                cout << " Saisir sa longueur: ";
                cin >> longueur;
            }while(longueur < 3);

            cout << endl;

            cout << " Fixer le nombre de pieces requises lors d'un alignement pour gagner. " << endl;
            cout << " (Alignement minimal autorise de longueur 2 pour gagner)" << endl;
            do
            {
                cout << " Votre choix: ";
                cin >> pieces;
            }while(pieces < 2 || pieces > largeur || pieces > longueur);
            cout << endl;
                    int **plateau = new int*[largeur];

            for (int i = 0; i < largeur; i++)
                plateau[i] = new int[longueur];

            generationPlateau(plateau, largeur, longueur);
            affichagePlateau(plateau, largeur, longueur);
            estTourHumain = choixDuJoueur();

            do
            {
                deplacement(plateau, profondeur, largeur, longueur, estTourHumain, pieces);
                affichagePlateau(plateau, largeur, longueur);
                estTourHumain++;
            }while(victoire == false);

        }

  //      else
        //    cout << " Erreur choixDebut" << endl;

        do
        {
            cout << " Voulez vous fermer le programme ? Saisir oui / non: ";
            cin >> quitter;
            cout << endl;
        }while(quitter != "non" && quitter != "oui");

    }while(quitter == "non");

    for (int i = 0; i < longueur * largeur; i++)
        delete[] plateau[i];
    delete[] plateau;

    return 0;
}
