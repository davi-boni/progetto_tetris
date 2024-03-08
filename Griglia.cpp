#include <iostream>
#include <ncurses.h>
#include "Griglia.hpp"
using namespace std;

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
