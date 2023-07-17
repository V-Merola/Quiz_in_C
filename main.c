#include <stdio.h>
#include <stdlib.h>
#include "TInfo.h"




int main(){


 int nDomanda = 16;
 
 TList list = listCreate();
 TList preferiti = listCreate();
 TInfo cerca;
 //TNode *nodeCerca;
 int menu = 0;
 int subMenuModifica = 0;
 int subMenuPreferiti = 0;

 

list = listInsert(list,(TInfo){"Rossi", "Mario", 1});

list = listInsert(list,(TInfo){"verdi", "giuseppe", 2});

list = listInsert(list,(TInfo){"azka", "dario", 3});

list = listInsert(list,(TInfo){"romo", "remo", 4});

list = listInsert(list,(TInfo){"Rossi", "Mimmo", 5});

list = listInsert(list,(TInfo){"Robert", "junior", 6});

list = listInsert(list,(TInfo){"lol", "awert", 7});

list = listInsert(list,(TInfo){"vino", "rosso", 8});

list = listInsert(list,(TInfo){"vino", "Mario", 9});

list = listInsert(list,(TInfo){"pianta", "filippo", 10});

list = listInsert(list,(TInfo){"orologio", "lancette", 11});

list = listInsert(list,(TInfo){"Roi", "Marì", 12});

list = listInsert(list,(TInfo){"Rando", "Mario", 13});

list = listInsert(list,(TInfo){"esper", "file", 14});

list = listInsert(list,(TInfo){"quanto", "costa", 15});

list = listInsert(list,(TInfo){"tutti", "fuori", 16});


home: 
	printf("	Home:\n");
	printf("1	Inserisci una nuova domanda\n"
	"2	Stampa tutte le domande\n"
	"3	Stampa tutte le domande e la risposta\n"
	"4	Preferiti\n""5	Modifica\n""6	Ritorna al quiz\n"
	"7	Cerca\n""8	exit\n");
	scanf("%d",&menu);


switch(menu){
	   case 1:
			inserisciNuovaDomanda(info,list, &nDomanda);
			goto home;
			break;
	   case 2:
		     printf("Stampa tutte le domande\n");
		     clear();
		     if(list != NULL)
	 		   listPrint2(list);
			 else 
			   printf("Nessun elemento presente\n");
			goto home;
			break;
		case 3:
			 printf("Stampa tutte le domande e la risposta\n");
			 clear();
				if(list != NULL)
				listPrint(list);
				else 
					printf("Nessun elemento presente\n");
			goto home;
			break;
		case 4:
			 printf("1	inserisci nei preferiti\n2	visualizza preferiti\n");
			 scanf("%d", &subMenuPreferiti);

		switch(subMenuPreferiti){
				
				case 1:
				clear();
					printf("Inserisci il numero della domanda da salvare nei preferiti\n");
					scanf("%d",&cerca.numDomanda);
		    		preferiti  = listCopy(list, preferiti, cerca);
					printf("Inserito nei preferiti\n");
				    goto home;
						break;

				case 2:
					clear();
					printf("I miei preferiti\n");
					listPrint(preferiti);
					getchar();
					getchar();
					goto home;
						break;

				default:
					goto home;
				};
		case 5:
			 clear();
			 printf("	Modifica:\n");
		
			 printf("1	Elimina una domanda\n"
				"2	Elimina una risposta\n"
				"3	Modifica domanda\n"
				"4	Modifica risposta\n"
				"5	Elimina domanda e risposta\n");
			 scanf("%d", &subMenuModifica);

		switch(subMenuModifica){
		
			case 1:
				if(list != NULL)
		       	listPrint(list);
	        	else 
			    printf("Nessun elemento presente\n");
				printf("Inserisci il numero della domanda da eliminare:\n");
				scanf("%d",&cerca.numDomanda);
				list =eliminaDomanda(list, cerca);
				clear();
				goto home;	
			case 2:
				if(list != NULL)
		       	listPrint(list);
	        	else 
			    printf("Nessun elemento presente\n");
			   	printf("Inserisci il numero della risposta da eliminare:\n");
				scanf("%d",&cerca.numDomanda);
		        list = eliminaRisposta(list, cerca);
					getchar();
					getchar();
				clear();
				goto home;
			case 3:
				if(list != NULL)
		       	listPrint(list);
	        	else 
			    printf("Nessun elemento presente\n");
				printf("Inserisci il numero della domanda da modificare\n");
				scanf("%d",&cerca.numDomanda);
				list = modificaDomanda(list,cerca);
			 	getchar();		
			     	clear();
				goto home;
			case 4: 
				if(list != NULL)
		       	listPrint(list);
	        	else 
			    printf("Nessun elemento presente\n");
				printf("Inserisci il numero della risposta da modificare\n");
					scanf("%d",&cerca.numDomanda);
					list = modificaRisposta(list,cerca);

			
				clear();
				goto home;

			case 5:
				if(list != NULL)
		       	listPrint(list);
	        	else 
			    printf("Nessun elemento presente\n");
				printf("Inserisci il numero della domanda/risposta da eliminare\n");
				scanf("%d", &cerca.numDomanda);
				list = listDelete(list, cerca);
				printf("Eliminiazione riuscita\n");
				getchar();
			
				goto home;
			default:
				clear();
				goto home;
		};
	
	        case 6: 
			    // conteggio = 
			     randomQuiz(list,nDomanda);
	     
			    	getchar();
			    goto home;
		    	break;
       	case 7: 
  				cercaDomanda(list, cerca);
	         	goto home;
	         	break;
     	case 8:
		       break;

     	default:
	     	printf("error\n");
	
		    goto home;
};


}


