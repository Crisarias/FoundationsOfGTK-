#include <gtk/gtk.h>
#define BusNaranja 0
#define BusRosa 1
#define BusCeleste 2
#define BusBlanco 3
#define BusNegro 4
#define BusGris 5
#define BusRojo 6
#define BusVerde 7
#define BusAzul 8

static void destroy (GtkWidget*, gpointer);
// Set the style provider for the widgets
static void apply_css_provider (GtkWidget * widget, GtkCssProvider * cssstyleProvider);
// Set the action depending on the toggle value and call the correct function depending on the color
static void button_toggled (GtkToggleButton *toggle, gpointer busColor);
// Activate bus
static void enable_bus(int busColor);
// Deactivate bus
static void disable_bus(int busColor);
//Add car with random destination
static void add_car(GtkButton *button, gpointer data);
//Add ambulance with random destination
static void add_ambulance(GtkButton *button, gpointer data);
//Add car with custom arguments
static void add_custom_car(GtkButton *button, gpointer data);
//Add ambulance with custom arguments
static void add_custom_ambulance(GtkButton *button, gpointer data);
//Inicia la simulación con los parámetros dados
static void start_simulation(GtkButton *button, gpointer data);
//Detiene la simulación
static void stop_simulation(GtkButton *button, gpointer data);

gchar *inactiveBusLabel = "Click para Inactivar";
gchar *activeBusLabel = "Click para Activar";

GtkWidget *buttonStartSimulation, *buttonStopSimulation;

int main (int argc, 
          char *argv[])
{
    GtkWidget *window, *grid, *labelBuses, *labelAutosAmbulancias, *vseparator, *hseparator,
    *labelNaranja, *toggleNaranja,
    *labelRosa, *toggleRosa,
    *labelCeleste, *toggleCeleste,
    *labelBlanco, *toggleBlanco,
    *labelNegro, *toggleNegro,
    *labelGris, *toggleGris,
    *labelRojo, *toggleRojo,
    *labelVerde, *toggleVerde,
    *labelAzul, *toggleAzul,
    *buttonRandomCar, *buttonRandomAmbulance,
    *labelCustomCar, *labelCustomCarColor, *labelCustomCarDestination, *entryColorCar, *entryDestinationCar, *buttonCustomCar,
    *labelCustomAmbulance, *labelCustomAmbulanceDestination, *entryDestinationAmbulance, *buttonCustomAmbulance;  
    GtkCssProvider *    cssProvider     = gtk_css_provider_new();  

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Thread Ville Simulator");
    gtk_container_set_border_width (GTK_CONTAINER (window), 20);
    gtk_widget_set_size_request (window, 640, 480);

    g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (destroy), NULL);

    grid =  gtk_grid_new ();

    labelBuses = gtk_label_new ("Control de Buses");
    vseparator = gtk_separator_new (GTK_ORIENTATION_VERTICAL);
    labelAutosAmbulancias = gtk_label_new ("Control de Autos y Ambulancias");
    hseparator = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);

    labelNaranja  = gtk_label_new ("Bus Naranja");
    gtk_widget_set_halign (labelNaranja, GTK_ALIGN_START);
    toggleNaranja  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleNaranja), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusNaranja);


    labelRosa  = gtk_label_new ("Bus Rosa");
    gtk_widget_set_halign (labelRosa, GTK_ALIGN_START);
    toggleRosa  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleRosa), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusRosa);
    
    labelCeleste  = gtk_label_new ("Bus Celeste");
    gtk_widget_set_halign (labelCeleste, GTK_ALIGN_START);
    toggleCeleste  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleCeleste), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusCeleste);
    
    labelBlanco  = gtk_label_new ("Bus Blanco");
    gtk_widget_set_halign (labelBlanco, GTK_ALIGN_START);
    toggleBlanco  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleBlanco), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusBlanco);

    labelNegro  = gtk_label_new ("Bus Negro");
    gtk_widget_set_halign (labelNegro, GTK_ALIGN_START);
    toggleNegro  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleNegro), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusNegro);

    labelGris  = gtk_label_new ("Bus Gris");
    gtk_widget_set_halign (labelGris, GTK_ALIGN_START);
    toggleGris  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleGris), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusGris);

    labelRojo  = gtk_label_new ("Bus Rojo");
    gtk_widget_set_halign (labelRojo, GTK_ALIGN_START);
    toggleRojo  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleRojo), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusRojo);

    labelVerde  = gtk_label_new ("Bus Verde");
    gtk_widget_set_halign (labelVerde, GTK_ALIGN_START);
    toggleVerde  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleVerde), "toggled",
                G_CALLBACK (button_toggled),
                (gpointer)BusVerde);

    labelAzul  = gtk_label_new ("Bus Azul");
    gtk_widget_set_halign (labelAzul, GTK_ALIGN_START); 
    toggleAzul  = gtk_toggle_button_new_with_mnemonic (inactiveBusLabel);
    g_signal_connect (G_OBJECT (toggleAzul), "toggled",
                G_CALLBACK (button_toggled),
               (gpointer)BusAzul);

    buttonRandomCar = gtk_button_new_with_mnemonic ("Agregar automóvil con destino aleatorio");
    g_signal_connect (G_OBJECT (buttonRandomCar), "clicked",
            G_CALLBACK (add_car),
            NULL);

    buttonRandomAmbulance = gtk_button_new_with_mnemonic ("Agregar ambulacia con destino aleatorio");
    g_signal_connect (G_OBJECT (buttonRandomAmbulance), "clicked",
            G_CALLBACK (add_ambulance),
            NULL);

    labelCustomCar  = gtk_label_new ("Automóvil Personalizado");
    gtk_widget_set_halign (labelCustomCar, GTK_ALIGN_START);
    labelCustomCarColor  = gtk_label_new ("Color:");
    gtk_widget_set_halign (labelCustomCarColor, GTK_ALIGN_START);
    entryColorCar = gtk_entry_new ();
    labelCustomCarDestination  = gtk_label_new ("Destino:");    
    gtk_widget_set_halign (labelCustomCarDestination, GTK_ALIGN_START);
    entryDestinationCar = gtk_entry_new ();
    buttonCustomCar = gtk_button_new_with_mnemonic ("Agregar automóvil personalizado");
    g_signal_connect (G_OBJECT (buttonCustomCar), "clicked",
            G_CALLBACK (add_custom_car),
            NULL);
    

    labelCustomAmbulance  = gtk_label_new ("Ambulancia Personalizada");    
    gtk_widget_set_halign (labelCustomAmbulance, GTK_ALIGN_START); 
    labelCustomAmbulanceDestination  = gtk_label_new ("Destino:");
    gtk_widget_set_halign (labelCustomAmbulanceDestination, GTK_ALIGN_START);
    entryDestinationAmbulance = gtk_entry_new ();
    buttonCustomAmbulance = gtk_button_new_with_mnemonic ("Agregar Ambulancia personalizada");
    g_signal_connect (G_OBJECT (buttonCustomAmbulance), "clicked",
            G_CALLBACK (add_custom_ambulance),
            NULL);

    
    buttonStartSimulation = gtk_button_new_with_mnemonic ("Iniciar Simulación");
    g_signal_connect (G_OBJECT (buttonStartSimulation), "clicked",
            G_CALLBACK (start_simulation),
            NULL);

    buttonStopSimulation = gtk_button_new_with_mnemonic ("Detener Simulación");
    gtk_widget_set_sensitive(GTK_WIDGET(buttonStopSimulation), FALSE);
    g_signal_connect (G_OBJECT (buttonStopSimulation), "clicked",
            G_CALLBACK (stop_simulation),
            NULL);

    /*Attach controls to parent Grid*/
    gtk_grid_attach (GTK_GRID (grid), labelBuses, 0, 0, 2, 1);

    gtk_grid_attach (GTK_GRID (grid), labelNaranja, 0, 1, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleNaranja, 1, 1, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelRosa, 0, 2, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleRosa, 1, 2, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelCeleste, 0, 3, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleCeleste, 1, 3, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelBlanco, 0, 4, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleBlanco, 1, 4, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelNegro, 0, 5, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleNegro, 1, 5, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelGris, 0, 6, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleGris, 1, 6, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelRojo, 0, 7, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleRojo, 1, 7, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelVerde, 0, 8, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleVerde, 1, 8, 1, 1);
    
    gtk_grid_attach (GTK_GRID (grid), labelAzul, 0, 9, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), toggleAzul, 1, 9, 1, 1);

    gtk_grid_attach (GTK_GRID (grid), vseparator, 3, 0, 1, 10);

    gtk_grid_attach (GTK_GRID (grid), labelAutosAmbulancias, 4, 0, 2, 1);

    gtk_grid_attach (GTK_GRID (grid), buttonRandomCar, 4, 1, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), buttonRandomAmbulance, 4, 2, 2, 1);

    gtk_grid_attach (GTK_GRID (grid), labelCustomCar, 4, 3, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelCustomCarColor, 4, 4, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), entryColorCar, 5, 4, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), labelCustomCarDestination, 4, 5, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), entryDestinationCar, 5, 5, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), buttonCustomCar, 4, 6, 2, 1);

    gtk_grid_attach (GTK_GRID (grid), labelCustomAmbulance, 4, 7, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), labelCustomAmbulanceDestination, 4, 8, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), entryDestinationAmbulance, 5, 8, 1, 1);
    gtk_grid_attach (GTK_GRID (grid), buttonCustomAmbulance, 4, 9, 2, 1);

    gtk_grid_attach (GTK_GRID (grid), hseparator, 0, 10, 6, 1);

    gtk_grid_attach (GTK_GRID (grid), buttonStartSimulation, 0, 11, 2, 1);
    gtk_grid_attach (GTK_GRID (grid), buttonStopSimulation, 5, 11, 2, 1);


      /* Add five pixels of spacing between every row and every column. */
    gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
    gtk_grid_set_row_spacing (GTK_GRID (grid), 10);

    gtk_container_add (GTK_CONTAINER (window), grid);

    if( gtk_css_provider_load_from_path(cssProvider, "threadVilleSimulator.css", NULL) )
    {
        apply_css_provider( window , cssProvider );

        // set a default style - name is defined in .CSS file
        gtk_widget_set_name( GTK_WIDGET(labelBuses) , "title-label" );
        gtk_widget_set_name( GTK_WIDGET(labelAutosAmbulancias) , "title-label" );
        gtk_widget_set_name( GTK_WIDGET(labelCustomCar) , "description-label" );
        gtk_widget_set_name( GTK_WIDGET(labelCustomAmbulance) , "description-label" );        
        gtk_widget_set_name( GTK_WIDGET(toggleNaranja) , "orange" );        
        gtk_widget_set_name( GTK_WIDGET(toggleRosa) , "pink" );
        gtk_widget_set_name( GTK_WIDGET(toggleCeleste) , "skyBlue" );
        gtk_widget_set_name( GTK_WIDGET(toggleBlanco) , "white" );
        gtk_widget_set_name( GTK_WIDGET(toggleNegro) , "black" );
        gtk_widget_set_name( GTK_WIDGET(toggleGris) , "gray" );
        gtk_widget_set_name( GTK_WIDGET(toggleRojo) , "red" );
        gtk_widget_set_name( GTK_WIDGET(toggleVerde) , "green" );
        gtk_widget_set_name( GTK_WIDGET(toggleAzul) , "blue" );

        gtk_widget_show_all(window);

        gtk_main();
    }
    
    return 0;
}

static void
destroy (GtkWidget *window,
         gpointer data)
{
    gtk_main_quit ();
}

static void apply_css_provider (GtkWidget * widget, GtkCssProvider * cssstyleProvider)
{
    gtk_style_context_add_provider ( gtk_widget_get_style_context(widget), GTK_STYLE_PROVIDER(cssstyleProvider) , GTK_STYLE_PROVIDER_PRIORITY_USER );

    // For container widgets, apply to every child widget on the container
    if (GTK_IS_CONTAINER (widget))
    {
        gtk_container_forall( GTK_CONTAINER (widget), (GtkCallback)apply_css_provider , cssstyleProvider);
    }
}

static void 
button_toggled (GtkToggleButton *toggle, 
                gpointer busColor)
{
    if (gtk_toggle_button_get_active (toggle))
    {
        gtk_button_set_label (GTK_BUTTON (toggle), activeBusLabel);
        disable_bus((int)busColor);
    }    
    else
    {      
        gtk_button_set_label (GTK_BUTTON (toggle), inactiveBusLabel);
        enable_bus((int)busColor);
    }    
}

static void enable_bus(int busColor) {
    switch (busColor)
    {
    case BusNaranja:
        puts("Bus Naranja activado");
        break;
    case BusRosa:
        puts("Bus Rosa activado");
        break;
    case BusCeleste:
        puts("Bus Celeste activado");
        break;
    case BusBlanco:
        puts("Bus Blanco activado");
        break;
    case BusNegro:
        puts("Bus Negro activado");
        break;
    case BusGris:
        puts("Bus Gris activado");
        break;
    case BusRojo:
        puts("Bus Rojo activado");
        break;
    case BusVerde:
        puts("Bus Verde activado");
        break;
    case BusAzul:
        puts("Bus Azul activado");
        break;    
    default:
        break;
    }
}

static void disable_bus(int busColor) {
    switch (busColor)
    {
    case BusNaranja:
        puts("Bus Naranja inactivado");
        break;
    case BusRosa:
        puts("Bus Rosa inactivado");
        break;
    case BusCeleste:
        puts("Bus Celeste inactivado");
        break;
    case BusBlanco:
        puts("Bus Blanco inactivado");
        break;
    case BusNegro:
        puts("Bus Negro inactivado");
        break;
    case BusGris:
        puts("Bus Gris inactivado");
        break;
    case BusRojo:
        puts("Bus Rojo inactivado");
        break;
    case BusVerde:
        puts("Bus Verde inactivado");
        break;
    case BusAzul:
        puts("Bus Azul inactivado");
        break;    
    default:
        break;
    }
}

static void add_car(GtkButton *button, gpointer data)
{
    puts("Automóvil con destino aleatorio agregado");
}

static void add_ambulance(GtkButton *button, gpointer data)
{
    puts("Ambulancia con destino aleatorio agregada");
}

static void add_custom_car(GtkButton *button, gpointer data)
{
    puts("Automóvil personalizado agregado");
}

static void add_custom_ambulance(GtkButton *button, gpointer data)
{
    puts("Ambulancia personalizada agregada");
}


static void start_simulation(GtkButton *button, gpointer data)
{
    gtk_widget_set_sensitive(GTK_WIDGET(buttonStartSimulation), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(buttonStopSimulation), TRUE);
    puts("Simulación iniciada..");    
}

static void stop_simulation(GtkButton *button, gpointer data)
{
    gtk_widget_set_sensitive(GTK_WIDGET(buttonStartSimulation), TRUE);
    gtk_widget_set_sensitive(GTK_WIDGET(buttonStopSimulation), FALSE);
    puts("Simulación detenida..");
}

