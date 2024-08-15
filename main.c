#include <gtk-4.0/gtk/gtk.h>

const gchar* TEXT = "<span foreground=\"blue\" size=\"x-large\">Blue text</span> is <i>cool</i>!";



static void print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *s_window;

  window = gtk_application_window_new (app);
  s_window = gtk_scrolled_window_new(); 
  gtk_window_set_title (GTK_WINDOW (window), "Hello");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);




  GtkWidget *label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label), "<span foreground=\"blue\" size=\"x-large\">Blue text</span> is <i>cool</i>!\n\nlskdjfskljdfsdlkfsalkdjfslkdfljsd");

  PangoLayout* label_layout = gtk_label_get_layout((GtkLabel*)label);
  pango_layout_set_alignment(label_layout, PANGO_ALIGN_RIGHT);
  gtk_scrolled_window_set_child((GtkScrolledWindow*)s_window, label);
  gtk_window_set_child (GTK_WINDOW (window), s_window);
  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
