#include<stdio.h>
int main(void)
{
	FILE *arquivo;
	int a, b, soma = 0;
 	char nome[64];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nome);

	arquivo = fopen(nome, "r");

	do
	{
		fscanf(arquivo, "%d %d", &a, &b);
		int maior = 0;
		if(a>b)
		{
			maior = a;
			soma = a + b;
		}
		else
		{
			maior = b;
			soma = soma + a;
		}
		printf("%d é o maior número.\n", maior);
	}
	while(!feof(arquivo));
	printf("A soma dos números menores é %d.\n", soma);
	fclose(arquivo);
	return 0;
}	
