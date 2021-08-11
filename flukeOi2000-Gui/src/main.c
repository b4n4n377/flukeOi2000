#include <gtk/gtk.h>

// einfach mal so dazugematscht:
#include "shm.c"
#include "keys.h"

#include <gdk/gdkkeysyms.h>

// global pointers to Gtk structures
GtkWidget *window;
GtkBuilder *builder; // builder object used to connect Glade XML file
GtkWidget *g_label_display;

static gboolean
Update_Display_Label_func(gpointer user_data)
{
    // do something
    // printf("- ticker - \n");
    if (shmpointer)
        gtk_label_set_text(GTK_LABEL(g_label_display), shmpointer->displaytxt);

    return 1; // continue forever
}

void send_key_to_emu(unsigned char key)
{
    printf("KEY: %i\n", key);
    if (shmpointer)
    {
        shmpointer->key = key;
        shmpointer->key_consumed = 0;
    }
}

// main function, commands from the command line can be passed
int main(int argc, char *argv[])
{

    get_shm();

    gtk_init(&argc, &argv); // initialize Gtk

    builder = gtk_builder_new();
    //gtk_builder_add_from_file(builder, "glade/window_main.glade", NULL); // read the Glade XML file
    gtk_builder_add_from_resource(builder,"/flukeOi2000-Gui/window_main.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main")); // cast builder object, window ID in XML to GTK_Widget

    gtk_builder_connect_signals(builder, NULL); // build a table of all event/signal callbacks from the XML file

    // get pointers to the objects in the window
    g_label_display = GTK_WIDGET(gtk_builder_get_object(builder, "label_display")); // get pointer to the label used as display (ID of label id in XML file)

    g_object_unref(builder);

    gtk_widget_show(window);

    g_timeout_add(250, Update_Display_Label_func, 0);

    gtk_main(); // let Gtk watch for events / signals

    detach_shm();

    return EXIT_SUCCESS;
}

// callback fuctions to the Gtk events / signals
void on_window_main_destroy()
{
    gtk_main_quit();
}
void on_button_1_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_1 clicked - Oi!");
    send_key_to_emu(KEY_001);
}
void on_button_2_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_2 clicked - Oi!");
    send_key_to_emu(KEY_002);
}
void on_button_3_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_3 clicked - Oi!");
    send_key_to_emu(KEY_003);
}
void on_button_4_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_4 clicked - Oi!");
    send_key_to_emu(KEY_004);
}
void on_button_5_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_5 clicked - Oi!");
    send_key_to_emu(KEY_005);
}
void on_button_6_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_6 clicked - Oi!");
    send_key_to_emu(KEY_006);
}
void on_button_7_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_7 clicked - Oi!");
    send_key_to_emu(KEY_007);
}
void on_button_8_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_8 clicked - Oi!");
    send_key_to_emu(KEY_008);
}
void on_button_9_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_9 clicked - Oi!");
    send_key_to_emu(KEY_009);
}
void on_button_10_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_10 clicked - Oi!");
    send_key_to_emu(KEY_010);
}
void on_button_11_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_11 clicked - Oi!");
    send_key_to_emu(KEY_011);
}
void on_button_12_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_12 clicked - Oi!");
    send_key_to_emu(KEY_012);
}
void on_button_13_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_13 clicked - Oi!");
    send_key_to_emu(KEY_013);
}
void on_button_14_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_14 clicked - Oi!");
    send_key_to_emu(KEY_014);
}
void on_button_15_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_15 clicked - Oi!");
    send_key_to_emu(KEY_015);
}
void on_button_16_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_16 clicked - Oi!");
    send_key_to_emu(KEY_016);
}
void on_button_17_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_17 clicked - Oi!");
    send_key_to_emu(KEY_017);
}
void on_button_18_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_18 clicked - Oi!");
    send_key_to_emu(KEY_018);
}
void on_button_19_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_19 clicked - Oi!");
    send_key_to_emu(KEY_019);
}
void on_button_20_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_20 clicked - Oi!");
    send_key_to_emu(KEY_020);
}
void on_button_21_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_21 clicked - Oi!");
    send_key_to_emu(KEY_021);
}
void on_button_22_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_22 clicked - Oi!");
    send_key_to_emu(KEY_022);
}
void on_button_23_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_23 clicked - Oi!");
    send_key_to_emu(KEY_023);
}
void on_button_24_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_24 clicked - Oi!");
    send_key_to_emu(KEY_024);
}
void on_button_25_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_25 clicked - Oi!");
    send_key_to_emu(KEY_025);
}
void on_button_26_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_26 clicked - Oi!");
    send_key_to_emu(KEY_026);
}
void on_button_27_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_27 clicked - Oi!");
    send_key_to_emu(KEY_027);
}
void on_button_28_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_28 clicked - Oi!");
    send_key_to_emu(KEY_028);
}
void on_button_29_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_29 clicked - Oi!");
    send_key_to_emu(KEY_029);
}
void on_button_30_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_30 clicked - Oi!");
    send_key_to_emu(KEY_030);
}
void on_button_31_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_31 clicked - Oi!");
    send_key_to_emu(KEY_031);
}
void on_button_32_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_32 clicked - Oi!");
    send_key_to_emu(KEY_032);
}
void on_button_33_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_33 clicked - Oi!");
    send_key_to_emu(KEY_033);
}
void on_button_34_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_34 clicked - Oi!");
    send_key_to_emu(KEY_034);
}
void on_button_35_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_35 clicked - Oi!");
    send_key_to_emu(KEY_035);
}
void on_button_36_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_36 clicked - Oi!");
    send_key_to_emu(KEY_036);
}
void on_button_37_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_37 clicked - Oi!");
    send_key_to_emu(KEY_037);
}
void on_button_38_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_38 clicked - Oi!");
    send_key_to_emu(KEY_038);
}
void on_button_39_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_39 clicked - Oi!");
    send_key_to_emu(KEY_039);
}
void on_button_40_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_40 clicked - Oi!");
    send_key_to_emu(KEY_040);
}
void on_button_41_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_41 clicked - Oi!");
    send_key_to_emu(KEY_041);
}
void on_button_42_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_42 clicked - Oi!");
    send_key_to_emu(KEY_042);
}
void on_button_43_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_43 clicked - Oi!");
    send_key_to_emu(KEY_043);
}
void on_button_44_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_44 clicked - Oi!");
    send_key_to_emu(KEY_044);
}
void on_button_45_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_45 clicked - Oi!");
    send_key_to_emu(KEY_045);
}
void on_button_46_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_46 clicked - Oi!");
    send_key_to_emu(KEY_046);
}
void on_button_47_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_47 clicked - Oi!");
    send_key_to_emu(KEY_047);
}
void on_button_48_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_48 clicked - Oi!");
    send_key_to_emu(KEY_048);
}
void on_button_49_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_49 clicked - Oi!");
    send_key_to_emu(KEY_049);
}
void on_button_50_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_50 clicked - Oi!");
    send_key_to_emu(KEY_050);
}
void on_button_51_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_51 clicked - Oi!");
    send_key_to_emu(KEY_051);
}
void on_button_52_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_52 clicked - Oi!");
    send_key_to_emu(KEY_052);
}
void on_button_53_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_53 clicked - Oi!");
    send_key_to_emu(KEY_053);
}
void on_button_54_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_54 clicked - Oi!");
    send_key_to_emu(KEY_054);
}
void on_button_55_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_55 clicked - Oi!");
    send_key_to_emu(KEY_055);
}
void on_button_56_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_56 clicked - Oi!");
    send_key_to_emu(KEY_056);
}
void on_button_57_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_57 clicked - Oi!");
    send_key_to_emu(KEY_057);
}
void on_button_58_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_58 clicked - Oi!");
    send_key_to_emu(KEY_058);
}
void on_button_59_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_59 clicked - Oi!");
    send_key_to_emu(KEY_059);
}
void on_button_60_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_60 clicked - Oi!");
    send_key_to_emu(KEY_060);
}
void on_button_61_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_61 clicked - Oi!");
    send_key_to_emu(KEY_061);
}
void on_button_62_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_62 clicked - Oi!");
    send_key_to_emu(KEY_062);
}
void on_button_63_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_63 clicked - Oi!");
    send_key_to_emu(KEY_063);
}
void on_button_64_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_64 clicked - Oi!");
    send_key_to_emu(KEY_064);
}
void on_button_65_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_65 clicked - Oi!");
    send_key_to_emu(KEY_065);
}
void on_button_66_clicked()
{
    //gtk_label_set_text(GTK_LABEL(g_label_display), "button_66 clicked - Oi!");
    send_key_to_emu(KEY_066);
}

void on_window_main_key_press_event(GtkWidget *widget, GdkEventKey *key, gpointer user_data)
{
    // key pressed ?
    switch (key->keyval)
    {
    // insert ##################################################################
    case GDK_KEY_Insert:
        if (key->state & GDK_CONTROL_MASK) // ctrl + insert  = LEARN, KEY_001
        {
            send_key_to_emu(KEY_001);
        }
        else if (key->state & GDK_MOD1_MASK) // alt + insert  = AUTO, KEY_003
        {
            send_key_to_emu(KEY_003);
        }
        break;

    // delete ##################################################################
    case GDK_KEY_Delete:
        if (key->state & GDK_CONTROL_MASK) // ctrl + delete = RAM, KEY_002
        {
            send_key_to_emu(KEY_002);
        }
        else if (key->state & GDK_MOD1_MASK) // alt + delete = BUS, KEY_004
        {
            send_key_to_emu(KEY_004);
        }
        break;

    // home #####################################################################
    case GDK_KEY_Home:
        if (key->state & GDK_CONTROL_MASK) // ctrl + home = I/O, KEY_006
        {
            send_key_to_emu(KEY_006);
        }
        else if (key->state & GDK_MOD1_MASK) // alt + home = RAM LONG, KEY_008
        {
            send_key_to_emu(KEY_008);
        }
        break;

    // end #####################################################################
    case GDK_KEY_End:
        if (key->state & GDK_CONTROL_MASK) // ctrl + end = ROM, KEY_007
        {
            send_key_to_emu(KEY_007);
        }
        else if (key->state & GDK_MOD1_MASK) // alt + end = RAM SHORT, KEY_009
        {
            send_key_to_emu(KEY_009);
        }
        break;

    // page up #####################################################################
    case GDK_KEY_Page_Up:
        if (key->state & GDK_MOD1_MASK) // alt + page up = ROM, KEY_005
        {
            send_key_to_emu(KEY_005);
        }
        break;

    // page down #####################################################################
    case GDK_KEY_Page_Down:
        if (key->state & GDK_MOD1_MASK) // alt + page down = I/O, KEY_010
        {
            send_key_to_emu(KEY_010);
        }
        break;

    // a #####################################################################
    case GDK_KEY_A:
        send_key_to_emu(KEY_022);
        break;

    // b #####################################################################
    case GDK_KEY_B:
        send_key_to_emu(KEY_028);
        break;

    // c #####################################################################
    case GDK_KEY_C:
        send_key_to_emu(KEY_011);
        break;

    // d #####################################################################
    case GDK_KEY_D:
        send_key_to_emu(KEY_016);
        break;

    // e #####################################################################
    case GDK_KEY_E:
        send_key_to_emu(KEY_021);
        break;

    // f #####################################################################
    case GDK_KEY_F:
        send_key_to_emu(KEY_027);
        break;

    // 9 #####################################################################
    case GDK_KEY_9:
        send_key_to_emu(KEY_017);
        break;

    // 8 #####################################################################
    case GDK_KEY_8:
        send_key_to_emu(KEY_012);
        break;

    // 7 #####################################################################
    case GDK_KEY_7:
        send_key_to_emu(KEY_029);
        break;

    // 6 #####################################################################
    case GDK_KEY_6:
        send_key_to_emu(KEY_023);
        break;

    // 5 #####################################################################
    case GDK_KEY_5:
        send_key_to_emu(KEY_018);
        break;

    // 4 #####################################################################
    case GDK_KEY_4:
        send_key_to_emu(KEY_013);
        break;

    // 3 #####################################################################
    case GDK_KEY_3:
        send_key_to_emu(KEY_030);
        break;

    // 2 #####################################################################
    case GDK_KEY_2:
        send_key_to_emu(KEY_024);
        break;

    // 1 #####################################################################
    case GDK_KEY_1:
        send_key_to_emu(KEY_019);
        break;

    // 0 #####################################################################
    case GDK_KEY_0:
        send_key_to_emu(KEY_014);
        break;
    }
}