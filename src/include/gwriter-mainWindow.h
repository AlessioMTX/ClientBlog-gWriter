#ifndef GWRITER_MAINWINDOW_H
#define GWRITER_MAINWINDOW_H

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
#include <stdio.h>
#include <stdlib.h>

#define GWB_VERSION "0.1.1"
#define GWB_VERSION_STATUS "-Alpha"
#define GWB_UPDATES_URL "http://www.gwriterblog.org/version.php"
#define ICON_ABOUT ICONS_DIR"/gwb_about.png"
#define ICON_SETTINGS ICONS_DIR"/setting.png"
#define ICON_STAR ICONS_DIR"/star.png"
#define ICON_ADDUSER ICONS_DIR"/add-user.png"
#define ICON_FAVICON ICONS_DIR"/favicon.png"
#define ICON_CLOSE ICONS_DIR"/close.png"
#define ICON_UPGRADE ICONS_DIR"/upgrade.png"

GtkWidget*
create_mainWindow();

GtkWidget*
create_mainWindow_menubar();

GtkWidget*
create_mainWindow_statusbar();

GtkWidget*
create_mainWindow_toolbar();

void
create_mainWindow_creditsDialog();

void
create_mainWindow_upgradeDialog();

void
create_mainWindow_connectionDialog();

void
create_mainWindow_settingsDialog();



void
set_mainWindow_properties(GtkWidget*);



void 
destroy_mainWindow_widget(GtkButton*, gpointer);



#endif
