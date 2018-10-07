
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void afisare_elem_consecutive(int *v,int p,FILE *f)
{
	fprintf(f,"\n");
	int i;
	for(i=0;i<p;i++)
	fprintf(f," %d ",v[i]);
}
void push(Stiva **top,int val)
{
	Stiva *nod=malloc(sizeof(Stiva));
	nod->val=val;
	nod->next=*top;
	*top=nod;
}
int pop(Stiva **top)
{
	Stiva *temp=*top;
	int aux=temp->val;
	*top=(*top)->next;
	free(temp);
	return aux;
}
int nr_elemente(supermarket *head_supermarket)
{
	supermarket *p;
        int nr=0;
        for(p=head_supermarket;p!=NULL;p=p->next)
			nr++;

return nr;
}
void  cerinta_6(Stiva *top,supermarket *head_supermarket,int *v)
{
	supermarket *p;
	Stiva *q,*g;
	int i,j=0,k=0;
	for(p=head_supermarket;p!=NULL;p=p->next)
	 	{
		  push(&top,p->pret);
		}

	int numar;
	for(j=0,g=top;g!=NULL;g=g->next,j++)
		{
				q=g->next;
				numar=0;
				k=0;
				while(q!=NULL&&k!=1)
			 {

                    if(q->val > g->val)
						{numar++;

						  q=q->next;

						}
                    else {

							k=1;

                         }


			 }
			v[j]=numar;
		}
}
void afisare(cumparaturi* head_cumparaturi,cos_cumparaturi *head_cos,int v[],Tree *root,FILE *f)
{
   cumparaturi *p;
   cos_cumparaturi *q;
   if(v[0]==1||v[1]==1)
   {	 for(p=head_cumparaturi;p!=NULL;p=p->next)
   	{
         fprintf(f,"%s ",p->nume);
	 fprintf(f,"%s ",p->categorie);
         fprintf(f,"%d ",p->cantitate);
	 fprintf(f,"\n");
	}
    }
   if(v[2]==1||v[3]==1)
	{	fprintf(f,"\n");
		for(q=head_cos;q!=NULL;q=q->next)
			{
        		 fprintf(f,"%s ",q->nume);
        		 fprintf(f,"%s ",q->categorie);
        		 fprintf(f,"%d ",q->cantitate);
        		 fprintf(f,"\n");
       			 }

	}
   if(v[4]==1)
	{	fprintf(f,"\n");
		rsd(root,f);
	}

}

void creare_stocuri(supermarket** m,supermarket** n,supermarket** head_supermarket,FILE *f)
{

	int nr,i;
	fscanf(f,"%d",&nr);
	*m=malloc(sizeof(supermarket));
	fscanf(f,"%ms",&(*m)->nume);
	fscanf(f,"%ms",&(*m)->categorie);
	fscanf(f,"%d",&(*m)->pret);
	fscanf(f,"%d",&(*m)->cantitate);
	fscanf(f,"%d",&(*m)->stoc);
	(*m)->next=NULL;
	*head_supermarket=*m;
	for(i=0;i<nr-1;i++)
	{
	 *n=malloc(sizeof(supermarket));
        fscanf(f,"%ms",&(*n)->nume);
        fscanf(f,"%ms",&(*n)->categorie);
        fscanf(f,"%d",&(*n)->pret);
        fscanf(f,"%d",&(*n)->cantitate);
        fscanf(f,"%d",&(*n)->stoc);
        (*n)->next=NULL;
	(*m)->next=*n;
        *m=*n;
	}




}
void creare_lista_cumparaturi(cumparaturi** p,cumparaturi** q,cumparaturi** head_cumparaturi,FILE *f)
{
    int i,nr;
    fscanf(f,"%d",&nr);
	*p=malloc(sizeof(cumparaturi));
	fscanf(f,"%ms",&(*p)->nume);
	fscanf(f,"%ms",&(*p)->categorie);
	fscanf(f,"%d",&(*p)->cantitate);
	(*p)->next=NULL;
	*head_cumparaturi=*p;
	for(i=0;i<nr-1;i++)
	{
	*q=malloc(sizeof(cumparaturi));
	fscanf(f,"%ms",&(*q)->nume);
        fscanf(f,"%ms",&(*q)->categorie);
        fscanf(f,"%d",&(*q)->cantitate);
	(*q)->next=NULL;
	(*p)->next=*q;
	*p=*q;
	}

}

void eliminare(cumparaturi *head_cumparaturi,supermarket *head_supermarket,FILE *f)
{
	 cumparaturi *p,*aux;
	supermarket *m;
	int k=0;
	for(m=head_supermarket;m!=NULL;m=m->next)
		if(m->stoc==0)
			for(p=*head_cumparaturi;p->next!=NULL;p=p->next)
				{
					if(strcmp((p->next)->nume,m->nume)==0)
					{       aux=p->next;
						p->next=aux->next;
						free(aux);
						k=1;
					}


				}
}

void buy(cumparaturi *head_cumparaturi,supermarket *head_supermarket,cos_cumparaturi **head_cos,int buget) //cerinta 3
{
	cumparaturi *p;
	supermarket *m;
	cos_cumparaturi *t,*s;

	int nr,k=0,n=0,c,buget_aux;



	for(p=head_cumparaturi;p!=NULL;p=p->next)
	 for(m=head_supermarket;m!=NULL;m=m->next)
		{


						if(strcmp(p->nume,m->nume)==0)
							{
								if(p->cantitate==m->cantitate)
									{buget=buget-(m->cantitate)*(m->pret);
									c=m->cantitate;}
								else
									if((p->cantitate)>(m->cantitate))
									      {	buget=buget-(m->cantitate)*(m->pret);
										c=m->cantitate;}
								       else
										if((m->cantitate)>(p->cantitate))
											{buget=buget-(p->cantitate)*(m->pret);
											c=p->cantitate;}


								if(buget<0)
								{
								   while((buget<0)&&(0<c))
									{
									  nr=nr-(m->pret);
									 c--;
									buget=buget+(m->pret);
									}
								}

								if(k==0)
								{
									s=malloc(sizeof(cos_cumparaturi));
									s->next=NULL;
									s->nume=m->nume;
									s->categorie=m->categorie;
									s->cantitate=c;
									*head_cos=s;
									k=1;
								}
								else

									{
										t=malloc(sizeof(cos_cumparaturi));
										t->next=NULL;
									    t->nume=m->nume;
										t->categorie=m->categorie;
										t->cantitate=c;
										s->next=t;
										s=t;
									}


							}


			}


}

void unlimited_money(cumparaturi **head_cumparaturi,supermarket *head_supermarket,cos_cumparaturi **head_cos,FILE *f) //cerinta 4
{

	cumparaturi *p,*g,*j;
	supermarket *m,*h;
	cos_cumparaturi *t,*s,*a,*aux2;
	int dif,cantitate,aux,k,pret,min,H=0,v,z;

	aux2=malloc(sizeof(cos_cumparaturi));
	 for(p=*head_cumparaturi;p!=NULL;p=p->next)
         for(m=head_supermarket;m!=NULL;m=m->next)
                {


                if(strcmp(p->nume,m->nume)==0) //caut numele  produselor din lista de cumparaturi in supermarket
				{
					if(p->cantitate <= m->cantitate) //verific cantitatea
						{
							cantitate=p->cantitate;
							k=0;
							H++;

						}
					else
						if((p->cantitate)>(m->cantitate))
							{
								cantitate=m->cantitate;
								aux=(p->cantitate)-cantitate;
								k=1;
								H++;

							}
						else
							if((p->cantitate) < (m->cantitate))
							{
								cantitate=p->cantitate;
								k=0;
								H++;

							}
					if(H==1)
					{
						t=malloc(sizeof(cos_cumparaturi));
                                                t->next=NULL;
                                                t->nume=p->nume;
                                                t->categorie=p->categorie;
                                                t->cantitate=cantitate;
                                                s->next=t;
                                                s=t;
						*head_cos=s;
						p->cantitate=p->cantitate-cantitate;
					}
					else
						if(k==0) //daca cantitatea ceruta nu depaseste stocul il adaug
						{
							t=malloc(sizeof(cos_cumparaturi));
							t->next=NULL;
							t->nume=p->nume;
							t->categorie=p->categorie;
							t->cantitate=cantitate;
							p->cantitate=p->cantitate - cantitate;

							s->next=t;
							s=t;

						}


					       else
							if(k==1) //cantitatea ceruta depaseste stocul si adaug produsul curent in limita stocului
							{
								t=malloc(sizeof(cos_cumparaturi));
                                                		t->next=NULL;
                                                		t->nume=p->nume;
                                                		t->categorie=p->categorie;
                                                		t->cantitate=cantitate;
								p->cantitate=p->cantitate - cantitate;
                                                		s->next=t;
                                                		s=t;
															}


						dif=m->pret;
						z=0;
					for(h=head_supermarket;h!=NULL;h=h->next) //parcurg lista pentru a gasi cel mai apropiat pret
						{
							if(strcmp(h->categorie,p->categorie)==0) //verific categoria
								{
									if(strcmp(h->nume,p->nume)!=0)
										{


													 v=0;
													for(g=*head_cumparaturi;g!=NULL;g=g->next)
														{
															if(strcmp(g->categorie,h->categorie)==0)
															 {if(strcmp(g->nume,h->nume)==0)
																v=1;
															  }
														}
													if(v==0)
													{
													 	for(a=*head_cos;a!=NULL;a=a->next)
															{
																if(strcmp(a->categorie,h->categorie)==0)
                                                                {if(strcmp(a->nume,h->nume)==0)
                                                                 v=1;
                                                                }

															}
													}

													if(v==0)
													{
														if(m->pret > h->pret)
														{
															if(dif > (m->pret -h->pret) )
																{
																	dif=m->pret - h->pret;

																	aux2->nume=h->nume;
																	aux2->cantitate=h->cantitate;
																	aux2->categorie=h->categorie;
																	z=1;


																}

														}
														else
															{
																if(dif >(h->pret -m->pret))
																	{
																		dif=h->pret -m->pret;

                                                                                                                                        	aux2->nume=h->nume;
                                                                                                                                        aux2->cantitate=h->cantitate;
                                                                                                                                        aux2->categorie=h->categorie;

                                                                                                                                        	z=1;

																	}
															}

												}
										}
								}

						}

						if((aux2->cantitate >= aux)&&z==1)
						{
						t=malloc(sizeof(cos_cumparaturi));
                                                t->next=NULL;
                                                t->nume=aux2->nume;
                                                t->categorie=aux2->categorie;
                                                t->cantitate=aux;
                                                s->next=t;
                                                s=t;
						p->cantitate=p->cantitate-aux;

						}
						else
							if((aux2->cantitate < aux)&&z==1)
								{
									 aux=aux-aux2->cantitate;
									 t=malloc(sizeof(cos_cumparaturi));
                                               				 t->next=NULL;
                                               				 t->nume=aux2->nume;
                                               				 t->categorie=aux2->categorie;
                                               				 t->cantitate=aux;
                                                			 s->next=t;
                                               				 s=t;
									 p->cantitate=p->cantitate-aux;





								}

					}
					}


}
int numarare(cos_cumparaturi *head_cos)
{	int n=0;
	cos_cumparaturi *p;
	for(p=head_cos;p!=NULL;p=p->next)
	{
			n++;
	}
	return n;
}
Tree *arbore(int n,FILE *f)
{
	if(n>0)
	{
	  Tree *root=malloc(sizeof(Tree));
	  fscanf(f,"%d",&root->cantitate);

	  root->left=arbore(n/2,f);

	  root->right=arbore(n-1-n/2,f);

	 return  root;
	}
	else return NULL;
}


void rsd(Tree *root,FILE *f)
{
	if(root)
	{ fprintf(f," %d ",root->cantitate);
	  rsd(root->left,f);
	  rsd(root->right,f);
 	}
}
void ordonare(int b[],int x,cos_cumparaturi *head_cos)
{
cos_cumparaturi *s;
int j,i,aux;
for(i=0,s=head_cos;s!=NULL;s=s->next,i++)
{
        b[i]=s->cantitate;
}

for(i=0;i<x;i++)
for(j=i;j<x;j++)
{
        if(b[i]>=b[j])
        {
                aux=b[i];
                b[i]=b[j];
                b[j]=aux;
        }
}

}
