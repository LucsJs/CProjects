/*

A func��o abaixo realiza uma busca bin�ria com duas verifica��es a cada itera��o. 
Mude esta fun��o para que s� haja um if dentro do la�o.

int buscaBin(int x, int v[], int n) {
	int inicio, meio, fim;
	inicio = 0;
	fim = n;
	while (inicio <= fim) {
		meio = (fim + inicio) / 2;
		if (v[meio] == x) {
			return meio;
		} else if (v[meio] > x) {
			fim = meio - 1;
		} else {
			inicio = meio + 1;
		}
	}
	
	return -1;
}
*/

int buscaBin(int x, int v[], int n) {
	int inicio, meio, fim;
	inicio = 0;
	fim = n;
	while (inicio <= fim) {
		meio = (fim + inicio) / 2;
		if (v[meio] >= x) {
			fim = meio - 1;
		} else {
			inicio = meio + 1;
		}
	}
	
	if (v[inicio] == x) {
		return inicio;
	}
	
	return -1;
}
