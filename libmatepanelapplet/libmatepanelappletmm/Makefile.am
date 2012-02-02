## Copyright (c) 2001
## The libmatepanelappletmm development team.

SUBDIRS = private

sublib_name		= libmatepanelappletmm
sublib_libname = libmatepanelappletmm-2.6
sublib_libversion = $(LIBPANELAPPLETMM_SO_VERSION)
sublib_namespace	= Panel
sublib_cflags		= $(LIBPANELAPPLETMM_CFLAGS)
sublib_topdir = libmatepanelapplet


files_extra_h	= \
	factory.h \
  init.h \
  private.h \
  wrap_init.h

files_extra_cc = \
	factory.cc \
  init.cc \
  private.cc 

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES = libmatepanelappletmm-2.6.la
libmatepanelappletmm_2_6_la_SOURCES	= $(files_all_cc)
libmatepanelappletmm_2_6_la_LDFLAGS	= $(common_ldflags)
libmatepanelappletmm_2_6_la_LIBADD	= $(LIBPANELAPPLETMM_LIBS)
