/*
fun��o giradir(x, n) que retorne o valor do inteiro x
girado � direita de n posi��es de bit

ps: assumindo que o tamanho de um int � 32 bits

ex: giradir(11000001, 3);
	resultado: 00111000
*/

#define INT_BITS 32

unsigned int giradir(unsigned int, int);

unsigned int giradir(unsigned int x, int n) {
	
	int giro = n - 32 * (n/32);
	return (x >> giro | x << INT_BITS - giro);
}


