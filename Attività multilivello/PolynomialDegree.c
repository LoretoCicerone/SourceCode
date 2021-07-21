/*
* Dato un polinomio a coefficienti interi rappresentato come array di monomi, restituirne il grado massimo.
* Il polinomio è rappresentato, come suggerito mediante un array di strutture, in cui la singola struttura rappresenta
* un monomio.
*/

#include<stdio.h>
#include<stdlib.h>

//Struttura "monomial", la quale raprresenta il un monomio.
struct monomial{
 int coeff;
 int exp;
};

// funzione "maxDegree" per calcolare il massimo grado del polinomio inserito.
int maxDegree(struct monomial polynomial[], int limit){
 int max_degree = polynomial[0].exp;
 int j;
 for(j=1;j<limit;j++){
     if(max_degree < polynomial[j].exp)
     {
         max_degree = polynomial[j].exp;
     }
 }
 return max_degree;
}

int main(){

   int limit,i;

   struct monomial polynomial [limit]; //array di strutture "monomial"

   //Inizio fase di inserimento
   printf("Di quanti elementi vuoi che sia formato il polinomio?\n");
   scanf("%d",&limit);
   printf("\nInserisci le singole parti del polinomio \n");
   for(i=0;i<limit;i++)
   {
     printf("Inserisci il coefficiente:\n");
     scanf("%d", &polynomial[i].coeff);
     printf("Inserisci il grado di x per il coefficiente inserito:\n");
     scanf("%d", &polynomial[i].exp);
   }
   //Termine fase di inserimento.

   printf("\nIl polinomio inserito e' dunque: \n");

   for(i=0; i<limit; i++)
   {
    printf("%dx^%d +/- ", polynomial[i].coeff, polynomial[i].exp); //Rappresentazione del polinomio
   }

   printf("\ne ha grado: %d\n", maxDegree(polynomial,limit));
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