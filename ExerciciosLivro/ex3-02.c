/*
Escreva uma função escape(s, t) que converte caracteres como nova linha e
tabulação em sequências de escape visíveis como \n e \t, enquanto copia
t em s, usando switch.
*/
#include <stdio.h>
#define MAXVET 1000

void escape(char s[], char t[]) {
	int i, j;
	
	for (i = j = 0; t[i] != '\0' && i < MAXVET - 1; i++) {
		switch (t[i]) {
			case '\n':
			case '\t': {
				if (j < MAXVET - 2) {
					s[j++] = '\\';
					if (t[i] == '\n') {
						s[j++] = 'n';
					} else {
						s[j++] = 't';
					}
				} else {
					
				}
				break;
			}
			default:
				s[j++] = t[i];
				
		}
	}
	s[j] = '\0';
}

void lelinha(char linha[]) { // função auxiliar para ler linhas e armazenar na variável linha
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && i < MAXVET - 1) {
		linha[i++] = c;
	}
	linha[i] = '\0';
}


