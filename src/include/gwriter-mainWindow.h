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

// Description: Creates and returns the main Window
// Parameters: none
GtkWidget*
create_mainWindow();

// Description: Creates and returns the menubar of the main Window
// Parameters: none
GtkWidget*
create_mainWindow_menubar();

// Description: Creates and returns the statusbar of the main Window
// Parameters: none
GtkWidget*
create_mainWindow_statusbar();

// Description: Creates and returns the toolbar of the main Window
// Parameters: none
GtkWidget*
create_mainWindow_toolbar();

// Description: sets the properties of the window
// Parameters: the main window Widget
void
set_mainWindow_properties(GtkWidget*);

void
windows_about();

void
windows_adduser();

void
windows_setting();
