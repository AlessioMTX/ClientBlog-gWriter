#pragma once
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

GtkWidget*
create_mainWindow();

static GtkWidget*
create_mainWindow_menubar();

static GtkWidget*
create_statusbar();

static GtkWidget*
create_toolbar();

static void
create_creditsDialog();


static void
set_properties(GtkWidget*);


#endif
