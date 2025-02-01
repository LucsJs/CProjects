#include <stdio.h>
#define 50 MAX

#define 1 true
#define 0 false

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int topo;
	
} PILHA;

void inicializarPilha(PILHA* p) {
	p->topo = -1;
	
}

int tamanhoPilha(PILHA* p) {
	return p->topo + 1;
	
}

void exibirPilha(PILHA* p) {
	printf("[ ");
	for (int i = p->topo; i >= 0; i--) {
		printf("%d ", p->A[i].chave);
	}
	printf("]\n");
}

bool push(PILHA* p, REGISTRO reg) {
	if (tamanhoPilha(p) >= MAX) {
		return false;
		
	}
	p->topo += 1;
	p->A[p->topo] = reg;
	return true;
	
}

bool pop(PILHA* p, REGISTRO* reg) {
	if (p->topo < 0) {
		return false;
		
	}
	*reg = p->A[p->topo];
	p->topo -= 1;
	return true;
	
}

void reinicializarPilha(PILHA* p) {
	p->topo = -1;
}
















