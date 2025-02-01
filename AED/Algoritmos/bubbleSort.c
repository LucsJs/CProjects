#include <stdio.h>

void bubbleSort(int v[], int tam) {
	int aux;
	for (int f = tam-1; f > 0; f--) {
		for (int i = 0; i < f; i++) {
			if (v[i] > v[i+1]) {
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
	}
	
}

int main() {
	int arr[] = {55, 0, -78, -4, 32, 200, 52, 63, 69, 125};
	int tamanho = 10;
	
	printf("Array desordenado: [ ");
	for (int x = 0; x < tamanho; x++) {
		printf("%d ", arr[x]);
	}
	printf("] \n");
	
	bubbleSort(arr, tamanho);
	
	printf("Array ordenado: [ ");
	for (int y = 0; y < tamanho; y++) {
		printf("%d ", arr[y]);
	}
	printf("] \n");
	
	
	return 0;
}
