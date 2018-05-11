// XLR8 Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>
// modified by Bryan Craker <aloriumtech.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this
// Demonstrates how to adapt to use Wire code with XLR8Wire

// Created 29 March 2006
// Modified 10 May 2018

// This example code is in the public domain.

#include <XLR8I2C.h>

void setup() {
  enableWireInterrupts();
  XLR8Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  XLR8Wire.beginTransmission(8); // transmit to device #8
  XLR8Wire.write("x is ");       // sends five bytes
  XLR8Wire.write(x);             // sends one byte
  XLR8Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}

