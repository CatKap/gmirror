#include <gtk-4.0/gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <string.h>

const gchar* TEXT = "<span foreground=\"blue\" size=\"x-large\">Blue text</span> is <i>cool</i>!";

static void print_hello (GtkWidget *widget,              gpointer   data)
{
  g_print ("Hello World\n");
}



static int command_line (GtkApplication *app,  GApplicationCommandLine *cmdline) 
{
  gchar **argv;
  gint argc;
  gint i;
  
  argv = g_application_command_line_get_arguments(cmdline, &argc);
  
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *s_window;
  GtkWidget *v_box;
  GtkWidget *grid;
  
  window = gtk_application_window_new (app);
  s_window = gtk_scrolled_window_new(); 
  gtk_widget_set_vexpand(s_window, 1);
  v_box = gtk_box_new(1, 5);
  
  
  gtk_window_set_title (GTK_WINDOW (window), "Hello");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
  
  button = gtk_button_new_with_label (argv[1]);
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  
  
  
  
  GtkWidget *label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label), "<span foreground=\"blue\" size=\"x-large\">Blue text</span> is <i>cool</i>!\n\nlskdjfskljdfsdlkfsalkdjfslkdfljsd");
  
  PangoLayout* label_layout = gtk_label_get_layout((GtkLabel*)label);
  pango_layout_set_alignment(label_layout, PANGO_ALIGN_RIGHT);

  gtk_scrolled_window_set_child((GtkScrolledWindow*)s_window, label);
  gtk_box_append((GtkBox*)v_box, s_window);
  gtk_box_append((GtkBox*)v_box, button);
  
  gtk_window_set_child (GTK_WINDOW (window), v_box);
  gtk_window_present (GTK_WINDOW (window));
}


int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_HANDLES_COMMAND_LINE);
  g_signal_connect (app, "command_line", G_CALLBACK (command_line), (gpointer) NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
