#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
	struct lista *ant;
};

typedef struct lista nume;

nume *inicio=(nume *)malloc(sizeof(nume));

void insection_sort()
{
	nume *base;
	base=inicio->prox;
	nume *temp;
	temp=base->prox;
	nume *aux;
	nume *aux2;
	while(base->prox!=NULL)
	{
		temp=base->prox;
		if(base->num>temp->num)
		{
			if(temp->prox!=NULL)
			{
				aux=temp->prox;
				base->prox=aux;
				aux->ant=base;
			}
			else
			{
				base->prox=NULL;
			}
			aux=base->ant;
			while(aux->num>temp->num)
			{
				aux=aux->ant;
			}
			aux2=aux->prox;
			aux->prox=temp;
			temp->ant=aux;
			temp->prox=aux2;
			aux2->ant=temp;
		}
		else
		{
			base=base->prox;
		}	
	}
	base=inicio;
	base=base->prox;
	while(base!=NULL)
	{
		printf(" %i ", base->num);
		base=base->prox;
	}
	
}

main()
{
	int cont=1;
	nume *temp1;
	inicio->prox=NULL;
	inicio->ant=NULL;
	inicio->num=NULL;
	while(cont<=5)
	{
		nume *novo=(nume *)malloc(sizeof(nume));
		novo->prox=NULL;
		novo->ant=NULL;
		novo->num=NULL;
		printf("Digite um numero: ");
		scanf("%i", &novo->num);
		temp1=inicio;
		while(temp1->prox!=NULL)
		{
			temp1=temp1->prox;
		}
		temp1->prox=novo;
		novo->ant=temp1;
		system("cls");
		cont++;
	}
	insection_sort();
	system("pause");
}
