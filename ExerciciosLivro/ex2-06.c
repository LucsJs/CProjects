/*
função setabits(x, p, n, y) que retorna x com os n bits
que começam na posição p setados com os n bits mais à direita de y, deixando os
outros bits inalterados.

ex: setabtis(10011010, 6, 4, 00011001)
	resultado: 110011010

supondo que o shitf é lógico
*/

unsigned int setabits(unsigned int, int, int, int);

unsigned int setabits(unsigned int x, int p, int n, int y) {
	(((x >> p + 1) << n) | ((~0 << n) | y) << (p - n + 1)) | (~(~0 << (p - n + 1)) & x
}



/*
Explicação

xyyyyxxx x, n = 4, p = 6
zzzwwzzw y

0000000x x >> p + 1
000x0000 (x >> p + 1) << n
11110000 ~0 << n
1111wzzw (~0 << n) | y
000xwzzw ((x >> p + 1) << n) | ((~0 << n) | y)
xwzzw000 ((x >> p + 1) << n) | ((~0 << n) | y) << (p - n + 1)
00000xxx ~(~0 << (p - n + 1)) & x
xwzzwxxx (((x >> p + 1) << n) | ((~0 << n) | y) << (p - n + 1)) | (~(~0 << (p - n + 1)) & x

*/
