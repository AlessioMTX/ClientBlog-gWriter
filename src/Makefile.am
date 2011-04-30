bin_PROGRAMS = gWriterBlog
gWriterBlog_SOURCES = gwriter-main.c \
                      gwriter-switchpage.c \
                      gwriter-mainWindow.c \
                      gwriter-menu.c \
                      gwriter-mainWindow-settingsDialog.c \
                      gwriter-mainWindow-creditsDialog.c \
                      gwriter-mainWindow-upgradeDialog.c \
                      gwriter-mainWindow-connectionDialog.c \
                      include/gwriter-menu.h \
                      include/gwriter-mainWindow.h \
                      include/gwriter-switchpage.h
gWriterBlog_LDADD = @gtk_LIBS@ @LIBCURL_LIBS@

AM_CPPFLAGS = \
	-DICONS_DIR=\""$(prefix)/share/icons/@PACKAGE@"\" \
	@gtk_CFLAGS@ 


