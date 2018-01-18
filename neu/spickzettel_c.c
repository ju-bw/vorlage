/* ju -- 5-12-2016 -- vorlage.c */
/* vorlage */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>

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

// Datei Zeilenweise einlesen
// Anwendung: char *filename = "file.txt"; readfile(filename);
#define MAX_LEN 256
void readfile(char *dateiname) {
	char* line = malloc(sizeof(char)*MAX_LEN);
	FILE *stream = fopen(dateiname,"rt"); //Read Text
	if( stream == NULL ) ERROR
	while(!feof(stream)) {
		fgets(line, MAX_LEN, stream);
		printf("%s",line);
	}
	fclose(stream);
	free(line);
}

int main(void){
	printf("vorlage\n");

	char antwort;
	do{
		//Code
		// printf bzw. scanf
		char name[50];
		printf("Eingabe Vornamen: "); scanf("%s", name);
		printf("\nHallo %s!\n",name);	

		// Datei oeffnen - schreiben - lesen - schliessen
		printf("\n+++ Datei oeffnen - schreiben - lesen - schliessen +++\n\n");

		// Datei anlegen
		char *filename = "file.txt";
		FILE *stream;

		int n = 56;
		float x = 2.7182818284590452354;
		double y = 2.7182818284590452354;
		char *s = "Hallo";	
		char *message = "ju -- 6-12-2016 -- Schreiben in File";

		//*************** Datei (Über)Schreiben **********************
		// Datei oeffnen
		stream = fopen(filename,"wt");
		// Datei schreiben
		fprintf(stream,"%s %s!\n", s, name);		
		fprintf(stream, "ganze Zahl: %d\n", n);
		fprintf(stream,"genauigkeit von Gleitpunktzahlen: %f - %lf\n", x*1000, y*1000);
		// Datei schliessen
		fclose(stream);
	
		//*************** Datei (fort)schreiben **********************
		// Datei oeffnen
		stream = fopen(filename, "a");
		// Datei schreiben
		fprintf( stream, "\n%s\n\n", message);
		// Datei schliessen
		fclose(stream);

		//*************** Datei Zeilenweise einlesen *****************
		readfile(filename);
	
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
$ gcc vorlage.c -o vorlage.exe oder make oder make clean
$ ./vorlage.x oder .\vorlage.exe
*/

/*
// Ausgabe

*/

