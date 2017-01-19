#include <iostream>

using namespace std;

void generationPlateau(int **plateau,int largeur,int longueur)
{
    for(int i = 0; i < largeur; i++)
        for(int j = 0; j < longueur; j++)
           {
            plateau[i][j] = 0;
           }
}

void affichagePlateau(int **plateau, int largeur, int longueur) // boucles for avec | ou - pour former le tableau
{
    cout << "(y)|";
    for(int z = 0; z < longueur; z++)
        cout << z+1 << " ";
    cout << "(x)" << endl;

    for (int k = 0; k < (2 * longueur) + 4; k++)
        cout << "-";
    cout << endl;

    for(int i = 0; i < largeur; i++)
    {
        cout << i+1 << "  |";
        for(int j = 0; j < longueur; j++)
        {
            if(plateau[i][j] == -1) // si case = -1 alors on joue les O
                cout << "O " ;
            else if(plateau[i][j] == 1) // case = 1, on joue les X
                cout << "X ";
            else if(plateau[i][j] == 0) // case vide
                    cout << ". ";
            else
                cout << "fail geneplateau.cpp" << endl;
        }

        cout << "|"<< endl;
        for (int k = 0; k < (2 * longueur) + 4; k++)
            cout << "-";
        cout << endl;
    }
}

int choixDuJoueur()
{
    int choix = 0;

    cout << " Qui debute la partie ?" << endl;
    cout << " Taper 1 pour commencer" << endl;
    cout << " Taper 0 pour laisser commencer l'IA" << endl;

    do
    {
        cout << " Choix: ";
        cin >> choix;
        cout << endl;
    }while( choix < 0 || choix > 1);

    return choix;

}
