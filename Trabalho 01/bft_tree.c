/*
 * Author: Enio Marcos
 * Date:22/01/2020
 * Location: Mozambique/Beira
 * Bredth first travel Algorithm/Algoritmo de percurso por largura
 * 
*/
#include <stdio.h>
#include <stdlib.h>

//Estrutura dos dados
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

//
void printGivenLevel(Node *root, int level);
int height(Node *node);
Node *treeInsert(Item data);
Item itemCreate(int value);

//Metodo para inserir um item em uma ârvore
Item itemCreate(int value)
{
	Item item;
	item.value = value;
	return item;
}

//Metodo que percorre cada nivel da arvore
void printLevelOrder(Node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		//Metodo que imprime o nivel corrente
		printGivenLevel(root, i);
}

//Metodo que imprime o nivel pretendido
void printGivenLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->item.value);
	else if (level > 1)
	{
		printGivenLevel(root->leftptr, level - 1);
		printGivenLevel(root->rightptr, level - 1);
	}
}

//Metodo que computa o cumprimento da arvore
int height(Node *node)
{
	if (node == NULL)
		return 0;
	else
	{

		int lheight = height(node->leftptr);
		int rheight = height(node->rightptr);

		//Retorna-se apenas o maior cumprimento
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

//Metodo para crir um novo nó na arvore
Node *treeInsert(Item data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->item = data;
	node->leftptr = NULL;
	node->rightptr = NULL;

	return (node);
}

int main()
{
	Node *root = treeInsert(itemCreate(10));
	root->leftptr = treeInsert(itemCreate(53));
	root->rightptr = treeInsert(itemCreate(18));
	root->leftptr->leftptr = treeInsert(itemCreate(19));
	root->leftptr->rightptr = treeInsert(itemCreate(14));

	printf("A ordem do percurso por largura será: \n");
	printLevelOrder(root);
	printf("\n");

	return 0;
}
