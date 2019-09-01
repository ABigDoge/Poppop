#include <gtk/gtk.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

const char* image_defalut_path="./user/image/0.jpeg";
const char* image_1_path="./user/image/1.jpeg";
const char* image_2_path="./user/image/2.jpeg";
const char* image_3_path="./user/image/3.jpeg";
const char* image_4_path="./user/image/4.jpeg";
GtkWidget *button_touxiang;
GtkWidget *touxiang_image;
GtkWidget *window1;//头像set窗口
GtkWidget *window_sign;//签名设置窗口
GtkWidget *entry_sign;
GtkWidget *entry_ID;

GdkPixbuf* get_pix(int pic_num)
{
    GdkPixbuf *src,*dst;GtkWidget *entry_sign;
    if(pic_num==0)
    {
        src=gdk_pixbuf_new_from_file(image_defalut_path,NULL);
        dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
    }
    if(pic_num==1)
    {
        src=gdk_pixbuf_new_from_file(image_1_path,NULL);  GtkWidget *entry;
        dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
    }
    if(pic_num==2)
    {
        src=gdk_pixbuf_new_from_file(image_2_path,NULL);
        dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
    }
    if(pic_num==3)
    {
        src=gdk_pixbuf_new_from_file(image_3_path,NULL);
        dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
    }
    if(pic_num==4)
    {
        src=gdk_pixbuf_new_from_file(image_4_path,NULL);
        dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);
    }
    return dst;
}
/*修改图片大小函数*/
/*修改签名*/
void on_signset_activate(GtkWidget* widget,gpointer sign_set)
{
    gchar *text=gtk_entry_get_text(GTK_ENTRY(sign_set));
    gtk_entry_set_text(entry_sign,text);
}
void show_editor_set()
{
    GtkWidget *sign_set;
    window_sign=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    sign_set=gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(window_sign),sign_set);
    gtk_entry_set_max_length(sign_set,30);
    g_signal_connect(sign_set, "activate", G_CALLBACK(on_signset_activate), sign_set);
    gtk_widget_show_all(window_sign);

}

/*修改头像*/
void on_selsect_clicked(GtkWidget* button,gpointer data)
{
    if((gint)data==1)
    {
        gtk_image_set_from_pixbuf(touxiang_image,get_pix(1));
        change(2, "user_image:./user/image/1.jpeg", "./user/user_info.txt");
    }
    if((gint)data==2)
    {
        gtk_image_set_from_pixbuf(touxiang_image,get_pix(2));
        change(2, "user_image:./user/image/2.jpeg", "./user/user_info.txt");
    }
    if((gint)data==3)
    {
        gtk_image_set_from_pixbuf(touxiang_image,get_pix(3));
        change(2, "user_image:./user/image/3.jpeg", "./user/user_info.txt");
    }
    if((gint)data==4)
    {
        gtk_image_set_from_pixbuf(touxiang_image,get_pix(4));
        change(2, "user_image:./user/image/4.jpeg", "./user/user_info.txt");
    }
    gtk_widget_destroy(window1);
    /*补充发送给服务端的函数*/
}

void show_window_set()
{
    GtkWidget *vbox,hbox;
    GtkWidget *button;
    GtkWidget *image;
    GtkWidget *table;

    gint *image_default=0;
    gint *image_1=1;
    gint *image_2=2;
    gint *image_3=3;
    gint *image_4=4;

    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window1),"destroy", G_CALLBACK(gtk_widget_destroy),window1);

    table=gtk_table_new(4,4,FALSE);
    gtk_container_add(GTK_CONTAINER(window1),table);
    button=gtk_button_new();
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,2,0,2);
    image=gtk_image_new_from_pixbuf(get_pix(1));
    gtk_container_add(GTK_CONTAINER(button),image);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_selsect_clicked),(gpointer)image_1);

    button=gtk_button_new();
    gtk_table_attach_defaults(GTK_TABLE(table),button,2,4,0,2);
    image=gtk_image_new_from_pixbuf(get_pix(2));
    gtk_container_add(GTK_CONTAINER(button),image);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_selsect_clicked),(gpointer)image_2);

    button=gtk_button_new();
    gtk_table_attach_defaults(GTK_TABLE(table),button,0,2,2,4);
    image=gtk_image_new_from_pixbuf(get_pix(3));
    gtk_container_add(GTK_CONTAINER(button),image);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_selsect_clicked),(gpointer)image_3);

    button=gtk_button_new();
    gtk_table_attach_defaults(GTK_TABLE(table),button,2,4,2,4);
    image=gtk_image_new_from_pixbuf(get_pix(4));
    gtk_container_add(GTK_CONTAINER(button),image);
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_selsect_clicked),(gpointer)image_4);

    gtk_widget_show_all(window1);

}
