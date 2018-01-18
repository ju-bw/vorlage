/* 
	2016-12-10 02:43:21 
	Jan Unger 
	backup.c
	Prgrammauswahl -- Linux-Systembefehle im C-Programm ausführen
*/

#include <stdio.h>
#include <stdlib.h> //system("ls");
#include <math.h>
#include <string.h> 			//stpcpy

int main(void) {  
  int aktion;

	//system("sleep 10"); // Warten 10s

	system("clear");
  printf("\nProgramm -- Auswahl\n");
  printf("===================");
  do {
    printf("\n\nWollen Sie\n");
		printf("**********\n");
		system("date +'%Y-%m-%d_%H:%M'");
		printf(" - ls? -->                   1 eingeben\n");
    printf(" - make? -->                 2 eingeben\n");
    printf(" - make clean? -->           3 eingeben\n");
    printf(" - Archiv erstellen? -->     4 eingeben\n");
		printf(" - Git? -->                  5 eingeben\n");
    printf(" - beenden? -->              6 eingeben\n");
		printf("Eingabe: ");
    scanf("%d",&aktion);
    switch(aktion) {
    case 1:
      /* ls u. Datum*/
			system("clear");
      system("ls -l");
			system("date +'%Y-%m-%d_%H:%M'");
      break;

		case 2:
      /* make */
			system("clear");
      system("make");
      break;

    case 3:
			/* make clean */
			system("clear");      
			system("make clean");
      break;

		case 4:
			/* archiv erstellen */
			system("clear");  
			system("rsync -avc --progress ~/c/ /media/jan/daten/linux/c/");      
			system("zip -r /media/jan/daten/linux/c.zip ~/c");      
			system("tar czf /media/jan/daten/linux/$(date +'%Y-%m-%d')-programmieren_c.tar.gz ~/c");
			system("date +'%Y-%m-%d_%H:%M'");
			printf("Archiv wurde erstellt.");
      break;
	
		case 5:
      /* Git */
			system("clear");
			system("date +'%Y-%m-%d_%H:%M'");
			//system("git init");
			system("git add -A");
			system("git commit -m 'kommentar'");
			system("git status");
			system("git log");
      break;

		default:
      /*beenden*/
      printf("\nProgramm -- Auswahl -- Ende");
    }
  }
  while(aktion==1 || aktion==2 || aktion==3 || aktion==4 || aktion==5);
  
	printf("\nBeenden mit Enter...\n\n");	 	
	getchar(); //Speicherkontrolle, haelt Programm im RAM	
	//system("PAUSE"); 
	return 0;
}

