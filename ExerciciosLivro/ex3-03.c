/*
escreva uma funçã itos(n, s) que converte um número inteiro em uma string
*/


#include <stdio.h>

int main() {
	
	n = -184;
	char num[10];
	itos(n, s);
	printf("%s", num);
	
	return 0;
}


void itos(int n, char s[]) {
	int i = 0;
	if (n < 0) {
		s[i++] = '-';
	}
	s[i++] = n % 10;
	n /= 10;
	while(n != 0) {
		s[i++] = n % 10;
		n /= 10;
	}
	s[i] = '\0';
	
}
