int contaBits(unsigned int x) {
	int b;
	for (b = 0; x != 0; b++) {
		x &= (x - 1);
	}
	return b;
}
