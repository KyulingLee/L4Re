/**
 * \file
 * \brief  User-lock implementation for x86
 */
/*
 * (c) 2008-2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */
#pragma once

#include <l4/sys/utcb.h>
#include <l4/sys/ipc-invoke.h>

L4_INLINE l4_msgtag_t
l4_usem_down_to(l4_cap_idx_t ksem, l4_u_semaphore_t *sem, l4_timeout_s timeout) L4_NOTHROW
{
  l4_msgtag_t res;
  unsigned long dummy;

  l4_utcb_mr()->mr[0] = (l4_addr_t)sem;

  __asm__ __volatile__(
	"1: xorl %%eax, %%eax	\n\t"
	"   decl 0(%%edi)	\n\t"
	"   jge  2f		\n\t"
	"   mov $1, %%eax	\n\t"
	L4_ENTER_KERNEL
	"   cmp $0x10000, %%eax	\n\t"
	"   je 1b		\n\t"
	"2:			\n\t"
       :
	"=D" (dummy),
	"=c" (timeout),
	"=a" (res.raw)
       :
        "D" (sem),
	"d" (ksem),
	"c" (timeout)
       :
	"esi", "memory" L4S_PIC_CLOBBER
       );

  return res;
}

L4_INLINE l4_msgtag_t
l4_usem_up(l4_cap_idx_t ksem, l4_u_semaphore_t *sem) L4_NOTHROW
{
  l4_msgtag_t tag;
  l4_utcb_mr()->mr[0] = (l4_addr_t)sem;
  __asm__ __volatile__(
        "xorl %%eax, %%eax      \n\t"
	"incl 0(%%edi)		\n\t"
	"testb $1, 4(%%edi)	\n\t"
	"jz   2f		\n\t"
	"mov $0x10001, %%eax	\n\t"
	L4_ENTER_KERNEL
	"2:			\n\t"
       :
	"=D" (sem),
	"=d" (ksem),
	"=a" (tag.raw)
       :
	"D" (sem),
	"d" (ksem)
       :
	"ecx", "esi", "memory" L4S_PIC_CLOBBER
       );

  return tag;
}

