/*
* Esempio di implementazione delle LinkedList. In particolare, vengono rappresentati i metodi
* fondamentali di accesso e manipolazione dei dati (inserimento, modifica, cancellazione e ricerca).
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
* Per prima cosa rappresentiamo un nodo
* Esso è rappresentato come un dato (ad esempio un intero)
* ed un puntatore al nodo successivo
*/                                
                      
                                
struct node{                    
    int value; //value è un intero, e rappresenta il valore contenuto nel nodo corrente
    struct node *next; //next è un puntatore, e punta sempre all'elemento successivo della lista, in modo tale che questa non rimanga scollegata
};

//Operazioni di manipolazione fondamentali sulle liste:
/*
* Inserimento;
* Cancellazione;
* Ricerca;
* Modifica;
*/

//METODI DI INSERIMENTO

//Aggiungere un nodo in testa alla lista
void addFirst(struct node** head_ref, int new_data)
{
    //Allocazione del nodo
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
  
    //Il nuovo valore di value per il nodo creato è "new_data"
    new_node->value  = new_data;
  
    //Ora "new_node" va in testa alla lista
    new_node->next = (*head_ref);
  
    //Ora "head" punta a "new_node" in testa alla lista
    (*head_ref) = new_node;
}

//Aggiungere un nodo in coda alla lista
void addLast(struct node** head_ref, int new_data)
{
    //Allocazione del nodo
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    //last è il puntatore scelto per scorrere la lista
    struct node *last = *head_ref; 
  
    //Popola "new_node"
    new_node->value  = new_data;

    new_node->next = NULL;
 
    //Se il puntatore in testa è NULL, allora la lista è vuota
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
        return;
    } 
    else 
    {
    //Se la lista non è vuota, allora scorri la lista fino a quando non trovi l'ultimo puntatore "NULL", quindi l'ultimo della lista
    while (last->next != NULL)
    {
        last = last->next;
    }
    //Appena si arriva alla fine,  inserisci il nuovo nodo in coda
    last->next = new_node;
    return;   
    }
      
  
}

//METODO DI RICERCA ALL'INTERNO DI UNA LISTA

//Ricerca all'interno di una lista concatenata
int search(struct node **head, int val)
{
    //parto, come sempre, dal nodo di testa
    struct node *pointer = *head;

    //scorro lista fino alla fine
    while(pointer!=NULL) 
    {
        if(pointer->value == val)
        {
            printf("E' stato trovato l'elemento desiderato: %d\n", pointer->value);
            return 1;
        }
        pointer=pointer->next; //pointer punta sempre all'elemento successivo
    }
    printf("Non e' stato trovato l'elemento desiderato.\n");
    return 0;
}

//METODO DI MODIFICA DEL VALORE DI UN CERTO NODO

//Supponiamo di voler modificare un certo valore all'interno di un nodo ad una certa posizione
void modify_nodevalue(struct node **head, int val, int position)
{
    struct node *pointer = *head;
    

    //scorro la lista appoggiandomi su un indice i che mi identifica la posizione desiderata
    for(int i = 0; pointer!=NULL; i++, pointer=pointer->next)
    {
         if(i==position)
         {
         pointer->value=val;
         }
    }

}

//METODI DI CANCELLAZIONE

//Eliminare il primo nodo da una lista concatenata
void remove_first(struct node **head_ref)
{
    struct node *toDelete = *head_ref;
    *head_ref = toDelete->next;
    free(toDelete);  
}

void deleteLast(struct node *head_ref)
{
    struct node *toDelete;
    toDelete = head_ref->next;

    //Scorro la lista fino a quando non trovo un puntatore NULL (che sarà quindi l'ultimo della lista, 
    //che non può puntare a nessun elemento successivo)
    while(toDelete->next != NULL)
    {
        head_ref = toDelete;
        toDelete = toDelete->next;
    }
    free(head_ref->next);
    head_ref->next = NULL;
}



//Rimuovi un nodo ad una certa posizione
  void deleteNode(struct node **head_ref, int position)
{

   //Parto dalla posizione di testa
   struct node* temp = *head_ref;
 
    //Se il nodo da rimuovere si trova in posizione 0, allora temp diventa il nuovo nodo in testa
    if (position == 0)
    {
        *head_ref = temp->next;   
        free(temp);               
        return;
    }
 
    //Scorro la lista fino a quando non trovo l'elemento in posizione "position"
    for (int i=0; temp!=NULL && i<position-1; i++)
    {
         temp = temp->next; //temp->next è il nodo da eliminare
    }
 
    //ora il puntatore "new" punta l'elemento puntato da temp->next, il nodo da eliminare
    struct node *new = temp->next->next;
 
    free(temp->next); 
    temp->next = new;  
} 

//Stampa la lista
void printList(struct node *node)
{
    //scorro la lista fino alla fine
    while (node != NULL) 
    {
        printf(" %d ", node->value);
        //faccio puntare "node" sempre all'elemento successivo
        node = node->next;
    }
}

int main()
{
  struct node* first = NULL;
  int trovato;

  //Aggiungo elementi alla lista
  addLast(&first, 6);
 
 
  addFirst(&first, 7);
 
  
  addFirst(&first, 1);
 

  addLast(&first, 4);

  printf("\n Stampo la lista...: \n ");
  printList(first);

  deleteNode(&first, 2);
  printf("\n Stampo la lista dopo aver eliminato l'elemento in posizione 2: \n");
  printList(first);

  remove_first(&first);
  printf("\n Stampo la lista dopo aver eliminato il primo elemento: \n");
  printList(first);

  //Aggiungo elementi alla lista
  addLast(&first, 6);
  addFirst(&first, 7);
  addFirst(&first, 1);
  addLast(&first, 4);
  
  printf("\n Stampo la lista...: \n ");
  printList(first);

  deleteLast(first);
  printf("\n Stampo la lista dopo aver eliminato l'ultimo elemento: \n");
  printList(first);


  trovato = search (&first, 4);
  printf("\nL'esito della ricerca e' (1 se e' stato trovato l'elemento desiderato, 0 altrimenti.): %d\n", trovato);

  modify_nodevalue(&first, 3, 3);
  printf("\n Stampo la lista dopo aver modificato l'elemento in posizione 3 (indice 3): \n");
  printList(first);

  system("pause");
  return 0;

}
