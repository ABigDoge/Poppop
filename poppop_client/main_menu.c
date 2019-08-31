#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gdk/gdk.h>
#include "user_image_change.c"
#include "file_updata.c"
#include "dialog.c"

GtkWidget* window_info;//好友信息
gchar* ID;
GtkWidget *fix;
GtkWidget *main_window;

void friend_add_button_clicked(GtkWidget *button, gpointer data)
{

}

void friend_button_clicked(GtkWidget *button, gpointer data)
{
  gchar* info = gtk_widget_get_name(button);
  g_print("start chat with %s\n", (char*)info);
  on_frinedbutton_clicked(button);
}

GtkWidget *xpm_label_box( gchar *xpm_filename, gchar *label_text )
{
  GtkWidget *box;
  GtkWidget *label;
  GtkWidget *image;
  /* 为图像和标签创建盒 */
  box = gtk_hbox_new (FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (box), 2);
  /* 创建一个图像 */
  GdkPixbuf *src=gdk_pixbuf_new_from_file(xpm_filename,NULL);
  GdkPixbuf *dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
  image = gtk_image_new_from_pixbuf(dst);
  g_object_unref(src);
  g_object_unref(dst);

  /* 为按钮创建一个标签 */
  label = gtk_label_new (label_text);
  GdkColor color1;
  gdk_color_parse ("white", &color1);
  gtk_widget_modify_fg(label, GTK_STATE_NORMAL, &color1);
  /* 把图像和标签组装到盒子里 */
  gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);
  gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 3);

  gtk_widget_set_visible(box, TRUE);
  gtk_widget_set_visible(label, TRUE);
  gtk_widget_set_visible(image, TRUE);
  return box;
}

void init_user(GtkBuilder *builder)
{
  GFile* init_file = NULL;
  char buffer[1024];

  GtkWidget *user_image = GTK_WIDGET(gtk_builder_get_object(builder, "user_image"));
  GtkWidget *main_back = GTK_WIDGET(gtk_builder_get_object(builder, "main_back"));
  GtkWidget *user_id = GTK_WIDGET(gtk_builder_get_object(builder, "user_id"));
  GtkWidget *user_sign = GTK_WIDGET(gtk_builder_get_object(builder, "user_sign"));
  GdkPixbuf *src;
  GdkPixbuf *dst;
  char *str;

  init_file = fopen("./user/user_info.txt", "r");

  for(int i=0; i<4; i++)
  {
    fscanf(init_file, "%s", buffer);
    switch(i)
    {
      case 0:
             str = strchr(buffer, ':')+1;
             src=gdk_pixbuf_new_from_file(str,NULL);
             dst=gdk_pixbuf_scale_simple(src,300,800,GDK_INTERP_BILINEAR);
             gtk_image_set_from_pixbuf(main_back, dst);
             break;
      case 1:
             str = strchr(buffer, ':')+1;
             src=gdk_pixbuf_new_from_file(str,NULL);
             dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
             gtk_image_set_from_pixbuf(user_image, dst);
             break;
      case 2:
             gtk_label_set_text(user_id, strchr(buffer, ':') + 1);
             break;
      case 3:
             gtk_entry_set_text(user_sign, strchr(buffer, ':') + 1);
             break;
    }
  }

  fclose(init_file);

}



void init_friend()
{

  char info[1024];
  GFile *file = fopen("./user/friend_info.txt", "r");

  gint start = 0;
  while(fscanf(file, "%s", info) != EOF)
  {
    char image_path[1024];
    memset(image_path, '\0', sizeof(image_path));
    char *signal = strchr(info, ':');
    strncpy(image_path, info, signal - info);

    GtkWidget *button = gtk_button_new();
    gtk_widget_set_visible(button, TRUE);
    gtk_button_set_relief(button, GTK_RELIEF_NONE);
    gtk_widget_set_name(button, signal + 1);
    gtk_widget_set_size_request(button, (gint)300, (gint)100);
    GtkWidget *box = xpm_label_box (image_path, signal + 1);
    gtk_container_add (GTK_CONTAINER (button), box);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(friend_button_clicked), NULL);
    gtk_fixed_put(fix, button, (gint)0, start);
    start += 105;
  }
}

void user_sign_changed(GtkWidget object, GtkWidget *entry)
{
   char str[1024];
   strcpy(str, "user_sign:");
   strcat(str, (char*)gtk_entry_get_text(entry));
   change(4, str, "./user/user_info.txt");
}

void main_menu_run()
{
   GtkBuilder *builder = gtk_builder_new();
   gtk_builder_add_from_file(builder, "./UI/main.glade", NULL);

   init_user(builder);

   fix = GTK_WIDGET(gtk_builder_get_object(builder, "friend_fix"));
   init_friend(fix);
   g_print("success\n");

   main_window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
   g_signal_connect(G_OBJECT(main_window), "destroy", gtk_main_quit, NULL);

   GtkWidget *user_image_button = GTK_WIDGET(gtk_builder_get_object(builder, "user_image_button"));
   g_signal_connect(G_OBJECT(user_image_button), "clicked", G_CALLBACK(show_window_set), NULL);

   touxiang_image =  GTK_WIDGET(gtk_builder_get_object(builder, "user_image"));

   GtkWidget *user_sign = GTK_WIDGET(gtk_builder_get_object(builder, "user_sign"));
   g_signal_connect(G_OBJECT(user_sign), "activate", G_CALLBACK(user_sign_changed), user_sign);

   GtkWidget *friend_add_button = GTK_WIDGET(gtk_builder_get_object(builder, "friend_add"));
   gtk_button_set_relief(friend_add_button, GTK_RELIEF_NONE);
   g_signal_connect(G_OBJECT(friend_add_button), "clicked", G_CALLBACK(friend_add_button_clicked), friend_add_button);

   g_object_unref(G_OBJECT (builder));
   gtk_widget_show(main_window);
}



/*点击chat后的回调函数*/
void show_friend_window(GtkWidget* widget, gpointer friend_id)
{
    /*测试用户Id是否传过来*/
    gchar* test=(gchar*)friend_id;
    g_print(test);
    g_print("\n");
    /*此处添加跳转至对话框函数*/
    dialog_run();

    gtk_widget_destroy(window_info);

}

/*点击remove后的回调函数*/
void remove_friend(GtkWidget* widget,GtkWidget *button)
{
    /*此处添加删除好友的函数，好友id为friend_id*/
    gchar* friend_id=gtk_widget_get_name(button);
    delete_line(friend_id, "./user/friend_info.txt");
    gtk_widget_destroy(button);
    gtk_widget_destroy(window_info);
}


/*点击好友按钮的回调函数，传入一个描述好友id的gpointer类型的指针*/
void on_frinedbutton_clicked(GtkWidget *button)
{

    GtkWidget* vbox;
    GtkWidget* button_chat;
    GtkWidget* button_remove;
    window_info=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    vbox=gtk_vbox_new(TRUE,8);
    gtk_container_add(GTK_CONTAINER(window_info),vbox);

    gchar* friend_id=gtk_widget_get_name(button);
    //g_print(friend_id);
    button_chat=gtk_button_new_with_label("chat_with_friend");
    g_signal_connect(G_OBJECT(button_chat),"clicked",G_CALLBACK(show_friend_window),(gpointer)friend_id);
    gtk_container_add(GTK_CONTAINER(vbox),button_chat);

    button_remove=gtk_button_new_with_label("remove_friend");
    gtk_container_add(GTK_CONTAINER(vbox),button_remove);
    g_signal_connect(G_OBJECT(button_remove),"clicked",G_CALLBACK(remove_friend),button);

    gtk_widget_show_all(window_info);

}
