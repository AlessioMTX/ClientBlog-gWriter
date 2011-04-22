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
#define _GNU_SOURCE
#include <gtk/gtk.h>

#include "include/gwriter-mainWindow.h"

void
create_mainWindow_upgradeDialog()
{

	FILE* checkLatesVersion = NULL;
	char bufferLatesVersion[10];
	char *version = "0.1.1",
		 *cmd = NULL;
	
	GtkWidget *window,
			  *lastVersionMSG = gtk_label_new ("Last Version: "),
		      *lastVersionCheck,
			  *currentVersionMSG = gtk_label_new ("Current Version: "),
			  *currentVersionCheck = gtk_label_new (version),
			  *table = gtk_table_new (8, 10, TRUE),
			  *button = gtk_button_new_with_label ("Close");
			  
	GError *error = NULL;
    asprintf(&cmd, "%s%s", "wget -O /tmp/version.gwb http://www.gwriterblog.org/version.php?current=", version);
    
	system (cmd);
	checkLatesVersion = fopen ("/tmp/version.gwb", "r");
	fgets(bufferLatesVersion, 10, checkLatesVersion);
	remove("/tmp/version.twc");

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW(window), 240, 180);
	gtk_widget_set_size_request (window, 240, 180);
	gtk_window_set_title (GTK_WINDOW(window), "Check Updates");
	gtk_container_set_border_width (GTK_CONTAINER (window), 0);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_icon_from_file (GTK_WINDOW(window), "/usr/share/icons/gwriterblog/upgrade.png", &error);


	lastVersionCheck = gtk_label_new (bufferLatesVersion);
	gtk_table_attach (GTK_TABLE (table), currentVersionMSG, 1, 6, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), currentVersionCheck, 6, 9, 1, 2, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionMSG, 1, 5, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), lastVersionCheck, 6, 9, 3, 4, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	gtk_table_attach (GTK_TABLE (table), button, 1, 9, 5, 7, GTK_FILL | GTK_EXPAND,GTK_FILL | GTK_EXPAND, 0, 0);
	g_signal_connect (G_OBJECT (button), "clicked",  G_CALLBACK (destroy_mainWindow_widget), G_OBJECT (window));

	gtk_container_add (GTK_CONTAINER (window), table);

	g_signal_connect (G_OBJECT (window), "delete_event",  G_CALLBACK (gtk_widget_destroy), NULL);
	gtk_widget_show_all (window);

}
