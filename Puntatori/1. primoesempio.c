/*
* Dichiarazione di un intero e di un puntatore. Assegna un valore all'intero 
* e vedi il valore del puntatore. Dichiarazione di un nuovo puntatore e assegnamento
* del valore del vecchio puntatore a quello nuovo.
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int *p = &i;
    int *q;

    printf("%d\n", *p); /*Undefined behavior. SBAGLIATO!*/

    i=1;

    printf("Valore di *p dopo aver assegnato 1 ad i: %d\n", *p); /* Stampa 1 */
    printf("Valore di i dopo aver assegnato 1 ad i: %d\n", i);  /* Stampa 1 */

    *p=2;

    printf("il valore di *p dopo aver assegnato 2: %d\n", *p); /* Stampa 2 */
    printf("il valore di i dopo aver assegnato 2 a *p: %d\n", i);  /* Stampa 2 */

    q=p;

    printf("il valore di *q dopo aver assegnato q=p è: %d\n", *q);

    system("pause");
    return 0;


}