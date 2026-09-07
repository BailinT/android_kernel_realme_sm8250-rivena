/*
 * Based on arch/arm/include/asm/proc-fns.h
 *
 * Copyright (C) 1997-1999 Russell King
 * Copyright (C) 2000 Deep Blue Solutions Ltd
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_PROCFNS_H
#define __ASM_PROCFNS_H

#ifdef __KERNEL__
#ifndef __ASSEMBLY__

#include <asm/page.h>

struct mm_struct;
struct cpu_suspend_ctx;

extern void cpu_cache_off(void);
extern void cpu_do_idle(void);
extern void cpu_do_switch_mm(unsigned long pgd_phys, struct mm_struct *mm);
extern void cpu_reset(unsigned long addr) __attribute__((noreturn));
/* BailinT: cpu_soft_restart 以 arch/arm64/kernel/cpu-reset.h 的 4 参 static inline 为准，
 * 此处 4.19 二参旧 extern 声明与 5.x 调用方冲突（static follows non-static），删除 */

extern void cpu_do_suspend(struct cpu_suspend_ctx *ptr);
extern u64 cpu_do_resume(phys_addr_t ptr, u64 idmap_ttbr);

#include <asm/memory.h>

#endif /* __ASSEMBLY__ */
#endif /* __KERNEL__ */
#endif /* __ASM_PROCFNS_H */
