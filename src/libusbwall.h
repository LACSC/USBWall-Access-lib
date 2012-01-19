/*
** File libusbwall.h for project libusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  jeu. 19 janv. 2012 20:36:56 CET Philippe THIERRY
** Last update jeu. 19 janv. 2012 21:30:41 CET Philippe THIERRY
**
** Copyright (C) 2009 - Philippe THIERRY
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
/**
** \file libusbwall.h
**
** Brief documentation on one line
** Detailed documentation
** On multiple lines...
**
** \author Philippe THIERRY
**
** \requirements
** This header is compliant of the following requirements :
** REQ_CODE_QUALITY_130
** REQ_CODE_QUALITY_140
** REQ_CODE_QUALITY_150
*/

#ifndef LIBUSBWALL_H_
# define LIBUSBWALL_H_

#include <stdint.h>
#include <linux/usb/usbwall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	usbwall_init(void);

void	usbwall_release(void);

int usbwall_key_add(uint16_t	vendorid,
                    uint16_t	productid,
                    char	*serial);

int usbwall_key_del(uint16_t	vendorid,
                    uint16_t	productid,
                    char	*serial);

#endif /* !LIBUSBWALL_H_ */
