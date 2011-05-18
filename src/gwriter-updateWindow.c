/* 
 *	gWriterBlog - Blog Editor For Linux Desktop
 *		Copyright (C) 2011  PTKDev, Gaudo, RoxShannon
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
 * 		IRC: chat.freenode.net at #teamgwb
 */
 
#define _GNU_SOURCE
#include <gtk/gtk.h>

#include "include/gwriter-updateWindow.h"
#include "include/gwriter-version.h"
#include "include/memory.h"

static void
set_properties(GtkWidget*);

void
create_updateWindow()
{
  
  GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  GtkWidget* table  = gtk_table_new (8, 10, TRUE);
  GtkWidget* closeButton = gtk_button_new_with_label ("Close");
  
  gchar* latestVersionString = NULL;
  
  set_properties(window);

  gtk_table_attach (GTK_TABLE (table),
                    gtk_label_new ("Current Version: "),
                    1, 6, 1, 2,
                    GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND,
                    0, 0);
                    
  gtk_table_attach (GTK_TABLE (table),
                    gtk_label_new (CURRENT_VERSION),
                    6, 9, 1, 2,
                    GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND,
                    0, 0);
                
  gtk_table_attach (GTK_TABLE (table),
                    gtk_label_new ("Latest Version: "),
                    1, 5, 3, 4,
                    GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND,
                    0, 0);
  
  
  latestVersionString = alloc(1);
  get_latestVersion(latestVersionString);

  gtk_table_attach (GTK_TABLE (table),
                    gtk_label_new (latestVersionString),
                    6, 9, 3, 4,
                    GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND,
                    0, 0);
  dealloc((gpointer*)&latestVersionString);
                    
  gtk_table_attach (GTK_TABLE (table),
                    closeButton,
                    1, 9, 5, 7,
                    GTK_FILL | GTK_EXPAND,
                    GTK_FILL | GTK_EXPAND,
                    0, 0);
                    
  g_signal_connect (G_OBJECT (closeButton),
                    "clicked",
                    G_CALLBACK (gtk_widget_destroy),
                    GTK_WIDGET(window));

  gtk_container_add (GTK_CONTAINER (window), table);

  g_signal_connect (G_OBJECT (window),
                    "delete_event",
                    G_CALLBACK (gtk_widget_destroy),
                    window);
                  
  gtk_widget_show_all (window);

}

static void
set_properties(GtkWidget* window)
{
	gtk_window_set_default_size (GTK_WINDOW(window), 240, 180);
	gtk_widget_set_size_request (window, 240, 180);
	gtk_window_set_title (GTK_WINDOW(window), "Check Updates");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

}
