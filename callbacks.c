#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipement.h"

Equipement selected_eq;
GtkTreeSelection *selection1;
void
on_Ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout;
GtkWidget *window;
window= create_Ajout ();
  gtk_widget_show (window);

}


void
on_valider_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
Equipement E;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *fenetre_ajout;
GtkWidget *treeview1;


fenetre_ajout=lookup_widget(objet,"dashboard");
input1=lookup_widget(objet,"Code");
input2=lookup_widget(objet,"Type");
input3=lookup_widget(objet,"Marque");
input4=lookup_widget(objet,"annee");
input5=lookup_widget(objet,"Matricule");
input6=lookup_widget(objet,"etat");


strcpy(E.Code,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(E.Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
strcpy(E.annee_dachat,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(E.Matricule,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(E.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
ajouter(E);
GtkWidget *ajout;
GtkWidget *window;
window= create_dashboard ();
  gtk_widget_show (window);
treeview1=lookup_widget(window,"treeview1");

affiche(treeview1);
}



void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
GtkWidget *treeview1;
fenetre_afficher=lookup_widget(objet,"Ajout");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_dashboard ();
gtk_widget_show(fenetre_ajout);
treeview1=lookup_widget(fenetre_ajout,"treeview1");

affiche(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Code;
	gchar* Type;
	gchar* Marque;
	gchar* annee_dachat;
	gchar* Matricule;
	gchar* etat;
	Equipement p;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &Code,1,&Type,2,&Marque,3,&annee_dachat,4,&Matricule,5,&etat,-1);
	strcpy(p.Code,Code);
	strcpy(p.Type,Type);
	strcpy(p.Marque,Marque);
	strcpy(p.annee_dachat,annee_dachat);
	strcpy(p.Matricule,Matricule);
 	strcpy(p.etat,etat);
	
	}
selected_eq=p;
GtkWidget *dashboard;
dashboard=create_dashboard ();
 GtkWidget *E=lookup_widget(dashboard,"treeview1");

 selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(E));
}





/*void
on_Afficher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"dashboard");
fenetre_afficher=create_dashboard ();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");

affiche(treeview1);
}*/



void
on_rechercher_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
char ref[30];
GtkWidget *dialog;
GtkWidget *input;
GtkWidget *treeview1;
input=lookup_widget(objet,"id");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));

dialog=lookup_widget (objet,"dashboard");
treeview1=lookup_widget (objet,"treeview1");
rechercher(ref,treeview1);
}


void
on_actualiser_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"dashboard");
fenetre_afficher=lookup_widget(objet,"dashboard");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=create_dashboard ();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

affiche(treeview1);
}


void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)

{
GtkWidget *fenetre_ajout;
GtkWidget *dial;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"dashboard");
dial=lookup_widget(objet,"dialog1");
gtk_widget_destroy(fenetre_ajout);
dial=create_dialog1 ();
gtk_widget_show(dial);

}



void
on_cancel_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *dial;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"dashboard");
dial=lookup_widget(objet,"dialog1");
gtk_widget_destroy(dial);
fenetre_ajout=create_dashboard ();
gtk_widget_show(fenetre_ajout);
}


void
on_ok_clicked                          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fa;
GtkWidget *window;
GtkWidget *dial;
fa=lookup_widget(objet,"dashboard");

supprimer(selected_eq);
GtkWidget *tree;
dial=lookup_widget(objet,"dialog1");
gtk_widget_destroy(dial);
window= create_dashboard ();
  gtk_widget_show (window);

tree=lookup_widget(objet,"treeview1");
affiche(tree);

}


void
on_confirmer_Modif_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
 GtkWidget *tree ,*combobox1;
GtkWidget *dashboard;
dashboard=lookup_widget(objet,"dashboard");
tree=lookup_widget(objet,"treeview1");
combobox1=lookup_widget(dashboard,"combobox1");
	Equipement t;

        strcpy(t.Code,gtk_label_get_text(GTK_LABEL(lookup_widget(dashboard,"lab_Code"))));
        strcpy(t.Type,gtk_label_get_text(GTK_LABEL(lookup_widget(dashboard,"lab_Type"))));
        strcpy(t.Marque,gtk_label_get_text(GTK_LABEL(lookup_widget(dashboard,"lab_Marque"))));
        strcpy(t.Matricule,gtk_label_get_text(GTK_LABEL(lookup_widget(dashboard,"lab_Matricule"))));

      strcpy(t.annee_dachat,gtk_label_get_text(GTK_LABEL(lookup_widget(dashboard,"lab_Annee"))));

  supprimer(t);
	strcpy(t.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
       
	
	ajouter(t);
  gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(dashboard,"notebook1")));
 affiche(lookup_widget(dashboard,"treeview1"));
	
        GtkWidget *p=lookup_widget(dashboard,"treeview1");
        affiche(p);

}



void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
	 gchar* Code;
	gchar* Type;
	gchar* Marque;
	gchar* annee_dachat;
	gchar* Matricule;
	gchar* etat;
	Equipement p;
GtkWidget *dashboard;
dashboard=lookup_widget(objet,"dashboard");
  
       /* GtkTreeModel     *model;
        GtkTreeIter iter;
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

       
               gtk_tree_model_get (model, &iter,0, &Code,1,&Type,2,&Marque,3,&annee_dachat,4,&Matricule,5,&etat,-1);//recuperer les information de la ligne selectionneé
        // //remplir les champs de entry*/
                gtk_label_set_text(GTK_LABEL(lookup_widget(dashboard,"lab_Code")),selected_eq.Code);
                gtk_label_set_text(GTK_LABEL(lookup_widget(dashboard,"lab_Type")),selected_eq.Type);
                gtk_label_set_text(GTK_LABEL(lookup_widget(dashboard,"lab_Marque")),selected_eq.Marque);
                gtk_label_set_text(GTK_LABEL(lookup_widget(dashboard,"lab_Annee")),selected_eq.annee_dachat);
gtk_label_set_text(GTK_LABEL(lookup_widget(dashboard,"lab_Matricule")),selected_eq.Matricule);


           
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(dashboard,"notebook1")));//redirection vers la page precedente*/
}



void
on_betat_acct_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
	 gchar* Code;
	gchar* Type;
	
	Equipement p;
GtkWidget *change;
//change=lookup_widget(objet,"chang_etat");
change= create_chang_etat ();
GtkWidget *dashboard;
dashboard=lookup_widget(objet,"dashboard");
  
   gtk_widget_hide(dashboard);
gtk_widget_show(change);
                gtk_label_set_text(GTK_LABEL(lookup_widget(change,"labe_Code")),selected_eq.Code);
                gtk_label_set_text(GTK_LABEL(lookup_widget(change,"labe_Type")),selected_eq.Type);


}


void
on_conf_etat_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *change;
change=lookup_widget(objet_graphique,"chang_etat");
GtkWidget *input1,*input2,*input6;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
char etat_util[10];
char Code[10];
char Type[15];
date dt_uti;
input1=lookup_widget(objet_graphique,"labe_Code");
input2=lookup_widget(objet_graphique,"labe_Type");
input6=lookup_widget(objet_graphique,"combobox2");
jour=lookup_widget(objet_graphique, "sjour");
mois=lookup_widget(objet_graphique, "smoin");
annee=lookup_widget(objet_graphique, "sannee");
dt_uti.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
dt_uti.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
dt_uti.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(etat_util,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
 strcpy(Code,gtk_label_get_text(GTK_LABEL(input1)));
        strcpy(Type,gtk_label_get_text(GTK_LABEL(input2)));
ajout_util(dt_uti,etat_util,Code,Type);

//change=lookup_widget(objet,"chang_etat");
GtkWidget *dashboard;
dashboard= create_dashboard ();

change=lookup_widget(objet_graphique,"chang_etat");
  
   gtk_widget_hide(change);
gtk_widget_show(dashboard);
}


void
on_back_clicked                        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
GtkWidget *treeview1;
fenetre_afficher=lookup_widget(objet,"chang_etat");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=create_dashboard ();
gtk_widget_show(fenetre_ajout);
}


void
on_eq_uti_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
int res;
//GtkWidget *fenetre_ajout;
GtkWidget *dial;
GtkWidget *treeview2;


//dial=lookup_widget(objet,"eq_plus_util");
//treeview2=lookup_widget(objet,"treeview2");
//dial=lookup_widget(objet,"eq_plus_util");
//gtk_widget_destroy(fenetre_ajout);
dial=create_eq_plus_util ();
gtk_widget_show(dial);
equip();
treeview2=lookup_widget(dial,"treeview2");
//affiche_u(treeview2);
// gtk_label_set_text(GTK_LABEL(lookup_widget(objet,"type")),res);

/*char rct;
char ch[50];
rct=equi();
GtkWidget *dash=lookup_widget(objet,"dashboard");
GtkWidget *msg=lookup_widget(objet,"labres");
sprintf(ch,"l'équipement le plu utilisé : %s",rct);
gtk_label_set_text(GTK_LABEL(msg),ch);*/

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
	gchar* Code;
	gchar* Type;
	gint* nb;
	verif p;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &Code,1,&Type,2,&nb,-1);
	strcpy(p.id,Code);
	strcpy(p.type,Type);
	strcpy(p.nb,nb);
	
	
	}

GtkWidget *dashboard;
dashboard=create_eq_plus_util ();
 GtkWidget *E=lookup_widget(dashboard,"treeview2");

}


