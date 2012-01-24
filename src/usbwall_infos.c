/*
** File usbwall_infos.c for project libusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  ven. 20 janv. 2012 12:43:26 CET Philippe THIERRY
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
/*
** \file usbwall_infos.c
**
** Brief documentation on one line
** Detailed documentation
** On multiple lines...
**
** \author Philippe THIERRY
**
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libusbwall.h"

char	*usbwall_get_status()
{
  int fd = -1;
  int res = 0;
  int count = 255;
  char	*buffer = NULL;

  buffer = malloc(count + 1);
  fd = open("/proc/usbwall/status", O_RDONLY);
  res = read(fd, buffer, count);
  close(fd);
  if (res == -1) {
      return NULL;
  }
  buffer[res] = '\0';
  return buffer;
}

long	usbwall_get_release()
{
  int fd = -1;
  int res = 0;
  int count = 15;
  char	buffer[16];
  long release = 0;

  fd = open("/proc/usbwall/release", O_RDONLY);
  res = read(fd, buffer, count);
  close(fd);
  if (res == -1) {
      return 0;
  }
  buffer[res] = '\0';
  release = atoi(buffer);
  return release;

}
