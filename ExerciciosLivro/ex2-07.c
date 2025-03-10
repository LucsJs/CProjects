/*
função inverte(x, p, n) que retorne x com os n bits que 
começam na posição p invertidos(0 -> 1, 1 -> 0), deixando os demais inalterados
ps: assumindo que os shitfs são LÓGICOS

ex: inverte(10100100, 6, 4);
resultado: 11011100
*/

unsigned int inverte(unsigned int, int, int);

unsigned int inverte(unsigned int x, int p, int n) {
	
	return ~(~0 << n) << (p - n + 1) ^ x;
	
}


/*
EXEMPLO 
- 8 bits (abbbbaaa);
- supondo que ~b = d;
- inverte(abbbbaaa, 6, 4);

00000000 0
11111111 ~0
11110000 ~0 << n
00001111 ~(~0 << n)
01111000 ~(~0 << n) << (p - n + 1)
addddaaa ~(~0 << n) << (p - n + 1) ^ x
return addddaaa
*/
