/*
escrever função indicecad(s, t) que retorna o valor da string t dentro 
da string s, a partir da posição mais a direita. Retorna -1 caso não ache.
*/
#include <string.h>

int indiceCad(char s[], char t[]) {
	
	int i, j, k;
	
	for (i = strlen(s) - 1; i > 0; i--) {
		for (j = i, k = strlen(t) - 1; s[j] == t[k] && k >= 0 && j >= 0 ; k--, j--);
		
		if (k == -1 && t[0] != '\0') {
			return ++j;
		}
	}
	
	
	return -1;
	
}

