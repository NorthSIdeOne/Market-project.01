#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[])
{ 
cumparaturi *p,*q,*head_cumparaturi;
supermarket *m,*n,*head_supermarket;
cos_cumparaturi *head_cos,*s,*t;
Tree *root;
 FILE *f;
if((f=fopen("cerinte.txt","r"))==NULL)
	{
	 printf("Nu s-a putut deschide fisierul");
        exit(1);
	}

int v[10],buget,i,x;
for(i=0;i<6;i++)
	fscanf(f,"%d",&v[i]);

fscanf(f,"%d",&buget);

fclose(f);

if((f=fopen("date1.txt","r"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }

creare_stocuri(&m,&n,&head_supermarket,f);
fclose(f);
if(v[0]==1)//cerinta 1
{if((f=fopen("date2.txt","r"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }

creare_lista_cumparaturi(&p,&q,&head_cumparaturi,f);


 fclose(f);
}
if(v[1]==1)//cerinta 2
{if((f=fopen("date1.txt","r"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }



eliminare(head_cumparaturi,head_supermarket,f);


fclose(f);
}

if(v[2]==1)//cerinta 3
{
	buy(head_cumparaturi,head_supermarket,&head_cos,buget);

}
if(v[3]==1)//cerinta 4
{
unlimited_money(&head_cumparaturi,head_supermarket,&head_cos,f);
}

if(v[4]==1)  //cerinta 5
{x=numarare(head_cos);
int b[x+1];
ordonare(b,x,head_cos);
if((f=fopen("temp_arbore.in","w"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }

for(i=0;i<x;i++)
	fprintf(f," %d ",b[i]);
fclose(f);
if((f=fopen("temp_arbore.in","r"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }

root=arbore(x,f);

fclose(f);
}
//if(v[5]==1)

Stiva *top;
int nr;
nr=nr_elemente(head_supermarket);
int *r;
r=malloc(sizeof(int)*nr);
cerinta_6(top,head_supermarket,r);

if((f=fopen("rezultate.out","w"))==NULL)
        {
        printf("Nu s-a putut deschide fisierul");
        exit(1);
        }



afisare(head_cumparaturi,head_cos,v,root,f);
if(v[5]==1)
  afisare_elem_consecutive(r,nr,f);

fclose(f);

return 0;
}
