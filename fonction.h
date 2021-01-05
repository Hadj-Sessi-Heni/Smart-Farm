#include<gtk/gtk.h>

typedef struct {
int jour;
int mois;
int annee;
}date;

typedef struct {
char id[20];
char type[20];
char vaccin[20];
char sexe[20];
date d;
char  infosupp[20];
}troupeau;


typedef struct {
char login[20];
char mdp[20];

}aut;


void ajouter(troupeau A);
void supp(char id[]);
troupeau rech(char id[]);
void modi(char id[], troupeau U);
void afficher (GtkWidget *liste );
int nb_troupeaux(char type[]);

void ajouter_aut(aut y);
void afficher_aut (GtkWidget *liste );
