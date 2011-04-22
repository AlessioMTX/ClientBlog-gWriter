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

#include "include/gwriter-mainWindow.h"

// Add User
void
create_mainWindow_connectionDialog()
{
  //Inizializzazioni
  GtkWidget* window;
  GtkWidget* table;
  GtkWidget* label;
  GtkWidget* entry_api;
  GtkWidget* button;

  GError* error = NULL;

  // Dichiaro finestra
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW (window), 310, 350);
  gtk_widget_set_size_request (window, 310, 350);
  gtk_window_set_title (GTK_WINDOW (window), "New Blog");
  gtk_container_set_border_width (GTK_CONTAINER (window), 0);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  // Dichiaro finestra: favicon
  gtk_window_set_icon_from_file (GTK_WINDOW (window), ICON_FAVICON, &error);

  // Dichiaro autenticazione
  table = gtk_table_new (11, 10, TRUE);
  gtk_container_add (GTK_CONTAINER (window), table);

  label = gtk_label_new ("Provider");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  GList* items_blog = NULL;
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
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  entry_api = gtk_entry_new ();
  gtk_entry_set_text (GTK_ENTRY (entry_api), "");

  gtk_table_attach (GTK_TABLE (table), label, 1, 9,
                    2, 3, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);
  gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
                    3, 4, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);

  label = gtk_label_new ("NickName:");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
  entry_api = gtk_entry_new ();
  gtk_entry_set_text (GTK_ENTRY (entry_api), "");

  gtk_table_attach (GTK_TABLE (table), label, 1, 9,
                    4, 5, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);
  gtk_table_attach (GTK_TABLE (table), entry_api, 1, 9,
                    5, 6, GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND, 0, 0);

  label = gtk_label_new ("Password:");
  gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_LEFT);
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
