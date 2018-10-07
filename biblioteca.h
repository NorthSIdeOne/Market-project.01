#ifndef MY_LIBRARY
#define MY_LIBRARY
#include <stdio.h>
typedef struct stiva
{
	int val;
	struct stiva *next;

}Stiva;

typedef struct lista_supermarket
{
        char *nume;
	char *categorie;
	int  pret;
	int cantitate;
	int stoc;
	struct lista_supermarket *next;

 
}supermarket;

typedef struct lista_cumparaturi
{
	char *nume;
	char *categorie;
	int cantitate;
	struct lista_cumparaturi *next;
}cumparaturi;

typedef struct produse_cumparate
{
	char *nume;
	char *categorie;
	int  cantitate;
	struct produse_cumparate *next;
}cos_cumparaturi;

typedef struct Arbore
{
	char *nume;
        char *categorie;
        int  cantitate;
	struct Arbore *right,*left;
}Tree;
void afisare_elem_consecutive(int *v,int nr,FILE *f);
int nr_elemente(supermarket *head_supermarket);
void cerinta_6(Stiva *top,supermarket *head_supermarket,int *v);
void push(Stiva **top,int val);
int pop(Stiva **top);
void unlimited_money(cumparaturi **head_cumparaturi,supermarket *head_supermarket,cos_cumparaturi **head_cos,FILE *f);
void buy(cumparaturi *head_cumparaturi,supermarket *head_supermarket,cos_cumparaturi **head_cos,int buget);
void  eliminare(cumparaturi *head_cumparaturi,supermarket *head_supermarket,FILE *f);
void afisare_cumparaturi(cumparaturi* head_cumparaturi,FILE *f);
void creare_lista_cumparaturi(cumparaturi** p,cumparaturi** q,cumparaturi** head_cumparaturi,FILE *f);
void creare_stocuri(supermarket** m,supermarket** n,supermarket** head_supermarket,FILE *f);
void afisare(cumparaturi* head_cumparaturi,cos_cumparaturi *head_cos,int v[],Tree *root,FILE *f);
int numarare(cos_cumparaturi *head_cos);
Tree *arbore(int n,FILE *f);
void ordonare(int b[],int x,cos_cumparaturi *head_cos);
void rsd(Tree *root,FILE *f);

#endif
