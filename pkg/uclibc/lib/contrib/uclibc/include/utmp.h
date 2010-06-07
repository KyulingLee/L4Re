/* Copyright (C) 1993, 1996, 1997, 1998, 1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef	_UTMP_H
#define	_UTMP_H	1

#include <features.h>

#include <sys/types.h>


__BEGIN_DECLS

/* Get system dependent values and data structures.  */
#include <bits/utmp.h>

/* Compatibility names for the strings of the canonical file names.  */
#define UTMP_FILE	_PATH_UTMP
#define UTMP_FILENAME	_PATH_UTMP
#define WTMP_FILE	_PATH_WTMP
#define WTMP_FILENAME	_PATH_WTMP



#ifdef __UCLIBC_HAS_LIBUTIL__
/* Make FD be the controlling terminal, stdin, stdout, and stderr;
   then close FD.  Returns 0 on success, nonzero on error.  */
extern int login_tty (int __fd) __THROW;


/* Write the given entry into utmp and wtmp.  */
extern void login (__const struct utmp *__entry) __THROW;

/* Write the utmp entry to say the user on UT_LINE has logged out.  */
extern int logout (__const char *__ut_line) __THROW;

/* Append to wtmp an entry for the current time and the given info.  */
extern void logwtmp (__const char *__ut_line, __const char *__ut_name,
		     __const char *__ut_host) __THROW;
#endif

/* Append entry UTMP to the wtmp-like file WTMP_FILE.  */
extern void updwtmp (__const char *__wtmp_file, __const struct utmp *__utmp)
     __THROW;

/* Change name of the utmp file to be examined.  */
extern int utmpname (__const char *__file) __THROW;

/* Read next entry from a utmp-like file.  */
extern struct utmp *getutent (void) __THROW;

/* Reset the input stream to the beginning of the file.  */
extern void setutent (void) __THROW;
libc_hidden_proto(setutent)

/* Close the current open file.  */
extern void endutent (void) __THROW;

/* Search forward from the current point in the utmp file until the
   next entry with a ut_type matching ID->ut_type.  */
extern struct utmp *getutid (__const struct utmp *__id) __THROW;
libc_hidden_proto(getutid)

/* Search forward from the current point in the utmp file until the
   next entry with a ut_line matching LINE->ut_line.  */
extern struct utmp *getutline (__const struct utmp *__line) __THROW;

/* Write out entry pointed to by UTMP_PTR into the utmp file.  */
extern struct utmp *pututline (__const struct utmp *__utmp_ptr) __THROW;


#if 0 /* def	__USE_MISC */
/* Reentrant versions of the file for handling utmp files.  */
extern int getutent_r (struct utmp *__buffer, struct utmp **__result) __THROW;

extern int getutid_r (__const struct utmp *__id, struct utmp *__buffer,
		      struct utmp **__result) __THROW;

extern int getutline_r (__const struct utmp *__line,
			struct utmp *__buffer, struct utmp **__result) __THROW;

#endif	/* Use misc.  */

__END_DECLS

#endif /* utmp.h  */
