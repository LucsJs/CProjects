#include <stdio.h>
#include <malloc.h>

#define 0 false
#define 1 true

typedef int bool
typedef int TIPOCHAVE

typedef struct {
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct aux {
	REGISTRO reg;
	struct aux* prox;
	struct aux* ant;
	
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
	PONT cabeca;
	
} DEQUE;

void inicializarDeque(DEQUE* d) {
	d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
	d->cabeca->ant = d->cabeca;
	d->cabeca->prox = d->cabeca;
	
}

int tamanhoDeque(DEQUE* d) {
	int tam = 0;
	PONT end = d->cabeca->prox;
	while (end != d->cabeca) {
		tam++;
		end = end->prox;
		
	}
	return tam;
	
}

void exibirDeque(DEQUE* d) {
	PONT end = d->cabeca->prox
	printf("[ ");
	while (end != d->cabeca) {
		printf("%d ", end->reg.chave);
		
	}
	printf("]\n");
	
}

bool inserirFinal(DEQUE* d, REGISTRO reg) {
	PONT elem = (PONT) malloc(sizeof(ELEMENTO));
	elem->reg = reg;
	elem->prox = d->cabeca;
	elem->ant = d->cabeca->ant;
	d->cabeca->ant = elem;
	elem->ant->prox = elem;
	return true;
	
}

bool inserirComeco(DEQUE* d, REGISTRO reg) {
	PONT elem = (PONT) malloc(sizeof(ELEMENTO));
	elem->reg = reg;
	elem->ant = d->cabeca;
	elem->prox = d->cabeca->prox;
	d->cabeca->prox = elem;
	elem->prox->ant = elem;
	return true;
	
}

bool exclusaoInicio(DEQUE* d, REGISTRO* reg) {
	PONT apagar = d->cabeca->prox;
	if (apagar == d->cabeca) {
		return false;
		
	}
	d->cabeca->prox = apagar->prox;
	apagar->prox->ant = d->cabeca;
	*reg = apagar->reg;
	free(apagar);
	return true;
	
}

bool esclusaoFinal(DEQUE* d, REGISTRO* reg) {
	PONT apagar = d->cabeca->ant;
	if (apagar == d->cabeca) {
		return false;
		
	}
	d->cabeca->ant = apagar->ant;
	apagar->ant->prox = d->cabeca;
	*reg = apagar->reg;
	free(apagar);
	return true;
	
}

void reinicializarDeque(DEQUE* d) {
	PONT end  = d->cabeca->prox;
	while (end != d->cabeca) {
		PONT apagar = end;
		end = end->prox;
		free(apagar);
		
	}
	d->cabeca->prox = d->cabeca;
	d->cabeca->ant = d->cabeca;
	
}










