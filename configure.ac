AC_INIT([gWriterBlog], [1.0], [BUG: ptkdev@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_CANONICAL_HOST
AC_CONFIG_HEADERS([config.h])

PKG_CHECK_MODULES(gtk, [gtk+-2.0 >= 2.10.0],, 
		AC_MSG_ERROR([You must have gtk+ >= 2.10.0]))

PKG_CHECK_MODULES(LIBCURL, [libcurl >= 7.21.0],,
  AC_MSG_ERROR([*** libcurl not found - this program requires libcurl >= 7.21.0 http://curl.haxx.se/libcurl/ **]))


AC_SUBST(gtk_CFLAGS)
AC_SUBST(gtk_LIBS)
AC_SUBST(LIBCURL_LIBS)

AC_CONFIG_FILES([
Makefile
src/Makefile
img/Makefile
])
AC_OUTPUT


