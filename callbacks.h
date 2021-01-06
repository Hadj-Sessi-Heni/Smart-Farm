#include <gtk/gtk.h>


void
on_Ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_valider_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_rechercher_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancel_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ok_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer_Modif_clicked             (GtkButton       *objet,
                                        gpointer         user_data);



void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_betat_acct_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_conf_etat_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_back_clicked                        (GtkButton       *objet,
                                        gpointer         user_data);

void
on_eq_uti_clicked                      (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
