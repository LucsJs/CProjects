#include <stdio.h>

int binarySearch(int v[], int tam, int val) {
	int i = 0;
	int f = tam-1;
	int m;
	
	while (i <= f) {
		m = (f+i)/2;
		if (val == v[m]) {
			return m;
		} else if (val > v[m]){
			i = m+1;
		} else {
			f = m-1;
		}
	}
	return -1;	
}

int main() {
	
	int vet[] = {1, 3, 4, 5, 9, 12, 42, 65, 77, 98};
	printf("%d", binarySearch(vet, 10, 98));
	
	return 0;
}
