#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}date;
typedef struct{
char Code[30];
char Type[30];
char Marque[30];
char annee_dachat[30];
char Matricule[30];
char etat[30]
}Equipement;
typedef struct
{
char id[30];
char type[30];
int nb;
}verif;
typedef struct
{
char Code[30];
char type[30];
int nb;
char e[30];
}eq_ut;
void affiche(GtkWidget *liste);
void ajouter(Equipement E);
void supprimer(Equipement E);
void modifier(char id[],Equipement E);
void rechercher(char ref[],GtkWidget *liste);
void ajout_util(date D,char e[],char Code[] ,char Type[]);
void equip();
//void affiche_u(GtkWidget *liste);
