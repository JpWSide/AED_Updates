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

int busca(Node *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Elemento nao encontrado");
        return -1;
    }
    else
    {
        if (raiz->valor == chave)
        {
            printf("Valor encontrado!");
            return raiz->valor;
        }
        else if (chave < raiz->valor)
        {
            return busca(raiz->esquerda, chave);
        }
        else if (chave > raiz->valor)
        {
            return busca(raiz->direita, chave);
        }
    }
}

Node *remover(Node *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!");
        return NULL;
    }
    else
    {
        if (raiz->valor == chave)
        {
            if(raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                return NULL;
            }
        }
        else if (chave < raiz->valor)
        {
            raiz->esquerda = remover(raiz->esquerda, chave);
        }
        else
            raiz->direita = remover(raiz->direita, chave);
        return raiz;
    }
}

int tamanho(Node *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + tamanho(raiz->direita) + tamanho(raiz->esquerda);
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
        printf("\nEscolha a opçao\n1 inserir elementos\n2 imprimir elementos \n3 Buscar \n4 Remover \n0 sair\n");
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
        case 3:
            printf("Qual valor deseja buscar?");
            scanf("%d", &valor);
            busca(arv.raiz, valor);
            break;
        case 4:
            printf("Insira o elemento a ser removido ");
            scanf("%d", &valor);
            arv.raiz = remover(arv.raiz, valor);
            break;
        case 0:
            break;
        default:
            break;
        }

    } while (op != 0);
}