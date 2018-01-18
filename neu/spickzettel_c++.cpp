/* ju -- 6-12-2016 -- vorlage.cpp */
/* vorlage */

#include <cmath>
#include <climits>
#include <complex>   // float complex, double complex
#include <fstream>   // Datei
#include <stddef.h>  // wegen ptrdiff_t (Pointerarithmetik)
#include <ctime>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

// eig. C-Funktionsbibliothek 
// Funktionsaufruf: int a = potenziere(2,3); // basis, exponent
#include "meineFkt.h" 
// Konstantendefinition
const int    DIM = 7; 						//Array-DIMENSION
const double LICHT = 2.99793E8;
const double E  = 2.7182818284590452354;
const int    SEK_PRO_TAG = (60 * 60 * 24);	// Sekunden pro Tag
const double PI   = 3.14159265;
const double MWST = 19; // 7% oder 19%

// Makroersetzung 
#define ERROR {printf("\n+++ Fehler! +++"); exit(1);}


int main(void){
	printf("vorlage\n");

	char antwort;
	do{
		// ******************** Code *******************************
		// printf bzw. scanf
		char name[50];
		printf("Eingabe Vornamen: "); scanf("%s", name);
		printf("\nHallo %s!\n",name);	

		// cout und cin
		string name2;
		cout << "Namen Eingabe: "; getchar(); cin >> name2; 
		cout << "Hallo " << name2 << "!" << endl;


		//Wiederholen? 
		printf("\n	Nochmal (j/n)? "); getchar(); scanf("%c", &antwort);
	}
	while(antwort == 'j' || antwort == 'J');

	
	fflush(stdin); // Tastaturpuffer leeren
	getchar(); //Speicherkontrolle
	return 0;
}
/*
// Kompilieren & Ausfuehren
$ g++ vorlage.cpp -o vorlage.exe oder make oder make clean
$ ./vorlage.x oder .\vorlage.exe
*/

/*
// Ausgabe


*/

