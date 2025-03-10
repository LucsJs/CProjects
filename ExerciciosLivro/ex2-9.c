/*
Fazer uma função contabits que conta quantidade bits 1 em um número.
*/


int contaBits(unsigned int x) {
	int b;
	for (b = 0; x != 0; b++) {
		x &= (x - 1);
	}
	return b;
}
