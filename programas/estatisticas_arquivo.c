/*

Autor: Paulo Vianna Mu <paulo.mu@acad.pucrs.br>
Descrição: Código em C para ver estatísticas de um arquivo (quantidade de linhas, caracteres, bytes e palavras).

*/

#include <stdio.h>

// Comente a linha abaixo caso não queira exibir os caracteres do arquivo!
#define EXIBIR_CARACTERES

int main(void) {
	FILE *arquivo;
	char nome[64];
	
	printf("Digite o nome do arquivo: ");
	scanf("%s", nome);
	
	arquivo = fopen(nome, "r"); // Abrimos o arquivo em modo de leitura
	
	if (arquivo != NULL) { // Se o ponteiro do arquivo for igual a NULL, ocorreu algo errado ao abri-lo.
		char c;
		int caracteres = 0;
		int linhas = 0;
		int palavras = 0;
		int tamanho = 0;
		
		int comecou_uma_palavra = 0;
		
		while ((c = getc(arquivo)) != EOF) { // A variável c recebe o caractere lido, que é comparado com o caractere EOF (End Of File)
			caracteres ++;

			if (c == '\n' || c == ' ' || c == '	') { // '\n' = nova linha, ' ' = espaço, '	' = tabulação
				if (comecou_uma_palavra) {
					palavras ++;
					
					comecou_uma_palavra = 0;
				}
			} else { // Qualquer outro caractere
				if (!comecou_uma_palavra)
					comecou_uma_palavra = 1;
			}
			
			if (c == '\n') {
				linhas ++;
			#if defined EXIBIR_CARACTERES
				printf("[\\n] %i\n", c); // Gambiarra para exibir literalmente o caractere de nova linha '\n'
			} else {
				printf("[%c] %i\n", c, c);
			#endif
			}
		}
		
		if (feof(arquivo)) { // Se o programa chegou ao final do arquivo, então prosseguimos
			tamanho = caracteres * sizeof(char); // Multiplicamos a qtd. de caracteres pelo tamanho do char.
		
			printf("O arquivo '%s' contém %i linha(s), %i caractere(s), %i palavra(s) e %i byte(s).\n", nome, linhas, caracteres, palavras, tamanho);
		} else { // Caso contrário, algo errado ocorreu (porque a repetição while chegou ao caractere de final do arquivo, porém o programa não identificou isso)
			printf("O programa não chegou ao final do arquivo com sucesso.\n");
			printf("O arquivo pode estar corrompido!\n");
			
			return 1;
		}
		
	} else {
		printf("Não foi possível abrir o arquivo!\n");
		return 1;
	}
	
	fclose(arquivo);

	return 0;
}
