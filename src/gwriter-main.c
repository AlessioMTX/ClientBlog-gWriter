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
 
// SuBMenu File
  /* Fix Icons Linux
   * gconftool-2 --type boolean --set /desktop/gnome/interface/buttons_have_icons true
   * gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons true
   *  */

#include <gtk/gtk.h>

#include "include/gwriter-mainWindow.h"
#include "include/memory.h"

int main (int argc, char* argv[])
{
  gint DEBUG_nAllocs;
  
  gtk_init (&argc, &argv);

  GtkWidget* window = create_mainWindow();
  
  gtk_widget_show_all (window);
  gtk_main ();
  
  DEBUG_nAllocs = DEBUG_get_nAllocatedObjects();
  
  if(DEBUG_nAllocs != 0)
    g_error("POSSIBLE MEMORY LEAK! %d allocated objects not deallocated!", DEBUG_nAllocs);

  return 0;
}
