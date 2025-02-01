#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct aux{
	REGISTRO reg;
	struct aux* prox;
	
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	PONT cabeca;
	
} LISTA;

void inicializarLista(LISTA* l) {
	l->cabeca = (PONT) malloc(sizeof(ELEMENTO))
	l->cabeca->prox = l->cabeca;
	
}

int tamanho(LISTA* l) {
	int tam = 0;
	PONT end = l->cabeca->prox;
	while (end != l->cabeca) {
		tam++;
		end = end->prox;
		
	}
	return tam;
	
}

void exibirLista(LISTA* l) {
	PONT end = l->cabeca->prox;
	printf("[ ");
	while (end != l->cabeca) {
		printf("%d ", end->reg.chave);
		end = end->prox;
		
	}
	printf("]\n");
	
}

// Lista não precisa estar ordenada para realizar essa busca
PONT buscaSentinela(LISTA* l, TIPOCHAVE ch) {
	PONT end = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while(end->reg.chave != ch) {
		end = end->prox;
		
	}
	if (end == l->cabeca) {
		return NULL;
		
	}
	return end;
	
}

// Função de busca em lista ordenada
PONT buscaSentinelaOrd(LISTA* l, TIPOCHAVE ch) {
	PONT end = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while (end->reg.chave < ch) {
		end = end->prox;
		
	}
	if (end->reg.chave > ch || end == l->cabeca) {
		return NULL;
		
	} 
	return end;
	
}

PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
	*ant = l->cabeca;
	PONT end = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while (end->reg.chave < ch) {
		*ant = end;
		end = end->prox;
		
	}
	if (end->reg.chave > ch || end == l->cabeca) {
		return NULL;
		
	} 
	return end;
	
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
	PONT ant;
	if (buscaSeqExc(l, reg.chave, &ant) != NULL) {
		return false;
		
	}
	PONT elem = (PONT) malloc(sizeof(ELEMENTO));
	elem->reg = reg;
	elem->prox = ant->prox;
	ant->prox = elem;
	elem = NULL;
	return true;
	
}

bool excluirElem(LISTA* l, TIPOCHAVE ch) {
	PONT ant;
	PONT elem = buscaSeqExc(l, ch, &ant);
	if (elem == NULL) {
		return false;
		
	}
	ant->prox = elem->prox;
	free(elem);
	elem = NULL;
	return true;
	
}

void reinicializarLista(LISTA* l) {
	PONT prox = l->cabeca->prox;
	while (prox != l->cabeca) {
		PONT apagar = prox;
		prox = prox->prox;
		free(apagar);
		
	}
	l->cabeca->prox = l->cabeca;
	apagar = NULL;
	prox = NULL;
	
}
















