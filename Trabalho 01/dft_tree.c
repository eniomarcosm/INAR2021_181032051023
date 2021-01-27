/*
 * Author: Enio Marcos
 * Date:22/01/2020
 * Location: Mozambique/Beira
 * Depth first agorithm/Algoritmo de percurso por profundidade * 
 */

#include <stdio.h>
#include <stdlib.h>
//Estrutura do conteudo
struct item
{
    int value;
};
typedef struct item Item;

//Estrutura da ârvore
struct node
{
    Item item;
    struct node *leftptr, *rightptr;
};
typedef struct node Node;

//Metodo para inicializar a ârvore binaria
Node *treeInitialize()
{
    return NULL;
}

//Metodo para inserir um item em uma ârvore
Item itemCreate(int value)
{
    Item item;
    item.value = value;
    return item;
}

//Metodo para inserção de dados na ârvore
Node *treeInsert(Node *root, Item item)
{
    //Quando a raiz for nula inicializa com com o item
    if (root == NULL)
    {
        Node *aux = (Node *)malloc(sizeof(Node));
        aux->item = item;
        aux->leftptr = NULL;
        aux->rightptr = NULL;
        return aux;
    }
    else
    {
        if (item.value > root->item.value)
        {
            root->rightptr = treeInsert(root->rightptr, item);
        }
        else if (item.value < root->item.value)
        {
            root->leftptr = treeInsert(root->leftptr, item);
        }
        else
        {
            printf("Duplicado");
        }
    }
    return root;
}

void inOrderPrint(Node *root)
{
    //Se a raiz não tiver nenhum elemento, então deverá se inicializar
    if (root != NULL)
    {
        inOrderPrint(root->leftptr);
        printf("[%d] ", root->item.value);
        inOrderPrint(root->rightptr);
    }
}
void preOrderPrint(Node *root)
{
    //Se a raiz não tiver nenhum elemento, então deverá se inicializar
    if (root != NULL)
    {
        printf("[%d] ", root->item.value);
        preOrderPrint(root->leftptr);
        preOrderPrint(root->rightptr);
    }
}
void postOrderPrint(Node *root)
{
    //Se a raiz não tiver nenhum elemento, então deverá se inicializar
    if (root != NULL)
    {
        postOrderPrint(root->leftptr);
        postOrderPrint(root->rightptr);
        printf("[%d] ", root->item.value);
    }
}

void treeFree(Node *root)
{
    if (root != NULL)
    {
        treeFree(root->rightptr);
        treeFree(root->leftptr);
        free(root);
    }
}

Node *treeSearch(Node *root, int value)
{
    if (root != NULL)
    {
        if (root->item.value == value)
            return root;
        else
        {
            if (value > root->item.value)
                return treeSearch(root->rightptr, value);
            else
                return treeSearch(root->leftptr, value);
        }
    }
    return NULL;
}

Node *treeMin(Node *root)
{
    if (root != NULL)
    {
        Node *aux = root;
        while (aux->leftptr != NULL)
        {
            aux = aux->leftptr;
        }
        return aux;
    }
    return NULL;
}

Node *treeRemove(Node *root, int value)
{
    if (root != NULL)
    {
        if (value > root->item.value)
        {
            root->rightptr = treeRemove(root->rightptr, value);
        }
        else if (value < root->item.value)
        {
            root->leftptr = treeRemove(root->leftptr, value);
        }
        else
        {
            //Encotrado!
            if (root->leftptr == NULL && root->rightptr == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->leftptr == NULL && root->rightptr != NULL)
            {
                Node *aux = root->rightptr;
                free(root);
                return aux;
            }
            else if (root->leftptr != NULL && root->rightptr == NULL)
            {
                Node *aux = root->leftptr;
                free(root);
                return aux;
            }
            else
            {
                Node *aux = treeMin(root->rightptr);
                Item itemAux = aux->item;
                root = treeRemove(root, itemAux.value);
                root->item = itemAux;
                return root;
            }
        }
    }
    else
    {
        return NULL;
    }
}

int main()
{
    Node *root = treeInitialize();
    root = treeInsert(root, itemCreate(10));
    root = treeInsert(root, itemCreate(15));
    root = treeInsert(root, itemCreate(20));
    root = treeInsert(root, itemCreate(40));
    root = treeInsert(root, itemCreate(60));
    root = treeInsert(root, itemCreate(200));
    root = treeInsert(root, itemCreate(440));
    root = treeInsert(root, itemCreate(230));
    root = treeInsert(root, itemCreate(70));
    root = treeInsert(root, itemCreate(5));

    // treePrint(root);

    printf("Impressao na pre ordem da arvore:\n");
    preOrderPrint(root);

    printf("\nImpressao na ordem da arvore: \n");
    inOrderPrint(root);

    printf("\nImpressao na pos ordem da arvore: \n");
    postOrderPrint(root);

    printf("\n");

    // root = treeRemove(root, 5);
    // Node *tmp = treeSearch(root, 20);
    // if (tmp == NULL)
    //     printf(">>Elemento nao encontrado!");
    // else
    //     printf(">>Elemento encontrado!");

    // printf("\n");

    treeFree(root);

    return 0;
}
