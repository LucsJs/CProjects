/*
escreva uma fun�� itos(n, s) que converte um n�mero inteiro em uma string
*/

#include <string.h>

void itos(int n, char s[]) {
	int i = 0, inicio, fim;
	inicio = 0;
	if (n < 0) {
		s[i++] = '-';
		n *= -1;
		inicio = 1;
	}
	
	do {
		s[i++] = (n % 10) + '0';
		n /= 10;
	} while (n != 0);
	
	s[i] = '\0'; // at� aqui a fun��o pegaria -184 e tranformaria em -481. Ent�o invertemos
	
	fim = strlen(s) - 1;
	while (inicio < fim) { // parte para inverter.
		int aux = s[inicio];
		s[inicio++] = s[fim];
		s[fim--] = aux;
	}
	
}




