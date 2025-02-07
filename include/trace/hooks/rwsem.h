/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM rwsem
#define TRACE_INCLUDE_PATH trace/hooks
#if !defined(_TRACE_HOOK_RWSEM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_RWSEM_H
#include <trace/hooks/vendor_hooks.h>
/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */
struct rw_semaphore;
struct rwsem_waiter;
DECLARE_HOOK(android_vh_rwsem_init,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_rwsem_wake,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_rwsem_write_finished,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_alter_rwsem_list_add,
	TP_PROTO(struct rwsem_waiter *waiter,
		 struct rw_semaphore *sem,
		 bool *already_on_list),
	TP_ARGS(waiter, sem, already_on_list));
DECLARE_HOOK(android_vh_rwsem_wake_finish,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_rwsem_direct_rsteal,
	TP_PROTO(struct rw_semaphore *sem, bool *steal),
	TP_ARGS(sem, steal));
DECLARE_HOOK(android_vh_rwsem_optimistic_rspin,
	TP_PROTO(struct rw_semaphore *sem, long *adjustment, bool *rspin),
	TP_ARGS(sem, adjustment, rspin));
DECLARE_HOOK(android_vh_rwsem_read_trylock_failed,
	TP_PROTO(struct rw_semaphore *sem, long *cntp, int *ret),
	TP_ARGS(sem, cntp, ret));
DECLARE_HOOK(android_vh_record_rwsem_reader_owned,
	TP_PROTO(struct rw_semaphore *sem,
		 struct list_head *wlist),
	TP_ARGS(sem, wlist));
DECLARE_HOOK(android_vh_clear_rwsem_reader_owned,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_record_rwsem_writer_owned,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
DECLARE_HOOK(android_vh_clear_rwsem_writer_owned,
	TP_PROTO(struct rw_semaphore *sem),
	TP_ARGS(sem));
#endif /* _TRACE_HOOK_RWSEM_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
