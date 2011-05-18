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
 
#include <gtk/gtk.h>

#include "include/gwriter-mainWindow.h"
#include "include/gwriter-menu.h"
#include "include/gwriter-updateWindow.h"
#include "include/gwriter-images.h"


static void
set_properties(GtkWidget*);

static GtkWidget*
create_menubar();

static void
create_creditsDialog();

static GtkWidget*
create_statusbar();

static GtkWidget*
create_toolbar();

GtkWidget*
create_mainWindow()
{
  GtkWidget* vBox = gtk_vbox_new(0, 1);;
  GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  GtkWidget* menubar;
  GtkWidget* statusbar;
  GtkWidget* toolbar;

  

  gtk_container_add(GTK_CONTAINER(window), vBox);
  
  set_properties(window);
  
  menubar = create_menubar();
  gtk_box_pack_start (GTK_BOX (vBox), menubar, FALSE, FALSE, 0);
  
  statusbar = create_statusbar();
  gtk_box_pack_end (GTK_BOX (vBox), statusbar, FALSE, FALSE, 0);
  
  toolbar = create_toolbar();
  gtk_box_pack_end (GTK_BOX (vBox), toolbar, FALSE, FALSE, 0);
 
  return window;
}

static void
set_properties(GtkWidget* window)
{
  GError* error = NULL;
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 600);
  gtk_widget_set_size_request (window, 570, 570);
  gtk_window_set_title (GTK_WINDOW (window), "gWriter Blog");
  gtk_container_set_border_width (GTK_CONTAINER (window), 0);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  gtk_window_set_icon_from_file (GTK_WINDOW (window), ICON_FAVICON, &error);

  g_signal_connect (window, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
}

static GtkWidget*
create_menubar()
{
  GtkWidget* menubar = gtk_menu_bar_new();
  GtkWidget* menu;
  GtkWidget* item;
  
  menu = create_menu(menubar, "File");
  item = create_menu_item(menu, "New Blog", ICON_ADDUSER);
  
  item = create_menu_item(menu, "Settings", ICON_ADDUSER);
  
  item = create_menu_item(menu, "Exit", ICON_CLOSE);
  g_signal_connect (G_OBJECT (item), "activate",
                                     G_CALLBACK (gtk_main_quit),
                                     NULL);
  
  menu = create_menu(menubar, "Help");
  item = create_menu_item(menu, "Updates", ICON_UPGRADE);
  g_signal_connect (G_OBJECT (item), "activate",
                                     G_CALLBACK (create_updateWindow),
                                     NULL);
  
  item = create_menu_item(menu, "Info", ICON_STAR);
  g_signal_connect (G_OBJECT (item), "activate",
                                     G_CALLBACK (create_creditsDialog),
                                     NULL);
  
  return menubar;
}

static GtkWidget*
create_statusbar()
{
  GtkWidget* statusbar = gtk_statusbar_new ();
  
  gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (statusbar), TRUE);
  gtk_statusbar_push (GTK_STATUSBAR (statusbar), 0, "");
  
  return statusbar;
}

static GtkWidget*
create_toolbar()
{
  GtkWidget* toolbar = gtk_toolbar_new ();
 
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_ICONS);
  
  return toolbar;
}

static void
create_creditsDialog()
{
  GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file ("/usr/share/icons/gwriterblog/gwb_about.png", NULL);
  GtkWidget* dialog = gtk_about_dialog_new();

  GError* error = NULL;

  gtk_window_set_icon_from_file (GTK_WINDOW (dialog), ICON_FAVICON, &error);

  gtk_about_dialog_set_name (GTK_ABOUT_DIALOG (dialog), "gWriter Blog");
  gtk_about_dialog_set_version (GTK_ABOUT_DIALOG (dialog), "");
  gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG (dialog), "(c) PTKDev, Gaudo");
  gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG (dialog), "Basato su librerie GTK e semplicità!\n\nVersion: 0.1.1");
  gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog), "http://www.gwriterblog.org/");

  gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG (dialog), pixbuf);
  g_object_unref (pixbuf), pixbuf = NULL;

  gtk_dialog_run (GTK_DIALOG (dialog) );
  gtk_widget_destroy (dialog);

}



