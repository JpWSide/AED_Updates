#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;
    struct node *esquerda, *direita;

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

int main()
{
    int op, valor;
    Arv arv;
    arv.raiz = NULL;
    do
    {
        printf("\nEscolha a opçao\n 1 inserir elementos\n 2 imprimir elementos \n 0 sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Insira o elemento desejado ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\nImprimindo elementos...\n");
            imprimir(arv.raiz);
            break;
        case 0:
            break;
        default:
            break;
        }

    } while (op != 0);
}