/*
 * (c) 2008-2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */
#ifndef PATCH_H
#define PATCH_H

#include <l4/sys/compiler.h>

EXTERN_C_BEGIN
void
patch_module(const char **str, l4util_mb_info_t *mbi);
char *
get_arg_module(l4util_mb_info_t *mbi, const char *name, unsigned *size);
EXTERN_C_END

#endif
