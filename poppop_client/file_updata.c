#include <gtk/gtk.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
/*文件路径:file_path 将第line行的内容改为text*/

void change(int line, char *text,char *file_path)

{



	FILE *fp = fopen(file_path, "r +");

	char buff[1024];

	char ch;

	int cur=0,cur1=0;

	while ((ch =fgetc(fp)) != EOF)

	{

		buff[cur++] = ch;

	}

	buff[cur++] = 0;



	int line_cnt = 1,pos_begin,pos_end;

	while (line_cnt != line)

	{

		if (buff[cur1++] == '\n')

			line_cnt++;

	}

	pos_end=pos_begin = cur1;

	while (buff[cur1++] != '\n')

		pos_end++;

	char buff2[2048];

	int tp1 = 0,tp2=0;

	while (1)

	{



		if (tp1 == pos_begin)

		{

			tp1 = pos_end;

			int str_len = strlen(text);

			for (int I = 0; I < str_len; I++)

				buff2[tp2++] = text[I];

		}

		buff2[tp2] = buff[tp1];

		tp2++;

		tp1++;

		if (buff[tp1] == 0)

		{

			buff[tp2] = 0;

			break;

		}

	}

	//g_print(buff2);



	fclose(fp);

	FILE *fp1 = fopen(file_path, "w");

	fclose(fp1);

	FILE *fp2 = fopen(file_path, "r +");

	for (int I = 0; I < tp2; I++)

		fputc(buff2[I], fp2);

    fclose(fp2);



}


void delete_line(char *text, char* file_path)
{
	FILE *fp = fopen(file_path, "r +");

	char buff[1024] = { 0 };

	char ch;

	int cur = 0, cur1 = 0;

	while ((ch = fgetc(fp)) != EOF)

	{

		buff[cur++] = ch;

	}
	buff[cur] = 0;
	if(strstr(buff,text)==NULL)
    	{
      	  g_print("No substring in the text\n");
       	 return;
    	}
	char char_s[1000] = { 0 };
	int p_begin = 0;
	int d_begin=0, d_end=0;
	int s_begin = 0;
	while(1)
	{

		char_s[s_begin++]=buff[p_begin++];
		if (char_s[s_begin-1] == '\n' ||char_s[s_begin -1] == 0)//得到一行子串
		{
			s_begin = 0;
			d_end = p_begin - 1;
			if (strstr(char_s, text) != NULL)
			{
				break;
			}
			memset(char_s, 0, sizeof(char_s));

			d_begin = p_begin;//更新
		}
	}
	char buff2[2048] = { 0 };
	int p1 =0, p2 = 0;
	while (1)
	{
		if (p1 == d_begin)
		{
			p1 = d_end + 1;
		}
		buff2[p2++] = buff[p1++];
		if (p1 >= cur)
			break;
	}
	fclose(fp);

	FILE *fp1 = fopen(file_path, "w");

	fclose(fp1);

	FILE *fp2 = fopen(file_path, "r +");
	int len = strlen(buff2);
	for (int I = 0; I < len; I++)

		fputc(buff2[I], fp2);

	fclose(fp2);
}

void change_friend_label(char *friendname, char *label)
{
    FILE *in=fopen("./user/friend_info.txt","r");
    FILE *out=fopen("./user/tmp.txt","w");
    char buffer[1024];

    while(fscanf(in, "%s", buffer) != EOF)
    {

       if(strstr(buffer, friendname) == NULL)
       {
         strcat(buffer, "\n");
         fprintf(out, "%s", buffer);
         g_print("%s\n", buffer);
       }
       else
       {
         char str[1024];
         memset(str, '\0', sizeof(str));
         strcpy(str, label);
         char *pointer = strchr(buffer, ':');
         strcat(str, pointer);
         strcat(str, "\n");
         fprintf(out, "%s", str);
         g_print("%s\n", str);
       }

       memset(buffer, '\0', sizeof(buffer));
    }

    fclose(in);
    fclose(out);
    unlink("./user/friend_info.txt"); /*删除test.txt*/
    rename("./user/tmp.txt","./user/friend_info.txt"); /*改名*/
}


void add_friendlist_label(char *label)
{
    FILE *in=fopen("./user/user_info.txt","r");
    FILE *out=fopen("./user/tmp.txt","w");
    char buffer[1024];
    char tmp[1024];
    memset(tmp, '\0', sizeof(tmp));
    char *point;

    for(int i=0; i<6; i++)
    {
       fscanf(in, "%s", buffer);
       switch(i)
       {
         case 4:
         point = strchr(buffer, '/');
         strncpy(tmp, buffer, point - buffer);
         strcat(tmp, label);
         strcat(tmp, ",/");
         strcat(tmp, "\n");
         fprintf(out, "%s", tmp);
         break;

         default :
         strcat(buffer, "\n");
         fprintf(out, "%s", buffer);
         break;
       }
    }

    fclose(in);
    fclose(out);
    unlink("./user/user_info.txt"); /*删除test.txt*/
    rename("./user/tmp.txt","./user/user_info.txt"); /*改名*/
}
