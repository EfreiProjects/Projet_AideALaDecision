#include <iostream>
#include <fstream>

using namespace std;


int** lecture(string fichier, int &taille, int &alignement)
{
    cout << " Ouverture de " << fichier << "." << endl;

    ifstream graphe(fichier.c_str(), ios::in);

    if(graphe)
    {
        string ligneEnCoursDeLecture;

        getline(graphe, ligneEnCoursDeLecture);
        sscanf(ligneEnCoursDeLecture.c_str(), "%d", &taille);
        cout << " Plateau carre de " << taille << "x"<< taille << " cases de long." << endl;

        getline(graphe, ligneEnCoursDeLecture);
        sscanf(ligneEnCoursDeLecture.c_str(), "%d", &alignement);
        cout << " Il faut aligner " << alignement << " symboles pour remporter la manche." << endl << endl;

        int **plateau = new int*[taille];

        for (int i = 0; i < taille; i++)
            plateau[i] = new int[taille];

        do
        {
        for(int i = 0; i < taille; i++)
            for(int j = 0; j < taille; j++)
                {
                    graphe >> plateau[i][j];
                }
                graphe.close();
                return plateau;
        }while(!graphe.eof());
    }
    cerr << " L'ouverture a echoue !" << endl;
    return NULL;
}
