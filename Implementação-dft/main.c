#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funcao.h"
#include "teste1.h" /*Teste de validação N=8 , Estagios=3*/
#include "teste2.h"/*Teste de validação N=16 , Estagios=4*/
#include "teste3.h" /*Teste de validação N=64 , Estagios=6*/


//MENU VALUES
#define TESTE_1          1
#define TESTE_2          2
#define TESTE_3          3
#define VOZ_DAT         4

typedef struct{
    double real, imag;
} complex;

//###########
//@PROTOTIPOS
//###########
void PrintResult(complex * x1, int N);

int main()
{
    complex *X_in;           // Sinal
    double *x;// DFT of x (real and imaginary parts)
    int length, i,k,n;
    FILE* arq;


int menu_option=6; //menu ativado
 clock_t end, start;
  while(menu_option != 0) {
        printf(
        "---------------------------------------------------------------\n"
        "Calculo da DFT - Transformada de fourier discreta - Selecione uma opcao:\n"
        "---------------------------------------------------------------\n"
        "1 - Calcular  Teste de validacao 1    \n"
        "2 - Calcular  Teste de validacao 2\n"
        "3 - Calcular  Teste de validacao 3 \n"
        "4 - Calcular  Voz.dat \n"
        "---------------------\n"
        "0 - EXIT.\n"
        "---------------------\n"
        );
        scanf("%d", &menu_option);
        switch (menu_option){
            case TESTE_1:
                // Calculando a DFT usando forca bruta
             X_in = malloc(8 *sizeof(complex)); /*Aloca vetor de compelxo*/
            start = clock();

                for (k=0 ; k<8 ; k++)
                    {
                      X_in[k].real = 0;
                      X_in[k].imag = 0;
                      for (n=0 ; n<8 ; n++){
                        X_in[k].real += xn[n] * cos((2*n * k * M_PI )/ 8);               // Parte real de X[k]
                        X_in[k].imag -= xn[n] * sin((2*n * k * M_PI )/ 8);         // Parte imaginaria de X[k]
                    }
                     }
            end = clock();
            PrintResult(X_in, 8);
            printf(" 8 ENTRADAS DFT: \n");
            printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
            printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));



             break;

           case TESTE_2:

                   // Calculando a DFT usando forca bruta
            X_in = malloc(16 *sizeof(complex)); /*Aloca vetor de compelxo*/
            start = clock();

                for (k=0 ; k<16 ; k++)
                    {
                      X_in[k].real = 0;
                      X_in[k].imag = 0;
                      for (n=0 ; n<16 ; n++){
                        X_in[k].real += in16[n] * cos((2*n * k * M_PI )/ 16);               // Parte real de X[k]
                        X_in[k].imag -= in16[n] * sin((2*n * k * M_PI )/ 16);         // Parte imaginaria de X[k]
                    }
                     }
            end = clock();
            PrintResult(X_in, 16);
            printf(" 16 ENTRADAS DFT: \n");
            printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
            printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));



            break;
           case TESTE_3:
            X_in = malloc(64 *sizeof(complex)); /*Aloca vetor de compelxo*/
             start = clock();

                for (k=0 ; k<64 ; k++)
                    {
                      X_in[k].real = 0;
                      X_in[k].imag = 0;
                      for (n=0 ; n<64 ; n++){
                        X_in[k].real += in64[n] * cos((2*n * k * M_PI )/ 64);               // Parte real de X[k]
                        X_in[k].imag -= in64[n] * sin((2*n * k * M_PI )/ 64);         // Parte imaginaria de X[k]
                    }
                     }
            end = clock();
            PrintResult(X_in, 64);
            printf("64 ENTRADAS DFT: \n");
            printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
            printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));


            break;

           case VOZ_DAT:
            x = OpenArquivo();
            length = x[0];
            printf("length %d\n",length);
            X_in = malloc(length *sizeof(complex)); /*Aloca vetor de compelxo*/

             start = clock();
            for (k=0 ; k<length ; k++)
                    {
                      X_in[k].real = 0;
                      X_in[k].imag = 0;
                      for (n=1; n<=length ; n++)
                      {
                        X_in[k].real += x[n] * cos((2*(n-1) * k * M_PI )/ length);               // Parte real de X[k]
                        X_in[k].imag -= x[n] * sin((2*(n-1)* k * M_PI )/ length);         // Parte imaginaria de X[k]
                    }
            }
            end = clock();

            printf("\n  Arquivo VOZ  DFT: \n");
            PrintResult(X_in,length);


            printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
            printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));

             break;

            default:
            break;
        }
    }
return 1;
}


void PrintResult(complex * x1, int N){
    int i;
    for(i=0;i<N;i++) {
        printf("REAL X[%d]: %lf - IMG[%d]: %lf -- \n", i, x1[i].real, i,x1[i].imag);
    }
}

