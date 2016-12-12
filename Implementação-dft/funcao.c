#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcao.h"


double* OpenArquivo()
{
    double* amostra;
    int length;
    FILE *arq;
    int i;

    arq = fopen("voz.dat","r");
    fscanf(arq, "%i ", &length);

    amostra = calloc(sizeof(double),length);
    amostra[0] = length;
    for (i = 1; i <= length; i++)
    {
        /* Armazenar os valores do arquivo*/
        fscanf(arq, "%lf", &amostra[i]);
        printf("input: %lf \n", amostra[i]);

    }

    fclose(arq);
    return amostra;
}
