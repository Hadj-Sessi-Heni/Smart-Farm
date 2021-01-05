
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


void
on_return_A_G_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
  GtkWidget *gestion;
GtkWidget *window;
window= create_gestion ();
  gtk_widget_show (window);
}












//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void
on_button_ajoua_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*Ajouter;
Ajouter=lookup_widget(objet,"Ajouter");
troupeau A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "1a2z3e4r5t6y7u8i9opqsdfghjklmwxcvbn";

se = lookup_widget (objet,"entry6a");
da = lookup_widget (objet,"entry4_datea");
po = lookup_widget (objet,"entry7_etatea");


strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.vaccin,gtk_entry_get_text(GTK_ENTRY(da)));
strcpy(A.infosupp,gtk_entry_get_text(GTK_ENTRY(po)));


GtkWidget  *input3;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;


input3=lookup_widget(objet,"combobox1");
jour=lookup_widget(objet,"spinbutton1");
mois=lookup_widget(objet,"spinbutton2");
annee=lookup_widget(objet,"spinbutton3");

strcpy(A.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));

A.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
A.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));



 //
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);


ajouter(A);

}





//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{




}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *Ajouter_ ;
  Ajouter_ = create_Ajouter_ ();
  gtk_widget_show (Ajouter_);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button3_suppAjou_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
   GtkWidget *modif_supp;
  modif_supp = create_modif_supp ();
  gtk_widget_show (modif_supp);

}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button2_moda_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{

GtkWidget *dd,*ty,*se,*da,*po,*windowmod,*jour,*mois,*annee;
char id[20];
troupeau U ;

dd = lookup_widget (button,"entry87a");
ty = lookup_widget (button,"entry8a");
se = lookup_widget (button,"entry9a");
da = lookup_widget (button,"combobox2");
po = lookup_widget (button,"entry11a");
jour = lookup_widget (button,"spinbutton4");
mois= lookup_widget (button,"spinbutton5");
annee = lookup_widget (button,"spinbutton6");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.vaccin,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.infosupp,gtk_entry_get_text(GTK_ENTRY(po)));
U.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
U.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
U.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

modi(id,U);

}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button1_affia_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{

GtkWidget *dd,*type,*vaccin,*sexe,*infosupp,*ty,*se,*da,*po,*windowmod,*l;

char id[30];


dd = lookup_widget (button,"entry87a");
type = lookup_widget(button, "label14a");
vaccin = lookup_widget(button, "label15a");
sexe= lookup_widget(button, "label16a");
infosupp = lookup_widget(button, "label17a");

ty = lookup_widget (button,"entry8a");
se = lookup_widget (button,"entry9a");
da = lookup_widget (button,"entry10a");
po = lookup_widget (button,"entry11a");
l = lookup_widget (button,"label34");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
troupeau A= rech(id);

gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(vaccin),A.vaccin);
gtk_label_set_text(GTK_LABEL(sexe),A.sexe);
gtk_label_set_text(GTK_LABEL(infosupp),A.infosupp);
gtk_label_set_text(GTK_LABEL(l),A.sexe);

gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.vaccin);
gtk_entry_set_text(GTK_LABEL(da),A.sexe);
gtk_entry_set_text(GTK_LABEL(po),A.infosupp);

}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button3_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
/*
//GtkWidget *gestion;
GtkWidget *modif_supp;
//  gestion = create_gestion ();
//gtk_widget_show (gestion);
  modif_supp= lookup_widget(objet,"modif_supp");
  gtk_widget_hide(modif_supp);
  */
}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button1_suppa_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *dd;
char id[30];
dd = lookup_widget (button,"entry87a");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
supp(id);
}








//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

/////////////////////////////////////////////////
void
on_button4Actualiser_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

        GtkWidget *gestion,*treeview1;
	gestion=lookup_widget(objet,"gestion");
	treeview1=lookup_widget(objet,"treeview1");
	afficher(treeview1);


}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *ty,*nb;


char type[20];

ty = lookup_widget (objet_graphique,"entry1");
nb = lookup_widget(objet_graphique, "spinbutton7");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(ty)));
 FILE* F;

troupeau n;
int nb1=0;


F=fopen("troupeau.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F, "%s %s %s %s %d %d %d %s\n",n.id,n.type,n.vaccin,n.sexe,&n.d.jour,&n.d.mois,&n.d.annee,n.infosupp)==8)
    {
      if(strcmp(n.type,type)==0)
      nb1++;
    }
fclose(F); 
}

gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),nb1);





}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_supprimerH_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{




GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");
        
        gchar *id;//gchar type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supp (id);// supprimer la ligne du fichier


}
}
int x;
int t[2]={0,0};
void
on_validationH_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label35");

gtk_label_set_text(GTK_LABEL(output),ch3);
}



//////////////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_radiobutton1H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_radiobutton2HJ_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


void
on_checkbutton2gb_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;} 
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_checkbutton1ga_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

void
on_button9H_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_;
GtkWidget *window;
window= create_Ajouter_ ();
  gtk_widget_show (window);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button14CrH_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gest_aut;
GtkWidget *window;
window= create_gest_aut ();
  gtk_widget_show (window);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_button13log_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window;
window= create_window1 ();
  gtk_widget_show (window);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_Ajout_aut_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

aut y;


GtkWidget *input1,*input2;



input1=lookup_widget(objet_graphique,"log2");
input2=lookup_widget(objet_graphique,"mdp2");

strcpy(y.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(y.mdp,gtk_entry_get_text(GTK_ENTRY(input2)));


ajouter_aut(y);




}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_afficher_tree_aut_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *gest_aut;
GtkWidget *treeview4_auth;

gest_aut=lookup_widget(objet,"gest_aut");
treeview4_auth=lookup_widget(gest_aut,"treeview4_auth");
afficher_aut(treeview4_auth);

}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void
on_treeview4_auth_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
aut y;

gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);

}
//strcpy(selected_auth.login,str_data);

FILE *f;

f=fopen("aut.txt","r");
while(!feof(f))
	{
	fscanf(f,"%s %s",y.login,y.mdp);
	
	}
fclose(f);


}

/*
void
on_retH_activate                       (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *auth;
GtkWidget *window;
window= create_auth ();
  gtk_widget_show (window);


}
*/

void
on_retH_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *gest_aut;
gest_aut=lookup_widget(objet,"gest_aut");
gtk_widget_destroy(gest_aut);

}

