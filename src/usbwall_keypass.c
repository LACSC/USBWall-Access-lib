/*
** File usbwall_keypass.c for project libusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  jeu. 19 janv. 2012 20:36:06 CET Philippe THIERRY
** Last update jeu. 19 janv. 2012 21:29:29 CET Philippe THIERRY
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
** \file usbwall_keypass.c
**
** Brief documentation on one line
** Detailed documentation
** On multiple lines...
**
** \author Philippe THIERRY
**
*/

#include <sys/ioctl.h>
#include <string.h>
#include "libusbwall.h"
#include "usbwall_init.h"

/*!
** \brief usbwall_key_add
** 
** \param vendorid 
** \param productid 
** \param serial 
** 
** \return 
*/
int usbwall_key_add(uint16_t	vendorid,
                    uint16_t	productid,
                    const char	*serial)
{
  procfs_info_t usbwallinfo;
  int fd = -1;
  int res = -1;

  if (!usbwall_init_done()) {
    return EAGAIN;
  }
  usbwallinfo.info.keyflags = USBWALL_KEY_ADD | USBWALL_KEY_ACCESS_READ | USBWALL_KEY_ACCESS_WRITE | USBWALL_KEY_ACCESS_EXEC;
  usbwallinfo.info.idVendor = vendorid;
  usbwallinfo.info.idProduct = productid;
  strncpy(usbwallinfo.info.idSerialNumber, serial, 32);

  fd = open("/dev/usbwall", O_WRONLY);
  res = ioctl(fd, USBWALL_IO_ADDKEY, &(usbwallinfo.info));
  if (res == -1) {
    close(fd);
    return 1;
  }
  close(fd);
  return 0;
}

int usbwall_key_del(uint16_t	vendorid,
                    uint16_t	productid,
                    const char	*serial)
{
  procfs_info_t usbwallinfo;
  int fd = -1;
  int res = -1;

  if (!usbwall_init_done()) {
    return EAGAIN;
  }
  usbwallinfo.info.keyflags = USBWALL_KEY_DEL;
  usbwallinfo.info.idVendor = vendorid;
  usbwallinfo.info.idProduct = productid;
  strncpy(usbwallinfo.info.idSerialNumber, serial, 32);

  fd = open("/dev/usbwall", O_WRONLY);
  res = ioctl(fd, USBWALL_IO_DELKEY, &(usbwallinfo.info));
  if (res == -1) {
    close(fd);
    return 1;
  }
  close(fd);
  return 0;
}
