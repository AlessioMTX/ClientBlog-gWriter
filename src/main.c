/* 
*	gWriterBlog - Blog Editor For Linux Desktop
*		Copyright (C) 2011  PTKDev
*
*		This program is free software: you can redistribute it and/or modify
*		it under the terms of the GNU General Public License as published by
*		the Free Software Foundation, either version 3 of the License, or
*		(at your option) any later version.
*
*		This program is distributed in the hope that it will be useful,
*		but WITHOUT ANY WARRANTY; without even the implied warranty of
*		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*		GNU General Public License for more details.
*
*		You should have received a copy of the GNU General Public License
*		along with this program.  If not, see <http://www.gnu.org/licenses/>.
*		
*			
*		Author: Patryk Rzucidlo (PTKDev)
*		Twitter: @ptkdev / @gwriterblog_en
*		WebSite: http://www.gwriterblog.org
*/


#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>

#include "include/gwriter.h"
#include "include/gwriter_mainWindow.h"
#include "include/gwriter_menuBar.h"

int main (int argc, char* argv[])
{
  gtk_init (&argc, &argv);

  GError* error = NULL;

  GtkWidget* window;
  GtkWidget* notebook;
  GtkWidget* label;
  GtkWidget* button;
  GtkWidget* entry_nick;
  GtkWidget* switch_menu;
  GtkWidget* entry_title;
  GtkWidget* table;
  GtkWidget* toolbar;
  GtkWidget* statusbar;
  GtkWidget* menuBar;
  GtkWidget* vBox;
  
    // SuBMenu File
  /* Fix Icons Linux
   * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
   * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
   *  */
  
  window = create_main_window();
  
  vBox = gtk_vbox_new(0, 1);
  gtk_container_add(GTK_CONTAINER(window), vBox);
  
  menuBar = create_menu_bar(window);
  gtk_box_pack_start (GTK_BOX (vBox), menuBar, FALSE, FALSE, 0);
  
  statusbar = gtk_statusbar_new ();
  gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), TRUE);
  gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "");
  gtk_box_pack_end (GTK_BOX (vBox), statusbar, FALSE, FALSE, 0);


  toolbar = gtk_toolbar_new ();
  gtk_box_pack_end (GTK_BOX (vBox), toolbar, FALSE, FALSE, 0);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);

  table = gtk_table_new (23, 15, TRUE);

  notebook = gtk_notebook_new ();
  gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_TOP);

  label = gtk_label_new ("Titolo Post:");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
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
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  entry_title = gtk_entry_new ();
  gtk_entry_set_text (GTK_ENTRY (entry_title), "");

  gtk_table_attach (GTK_TABLE (table), label, 1, 2,
                    17, 18, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);
  gtk_table_attach (GTK_TABLE (table), entry_title, 1, 14,
                    18, 19, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);

  label = gtk_label_new ("Categorie:");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  GList* items_account = NULL;
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

  gtk_container_add (GTK_CONTAINER (vBox), table);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
