float Temperatura(float f) {
	float c;
	c = ((5.0 / 9.0) * (f - 32));

	if (c <= -268)
		printf("ZERO ABSOLUTO.\n");
	else if (c >= -5 && c <= 5)
		printf("CONGELAMENTO D'ÁGUA\n");
	else if (c >= 95 && c <= 105)
		printf("EBULIÇÃO D'ÁGUA\n");

	return c;
}
