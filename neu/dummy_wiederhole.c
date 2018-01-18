/* ju -- 11-12-2016 -- vorlage.c */
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
// Funktion Ausgabe am Bildschirm vorlage
char *out_screen(char *text, int a);

// +++++++++++++++++++++++++++++++

int main(void){
	char antwort;
	int clear_puffer, check; //error = false;
	char *hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";

	// variablen - Algorithmus
	int zahl;

	// +++++++++++++++++++++++++++++++
	// Thema
	char *message = "## vorlage\n";
	// Beschreibung bzw. Info	
	char *message2 = "beschreibung\n";

	// +++++++++++++++++++++++++++++++
	do{
		system("clear"); // system("cls");
	 	system("date +'%Y-%m-%d_%H:%M'");
		printf("%s", message);		
		printf("%s", message2);

		// +++++++++++++++++++++++++++++++

		// Eingabe Zahlen
		do{
			printf("Eingabe - Zahl: ");
			check = scanf("%d",&zahl);
			if((check != 1) || (zahl <= 0)){
				//hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";
				printf("%s",hinweis);
			}		
		}while(((clear_puffer = getchar()) != EOF && clear_puffer != '\n') 
				 || (check != 1) || (zahl <= 0));		


		// Algorithmus - Funktionsaufruf - Ausgabe
		// out_screen("	Version1: ", zahl); // Bildschirm
	
		out_screen("Version1: ", zahl);
		
		// +++++++++++++++++++++++++++++++
		// Wiederholen
		do{
			printf("\nNoch einmal? [j/n] "); 
			scanf("%c", &antwort);
		}while(((clear_puffer = getchar()) != EOF && clear_puffer != '\n'));			
	}while((antwort == 'j') || (antwort == 'J'));

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
// Funktion Ausgabe am Bildschirm vorlage
char *out_screen(char *text, int a){
	printf("%s %d\n", text, a);
	return text;
}





