#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouvrier.h"
char id[30],idrech[30];
GtkWidget *windowouvrier;
int x=1;


void
on_DBbuttonrechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
ouvrier o;
GtkWidget *windowouvrier;
GtkWidget *DBentrycin;
GtkWidget *DBtreeview;
FILE*f;
FILE*f2;


windowouvrier=lookup_widget(button,"windowouvrier");
DBentrycin=lookup_widget(button,"DBentrycin");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(DBentrycin)));
f=fopen("ouvrier.bin","rb");

 if(f!=NULL)
 {
  while(fread(&o,sizeof(ouvrier),1,f))
     {
       f2=fopen("DBrecherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if ((strcmp(o.cin,idrech)==0))
     { 
     fwrite(&o,sizeof(ouvrier),1,f2);
     }
   
     DBtreeview=lookup_widget(windowouvrier,"DBtreeview");
     DBrecherche(DBtreeview);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("DBrecherche.bin");
}


void
on_DBtreeview_row_activated            (GtkTreeView     *DBtreeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
gchar *cin;
        gchar *nom;
        gchar *prenom;

	GtkTreeModel *Model = gtk_tree_view_get_model(DBtreeview);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);
				gtk_tree_model_get (Model,&iter,1,&cin,2,&nom,4,&prenom,-1);//recuperer les information de la ligne selectionneé
		//remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowouvrier,"DBentrymodifcin")),cin);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowouvrier,"DBentrymodifnom")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(windowouvrier,"DBentrymodifprenom")),prenom);
		
}
}


void
on_DBbuttonactualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *DBtreeview;
windowouvrier=lookup_widget(button,"windowouvrier");
DBtreeview=lookup_widget(windowouvrier,"DBtreeview");
DBaffichage(DBtreeview);
}


void
on_DBbuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
ouvrier o;
    GtkWidget *DBtreeview;
	    windowouvrier=lookup_widget(button,"windowouvrier");
	    DBtreeview=lookup_widget(windowouvrier,"DBtreeview");
	    DBsuppression(id,o);
            DBaffichage(DBtreeview);
}


void
on_DBbuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowouvrier,"DBnotebook")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowouvrier,"DBnotebook")));
}


void
on_DBbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
ouvrier o;char Type[30];
GtkWidget *DBentryajoutcin;
GtkWidget *DBentryajoutnom;
GtkWidget *DBentryajoutprenom;
GtkWidget *DBspinbuttonajoutjour;
GtkWidget *DBspinbuttonajoutmois;
GtkWidget *DBspinbuttonajoutannee;
GtkWidget *DBcomboboxajoutsexe;
GtkWidget *sortiea;

DBspinbuttonajoutjour=lookup_widget(button, "DBspinbuttonajoutjour");
DBspinbuttonajoutmois=lookup_widget(button, "DBspinbuttonajoutmois");
DBspinbuttonajoutannee=lookup_widget(button, "DBspinbuttonajoutannee");
DBcomboboxajoutsexe=lookup_widget(button, "DBcomboboxajoutsexe");
DBentryajoutcin=lookup_widget(button,"DBentryajoutcin");
DBentryajoutnom=lookup_widget(button,"DBentryajoutnom");
DBentryajoutprenom=lookup_widget(button,"DBentryajoutprenom");
sortiea=lookup_widget(button, "DBlabelmsgsucc");

strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(DBentryajoutcin)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(DBentryajoutnom)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(DBentryajoutprenom)));
o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutjour));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutmois));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonajoutannee));

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(DBcomboboxajoutsexe)));
strcpy(o.sexe,Type);
DBajout(o);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");
}


void
on_DBbuttonconfirmermodif_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
ouvrier o;char Type[30];
GtkWidget *DBcomboboxmodifsexe;
GtkWidget *DBentrymodifcin;
GtkWidget *DBentrymodifnom;
GtkWidget *DBspinbuttonmodifjour;
GtkWidget *DBspinbuttonmodifmois;
GtkWidget *DBspinbuttonmodifannee;
GtkWidget *DBentrymodifprenom;
GtkWidget *sortiem;    
	
DBspinbuttonmodifjour=lookup_widget(button, "DBspinbuttonmodifjour");
DBspinbuttonmodifmois=lookup_widget(button, "DBspinbuttonmodifmois");
DBspinbuttonmodifannee=lookup_widget(button, "DBspinbuttonmodifannee");
DBcomboboxmodifsexe=lookup_widget(button, "DBcomboboxmodifsexe");
DBentrymodifcin=lookup_widget(button,"DBentrymodifcin");
DBentrymodifnom=lookup_widget(button,"DBentrymodifnom");
DBentrymodifprenom=lookup_widget(button,"DBentrymodifprenom");
sortiem=lookup_widget(button, "DBlabelmodifreus");

strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(DBentrymodifcin)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(DBentrymodifnom)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(DBentrymodifprenom)));
o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifjour));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifmois));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(DBspinbuttonmodifannee));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(DBcomboboxmodifsexe)));
strcpy(o.sexe,Type);
DBmodification(id,o);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectuée avec succès!");
}
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){x=1;}

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){x=0;}

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
pointage p;
GtkWidget *cinn;
GtkWidget *jourr;
GtkWidget *moiss;
GtkWidget *anneee;
cinn=lookup_widget(button,"entry1");
jourr=lookup_widget(button, "spinbutton1");
moiss=lookup_widget(button, "spinbutton2");
anneee=lookup_widget(button, "spinbutton3");


strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));
p.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr));
p.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiss));
p.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneee));


if(x==1)
{p.present=1;}

else 
{p.present=0;}
presence ( p);


}



void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *sortiem;
GtkWidget *ta;
GtkWidget *pourcent ;
int mm;
int aa;
pointage p;
int tauxpresence=0;
char tauxtxt[200];
double absence;
double i=0;
float tauxabsence;
FILE *f=NULL;
mois=lookup_widget(button, "spinbutton4");
annee=lookup_widget(button, "spinbutton5");
mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
aa=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
sortiem=lookup_widget(button, "label35");
ta=lookup_widget(button, "label38");
pourcent=lookup_widget(button, "label39");

    f=fopen("pointage.txt","r");
    if(f!=NULL)
    {
        while((fscanf(f, "%s %d %d %d %d",p.cin,&p.date.jour,&p.date.mois,&p.date.annee,&p.present)!=EOF))

{
if((p.date.mois==mm)&&(p.date.annee==aa))

{
i++;
tauxpresence=tauxpresence+p.present;
}
}
fclose(f);
}
absence=i-tauxpresence;
tauxabsence=(absence/i)*100;

sprintf(tauxtxt,"%.2f",tauxabsence);
gtk_label_set_text(GTK_LABEL(ta),"Le taux d`absence est :");
gtk_label_set_text(GTK_LABEL(pourcent),"%");
gtk_label_set_text(GTK_LABEL(sortiem),tauxtxt);

return 0;
}


