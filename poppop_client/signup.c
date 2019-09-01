#include <gtk/gtk.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

GtkWidget *signup_name_entry;
GtkWidget *signup_password_entry;
GtkWidget *signup_password_confirm_entry;
GtkWidget *signup_password_question_entry;
GtkWidget *signup_password_answer_entry;

void submit_clicked(GtkWidget *button, GtkWidget *win)
{
  if(strlen((char *)gtk_entry_get_text(GTK_ENTRY(signup_password_entry))) < 6)
  {
    password_short_error(win);
  }
  else if(strcmp((char *)gtk_entry_get_text(GTK_ENTRY(signup_password_entry)), (char *)gtk_entry_get_text(GTK_ENTRY(signup_password_confirm_entry))) != 0)
  {
    password_wrong_error(win);
  }
  else
  {

    submit_success(win);
  }
}

void signup_run()
{
   GtkBuilder *builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "./UI/signup.glade", NULL);
   GtkWidget *signup_window = GTK_WIDGET(gtk_builder_get_object (builder, "signup_window"));
   GtkWidget *submit_button = GTK_WIDGET(gtk_builder_get_object (builder, "submit_button"));

   signup_name_entry = GTK_WIDGET(gtk_builder_get_object (builder, "sign_name_entry"));
   signup_password_entry = GTK_WIDGET(gtk_builder_get_object (builder, "sign_password_entry"));
   signup_password_confirm_entry = GTK_WIDGET(gtk_builder_get_object (builder, "sign_password_confirm_entry"));
   signup_password_question_entry = GTK_WIDGET(gtk_builder_get_object (builder, "sign_password_question_entry"));
   signup_password_answer_entry = GTK_WIDGET(gtk_builder_get_object (builder, "sign_password_answer_entry"));

   g_signal_connect(G_OBJECT(signup_window), "destroy", G_CALLBACK(gtk_widget_destroy), NULL);
   g_signal_connect(G_OBJECT(submit_button), "clicked", G_CALLBACK(submit_clicked), signup_window);

   g_object_unref(G_OBJECT (builder));
   gtk_widget_show(signup_window);
}

void password_short_error(GtkWidget* win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "密码长度不正确");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

void password_wrong_error(GtkWidget* win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "两次输入的密码不正确");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

void submit_success(GtkWidget* win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "注册成功");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

void create_user_info()
{
  ;
}
