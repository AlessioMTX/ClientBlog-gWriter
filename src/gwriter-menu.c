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

#include "include/gwriter-menu.h"

GtkWidget*
create_menu_item(GtkWidget* menu, const gchar const* title, const gchar const* imagePath  )
{
  GtkWidget* item = gtk_image_menu_item_new_with_label(title);
  GtkWidget* image = gtk_image_new_from_file (imagePath);
  
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item), image);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
  
  return item;
}


GtkWidget*
create_menu(GtkWidget* menuBar, const gchar const* name)
{
  GtkWidget* menu = gtk_menu_new();
  GtkWidget* item = gtk_menu_item_new_with_label(name);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), item);
  
  return menu;
}

