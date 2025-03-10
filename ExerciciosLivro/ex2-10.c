/*
função que retorna letra minúscula usando operador condicional
*/

int minusc(char c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
