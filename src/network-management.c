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

#include "include/memory-management.h"
#include "include/network-management.h"

gchar*
get_fileContent_from_url(const gchar const* url)
{
  CURL* curl_handle = NULL;
  MemoryStruct chunk;
 
  chunk.memory = malloc_space(1);  // will be grown as needed by the realloc
  chunk.size = 0;
  
  curl_handle = curl_easy_init();
  
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_to_memory);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (gpointer)&chunk);
  
  // some servers don't like requests that are made without a user-agentfield, so we provide one
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  curl_easy_perform(curl_handle);
  
  curl_easy_cleanup(curl_handle);
   
  return chunk.memory;
}


static gsize
write_to_memory(gpointer ptr, gsize size, gsize nmemb, gpointer data)
{
  gsize realsize = size * nmemb;
  MemoryStruct *mem = (MemoryStruct *)data;

  mem->memory = g_realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    g_error("not enough memory (realloc returned NULL)\n");
  }

  memcpy(&(mem->memory[mem->size]), ptr, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}
