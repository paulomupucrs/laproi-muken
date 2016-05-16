#include <stdio.h>

int main(void) {
	FILE *arquivo;
	char nome[64];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nome);

	printf("Vamos ler o arquivo '%s'...\n", nome);

	arquivo = fopen(nome, "r");

	int contagemLetras[256] = {0};
	char c;

	while ( (c = getc(arquivo)) != EOF) {
		contagemLetras[(int)c] ++;
	}

	int i;
	int maior = 0;

	for (i = 32; i < 127; i++) {
		if (contagemLetras[i])
			printf("%5d ['%c'] = %i ocorrência(s)\n", i,  i, contagemLetras[i]);

		if (contagemLetras[i] > contagemLetras[maior])
			maior = i;
	}

	printf("['%c'] é a letra que mais aparece no arquivo.\n", maior);

	fclose(arquivo);

	return 0;
}
