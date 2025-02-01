#include <stdio.h>
#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
    int ano_fab;
			
} REGISTRO;

typedef struct{
	REGISTRO A[MAX+1];
	int nroElem;
	
} LISTA;

void inicializarLista(LISTA* p) {
	p->nroElem = 0;
}

int tamanho(LISTA* l) {
	return l->nroElem;	
}

void exibirLista(LISTA* p) {
	printf("Lista: \"");
	for (int i = 0; i < p->nroElem; i++){
		printf("%d-%d ", p->A[i].chave, p->A[i].ano_fab);
	}
	
	printf("\"\n");
}
//Essa busca é menos otimizada pois tem duas verificações a cada iteração
int buscaSequencial(LISTA* p, TIPOCHAVE ch) {
	int i = 0;
	while (i < p->nroElem) {
		
		if (p->A[i].chave == ch) {
			return i;
		} else {
			i++;
		}
		
	}
	return -1;
}

//Essa busca é mais otimizada, porém, sequencial
int buscaSentinela(LISTA* p, TIPOCHAVE ch) {
	p->A[p->nroElem] = ch;
	int i = 0;
	while (p->A[i].chave != ch) {
		i++;
	}
	if (i == p->nroElem) {
		return -1;
	} else {
		return i;
	}
	
}

int buscaBinaria(LISTA* p, TIPOCHAVE ch) {
	int i = 0;
	int f = p->nroElem-1;
	int m;
	
	while (i<f) {
		m = (f+i)/2;
		if (ch == p->A[m].chave) {
			return m;
		} else if (ch > p->A[m].chave) {
			i = m+1;
		} else {
			f = m-1;
		}
	}
	
	return -1
}

//Essa função insere um elemento na lista de maneira desordenada
bool inserirElemLista(LISTA* p, REGISTRO reg, int i) {
	if (i > p->nroElem || i < 0 || p->nroElem == MAX){
		return false;
	} else {
		for (int j = p->nroElem - 1; j > i; j--){
			p->A[j+1] = p->A[j];
		}
		p->A[i] = reg;
		p->nroElem++;
		return true;
	}
}

//Esta função insere elementos de maneira ordenada

bool inserirElemListaOrd(LISTA* p, REGISTRO reg) {
	if (p->nroElem >= MAX) {
		return false;
	} else {
		for (int i = p->nroElem; p->A[i-1].chave > reg.chave && i > 0; i--) {
			p->A[i] = p->A[i-1];
		}
		
		p->A[i] = reg;
		p->nroElem++;
		return true;
	}
	
}

bool excluirElemLista(LISTA* p, TIPOCHAVE ch) {
	int i = buscaBinaria(p, ch);
	if (i == -1) {
		return false;
	} else {
		for (int j = i+1; j < p->nroElem; j++) {
			p->A[j-1] = p->A[j];
		}
		p->nroElem--;
		return true;
	}
}

void reinicializarLista(LISTA* p) {
	p->nroElem = 0;
}



