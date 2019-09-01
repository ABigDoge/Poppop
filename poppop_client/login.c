#include <gtk/gtk.h>
#include "signup.c"
#include "main_menu.c"

void signup_clicked(GtkWidget *button, gpointer data)
{
  signup_run();
}

void login_clicked(GtkWidget *button, GtkWidget *window)
{
  main_menu_run();
  gtk_widget_destroy(window);
}

void login_run()
{
   GtkBuilder *builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "./UI/login.glade", NULL);
   GtkWidget *login_window = GTK_WIDGET(gtk_builder_get_object (builder, "login_window"));
   GtkWidget *signup_button = GTK_WIDGET(gtk_builder_get_object (builder, "signup_button"));
   GtkWidget *login_button = GTK_WIDGET(gtk_builder_get_object (builder, "login_button"));

   g_signal_connect(G_OBJECT(login_window), "destroy", G_CALLBACK(gtk_widget_destroy), NULL);
   g_signal_connect(G_OBJECT(signup_button), "clicked", G_CALLBACK(signup_clicked), NULL);
   g_signal_connect(G_OBJECT(login_button), "clicked", G_CALLBACK(login_clicked), login_window);

   g_object_unref(G_OBJECT (builder));
   gtk_widget_show(login_window);
}
