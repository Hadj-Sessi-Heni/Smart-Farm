#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fonction_emp.h"
#include <gtk/gtk.h>
enum
{	
	CIN,
	NOM,
	PRENOM,
	AGE,
	DATE,
	SEXE,
	ADRESS,
	MAIL,
	TEL,
	COLUMNS
};
/////////////////Ajouter////////////////////
void ajouter_employe(employe e)
{
FILE *f=NULL;
f=fopen("employe.bin","a+b");
if(f!=NULL)
fwrite(&e,sizeof(employe),1,f);
fclose(f);
}

/////////////////Afficher///////////////////
void afficher_employe(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[8];
	char sexe[8];//1:homme 2:femme
	char adress[20];
	char password[20];
	char mail[30];
	char tel[8];

employe e;
FILE *f;
store=NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date_ambauche",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mail",renderer,"text",MAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("employe.bin","rb");
if(f==NULL)
{
return;
}
else
{

f=fopen("employe.bin","rb");
		while(fread(&e,sizeof(employe),1,f)!=0)
{

char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}

}

/////////////////Supprimer/////////////////// 
void supprimer_employe(employe e)
{
FILE *f,*g;
employe E;
f=fopen("employe.bin","rb");
g=fopen("dump.bin","ab");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while (fread(&E,sizeof(employe),1,f)!=0)
	{
	if(strcmp(e.cin,E.cin)!=0 )
	fwrite(&E,sizeof(employe),1,g);	
	}
fclose(f);
fclose(g);
remove("employe.bin");
rename("dump.bin","employe.bin");
}
}

/////////////////Modifier///////////////////
void modifier_employe(employe e)
{
FILE *f,*g;
employe E;
f=fopen("employe.bin","rb");
g=fopen("dump.bin","ab");
if (f==NULL || g==NULL)
{
return;
}
else
{ 
	while (fread(&E,sizeof(employe),1,f)!=0)
	{
	if(strcmp(e.cin,E.cin)!=0 )
	fwrite(&E,sizeof(employe),1,g);	
	
	}
fwrite(&e,sizeof(employe),1,g);
fclose(f);
fclose(g);
remove("employe.bin");
rename("dump.bin","employe.bin");
}
}

/////////////////Chercher///////////////////
void chercher_employe(char c[8],GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[8];
	char sexe[8];//1:homme 2:femme
	char adress[20];
	char password[20];
	char mail[30];
	char tel[8];

employe e;
FILE *f;
store=NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date_ambauche",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mail",renderer,"text",MAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("employe.bin","rb");
if(f==NULL)
{
return;
}
else
{

//f=fopen("employe.bin","rb");
		while(fread(&e,sizeof(employe),1,f)!=0)
{
if (strcmp(e.cin,c)==0)
{char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}

}

/////////////////Chercher_type///////////////////
/*void chercher_type_employe(int s,int n,int p,int z,char k[20], char l[20],GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[8];
	char sexe[8];//1:homme 2:femme
	char adress[20];
	char password[20];
	char mail[30];
	char tel[8];

employe e;
FILE *f;
store=NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("age",renderer,"text",AGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date_ambauche",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mail",renderer,"text",MAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("employe.bin","rb");
if(f==NULL)
{
return;
}
else
{

//f=fopen("employe.bin","rb");
		while(fread(&e,sizeof(employe),1,f)!=0)
{
if (p==0){
if(n==0){
if (s==1){
if (z==1){
if (strcmp(e.sexe,"homme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

else if (z==2){
if (strcmp(e.sexe,"femme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

}

}
else if(n==1){
if (strcmp(e.nom,k)==0){
if (s==1){
if (z==1){
if (strcmp(e.sexe,"homme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

else if (z==2){
if (strcmp(e.sexe,"femme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

}
else if(s==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}
}
}
}
else if (p==1){
if (strcmp(e.prenom,l)==0){
if(n==0){
if (s==1){
if (z==1){
if (strcmp(e.sexe,"homme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

else if (z==2){
if (strcmp(e.sexe,"femme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

}

}
else if(n==1){
if (strcmp(e.nom,k)==0){
if (s==1){
if (z==1){
if (strcmp(e.sexe,"homme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

else if (z==2){
if (strcmp(e.sexe,"femme")==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}

}

}
else if(s==0){
char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CIN, e.cin, NOM, e.nom, PRENOM, e.prenom, AGE, e.age, DATE, date_ambauche, SEXE, e.sexe, ADRESS, e.adress, MAIL, e.mail, TEL, e.tel ,-1);
}
}
}
}
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}

}

*/

enum
{	
	CINs,
	NOMs,
	PRENOMs,
	COLUMN
};
void afficher_employe_ab(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;


	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[8];
	char sexe[8];//1:homme 2:femme
	char adress[20];
	char password[20];
	char mail[30];
	char tel[8];

employe e;
FILE *f;
store=NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CINs,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOMs,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMs,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



}
store=gtk_list_store_new(COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("employe.bin","rb");
if(f==NULL)
{
return;
}
else
{

f=fopen("employe.bin","rb");
		while(fread(&e,sizeof(employe),1,f)!=0)
{

/*char date_ambauche[15];
char cjour[10],cmois[10],cannee[10];
sprintf(cjour,"%d",e.date_amb.jour);
sprintf(cmois,"%d",e.date_amb.mois);
sprintf(cannee,"%d",e.date_amb.annee);
	strcpy(date_ambauche,cjour);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cmois);
	strcat(date_ambauche,"-");
	strcat(date_ambauche,cannee);*/
gtk_list_store_append(store,&iter);
gtk_list_store_set(store, &iter, CINs, e.cin, NOMs, e.nom, PRENOMs, e.prenom,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}

}
//////////
float calcul_absenteisme_emp(employe e)
{
absent a;
int ab=0,pr=0;
float c;
FILE *f=NULL;
f=fopen("absenteisme.bin","rb");
if(f!=NULL){
return;}
else {
f=fopen("absenteisme.bin","rb");
while(fread(&e,sizeof(employe),1,f)!=0){
if (strcmp(e.cin,a.cin)==0){
if (a.val==0){ab++;}
else{pr++;}



}
}
}
fclose(f);
c=(float)ab/(float)(pr+ab);
return c;
}
/////////////////
int exist_employe(char *cin){
FILE*f=NULL;
employe e;
f=fopen("employe.bin","rb"); 
	while(fread(&e,sizeof(employe),1,f)!=0){
if(strcmp(e.cin,cin)==0)
return 1;   
}
fclose(f);
return 0;
}



