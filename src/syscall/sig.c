/*
 * This file is part of Foreign Linux.
 *
 * Copyright (C) 2014, 2015 Xiangyan Sun <wishstudio@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <common/errno.h>
#include <common/signal.h>
#include <syscall/sig.h>
#include <syscall/syscall.h>
#include <log.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

DEFINE_SYSCALL(alarm, unsigned int, seconds)
{
	log_info("alarm(%d)\n", seconds);
	log_error("alarm() not implemented.\n");
	return 0;
}

DEFINE_SYSCALL(kill, pid_t, pid, int, sig)
{
	log_info("kill(%d, %d)\n", pid, sig);
	log_error("kill() not implemented.\n");
	return 0;
}

DEFINE_SYSCALL(tgkill, pid_t, tgid, pid_t, pid, int, sig)
{
	log_info("tgkill(%d, %d, %d)\n", tgid, pid, sig);
	log_error("tgkill() not implemented.\n");
	return 0;
}

DEFINE_SYSCALL(personality, unsigned long, persona)
{
	log_info("personality(%d)\n", persona);
	if (persona != 0 && persona != 0xFFFFFFFFU)
	{
		log_error("ERROR: persona != 0");
		return -EINVAL;
	}
	return 0;
}

DEFINE_SYSCALL(rt_sigaction, int, signum, const struct sigaction *, act, struct sigaction *, oldact)
{
	log_info("rt_sigaction(%d, %p, %p)\n", signum, act, oldact);
	log_error("rt_sigaction() not implemented.\n");
	return 0;
}

DEFINE_SYSCALL(rt_sigprocmask, int, how, const sigset_t *, set, sigset_t *, oldset)
{
	log_info("rt_sigprocmask(%d, 0x%p, 0x%p)\n", how, set, oldset);
	log_error("rt_sigprocmask() not implemented.\n");
	return 0;
}

DEFINE_SYSCALL(sigaltstack, const stack_t *, ss, stack_t *, oss)
{
	log_info("sigaltstack(ss=%p, oss=%p)\n", ss, oss);
	log_error("sigaltstack() not implemented.\n");
	return -ENOSYS;
}
