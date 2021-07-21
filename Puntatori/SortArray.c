/*
* Esempio in cui vi è una funzione che accetta in input un array di interi oppure un array di decimali.
* Ordinare gli elementi all'interno dell'array in ordine crescente. 
*/

#include<stdlib.h>
#include<stdio.h>
#define SIZE 10 //Il numero di elementi di ogni array è 10


/*
* Funzione "sort" per ordinare gli elementi dell'array in ordine crescente.
* @ptr è un puntatore void in quanto, appunto, la funzione può accettare sia array di interi che di decimali.
* @SIZE è la dimensione dell'array
* @type è il tipo di array che viene passato alla funzione:
* 1- Interi;
* 2- Decimali;
*/
void sort (void *ptr, int size, int type)

{ //Begin-sort

    int i; //Indice per lo scorrimento dell'array.
    int j; //Indice per lo scorrimento dell'array

    int current_integer; //variabile che contiene l'intero più grande corrente dopo un confronto tra elementi successivi
    int *cast_integer = (int*)ptr; //cast_integer è la nuova variabile puntatore di tipo intero

    float current_float; //variabile che contiene il decimale più grande corrente dopo un confronto tra elementi successivi
    float *cast_float = (float*)ptr; //cast_float è la nuova variabile puntatore di tipo decimale

    switch(type)
    { //Begin-Switch

        case 1: //caso in cui l'array è un array di interi.
        
        for(i=0;i<SIZE;i++)

        { //Begin-for(index i)

            for(j=i+1; j<SIZE; j++)

            { //Begin-for(index j)

                if( *(cast_integer+i) > *(cast_integer+j ) )
                {
                   current_integer = *(cast_integer+i);
                   *(cast_integer+i) = *(cast_integer+j);
                   *(cast_integer+j) = current_integer;
                }

            } //End-for(index j)

        } //End-for(index i)

      for(i=0;i<SIZE;i++)
      {

	  printf("Elemento numero %d : %d \n",i+1,*(cast_integer+i));

	  }   
      break; //case 1
        
        case 2: //caso in cui l'array è un array di decimali.
        
        for(i=0;i<SIZE;i++)

        { //Begin-for(index i)

            for(j=i+1; j<SIZE; j++)

            { //Begin-for(index j)

                if( *(cast_float+i) > *(cast_float+j ) )
                {
                   current_float = *(cast_float+i);
                   *(cast_float+i) = *(cast_float+j);
                   *(cast_float+j) = current_float;
                }

            } //End-for(index j)  

        } //End-for(index i)

      for(i=0;i<SIZE;i++)
      {

	  printf("Elemento numero %d : %f \n",i+1,*(cast_float+i));

	  }   

      break; //case 2
    
    } //End-Switch

} //End-Sort

int main()
{

   int integer[SIZE] = {24, 50, 13, 64, 90, 2, 1, 15, 22, 44};
   float decimal[SIZE] = {10.4f, 11.3f, 2.4f, 1.1f, 90.8f, 92.0f, 32.4f, 55.4f, 21.3f, 92.1f};

   printf("\nElementi interi in ordine crescente: \n \n");
   sort(&integer, SIZE, 1);
   printf("\nElementi decimali in ordine crescente:\n \n");
   sort(&decimal, SIZE, 2);

   system("pause");
   return 0;

}