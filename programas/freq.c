/*

Autor: Paulo Vianna Mu <paulo.mu@acad.pucrs.br> & Fernando Ken <fernando.ken@acad.pucrs.br>
Descrição: Exibe o(s) caractere(s) mais frequente(s) do arquivo.

*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2){
		printf("A forma correta de usar o comando é freq.o [nome do arquivo](burro).\n");
		return 1;
	}
	
	FILE *arquivo;

	printf("Vamos ler o arquivo '%s'...\n", argv[1]);

	arquivo = fopen(argv[1], "r");

	int maior = 0;
	int empate[256] = {0};

	if (arquivo != NULL) {
		int contagemLetras[256] = {0};
		char c;

		while ((c = getc(arquivo)) != EOF) {
			int index;

			if (c >= 32 && c <= 90)
				index = c + 32;
			else
				index = c;

			contagemLetras[index] ++;
		}

		int i;

		for (i = 32; i < 127; i++) { // 
			if (contagemLetras[i])
				printf("%5d ['%c'] = %i ocorrência(s)\n", i,  i, contagemLetras[i]);

			if (contagemLetras[i] > contagemLetras[maior])
				maior = i;
			
			if (contagemLetras[i] == contagemLetras[maior])
				empate[i] = 1;
		}
	} else {
		printf("Falha ao abrir o arquivo!\n");
		
		return 1;
	}

	printf("\n");

	int x;
	int empatou = 0;

	for (x = 0; x < 256; x++) {
		if (empate[x]) {
			empatou = 1;

			if (x == 255)
				printf("['%c']", x);			
		}
	}

	if (empatou)
		printf(" são os caracteres que mais apareceram no arquivo.\n");
	else
		printf("['%c'] é o caractere que mais aparece no arquivo.\n", maior);

	fclose(arquivo);

	return 0;
}
