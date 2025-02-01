#include <stdio.h>
#include <malloc.h>

#define 1 true
#define 0 false

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct aux{
	REGISTRO reg;
	struct aux* prox;
	
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT topo;
	
} PILHA;

void inicializarPilha(PILHA* p) {
	p->topo = NULL;
	
}

int tamanhoPilha(PILHA* p) {
	int tam = 0;
	PONT end = p->topo;
	while (end != NULL) {
		tam++;
		end = end->prox;
		
	}
	return tam;
	
}

void exibirPilha(PILHA* p) {
	printf("[ ");
	PONT end = p->topo;
	while (end != NULL) {
		printf("%d ", end->reg.chave);
		end = end->prox
		
	}
	printf("]\n");
	
}

bool push(PILHA* p, REGISTRO reg) {
	PONT end = (PONT) malloc(sizeof(ELEMENTO));
	end->reg = reg;
	end->prox = p->topo;
	p->topo = end;
	return true;
	
}

bool pop(PILHA* p, REGISTRO* reg) {
	PONT apagar = p->topo;
	if (p->topo == NULL) {
		return false;
		
	}
	*reg = p->topo->reg;
	p->topo = p->topo->prox;
	free(apagar);
	
}

void reinicializarPilha(PILHA* p) {
	while(p->topo != NULL) {
		PONT apagar = p->topo;
		p->topo = p->topo->prox;
		free(apagar);
		
	}
	
}














