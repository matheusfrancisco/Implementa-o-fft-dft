#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <"complex.c">

/* Estrutura do numero complex */
typedef struct
{
	    double a,b;
} complex;


/*Estrutura das funções */ 
complex soma(complex z1, complex z2);
complex subtr(complex z1, complex z2);
complex mult(complex z1, complex z2);
complex divi(complex z1, complex z2);
double modulo(complex z);
double angle(complex z);
void mostra(complex z);
complex le(void);

