/**
 * \file
 * \brief Stack utilities for x86
 */
/*
 * (c) 2008-2009 Technische Universität Dresden
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU Lesser General Public License 2.1.
 * Please see the COPYING-LGPL-2.1 file for details.
 */
#ifndef __L4UTIL__INCLUDE__ARCH_X86__STACK_IMPL_H__
#define __L4UTIL__INCLUDE__ARCH_X86__STACK_IMPL_H__

#ifndef _L4UTIL_STACK_H
#error Do not include stack_impl.h directly, use stack.h instead
#endif

EXTERN_C_BEGIN

L4_INLINE l4_addr_t l4util_stack_get_sp(void)
{
  l4_addr_t esp;

  asm("movl   %%esp, %0\n\t" : "=r" (esp) : );
  return esp;
}

EXTERN_C_END

#endif /* ! __L4UTIL__INCLUDE__ARCH_ARM__STACK_IMPL_H__ */
