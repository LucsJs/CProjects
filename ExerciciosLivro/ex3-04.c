/*
Escrever uma função que itob(n, s, b) que tranforma um inteiro em um 
outro número na base b na cadeia s. só servindo para números positivos
*/

#include <stdio.h>
#include <string.h>

void itob(int, char[], int);
void inverte(char[]);

int main() {
	
	char s[10];
	itob(23, s, 2);
	printf("%s\n", s);
	itob(23, s, 8);
	printf("%s\n", s);
	itob(23, s, 10);
	printf("%s\n", s);
	itob(23, s, 16);
	printf("%s\n", s);
	itob(23, s, 20);
	printf("%s\n", s);
	
	return 0;
}

void itob(int n, char s[], int b) { // Usarei o método das divisões sucessivas
	int resto;
	int divInt;
	int i;
	
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
