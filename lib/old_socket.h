/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        old_socket.h include file.
 *
 * Author:      Alexandre Cassen, <acassen@linux-vs.org>
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 *
 * Copyright (C) 2001-2016 Alexandre Cassen, <acassen@gmail.com>
 */

#ifndef _OLD_SOCKET_H
#define _OLD_SOCKET_H 1

#if !defined _HAVE_SOCK_NONBLOCK_ || !defined _HAVE_SOCK_CLOEXEC_
#include <fcntl.h>
#endif
#include <stdbool.h>

/* Kernels < 2.6.27 don't support the SOCK_CLOEXEC or SOCK_NONBLOCK options */

#ifndef _HAVE_SOCK_NONBLOCK_
#define SOCK_NONBLOCK	04000
#endif

#ifndef _HAVE_SOCK_CLOEXEC_
#define SOCK_CLOEXEC	0
#endif

#if !defined _HAVE_SOCK_NONBLOCK_ || !defined _HAVE_SOCK_CLOEXEC_
bool set_sock_flags(int fd, int cmd, long flags);
#endif
#endif
