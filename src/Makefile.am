bin_PROGRAMS = gWriterBlog
gWriterBlog_SOURCES = gwriter-main.c \
                      gwriter-switchpage.c \
                      gwriter-mainWindow.c \
                      gwriter-menu.c \
                      gwriter-mainWindow-creditsDialog.c \
                      gwriter-updateWindow.c \
                      gwriter-version.c \
                      gwriter-images.c \
                      network-management.c \
                      memory-management.c \
                      memory-debug.c \
\
                      include/gwriter-menu.h \
                      include/gwriter-version.h \
                      include/gwriter-updateWindow.h \
                      include/gwriter-mainWindow.h \
                      include/gwriter-switchpage.h \
                      include/gwriter-images.h \
                      include/memory-management.h \
                      include/network-management.h \
                      include/memory-debug.h
                      
gWriterBlog_LDADD = @gtk_LIBS@ @LIBCURL_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ 


