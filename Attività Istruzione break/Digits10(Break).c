/*
*In questo caso, a differenza dell'altro esempio, si fa uso dell'istruzione break.
*In particolare, l'esempio prevede di trovare, dato un array di interi, un numero la cui somma delle sue singole cifre
*sia uguale a 10. Se viene trovato, allora il programma termina.
*/

#include <stdio.h>
#include <stdlib.h>



 int main()
{
    //"array" è il vettore in cui verranno inseriti gli interi.
    //"limit" è il limite di inserimento dato dall'utente.
    //"i" è un intero e viene utilizzato come indice di scorrimento.
    //"resto" è il risultato della funzione modulo.
    //"trovato" funge da variabile booleana e varrà 1 se l'intero la cui somma delle cifre è uguale a 10 viene trovato
    //"somma" è il risultato della somma delle cifre.
    int array[10],limit,i=0,resto=0;
    int trovato = 0;
    int somma = 0;


    //Inserimento degli interi all'intero dell'array.
    printf("Quanti interi vuoi che contenga l'array?");
    scanf("%d",&limit);
    printf("Inserisci:",limit);

     for(i=0;i<limit;i++)
     {
          scanf("%d",&array[i]);
          
     }
     //Termine fase di inserimento.


    /*
    * A differenza dell'altro esempio, il ciclo for più esterno ed il ciclo while non prevedono un controllo sulla variabile "trovato"
    * e somma, rispettivamente. Di conseguenza ho una serie di if a cascata per verificare il valore delle variabili
    * "trovato" e "somma" che rendono il codice ridondante e ripetitivo.
    */

     for(i=0;i<limit;i++)
     {
     //Ad ogni iterazione la variabile somma viene posta a 0.
        somma = 0;

        while(array[i] != 0)

        {
               resto = array[i] % 10; 
               somma += resto;
               array[i] = array[i] / 10;

               if(somma == 10)
               {
                   trovato = 1;
                   break;
                   //esco dal ciclo while
               }
        }
          
          //Se sono uscito dal ciclo while per via del break al suo interno, allora il programma termina.
           if(trovato == 1)
          { 
            printf("trovato!");
             break;
             //esco dal ciclo for
          }
          
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
        "input": "44 55 10 90",
        "expected": "1"},
        {
        "id": "1",
        "input": "10 20 30 45 65",
        "expected": "0"},
     	{
        "id": "2",
        "input": "703 844 508 124",
        "expected": "1"},
     	{
        "id": "3",
        "input": "5 13 15 17 23 33 45",
        "expected": "0"},
     	{
        "id": "4",
        "input": "2 8 6 11 47 55",
        "expected": "1"},
     	{
        "id": "5",
        "input": "22 303 505",
        "expected": "1"},
     	{
        "id": "6",
        "input": "307 10 44 68",
        "expected": "1"},
     	{
        "id": "7",
        "input": "450 90 10 33",
        "expected": "0"},
     	{
        "id": "8",
        "input": "100 101 410 455",
        "expected": "0"},
     	{
        "id": "9",
        "input": "909 910 330 503",
        "expected": "1"}
    ]
}

*/
