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
// Funktion schreibt Text in alle *.md, *.csv, *.tex
char *text_in_file(char *text);

// Funktion schreibt formatiert in alle *.md, *.csv, *.tex
char *out_file(char *text, int a, int b);
// Funktion Ausgabe formatiert am Bildschirm vorlage
char *out_screen(char *text, int a, int b);

// Funktion schreibt Text in *.md
char *md_in_file(char *text);
// Funktion schreibt Text in *.csv
char *csv_in_file(char *text);
// Funktion schreibt Text in *.tex
char *tex_in_file(char *text);

// +++++++++++++++++++++++++++++++

// globale Variablen
// Dateiname 
char *fileMd  = "vorlage-Tab.md";    
char *fileCSV = "vorlage-Tab.csv";
char *fileTeX = "vorlage-Tab.tex";

int main(void){
	//char antwort;
	int clear_puffer, check; //error = false;
	char *hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";
	
	// variablen - Algorithmus
	int zahl;
	
	// +++++++++++++++++++++++++++++
	// Thema
	char *message = "\n## vorlage\n";
	// Beschreibung bzw. Info	
	char *message2 = "beschreibung\n";
														// Anpassen: Referenz auf Code
	char *TabMdKopfzeile = "siehe code. vorlage\n\n"
												 "~~~\n	Code einfügen!\n~~~\n\n"
														// Anpassen: Referenz auf Tabelle
												 "siehe tab. vorlage\n\n"
													  // Anpassen: spaltennamen
												 "| spalte1 | spalte2 |\n"
												 "|:--------|:--------|";
	char *TabCSVKopfzeile = "\nspalte1;spalte2";
	char *TabTeXKopfzeile = "		\\textbf{spalte1} & \\textbf{spalte2} \\\\ \n"
													"		\\midrule";
													  // Anpassen: Referenz auf Tabelle
	char *TabTeXBegin =  "Tabelle \\ref{tab:vorlage}\n%\n"
											 "%% Tabelle\n"
											 "\\begin{table}[!htbp] % hier einfügen\n" 
											 "	%============================\n"
											 "	\\caption[vorlage]{vorlage}	% Caption anpassen!\n"
													  // Anpassen: Tabellenname u. label
											 "	%\\label{tab:vorlage}	% Referenz anpassen!\n"
											 "	%============================\n"
											 "	\\medskip\n"
											 "	\\centering\n" 
											 "	\\setlength{\\tabcolsep}{5mm} % spaltenlänge fest \n"
											 "	\\rowcolors{1}{orange!25}{orange!5} % Farbe anpassen!\n" 
											 "	% auto. spaltenumbruch\n"
											 "	%\\begin{tabularx}{\\textwidth}{XX} % Anzahl spalten\n"
														// Anpassen: Anzahl spalten
											 "	\\begin{tabular}{ll} % Anzahl spalten\n" 
											 "		\\toprule\n"
											 "		%============================";											 
	char *TabTeXEnd = "		%============================\n"
										"		\\bottomrule\n"
										"		%\\end{tabularx}\n"
										"	\\end{tabular}\n"
										"\\end{table}\n";
						 
	// Ausgabe in Datei	
	md_in_file(message);
	md_in_file(message2);
	md_in_file(TabMdKopfzeile);										 												 
 	csv_in_file(TabCSVKopfzeile);	
 	tex_in_file(TabTeXBegin);
 	tex_in_file(TabTeXKopfzeile);

	// +++++++++++++++++++++++++++++
	system("clear"); // system("cls");
 	system("date +'%Y-%m-%d_%H:%M'");
	printf("%s\n", message);		
	printf("%s", message2);
	
	// +++++++++++++++++++++++++++++
	
	// Eingabe Zahlen
	do{
		printf("\nEingabe - Zahl [von 1 bis 10]: ");
		//text_in_file("	Eingabe - Zahl [von 1 bis 10]: "); 
		check = scanf("%d",&zahl);
		if((check != 1) || (zahl <= 0) | (zahl >10)){
			//hinweis = "	Fehler! Bitte eine plausible Zahl eingeben.\n";
			printf("%s",hinweis);
			//text_in_file(hinweis);	
		}		
	}while(((clear_puffer = getchar()) != EOF && clear_puffer != '\n') 
			 || (check != 1) || (zahl <= 0) || (zahl >10) );		

	// Algorithmus - Funktionsaufruf - Ausgabe
	// out_screen("	Version1: ", zahl); // Bildschirm
	// out_file("	Version1: ", zahl);		// Schreiben
	
	for( int i = 1; i <= zahl; i++){
		out_screen("dummyText", i, i*i);
		out_file("dummyText", i, i*i);
	}

	// +++++++++++++++++++++++++++++++
	// Ausgabe in Datei: // Latex - Tabelle schliessen
	tex_in_file(TabTeXEnd);	
	
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
// Funktion schreibt Text in  alle *.md, *.csv, *.tex
char *text_in_file(char *text){
	// Dateiname 
	/*
	char *fileMd  = "vorlage-Tab.md";    
	char *fileCSV = "vorlage-Tab.csv";
	char *fileTeX = "vorlage-Tab.tex";
	*/
	// Öffnen u. (fort)schreiben 
	FILE *streamMd  = fopen(fileMd,  "a"); 
	FILE *streamCSV = fopen(fileCSV,  "a");
	FILE *streamTeX = fopen(fileTeX,  "a");
	// printf("%s\n", text);							// Bildschirm
	// fprintf( streamMd, "%s\n", text);	// Schreiben
	// Schreiben 
	fprintf( streamMd,  "%s\n", text);			
	fprintf( streamCSV, "%s\n", text);			
	fprintf( streamTeX, "%s\n", text);
	// Schliessen										
	fclose(streamMd); 										 
	fclose(streamCSV);
	fclose(streamTeX);
	return text;
} 

// Funktion schreibt Text in *.md
char *md_in_file(char *text){
	//char *fileMd  = "vorlage-Tab.md";      // Dateiname 
	FILE *streamMd  = fopen(fileMd,  "a"); // Öffnen u. (fort)schreiben 
	// printf("%s \n", text);							 // Bildschirm
	// fprintf( streamMd, "%s \n", text);	 // Schreiben
	fprintf( streamMd,  "%s\n", text);		 // Schreiben 
	fclose(streamMd); 										 // Schliessen 
	return text;
} 

// Funktion schreibt Text in *.csv
char *csv_in_file(char *text){
	//char *fileCSV = "vorlage-Tab.csv";     // Dateiname 
	FILE *streamCSV = fopen(fileCSV,  "a");// Öffnen u. (fort)schreiben 
	// printf("%s \n", text);							 // Bildschirm
	// fprintf( streamMd, "%s \n", text);	 // Schreiben
	fprintf( streamCSV, "%s\n", text);		 // Schreiben 
	fclose(streamCSV);                     // Schliessen 
	return text;
} 

// Funktion schreibt Text in *.tex
char *tex_in_file(char *text){
	//char *fileTeX = "vorlage-Tab.tex";     // Dateiname 
	FILE *streamTeX = fopen(fileTeX,  "a");// Öffnen u. (fort)schreiben 
	// printf("%s \n", text);							 // Bildschirm
	// fprintf( streamMd, "%s \n", text);	 // Schreiben
	fprintf( streamTeX, "%s\n", text);		 // Schreiben 								
	fclose(streamTeX);                     // Schliessen 
	return text;
} 

// Funktion schreibt formatiert in alle *.md, *.csv, *.tex
char *out_file(char *text, int a, int b){
	// Dateiname 
	/*
	char *fileMd  = "vorlage-Tab.md";    
	char *fileCSV = "vorlage-Tab.csv";
	char *fileTeX = "vorlage-Tab.tex";
	*/
	// Öffnen u. (fort)schreiben 
	FILE *streamMd = fopen(fileMd,  "a"); 
	FILE *streamCSV = fopen(fileCSV,  "a");
	FILE *streamTeX = fopen(fileTeX,  "a");
	// printf("%s %d\n", text, a);						 // Bildschirm
	// fprintf( streamMd, "%s %d\n", text, a); // Schreiben 
	// Schreiben 
	fprintf( streamMd,  "| %2d  | %3d |\n"  , a, b); 
	fprintf( streamCSV, "%2d;%3d\n"           , a, b); 
	fprintf( streamTeX, "		%2d & %3d \\\\ \n", a, b); 			
	// Schliessen  
	fclose(streamMd); 										
	fclose(streamCSV);
	fclose(streamTeX);
	return text;
} 

// Funktion Ausgabe formatiert am Bildschirm vorlage
char *out_screen(char *text, int a, int b){
	printf("%2d | %3d\n", a, b);
	return text;
}


