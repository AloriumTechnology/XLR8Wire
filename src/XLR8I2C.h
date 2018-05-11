// Include register addresses and the XLR8Wire header
#include <XLR8AddrPack.h>
#include <XLR8Wire.h>

#define OPENXLR8_vect ANALOG_COMP_vect

// Define the default I2C XB registers
#define XB_TWCR_ADDR  0xE0
#define XB_TWDR_ADDR  0xE1
#define XB_TWAR_ADDR  0xE2
#define XB_TWSR_ADDR  0xE3
#define XB_TWBR_ADDR  0xE4
#define XB_TWAMR_ADDR 0xE5

#define XICR_Reg    _SFR_MEM8(XICR_Address)
#define XMSK_Reg    _SFR_MEM8(XMSK_Address)
#define XACK_Reg    _SFR_MEM8(XACK_Address)
#define XIFR_Reg    _SFR_MEM8(XIFR_Address)
#define OX8ICR_Reg  _SFR_MEM8(OX8ICR_Address)
#define OX8MSK_Reg  _SFR_MEM8(OX8MSK_Address)
#define OX8IFR_Reg  _SFR_MEM8(OX8IFR_Address)

// Initialize the default XLR8 I2C XB instance
XLR8TwoWire XLR8Wire = XLR8TwoWire(XB_TWAMR_ADDR,
                                   XB_TWCR_ADDR,
                                   XB_TWDR_ADDR,
                                   XB_TWAR_ADDR,
                                   XB_TWSR_ADDR,
                                   XB_TWBR_ADDR);

// Enable the I2C interrupts
void enableWireInterrupts() {
  XICR_Reg |= 0x02;
  XMSK_Reg |= 0x02;
  OX8ICR_Reg |= 0x01;
  OX8MSK_Reg |= 0x01;
}

// The default interrupt handler
ISR (OPENXLR8_vect) {
  uint8_t flags = OX8IFR_Reg;
  XLR8Wire.handleInterrupt();
  OX8IFR_Reg = 0x01;
  XACK_Reg = 0x02;
  XIFR_Reg = 0x02;
}

