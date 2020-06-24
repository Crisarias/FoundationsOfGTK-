#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);

int main (int argc, 
          char *argv[])
{
    GtkWidget *window, *grid, *labelNaranja, *labelRosa, *labelCeleste, *labelBlanco, *labelNegro, *labelGris, *labelRojo, *labelVerde, *labelAzul;
    

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "ThreadVilleSimulator");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 640, 480);

    g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (destroy), NULL);

    grid =  gtk_grid_new ();

    labelNaranja = gtk_label_new ("Bus Naranja");
    gtk_widget_set_halign (labelNaranja, GTK_ALIGN_START);


    labelRosa = gtk_label_new ("Bus Rosa");
    gtk_widget_set_halign (labelRosa, GTK_ALIGN_START);

    labelCeleste = gtk_label_new ("Bus Celeste");
    gtk_widget_set_halign (labelCeleste, GTK_ALIGN_START);

    labelBlanco = gtk_label_new ("Bus Blanco");
    gtk_widget_set_halign (labelBlanco, GTK_ALIGN_START);

    labelNegro = gtk_label_new ("Bus Negro");
    gtk_widget_set_halign (labelNegro, GTK_ALIGN_START);

    labelGris = gtk_label_new ("Bus Gris");
    gtk_widget_set_halign (labelGris, GTK_ALIGN_START);

    labelRojo = gtk_label_new ("Bus Rojo");
    gtk_widget_set_halign (labelRojo, GTK_ALIGN_START);

    labelVerde = gtk_label_new ("Bus Verde");
    gtk_widget_set_halign (labelVerde, GTK_ALIGN_START);

    labelAzul = gtk_label_new ("Bus Azul");
    gtk_widget_set_halign (labelAzul, GTK_ALIGN_START);

    /*Attach controls to parent Grid*/
    gtk_grid_attach (GTK_GRID (grid), labelNaranja, 0, 0, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelRosa, 0, 1, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelCeleste, 0, 2, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelBlanco, 0, 3, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelNegro, 0, 4, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelGris, 0, 5, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelRojo, 0, 6, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelVerde, 0, 7, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelAzul, 0, 8, 2, 1);

    gtk_container_add (GTK_CONTAINER (window), grid);
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
