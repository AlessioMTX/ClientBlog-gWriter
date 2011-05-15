bin_PROGRAMS = gWriterBlog
gWriterBlog_SOURCES = gwriter-main.c \
                      gwriter-mainWindow.c \
                      gwriter-menu.c \
                      gwriter-updateWindow.c \
                      gwriter-version.c \
                      gwriter-images.c \
                      network.c \
                      memory.c \
\
                      include/gwriter-menu.h \
                      include/gwriter-version.h \
                      include/gwriter-updateWindow.h \
                      include/gwriter-mainWindow.h \
                      include/gwriter-images.h \
                      include/memory.h \
                      include/network.h 
                      
gWriterBlog_LDADD = @gtk_LIBS@ @LIBCURL_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ 


