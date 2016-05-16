#include<stdio.h>
#include<stdlib.h>
#define SIZE 256

int main(void)
{
    int total = 0;
    int j;
    int s[SIZE];

    for( j = 0 ; j < SIZE ; j++) { /*j++ ou j = j + 1 ou j += 1*/
        s[j] = 0;
    }
    //TODO: ler o arquivo
    s['A']++;
    s['B']++;
    s['A']++;
    //
    for( j = 0 ; j < SIZE ; j++) { /*j++ ou j = j + 1 ou j += 1*/
        total += s[j];
    }

    printf("%s%14s\n", "Elemento", "Valor");

    for( j = 0 ; j < SIZE ; j++) { /*j++ ou j = j + 1 ou j += 1*/
        if (s[j] != 0)
            printf("%8d%5c%5x%14d\n", j, j, j, s[j]); /*	USAR %5c OU %5x(HEXADECIMAL) */
    }

    printf("%8s%14d\n", "Total", total);

    return EXIT_SUCCESS;
}

