#include "TInfo.h"


/*FUNZIONI PER IL TIPO DI DATO*/
int infoEqual(TInfo info1, TInfo info2){
	return info1.numDomanda == info2.numDomanda;
}
int infoLess(TInfo info1, TInfo info2){
		return info1.numDomanda < info2.numDomanda;
}
int infoGreater(TInfo info1, TInfo info2){
		return info1.numDomanda > info2.numDomanda;
}
void infoPrint(TInfo info1){
	printf("DOMANDA ");
	printf("%d:",info1.numDomanda);
	printf("%s ",info1.domanda);
	printf("\n");

	
}

void infoPrint2(TInfo info1){
	printf("RISPOSTA %d: ",info1.numDomanda);
	printf("%s ",info1.risposta);
	printf("\n");
	
}



/*FUNZIONI PER LE LISTE*/
TNode *nodeCreate(TInfo info){
	TNode *new = malloc(sizeof(TNode));
	if(new != NULL){
		new->info = info;
		new->link = NULL;
	}
	return new;
}
void nodeDestroy(TNode* node){
	free(node);
}
TList listCreate(void){
	return NULL;
}
TList listDestroy(TList list){
	TNode *node;
	while(list != NULL){
		node = list;
		list = list->link;
		nodeDestroy(node);
	}
	return list;
}
void listPrint(TList list){
	if(list != NULL ){
		infoPrint(list->info);
		infoPrint2(list->info);
		listPrint(list->link);
		}else
			printf("\n");
		
}

void listPrint2(TList list){
		if(list != NULL ){
		infoPrint(list->info);
		listPrint2(list->link);
		}else
			printf("\n");
		
}

TNode *listSearch(TList list, TInfo info){
	if (list == NULL)
		return NULL;
	if(infoEqual(list->info, info))
		return list;
	return listSearch(list->link, info);
}

TList listInsert(TList list, TInfo info){
	if(list == NULL ){
		TNode *node = nodeCreate(info);
		assert(node != NULL);
        node->link = list;
     	return node;
	}
	list->link = listInsert(list->link, info);
	return list;
}
TList listDelete(TList list, TInfo info){
	 if(list == NULL || infoGreater(list->info, info))
        return list;
    if(infoEqual(list->info, info)){
        TList App = list->link;
    nodeDestroy(list);
        return App;
    }
    list->link = listDelete(list->link, info);
    return list;
}


/*
*FUNZIONI DI UTILIZZO 
*/

TList eliminaRisposta(TList list, TInfo info){

	if(list == NULL || infoGreater(list->info, info))
		return list;
	if(infoEqual(list->info, info)){
	
	for(int i = 0; i<DIM_DOMANDA;i++){
	list->info.risposta[i] = '\0';
	 }
	}
	list->link = eliminaRisposta(list->link, info);
	return list;
}

TList eliminaDomanda(TList list, TInfo info){
	
	if(list == NULL || infoGreater(list->info, info))
		return list;
	if(infoEqual(list->info, info)){
	
	for(int i = 0; i<DIM_DOMANDA;i++){
	list->info.domanda[i] = '\0';
	 }
	}
	list->link = eliminaDomanda(list->link, info);
	return list;
}

TList modificaDomanda(TList list, TInfo info){
	if(list == NULL || infoGreater(list->info, info))
	     return list;
	if(infoEqual(list->info, info)){
		printf("Inserisci la nuova domanda\n");
		getchar();
		fgets(list->info.domanda, DIM_DOMANDA, stdin);
		printf("Domanda modificata\n");
	}
	list->link = modificaDomanda(list->link, info);
	return list;
}

TList modificaRisposta(TList list, TInfo info){
	if(list == NULL || infoGreater(list->info, info))
	     return list;
	if(infoEqual(list->info, info)){
		printf("Inserisci la nuova risposta\n");
		getchar();
		fgets(list->info.risposta, DIM_DOMANDA, stdin);
		printf("Risposta modificata\n");
	}
	list->link = modificaRisposta(list->link, info);
	return list;
}
void cercaDomanda(TList list, TInfo cerca ){
TNode *nodeCerca;
		printf("Inserisci il numero della domanda:\n");
		scanf("%d", &cerca.numDomanda);
		nodeCerca = listSearch(list, cerca);
		clear();
		if(nodeCerca != NULL){
			printf("Domanda %d: %s ",nodeCerca->info.numDomanda,nodeCerca->info.domanda);
			printf("\n\n");
			printf("Risposta %d: %s ",nodeCerca->info.numDomanda, nodeCerca->info.risposta);
		}	else
			printf("errore\n");
			printf("\n");
		getchar();
		getchar();
	
}


TList listCopy(TList list1, TList list2, TInfo info){
	if(list1 == NULL)
		return NULL;
	if(infoEqual(list1->info, info)){
	
		list2 = listInsert(list2, list1->info);
	}else{
	return listCopy(list1->link, list2,info);
}
	 return list2;
}

/*
int randomQuiz(TList list, int nDomanda){
	TNode *nodeCerca;
	TInfo i;
	int conteggio = 0;
		getchar();
		fflush(stdin);

	for(int h = 0; h<4;h++){
     	i.numDomanda = rand() % nDomanda +1;
        nodeCerca = listSearch(list, i);
			if(nodeCerca != NULL){
				printf("Rispondi alla domanda %d: %s ",nodeCerca->info.numDomanda,nodeCerca->info.domanda);
				printf("\n");
			  }else
				printf("errore\n");

		     	printf("\n");
		 	if (verificaRisposta(nodeCerca)== 1)
						conteggio++;
					}
		return conteggio;
}
*/
void randomQuiz(TList list, int nDomanda){
	TNode *nodeCerca;
	TInfo i;
	int rCorrette = 0;
		getchar();
		fflush(stdin);

	for(int h = 0; h<4;h++){
     	i.numDomanda = rand() % nDomanda +1;
        nodeCerca = listSearch(list, i);
			if(nodeCerca != NULL){
				printf("Rispondi alla domanda %d: %s ",nodeCerca->info.numDomanda,nodeCerca->info.domanda);
				printf("\n");
			  }else
				printf("errore\n");

		     	printf("\n");

		 	verificaRisposta(nodeCerca,&rCorrette);
		
					}
					printf("Risposte corrette: %d\n",rCorrette);
					
	
}


void verificaRisposta(TNode *node, int *risposteCorrette){ //AGGIUNGO int *risposteCorrette

	TInfo rispostaUtente;
	scanf("%s",rispostaUtente.risposta);
    if(strcmp(rispostaUtente.risposta, node->info.risposta)==0){
			printf("Risposta corretta!\n");
			*risposteCorrette = *risposteCorrette +1;
		}else
			printf("Sbagliato!\nLa risposta corretta è: %s \n", node->info.risposta);

}
/*	
int verificaRisposta(TNode *node){ //AGGIUNGO int *risposteCorrette
	int corretto = 0;
	TInfo rispostaUtente;
	scanf("%s",rispostaUtente.risposta);
    if(strcmp(rispostaUtente.risposta, node->info.risposta)==0){
			printf("Risposta corretta!\n");
			corretto = 1;
		}else
			printf("Sbagliato!\nLa risposta corretta è: %s \n", node->info.risposta);
	return corretto;
}
*/
	

void inserisciNuovaDomanda(TInfo info, TList list,int *nDomanda){
	 
		clear();
	    printf("Inserisci una nuova domanda:\n");
		getchar();
       
		info.numDomanda = *nDomanda+=1;
        printf("Domanda numero = %d\n", *nDomanda);
		fgets(info.domanda, DIM_DOMANDA, stdin);
		printf("Inserisci la risposta:\n");
		fgets(info.risposta, DIM_DOMANDA, stdin);
		list = 	listInsert(list, info);

		clear();

		if(list!= NULL){
			printf("Inserimento riuscito\n");
		}else 
			printf("Errore nell'inserimento\n");
			printf("premi invio\n");
			getchar();
			clear();
}


