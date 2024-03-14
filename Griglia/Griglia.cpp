#include <iostream>
#include <ncurses.h>
#include "Griglia.hpp"
using namespace std;

Griglia::Griglia() {
  for (int i = 0; i < r; i++) {
		if (i == ROW - 1) {
			for (int j = 0; j < c; j++) {
				if ( j == 0) {  
					matrice[i][j] = '<';
					matrice[i][j+1] = '|';
					j++;
				}
				else if (j == COL - 2) {
					matrice[i][j] = '|';
					matrice[i][j+1] = '>';
					j++;
				}
				else matrice[i][j] = '^';
			}
		}
		else {
			for (int j = 0; j < c; j++) {
				if (j == 0) {
					matrice[i][j] = '<';
					matrice[i][j+1] = '|';
					j++;
				}
				else if (j == c - 2) {
					matrice[i][j] = '|';
					matrice[i][j+1] = '>';
					j++;
				}
				else {
					matrice[i][j] = '.';
				}
			}
		}
	}
}

bool Griglia::controllo_ultima_riga() {
  bool full = true;
  int j = 2;

  while (full && j < COL - 1) {
    if (matrice[ROW - 2][j] == ".") full = false;
    j++;
  }
  
  return full;
}

void Griglia::scorrimento() {
  for (int i = ROW - 2; i > 0; i--) {
    for (int j = 2; j < COL - 2; j++) {
      matrice[i][j] = matrice[i - 1][j];
    }
  }

  for (int j = 2; j < COL - 2; j++) {
    matrice[0][j] = '.';
  }
}
