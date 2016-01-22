#include <iostream>
#include <Windows.h>
#include "fonds.h"
using namespace std;

//Prototypen
void show_matrix(bool Matrix[10][11]);
void reset_matrix(bool Matrix[10][11]);

//Main-Funktion
int main() {
	const char text[] = { "test" };
	int num_cols = 11;
	int num_rows = 10;
	int lettersize = 5;
	int shift = 10;
	int temp, rest;
	bool Matrix[10][11] = { 0 };

	for (int s = 0; s < ((sizeof(text) - 1) * lettersize) + shift; s++)
	{
		reset_matrix(Matrix); //Matrix jede Runde löschen, damit keine Reste bleiben bei der Verschiebung
		//Iterate Cols
		for (int c = -shift; c < num_cols- shift; c++) {
			if ((c + s) < 0)
				temp = 0; //Leerzeilen davor
			else
				temp = font5x7_basic[text[(c + s) / lettersize] - 32][(c + s) % lettersize]; //Buchstaben holen aus der fonds.h
			cout << temp; //Kontrolle
			rest = 0;
			int iterator = 9;
			if (temp == 0) {
				//Mach nix
			}
			else {
				do {		//Hex in Binär ändern, zum Eintragen in die Matrix
					rest = temp % 2;
					temp /= 2;
					Matrix[iterator][c + shift] = rest;
					iterator--;
				} while (temp != 0);

			}
		}
		cout << endl;
		show_matrix(Matrix);
		cout << endl;
	}
}
void reset_matrix(bool Matrix[10][11]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 11;j++)
			Matrix[i][j] = false;
};


void show_matrix(bool Matrix[10][11]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			cout << Matrix[i][j];
		}
		cout << endl;
	}
};
