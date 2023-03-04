#include<stdio.h>

int judgeCircle(int x, int y){
    if((x == 0) && (y == 0)){
        return 1;
    }
    else return 0;
}

int main(){
    char *vetor = NULL;
    int size = 0, x, y;

    do{
        printf("Insira o comando para movimentar o robo (U, D, R, L) e O para sair.\n");
        scanf("%c", &vetor[size]);

        switch (vetor[size])
        {
        case 'U':
            y++;
            printf("Para Cima!");
            break;
        case 'D':
            y--;
            printf("Para Baixo!");
            break;
        case 'R':
            x++;
            printf("Para Direita!");
            break;
        case 'L':
            x--;
            printf("Para Esquerda!");
            break;        
        default:
            break;
        }
        size++;
        vetor = (char *) realloc(vetor, size * sizeof(char));

    }while (vetor[size-1] != 'O');

    if(judgeCircle(x, y) == 1){
        printf("Verdadeiro!");
    }
    else printf("Falso!");

    return 0;
}