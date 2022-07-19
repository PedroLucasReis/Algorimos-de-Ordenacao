#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct lista{
	int num;
	struct lista *prox;
	struct lista *ant;
};

typedef struct lista nume;

nume *inicio=(nume *)malloc(sizeof(nume));

void quick_sort()
{
	int sort, i=0, cont=1;
	nume *pivo;
	nume *temp;
	nume *aux;
	
	do
	{
		cont=0;
		srand(time(NULL));
		sort=rand()%5;
		pivo=inicio->prox;
		i=0;
		while(i<=sort && pivo->prox!=NULL)
		{
			pivo=pivo->prox;
			i++;
		}
		if(pivo->prox!=NULL)
		{
			temp=pivo->prox;
			aux=pivo;
			while(temp!=NULL)
			{
				if(aux->num>temp->num)
				{
					aux=temp;
				}
				else
				{
					temp=temp->prox;
				}
			}
			if(aux!=pivo)
			{
				if(aux->prox!=NULL)
				{
					aux->ant->prox=aux->prox;
					aux->prox->ant=aux->ant;
				}
				else
				{
					aux->ant->prox=NULL;
				}
				aux->prox=pivo;
				aux->ant=pivo->ant;
				pivo->ant=aux;
				aux->ant->prox=aux;
			}
		}
		if(pivo->ant!=inicio)
		{
			temp=pivo->ant;
			aux=pivo;
			while(temp!=inicio)
			{
				if(aux->num<temp->num)
				{
					aux=temp;
				}
				else
				{
					temp=temp->ant;
				}
			}
			if(aux!=pivo)
			{
				aux->ant->prox=aux->prox;
				aux->prox->ant=aux->ant;
				aux->ant=pivo;
				if(pivo->prox!=NULL)
				{
					aux->prox=pivo->prox;
					aux->prox->ant=aux;
				}
				else
				{
					aux->prox=NULL;
				}
				
				pivo->prox=aux;
				
				
			}
		}
		temp=inicio;
		temp=temp->prox;
		while(temp->prox!=NULL)
		{
			if(temp->num>temp->prox->num)
			{
				cont=1;
				temp=temp->prox;
			}
			else
			{
				temp=temp->prox;
			}
		}
	}
	while(cont==1);
	temp=inicio->prox;
	while(temp!=NULL)
	{
		printf("| %i ",temp->num);
		temp=temp->prox;
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
	quick_sort();
	system("pause");
}

