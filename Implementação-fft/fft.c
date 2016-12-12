/*
Objetivo desde programa é calcular a Transformada rapida de fourier de um arquivo Voz.dat cuja
mesmo tem 500000 amostras, para isso foi implementada a FFT-Radix2 utilizando Butterfly
para implementação foi criada funcões e estrutura nescessaria para armazenar os dados,cuja são
ordenar as amostra por bit reversal , somar numeros complexo , multiplicar numeros complexos
e também para calcular os W, e a função para aplicar o calculo da fft
Foi criado teste de validação do programa  , utilizando amostras de 8, 16 e 64 .

O programa tem um menu tendo como opções 1 é calcular a fft de 8 amostra, 2 calcular a fft de 16 amostra
e 3 calcular a fft de 64amostras assim tendo a opção 4 cuja mesma calcula a FFT do arquivo voz.dat.

*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "teste1.h" /*Teste de validação N=8 , Estagios=3*/
#include "teste2.h"/*Teste de validação N=16 , Estagios=4*/
#include "teste3.h" /*Teste de validação N=64 , Estagios=6*/


//MENU VALUES
#define TESTE_1          1
#define TESTE_2          2
#define TESTE_3          3
#define VOZ_DAT	4

typedef struct{
	double real, imag;
} complex;



//###########
//@PROTOTIPOS
//###########

complex mult(complex z1, complex z2);    // multiplicação de numeros complexos
complex soma(complex z1, complex z2);  // soma de dois numeros complexos
complex W(int n, int N); 		    //  W

void revesalBit(complex * x, int N); // Função para ordenar ReverterBit
void PrintResult(complex * x1, int N); // Funcao para Printar a saida calculada FFT
void fft(complex * x, int N); // Calcular FFT

complex * OpenArquivo(int * length); //Abrir arquivo  e armazenar em uma estrutura complexa


int main(){
complex * X_in;
int length =1;
int i, j;
int menu_option=6; //menu ativado
 clock_t end, start;
  while(menu_option != 0) {
        printf(
        "---------------------------------------------------------------\n"
        "Calculo da FFT - Transformada de fourier rapida - Selecione uma opcao:\n"
        "---------------------------------------------------------------\n"
        "1 - Calcular  Teste de validacao 1    \n"
        "2 - Calcular  Teste de validacao 2    \n"
        "3 - Calcular  Teste de validacao 3    \n"
        "4 - Calcular  Voz.dat \n"
        "---------------------\n"
        "0 - EXIT.\n"
        "---------------------\n"
        );
        scanf("%d", &menu_option);
        switch (menu_option){
            case TESTE_1:
            /*Calcula a FFT para o Header Teste1*/
            X_in = malloc(8 *sizeof(complex)); /*Aloca vetor de compelxo*/

	for(i=0;i<8;i++) {
		X_in[i].real = xn[i];
		X_in[i].imag = 0;
	 }
 	revesalBit(X_in, 8);
 	start = clock();
 	fft(X_in, 8);
 	end = clock();
 	PrintResult(X_in, 8);

 	printf(" 8 ENTRADAS FFT: \n");
	printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));
            break;

            case TESTE_2:
            /*Calcula a FFT para o Header Teste2*/
             X_in = malloc(16 *sizeof(complex)); /*Aloca vetor de compelxo*/

	for(i=0;i<16;i++) {
		X_in[i].real = in16[i];
		X_in[i].imag = 0;
	 }
 	revesalBit(X_in, 16);
 	start = clock();
 	fft(X_in, 16);
 	end = clock();

 	PrintResult(X_in, 16);
 	printf(" 16 ENTRADAS FFT: \n");
	printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));


            break;

            case TESTE_3:/*Calcula a FFT para o Header Teste3*/
             X_in = malloc(64 *sizeof(complex)); /*Aloca vetor de compelxo*/

	for(i=0;i<64;i++) {
		X_in[i].real = in64[i];
		X_in[i].imag = 0;
	 }
 	revesalBit(X_in, 64);
 	start = clock();
 	fft(X_in, 64);
 	end = clock();

 	PrintResult(X_in, 64);
 	printf(" 64 ENTRADAS FFT: \n");
	printf("Tempo total calculado: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));

            break;
            case VOZ_DAT:/*Calcula a FFT para o Arquivo Voz.dat*/
       	X_in = OpenArquivo(&length); /*Abrindo o Arquivo VOZ*/

	revesalBit(X_in, length);
	start = clock();

	fft(X_in, length);
	end = clock();
	PrintResult(X_in, length);
	printf(" Arquivo VOZ.DAT : \n");
	printf("Tempo total do calculo: %4.4f ms\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	printf("Aproximadamente: %4.4f segundos\n",(double)(end-start)/(double)(CLOCKS_PER_SEC));


            break;

            default:
            break;
        }
    }
return 1;
}

complex * OpenArquivo(int *length){

	FILE *arq;
	complex * x1;
	int i= 0, j = 0;
	double x, resultado;
	arq = fopen("voz.dat","r");

	/*Verifica se a abertura ocorreu com sucesso*/
	if(arq==NULL){
		printf("Impossivel abrir arquivo ");
	}else{
		printf("\n Arquivo aberto com sucesso \n");
		while (!feof(arq)){
			resultado = fscanf(arq, "%lf", &x);
			if(j != 0) {/*Armazenando os arquivos*/
				x1[i].real = x;
				x1[i].imag = 0.0;
				i++;
			}else{ /*Pegando o tamanho do arquivo */
				*length = (int)x;
				x1 = malloc(x * sizeof(complex));
				j = 1;
			}
		};
		fclose(arq);

	}
	printf("\n Arquivo carregado com sucesso. \n");
	return x1;
}


void revesalBit(complex * x, int N){
	/*Declaracao de variaveis*/
	int j, i, aux, aux2, aux3 = 0;
	complex c_aux;

	aux2 = N/2; /* Divide na metado o  vetor*/


	for(i=1;i<(N-1);i++) /**/
	{

		aux = aux2;
		while(aux3>=aux)/* Acha a metade */
		{

			aux3 = aux3 - aux;
			aux = aux/2;
		}
		aux3 = aux3 + aux;

		if(i<aux3) /*Trocamos as posiçoes    */
		{

			c_aux = x[i];
			x[i] = x[aux3];
			x[aux3] = c_aux;
		}
	}
	/*TESTE DE VALIDACAO

	printf("\n ORDEM REVERSAL  \n\n");
	for(j=0;j<N;j++) {
		printf("REAL X[%d]: %lf - IMG: %lf -- \n", j, x[j].real, x[j].imag);
	}*/
}

void fft(complex * x, int N){
	int Nestagios ,est, j, indiceWD,  aux, aux2;
	complex *Xf;
	int  a, b, d;
	Nestagios = log2(N) ;/*Calcula no numero de estagios*/
	indiceWD = 2; /*Indice low do W*/
	 Xf = (complex*)malloc(N * sizeof(complex));
	if(Xf!=NULL){
	for(est = 1; est <= Nestagios; est++) {


		//printf("\nESTAGIO: %d ", est);
		for(aux = 0; aux < indiceWD; aux++) {/**/

			for(aux2=0; aux2 < (N/indiceWD); aux2++){ /*Numero de Caixas do Estagio*/

				a = aux + (aux2*indiceWD);

				d =  indiceWD/2 ;


				if(aux >= d){
					b = a - d;
					/*Aqui ira somar partes  Down */

					Xf[a] = soma(x[b], mult(x[a], W(aux, indiceWD)));
				}else{
					b = a + d;
					/*Aqui ira somar da parte  UP*/

					Xf[a] = soma(x[a], mult(x[b], W(aux, indiceWD)));
				}
			}
		}
		/*Atualizando o vetor para o proximo estagio*/
		for(j=0;j<N;j++) {
			x[j] = Xf[j];
		}

		indiceWD = indiceWD * 2;/*Indece de W muda no final do estagio */

	}
	printf("\n FFT \n");
	}	
	

}



void PrintResult(complex * x1, int N){
	int i;
	for(i=0;i<N;i++) {
		printf("REAL X[%d]: \t %lf \tIMG[%d]: \t %lf -- \n", i, x1[i].real, i,x1[i].imag);
	}
}

complex W(int n, int N){
	complex z;
	double angulo = n*2*M_PI/N;
	z.real = cos(angulo);
   	z.imag = -sin(angulo);
	//printf("ELEVADO %d %d REAL: %lf - IMG: %lf -- \n", n, N, z.real, z.imag);
	return z;
}

complex soma(complex z1, complex z2){
	complex z;
	z.real = (z1.real + z2.real);
	z.imag = (z1.imag + z2.imag);
	return z;
}

complex mult(complex z1, complex z2){
	complex z;
	z.real = ((z1.real*z2.real) - (z1.imag*z2.imag));
	z.imag = ((z1.real*z2.imag) + (z2.real*z1.imag));
	return z;
}
