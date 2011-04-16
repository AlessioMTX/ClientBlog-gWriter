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

#include "include/gwriter-switchpage.h"
#include "include/gwriter-menu.h"

// Setting
void windows_setting()
{

  GtkWidget* window;
  GtkWidget* notebook;
  GtkWidget* setting_menu;
  GtkWidget* table;
  GtkWidget* label;
  GtkWidget* entry_nick;
  GtkWidget* button;

  GError* error = NULL;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW (window), 310, 300);
  gtk_widget_set_size_request (window, 310, 300);
  gtk_window_set_title (GTK_WINDOW (window), "Setting");
  gtk_container_set_border_width (GTK_CONTAINER (window), 0);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);


  gtk_window_set_icon_from_file (GTK_WINDOW (window), "/usr/share/icons/gwriterblog/favicon.png", &error);

  notebook = gtk_notebook_new ();
  gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

  setting_menu = gtk_label_new ("Account");

  table = gtk_table_new (7, 10, TRUE);
  label = gtk_label_new ("Blog Da Usare:");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  GList* items_account = NULL;
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
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  GList* items_skin = NULL;
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
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  GList* items_lang = NULL;
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

