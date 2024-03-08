//Griglia Tetris
#include <iostream>
#include <stdio.h>
using namespace std;

#define r 23
#define c 12

bool controlloUltimaRiga() { // verifica se l'ultima riga della matrice è piena
	
}

void scorrimento() { // fa scorrere la griglia, eliminando l'ultima e aggiungendone una in cima
	if(controlloUltimaRiga()) {
		/*codice*/
}

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

void inizializza_griglia(){
	char griglia[r][c];
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
	stampa_griglia(griglia);
}

int main(){
	inizializza_griglia();
	return(0);
}

