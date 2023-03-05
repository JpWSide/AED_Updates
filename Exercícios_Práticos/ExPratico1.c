#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool judgeCircle(char *moves)
{
    int x = 0, y = 0;
    bool position;

    for (int i = 0; i <= 20000; i++)
    { // varre o vetor traduzindo os movimentos.
        if(moves[i] == 'O')
        break;
        switch (moves[i])
        {
            
            case 'U':
                y++;
                printf("Para Cima!\n");
                break;
            case 'D':
                y--;
                printf("Para Baixo!\n");
                break;
            case 'R':
                x++;
                printf("Para Direita!\n");
                break;
            case 'L':
                x--;
                printf("Para Esquerda!\n");
                break;

            default:
                break;
            }
        
        }
    
    if ((x == 0) && (y == 0))
    { // Verifica se o robo está no (0,0)
        position = true;
        return position;
    }
    else
    {
        position = false;
        return position;
    }
}

int main()
{
    char *moves = (char *)malloc(20000 * sizeof(char)); // Aloca a memoria

    printf("movimentos (somente U, D, R ou L) e finalize o movimento com O: ");
    scanf("%s", moves);

    if (judgeCircle(moves) == 1)
    {
        printf("\nVerdadeiro!\n");
    }
    else
    {
        printf("\nFalso!\n");
    }
}
