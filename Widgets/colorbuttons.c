#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);
static void color_changed (GtkColorButton*, GtkWidget*);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *button, *label, *hbox;
  GdkRGBA color;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Color Button");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);

  /* Set the initial color as #003366 and set the dialog title. */
  gdk_rgba_parse (&color, "#003366");
  button = gtk_color_button_new_with_rgba (&color);
  gtk_color_button_set_title (GTK_COLOR_BUTTON (button), "Select a Color");
  
  label = gtk_label_new ("Look at my color!");
  gtk_widget_override_color(label, GTK_STATE_FLAG_NORMAL, &color);

  g_signal_connect (G_OBJECT (button), "color_set",
                    G_CALLBACK (color_changed),
                    (gpointer) label);
  
  hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 5);
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 5);

  gtk_container_add (GTK_CONTAINER (window), hbox);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

/* Retrieve the selected color and set it as the GtkLabel's foreground color. */
static void
color_changed (GtkColorButton *button,
               GtkWidget *label)
{
  GdkRGBA color;
  gtk_color_button_get_rgba(button, &color);
  gtk_widget_override_color (label, GTK_STATE_FLAG_NORMAL, &color);
}

static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}
