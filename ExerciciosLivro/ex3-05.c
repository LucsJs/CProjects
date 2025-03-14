/*
Escreva uma função itoa(n, s[], esp) que pôe, no vetor s de char, 
o numero n convertido em caracteres com um número de espaços.
se houver mais espaços que dígitos, pôr os espaços na esquerda.
*/

#include <stdio.h>
#include <string.h>

void atoi(int, char[], int);
void inverte(char[]);


int main() {
	
	char s[25];
	atoi(-241, s, 10);
	printf("%s", s);
	
	return 0;
}

void atoi(int n, char s[], int esp) {
	int i, sinal;
	
	sinal = 1;
	if (n < 0) {
		sinal = -1;
	}
	
	i = 0;
	do {
		s[i++] = (n % 10) * sinal + '0';
		esp--;
	} while ((n /= 10) != 0);
	
	if (sinal < 0) {
		s[i++] = '-';
		esp--;
	}
	while (esp > 0) {
		s[i++] = ' ';
		esp--;
	}
	s[i] = '\0';
	inverte(s);
}

void inverte(char s[]) {
	int i, j, aux;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		aux = s[i];
		s[i] = s[j];
		s[j] = aux;
	}
}
