
#include<stdio.h>
#include<stdlib.h>

/*
* Tale funzione ha il semplice scopo di scambiare l'ordine dei numeri. Ho fatto notare come accedere ad una variabile 
* puntata void sia sinonimo di errore (Undefined Behavior).
*/
void function(int *x, void *y)
{

  printf("First parameter is : %d \n", *x); // Il primo argomento è : 10

  // printf("Second parameter is :", *y); //undefined Behavior! Si sta tentando di accedere una variabile puntata void

  printf("Second parameter is: %d \n", *(int*)y); //OK! E' necessario un cast. La variabile puntata y è stata convertita da void ad int (NON PERMANENTEMENTE!)

  int n;

  n=*x;

  //*x=*y; //ERRORE! Si sta tentando di assegnare un tipo void ad un tipo int.

  *x=*(int*)y; //OK! Anche in questo caso è necessario un cast.

  *(int*)y = n;

}


int main()
{
 int a = 10, b = 20;

 function(&a,&b); //vengono scambiati gli interi in a e b nella funzione "function"
 printf("a vale:  %d\n", a); //a vale : 20
 printf("b vale:  %d\n", b); //b vale : 10

 system("pause");
 return 0;
}

