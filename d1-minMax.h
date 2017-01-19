/**
 *@file		minMax.h
 *@author	Knive
 *@version
 *@date     10 mars 2014
 *@brief
 *@details
 */

#ifndef MINMAX_H_
#define MINMAX_H_

#include <iostream>
#include <time.h>
#include <stdlib.h>

void iaJouer(int** plateau,int profondeur, int longueur, int largeur, int pieces);

int max(int** plateau,int profondeur, int longueur, int largeur, int p, int maxi, int maxj);

int min(int** plateau,int profondeur, int longueur, int largeur, int p, int maxi, int maxj);

void nb_series(int **plateau, int longueur, int largeur, int* series_IA, int* series_J, int p);

int eval(int** plateau, int longueur, int largeur, int p, int maxi, int maxj);

//int gagnant(int** plateau);

#endif /* MINMAX_H_ */
