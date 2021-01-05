#include <gtk/gtk.h>
typedef struct
{
int j;
int m;
int a;
}date_capt;


typedef struct
{
	char captID[20];
	char captMarque[20];
	char captType[20];
	int captValMin;
	int captValMax;
}capteur;




typedef struct
{
int etatDefece;
int captValEnr;
date_capt date_capteur;
char captIDhist[20];
char captMarquehist[20];
}capterHist;

typedef struct
{
int nbr;

char captMarquedefec[20];
}capteurDefec;


void afficher_capt(GtkWidget *liste);

void ajouter_capt(capteur C);
void supprimer_capt(capteur C);

void rechercher_capt(char IDa[20],char Marque[20],GtkWidget *liste);
void modifier_capt(capteur C);
void ajouter_capt_hist(capterHist h);
void afficher_capt_hist(GtkWidget *liste);
void supprimer_capt_hist(capterHist h);
void rechercher_capt_hist(char IDe[20],char Marque[20],GtkWidget *liste);

void affiche_captTemp(GtkWidget *liste);
void affiche_captHum(GtkWidget *liste);
void afficher_captAlarm(int Jour,int Mois, int Annee,GtkWidget *liste);
void afficher_captdefec(GtkWidget *liste);
void marque_defec(capteurDefec d);
