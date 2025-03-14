/*
Olhe a função abaixo:
// converte n para caracteres em s
void itoa(int n, char s[]) {

	int i, sinal;
	
	if ((sinal = n) < 0) {
		n = -n;
	}
	
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	
	if (sinal < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	inverte(s);
}

não funciona para o menor número possível de 32 bits com complemento de 2.
Por que? Faça uma versão que funcione em todas as implementações.
*/

/*
-- RESPOSTA --
não dá certo pois com o número sendo negativo, a função inverte o sinal no começo e 
esse número nao cabe em 32 bits.
*/

#include <stdio.h>
#include <string.h>

void atoi(int, char[]);
void inverte(char[]);


int main() {
	
	char s[25];
	atoi(0, s);
	printf("%s", s);
	
	return 0;
}

void atoi(int n, char s[]) {
	int i, sinal;
	
	sinal = 1;
	if (n < 0) {
		sinal = -1;
	}
	
	i = 0;
	do {
		s[i++] = (n % 10) * sinal + '0';
		
	} while ((n /= 10) != 0);
	
	if (sinal < 0) {
		s[i++] = '-';
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
