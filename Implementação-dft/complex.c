#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <"complex.h">

complex le(void)
{
   complex z;                    //A funcao pede para digitar dois numeros
   printf("Parte real: ");       //e esses numeros ficam armazenados na
   scanf("%lf",&z.a);            //estrutura z que a funcao retorna.
   printf("Parte imaginaria: ");
   scanf("%lf",&z.b);
   return z;
}
   
void mostra(complex z)
{
   if(z.b<0&&z.a!=0) //se o b for negativo ele plota direto (- b)
   {                 //porque sem isso ficaria (+ -b).
      z.b=z.b*(-1.0);    
      printf("%.3lf - %.3lf * i\n\n",z.a,z.b);
   }
   else if(z.a==0&&z.b!=0)//caso a seja 0 apenas o b aparece.
      printf("%.3lf * i\n\n",z.b);
   else if(z.b==0&&z.a!=0)//caso b seja 0 apenas o a aparece.
      printf("%.3lf\n\n",z.a);
   else if(z.a==0&&z.b==0)//caso ambos sejam 0 o resultado e 0.
      printf("0\n\n");
   else//qualquer outra condicao ele mostra a + b.
      printf("%.3lf + %.3lf * i\n\n",z.a,z.b);
}

complex soma(complex z1, complex z2)
{
   z1.a=z1.a+z2.a;//soma os elementos de mesma natureza.
   z1.b=z1.b+z2.b;
   return z1;
}

complex subtr(complex z1, complex z2)
{
   z1.a=z1.a-z2.a;//subtrai elementos de mesma natureza
   z1.b=z1.b-z2.b;
   return z1;
}

complex mult(complex z1, complex z2)
{
   complex z;//multiplicacao de numeros complexos
   z.a=(z1.a*z2.a)-(z1.b*z2.b);
   z.b=(z1.a*z2.b)+(z2.a*z1.b);
   return z;
}

complex divi(complex z1, complex z2)
{
   complex z;//divisao de numeros complexos
   z.a=((z1.a*z2.a)+(z1.b*z2.b))/(pow(z2.a,2)+pow(z2.b,2));
   z.b=((z2.a*z1.b)-(z1.a*z2.b))/(pow(z2.a,2)+pow(z2.b,2));
   return z;
}

double modulo(complex z)//calcula modulo.
{
   return sqrt(pow(z.a,2)+pow(z.b,2));
}

double angle(complex z)//calculo o angulo de fase.
{
   return atan2(z.b,z.a);
}
