/*
* Esempio di implementazione degli ArrayList. In particolare, vengono rappresentati i metodi
* fondamentali di accesso e manipolazione dei dati (inserimento, modifica, cancellazione e ricerca).
* A differenza delle linkedlist, gli arraylist hanno il vantaggio secondo il quale l'accesso ad un elemento 
* risulta molto più veloce. Infatti sono strutture dati basate su array, e quindi indicizzate.
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>

/*
* Per prima cosa andiamo a definire una struttura che rappresenti 
* l'ArrayList generico
*/                                                            
struct List{                    
    int size; //size rappresenta il numero degli elementi contenuti nell'arraylist
    int capacity; //capacity rappresenta la capacità di un ArrayList.
    void **items; //puntatore ad un generico elemento all'interno di un Arraylist.
};


/*
* L’istruzione typedef permette di definire degli alias a dei tipi di dato esistenti. 
* Non si definisce un nuovo tipo, ma si introduce un nome che corrisponde ad uno dei tipi definiti. 
* La sintassi è questa: typedef tipo nome_tipo. In questo caso viene usata per la struttura List creata
*/
typedef struct List List;

//Operazioni di manipolazione fondamentali sulle liste:
/*
* Inserimento;
* Cancellazione;
* Ricerca;
* Modifica;
*/

/*
* Dichiarazione di un ArrayList con una certa capacità iniziale.
*
*/
List* initiate(int initial_capacity) {
    //allocazione dello spazio di memoria per l'arraylist
    List* list = malloc(sizeof(List));
    //allocazione dello spazio di memoria per gli elementi che andranno a comporre l'arraylist
    list->items = malloc(sizeof(void*) * initial_capacity);
    //All'inizio l'arraylist sarà vuoto, per cui size = 0;
    list->size = 0;
    //Capacità iniziale passata come parametro.
    list->capacity = initial_capacity;
    return list;
}

List* create_list() {
    return initiate(16);
}

//Ogni volta che si deve inserire un elemento nell'arraylist, si realloca la memoria
//se questa non è sufficientemente grande.

int add(List* list, void* item) {
    int resized = 0;
    //ritorna "resized = 1" se l'arraylist è stato ridimensionato

    
    //controllo se gli elementi già all'interno dell'arraylist sono in un numero pari alla capacità
    //dell'arraylist stesso. Se si, crea un array più grande e copia gli elementi al suo interno.
    if (list->size == list->capacity) {
        //crea un array più grande grazie all'operazione "ceil", la quale mi restituisce l'intero 
        //immediatamente più grande dopo "capacity".
        int new_capacity = (int)ceil(list->capacity * 1.5);
        void** new_array = malloc(sizeof(void*) * new_capacity);
        
        //copia i vecchi elementi nel nuovo array
        for (int i = 0; i < list->size; ++i) {
            new_array[i] = list->items[i];
        }
        
        //Deallocazione del vecchio spazio di memoria.
         free(list->items);
        list->items = new_array;
        list->capacity = new_capacity;
        resized = 1;
    }
 
    list->items[list->size] = item;
    list->size++;
    return resized;
}

/*
* Ecco cosa differenzia gli arraylist dalle liste concatenate:
* In questa funzione viene passato come parametro un indice (index),
* che indica proprio la posizione in cui "item" sarà inserito. Questa operazione avviene in tempo costante
* a differenza delle LinkedList.
* Questo ha come cnseguenza lo spostamento degli altri elementi verso destra o verso sinistra per
* fargli spazio
*/
int insert(List* list, int index, int * item) {
    if (0 > index || index >= list->size) {
        return 0;
    }
 
    //Richiamo la funzione creata precedentemente per vedere se ho abbastanza spazio.
    add(list, NULL);
 
    //muovo tutti gli elementi a destra o a sinista per far spazio al nuovo elemento.
    for (int i = list->size - 2; i >= index; --i) {
        list->items[i + 1] = list->items[i];
    }
 
    //inserisci il nuovo elemento. Grazie all'indice questa operazione avviene in tempo costante.
    list->items[index] = item;
    return 1;
}

//Operazione di ricerca di un elemento
// Anche questa operazione avviene in tempo costante. La lista è indicizzata.
void* get(List* list, int index) {
    if (0 > index || index >= list->size) {
        return NULL;
    } else {
        return list->items[index];
    }
}

//Rimuovi un elemnto dalla lista.
void* delete(List* list, int index) {
    
    //Controllo che index non corrisponda ad un valore errato. Deve essere 
    //un valore che rispetta entrambi gli estremi dell'arraylist.
    if (0 > index || index >= list->size) {
        return NULL;
    }
 
    //Prendo l'elemento da eliminare. Faccio shift di conseguenza degli elementi rimanenti
    //Questa operazione di shift non è banale, se l'arraylist è composto di molti elementi
    //è un'operazione molto onerosa.
    void* removed_item = list->items[index];
    for (int i = index + 1; i < list->size; ++i) {
        list->items[i - 1] = list->items[i];
    }
    //riduci di 1 gli elementi rimanenti, uso l'aritmetica dei puntatori.
    --list->size;
    return removed_item;
}

int list_size(List* list) {
    return list->size;
}
//Svuotare la lista
void empty_list(List* list) {
    free(list->items);
}

int main() 
{
 //creo una nuova lista.
 
    printf("Inserisci 10 elementi\n");
    for (int i = 0; i < 10; ++i) { // infinite loops are undefined behavior
        int* new_item = malloc(sizeof(int));
        printf("\n Insersici:");
        scanf("%d", new_item);
 
        if (*new_item == 0) {
            free(new_item);
            break;
        } else if (add(list, new_item)) {
            printf("array has been resized.\n");
        }
    }

    //Stampo a video effettuando una ricerca
    for (int i = 0; i < list_size(list); i++) {
        printf("list[%d] = %d\n", i, *((int*)get(list, i)));
    }
    
    delete(list,4);
    printf("\n dopo aver eliminato l'elemento in posizione 4 nella lista...\n");
     for (int i = 0; i < list_size(list); i++) {
        printf("list[%d] = %d\n", i, *((int*)get(list, i)));
    }
    system("pause");
    return 0;
}


