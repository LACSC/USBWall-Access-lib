/*
** File usbwall_init.c for project libusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  jeu. 19 janv. 2012 20:35:50 CET Philippe THIERRY
** Last update jeu. 19 janv. 2012 20:46:53 CET Philippe THIERRY
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
** \file usbwall_init.c
**
** Brief documentation on one line
** Detailed documentation
** On multiple lines...
**
** \author Philippe THIERRY
**
*/

#include "usbwall_init.h"
#include "libusbwall.h"

static int context = 0;

int	usbwall_init(void)
{
  int fd = -1;

  fd = open("/proc/usbwall/key_ctrl", O_WRONLY);
  if (fd == -1) {
    return ENODEV;
  }
  context = 1;
  return 0;
}

void	usbwall_release(void)
{
  context = 0;
}

int	usbwall_init_done(void)
{
  return (context == 1);
}
