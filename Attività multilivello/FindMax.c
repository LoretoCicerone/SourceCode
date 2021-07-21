/*
* Dato un array di numeri interi, trovare il massimo tra questi.
*/

#include<stdio.h>
#include<stdlib.h>

//Un parallelo con Java:
/*
* L'implementazione della funzione "findmax", per trovare il massimo all'intero di un array
* è sostanzialmente identica anche nel caso di Java. Nello specifico, supponiamo di aver creato una classe "Max"
* e di aver creato il seguente metodo al suo interno:

* public int getmax(int[]array)
    {
        int current_max = array[0];
        for(int i=0; i<array.length;i++)
        {
            if(current_max < array[i])
            {
                current_max = array[i];
            }
        }
        return current_max;
    }
*
* Si può notare che l'implementazione è molto simile a quella sottostante.
*/

//Funzione "findmax" con la quale trovo il massimo all'interno dell'array.

int findmax (int array[], int limit)
{
  //j rappresenta l'indice di scorrimento dell'array.
  //current_max rappresenta l'intero corrente ad ogni iterazione.
  int j, current_max;

  current_max = array[0]; //ora current_max è l'elemento in posizione 0


  for(j=1;j<limit; j++)
  {
    if(current_max < array[j]) //confronto il massimo corrente con l'elemento in posizione j-esima
    {
        current_max = array[j];
    }

  }
  return current_max;
}

int main()
{
     int array[10],limit,i;

     //Inizio fase di inserimento degli interi nell'array
     printf("Quanti interi vuoi che contenga l'array? \n");
     scanf("%d",&limit);
     printf("Inserisci: \n",limit);
     for(i=0;i<limit;i++)
     {
          scanf("%d",&array[i]);
     }
     //Fine fase di inserimento degli interi nell'array

     printf("\n Il massimo degli interi all'interno dell'array e': %d \n \n", findmax(array,limit));
     system("pause");
     return 0;

}

/*

Testcases in Json format:

{
    "amount": 10,
    "test_cases": [{
        "id": "0",
        "input": "2 7 8 13 15 17 20",
        "expected": "20"},
        {
        "id": "1",
        "input": "1 23 25 26 13 19 14",
        "expected": "26"},
     	{
        "id": "2",
        "input": "4 8 12 16 20 24",
        "expected": "24"},
     	{
        "id": "3",
        "input": "5 13 15 17 23 33 45",
        "expected": "45"},
     	{
        "id": "4",
        "input": "2 8 6 11 47 55",
        "expected": "55"},
     	{
        "id": "5",
        "input": "3 6 9 12 15 18 21",
        "expected": "21"},
     	{
        "id": "6",
        "input": "2 1 8",
        "expected": "8"},
     	{
        "id": "7",
        "input": "9 18 27 36 78",
        "expected": "78"},
     	{
        "id": "8",
        "input": "1 2 3 4 5 6 7 8 9 10",
        "expected": "10"},
     	{
        "id": "9",
        "input": "23 49 56 99 101 105",
        "expected": "105"}
    ]
}

*/