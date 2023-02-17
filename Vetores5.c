#include<stdio.h>
int main(){
	int j=0, i, V[10];
	for(i=0; i<10 ;i++ ){
		printf("Insira os valores da posicao %d vetor: \n", i+1);
		scanf("%d", &V[i]);	
	}
	for(i=0; i<10 ;i++ ){	
		if(V[i] % 2 != 1){
			j++;
		}else;
		
		
	}
	printf("Valores par: %d", j);
}
