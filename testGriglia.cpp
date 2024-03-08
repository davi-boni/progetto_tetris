//Griglia Tetris
#include <iostream>
#include <stdio.h>
using namespace std;

const int r=23;
const int c=18;

void stampa_griglia(char g[r][c]){
	for(int i=0;i<r;i++){				//ultime due righe sono grafiche
		cout<<endl;
		for(int j=0;j<c;j++){
			if(j==0 || j==1 || j==c-2 || j==c-1){
				cout<<g[i][j];
				if(j==1) cout<<" ";
			}
			else cout<<g[i][j]<<" ";
		}
	}
}

bool controlloUltimaRiga(char g[r][c]) { // verifica se l'ultima riga della matrice è piena
	bool full=true;
	int j=2;
	while(full && j<c-1){
	    if(g[r-2][j]=='.') full=false;
	    j++;
	}
	return(full);
}



void inizializza_griglia(char griglia[r][c]){
	for(int i=0;i<r;i++){
		if(i==r-1){
			for(int z=0;z<c;z++){
				if(z==0){
					griglia[i][z]='<';
					griglia[i][z+1]='|';
					z++;
				}
				else if(z==c-2){
					griglia[i][z]='|';
					griglia[i][z+1]='>';
					z++;
				}
				else griglia[i][z]='^';
			}
		}
		else{
			for(int j=0;j<c;j++){
				if(j==0){
					griglia[i][j]='<';
					griglia[i][j+1]='|';
					j++;
				}
				else if(j==c-2){
					griglia[i][j]='|';
					griglia[i][j+1]='>';
					j++;
				}
				else{
					griglia[i][j]='.';
				}
			}
		}
	}
}

void scorrimento(char g[r][c]){
    for(int i=r-2;i>0;i--){
        for(int j=2;j<c-2;j++){
            g[i][j]=g[i-1][j];
        }
    }
    for(int j=2;j<c-2;j++){
        g[0][j]='.';
    }
}



int main(){
    char griglia[r][c];
	inizializza_griglia(griglia);
	for(int i=2; i<c-2;i++){
	    if(i%2==0) griglia[r-2][i]='[';
	    else if(i%2!=0) griglia[r-2][i]=']';
	    
	}
	griglia[r-6][3]='[';
	griglia[r-6][4]=']';
	griglia[0][6]='[';
	griglia[0][7]=']';
	scorrimento(griglia);
	scorrimento(griglia);
	scorrimento(griglia);
	scorrimento(griglia);

	stampa_griglia(griglia);
	return(0);
}
