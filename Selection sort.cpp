#include <stdio.h>
#include <stdlib.h>

struct numeros{
	int num;
	struct numeros *prox;
	struct numeros *ant;
};

typedef struct numeros nn;

nn *inicio=(nn *) malloc (sizeof(nn));


void select_sort()
{
	nn *bases;
	bases=inicio;
	bases=bases->prox;
	nn *temp;
	nn *menor;
	
	
	while(bases->prox!=NULL)
	{
		temp=bases;
		temp=temp->prox;
		menor=bases;
		while(temp!=NULL)
		{
			if(menor->num>temp->num)
			{
				menor=temp;
				temp=temp->prox;
			}
			else
			{
				temp=temp->prox;
			}
		}
		if(menor!=bases)
		{
			if(menor->prox==NULL)
			{
				menor->ant->prox=NULL;
			}
			else
			{
				menor->ant->prox=menor->prox;
				menor->prox->ant=menor->ant;
			}
			menor->ant=bases->ant;
			bases->ant->prox=menor;
			bases->ant=menor;
			menor->prox=bases;
		}
		else
		{
			bases=bases->prox;
		}
	}
	temp=inicio;
	temp=temp->prox;
	system("cls");
	while(temp!=NULL)
	{
		printf("%i\n", temp->num);
		temp=temp->prox;
	}
	
}

main()
{
	int cont=1;
	inicio->ant=NULL;
	inicio->num=NULL;
	inicio->prox=NULL;
	while(cont<=5)
	{
		nn *novo=(nn *) malloc (sizeof(nn));
		novo->ant=NULL;
		novo->num=NULL;
		novo->prox=NULL;
		printf("Digite um numero: ");
		scanf("%i", &novo->num);
		nn *temp;
		temp=inicio;
		while(temp->prox!=NULL)
		{
			temp=temp->prox;
		}
		novo->ant=temp;
		temp->prox=novo;
		cont++;
	}
	
	select_sort();
	
}
