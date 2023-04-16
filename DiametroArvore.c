//Não consegui fazer o que foi solicitado, desculpe
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *esquerda, *direita, *ant;

} Node;

typedef struct arv
{
    Node *raiz;
} Arv;

void inserirDireita(Node *nodo, int valor);
void inserirEsquerda(Node *nodo, int valor)
{
    if (nodo->esquerda == NULL)
    {
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        nodo->esquerda = novo;
        novo->ant = nodo;
    }
    else
    {
        if (valor < nodo->esquerda->valor)
            inserirEsquerda(nodo->esquerda, valor);

        else if (valor > nodo->esquerda->valor)
            inserirDireita(nodo->esquerda, valor);
    }
}
void inserirDireita(Node *nodo, int valor)
{
    if (nodo->direita == NULL)
    {
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        nodo->direita = novo;
        novo->ant = nodo;
    }
    else
    {
        if (valor > nodo->direita->valor)
            inserirDireita(nodo->direita, valor);

        else if (valor < nodo->direita->valor)
            inserirEsquerda(nodo->direita, valor);
    }
}

void inserir(Arv *arv, int valor) 
{
    if (arv->raiz == NULL)
    {
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
        novo->ant = arv->raiz;
    }
    else if (valor < arv->raiz->valor)
    {
        inserirEsquerda(arv->raiz, valor);
    }
    else if (valor > arv->raiz->valor)
    {
        inserirDireita(arv->raiz, valor);
    }
}

int tamanho(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
    {
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int altura(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
    {
        int alturaEsquerda = altura(raiz->esquerda);
        int alturaDireita = altura(raiz->direita);
        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}

void imprimir(Node *raiz)
{
    if (raiz == NULL)
        return;
    else
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir(raiz->direita);
    }
}

int diameterOfBinaryTree(Node *raiz){
    int n;
    if (raiz == NULL)
        return 0;

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
    int diametroEsquerda = diameterOfBinaryTree(raiz->esquerda);
    int diametroDireita = diameterOfBinaryTree(raiz->direita);

    int diametroPassandoPelaRaiz = alturaEsquerda + alturaDireita;
    int diametroNaoPassandoPelaRaiz = (diametroEsquerda > diametroDireita ? diametroEsquerda : diametroDireita);


    return (n = diametroPassandoPelaRaiz > diametroNaoPassandoPelaRaiz ? diametroPassandoPelaRaiz : diametroNaoPassandoPelaRaiz);
}



int main(){
    int escolha;
    Arv *arv;
    arv->raiz = NULL;
    do{
        imprimir(arv);
        printf("Escolha a opcao desejada:\n1-Inserir Numeros\n2-Retornar Diametro\n0-Sair ");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Insira o valor desejado: ");
            int valor;
            scanf("%i", &valor);
            inserir(arv, valor);
            break;
        
        case 2:
            printf("O diametro da arvore e: %d\n", diameterOfBinaryTree(arv->raiz));
            break;
        default:
            break;
        }
    }while(escolha != 0);
}