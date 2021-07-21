/*
* Attività 5a:
* 1) Uso degli array per allocare una sequenza di interi forniti da terminale:
*
* In questo esempio si fa un uso esplicito delle funzioni "malloc" e "realloc".
* In particolare, dati una sequenza di interi forniti da terminale, e messi all'interno di un array allocato dinamicamente
* con la funzione "malloc", si vuole ordinare in ordine crescente tali elementi. Deve essere possibile inserire ulteriori elementi
* dinamicamente. A tal proposito, si utilizza la funzione "realloc" per allocare un ulteriore spazio di memoria, nel caso in cui quello
* allocato precedentemente sia insufficiente.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    //"pointer" punterà all'indirizzo di base del blocco che andremo a creare
    int *pointer;

    //"old_limit" e "limit" rappresentano, rispettivamente, la lunghezza dell'array alla sua creazione
    //e quando e dopo averne aggiunto elementi in più
    int old_limit, limit;

    //"i" e "j" rappresentano i soliti indici di scorrimento dell'array
    int i,j;
    
    //"current" è la variabile di appoggio per l'operazione di ordinamento
    int current;

    //"integer" è la variabile con cui vado a riempire l'array
    int integer;

    //"array_length" è il risultato della somma tra "old_limit" e "limit" (vedi sopra)
    int array_length;
    
    //"cont" è una semplice variabile che serve per decidere se si vuole continuare ad inserire elementi dinamicamente o meno.
    char cont;
    
    printf("Inserisci il numero degli elementi:\n");
    scanf("%d", &old_limit);

    //Allocazione dinamica della memoria utilizzando la funzione "malloc", con a dimensione specificata "limit".
    pointer=(int*)malloc(old_limit * sizeof(int));
    
    printf("\nInserisci gli interi all'interno dell'array\n");

    for(i=0;i<old_limit;i++)
    {
      printf("Inserisci: ");
      scanf("%d", &integer);
      pointer[i] = integer;
    }

    //Inizio fase di ordinamento dell'array
    for(i=0;i<old_limit;i++)
    {

      for(j=i+1;j<old_limit;j++)
      {

        if(pointer[i] > pointer[j])
        {

          current = pointer[i];
          pointer[i] = pointer[j];
          pointer[j] = current;

        }
 
      }

    }
    //Fine fase di ordinamento dell'array

    printf("Gli elementi dell'array dopo l'ordinamento...: ");
    for (i = 0; i < old_limit; i++) 
    {
    printf("%d, ", pointer[i]); 
    }

    //Se si decide di aggiungere ulteriori elementi, allora, come suggerito, si sceglie y (yes), oppure n(no).
    printf("\nVuoi inserire altri numeri? (y/n)");
    scanf(" %c", &cont);

    while(cont == 'y')
    {
      printf("\nInserisci il numero degli elementi in aggiunta a quelli gia' inseriti:\n");
      scanf("%d", &limit);
      array_length=limit+old_limit;
      
      //Si è scelto di aggiungere ulteriori elementi, allora si usa la funzione "realloc". Se lo spazio utilizzato precedentemente con 
      //la funzione "malloc" risulta inseufficiente, allora la funzione realloc, rialloca, appunto, un ulteriore spazio di memoria in cui
      //è sempre il puntatore "pointer" a puntare ad essa.
      pointer = realloc(pointer, limit * sizeof(int));

      //Se si decide di continuare ad inserire elementi, allora l'indice i viene messo in corrispondenza dell'ultimo elemento inserito.
      for(i=old_limit;i<array_length;i++)
      {
        printf("Inserisci: ");
        scanf("%d", &integer);
        pointer[i] = integer;
      }
    
    //Inizio fase di ordinamento
    for(i=0;i<array_length;i++)
    {
      for(j=i+1;j<array_length;j++)
      {
        if(pointer[i] > pointer[j])
        {

          current = pointer[i];
          pointer[i] = pointer[j];
          pointer[j] = current;

        }
 
      }
    }
    //Fine fase di ordinamento

    printf("Gli elementi dell'array dopo l'ordinamento...: ");

    for (i = 0; i < array_length; i++) 
    {
    printf("%d, ", pointer[i]);
    }

    printf("\n Vuoi inserire altri numeri? (y/n)");
    scanf(" %c", &cont);
    
    //Ora assegno ad "old_limit" il nuovo valore di array_length, in modo tale che l'indice i riparta dall'ultimo elemento inserito.
    old_limit=array_length;
    }
  
  //Deallocazione della memoria attraverso il metodo "free", nel caso in cui si scelfa di non aggiungere elementi.
  free(pointer);
  system("pause");
  return 0;

}
