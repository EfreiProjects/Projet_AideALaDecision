#include <iostream>
#include <cmath>

using namespace std;

bool verificationVictoire(int **plateau, int largeur, int longueur, int pieces, int posX, int posY){
    /*
	int sumL = 0;
    int sumC = 0;
    int sumDM = 0;
    int sumDD = 0;
    int debutDiagX = 0;
    int debutDiagY = 0;

    for(int i=0; i<largeur; i++){ // colonne
        sumC = sumC + plateau[i][posX];
    }
    cout << "somme colonne" << sumC << endl;

    for(int i=0; i<longueur; i++){ //ligne
        sumL = sumL + plateau[posY][i];
    }
    cout << "somme ligne" << sumL << endl;

    debutDiagX = posX; //diagonale montante
    debutDiagY = posY;
    while(debutDiagX > 0 && debutDiagY < largeur){
        debutDiagX--;
        debutDiagY++;
    }
    cout << "debut diag montante en : " << debutDiagX+1 << "," << debutDiagY+1 << endl;
    while(debutDiagY > -1){
        if(debutDiagX >= 0 && debutDiagX < longueur && debutDiagY >=0 && debutDiagY < largeur){
            sumDM = sumDM + plateau[debutDiagY][debutDiagX];
        }
        debutDiagX++;
        debutDiagY--;
    }
    cout << "somme diag montante : " << sumDM << endl;

    if(posX == posY){ // diagonale descendante
        int limit;
        debutDiagX = 0;
        debutDiagY = 0;
    }
    if(posX < posY){
        debutDiagX = 0;
        debutDiagY = posY - posX;
    }
    if(posY < posX){
        debutDiagY = 0;
        debutDiagX = posX - posY;
    }
    cout << "debut diag descendante en : " << debutDiagX+1 << "," << debutDiagY+1 << endl;

    while(debutDiagX < longueur && debutDiagY < largeur){
        sumDD = sumDD + plateau[debutDiagY][debutDiagX];
        debutDiagX++;
        debutDiagY++;
    }
    cout << "somme diag descendante : " << sumDD << endl;

    if(sumC >= abs(pieces) || sumL >= abs(pieces) || sumDD >= abs(pieces) || sumDM >= abs(pieces)){
        cout << "vous avez potentiellement gagne" << endl;
    }
    */
    return 50;
}
