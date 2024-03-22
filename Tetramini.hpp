#include <cstring>
#include <ncurses.h>
#include <iostream>

using namespace std;

#define R 2
#define C 4
#define L 8

class Tetramini
{
protected:
    int xloc, yloc, xmax, ymax;
    char tetram[R][C];
    char l[L];
    WINDOW *curwin;
public:

    Tetramini(){
        getmaxyx(curwin,ymax,xmax);
    }

    void mvdown(){
        yloc++;

    }

    void mvleft()
    {
        xloc--;
    }

    void mvright()
    {
        xloc++;
    }

    void rotation(){

    }

    int getmv(){
        int choice = wgetch(curwin);
        switch (choice)
        {
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        case KEY_UP:
            rotation();
            break;
        default:
            break;
        }
    return choice;
    }

    void empty2(){
        int y=yloc;
        int x=xloc;
        for (int i = 0; i < L; i++)
        {
            l[i]=' ';
            if(i%2==0 && i!=0) y++, x=xloc;
            mvwaddch(curwin, y, x, l[i]);
            x++;
        }
    }

    void empty1(){
        int x=xloc;
        int y=yloc;
        for (int  i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                tetram[i][j]=' ';
                mvwaddch(curwin,y,x, tetram[i][j]);
                x++;
                if(j==3) x=xloc, y++;
            }
            
        }
    }
};



class Quadrato : public Tetramini{
    protected:
    public:
    
    Quadrato(WINDOW *win, int y, int x){
        curwin=win;
        keypad(curwin, true);
        getmaxyx(curwin,ymax,xmax);
        yloc=y;
        xloc=x;
        for (int  i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if(j%2==0){
                    tetram[i][j]='[';
                }
                else tetram[i][j]=']';
                mvwaddch(curwin,y,x, tetram[i][j]);
                x++;
                if(j==3) x=xloc, y++;
            }
            
        }
    };

    void mvdown(){
        empty1();
        yloc++;
        if (yloc>ymax-3) yloc=ymax-3;

    }

    void mvleft(){
        empty1();
        xloc--;
        if(xloc<1) xloc=1;
    }

    void mvright(){
        empty1();
        xloc++;
        if(xloc>xmax-5) xloc=xmax-5;
    }

    int getmv(){
        int choice = wgetch(curwin);
        switch (choice)
        {
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
       case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
        }
    return choice;
    }
    
    void display(){
        int x=xloc;
        int y=yloc;
        for (int  i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if(j%2==0){
                    tetram[i][j]='[';
                }
                else tetram[i][j]=']';
                mvwaddch(curwin,y,x, tetram[i][j]);
                x++;
                if(j==3)x=xloc, y++;
            }
        }
    }


};

class Linea : public Tetramini{
    protected:
    
    public:
    Linea(WINDOW *win,int y, int x){
        curwin=win;
        keypad(curwin, true);
        getmaxyx(curwin,ymax,xmax);
        yloc=y;
        xloc=x;
        for (int i = 0; i < L; i++)
        {
            if(i%2==0) l[i]='[';
            else l[i]=']';
            if(i%2==0 && i!=0) y++, x=xloc;
            mvwaddch(curwin, y, x, l[i]);
            x++;
        }
    }
    
    void mvdown(){
        empty2();
        yloc++;
        if (yloc>ymax-5)
        {
            yloc=ymax-5;
        }
        
    }

    void rotation(){
        empty2();
        int y=yloc+1;
        int x=xloc;
        for (int i = 0; i < L; i++)
        {
            if(i%2==0) l[i]='[';
            else l[i]=']';
            mvwaddch(curwin, y, x, l[i]);
            x++;
        }
    }

    void display1(){
        int y=yloc;
        int x=xloc;
        for (int i = 0; i < L; i++)
        {
            if(i%2==0) l[i]='[';
            else l[i]=']';
            if(i%2==0 && i!=0) y++, x=xloc;
            mvwaddch(curwin, y, x, l[i]);
            x++;
        }
    }    

    int getmv(){
        int choice = wgetch(curwin);
        switch (choice)
        {
        case KEY_DOWN:
            mvdown();
            break;
        default:
            break;
        }
    return choice;
    }

};

