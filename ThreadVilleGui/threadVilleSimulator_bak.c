#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);

int main (int argc, 
          char *argv[])
{
    GtkWidget *window, *hbox, *vboxBuses, *vboxActions , *vboxNaranja, *vboxRosa, *vboxCeleste, *vboxBlanco, *vboxNegro, *vboxGris, *vboxRojo, *vboxVerde, *vboxAzul,
    *labelNaranja, *labelRosa, *labelCeleste, *labelBlanco, *labelNegro, *labelGris, *labelRojo, *labelVerde, *labelAzul;
    

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "ThreadVilleSimulator");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (window, 640, 480);

    g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (destroy), NULL);

    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
    vboxBuses = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    vboxActions = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);

    vboxNaranja = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelNaranja = gtk_label_new ("Bus Naranja");
    gtk_label_set_xalign(GTK_LABEL(labelNaranja), 0.0);
    gtk_container_add (GTK_CONTAINER (vboxNaranja), labelNaranja);

    vboxRosa = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelRosa = gtk_label_new ("Bus Rosa");    
    gtk_label_set_xalign(GTK_LABEL(labelNaranja), 0.0);
    gtk_container_add (GTK_CONTAINER (vboxRosa), labelRosa);


    vboxCeleste = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelCeleste = gtk_label_new ("Bus Celeste");
    gtk_container_add (GTK_CONTAINER (vboxCeleste), labelCeleste);


    vboxBlanco = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelBlanco = gtk_label_new ("Bus Blanco");
    gtk_container_add (GTK_CONTAINER (vboxBlanco), labelBlanco);


    vboxNegro = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelNegro = gtk_label_new ("Bus Negro");
    gtk_container_add (GTK_CONTAINER (vboxNegro), labelNegro);


    vboxGris = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelGris = gtk_label_new ("Bus Gris");
    gtk_container_add (GTK_CONTAINER (vboxGris), labelGris);


    vboxRojo = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelRojo = gtk_label_new ("Bus Rojo");
    gtk_container_add (GTK_CONTAINER (vboxRojo), labelRojo);


    vboxVerde = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelVerde = gtk_label_new ("Bus Verde");
    gtk_container_add (GTK_CONTAINER (vboxVerde), labelVerde);


    vboxAzul = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
    labelAzul = gtk_label_new ("Bus Azul");
    gtk_container_add (GTK_CONTAINER (vboxAzul), labelAzul);


    gtk_box_pack_start (GTK_BOX (hbox), vboxBuses, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (hbox), vboxActions, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxNaranja, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxRosa, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxCeleste, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxBlanco, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxNegro, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxGris, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxRojo, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxVerde, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vboxBuses), vboxAzul, TRUE, TRUE, 0);

    gtk_container_add (GTK_CONTAINER (window), hbox);

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
