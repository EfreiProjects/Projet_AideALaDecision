/**
*@file minMax.cpp
*@author Knive & Kapina
*/
#include "d1-minMax.h"
#include "d1-verifVictoire.h"


void iaJouer(int** plateau, int profondeur, int longueur, int largeur, int p) {
     int max = -10000;
     int tmp,maxi,maxj;
     srand(time(NULL));

     for (int i=0;i<longueur;i++) {
          for (int j=0;j<largeur;j++) {
                if(plateau[i][j] == 0) {
                      plateau[i][j] = 1;
                      verificationVictoire(plateau, largeur, longueur, p, j, i);
                      tmp = min(plateau,profondeur-1, longueur, largeur, p, maxi, maxj);

                      if(tmp > max || ( (tmp == max) && (rand()%2 == 0) ) ) {
                            max = tmp;
                            maxi = i;
                            maxj = j;
                      }
                      plateau[i][j] = 0;
                }
          }
     }

     plateau[maxi][maxj] = 1;
}

int max(int** plateau,int profondeur, int longueur, int largeur, int p, int maxi, int maxj) {
     if(profondeur == 0 || verificationVictoire(plateau, largeur, longueur, p, maxi, maxj)!=0)
          return eval(plateau, longueur, largeur, p, maxi, maxj);

     int max = -10000;
     int tmp;
     srand(time(NULL));

     for(int i=0;i<longueur;i++) {
          for(int j=0;j<largeur;j++) {
                if(plateau[i][j] == 0) {
                      plateau[i][j] = -1;
                      tmp = min(plateau,profondeur-1, longueur, largeur, p, maxi, maxj);

                      if(tmp > max || ( (tmp == max) && (rand()%2 == 0) ) )  max = tmp;
                      plateau[i][j] = 0;
                }
          }
     }

     return max;
}

int min(int** plateau,int profondeur, int longueur, int largeur, int p, int maxi, int maxj) {
     if(profondeur == 0 || verificationVictoire(plateau, largeur, longueur, p, maxi, maxj)!=0)
          return eval(plateau, longueur, largeur, p, maxi, maxj);

     int min = 10000;
     int i,j,tmp;
     srand(time(NULL));

     for(i=0;i<3;i++) {
          for(j=0;j<3;j++) {
                if(plateau[i][j] == 0) {
                      plateau[i][j] = 1;
                      tmp = max(plateau,profondeur-1, longueur, largeur, p, maxi, maxj);

                      if(tmp < min || ( (tmp == min) && (rand()%2 == 0) ) ) min = tmp;
                      plateau[i][j] = 0;
                }
          }
     }

     return min;
}

int eval(int** plateau, int longueur, int largeur, int p, int posX, int posY) {
     int vainqueur;
     int nb_de_pions = 0;
     int i,j;

     //On compte le nombre de pions pr�sents sur le plateau
     for(i=0;i<longueur;i++) {
          for(j=0;j<largeur;j++) {
               if(plateau[i][j] != 0)
            	   nb_de_pions++;
          }
     }

     if( (vainqueur = verificationVictoire(plateau, largeur, longueur, p, posX, posY)) != 0) {
          if( vainqueur == 1 )
               return 10000 - nb_de_pions;
          else if( vainqueur == 2 )
               return -10000 + nb_de_pions;
          else
               return 0;
     }

     //On compte le nombre de s�ries de 2 pions align�s de chacun des joueurs
     int series_IA = 0, series_j = 0;

     nb_series(plateau,longueur, largeur, &series_IA,&series_j, p);

     return series_IA - series_j;
}

void nb_series(int **plateau, int longueur, int largeur, int* series_IA, int* series_J, int p) {
    int i2, j2, n;
    bool alignement = false;

    *series_IA = 0;
    *series_J = 0;

    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            //ligne
            if (plateau[i][j] == 1) {
                for (n = j+1; n < p-1; n++) {
                    if (n == largeur) break;
                    if (plateau[i][n] == 1 || plateau[i][n] == 0) alignement = true;
                    else alignement = false;
                }
                if (alignement == true) series_IA++;
            }
            if (plateau[i][j] == -1) {
                 for (n = j+1; n < p-1; n++) {
                     if (n == largeur) break;
                     if (plateau[i][n] == -1 || plateau[i][n] == 0) alignement = true;
                     else alignement = false;
                 }
                 if (alignement == true) series_J++;
            }

            //colonne
            if (plateau[i][j] == 1) {
                for (n = i+1; n < p-1; n++) {
                    if (n == largeur) break;
                    if (plateau[n][j] == 1 || plateau[i][n] == 0) alignement = true;
                    else alignement = false;
                }
                if (alignement == true) series_IA++;
            }
            if (plateau[i][j] == -1) {
                 for (n = i+1; n < p-1; n++) {
                     if (n == largeur) break;
                     if (plateau[i][n] == -1 || plateau[i][n] == 0) alignement = true;
                     else alignement = false;
                 }
                 if (alignement == true) series_J++;
            }

            //diagonale montante
            if (plateau[i][j] == 1) {
                for (n = 0; n < p; n++) {
                    i2 = i;
                    j2 = j;
                    if (i2-1 < 0 || j2+1 > largeur) break;
                    if (plateau[i2-1][j2+1] == 1 || plateau[i2-1][j2+1] == 0) alignement = true;
                    else alignement = false;
                    i2 -= 1;
                    j2 += 1;
                }
                if (alignement == true) series_IA++;
            }
            if (plateau[i][j] == -1) {
                for (n = 0; n < p; n++) {
                    i2 = i;
                    j2 = j;
                    if (i2-1 < 0 || j2+1 > largeur) break;
                    if (plateau[i2-1][j2+1] == -1 || plateau[i2-1][j2+1] == 0) alignement = true;
                    else alignement = false;
                    i2 -= 1;
                    j2 += 1;
                }
                if (alignement == true) series_J++;
            }

            //diagonale descendante
            if (plateau[i][j] == 1) {
                for (n = 0; n < p; n++) {
                    i2 = i;
                    j2 = j;
                    if (i2+1 > longueur || j2+1 > largeur) break;
                    if (plateau[i2+1][j2+1] == 1 || plateau[i2+1][j2+1] == 0) alignement = true;
                    else alignement = false;
                    i2 += 1;
                    j2 += 1;
                }
                if (alignement == true) series_IA++;
            }
            if (plateau[i][j] == -1) {
                for (n = 0; n < p; n++) {
                    i2 = i;
                    j2 = j;
                    if (i2+1 > longueur || j2+1 > largeur) break;
                    if (plateau[i2+1][j2+1] == -1 || plateau[i2+1][j2+1] == 0) alignement = true;
                    else alignement = false;
                    i2 += 1;
                    j2 += 1;
                }
                if (alignement == true) series_J++;
            }
        }
    }
}
