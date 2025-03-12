/*
Escrever uma fun��o que itob(n, s, b) que tranforma um inteiro em um 
outro n�mero na base b na cadeia s. s� servindo para n�meros positivos
*/

#include <string.h>
#include <stdio.h>

void itob(int, char[], int);
void inverte(char[]);

int main() {
	int n = 69;
	char s[20];
	itob(n, s, 2);
	printf("%s\n", s);
	itob(n, s, 8);
	printf("%s\n", s);
	itob(n, s, 10);
	printf("%s\n", s);
	itob(n, s, 16);
	printf("%s\n", s);
	itob(n, s, 24);
	printf("%s\n", s);
	
	
	return 0;
}

void itob(int n, char s[], int b) { // Usarei o m�todo das divis�es sucessivas
	int resto;
	int divInt;
	int i = 0;
	
	do {
		resto = n % b;
		if (resto >= 0 && resto <= 9) {
			s[i++] = resto + '0';
		} else {
			s[i++] = resto + '7';
		}
		
		divInt = n / b;
		n = divInt;
	} while (divInt != 0);
	
	s[i] = '\0';
	inverte(s);
	
}


void inverte(char s[]) {
	int i, j;
	i = 0;
	j = strlen(s) - 1;
	while (i < j) {
		char aux = s[i];
		s[i++] = s[j];
		s[j--] = aux;
	}
}




