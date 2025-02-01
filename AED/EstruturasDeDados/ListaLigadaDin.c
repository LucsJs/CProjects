#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCAHVE;

typedef struct {
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct aux{
	REGISTRO reg;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	PONT inicio;
} LISTA;

void inicializarLista(LISTA* l) {
	l->inicio = NULL;
}

int tamanho(LISTA* l) {
	PONT end = l->inicio;
	int tam = 0;
	while(end != NULL) {
		tam++;
		end = end->prox;
	}
	return tam;
}

void exibirLista(LISTA* l) {
	PONT end = l->inicio;
	printf("[ ");
	while (end != NULL) {
		printf("%d ", end->reg.chave);
		end = end->prox;
	}
	printf("]\n");
}


// Busca em lista desordenada
PONT buscaSequencial(LISTA* l, TIPOCHAVE ch) {
	PONT end = l->inicio;
	while (end != NULL) {
		if (end->reg.chave == ch) {
			return end;
		}
		end = end->prox;
	}
	return NULL;
	
}

// Busca em lista ordenada
PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) {
	PONT end = l->inicio;
	while (end != NULL && end->reg.chave < ch) {
		end = end->prox;
	}
	if (end != NULL && end->reg.chave == ch) {
		return end;
	}
	return NULL;
}

PONT buscaSequencialExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
	*ant = NULL;
	PONT end = l->inicio;
	while (end != NULL && end->reg.chave < ch) {
		*ant = end;
		end = end->prox;
	}
	if (end != NULL && end->reg.chave == ch){
		return end;
	}
	return NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
	PONT ant, i;
	TIPOCHAVE ch = reg.chave;
	i = buscaSequencialExc(l, ch, &ant);
	if (i != NULL) {
		return false;
		
	} else {
		i = (PONT) malloc(sizeof(ELEMENTO));
		i->reg = reg;
		if (ant != NULL) {
			i->prox = ant->prox;
			ant->prox = i;
			
		} else {
			i->prox = l.inicio;
			l.inicio = i;
			
		}
		
	}
	return true;
	
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
	PONT ant, i;
	i = buscaSequencialExc(l, ch, &ant);
	if (i == NULL) {
		return false;
	}
	
	if (ant == NULL) {
		l->inicio = i->prox;
		
	} else {
		ant->prox = i->prox;
		
	}
	free(i);
	return true;
	
}

void reinicializarLista(LISTA* l) {
	PONT end = l->inicio;
	while (end != NULL) {
		PONT apagar = end;
		end = end->prox;
		free(apagar);
	}
	l->inicio = NULL;
}










