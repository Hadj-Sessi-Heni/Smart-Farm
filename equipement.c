#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "equipement.h"
#include <gtk/gtk.h>
enum
{
	CODE,
	TYPE,
	MARQUE,
	ANNEE,
	MATRICULE,
	ETAT,
	//NOMBREDUTILISATION,
	COLUMNS
};
enum{
	CODE1,
	TYPE1,
	ETAT1,
	NOMBREDUTILISATION,
	COLUMNS1
};

///////////////////////////////////////////////////////////
void ajouter(Equipement E)
{
FILE *f;
f=fopen("equi.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",E.Code,E.Type,E.Marque,E.annee_dachat,E.Matricule,E.etat);
fclose(f);
}
}
///////////////////////////////////////////////////////////
void affiche(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char Code[30];
	char Type[30];
	char Marque[30];
	char annee_dachat[30];
	char Matricule[30];
	char etat[30];
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee_dachat",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Matricule",renderer,"text",MATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("equi.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("equi.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",Code,Type,Marque,annee_dachat,Matricule,etat)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CODE, Code, TYPE, Type, MARQUE, Marque, ANNEE, annee_dachat, MATRICULE, Matricule, ETAT, etat, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}

}
///////////////////////////////////////////////////////////
void supprimer(Equipement E)
{	char Code[30];
	char Type[30];
	char Marque[30];
	char annee_dachat[30];
	char Matricule[30];
	char etat[30];
	

FILE *f,*g;
f=fopen("equi.txt","r");
g=fopen("dump.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while(fscanf(f,"%s %s %s %s %s %s\n",Code,Type,Marque,annee_dachat,Matricule,etat)!=EOF)
	{
	if(strcmp(E.Code,Code)!=0 || strcmp(E.Type,Type)!=0 || strcmp(E.Marque,Marque)!=0 || strcmp(E.annee_dachat,annee_dachat)!=0 || strcmp(E.Matricule,Matricule)!=0 )
	fprintf(g,"%s %s %s %s %s %s\n",Code,Type,Marque,annee_dachat,Matricule,etat);	
	}
fclose(f);
fclose(g);
remove("equi.txt");
rename("dump.txt","equi.txt");
}
}
///////////////////////////////////////////
void rechercher(char ref[],GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Equipement E;

	char Code[30];
	char Type[30];
	char Marque[30];
	char annee_dachat[30];
	char Matricule[30];
	char etat[30];
	//store=NULL;
FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Code",renderer,"text",CODE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee_dachat",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Matricule",renderer,"text",MATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",ETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("equi.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("equi.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s\n",Code,Type,Marque,annee_dachat,Matricule,etat)!=EOF)
{if(strcmp(Code,ref)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CODE,Code,TYPE,Type,MARQUE,Marque,ANNEE,annee_dachat,MATRICULE,Matricule,ETAT,etat,-1);
}

}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
/*-------------------------------------------*/
void ajout_util(date D,char e[],char Code[] ,char Type[]){
FILE *f;
f=fopen("utilisation.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %d %d %d \n",Code,Type,e,D.jour,D.mois,D.annee);
fclose(f);
}
}
/*--------------------------------------------*/
/*void affiche_u(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;

	char Code[30];
	char Type[30];
	//char e[30];
	int nb;
	
	store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Code",renderer,"text",CODE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type",renderer,"text",TYPE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

/*renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",ETAT1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);*/

/*renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nb",renderer,"text",NOMBREDUTILISATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
f=fopen("occurance.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("occurance.txt","a+");
		while(fscanf(f,"%s %s  %d \n",Code,Type,nb)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CODE, Code, TYPE, Type, NOMBREDUTILISATION,nb, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}*/
/*---------------------------------------------*/
void equip(){
FILE *f;
FILE *g;
FILE *h;
char Code[30];
char Type[30];
char etat[30];
int nb_occ;
date D;
char util[]="utiliser";
char e[30];
int i=0;
int taille=0;
verif t[taille];

f=fopen("utilisation.txt","a+");
while(fscanf(f,"%s %s %s %d %d %d\n",Code,Type,etat,D.jour,D.mois,D.annee)!=EOF){
taille+=1;}

while(fscanf(f,"%s %s %s %d %d %d\n",Code,Type,etat,D.jour,D.mois,D.annee)!=EOF){
strcpy(t[i].id,Code);
strcpy(t[i].type,Type);
if(strcmp(etat,util)==0){
t[i].nb=t[i].nb+1;
i++;
}
}
int j,k;
verif V;
eq_ut E;
for(j=0;j<taille;j++){
for(k=j+1;k<taille;k++){
if(t[j].nb<t[k].nb)
{strcpy(V.id,t[j].id);
strcpy(V.type,t[j].type);
V.nb=t[j].nb;
strcpy(t[j].id,t[k].id);
strcpy(t[j].type,t[k].type);
t[j].nb=t[k].nb;
strcpy(t[k].id,V.id);
strcpy(t[k].type,V.type);
t[k].nb=V.nb;}}}
int a;
for(a=0;a<taille;a++){
rewind(f);
while(fscanf(f,"%s %s %s \n",E.Code,E.type,E.e)!=EOF){
if (strcmp(t[a].id,E.Code)==0){
strcpy(V.id,E.Code);
strcpy(V.type,E.type);
V.nb=t[a].nb;}
g=fopen("occurance.txt","a+");
if (g!=NULL)
{
fprintf(g,"%s %s %d \n",V.id,V.type,V.nb);
fclose(g);}

fclose(f);}}
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkWidget *liste;
	GtkListStore *store;

	char Code1[30];
	char Type1[30];
	//char e[30];
	int nb;
	
	store=NULL;



store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Code1",renderer,"text",CODE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" Type1",renderer,"text",TYPE1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

/*renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" etat",renderer,"text",ETAT1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);*/

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nb",renderer,"text",NOMBREDUTILISATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);

h=fopen("occurance.txt","r");
if(h!=NULL)
{

h=fopen("occurance.txt","a+");
		while(fscanf(h,"%s %s  %d \n",Code1,Type1,&nb)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CODE, Code1, TYPE, Type1, NOMBREDUTILISATION,nb, -1);
}
fclose(h);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);

}
}
/*
char equip(){
FILE *f;
char code[30];
char type[30];
char etat[30];
date D;
int indice,test;
char eta[]='utiliser';
int i,j,max;
int n=0;
char m[50][3];
for (i=0;i<50;i++)
{for(j=0;j<3;j++)
{	m[i][j]=0;
}}
f=fopen("utilisation.txt","r+");
while(fscanf(f, "%s %s %s %d/%d/%d\n", code, type, etat, &D.jour,&D.mois, &D.annee) != EOF)
{
	indice=-1;
	test=0;
	i=0;
	while((i<=n)&&(test==0))
	{
		
		if(strcmp(etat,eta)==0)
			{
			indice=i;
			test=1;
			}
		i++;
	}

	//if(indice==-1)
	//{
		n++;
		strcpy(m[n-1][0],type);
		m[n-1][1]=test;
	//}
	/*else 
		{m[indice][1]+=p.stock;}
}*/
/*fclose(f);
max=0;
for(i=1;i<n;i++)
{
if(m[i][1]<m[max][1])
max=i;
}
return m[max][0];
}*/








