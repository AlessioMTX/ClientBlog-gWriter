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
#include <curl/curl.h>
#include <string.h>

#include "include/memory.h"
#include "include/network.h"

static gsize
write_to_memory(gpointer, gsize, gsize, gpointer);

void
get_fileContents_from_url(gchar* p, const gchar const* url)
{
  CURL *curl_handle;
  MemoryStruct chunk;
 
  chunk.memory = p;  /* will be grown as needed by the realloc above */ 
  chunk.size = 0;    /* no data at this point */ 
 
  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();
  
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_to_memory);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (gpointer)&chunk);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_perform(curl_handle);
  
  curl_easy_cleanup(curl_handle);
  curl_global_cleanup();

}


static gsize
write_to_memory(gpointer ptr, gsize size, gsize nmemb, gpointer data)
{
  gsize realsize = size * nmemb;
  MemoryStruct* mem = (MemoryStruct *)data;
 
  if (mem->memory == NULL) {
    g_error("You have to pass an already allocated gchar*\n");
  }
  mem->memory = g_realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    g_error("not enough memory (realloc returned NULL)\n");
  }
 
  g_memmove(&(mem->memory[mem->size]), ptr, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}
