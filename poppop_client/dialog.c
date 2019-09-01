#include <gtk/gtk.h>
#include <string.h>
//sioioiii/s2
//ijijiji/ji//s2

GtkWidget *text_view;

GtkWidget *send_text;

GtkTextBuffer *buffer, *sbuffer;

GtkTextIter *Iter;

void destory_sticker_window(GtkWidget *widget,GdkEventCrossing *event,GtkWidget* data);

void insert_sticker(GtkWidget *widget,GdkEventButton *event, gint stiker_num);

void printcontent(gchar *text );

void printstiker(gint x);

void printwords(gchar* text);


void create_message_dialog (GtkMessageType type, gchar* message);




// 点击发送按钮
//*************************************************
void send_button_event(GtkWidget *widget)

{

GtkTextIter start,end;

gtk_text_buffer_get_start_iter(sbuffer,&start);

gtk_text_buffer_get_end_iter(sbuffer,&end);

char *text=gtk_text_buffer_get_text(sbuffer,&start,&end,TRUE);

int len= strlen(text);

//for(int i=0; i<len;i++)
//  printf("%c",text[i]);

if(len>0)
{
   printcontent(text);

   gtk_text_buffer_get_end_iter(buffer,&end);

   gtk_text_buffer_insert(buffer,&end,"\n",-1);

   gtk_text_buffer_set_text(sbuffer,"",-1);

  //memset(sbuffer,'\0', sizeof(sbuffer));

}

else
   create_message_dialog(GTK_MESSAGE_INFO,
   "The message is not allowed to be empty!");

}
//*************************************************

//打印文本框的内容
//*************************************************
void printcontent(char *text )
{
 GtkTextIter end;

 int len = strlen(text);

 if(len==0) return;

 int i,flag=0;

 for (i=0;i<len;i++)
    {

      if (text[i] == '/')
        {
          gchar pre[i];
          int j=0;
          for (j=0;j<i;j++)

             pre[j]=text[j];

          pre[j] = '\0';

         // for(int k=0; k<j;k++) g_print("%c",pre[k]);

          printwords(pre);
          //gtk_text_buffer_get_end_iter(buffer,&end);

          //gtk_text_buffer_insert(buffer,&end,pre,strlen(pre));

          flag=1;

          break;

        }
    }

  if (flag)
    {   if(text[i+1] == 's' && text[i+2] >='1' && text[i+2]<='6')

        { gint x= text[i+2]-'0';

          printstiker(x);

          printcontent(&text[i+3]);
        }

        else
        {  gtk_text_buffer_get_end_iter(buffer,&end);

           gtk_text_buffer_insert(buffer,&end,"/",-1);

           printcontent(&text[i+1]);
        }
    }

  else
    printwords(text);

}
//*************************************************

//打印纯文本
//*************************************************
void printwords(gchar *text)
{

GtkTextIter end;

gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer),&end);

gtk_text_buffer_insert(GTK_TEXT_BUFFER(buffer),&end,text,-1);

}
//*************************************************

//打印表情
//*************************************************
void printstiker(gint i)
{

GtkTextIter end;

gtk_text_buffer_get_end_iter(buffer,&end);

GtkWidget *image;

switch(i)
{

case 1: image = gtk_image_new_from_file("./user/emoji/s1.png");
        break;
case 2: image = gtk_image_new_from_file("./user/emoji/s2.png");
        break;
case 3: image = gtk_image_new_from_file("./user/emoji/s3.png");
        break;
case 4: image = gtk_image_new_from_file("./user/emoji/s4.png");
        break;
case 5: image = gtk_image_new_from_file("./user/emoji/s5.png");
        break;
case 6: image = gtk_image_new_from_file("./user/emoji/s6.png");
        break;

}
GtkTextChildAnchor *anchor;

anchor = gtk_text_buffer_create_child_anchor(buffer,&end);//创建子控件的位置标记

gtk_text_view_add_child_at_anchor(GTK_TEXT_VIEW(text_view),image,anchor);

gtk_widget_show(image);

}
//*************************************************

// 点击表情按钮
//*************************************************
void stiker_button_event(GtkWidget *widget)
{

GtkWidget *sticker_window;

GtkWidget *eventbox;

GtkWidget *sbox1, *sbox2, *sbox3, *sbox4, *sbox5, *sbox6;  //盛放6个表情的eventbox

GtkWidget *table;

GtkWidget *s1, *s2, *s3, *s4, *s5, *s6; //6个表情的image

sticker_window = gtk_window_new(GTK_WINDOW_POPUP);

gtk_window_set_default_size(GTK_WINDOW(sticker_window),100,100);

gtk_widget_set_size_request(sticker_window,150,90);

gtk_window_set_position(GTK_WINDOW(sticker_window), GTK_WIN_POS_MOUSE);

eventbox = gtk_event_box_new();

g_signal_connect(G_OBJECT(eventbox),"leave_notify_event",G_CALLBACK(destory_sticker_window),sticker_window);

gtk_container_add(GTK_CONTAINER(sticker_window),eventbox);

table = gtk_table_new(2,3,FALSE);

gtk_container_add(GTK_CONTAINER(eventbox),table);

sbox1 = gtk_event_box_new();

sbox2 = gtk_event_box_new();

sbox3 = gtk_event_box_new();

sbox4 = gtk_event_box_new();

sbox5 = gtk_event_box_new();

sbox6 = gtk_event_box_new();

g_signal_connect(G_OBJECT(sbox1),"button_press_event",G_CALLBACK(insert_sticker),1);
g_signal_connect(G_OBJECT(sbox2),"button_press_event",G_CALLBACK(insert_sticker),2);
g_signal_connect(G_OBJECT(sbox3),"button_press_event",G_CALLBACK(insert_sticker),3);
g_signal_connect(G_OBJECT(sbox4),"button_press_event",G_CALLBACK(insert_sticker),4);
g_signal_connect(G_OBJECT(sbox5),"button_press_event",G_CALLBACK(insert_sticker),5);
g_signal_connect(G_OBJECT(sbox6),"button_press_event",G_CALLBACK(insert_sticker),6);

s1=gtk_image_new_from_file("./user/emoji/s1.png");

s2=gtk_image_new_from_file("./user/emoji/s2.png");

s3=gtk_image_new_from_file("./user/emoji/s3.png");

s4=gtk_image_new_from_file("./user/emoji/s4.png");

s5=gtk_image_new_from_file("./user/emoji/s5.png");

s6=gtk_image_new_from_file("./user/emoji/s6.png");

gtk_container_add(GTK_CONTAINER(sbox1),s1);

gtk_container_add(GTK_CONTAINER(sbox2),s2);

gtk_container_add(GTK_CONTAINER(sbox3),s3);

gtk_container_add(GTK_CONTAINER(sbox4),s4);

gtk_container_add(GTK_CONTAINER(sbox5),s5);

gtk_container_add(GTK_CONTAINER(sbox6),s6);

gtk_table_attach_defaults(GTK_TABLE(table),sbox1,0,1,0,1);

gtk_table_attach_defaults(GTK_TABLE(table),sbox2,1,2,0,1);

gtk_table_attach_defaults(GTK_TABLE(table),sbox3,2,3,0,1);

gtk_table_attach_defaults(GTK_TABLE(table),sbox4,0,1,1,2);

gtk_table_attach_defaults(GTK_TABLE(table),sbox5,1,2,1,2);

gtk_table_attach_defaults(GTK_TABLE(table),sbox6,2,3,1,2);

gtk_widget_show_all(sticker_window);

}
//*************************************************

//将表情插入编辑框
//*************************************************
void insert_sticker(GtkWidget *widget,GdkEventButton *event, gint stiker_num)
{    gchar *x;
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(sbuffer,&end);

    if(stiker_num == 1)
        x="/s1";
    else if(stiker_num ==2)
         x="/s2";
    else if(stiker_num ==3)
         x="/s3";
    else if(stiker_num ==4)
       x="/s4";
    else if(stiker_num ==5)
       x="/s5";
    else
       x="/s6";

 gtk_text_buffer_insert(GTK_TEXT_BUFFER(sbuffer),&end,x,-1);
}

void destory_sticker_window(GtkWidget *widget,GdkEventCrossing *event,GtkWidget* data)
{
    gtk_widget_destroy(data);
}

void create_message_dialog (GtkMessageType type, gchar* message){
    GtkWidget* dialogx;
    dialogx = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,type,GTK_BUTTONS_OK,message);
    gtk_dialog_run(GTK_DIALOG(dialogx));
    gtk_widget_destroy(dialogx);
}
//*************************************************

void dialog_run()

{

  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "./UI/dialog.glade", NULL);

  GtkWidget *dialog_window = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_window"));
  g_signal_connect(G_OBJECT(dialog_window), "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

  GtkWidget *send_button = GTK_WIDGET(gtk_builder_get_object(builder, "send_button"));
  g_signal_connect(G_OBJECT(send_button), "clicked", G_CALLBACK(send_button_event), NULL);

  GtkWidget *emoji_button = GTK_WIDGET(gtk_builder_get_object(builder, "emoji_button"));
  g_signal_connect(G_OBJECT(emoji_button), "clicked", G_CALLBACK(stiker_button_event), NULL);


  text_view = GTK_WIDGET(gtk_builder_get_object(builder, "text_view"));
  send_text = GTK_WIDGET(gtk_builder_get_object(builder, "send_text"));

  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
  sbuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(send_text));

  g_object_unref(G_OBJECT (builder));
  gtk_widget_show(dialog_window);
}





