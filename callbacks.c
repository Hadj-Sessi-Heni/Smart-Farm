#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction_emp.h"
int x_ch,y_ch,z_ch,a_ch;
int choix_ch[3]={0,0,0};
employe active_emp;
employe act_emp;
absent ab;
date d_ch;

///////

void
on_radiobutton2_femme_ch_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{z_ch=2;}
}


void
on_radiobutton1_homme_ch_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{z_ch=1;}
}


void
on_radiobutton1_H_ch_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x_ch=1;}
}


void
on_radiobutton2_F_ch_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{x_ch=2;}
}

void
on_radiobutton3_H_ch_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{y_ch=1;}
}


void
on_radiobutton4_F_ch_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{y_ch=2;}
}


void
on_checkbutton1_sexe_ch_clicked        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_ch[0]=1;
GtkWidget *input1,*input2;
input1=lookup_widget(togglebutton,"radiobutton1_homme_ch");
input2=lookup_widget(togglebutton,"radiobutton2_femme_ch");
gtk_widget_show(input1);
gtk_widget_show(input2);
}
}


void
on_checkbutton2_nom_ch_clicked         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_ch[1]=1;
GtkWidget *input1;
input1=lookup_widget(togglebutton,"entry1_name");
gtk_widget_show(input1);}
}


void
on_checkbutton3_prenom_ch_clicked      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix_ch[2]=1;
GtkWidget *input1;
input1=lookup_widget(togglebutton,"entry2_prename");
gtk_widget_show(input1);}
}




void
on_treeview2_ab_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar *str_data;
	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
	{
	gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);
	}
	strcpy(active_emp.cin,str_data);
	
	FILE *f;
	employe e;
	f=fopen("employe.bin","rb");
	while(!feof(f))
	{
	fread(&e,sizeof(employe),1,f);
	if(strcmp(act_emp.cin,e.cin)==0)
	{act_emp=e;}
	}
	fclose(f);

}




void
on_button1_afficher_ch_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_employe;
GtkWidget *treeview1;
gestion_employe=lookup_widget(objet,"gestion_employe");
treeview1=lookup_widget(gestion_employe,"treeview1_ch");
afficher_employe(treeview1);
}


void
on_button_supprimer_ch_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_employe;
	GtkWidget *treeview;
	gestion_employe=lookup_widget(objet,"gestion_employe");
	supprimer_employe(active_emp);
	treeview=lookup_widget(gestion_employe,"treeview1_ch");
	afficher_employe(treeview);
}




void
on_button_modifier_ch_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_employe;

gestion_employe=lookup_widget(objet,"gestion_employe");
GtkWidget *input1,*input2,*input3,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
input1=lookup_widget(gestion_employe,"entry7_nom");
input2=lookup_widget(gestion_employe,"entry8_prenom");
input3=lookup_widget(gestion_employe,"spinbutton5_age");
input5=lookup_widget(gestion_employe,"spinbutton6_jour");
input6=lookup_widget(gestion_employe,"spinbutton7_mois");
input7=lookup_widget(gestion_employe,"spinbutton8_an");
input8=lookup_widget(gestion_employe,"entry9_adress");
input9=lookup_widget(gestion_employe,"entry10_password");
input10=lookup_widget(gestion_employe,"entry2_mail");
input11=lookup_widget(gestion_employe,"entry2_tel");
gtk_entry_set_text(input1,active_emp.nom);
gtk_entry_set_text(input2,active_emp.prenom);
gtk_entry_set_text(input8,active_emp.adress);
gtk_entry_set_text(input9,active_emp.password);
gtk_entry_set_text(input10,active_emp.mail);
gtk_entry_set_text(input11,active_emp.tel);
gtk_spin_button_set_value(input3,active_emp.age);
gtk_spin_button_set_value(input5,active_emp.date_amb.jour);
gtk_spin_button_set_value(input6,active_emp.date_amb.mois);
gtk_spin_button_set_value(input7,active_emp.date_amb.annee);
gtk_notebook_set_current_page(GTK_NOTEBOOK(lookup_widget(gestion_employe,"notebook2_ch")),3);

}


void
on_button1_checher1_ch_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
char type[30];
char cin[8];
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
GtkWidget *input1,*input2,*input4,*input3,*input5,*input6,*input7,*input8,*input10,*input11;
input1=lookup_widget(gestion_employe,"label45");
input2=lookup_widget(gestion_employe,"entry1_cin");
input3=lookup_widget(gestion_employe,"checkbutton1_sexe_ch");
input4=lookup_widget(gestion_employe,"checkbutton2_nom_ch");
input5=lookup_widget(gestion_employe,"checkbutton3_prenom_ch");
input6=lookup_widget(gestion_employe,"radiobutton1_homme_ch");
input7=lookup_widget(gestion_employe,"radiobutton2_femme_ch");
input8=lookup_widget(gestion_employe,"comboboxentry1");
input10=lookup_widget(gestion_employe,"entry1_name");
input11=lookup_widget(gestion_employe,"entry2_prename");
gtk_widget_hide(input1);
gtk_widget_hide(input2);
gtk_widget_hide(input3);
gtk_widget_hide(input4);
gtk_widget_hide(input5);
gtk_widget_hide(input6);
gtk_widget_hide(input7);
gtk_widget_hide(input10);
gtk_widget_hide(input11);
gtk_notebook_set_current_page(GTK_NOTEBOOK(lookup_widget(gestion_employe,"notebook2_ch")),2);
}






void
on_button4_chercher_ch_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
char cin[8];
char nom[20], prenom[20];
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
GtkWidget *treeview1;
treeview1=lookup_widget(gestion_employe,"treeview1_ch");
GtkWidget *input1,*input2,*input4,*input3,*input5,*input6,*input7,*input8,*input10,*input11;
input1=lookup_widget(gestion_employe,"label45");
input2=lookup_widget(gestion_employe,"entry1_cin");
input3=lookup_widget(gestion_employe,"checkbutton1_sexe_ch");
input4=lookup_widget(gestion_employe,"checkbutton2_nom_ch");
input5=lookup_widget(gestion_employe,"checkbutton3_prenom_ch");
input6=lookup_widget(gestion_employe,"radiobutton1_homme_ch");
input7=lookup_widget(gestion_employe,"radiobutton2_femme_ch");
input8=lookup_widget(gestion_employe,"comboboxentry1");
input10=lookup_widget(gestion_employe,"entry1_name");
input11=lookup_widget(gestion_employe,"entry2_prename");
if (strcmp("recherche_simple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)))==0){
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input2)));
chercher_employe(cin,treeview1);}
else if(strcmp("recherche_multi-critère",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)))==0){
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input11)));
chercher_type_employe(choix_ch[0],choix_ch[1],choix_ch[2],z_ch,nom,prenom,treeview1);
}



gtk_notebook_set_current_page(GTK_NOTEBOOK(lookup_widget(gestion_employe,"notebook2_ch")),0);
}




void
on_button5_modifier_ch_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
employe e;
GtkWidget *input1,*input2,*input3,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
input1=lookup_widget(gestion_employe,"entry7_nom");
input2=lookup_widget(gestion_employe,"entry8_prenom");
input3=lookup_widget(gestion_employe,"spinbutton5_age");
input5=lookup_widget(gestion_employe,"spinbutton6_jour");
input6=lookup_widget(gestion_employe,"spinbutton7_mois");
input7=lookup_widget(gestion_employe,"spinbutton8_an");
input8=lookup_widget(gestion_employe,"entry9_adress");
input9=lookup_widget(gestion_employe,"entry10_password");
input10=lookup_widget(gestion_employe,"entry2_mail");
input11=lookup_widget(gestion_employe,"entry2_tel");
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
e.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
//strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
if(y_ch==1)
strcpy(e.sexe,"Homme");
else if(y_ch==2)
strcpy(e.sexe,"Femme");
e.date_amb.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
e.date_amb.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
e.date_amb.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
strcpy(e.adress,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(input11)));
strcpy(e.cin,active_emp.cin);
/*supprimer_employe(active_emp);
ajouter_employe(e);*/
modifier_employe(e);
}


void
on_treeview1_ch_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *str_data;
	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
	{
	gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);
	}
	strcpy(active_emp.cin,str_data);
	
	FILE *f;
	employe e;
	f=fopen("employe.bin","rb");
	while(!feof(f))
	{
	fread(&e,sizeof(employe),1,f);
	if(strcmp(active_emp.cin,e.cin)==0)
	{active_emp=e;}
	}
	fclose(f);
}



void
on_button1_ch_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
char type[30];
char cin[8];
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
GtkWidget *input1,*input2,*input4,*input3,*input5,*input6,*input7,*input8,*input10,*input11;
input1=lookup_widget(gestion_employe,"label45");
input2=lookup_widget(gestion_employe,"entry1_cin");
input3=lookup_widget(gestion_employe,"checkbutton1_sexe_ch");
input4=lookup_widget(gestion_employe,"checkbutton2_nom_ch");
input5=lookup_widget(gestion_employe,"checkbutton3_prenom_ch");
input6=lookup_widget(gestion_employe,"radiobutton1_homme_ch");
input7=lookup_widget(gestion_employe,"radiobutton2_femme_ch");
input8=lookup_widget(gestion_employe,"comboboxentry1");
input10=lookup_widget(gestion_employe,"entry1_name");
input11=lookup_widget(gestion_employe,"entry2_prename");
if (strcmp("recherche_simple",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)))==0){
gtk_widget_show(input1);
gtk_widget_show(input2);

strcpy(type,"recherche_simple");

}
else if(strcmp("recherche_multi-critère",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)))==0){
gtk_widget_show(input3);
gtk_widget_show(input4);
gtk_widget_show(input5);
strcpy(type,"recherche_multi-critère");

}
}


void
on_button1_ajouter_ch_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
employe e;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget *gestion_employe;
GtkWidget *exist,*success;
int b=1;
GtkWidget *lab_nom,*lab_pre,*lab_cin,*lab_tel,*lab_mail,*lab_ad,*lab_pass;
gestion_employe=lookup_widget(objet,"gestion_employe");
input1=lookup_widget(gestion_employe,"entry1_nom");
input2=lookup_widget(gestion_employe,"entry2_prenom");
input3=lookup_widget(gestion_employe,"spinbutton1_age");
input4=lookup_widget(gestion_employe,"entry5_cin");
input5=lookup_widget(gestion_employe,"spinbutton2_jour");
input6=lookup_widget(gestion_employe,"spinbutton3_mois");
input7=lookup_widget(gestion_employe,"spinbutton4_an");
input8=lookup_widget(gestion_employe,"entry3_adress");
input9=lookup_widget(gestion_employe,"entry4_password");
input10=lookup_widget(gestion_employe,"entry1_mail");
input11=lookup_widget(gestion_employe,"entry1_tel");
exist=lookup_widget(gestion_employe,"label52");
success=lookup_widget(gestion_employe,"label53");

lab_nom=lookup_widget(gestion_employe,"label54");
lab_pre=lookup_widget(gestion_employe,"label58");
lab_cin=lookup_widget(gestion_employe,"label59");
lab_tel=lookup_widget(gestion_employe,"label55");
lab_mail=lookup_widget(gestion_employe,"label60");
lab_pass=lookup_widget(gestion_employe,"label56");
lab_ad=lookup_widget(gestion_employe,"label57");


gtk_widget_hide(exist);
gtk_widget_hide(success);

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
e.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
if(x_ch==1)
strcpy(e.sexe,"homme");
else if(x_ch==2)
strcpy(e.sexe,"femme");
e.date_amb.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
e.date_amb.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
e.date_amb.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
strcpy(e.adress,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(e.mail,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(e.tel,gtk_entry_get_text(GTK_ENTRY(input11)));


if(strcmp(e.nom,"")==0){
		  gtk_widget_show (lab_nom);
b=0;
}
else {
		  gtk_widget_hide(lab_nom);
}
if(strcmp(e.prenom,"")==0){
		  gtk_widget_show (lab_pre);
b=0;
}
else {
		  gtk_widget_hide(lab_pre);
}
if(strcmp(e.cin,"")==0){
		  gtk_widget_show (lab_cin);
b=0;
}
else {
		  gtk_widget_hide(lab_cin);
}
if(strcmp(e.tel,"")==0){
		  gtk_widget_show (lab_tel);
b=0;
}
else {
		  gtk_widget_hide(lab_tel);
}
if(strcmp(e.mail,"")==0){
		  gtk_widget_show (lab_mail);
b=0;
}
else {
		  gtk_widget_hide(lab_mail);
}
if(strcmp(e.password,"")==0){
		  gtk_widget_show (lab_pass);
b=0;
}
else {
		  gtk_widget_hide(lab_pass);
}
if(strcmp(e.adress,"")==0){
		  gtk_widget_show (lab_ad);
b=0;
}
else {
		  gtk_widget_hide(lab_ad);
}
if(b==1){

        if(exist_employe(e.cin)==1)
        {

				  gtk_widget_show(exist);
        }
        else {
						  gtk_widget_hide(exist);
                ajouter_employe(e);

						  gtk_widget_show(success);
        
}
}
}


void
on_radiobutton1_ch_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{a_ch=1;}
}


void
on_button3_apply_ch_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3;
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
input1=lookup_widget(gestion_employe,"spinbutton1_j");
input2=lookup_widget(gestion_employe,"spinbutton2_m");
input2=lookup_widget(gestion_employe,"spinbutton3_a");
d_ch.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
d_ch.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
d_ch.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
GtkWidget *treeview1;
treeview1=lookup_widget(gestion_employe,"treeview2_ab");
afficher_employe_ab(treeview1);

}


void
on_radiobutton2_ch_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{a_ch=0;}
}


void
on_button2_valider_ch_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_employe,*test;
gestion_employe=lookup_widget(objet,"gestion_employe");
test=lookup_widget(gestion_employe,"label61");

absent em_ab,a;
int x=0;
strcpy(em_ab.cin,act_emp.cin);
em_ab.date=d_ch;
em_ab.val=a_ch;
FILE *g=NULL;
g=fopen("absenteisme.bin","rb"); 
if(g!=NULL){
	while(fread(&a,sizeof(absent),1,g)!=0){
if((strcmp(em_ab.cin,a.cin)==0)&&(a.date.jour==em_ab.date.jour)&&(a.date.mois==em_ab.date.mois)&&(a.date.annee==em_ab.date.annee))
x=1;   
}
}
fclose(g);
if (x==1){ gtk_widget_show(test);}
else {
gtk_widget_hide(test);
FILE *f=NULL;
f=fopen("absenteisme.bin","a+b");
if(f!=NULL)
fwrite(&em_ab,sizeof(absent),1,f);
fclose(f);}
}


void
on_button4_ch_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
float i=0;
char c[20]="";
GtkWidget *gestion_employe;
gestion_employe=lookup_widget(objet,"gestion_employe");
//i=calcul_absenteisme_emp(act_emp);

absent abs;
int ab=0,pr=0;
FILE *f=NULL;
f=fopen("absenteisme.bin","rb");
if(f!=NULL){
f=fopen("absenteisme.bin","rb");
while(fread(&abs,sizeof(absent),1,f)!=0){
if (strcmp(act_emp.cin,abs.cin)==0){
if (abs.val==0){ab++;}
else{pr++;}

}
}
}
fclose(f);
i=(float)ab/(float)(pr+ab);
i=i*100;


GtkWidget *input1;
input1=lookup_widget(gestion_employe,"label51_ab");
sprintf(c,"%f %%",i);
gtk_label_set_text(GTK_LABEL(input1),c);
gtk_widget_show(input1);
}


