#include <gtk/gtk.h>
typedef struct
{ 
int jour;
int mois;
int annee;
}date;
typedef struct
{
char nom[20];
char prenom[20];
int age;
char cin[8];
char sexe[8];//1:homme 2:femme
date date_amb;
char adress[20];
char password[20];
char mail[30];
char tel[8];
}employe;
typedef struct
{
char cin[8];
date date;
int val;//1:p 0:a
}absent;
void ajouter_employe(employe e);
void afficher_employe(GtkWidget *liste);
void supprimer_employe(employe e);
void chercher_employe(char c[8],GtkWidget *liste);
void modifier_employe(employe e);
void chercher_type_employe(int s,int n,int p,int z,char k[20], char l[20],GtkWidget *liste);
void afficher_employe_ab(GtkWidget *liste);
//float calcul_absenteisme_emp(act_emp);
int exist_employe(char cin[8]);
