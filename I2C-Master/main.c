/**
 * \brief I2C-Driver-MSP430g2553
 *
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 *
 * \version 1.0.0
 *
 * \date 10/03/2022
 *
 */


#include <msp430g2553.h>
#include "TI_USCI_I2C_master.h"
#include "crc8.h"

unsigned char timercounter;
unsigned char msg[40] = { };
unsigned char store[40] = { };
unsigned int crc8_var;


void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  BCSCTL1 = CALBC1_8MHZ; 
  DCOCTL = CALDCO_8MHZ;

  _EINT();

  TI_USCI_I2C_transmitinit(EPS, 0x12);      // init transmitting with USCI

  while ( TI_USCI_I2C_notready() );         // wait for bus to be free

  if ( TI_USCI_I2C_slave_present(EPS) )     // slave address may differ from
  {                                         // initialization
    // ----- Master Message -----

    msg[0] = 0x30;                          //Pedir para ler o ID da variavel (0xEEE2)

    crc8_var = crc8(msg, 1);                //Calculating crc8

    msg[1] = crc8_var;                      //Adding the crc8 value to the end of the message

    // ----- Master Message END -----

    // ------------------------------------

    // ----- Sending Master Message -----

    TI_USCI_I2C_transmitinit(EPS, 0x12);     // init transmitting with

    while ( TI_USCI_I2C_notready() );        // wait for bus to be free

    TI_USCI_I2C_transmit(2, msg);            // start transmitting

    // ----- Sending Master Message END -----

    // ------------------------------------

    // ----- Receiving Slave Message -----

    while ( TI_USCI_I2C_notready() );        // wait for bus to be free

    TI_USCI_I2C_receiveinit(EPS, 0x12);      // init receiving with USCI

    while ( TI_USCI_I2C_notready() );        // wait for bus to be free

    TI_USCI_I2C_receive(5, store);

    while ( TI_USCI_I2C_notready() );        // wait for bus to be free

    // ----- Receiving Slave Message END -----
  }
  
  LPM3;
 
}

