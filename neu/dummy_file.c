/* ju -- 11-12-2016 -- vorlage_file.c */
/* 
Thema:        vorlage 
Beschreibung:

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // system("clear"); system("cls");
#include <stdbool.h>

// +++++++++++++++++++++++++++++++
// Konstantendefinition
//const int    DIM = 7; 						//Array-DIMENSION
//const double LICHT = 2.99793E8;
//const double E  = 2.7182818284590452354;
//const int    SEK_PRO_TAG = (60 * 60 * 24);	// Sekunden pro Tag
const double PI   = 3.14159265;
//const double MWST = 19; // 7% oder 19%

// +++++++++++++++++++++++++++++++
// Makroersetzung 
//#define ERROR {printf("\n+++ Fehler! +++"); exit(1);}

// eig. C-Funktionsbibliothek 
// Funktionsaufruf: int a = potenziere(2,3); // basis, exponent
#include "meineFkt.h" 
// Deklaration von Funktionen
// Funktion Text  in Datei schreiben
char *text_in_file(char *text);
// Funktion Schreiben in Datei vorlage
char *out_file(char *text, int a);
// Funktion Ausgabe am Bildschirm vorlage
char *out_screen(char *text, int a);

// +++++++++++++++++++++++++++++++

int main(void){
	//char antwort;
	int clear_puffer, check; //error = false;
	char *hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";

	// variablen - Algorithmus
	int zahl;

	// +++++++++++++++++++++++++++++
	// Thema
	char *message = "## vorlage \n";
	// Beschreibung bzw. Info	
	char *message2 = "beschreibung \n";
	
	// Markdown anpassen
	char *MdKopfzeile = "siehe code. vorlage\n\n"
											"~~~\n	Code anpassen!\n~~~\n\n"
											"siehe code. vorlage-out\n\n"
											"~~~\n";
	char *MdFusszeile = "~~~\n";	

	// Ausgabe in Datei	
	text_in_file(message);
	text_in_file(message2);
	text_in_file(MdKopfzeile);										 												 
 
	// +++++++++++++++++++++++++++++
	system("clear"); // system("cls");
 	system("date +'%Y-%m-%d_%H:%M'");
	printf("%s", message);		
	printf("%s", message2);
	
	// +++++++++++++++++++++++++++++

	// Eingabe Zahlen
	do{
		printf("Eingabe - Zahl: ");
		text_in_file("	Eingabe - Zahl: ");	 
		check = scanf("%d",&zahl);
		if((check != 1) || (zahl <= 0)){
			//hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";
			printf("%s",hinweis);
			text_in_file(hinweis);	
		}		
	}while(((clear_puffer = getchar()) != EOF && clear_puffer != '\n') 
			 || (check != 1) || (zahl <= 0));		

	// Algorithmus - Funktionsaufruf - Ausgabe
	// out_screen("	Version1: ", zahl); // Bildschirm
	// out_file("	Version1: ", zahl);		// Schreiben
	
	out_screen("	Version1: ", zahl);
	out_file("	Version1: ", zahl);

	// +++++++++++++++++++++++++++++++
	// Ausgabe in Datei: Markdown - Code ende
	text_in_file(MdFusszeile);	
	
	// +++++++++++++++++++++++++++++++	

	//int clear_puffer;
	//while( (clear_puffer = getchar()) != EOF && clear_puffer != '\n');
	printf("\nBeenden mit Enter...");	 	
	getchar(); //Speicherkontrolle, haelt Programm im RAM	
	//system("PAUSE"); 
	return 0;
}

// +++++++++++++++++++++++++++++++

// Algorithmus - Funktionen
// Funktion Text  in Datei schreiben
char *text_in_file(char *text){
	char *fileMd  = "vorlage_file.md";    // Dateiname 
	FILE *streamMd = fopen(fileMd,  "a"); // Öffnen u. (fort)schreiben 
	// printf("%s \n", text);							// Bildschirm
	// fprintf( streamMd, "%s \n", text);	// Schreiben
	fprintf( streamMd, "%s\n", text);			// Schreiben 								
	fclose(streamMd); 										// Schliessen  
	return text;
} 

// Funktion Schreiben in Datei vorlage
char *out_file(char *text, int a){
	char *fileMd  = "vorlage_file.md";    // Dateiname 
	FILE *streamMd = fopen(fileMd,  "a"); // Öffnen u. (fort)schreiben 
	// printf("%s %d\n", text, a);						 // Bildschirm
	// fprintf( streamMd, "%s %d\n", text, a); // Schreiben 	
	fprintf( streamMd, "%s %d\n", text, a);		// Schreiben 	 
	fclose(streamMd); 										// Schliessen  
	return text;
} 
// Funktion Ausgabe am Bildschirm vorlage
char *out_screen(char *text, int a){
	printf("%s %d\n", text, a);
	return text;
}


