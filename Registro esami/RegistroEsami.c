/*
	LPS Example

	Registro Esami

	Language: C99
 	Style: plain C
 	Version: Ref-pc
 */

/*
	Original Plain C Code
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Studente {
	char *nome;
	unsigned int matricola;
	unsigned char voto;
	unsigned char numEsercizi;
};

/* 
	Dealloca un oggetto di tipo struct Studente precedentmente allocato.
	Il parametro è un puntatore all'oggetto da deallocare; può essere il null pointer,
	nel qual caso la funzione non fa nulla.
*/
void eliminaStudente( struct Studente *p )
{
	if ( p ) {
		free( p -> nome );
		free( p );
	}
	return;
}

void stampaComandi( void )
{
		printf( "Inserisci un comando:\n\n" );
		printf( "2: Annulla un esito\n" );
		printf( "1: Inserisci un nuovo esito\n" );
		printf( "0: Termina inserimento e stampa verbale\n" );	
}

int main( void )
{
	printf( "Registro Esami\n" );

	bool stampaVerbale = false;
	int comandoUtente;

	struct Studente *promosso1 = NULL, *promosso2 = NULL, *promosso3 = NULL;

	do {
		stampaComandi();

		scanf( "%d", &comandoUtente );

		if ( comandoUtente == 0 ) stampaVerbale = true;
		else if ( comandoUtente == 1 ) {
			printf( "Inserisci dati studente\n" );
			struct Studente *nuovoStudente = malloc( sizeof(struct Studente) );
			printf( "Nome (max. 100 caratteri): " );
			nuovoStudente -> nome = malloc( 100 );
			scanf( "%99s", nuovoStudente -> nome );
			printf( "Matricola: " );
			scanf( "%u", &nuovoStudente -> matricola );
			printf( "Voto: " );
			scanf( "%hhu", &nuovoStudente -> voto );
			printf( "Numero Esercizi Svolti: " );
			scanf( "%hhu", &nuovoStudente -> numEsercizi );

			/* 
				memorizza lo studente se è uno dei migliori 3
			*/
			if ( promosso1 == NULL ) promosso1 = nuovoStudente;
			else if ( promosso1 -> voto < nuovoStudente -> voto ||
					( promosso1 -> voto == nuovoStudente -> voto &&
					promosso1 -> numEsercizi < nuovoStudente -> numEsercizi)
				) {
					eliminaStudente( promosso3 );	// se promosso3 == NULL non accade nulla
					promosso3 = promosso2;
					promosso2 = promosso1;
					promosso1 = nuovoStudente;
				}
			else if ( promosso2 == NULL ) promosso2 = nuovoStudente;
			else if ( promosso2 -> voto < nuovoStudente -> voto ||
					( promosso2 -> voto == nuovoStudente -> voto &&
					promosso2 -> numEsercizi < nuovoStudente -> numEsercizi)
				) {
					eliminaStudente( promosso3 );	// se promosso3 == NULL non accade nulla
					promosso3 = promosso2;
					promosso2 = nuovoStudente;
				}
			else if ( promosso3 == NULL ) promosso3 = nuovoStudente;
			else if ( promosso3 -> voto < nuovoStudente -> voto ||
					( promosso3 -> voto == nuovoStudente -> voto &&
					promosso3 -> numEsercizi < nuovoStudente -> numEsercizi)
				) {
					eliminaStudente( promosso3 );
					promosso3 = nuovoStudente;
				}
	
		} else if ( comandoUtente == 2 ) {
			printf( "Inserisci matricola studente\n" );
			printf( "Matricola: " );
			int matricolaAnnulla;
			scanf( "%d", &matricolaAnnulla );
			if ( promosso1 != NULL && matricolaAnnulla == promosso1 -> matricola ) {
				eliminaStudente( promosso1 );
				promosso1 = promosso2;
				promosso2 = promosso3;
				promosso3 = NULL;
			} else if ( promosso2 != NULL && matricolaAnnulla == promosso2 -> matricola ) {
				eliminaStudente( promosso2 );
				promosso2 = promosso3;
				promosso3 = NULL;
			} else if ( promosso3 != NULL && matricolaAnnulla == promosso3 -> matricola )
				eliminaStudente( promosso3 );
				promosso3 = NULL;
		}
		printf( "\n" );
	} while ( !stampaVerbale ) ;

	printf( "\n\nVerbale Esame\n" );
	printf( "Esame\t%-20s %-5s\n", "Nome", "Voto" );
	if (promosso1 != NULL ) printf( "  1  \t%-20s %-5d\n", promosso1 -> nome, promosso1 -> voto );
	if (promosso2 != NULL ) printf( "  2  \t%-20s %-5d\n", promosso2 -> nome, promosso2 -> voto );
	if (promosso3 != NULL ) printf( "  3  \t%-20s %-5d\n", promosso3 -> nome, promosso3 -> voto );

	printf( "\n\n\nFine Programma\n\n" );


}

