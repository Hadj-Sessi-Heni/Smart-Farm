#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"

capteur selected_capteur;
capterHist selected_capteurhist;
GtkWidget *COWindowHome;
  GtkWidget *COWindowAjout;
GtkWidget *COlabelTypeAjout;



void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_CObuttonAjouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{



FILE *t=NULL;
FILE *g=NULL;
GtkWidget *id,*mq,*tp,*min,*max,*idh,*windowAuth,*hum,*temp;
capteur C;
id = lookup_widget (objet_graphique,"COentryIDAjout");
mq = lookup_widget (objet_graphique,"COentryMarqueAjout");
//tp = lookup_widget (objet_graphique,"COentryTypeAjout");
min = lookup_widget (objet_graphique,"COspinbuttonValMinAjout");
max = lookup_widget (objet_graphique,"COspinbuttonValMaxAjout");


strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(mq)));

hum=lookup_widget (objet_graphique,"COradiobuttonHumAjout");
temp=lookup_widget (objet_graphique,"COradiobuttonTempAjout");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hum)))
{
strcpy(C.captType,"HUM");
}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(temp)))
{
strcpy(C.captType,"TEMP");
}


C.captValMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
C.captValMax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));




ajouter_capt(C);





}


void
on_CObuttonSupprimer_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *window1;
window1 = create_window1 ();
  gtk_widget_show (window1);
}


void
on_CObuttonRecherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COWindowHome;
GtkWidget *id,*mr;
id = lookup_widget (objet,"COentryIDRecherche");
mr = lookup_widget (objet,"COentryMarqueRecherche");
char IDs[20];
char Marques[20];

strcpy(IDs,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(Marques,gtk_entry_get_text(GTK_ENTRY(mr)));

GtkWidget *COtreeviewAffichage;
COWindowHome=lookup_widget (objet,"COWindowHome");


COtreeviewAffichage=lookup_widget (COWindowHome,"COtreeviewAffichage");

rechercher_capt(IDs,Marques,COtreeviewAffichage);





}


void
on_CObuttonAjoutHist_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
FILE *t=NULL;
FILE *g=NULL;
GtkWidget *jour,*mois,*annee,*val,*id;
capterHist h;

val = lookup_widget (objet_graphique,"COspinbuttonValAjout");
jour = lookup_widget (objet_graphique,"COspinbuttonJourAjout");
mois = lookup_widget (objet_graphique,"COspinbuttonMoisAjout");
annee = lookup_widget (objet_graphique,"COspinbuttonAnneeAjout");
id = lookup_widget (objet_graphique,"COcomboboxIDAjout");


strcpy(h.captIDhist,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));





h.captValEnr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val));
h.date_capteur.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
h.date_capteur.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
h.date_capteur.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


ajouter_capt_hist(h);
}


void
on_CObuttonDisponible_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
capteur C;
GtkWidget *idh;
idh = lookup_widget (objet_graphique,"COcomboboxIDAjout");
FILE *f;
    f=fopen("capteur.bin","rb") ;
    if (f !=NULL)
    {



    while(fread(&C,sizeof(capteur),1,f)!=0)
{
	gtk_combo_box_append_text(GTK_COMBO_BOX(idh),_(C.captID));

}

}
}


void
on_CObuttonModif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *COWindowModif;





GtkWidget *Add_Fact,*Main_Menue;
Add_Fact = create_COWindowModif ();
  gtk_widget_show (Add_Fact);


GtkWidget *id,*mq,*min,*max,*tp,*hum,*temp;
capteur c;


id = lookup_widget (Add_Fact,"COentryIDModif");
mq = lookup_widget (Add_Fact,"COentryMarqueModif");

min = lookup_widget (Add_Fact,"COspinbuttonValMinModif");
max = lookup_widget (Add_Fact,"COspinbuttonValMaxModif");


hum=lookup_widget (Add_Fact,"COradiobuttonHumModif");
temp=lookup_widget (Add_Fact,"COradiobuttonTempModif");


gtk_entry_set_text(id,selected_capteur.captID);
gtk_entry_set_text(mq,selected_capteur.captMarque);


gtk_spin_button_set_value(min,selected_capteur.captValMin);
gtk_spin_button_set_value(max,selected_capteur.captValMax);

if(strcmp(selected_capteur.captType,"TEMP")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(temp),1);
if(strcmp(selected_capteur.captType,"HUM")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hum),1);

}





void
on_CObuttonConfirmModif_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

capteur C;

GtkWidget *id,*mq,*tp,*min,*max,*idh,*COWindowHome,*hum,*temp;

id = lookup_widget (objet_graphique,"COentryIDModif");
mq = lookup_widget (objet_graphique,"COentryMarqueModif");

min = lookup_widget (objet_graphique,"COspinbuttonValMinModif");
max = lookup_widget (objet_graphique,"COspinbuttonValMaxModif");


strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(mq)));

hum=lookup_widget (objet_graphique,"COradiobuttonHumModif");
temp=lookup_widget (objet_graphique,"COradiobuttonTempModif");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hum)))
{
strcpy(C.captType,"HUM");
}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(temp)))
{
strcpy(C.captType,"TEMP");
}

C.captValMin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
C.captValMax=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));




supprimer_capt(C);
ajouter_capt(C);




}



void
on_CObuttonSupprimerHist_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *window2;
window2 = create_window2 ();
  gtk_widget_show (window2);
}


void
on_CObuttonModifHist_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *COWindowModif;




GtkWidget *Add_Fact,*Main_Menue;
Add_Fact = create_COwindowModifHist ();
  gtk_widget_show (Add_Fact);


GtkWidget *id,*jour,*mois,*annee,*val;
capterHist h;


id = lookup_widget (Add_Fact,"COentryIDModifHist");
val = lookup_widget (Add_Fact,"COspinbuttonValModif");

jour = lookup_widget (Add_Fact,"COspinbuttonJourMdif");
mois = lookup_widget (Add_Fact,"COspinbuttonMoisModif");
annee = lookup_widget (Add_Fact,"COspinbuttonAnneeModif");




gtk_entry_set_text(id,selected_capteurhist.captIDhist);

gtk_spin_button_set_value(val,selected_capteurhist.captValEnr);
gtk_spin_button_set_value(jour,selected_capteurhist.date_capteur.j);
gtk_spin_button_set_value(mois,selected_capteurhist.date_capteur.m);
gtk_spin_button_set_value(annee,selected_capteurhist.date_capteur.a);
}


void
on_CObuttonAfficheHist_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COWindowHome;

GtkWidget *COtreeviewAffichageHist;
COWindowHome=lookup_widget (objet,"COWindowHome");

COtreeviewAffichageHist=lookup_widget (COWindowHome,"COtreeviewAffichageHist");
afficher_capt_hist(COtreeviewAffichageHist);

}


void
on_CObuttonRechercheHist_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COWindowHome;
GtkWidget *id,*mr;
id = lookup_widget (objet,"COentryIDRechercheHist");
mr = lookup_widget (objet,"COentryMarqueRechercheHist");
char IDs[20];
char Marques[20];
strcpy(IDs,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(Marques,gtk_entry_get_text(GTK_ENTRY(mr)));

GtkWidget *COtreeviewAffichageHist;
COWindowHome=lookup_widget (objet,"COWindowHome");


COtreeviewAffichageHist=lookup_widget (COWindowHome,"COtreeviewAffichageHist");

rechercher_capt_hist(IDs,Marques,COtreeviewAffichageHist);
}


void
on_COtreeviewAffichageHist_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                        
{
gchar *str_datah;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_datah,-1);

}
strcpy(selected_capteurhist.captIDhist,str_datah);

FILE *f;capterHist h;
f=fopen("capteurHistorique.bin","rb");
while(!feof(f))
	{
	fread(&h,sizeof(capterHist),1,f);
	if(strcmp(selected_capteurhist.captIDhist,h.captIDhist)==0){selected_capteurhist=h;}	
	}
fclose(f);

}


void
on_CObuttonConfirmModifHist_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*jour,*mois,*annee,*val;
capterHist h;
capteur C;

id = lookup_widget (objet_graphique,"COentryIDModifHist");
val = lookup_widget (objet_graphique,"COspinbuttonValModif");

jour = lookup_widget (objet_graphique,"COspinbuttonJourMdif");
mois = lookup_widget (objet_graphique,"COspinbuttonMoisModif");
annee = lookup_widget (objet_graphique,"COspinbuttonAnneeModif");

strcpy(h.captIDhist,gtk_entry_get_text(GTK_ENTRY(id)));



strcpy(h.captMarquehist,C.captMarque);



h.captValEnr=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val));

h.date_capteur.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

h.date_capteur.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
h.date_capteur.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

//modifier_capt(C);
supprimer_capt_hist(h);
ajouter_capt_hist(h);

}


void
on_CObuttonRetourModifHist_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COwindowModifHist;
COwindowModifHist=lookup_widget(objet,"COwindowModifHist");
gtk_widget_destroy(COwindowModifHist);
}


void
on_CObuttonRetour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COWindowModif;
COWindowModif=lookup_widget(objet,"COWindowModif");
gtk_widget_destroy(COWindowModif);
}


void
on_CObuttonAfficherAlarm_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
int jo,mo,an;
GtkWidget *COwindowAlarmants,*jour,*mois,*annee;

jour = lookup_widget (objet,"spinbutton1");
mois = lookup_widget (objet,"spinbutton2");
annee = lookup_widget (objet,"spinbutton3");

jo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
mo=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
an=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

GtkWidget *list1;
COwindowAlarmants=lookup_widget (objet,"COwindowAlarmants");

list1=lookup_widget (COwindowAlarmants,"list1");
afficher_captAlarm(jo,mo,an,list1);
}


void
on_CObuttonAfficherDefec_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *COwindowDefec,*hum,*temp;
capteurDefec d;
GtkWidget *list2;
COwindowDefec=lookup_widget (objet,"COwindowDefec");

list2=lookup_widget (COwindowDefec,"list2");
//marque_defec(d);
afficher_captdefec(list2);

}


void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"window1");
gtk_widget_destroy (window1);
}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"window1");


supprimer_capt(selected_capteur);



GtkWidget *tree;
tree=lookup_widget(window1,"COtreeviewAffichage");
afficher_capt(tree);
gtk_widget_destroy (window1);
}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2=lookup_widget(button,"window2");


supprimer_capt_hist(selected_capteurhist);



GtkWidget *tree;
tree=lookup_widget(window2,"COtreeviewAffichageHist");
afficher_capt_hist(tree);
gtk_widget_destroy (window2);
}


void
on_button31_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2=lookup_widget(button,"window2");
gtk_widget_destroy (window2);
}

