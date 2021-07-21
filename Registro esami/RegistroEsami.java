/*
	LPS Example

	Registro Esami

	Language: Java
 	Style: plain Java
 	Version: Ref-java
 */

/*
	Original Plain Java Code
*/

import java.util.Scanner;

public class RegistroEsami {

	public static void stampaComandi( ) {
		System.out.println( "Inserisci un comando:\n\n" );
		System.out.println( "2: Annulla un esito\n" );
		System.out.println( "1: Inserisci un nuovo esito\n" );
		System.out.println( "0: Termina inserimento e stampa verbale\n" );
	
	}

	public static void main( String args[] ) {
		System.out.println( "Registro Esami" );

		Scanner input =  new Scanner( System.in );
		Boolean stampaVerbale = false;

		Studente promosso1 = null, promosso2 = null, promosso3 = null;

		do {
			stampaComandi();

			int comandoUtente = input.nextInt();
			input.nextLine();
			if ( comandoUtente == 0 ) stampaVerbale = true;
			else if ( comandoUtente == 1 ) {
				System.out.println( "Inserisci dati studente" );
				Studente nuovoStudente = new Studente();
				System.out.print( "Nome: " );
				nuovoStudente.nome = input.nextLine();
				System.out.print( "Matricola: " );
				nuovoStudente.matricola = input.nextInt();
				System.out.print( "Voto: " );
				nuovoStudente.voto = input.nextByte();
				System.out.print( "Numero Esercizi Svolti: " );
				nuovoStudente.numEsercizi = input.nextByte();
				input.nextLine();

				/* 
					memorizza lo studente se è uno dei migliori 3
				*/
				if ( promosso1 == null ) promosso1 = nuovoStudente;
				else if ( promosso1.voto < nuovoStudente.voto ||
						( promosso1.voto == nuovoStudente.voto &&
						promosso1.numEsercizi < nuovoStudente.numEsercizi)
					) {
						promosso3 = promosso2;
						promosso2 = promosso1;
						promosso1 = nuovoStudente;
					}
				else if ( promosso2 == null ) promosso2 = nuovoStudente;
				else if ( promosso2.voto < nuovoStudente.voto ||
						( promosso2.voto == nuovoStudente.voto &&
						promosso2.numEsercizi < nuovoStudente.numEsercizi)
					) {
						promosso3 = promosso2;
						promosso2 = nuovoStudente;
					}
				else if ( promosso3 == null ) promosso3 = nuovoStudente;
				else if ( promosso3.voto < nuovoStudente.voto ||
						( promosso3.voto == nuovoStudente.voto &&
						promosso3.numEsercizi < nuovoStudente.numEsercizi)
					) {
						promosso3 = nuovoStudente;
					}
		
			} else if ( comandoUtente == 2 ) {
				System.out.println( "Inserisci matricola studente" );
				System.out.print( "Matricola: " );
				int matricolaAnnulla = input.nextInt();
				if ( promosso1 != null && matricolaAnnulla == promosso1.matricola ) {
					promosso1 = promosso2;
					promosso2 = promosso3;
					promosso3 = null;
				} else if ( promosso2 != null && matricolaAnnulla == promosso2.matricola ) {
					promosso2 = promosso3;
					promosso3 = null;
				} else if ( promosso3 != null && matricolaAnnulla == promosso3.matricola )
					promosso3 = null;
			}
			System.out.println( "" );
		} while ( !stampaVerbale ) ;

		System.out.println( "\n\nVerbale Esame\n" );
		System.out.printf( "Esame\t%-20s %-5s\n", "Nome", "Voto" );
		if (promosso1 != null ) System.out.printf( "  1  \t%-20s %-5d\n", promosso1.nome, promosso1.voto );
		if (promosso2 != null ) System.out.printf( "  2  \t%-20s %-5d\n", promosso2.nome, promosso2.voto );
		if (promosso3 != null ) System.out.printf( "  3  \t%-20s %-5d\n", promosso3.nome, promosso3.voto );

		System.out.println( "\n\n\nFine Programma" );
	}

}

class Studente {
	String nome;
	int matricola;
	byte voto;
	byte numEsercizi;

}