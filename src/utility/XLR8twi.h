/*
  XLR8twi.h - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2018 by Bryan Craker (bryan.craker@aloriumtech.org) of Alorium 
  Technology to use arbitrary register addresses
*/

#ifndef XLR8_twi_h
#define XLR8_twi_h

  #include <inttypes.h>

  #ifndef XLR8_TWI_FREQ
  #define XLR8_TWI_FREQ 100000L
  #endif

  #ifndef XLR8_TWI_BUFFER_LENGTH
  #define XLR8_TWI_BUFFER_LENGTH 32
  #endif

  #define XLR8_TWI_READY 0
  #define XLR8_TWI_MRX   1
  #define XLR8_TWI_MTX   2
  #define XLR8_TWI_SRX   3
  #define XLR8_TWI_STX   4
  
  void xlr8_twi_set_registers(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
  void xlr8_twi_init(void);
  void xlr8_twi_disable(void);
  void xlr8_twi_setAddress(uint8_t);
  void xlr8_twi_setFrequency(uint32_t);
  uint8_t xlr8_twi_readFrom(uint8_t, uint8_t*, uint8_t, uint8_t);
  uint8_t xlr8_twi_writeTo(uint8_t, uint8_t*, uint8_t, uint8_t, uint8_t);
  uint8_t xlr8_twi_transmit(const uint8_t*, uint8_t);
  void xlr8_twi_attachSlaveRxEvent( void (*)(uint8_t*, int) );
  void xlr8_twi_attachSlaveTxEvent( void (*)(void) );
  void xlr8_twi_reply(uint8_t);
  void xlr8_twi_stop(void);
  void xlr8_twi_releaseBus(void);
  void xlr8_handle_interrupt(void);

#endif

