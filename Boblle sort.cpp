#include <stdio.h>
#include <stdlib.h>

struct numeros{
	int num;
	struct numeros *ant;
	struct numeros *prox;
};

typedef struct numeros nn;

nn *inicio=(nn *)malloc(sizeof(nn));

boblle_sort()
{
	int cont=0, cont2=0;
	nn *temp5;
	temp5=inicio;
	while(temp5!=NULL)
	{
		temp5=temp5->prox;
		cont++;
	}
	temp5=inicio;
	temp5=temp5->prox;
	nn *temp2;
	temp2=temp5->prox;
	do
	{
		if(temp2!=NULL && temp5->num>temp2->num)
		{
			temp2->ant=temp5->ant;
			temp5->ant->prox=temp2;
			temp5->prox=temp2->prox;
			temp2->prox=temp5;
			temp5->ant=temp2;
			if(temp5->prox!=NULL)
			{
				temp5->prox->ant=temp5;
			}
			temp2=temp5->prox;
			cont2=0;
		}
		else
		{
			if(temp2==NULL)
			{
				temp5=inicio->prox;
				temp2=temp5->prox;
			}
			else
			{
				temp5=temp5->prox;
				temp2=temp5->prox;
				cont2++;
			}
		}
		printf("\nErro\n");
	}
	while(cont2!=cont);
	system("cls");
	temp5=inicio;
	temp5=temp5->prox;
	while(temp5!=NULL)
	{
		printf("%i\n", temp5->num);
		temp5=temp5->prox;
	}
	
}

main()
{
	inicio->ant=NULL;
	inicio->num=NULL;
	inicio->prox=NULL;
	int cont=1;
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
	boblle_sort();
	system("pause");
}
