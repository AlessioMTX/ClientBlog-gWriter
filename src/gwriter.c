#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>

GdkPixbuf* import_img(char* filename) 
{
      GdkPixbuf* tempbuffer=NULL;
      char temp[200];
      if (filename) 
      {
            sprintf(temp,"%s", filename);
            tempbuffer= gdk_pixbuf_new_from_file(temp,NULL);
            return tempbuffer;
      }
      else return NULL;

}

void windows_about()
{
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("/usr/share/icons/gwriterblog/gwb_about.png", NULL);
	GtkWidget *dialog = gtk_about_dialog_new();
	GError *error = NULL;
	
	gtk_window_set_icon_from_file (GTK_WINDOW(dialog), "/usr/share/icons/gwriterblog/favicon.png", &error);
	
	gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "gWriter Blog");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), ""); 
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) PTKDev, Gaudo and RoxShannon");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Basato su librerie GTK e semplicità!\n\nVersion: 0.1.1");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://www.gwriterblog.org/");
	
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
	g_object_unref(pixbuf), pixbuf = NULL;
	
	gtk_dialog_run(GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);

}

static void switch_page (GtkButton *button, GtkNotebook *notebook)
{
	if (gtk_notebook_get_current_page (notebook) == 0)
	{
		gtk_notebook_set_current_page (notebook, 1);
	}else{
		gtk_notebook_set_current_page (notebook, 0);
	}
}

// Add User
void windows_adduser()
{
	//Inizializzazioni
	GtkWidget *window, *table, *label, *entry_api, *button;
	GError *error = NULL;
	
	// Dichiaro finestra
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 350);
	gtk_widget_set_size_request (window, 310, 350);
	gtk_window_set_title (GTK_WINDOW(window), "New Blog");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	// Dichiaro finestra: favicon
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "/usr/share/icons/gwriterblog/favicon.png", &error);

	// Dichiaro autenticazione
	 table = gtk_table_new (11, 10, TRUE);
	 gtk_container_add (GTK_CONTAINER (window), table);
	 
	label = gtk_label_new ("Provider");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_blog = NULL;
	items_blog = g_list_append (items_blog, "Wordpress");
	entry_api = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_api), items_blog);
                                  
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					0, 1, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
					1, 2, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	 
	 label = gtk_label_new ("Url Blog:");
	 gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	 entry_api = gtk_entry_new ();
	 gtk_entry_set_text (GTK_ENTRY (entry_api), "");
	 
	 gtk_table_attach (GTK_TABLE (table), label, 1, 9,
						2, 3, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	 gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
						3, 4, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
						 
	 label = gtk_label_new ("NickName:");
	 gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	 entry_api = gtk_entry_new ();
	 gtk_entry_set_text (GTK_ENTRY (entry_api), "");
	 
	 gtk_table_attach (GTK_TABLE (table), label, 1, 9,
						4, 5, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	 gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
						5, 6, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);	 
						 
	 label = gtk_label_new ("Password:");
	 gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	 entry_api = gtk_entry_new ();
	 gtk_entry_set_text (GTK_ENTRY (entry_api), "");
	 
	 gtk_table_attach (GTK_TABLE (table), label, 1, 9,
						6, 7, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	 gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
						7, 8, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
						 
	
	 button = gtk_button_new_with_label ("SALVA");
	 gtk_table_attach (GTK_TABLE (table), button, 1, 9,
						9, 10, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	
	gtk_container_add (GTK_CONTAINER (window), table);
		 
	//Eventi Di Chiusura
	g_signal_connect (G_OBJECT (window), "delete_event", FALSE, NULL);
	gtk_widget_show_all (window);

}

// Setting
void windows_setting()
{

	GtkWidget *window, *notebook, *setting_menu, *table, *label, *entry_nick,*button;
	GError *error = NULL;
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 310, 300);
	gtk_widget_set_size_request (window, 310, 300);
	gtk_window_set_title (GTK_WINDOW(window), "Setting");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	

	gtk_window_set_icon_from_file (GTK_WINDOW(window), "/usr/share/icons/gwriterblog/favicon.png", &error);
	
	notebook = gtk_notebook_new ();
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

	setting_menu = gtk_label_new ("Account");	

	table = gtk_table_new (7, 10, TRUE);
	label = gtk_label_new ("Blog Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_account = NULL;
	items_account = g_list_append (items_account, "http://www.sito1.it");
	items_account = g_list_append (items_account, "http://www.sito2.it");
	items_account = g_list_append (items_account, "http://www.sito3.it");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_account);
                                  
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					0, 1, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
					1, 2, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
				 
	 button = gtk_button_new_with_label ("SALVA");
	 gtk_table_attach (GTK_TABLE (table), button, 1, 9,
						5, 6, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	
	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);
	

	setting_menu = gtk_label_new ("Aspetto");	

	table = gtk_table_new (7, 10, TRUE);
	label = gtk_label_new ("Tema Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_skin = NULL;
	items_skin = g_list_append (items_skin, "default");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_skin);
                                  
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					0, 1, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
					1, 2, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	label = gtk_label_new ("Lingua Da Usare:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_lang = NULL;
	items_lang = g_list_append (items_lang, "italian");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_lang);
                                  
	gtk_table_attach (GTK_TABLE (table), label, 1, 9,
					2, 3, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 9,
					3, 4, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	 button = gtk_button_new_with_label ("SALVA");
	 gtk_table_attach (GTK_TABLE (table), button, 1, 9,
						5, 6, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	
	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), table, setting_menu);
	
	gtk_container_add (GTK_CONTAINER (window), notebook);

	g_signal_connect (G_OBJECT (window), "delete_event", FALSE, NULL);
	gtk_widget_show_all (window);

}

int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);
		
	GError *error = NULL;
	GdkPixbuf *icon_menu;
	GtkWidget *window,*menu_bar,*layout, *notebook,*label,*button,*entry_nick, *switch_menu,*entry_title,*table,*menuImage,*toolbar,*statusbar,*file_menu_obj,*file_menu_root,*file_menu_items,*aiuto_menu_obj,*aiuto_menu_root,*aiuto_menu_items;

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 600, 600);
	gtk_widget_set_size_request (window, 570, 570);
	gtk_window_set_title (GTK_WINDOW(window), "gWriter Blog");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "/usr/share/icons/gwriterblog/favicon.png", &error);
	
	g_signal_connect (G_OBJECT (window), "delete_event",
					  G_CALLBACK (gtk_main_quit), NULL);
					  
	file_menu_obj = gtk_menu_new();
	aiuto_menu_obj = gtk_menu_new();
	
	// SuBMenu File
	/* Fix Icons Linux
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
	 * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
	 *  */
	file_menu_items = gtk_image_menu_item_new_with_label("New Blog");   
    icon_menu = import_img("/usr/share/icons/gwriterblog/add_user.png");
	menuImage = gtk_image_new_from_pixbuf (icon_menu);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), menuImage);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_adduser), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_items = gtk_image_menu_item_new_with_label("Setting");   
    icon_menu = import_img("/usr/share/icons/gwriterblog/setting.png");
	menuImage = gtk_image_new_from_pixbuf (icon_menu);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), menuImage);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_setting), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_items = gtk_image_menu_item_new_with_label("Exit");
    icon_menu = import_img("/usr/share/icons/gwriterblog/close.png");
	menuImage = gtk_image_new_from_pixbuf (icon_menu);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), menuImage);
	g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtk_main_quit), NULL);
    gtk_menu_append(GTK_MENU (file_menu_obj), file_menu_items);
    
    file_menu_root = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (file_menu_root), file_menu_obj);
    

    aiuto_menu_items = gtk_image_menu_item_new_with_label("Information");
    icon_menu = import_img("/usr/share/icons/gwriterblog/star.png");
	menuImage = gtk_image_new_from_pixbuf (icon_menu);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (aiuto_menu_items), menuImage);
	g_signal_connect (G_OBJECT (aiuto_menu_items), "activate", G_CALLBACK (windows_about), NULL);
    gtk_menu_append(GTK_MENU (aiuto_menu_obj), aiuto_menu_items);
    
    
    aiuto_menu_root = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (aiuto_menu_root), aiuto_menu_obj);

    layout = gtk_vbox_new(0, 1);
    gtk_container_add(GTK_CONTAINER(window), layout);
    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(layout), menu_bar, FALSE, FALSE, 0);
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), file_menu_root);
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), aiuto_menu_root);    
    

    statusbar = gtk_statusbar_new ();
    gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR(statusbar), TRUE);
    gtk_statusbar_push (GTK_STATUSBAR(statusbar), 0, "");
    gtk_box_pack_end (GTK_BOX (layout), statusbar, FALSE, FALSE, 0);
    

	toolbar = gtk_toolbar_new ();
	gtk_box_pack_end (GTK_BOX (layout), toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
	
	table = gtk_table_new (23, 15, TRUE);
					 
	notebook = gtk_notebook_new ();
	gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_TOP);

	label = gtk_label_new ("Titolo Post:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	entry_title = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (entry_title), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 3,
					0, 1, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_title, 1, 14,
					1, 2, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	

	switch_menu = gtk_label_new ("WYSIWYG");	
	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), switch_menu, switch_menu);
    
    switch_menu = gtk_label_new ("HTML");	
	g_signal_connect (G_OBJECT (table), "clicked", G_CALLBACK (switch_page), notebook);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), switch_menu, switch_menu);    
	
	gtk_table_attach (GTK_TABLE (table), notebook, 0, 15,
					3, 17, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
				
	label = gtk_label_new ("Tags:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	entry_title = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (entry_title), "");

	gtk_table_attach (GTK_TABLE (table), label, 1, 2,
					17, 18, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_title, 1, 14,
					18, 19, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
	label = gtk_label_new ("Categorie:");
	gtk_label_set_justify(GTK_LABEL (label),GTK_JUSTIFY_LEFT);
	GList *items_account = NULL;
	items_account = g_list_append (items_account, "Cat1");
	items_account = g_list_append (items_account, "Cat2");
	items_account = g_list_append (items_account, "Cat3");
	entry_nick = gtk_combo_new ();
	gtk_combo_set_popdown_strings (GTK_COMBO (entry_nick), items_account);
                                  
	gtk_table_attach (GTK_TABLE (table), label, 1, 8,
					20, 21, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), entry_nick, 1, 8,
					21, 22, GTK_FILL | GTK_EXPAND,
					 GTK_FILL | GTK_EXPAND, 0, 0);
					 
					 
	button = gtk_button_new_with_label ("BOZZA");
	gtk_table_attach (GTK_TABLE (table), button, 9, 11,
						20, 22, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
						 
	button = gtk_button_new_with_label ("PUBBLICA");
	gtk_table_attach (GTK_TABLE (table), button, 11, 14,
						20, 22, GTK_FILL | GTK_EXPAND,
						 GTK_FILL | GTK_EXPAND, 0, 0);
	
	gtk_container_add(GTK_CONTAINER(layout), table);
    
	gtk_widget_show_all (window);	
	gtk_main ();

 return 0;
}
