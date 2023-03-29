#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *rodando;
void **pBuffer;
void *newNode(char *nome, int *idade, int *telefone);
void addContato(char *nome, int *idade, int *telefone, void **head);
void delContato(char *nome, void **head);
void procurarContato(void **head, char *nome);
void listarContato();
int ordemAlfa();

void *newNode(char *nome, int *idade, int *telefone)
{
    void *nodo = (void *)calloc(1, sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **) * 2);

    char *pNome = (char *)nodo;
    int *pIdade = (int *)(nodo + sizeof(char) * 11);
    int *pNumero = (int *)(nodo + sizeof(char) * 11 + sizeof(int));
    void **pAnt = (void **)(nodo + sizeof(char) * 11 + sizeof(int) + sizeof(int));
    void **pProx = (void **)(nodo + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));

    memcpy(pNome, nome, strlen(nome));
    *pIdade = *idade;
    *pNumero = *telefone;
    *pAnt = NULL;
    *pProx = NULL;
    return nodo;
}

void addContato(char *nome, int *idade, int *telefone, void **head)
{
    void *nodo = newNode(nome, idade, telefone);

    void **ant, **atual;
    ant = malloc(sizeof(void **));
    atual = malloc(sizeof(void **));
    *ant = NULL;
    *atual = (void *)*head;

    void **pAnt = (void **)(nodo + sizeof(char) * 11 + sizeof(int) + sizeof(int));
    void **pProx = (void **)(nodo + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));

    if (*head == NULL)
    {
        *head = nodo;
        free(ant);
        free(atual);
        return;
    }

    while (*atual != NULL && ordemAlfa(nome, (char *)*atual) >= 0)
    {
        *ant = *atual;
        *atual = (void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
    }
    if (*ant == NULL)
    {
        *pProx = *atual;
        void **antDeAtual = (void **)(nodo + sizeof(char) * 11 + sizeof(int) + sizeof(int));
        *antDeAtual = nodo;
        *head = nodo;
    }
    else if (*atual != NULL)
    {
        void **antDeProx = (*ant + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        *antDeProx = nodo;
        *pProx = *atual;
        void **antDeAtual = (void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int));
        *antDeAtual = nodo;
        *pAnt = ant;
    }
    else
    {
        void **antDeProx = (*ant + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        *antDeProx = nodo;
        *pAnt = *ant;
    }
    free(ant);
    free(atual);
    return;
}

void delContato(char *nome, void **head)
{
    if (*head == NULL)
        return;

    void **ant, **atual, **prox;
    ant = malloc(sizeof(void **));
    atual = malloc(sizeof(void **));
    *ant = NULL;
    *atual = (void *)*head;

    while (*atual != NULL && ordemAlfa(nome, (char *)*atual) != 0)
    {
        *ant = *atual;
        *atual = *(void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
    }

    void **pAnt = (void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int));
    void **pProximo = (void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));

    if (*pProximo != NULL)
    {
        void **antDoProximo = (void **)(*ant + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        *antDoProximo = *pProximo;
        void **proximoDoAnt = (void **)(*pProximo + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        *proximoDoAnt = *ant;
    }
    else if (*pAnt != NULL)
    {
        void **antDoProximo = (void **)(*ant + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        *antDoProximo = NULL;
    }
    free(ant);
    free(*atual);
    free(atual);
}

void procurarContato(void **head, char *nome)
{
    if (*head == NULL)
        return;

    void **ant, **atual;
    ant = malloc(sizeof(void **));
    atual = malloc(sizeof(void **));
    *ant = NULL;
    *atual = (void *)*head;

    while (*atual != NULL && ordemAlfa(nome, (char *)*atual) != 0)
    {
        *ant = *atual;
        *atual = *(void **)(atual + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
    }
    *ant = *atual;
    printf("Contato:\n");
    printf("Nome: %s\n", (char *)*ant);
    *ant += sizeof(char) * 11;
    printf("Idade: %d\n", *(int *)*ant);
    *ant += sizeof(int);
    printf("Number: %ld\n", *(int *)*ant);
    free(ant);
    free(atual);
}

int ordemAlfa(char *nm1, char *nm2)
{
    while (*nm1 && *nm2 && *nm1 == *nm2)
    {
        nm1++;
        nm2++;
    }
    int *res = malloc(sizeof(int));
    *res = (*nm1 - *nm2);

    if (*res < 0)
    {
        free(res);
        return -1;
    }
    else if (*res > 0)
    {
        free(res);
        return 1;
    }
    free(res);
    return 0;
}

void listarContato(void **head, int *total)
{
    void **ant, **atual;
    ant = malloc(sizeof(void **));
    atual = malloc(sizeof(void **));
    *ant = NULL;
    *atual = (void *)*head;
    int *contador = malloc(sizeof(int));
    *contador = 0;
    while (*atual != NULL && *total > *contador)
    {
        *ant = *atual;
        printf("\nContato:\n");
        printf("Nome: %s\n", (char *)*(void **)ant);
        *ant += sizeof(char) * 11;
        printf("Idade: %d\n", *(int *)*ant);
        *ant += sizeof(int);
        printf("Telefone: %ld\n", *(int *)*ant);
        *atual = *(void **)(*atual + sizeof(char) * 11 + sizeof(int) + sizeof(int) + sizeof(void **));
        (*contador)++;
    }
    free(contador);
    free(ant);
    free(atual);
}

void menu()
{
    int escolha;
    printf("Selecione a opção desejada:\n");
    printf("1- Adicionar contato\n");
    printf("2- Remover contato\n");
    printf("3- Buscar contato\n");
    printf("4- Listar contato\n");
    printf("5- Sair\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        int *idade = malloc(sizeof(int));
        char *nome = malloc(10 * sizeof(int));
        int *telefone = malloc(sizeof(int));

        printf("Digite o nome do contato:\n");
        scanf("%10s", nome);
        printf("Digite a idade do contato:\n");
        scanf("%d", idade);
        printf("Digite o telefone do contato:\n");
        scanf("%lf", telefone);
        addContato(nome, idade, telefone, pBuffer);
        printf("Conrato adicionado com sucesso.\n");
        free(nome);
        free(idade);
        free(telefone);
        break;
    case 2:
        char *nomeRemover = malloc(sizeof(char) * 11);
        printf("Digite o nome do contato: ");
        scanf("%s", nomeRemover);
        delContato(nomeRemover, pBuffer);
        printf("Contato excluido com sucesso.\n");
        free(nomeRemover);
        break;
    case 3:
        char *nomeProcura = malloc(sizeof(char) * 11);
        printf("Digite o nome do contato a ser exibido: ");
        scanf(" %s", nomeProcura);
        procurarContato(pBuffer, nomeProcura);
        free(nomeProcura);
        break;
    case 4:
        int* numLista = malloc(sizeof(int));
        printf("Quantos contatos deseja listar? ");
        scanf("%d", numLista);
        listarContato(pBuffer, numLista);
        free(numLista);
        break;
    case 5:
    *rodando = 1;
    break;
    default:
        printf("Opção invalida, digite uma opçao valida!!!");
        menu();
        break;
    }
}

int main(int argc, char *argv[])
{
    rodando = (int *)malloc(sizeof(int));
    *rodando = 0;
    pBuffer = malloc(sizeof(void **));
    *pBuffer = NULL;

    while (*rodando == 0)
        menu();

    free(rodando);
    free(pBuffer);
    return 0;
}
