#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "ouvrier.h"


enum{SEXE,CIN,NOM,DATE,PRENOM,COLUMNS};

void DBaffichage(GtkWidget* DBtreeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
ouvrier o;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(DBtreeview);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (DBtreeview), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (DBtreeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (DBtreeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (DBtreeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de recrutement", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (DBtreeview), column);}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("ouvrier.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("ouvrier.bin","ab+");
while(fread(&o,sizeof(ouvrier),1,f))
{sprintf(Date,"%d/%d/%d",o.date.jour,o.date.mois,o.date.annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,SEXE,o.sexe,CIN,o.cin,NOM,o.nom,DATE,Date,PRENOM,o.prenom,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(DBtreeview),GTK_TREE_MODEL (store));
g_object_unref(store);}}


void presence (pointage p)
{FILE*f=NULL; 
f=fopen("pointage.txt","a+");
fprintf(f, "%s %d %d %d %d\n",p.cin,p.date.jour,p.date.mois,p.date.annee,p.present);  
fclose(f);}


void DBajout (ouvrier o){
FILE*f=NULL; 
f=fopen("ouvrier.bin","ab+");
fwrite(&o,sizeof(ouvrier),1,f);  
fclose(f);
 
}

void DBsuppression(char id[30],ouvrier o){
FILE*f;
FILE*g;
f=fopen("ouvrier.bin","rb+");
g=fopen("DBtmp.bin","wb+");
if(g!=NULL){
while(fread(&o,sizeof(ouvrier),1,f))
{
if (strcmp(o.cin,id)!=0){
fwrite(&o,sizeof(ouvrier),1,g);

}
}
}fclose(f);
fclose(g);
remove("ouvrier.bin");
rename("DBtmp.bin","ouvrier.bin");
}



void DBmodification(char id[30],ouvrier o)
{

	DBsuppression(id,o);
	DBajout(o);

}

void DBrecherche(GtkWidget* DBtreeview)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;ouvrier o;
 FILE *f2;char Date[100]; 
 store=gtk_tree_view_get_model(DBtreeview);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Sexe",renderer, "text",SEXE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(DBtreeview), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("CIN",renderer, "text",CIN,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(DBtreeview), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",NOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(DBtreeview), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(DBtreeview), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",PRENOM,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(DBtreeview), column);}
  
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f2=fopen("DBrecherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("DBrecherche.bin", "ab+");
    while(fread(&o,sizeof(ouvrier),1,f2))
     {sprintf(Date,"%d/%d/%d",o.date.jour,o.date.mois,o.date.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,SEXE,o.sexe,CIN,o.cin,NOM,o.nom,DATE,Date,PRENOM,o.prenom, -1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (DBtreeview), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}

