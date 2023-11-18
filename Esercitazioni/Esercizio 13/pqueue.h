// file PQueue.h


typedef struct c_PQ *PQueue;

// prototipi

PQueue newPQ(void);

int emptyPQ(PQueue q);

int getMax(PQueue q);

int deleteMax(PQueue q);

int insert (PQueue q, int key);


/*
L’ADT coda a priorità è realizzato in maniera semplificata.

Vengono inserite solo chiavi di tipo intero, senza valori associati

Gli operatori insert() e deleteMax() restituiscono un valore 0 se l’operazione fallisce, 1 se termina con successo*/
