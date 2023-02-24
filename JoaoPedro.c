#include<stdio.h>

int main(){
    int degraus, totalPasso, i, v, caminhos = 0;
    printf("Insira o numero de degraus");
    scanf("%i", &degraus);
    
    if((degraus/2) > 1){
        v = degraus/2;
        for(v ; v !=0 ; v--){
            caminhos += v * ((v*2) - degraus);
        }
    }
    printf("O numero de possibilidades e: %i" &caminhos);
    
    
    /*while(totalPasso != degraus){
        
        v = degraus % 2;

            if(v == 0){
                caminhos += 2;
            }
        
        for(i=0 ; i<degraus ; i++){
            
            
        }
    }*/

}