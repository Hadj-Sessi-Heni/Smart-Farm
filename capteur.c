#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>


void ajouter_capt(capteur C)
{

FILE *f=NULL;
FILE *t=NULL;
FILE *g=NULL;
f=fopen("capteurHum.bin","a+b") ;
t=fopen("capteurTemp.bin","a+b") ;
g=fopen("capteur.bin", "a+b"); 
char a[]="TMP";
char b[]="HUM";
if((f!=NULL)&&(t!=NULL))
{

    
   
   fwrite(&C,sizeof(capteur),1,g);
	if (strcmp(C.captType,a)==0)
	{
 		 fwrite(&C,sizeof(capteur),1,t);
	}else
	if (strcmp(C.captType,b)==0) {
   	
    	fwrite(&C,sizeof(capteur),1,f);
	}

fclose(t);
fclose(f);
fclose(g);
}
else
printf("\n Not found");
}

/*
f=fopen("capteurHum.bin","rb") ;
t=fopen("capteurTemp.bin","rb") ; 
  
   // Open file to store the result 
   FILE *g = fopen("capteur.bin", "a+b"); 
   char v; 
  
   if (f == NULL || t == NULL || g == NULL) 
   { 
          
         exit(0); 
   } 
  
   // Copy contents of first file to file3.txt 
   while ((v = fgetc(f)) != EOF) 
      fputc(v, g); 
  
   // Copy contents of second file to file3.txt 
   while ((v = fgetc(t)) != EOF) 
      fputc(v, g); 
  
   
  
   fclose(f); 
   fclose(t); 
   fclose(g); 

*/
//*************************************************
void ajouter_capt_hist(capterHist h)
{
capteur C;
char ID[20];
char captType[20];
capteur c;
FILE *j=NULL;
FILE *f=NULL;
FILE *t=NULL;
FILE *g=NULL;
j=fopen("capteur.bin","rb");
f=fopen("capteurHumHistorique.bin","a+b") ;
t=fopen("capteurTempHistorique.bin","a+b") ;
g=fopen("capteurHistorique.bin", "a+b"); 
char a[]="TMP";
char b[]="HUM";
if(g!=NULL)
{

    

	while(fread(&C,sizeof(capteur),1,j)!=0)
	{
strcpy(h.captMarquehist,C.captMarque);
		
 		if((strcmp(C.captID,h.captIDhist)==0))
		{
			
		    /*strcpy(h.captIDhist,ID);
		    printf("valeur enregistre par le capteur:");
		    scanf("%d",&h.captValEnr);
		    printf("date de l'enregistrement de cette valeur :\n ");
		    printf("jour: ");
		    scanf("%d",&h.date_capteur.j);
		    printf(" Mois: ");
		    scanf("%d",&h.date_capteur.m);
		    printf(" Annee: ");
		    scanf("%d",&h.date_capteur.a);*/
		   	 if ((h.captValEnr >=C.captValMin)&&(h.captValEnr <=C.captValMax))
				{
					
					h.etatDefece=0;
				}else {h.etatDefece=1;}
		    fwrite(&h,sizeof(capterHist),1,g);
			/*if (strcmp(captType,a)==0)
			{
  				fwrite(&h,sizeof(capterHist),1,t);
			}else
			if (strcmp(C.captType,b)==0) {
   	
    			fwrite(&h,sizeof(capterHist),1,f);
			}*/
		}
		}
		fclose(t);
		fclose(f);
		fclose(g);
}
else
printf("\n Not found");

}



//*************************************************
enum
{

     ID,
     MARQUE,
     TYPE,
     MAXIMUM,
     MINIMUM,
     COLUMNS
};
void afficher_capt(GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capteur a;

	char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("TYPE",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MINIMUM",renderer, "text",MINIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MAXIMUM",renderer, "text",MAXIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteur.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteur.bin","rb") ;


    while(fread(&a,sizeof(capteur),1,f)!=0)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,a.captID,MARQUE,a.captMarque,TYPE,a.captType,MINIMUM,a.captValMin,MAXIMUM,a.captValMax,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);





}
}

//*****************************************************
enum
{

     IDM,
     VALEUR,
     MARQUEM,
     JOUR,
     MOIS,
     ANNEE,
     ETAT,
     COLUMNSM
};


void afficher_capt_hist(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capterHist b;

	char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;	

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",IDM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("VALEUR",renderer, "text",VALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUEM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("JOUR",renderer, "text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MOIS",renderer, "text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ANNEE",renderer, "text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ETAT(1 defec/0 non defec)",renderer, "text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
}

	store=gtk_list_store_new(COLUMNSM,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteurHistorique.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteurHistorique.bin","rb") ;


    while(fread(&b,sizeof(capterHist),1,f)!=0)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,IDM,b.captIDhist,VALEUR,b.captValEnr,MARQUEM,b.captMarquehist,JOUR,b.date_capteur.j,MOIS,b.date_capteur.m,ANNEE,b.date_capteur.a,ETAT,b.etatDefece,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);





}
}


//****************************************************
void supprimer_capt(capteur C)

{
char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;
FILE *f;
FILE *c;

capteur s;
f=fopen("capteur.bin","rb");

c=fopen("tempo.bin","ab");


    if (f==NULL || c==NULL )
    {
	return;
    }
    else{
    	while (fread(&s,sizeof(capteur),1,f)!=0)
    {



	
	if(strcmp(C.captID,s.captID)!=0 )
        fwrite(&s,sizeof(capteur),1,c);




    }
	
   
fclose(c);
fclose(f);
remove("capteur.bin");
rename("tempo.bin","capteur.bin");
}
}

//*******************************************
void supprimer_capt_hist(capterHist h)

{
char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;
FILE *f;
FILE *c;

capterHist d;
f=fopen("capteurHistorique.bin","rb");

c=fopen("tempoHistorique.bin","ab");


    if (f==NULL || c==NULL )
    {
	return;
    }
    else{
    	while (fread(&d,sizeof(capterHist),1,f)!=0)
    {



	
	if(strcmp(h.captIDhist,d.captIDhist)!=0 )
        fwrite(&d,sizeof(capterHist),1,c);




    }
	
   
fclose(c);
fclose(f);
remove("capteurHistorique.bin");
rename("tempoHistorique.bin","capteurHistorique.bin");
}
}













//*******************************************
void modifier_capt(capteur C)

{

FILE *f;
FILE *c;

capteur s;
f=fopen("capteur.bin","rb");

c=fopen("tempo.bin","ab");


    if (f==NULL || c==NULL )
    {
	return;
    }
    else{

    while (fread(&C,sizeof(capteur),1,f)!=0)
    {



	
	if(strcmp(s.captID,C.captID)==0)
        {
 
   
	fwrite(&s,sizeof(capteur),1,c);
	}
	else
	fwrite(&C,sizeof(capteur),1,c);
    
    }
	
fclose(c);
fclose(f);
remove("capteur.bin");
rename("tempo.bin","capteur.bin");
}

}


//***********************************************************
void rechercher_capt(char IDa[20],char Marque[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capteur a;

	

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("TYPE",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MINIMUM",renderer, "text",MINIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MAXIMUM",renderer, "text",MAXIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
}

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteur.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteur.bin","rb") ;


    while(fread(&a,sizeof(capteur),1,f)!=0)
{
	if((strcmp(a.captID,IDa)==0)&& strcmp(a.captMarque,Marque)==0)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,a.captID,MARQUE,a.captMarque,TYPE,a.captType,MINIMUM,a.captValMin,MAXIMUM,a.captValMax,-1);
	}
	}
	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	g_object_unref(store);

}
}

void rechercher_capt_hist(char IDe[20],char Marque[20],GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capterHist b;

	
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("IDM",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("VALEUR",renderer, "text",VALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUEM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("JOUR",renderer, "text",JOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MOIS",renderer, "text",MOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ANNEE",renderer, "text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ETAT(1 defec/0 non defec)",renderer, "text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
}

	store=gtk_list_store_new(COLUMNSM,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteurHistorique.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteurHistorique.bin","rb") ;


    while(fread(&b,sizeof(capterHist),1,f)!=0)
{
	if((strcmp(b.captIDhist,IDe)==0 && strcmp(b.captMarquehist,Marque)==0))
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,IDM,b.captIDhist,VALEUR,b.captValEnr,MARQUEM,b.captMarquehist,JOUR,b.date_capteur.j,MOIS,b.date_capteur.m,ANNEE,b.date_capteur.a,ETAT,b.etatDefece,-1);
	}
	}

	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);


}
}



void affiche_captTemp(GtkWidget *liste)
{
char Temp[20]="TEMP";
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capteur a;

	char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("TYPE",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MINIMUM",renderer, "text",MINIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MAXIMUM",renderer, "text",MAXIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
}

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteur.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteur.bin","rb") ;


    while(fread(&a,sizeof(capteur),1,f)!=0)
{
	if((strcmp(a.captType,Temp)==0))
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,a.captID,MARQUE,a.captMarque,TYPE,a.captType,MINIMUM,a.captValMin,MAXIMUM,a.captValMax,-1);
	}
	}
	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	g_object_unref(store);





}
}

void affiche_captHum(GtkWidget *liste)
{
char Hum[20]="HUM";
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capteur a;

	char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("TYPE",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MINIMUM",renderer, "text",MINIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MAXIMUM",renderer, "text",MAXIMUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteur.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteur.bin","rb") ;


    while(fread(&a,sizeof(capteur),1,f)!=0)
{
	if((strcmp(a.captType,Hum)==0))
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,a.captID,MARQUE,a.captMarque,TYPE,a.captType,MINIMUM,a.captValMin,MAXIMUM,a.captValMax,-1);
	}
	}
	
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

	g_object_unref(store);

}
}

enum
{

     IDA,
     VALEURA,
     JOURA,
     MOISA,
     ANNEEA,
     
     COLUMNSA
};

void afficher_captAlarm(int Jour,int Mois, int Annee,GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	capterHist b;

	

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",IDA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("VALEUR",renderer, "text",VALEURA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("JOUR",renderer, "text",JOURA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MOIS",renderer, "text",MOISA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ANNEE",renderer, "text",ANNEEA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	
}

	store=gtk_list_store_new(COLUMNSA,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    
    
    f=fopen("capteurHistorique.bin","rb") ;
    if (f ==NULL)
    {
	return;
    }else
    {f=fopen("capteurHistorique.bin","rb") ;


    while(fread(&b,sizeof(capterHist),1,f)!=0)
{
        if (b.etatDefece==1)
{
         if ((b.date_capteur.j==Jour) && (b.date_capteur.m==Mois) && (b.date_capteur.a==Annee))
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,IDA,b.captIDhist,VALEURA,b.captValEnr,JOURA,b.date_capteur.j,MOISA,b.date_capteur.m,ANNEEA,b.date_capteur.a,-1);
	}
	}
}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);





}
}


enum
{

     MARQUED,
     NBR,
     COLUMNSD
};

void marque_defec(capteurDefec d)
{
capterHist h;
FILE *f=NULL;
FILE *t=NULL;
f=fopen("capteurHistorique.bin","rb");
t=fopen("capteurdefec.bin","a+b") ;

while (fread(&h,sizeof(capterHist),1,f)!=0)
{
   if (h.etatDefece==1)
{
strcpy(d.captMarquedefec,h.captMarquehist);
d.nbr++;

fwrite(&d,sizeof(capteurDefec),1,t);
}

fclose(f);
fclose(t);
}
}

//************************************************************
void afficher_captdefec(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
	
	

store=NULL;



int i,j,d;


char tab[200][200];

capterHist h;
FILE *f=NULL;
FILE *t=NULL;
f=fopen("capteurHistorique.bin","rb");
t=fopen("capteurdefec.bin","a+b") ;

while (fread(&h,sizeof(capterHist),1,f)!=0)
{
   if (h.etatDefece==1)
{
	d++;

	strcpy(tab[d],h.captMarquehist);

	}


}
fclose(f);

int maxCount, count;
char maxElement[50];
    maxCount = 0;

    for(i = 0; i<= d; i++){
        count = 1;
        for(j = i+1; j <= d; j++){
            if(strcmp(tab[j],tab[i])==0){
                count++;

                if(count >= maxCount){
                    maxCount = count;
                    strcpy(maxElement,tab[j]);
                }
            }
        }
    }
  



store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MARQUE",renderer, "text",MARQUED,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nombre des capteur defectueux",renderer, "text",NBR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}

	store=gtk_list_store_new(COLUMNSD,G_TYPE_STRING,G_TYPE_INT);
    
    
    
	
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,MARQUED,maxElement,NBR,maxCount,-1);
	
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);





}
