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
#include "gwriter.h"

int main (int argc, char* argv[])
{
  gtk_init (&argc, &argv);

  GError* error = NULL;

  GtkWidget* window;
  GtkWidget* menu_bar;
  GtkWidget* layout;
  GtkWidget* notebook;
  GtkWidget* label;
  GtkWidget* button;
  GtkWidget* entry_nick;
  GtkWidget* switch_menu;
  GtkWidget* entry_title;
  GtkWidget* table;
  GtkWidget* icon_menu;
  GtkWidget* toolbar;
  GtkWidget* statusbar;
  GtkWidget* file_menu_obj;
  GtkWidget* file_menu_root;
  GtkWidget* file_menu_items;
  GtkWidget* aiuto_menu_obj;
  GtkWidget* aiuto_menu_root;
  GtkWidget* aiuto_menu_items;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 600);
  gtk_widget_set_size_request (window, 570, 570);
  gtk_window_set_title (GTK_WINDOW (window), "gWriter Blog");
  gtk_container_set_border_width (GTK_CONTAINER (window), 0);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  gtk_window_set_icon_from_file (GTK_WINDOW (window), "/usr/share/icons/gwriterblog/favicon.png", &error);

  g_signal_connect (G_OBJECT (window), "delete_event",
                    G_CALLBACK (gtk_main_quit), NULL);

  file_menu_obj = gtk_menu_new();
  aiuto_menu_obj = gtk_menu_new();

  // SuBMenu File
  /* Fix Icons Linux
   * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
   * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
   *  */
  file_menu_items = gtk_image_menu_item_new_with_label ("New Blog");
  icon_menu = gtk_image_new_from_file ("/usr/share/icons/gwriterblog/add_user.png");

  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
  g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_adduser), NULL);
  gtk_menu_append (GTK_MENU (file_menu_obj), file_menu_items);

  file_menu_items = gtk_image_menu_item_new_with_label ("Setting");
  icon_menu = gtk_image_new_from_file ("/usr/share/icons/gwriterblog/setting.png");

  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
  g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (windows_setting), NULL);
  gtk_menu_append (GTK_MENU (file_menu_obj), file_menu_items);

  file_menu_items = gtk_image_menu_item_new_with_label ("Exit");
  icon_menu = gtk_image_new_from_file ("/usr/share/icons/gwriterblog/close.png");

  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (file_menu_items), icon_menu);
  g_signal_connect (G_OBJECT (file_menu_items), "activate", G_CALLBACK (gtk_main_quit), NULL);
  gtk_menu_append (GTK_MENU (file_menu_obj), file_menu_items);

  file_menu_root = gtk_menu_item_new_with_label ("File");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (file_menu_root), file_menu_obj);


  aiuto_menu_items = gtk_image_menu_item_new_with_label ("Information");
  icon_menu = gtk_image_new_from_file ("/usr/share/icons/gwriterblog/star.png");

  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (aiuto_menu_items), icon_menu);
  g_signal_connect (G_OBJECT (aiuto_menu_items), "activate", G_CALLBACK (windows_about), NULL);
  gtk_menu_append (GTK_MENU (aiuto_menu_obj), aiuto_menu_items);


  aiuto_menu_root = gtk_menu_item_new_with_label ("Help");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (aiuto_menu_root), aiuto_menu_obj);

  layout = gtk_vbox_new (0, 1);
  gtk_container_add (GTK_CONTAINER (window), layout);
  menu_bar = gtk_menu_bar_new();
  gtk_box_pack_start (GTK_BOX (layout), menu_bar, FALSE, FALSE, 0);
  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), file_menu_root);
  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), aiuto_menu_root);


  statusbar = gtk_statusbar_new ();
  gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), TRUE);
  gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "");
  gtk_box_pack_end (GTK_BOX (layout), statusbar, FALSE, FALSE, 0);


  toolbar = gtk_toolbar_new ();
  gtk_box_pack_end (GTK_BOX (layout), toolbar, FALSE, FALSE, 0);
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

  gtk_container_add (GTK_CONTAINER (layout), table);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
