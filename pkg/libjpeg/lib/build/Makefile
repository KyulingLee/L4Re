PKGDIR          ?= ../..
L4DIR           ?= $(PKGDIR)/../..

TARGET          = libjpeg.a libjpeg.so
SYSTEMS         = $(SYSTEMS_PLAIN)
LIBS            = $(GCCLIB)
CONTRIB_INCDIR  = libjpeg

SRC_C           = jaricom.c jcapimin.c jcapistd.c jcarith.c jccoefct.c jccolor.c jcdctmgr.c jchuff.c \
        jcinit.c jcmainct.c jcmarker.c jcmaster.c jcomapi.c jcparam.c \
        jcprepct.c jcsample.c jctrans.c jdapimin.c jdapistd.c \
        jdatadst.c jdatasrc.c jdcoefct.c jdcolor.c jddctmgr.c jdhuff.c \
        jdinput.c jdmainct.c jdmarker.c jdmaster.c jdmerge.c \
        jdpostct.c jdsample.c jdtrans.c jerror.c jfdctflt.c jfdctfst.c \
        jfdctint.c jidctflt.c jidctfst.c jidctint.c jquant1.c \
        jquant2.c jutils.c jmemmgr.c jmemnobs.c jdarith.c

vpath %.c $(SRC_DIR)/../contrib

include $(L4DIR)/mk/lib.mk

# prevent warnings
CFLAGS := $(filter-out -Wextra -Wall,$(CFLAGS))
