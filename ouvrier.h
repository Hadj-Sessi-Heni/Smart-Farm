#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Datee;
typedef struct
{
char cin[20];
int present;
Datee date;
}pointage;

typedef struct
{
char sexe[30];
char cin[30];
char nom[30];
char prenom[30];
Datee date;
}ouvrier;
void presence (pointage p);
void DBajout(ouvrier o);
void DBrecherche(GtkWidget* DBtreeview);
void DBsuppression(char id[30], ouvrier o);
void DBaffichage(GtkWidget* DBtreeview);
void DBmodification(char id[30], ouvrier o);


