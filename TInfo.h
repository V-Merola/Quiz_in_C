#ifndef TINFO_H
#define TINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define clear() printf("\033[H\033[J")
#define DIM_DOMANDA 50


typedef struct {
	char domanda[DIM_DOMANDA];
	char risposta[DIM_DOMANDA];
	int numDomanda;
}TInfo;



struct SNode{
	TInfo info;
	struct SNode *link;
};
typedef struct SNode TNode;
typedef TNode *TList;

TInfo info;

/*FUNZIONI PER LE LISTE*/
TNode *nodeCreate(TInfo);
void nodeDestroy(TNode*);
TList listCreate(void);
TList listDestroy(TList);
void listPrint(TList);
void listPrint2(TList);
TNode *listSearch(TList, TInfo);
TList listInsert(TList, TInfo);
TList listDelete(TList, TInfo);

/*
*FUNZIONI DI UTILIZZO 
*/
TList eliminaRisposta(TList, TInfo);
TList eliminaDomanda(TList, TInfo);
TList modificaDomanda(TList, TInfo);
TList modificaRisposta(TList, TInfo);

void randomQuiz(TList,int );
void verificaRisposta(TNode*, int*);


TList riordinoIndici(TList, TInfo);

TList listCopy(TList list1, TList list2, TInfo info);
void cercaDomanda(TList list, TInfo cerca );



//funzioni del menu

void inserisciNuovaDomanda(TInfo info, TList list,int *nDomanda);

/*FUNZIONI PER IL TIPO DI DATO*/
int infoEqual(TInfo, TInfo);
int infoLess(TInfo, TInfo);
int infoGreater(TInfo, TInfo);

void infoPrint(TInfo);
void infoPrint2(TInfo);
#endif 
