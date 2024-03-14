#include <iostream>
#include <ncurses.h>
using namespace std;

#define ROW 23
#define COL 12

class Griglia {
  protected:
    char matrice[ROW][COL];
  public:
    Griglia();
    void stampa();
    bool controllo_ultima_riga();
    void scorrimento();
    void collisioni();
    void game_over();
};
