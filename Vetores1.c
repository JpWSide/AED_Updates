#include<stdio.h>
int main(){
		int j=0, i, A[6];
		A[0] = 1;
		A[1] = 0;
		A[2] = 5;
		A[3] = -2;
		A[4] = -5;
		A[5] = 7;
		j = A[0]+ A[1]+ A[5];
		printf("Valores somados dao: %d\n", j);
		A[3] = 100;
		for (i=0; i<6; i++){
			printf("%d ", A[i]);
			}
		
}
