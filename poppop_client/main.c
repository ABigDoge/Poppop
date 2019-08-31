#include <stdlib.h>
#include <gtk/gtk.h>
#include "login.c"

int main (int argc, char *argv[])
{
  gtk_init (&argc, &argv);

  login_run();

  gtk_main ();
  return 0;

}
