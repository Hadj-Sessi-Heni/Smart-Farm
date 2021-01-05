
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
#include <time.h>

#include <stdio.h>




enum
{
	ID,
	TYPE,
	VACCIN,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	INFOSUP,
	COLUMNS

};

/*int nb_troupeaux(char type[])
{

  FILE* F;

troupeau n;
int nb=0;


F=fopen("troupeau.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F, "%s %s %s %d %d %d %s\n",n.id,n.type,n.vaccin,n.sexe,&n.d.jour,&n.d.mois,&n.d.annee,n.infosupp)!=EOF)
    {
      if(strcmp(n.type,type)==0)
      nb++;
    }
fclose(F);
return(nb);


}
}

*/




//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
///////////////////////////////////////////////////
void ajouter(troupeau A)

{
int id;
FILE *f;
f=fopen("troupeau.txt","a+");
	if(f!=NULL)
	{
	 fprintf(f," %s %s %s %s %d %d %d %s \n",A.id,A.type,A.vaccin,A.sexe,A.d.jour,A.d.mois,A.d.annee,A.infosupp);
	 fclose(f);
	}








}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
///////////////////////////////////////////
void supp(char id[])
{
  
  FILE *F, *FW;
  troupeau p ;
 
F = fopen ("troupeau.txt", "r");
FW = fopen ("trp.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf(F,"%s %s %s %s %d %d %d %s \n",p.id,p.type,p.vaccin,p.sexe,&p.d.jour,&p.d.mois,&p.d.annee,p.infosupp)!=EOF)
    if  (strcmp(p.id,id)!=0) 
      fprintf (FW, "%s %s %s %s %d %d %d %s \n",p.id,p.type,p.vaccin,p.sexe,p.d.jour,p.d.mois,p.d.annee,p.infosupp);
}
  fclose (F);
  fclose (FW);
remove("troupeau.txt");
rename("trp.txt", "troupeau.txt");



}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
////////////////////////////////////
troupeau rech(char id[])
{

FILE *F;
  troupeau Q;
  troupeau A;
  
F = fopen ("troupeau.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %d %d %d %s \n",Q.id,Q.type,Q.vaccin,Q.sexe,&Q.d.jour,&Q.d.mois,&Q.d.annee,Q.infosupp)!=EOF)
{
    if (strcmp (Q.id, id) == 0)
        {
	A.d.jour=Q.d.jour;
	A.d.mois=Q.d.mois;
	A.d.annee=Q.d.annee;
        strcpy(A.type,Q.type);
        strcpy(A.vaccin,Q.vaccin);
        strcpy(A.sexe,Q.sexe);
        strcpy(A.infosupp,Q.infosupp);
        }
        }
    
}
return (A);
  fclose (F);
}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////
void modi(char id [] , troupeau U) 
{

   FILE *F, *FW;
  troupeau c; 
  
F = fopen ("troupeau.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s %s %s %d %d %d %s \n",c.id,c.type,c.vaccin,c.sexe,&c.d.jour,&c.d.mois,&c.d.annee,c.infosupp)!=EOF)
    if (strcmp (c.id, id) == 0)
     {
fprintf (FW, "%s %s %s %s %d %d %d %s \n",id,U.type,U.vaccin,U.sexe,U.d.jour,U.d.mois,U.d.annee,U.infosupp);

     }
     else
     {
       fprintf (FW, "%s %s %s %s %d %d %d %s \n",c.id,c.type,c.vaccin,c.sexe,c.d.jour,c.d.mois,c.d.annee,c.infosupp);
     }
}    

  fclose (F);
  fclose (FW);
remove("troupeau.txt");
rename("tr.txt", "troupeau.txt");




}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////////
void afficher (GtkWidget *liste )
{
	
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;

char id [20];
char type[30];
char sexe[30];
char vaccin[30];
char jour[20];
char mois[20];
char annee[20];
char infosupp[30];



store=NULL;



FILE *f;



store = gtk_tree_view_get_model(liste);



if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("vaccin",renderer,"text",VACCIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("infosupp",renderer,"text",INFOSUP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("troupeau.txt","r");

if(f==NULL)

{

return;

}

else

{

f=fopen("troupeau.txt","a+");

while(fscanf(f," %s %s %s %s %s %s %s %s\n",id,type,vaccin,sexe,jour,mois,annee,infosupp)!=EOF)

{

gtk_list_store_append(store,&iter);

gtk_list_store_set(store, &iter, ID,id , TYPE,type, VACCIN,vaccin, SEXE,sexe , JOUR,jour, MOIS,mois, ANNEE,annee , INFOSUP,infosupp, -1);

}

fclose(f);

gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));

g_object_unref (store);

}
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////authentification////////////////
enum 
{
CIN,
MDP,
COL
};

void ajouter_aut(aut y)
{

FILE *f;
f=fopen("aut.txt","a+");
	if(f!=NULL)
	{
		fprintf(f," %s %s \n",y.login,y.mdp);
	 fclose(f);
	}
}
	



////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void afficher_aut (GtkWidget *liste )
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
aut y;

char login[60];
char mdp[60];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Login (CIN)",renderer, "text",CIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
column=gtk_tree_view_column_new_with_attributes("Mot de Passe",renderer, "text",MDP,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("aut.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("aut.txt","a+");
	while(fscanf(f," %s %s\n",login,mdp)!=EOF)
	{
        gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter ,CIN,login,MDP,mdp,-1);

}
	fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}





























