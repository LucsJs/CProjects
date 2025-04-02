/*
construir um programa de conversão de celcius para fahrenheit
*/

#include <stdio.h>

#define INICIO 0
#define FIM 300
#define INCR 20

int main() {
	
	float cel, fahr;
	cel = INICIO;
	
	while(cel <= FIM) {
		fahr = (9.0 / 5.0) * cel + 32.0;
		printf("%3.0f%6.0f\n", cel, fahr);
		cel = cel + INCR;
	}
	
	return 0;
	
}
