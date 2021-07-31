#include <gtk/gtk.h>


// global pointers to Gtk structures
GtkWidget       *window;                
GtkBuilder      *builder;               // builder object used to connect Glade XML file 
GtkWidget       *g_label_display;

// main function, commands from the command line can be passed
int main(int argc, char *argv[])    
{
    gtk_init(&argc, &argv);         // initialize Gtk

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);   // read the Glade XML file

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));  // cast builder object, window ID in XML to GTK_Widget 

    gtk_builder_connect_signals(builder, NULL); // build a table of all event/signal callbacks from the XML file
    
    // get pointers to the objects in the window
    g_label_display = GTK_WIDGET(gtk_builder_get_object(builder, "label_display")); // get pointer to the label used as display (ID of label id in XML file)

    g_object_unref(builder);

    gtk_widget_show(window);

    gtk_main(); // let Gtk watch for events / signals

    return  EXIT_SUCCESS;
}

// callback fuctions to the Gtk events / signals
void on_window_main_destroy()
{
    gtk_main_quit();
}
void on_button_1_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_1 clicked - Oi!");  
}
void on_button_2_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_2 clicked - Oi!");  
}
void on_button_3_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_3 clicked - Oi!");  
}
void on_button_4_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_4 clicked - Oi!");  
}
void on_button_5_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_5 clicked - Oi!");  
}
void on_button_6_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_6 clicked - Oi!");  
}
void on_button_7_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_7 clicked - Oi!");  
}
void on_button_8_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_8 clicked - Oi!");  
}
void on_button_9_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_9 clicked - Oi!");  
}
void on_button_10_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_10 clicked - Oi!");  
}
void on_button_11_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_11 clicked - Oi!");  
}
void on_button_12_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_12 clicked - Oi!");  
}
void on_button_13_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_13 clicked - Oi!");  
}
void on_button_14_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_14 clicked - Oi!");  
}
void on_button_15_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_15 clicked - Oi!");  
}
void on_button_16_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_16 clicked - Oi!");  
}
void on_button_17_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_17 clicked - Oi!");  
}
void on_button_18_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_18 clicked - Oi!");  
}
void on_button_19_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_19 clicked - Oi!");  
}
void on_button_20_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_20 clicked - Oi!");  
}
void on_button_21_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_21 clicked - Oi!");  
}
void on_button_22_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_22 clicked - Oi!");  
}
void on_button_23_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_23 clicked - Oi!");  
}
void on_button_24_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_24 clicked - Oi!");  
}
void on_button_25_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_25 clicked - Oi!");  
}
void on_button_26_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_26 clicked - Oi!");  
}
void on_button_27_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_27 clicked - Oi!");  
}
void on_button_28_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_28 clicked - Oi!");  
}
void on_button_29_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_29 clicked - Oi!");  
}
void on_button_30_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_30 clicked - Oi!");  
}
void on_button_31_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_31 clicked - Oi!");  
}
void on_button_32_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_32 clicked - Oi!");  
}
void on_button_33_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_33 clicked - Oi!");  
}
void on_button_34_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_34 clicked - Oi!");  
}
void on_button_35_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_35 clicked - Oi!");  
}
void on_button_36_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_36 clicked - Oi!");  
}
void on_button_37_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_37 clicked - Oi!");  
}
void on_button_38_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_38 clicked - Oi!");  
}
void on_button_39_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_39 clicked - Oi!");  
}
void on_button_40_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_40 clicked - Oi!");  
}
void on_button_41_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_41 clicked - Oi!");  
}
void on_button_42_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_42 clicked - Oi!");  
}
void on_button_43_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_43 clicked - Oi!");  
}
void on_button_44_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_44 clicked - Oi!");  
}
void on_button_45_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_45 clicked - Oi!");  
}
void on_button_46_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_46 clicked - Oi!");  
}
void on_button_47_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_47 clicked - Oi!");  
}
void on_button_48_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_48 clicked - Oi!");  
}
void on_button_49_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_49 clicked - Oi!");  
}
void on_button_50_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_50 clicked - Oi!");  
}
void on_button_51_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_51 clicked - Oi!");  
}
void on_button_52_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_52 clicked - Oi!");  
}
void on_button_53_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_53 clicked - Oi!");  
}
void on_button_54_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_54 clicked - Oi!");  
}
void on_button_55_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_55 clicked - Oi!");  
}
void on_button_56_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_56 clicked - Oi!");  
}
void on_button_57_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_57 clicked - Oi!");  
}
void on_button_58_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_58 clicked - Oi!");  
}
void on_button_59_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_59 clicked - Oi!");  
}
void on_button_60_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_60 clicked - Oi!");  
}
void on_button_61_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_61 clicked - Oi!");  
}
void on_button_62_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_62 clicked - Oi!");  
}
void on_button_63_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_63 clicked - Oi!");  
}
void on_button_64_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_64 clicked - Oi!");  
}
void on_button_65_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_65 clicked - Oi!");  
}
void on_button_66_clicked()
{ 
    gtk_label_set_text(GTK_LABEL(g_label_display), "button_66 clicked - Oi!");  
}