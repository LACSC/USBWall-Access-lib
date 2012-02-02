/*
** File libusbwall.h for project libusbwall
**
** Made by Philippe THIERRY
** Login   <phil@reseau-libre.net>
**
** Started on  jeu. 19 janv. 2012 20:36:56 CET Philippe THIERRY
** Last update dim. 22 janv. 2012 15:42:09 CET Philippe THIERRY
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
** This is the libusbwall.h API inteface. This file defines all the exported functions
** of the libusbwall library.
**
** \author Philippe THIERRY
**
*/

#ifndef LIBUSBWALL_H_
# define LIBUSBWALL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <linux/usb/usbwall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*!
 ** \brief initialize the libusbwall.
 **
 ** While this function is not called, any other libusbwall function will return EBUSY.
 ** 
 ** This functions does the necessary checks in order to validate the underlying usbwall module. If
 ** the module is not loaded or if its version does not correspond to the one supported by this
 ** version of libusbwall, this function will return 1. Otherwise this function return 0.
 ** 
 ** \return 1 if the environment is not supported, or 0.
 */
int	usbwall_init(void);

/*!
 ** \brief release the usbwall function. Release any private library data associated to the current context.
 **
 ** By now, this function doesn't do anything. Nevertheless, because there is an initialization
 ** function, it is cleaner to add an associated release function.
 */
void	usbwall_release(void);

/*!
 ** \brief Add a new key to the USBWall module white-list.
 **
 ** This function give the necessary informations to the USBWall module in order to accept the given
 ** key. By default, the flags passed to the module are
 ** USBWALL_KEY_ACCESS_READ, USBWALL_KEY_ACCESS_WRITE and USBWALL_KEY_ACCESS_EXEC.
 **
 ** These flags will be configurable in a future version of this library.
 ** 
 ** \param vendorid the vendor id value, as shown in lsusb
 ** \param productid the product id value, as shown in lsusb
 ** \param serial the product serial number, as shown in lsusb
 ** 
 ** \return 0 if the key has been correctly added, or 1.
 */
int usbwall_key_add(uint16_t	vendorid,
                    uint16_t	productid,
                    const char	*serial);

/*!
 ** \brief Delete a given key from the module whitelist.
 **
 ** This function delete the usb key identifier from the module internal list, if found.
 ** 
 ** \param vendorid the vendor id value, as shown in lsusb
 ** \param productid the product id value, as shown in lsusb
 ** \param serial the product serial number, as shown in lsusb
 ** 
 ** \return 0 if the key has been found and deleted, or 1.
 */
int usbwall_key_del(uint16_t	vendorid,
                    uint16_t	productid,
                    const char	*serial);

/*!
 ** \brief return the current module status.
 **
 ** Ask the module for its current status and return the result through a string.
 ** 
 ** \return the module status.
 */
char	*usbwall_get_status(void);

/*!
** \brief return the release code of the module
** 
** \return a positive value corresponding to the release code, or 0 if it fails to get it
*/
long	usbwall_get_release(void);

#ifdef __cplusplus
}
#endif

#endif /* !LIBUSBWALL_H_ */
