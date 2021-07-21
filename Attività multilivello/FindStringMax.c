/*
* Dato un array di stringhe, trovare quella massima tra queste.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char* findmax(char array[][100], int limit)
{
  int j;
  const char* current_max = array[0];
  
  for(j=1;j<limit;j++)
  {
    if(strlen(current_max) < strlen((const char*) array[j]))
    {
        current_max = (const char*) array[j];
    }

  }
  return current_max;

}

int main()
{
     char array[10][100];
     int limit,i;

     //Inizio fase di inserimento nell'array
     printf("Quante stringhe vuoi che contenga l'array? \n");
     scanf("%d",&limit);
     printf("Inserisci: \n",limit);
     for(i=0;i<limit;i++)
     {
          scanf("%s",&array[i]);
     }
     //Fine fase di inserimento nell'array

     printf("\n La stringa massima all'interno dell'array e' : %s \n \n", findmax(array,limit));
     system("pause");
     return 0;

}


/*

Testcases in Json format:

{
    "amount": 10,
    "test_cases": [{
        "id": "0",
        "input": " {"ciao", "hello", "hi"} ",
        "expected": "hello"},
        {
        "id": "1",
        "input": " {"Programming", "in", "C", "and", "Java"} ",
        "expected": "Programming"},
     	{
        "id": "2",
        "input": " { "Abstraction", "Modularity", "Thinking"} ",
        "expected": "Abstraction"},
     	{
        "id": "3",
        "input": "{ "Advanced", "skills", "Abstract", "Soft" }",
        "expected": "Advanced"},
     	{
        "id": "4",
        "input": "{"News", "Nothing", "Computer" } ",
        "expected": "Computer"},
     	{
        "id": "5",
        "input": " {"ASM", "C", "Java", "Read"} ",
        "expected": "Java"},
     	{
        "id": "6",
        "input": "{"Array", "Pointers"}",
        "expected": "Pointers"},
     	{
        "id": "7",
        "input": "{"Array", "Pointers", "Structures", "Types"}",
        "expected": "Structures"},
     	{
        "id": "8",
        "input": " { "Thinking", "in", "Java" } ",
        "expected": "Java"},
     	{
        "id": "9",
        "input": "{ "High", "Level", "of", "Abstraction" }",
        "expected": "Abstraction"}
    ]
}

*/