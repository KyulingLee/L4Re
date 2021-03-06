#pragma once

/*
 * constants.h --
 *
 * Globally used constants
 *
 * (c) 2011-2013 Björn Döbel <doebel@os.inf.tu-dresden.de>,
 *     economic rights: Technische Universität Dresden (Germany)
 * This file is part of TUD:OS and distributed under the terms of the
 * GNU General Public License 2.
 * Please see the COPYING-GPL-2 file for details.
 */

/*
 * Traditional vCPU handling method: every replica raises a fault
 * on its local vCPU and handles it on the own physical core.
 */
#define LOCAL_HANDLING 1

/*
 * Resilient cores test case 1: Upon a vCPU fault, migrate
 * the faulting vCPU to a resilient core (== CPU0). There,
 * handling is executed (and can be assumed to not fail). Before
 * resuming the vCPU, migrate back to the replica CPU, which
 * is assumed to be unsafe.
 */
#define MIGRATE_VCPU 0

/*
 * Resilient cores test case 2: Have a dedicated vCPU handler
 * thread on a resilient core (==CPU0). The non-resilient vCPU
 * handler then only sends an IPC to this thread in order to trigger
 * handling.
 */
#define SPLIT_HANDLING 0

namespace Romain
{
	enum {
		MAX_REPLICAS        =  3,        // maximum # of allowed replicas
		MAX_OBSERVERS       = 16,        // maximum # of fault observers
		MAX_CPUS            = 32,        // maximum # of physical CPUs we handle
		TRAMPOLINE_SIZE     = 64,        // size of the per-thread trampoline area
		HANDLER_STACK_SIZE  = (1 << 14), // size of the VCPU handler stack
		DEBUG_ENTRIES       = 1000,      // dbg: # of 64bit entries in thread->_measurements
		FIRST_REPLICA_CAP   = 0x1000,    // first replica cap markes as unused
		LOCK_INFO_PAGE      = 0xA000,    // address the lock info page is mapped to in replicas
		REPLICA_TSC_ADDRESS = 0xC000,    // start of replica-shared TSC buffer
		REPLICA_LOG_ADDRESS = 0xB0000000,   // start of replica log buffer (XXX: don't go lower -> KIP is there!)
	};
}
