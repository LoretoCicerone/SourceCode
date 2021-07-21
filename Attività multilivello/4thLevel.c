/*
*Inserire il parametro puntatore a funzione per effettuare il confronto tra coppie di elementi. 
*A tal proposito, è necessario che tutti gli elementi dell’array siano dei puntatori.
*/

#include<stdio.h>
#include<stdlib.h>

//Struttura "monomial", la quale raprresenta un monomio.
struct monomial{
 int coeff;
 int exp;
};

// funzione "maxDegree" per calcolare il massimo grado del polinomio inserito.
int maxDegree(struct monomial **polynomial, int limit)
{
    //Definizione di "pointer_array", ossia un puntatore all'array "polynomial"
    struct monomial ***pointer_array = &polynomial;
    int max_degree = (*pointer_array)[0]->exp;
    for(int j=1; j<limit; j++)
    {
        if(max_degree < (*pointer_array)[j]->exp)
        {
            max_degree = (*pointer_array)[j]->exp;
        }

    }
    printf("%d",max_degree);
    return max_degree;
}


int main()
{
  int limit,i;

  //c ed e sono variabili di appoggio, 
  //e servono per inserire il valore di coefficiente ed esponente all'interno dell'array, rispettivamente;
  int c=0, e=0; 
  
  //Definizione di un puntatore a funzione
  int (*functionPtr)(struct monomial **,int);

  //assegnazione della funzione "maxDegree"
  functionPtr = &maxDegree;

  int max;

   printf("Di quanti elementi vuoi che sia formato il polinomio?\n");
   scanf("%d",&limit);

   //allocazione di un numero pari al valore di "limit" di puntatori
   struct monomial **polynomial = malloc(limit * sizeof(struct monomial *));

   for(i=0;i<limit;i++)
   {
     //allocazione di un numero pari al valore di "limit" di strutture "monomial", con l'array che punta ad esse
     polynomial[i] = malloc(sizeof(struct monomial));
   }
 
    //Fase di assegnamento
     for(i=0;i<limit;i++)
   {
     printf("Inserisci il coefficiente:\n");
     scanf("%d", &c);
     polynomial[i]->coeff = c;
     printf("Inserisci il grado di x per il coefficiente inserito:\n");
     scanf("%d", &e);
     polynomial[i]->exp = e;
   }

   printf("\nIl grado del polinomio inserito è: %d\n", max = (*functionPtr)(polynomial, limit));
  

  system("pause");
  return 0;
}

/*

Testcases in Json format:

{
    "amount": 10,
    "test_cases": [{
        "id": "0",
        "input": " x^2 + 5x^3 + 7x ",
        "expected": "3"},
        {
        "id": "1",
        "input": " 6x^2 + 4x ",
        "expected": "2"},
     	{
        "id": "2",
        "input": " 9x^4 + 7x^3 + 4x",
        "expected": "4"},
     	{
        "id": "3",
        "input": " 9x^5 - 7x^2 + 6x ",
        "expected": "5"},
     	{
        "id": "4",
        "input": " 4x^2 + 9x ",
        "expected": "2"},
     	{
        "id": "5",
        "input": " 3x^8 + 8x^4 + 16x ",
        "expected": "8"},
     	{
        "id": "6",
        "input": " 3x^2 + 9x + 8 ",
        "expected": "2"},
     	{
        "id": "7",
        "input": " 10x^3 + 9 ",
        "expected": "3"},
     	{
        "id": "8",
        "input": " 2x^2 + 7x + 3 ",
        "expected": "2"},
     	{
        "id": "9",
        "input": " 5x^6 + 4x^2 + 10 ",
        "expected": "6"}
    ]
}

*/

//Un parallelo con Java:

/*
* Dall'esempio appena presentato si può fare un parallelo con Java. Come sappiamo, Java non permette l'uso
* e la manipolazione dei puntatori. Nell'esempio proposto possiamo notare che tutti gli elementi dell'array
* sono puntatori. In Java, un array può essere visto come un vero e proprio oggetto. Quando, ad esempio, definiamo
* un'array di interi (int[]array), stiamo puntualizzando il fatto di aver introdotto un puntatore 
* all'oggetto array. Quelli che nel linguaggio C vengono chiamati puntatori, in Java 
* vegnono chiamati riferimenti. In effetti, tutti gli oggetti che definiamo in Java sono riferimenti, e sono molto simili 
* ai puntatori usati nel linguaggio C. Consideriamo il vettore "polynomial" definito nell'esempio: questo non è
* altro che un array i cui elementi sono dei puntatori. Se consideriamo un riferimento immediato con Java possiamo pensare
* ad una lista di oggetti. Ad esempio, possiamo immaginare di avere una lista di persone, in cui la singola persona
* (il singolo oggetto), contiene informazioni come nome, cognome, età, ecc..., esattamente come nel caso del vettore
* polynomial, in cui i singoli elementi sono puntatori a strutture "monomial".  
*/

