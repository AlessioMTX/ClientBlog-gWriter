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

#include "include/memory-management.h"
#include "include/memory-debug.h"

gpointer
malloc_space(gsize s)
{
  gpointer p;
  
  p = g_malloc(s);
  
  N_LEAKED_ALLOCS++;
  
  return p;
}

void
mdealloc_space(gpointer* p)
{
  if(N_LEAKED_ALLOCS == 0)
    g_error("Error: Deallocating before allocating");
  
  if (p != NULL && *p != NULL) {  // safety check 
    g_free(*p);                    // deallocate chunk 
    *p = NULL;                   // reset original pointer 
    N_LEAKED_ALLOCS--;                   
  }

}
