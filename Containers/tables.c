#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *table, *label, *label2, *name;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Tables");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);

  table =  gtk_grid_new ();
  label = gtk_label_new ("Enter the following information ...");
  label2 = gtk_label_new ("Name: ");
  name = gtk_entry_new ();
  
  /* Attach the two labels and entry widget to their parent container. */
  gtk_grid_attach (GTK_GRID (table), label, 0, 0, 2, 1);
  gtk_grid_attach (GTK_GRID (table), label2, 0, 1, 1, 2);
  gtk_grid_attach (GTK_GRID (table), name, 1, 1, 2, 2);

  /* Add five pixels of spacing between every row and every column. */
  gtk_grid_set_column_spacing (GTK_GRID (table), 5);
  gtk_grid_set_row_spacing (GTK_GRID (table), 5);

  gtk_container_add (GTK_CONTAINER (window), table);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}
