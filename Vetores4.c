#include<stdio.h>
int main(){
	int x, y, i, A[7];
	for(i=0 ;i<8 ; i++){
		printf("Insira os valores da posicao %d vetor: \n", i+1);
		scanf("%d", &A[i]);		
		}
		printf("Insira as posicoes a serem somada: ");
		scanf("%d", &x);
		scanf("%d", &y);
		printf("A soma e: %d", A[x-1] + A[y-1]);
}
