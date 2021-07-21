//CON USO DELLA FUNZIONE BREAK.

//Inserisci manualmente un numero a piacimento di interi all'interno di un array.
//Durante la fase di scorrimento viene verificato se sono stati inseriti numeri primi.

#include<stdio.h>
#include <stdlib.h>
int main()
{
     //a è l'array in cui verranno inseriti gli interi inizialmente.
     //limit è il limite di inserimento dato dall'utente.
     //i e j sono le variabili utilizzate per lo scorrimento dell'array (indici).
     //In particolare j parte da 2 e non da 1 nel ciclo for più interno.
     //"primi" è l'array in cui verranno inseriti i numeri primi.
     //t è un intero con cui tengo traccia degli indici all'interno dell'array "primi".

     int array[10],limit,i,j,count=0,primi[10],t=0;

     //Inizio fase di inserimento
     printf("Quanti interi vuoi che contenga l'array? ");
     scanf("%d",&limit);
     printf("Inserisci:",limit);
     for(i=0;i<limit;i++)
     {
          scanf("%d",&array[i]);
     }
     //Termine fase di inserimento

     //Fase di scorrimento dell'array alla ricerca dei numeri primi.
     //count è una variabile che viene incrementata solo se si trovano numeri non primi.
     for(i=0;i<limit;i++)
     {
          count=0;
          for(j=2;j<array[i];j++)
          {
               if(array[i]%j==0)
               {
                   //in a[i] è presente un numero non primo? se si incremento count di 1 ed esco dal ciclo piu interno con BREAK.
                   //Inizializzo count di nuovo a 0 nel ciclo più esterno.
                    count=1;
                    break;
               }
          }
          //Se a[i] conteneva un numero non primo allora non ho incrementato count. Vado ad inserire tale numero all'interno di un array
          //"prime", di cui ne tengo traccia degli indici attraverso un indice t. 
          if(count==0)
          {
               primi[t]=array[i];
               t++;
          }
     }

     //TERMINE FASE DI SCORRIMENTO.


     printf("I numeri primi trovati sono i seguenti: ");
     for(i=0;i<t;i++)
     {
          printf(" %d ",primi[i]);
     }
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
        "expected": "2 7 13 17"},
        {
        "id": "1",
        "input": "1 23 25 26 13 19 14",
        "expected": "1 23 13 19"},
     	{
        "id": "2",
        "input": "4 8 12 16 20 24",
        "expected": " "},
     	{
        "id": "3",
        "input": "5 13 15 17 23 33 45",
        "expected": "5 13 17 23"},
     	{
        "id": "4",
        "input": "2 8 6 11 47 55",
        "expected": "2 11 47"},
     	{
        "id": "5",
        "input": "3 6 9 12 15 18 21",
        "expected": "3"},
     	{
        "id": "6",
        "input": "2 1 8",
        "expected": "2 1"},
     	{
        "id": "7",
        "input": "9 18 27 36 45",
        "expected": "9"},
     	{
        "id": "8",
        "input": "1 2 3 4 5 6 7 8 9 10",
        "expected": "1 2 3 5 7"},
     	{
        "id": "9",
        "input": "23 49 56 99 101 105",
        "expected": "23 49 101"}
    ]
}

*/