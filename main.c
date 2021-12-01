#include <stdio.h>


int main() {
   int vetor[] = {8, 3, 1, 85, 12, 5,16};
   int n = sizeof(vetor)/sizeof(int);
   int maiorDigito  =  maxDigVet(vetor, n);

   //Aplicando a ordenação;
   // bubble_sort(vetor, n);
   radix_sort(vetor, n, maiorDigito);

   /*	bubble_sort(vetor, 6);
    *	select_sort(vetor, 6);
    * 	insert_sort(vetor, 6);lg
    * 	shell_sort(vetor, 6);
    *	quick_sort(vetor, 6);
    *	radix_sort(vetor, 6);
    */

   //Apresentando o vetor ordenado
   for(int i = 0; i < n; i++){
	   printf("%dº elemento:\t%d\n",i+1, vetor[i]);
   }

   return 0;
}
