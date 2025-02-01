#include <stdio.h>
#define false 0
#define true 1 

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int inicio;
	int nroElem;	
	
} FILA;
