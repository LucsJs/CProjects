/*
fun��o que retorna letra min�scula usando operador condicional
*/

int minusc(char c) {
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
