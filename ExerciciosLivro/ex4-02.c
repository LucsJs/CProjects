/*
fa�a uma fun��o atof(num), que converte de string para numero com ponto flutuante double.
a fun��o deve suportar nota��o cient�fica.
*/

#include <stdio.h>
#include <ctype.h>

double atof(char[]);
double pot(int, int); // base(natural) ^ exp(inteiro)

int main() {
	
	printf("%f", atof("-12.35E+3"));
	
	
	return 0;
	
}

double atof(char s[]) {
	
	int i, sinal, pow, sinal_exp, exp;
	double val;
	
	for (i = 0; isspace(s[i]); i++); // pula espa�os no come�o
	
	sinal = (s[i] == '-') ? -1 : 1;
	
	if (s[i] == '-' || s[i] == '+') i++;
	
	for (val = 0; isdigit(s[i]); i++) { // faz a convers�o. s� para quando ver um caractere que n�o seja um d�gito
		val = val * 10 + (s[i] - '0');
	}
	
	if (s[i] == '.') {
		i++;
		for (pow = 0; isdigit(s[i]); i++, pow++) {
			val = val * 10 + (s[i] - '0');
		}
		
		val /= pot(10, pow);
	}
	
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		sinal_exp = (s[i] == '-') ? -1 : 1;
		
		if (s[i] == '+' || s[i] == '-') i++;
		
		for (exp = 0; isdigit(s[i]); i++) {
			exp = exp * 10 + (s[i] - '0');
		}
		
		val *= pot(10, sinal_exp * exp);
	}
	
	return sinal * val;
	
}

double pot(int base, int exp) { // em caso 0 ^ 0 retorna 1
	
	if (exp < 0) {
		return 1.0 / pot(base, exp * -1);
		
	} else if (exp > 0) {
		
		int x = 1;
		
		for (int i = 0; i < exp; i++) {
			x *= base;
		}
		return x;
	}
	
	return 1;
	
}



























