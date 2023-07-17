Quiz a risposta multipla.

tipo di dato:

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


/*FUNZIONI PER LE LISTE*/

TNode *nodeCreate(TInfo); //crea un nodo
void nodeDestroy(TNode*); //elimina un nodo
TList listCreate(void);  //crea lista allocando la memoria necessaria
TList listDestroy(TList);  //elimina la lista
void listPrint(TList);    //stampa la lista
void listPrint2(TList);
TNode *listSearch(TList, TInfo); //ricerca un elemento nella lista ricorsivamente
TList listInsert(TList, TInfo);  //inserisce un elemento nella lista
TList listDelete(TList, TInfo);  //elimina un elemento dalla lista


/*FUNZIONI DI UTILIZZO*/

TList eliminaRisposta(TList, TInfo);  
TList eliminaDomanda(TList, TInfo);
TList modificaDomanda(TList, TInfo);
TList modificaRisposta(TList, TInfo);

void randomQuiz(TList,int );
void verificaRisposta(TNode*, int*);


TList riordinoIndici(TList, TInfo);

TList listCopy(TList list1, TList list2, TInfo info);
void cercaDomanda(TList list, TInfo cerca );
