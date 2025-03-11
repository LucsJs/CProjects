/*

A funcção abaixo realiza uma busca binária com duas verificações a cada iteração. 
Mude esta função para que só haja um if dentro do laço.

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
